# Concurrence
[[10_Tubes]] ← → [[Fiche_Revision_IF110]]

---

## Introduction

La **communication par fichiers partagés** est une méthode simple de communication inter-processus (IPC) dans laquelle plusieurs processus **lisent et écrivent dans le même fichier**.  
Cette approche, bien que pratique, introduit des **problèmes de concurrence** : plusieurs processus peuvent modifier la même donnée simultanément, entraînant des incohérences.

### Objectifs
- Comprendre la **communication via fichiers partagés**.  
- Identifier les **problèmes de concurrence d’accès**.  
- Découvrir les mécanismes de **synchronisation** tels que les **verrous** (mutex).  

---

## Chapitre 1 — Communication par fichiers partagés

### 1.1 Principe

Un processus écrit une donnée dans un fichier pendant qu’un autre la lit.  

```bash
P1 : echo "Bonjour" > f1
P2 : read a < f1
```

Différences fondamentales :
- **Tube** : les données disparaissent après lecture.  
- **Fichier partagé** : les données persistent après lecture.

### 1.2 Schéma

```
Processus 1  ──>  Fichier partagé  ──>  Processus 2
```

---

## Chapitre 2 — Problème de la mise à jour concurrente

### 2.1 Illustration

Deux processus accèdent à la même ressource : l’un crédite un compte, l’autre le débite.

```bash
# Processus 1 (P1) crédite le compte
read a < compte-igor
a=$(expr $a + 2)
echo $a > compte-igor

# Processus 2 (P2) débite le compte
read b < compte-igor
b=$(expr $b - 100)
echo $b > compte-igor
```

Résultat possible :
- Les deux lisent la valeur initiale `100`.
- P1 écrit `102`, P2 écrit `0`.
→ Le dépôt de 2 € est **perdu**.

---

## Chapitre 3 — Sections critiques

### 3.1 Définition

Une **section critique** est une partie du programme qui accède à une ressource partagée.  
Deux processus ne doivent **jamais exécuter** leurs sections critiques **en même temps**.

### 3.2 Objectif

Assurer l’**exclusion mutuelle**, c’est-à-dire garantir qu’une seule section critique accède à une ressource donnée à la fois.

---

## Chapitre 4 — Le verrou (mutex)

### 4.1 Principe

Un **mutex** (Mutual Exclusion Lock) est un mécanisme qui contrôle l’accès exclusif à une ressource.  
Avant d’entrer en section critique, un processus doit **prendre le verrou** ; il doit le **libérer** à la sortie.

### 4.2 Opérations fondamentales

- **P (prendre le verrou)** → blocage si le verrou est déjà pris.  
- **V (libérer le verrou)** → permet à un autre processus d’y accéder.

Ces opérations doivent être **atomiques** (indivisibles).

---

## Chapitre 5 — Exemple d’utilisation d’un verrou

```bash
# Processus P1
P.sh compte-igor.lock
read a < compte-igor
a=$(expr $a + 2)
echo $a > compte-igor
V.sh compte-igor.lock

# Processus P2
P.sh compte-igor.lock
read b < compte-igor
b=$(expr $b - 100)
echo $b > compte-igor
V.sh compte-igor.lock
```

→ Les deux processus s’exécutent **séquentiellement**, pas simultanément.  
→ La cohérence du fichier `compte-igor` est préservée.

---

## Chapitre 6 — Implémentation pratique des verrous

### 6.1 Script `P.sh` — Prendre un verrou

Ce script bloque l’accès exclusif à une ressource partagée.  
Il utilise la commande `ln`, atomique sur les systèmes POSIX.

```bash
#! /bin/bash

if [ -z "$1" ]; then
    echo "Usage $0 mutex-name" >&1
    exit 1
else
    # Création atomique du lien dur représentant le verrou
    while ! ln "$0" "$1" 2>/dev/null; do
        sleep 1
    done

    # Vérification (utile sur systèmes non POSIX comme NTFS)
    inode_src=$(ls -i $0 | cut -f 1 -d" ")
    inode_dest=$(ls -i $1 | cut -f 1 -d" ")

    if [ "$inode_src" != "$inode_dest" ]; then
        echo "⚠️ Attention : P.sh ne fonctionne pas sur ce système de fichiers." >&2
        exit 1
    fi
    exit 0
fi
```

### 6.2 Script `V.sh` — Libérer un verrou

Libère le verrou en supprimant le fichier associé.

```bash
#! /bin/bash

if [ -z "$1" ]; then
    echo "Usage $0 mutex-name" >&1
    exit 1
else
    rm "$1"
    exit 0
fi
```

### 6.3 Exemple d’utilisation complète

```bash
P.sh compte-igor.lock
read solde < compte-igor
solde=$((solde + 10))
echo $solde > compte-igor
V.sh compte-igor.lock
```

🟢 **Résultat :**
Les processus se synchronisent correctement, garantissant une exécution séquentielle des sections critiques.

---

## Chapitre 7 — Interblocage (Deadlock)

### 7.1 Définition

Un **interblocage** survient lorsque deux processus attendent mutuellement la libération d’une ressource.

Exemple :
```
P1 : P.sh v1.lock → P.sh v2.lock
P2 : P.sh v2.lock → P.sh v1.lock
```

→ P1 attend v2.lock, P2 attend v1.lock.  
→ Aucun ne progresse : **blocage total**.

### 7.2 Prévention

- Toujours acquérir les verrous dans **le même ordre**.  
- Relâcher les verrous dès que possible.  
- Éviter les dépendances circulaires entre verrous.

---

## Chapitre 8 — Bonnes pratiques

- Toujours **prendre le verrou avant d’accéder** à la ressource partagée.  
- Toujours **libérer le verrou** à la fin, même en cas d’erreur (`trap` peut aider).  
- **Tester le fonctionnement** sur le système de fichiers (POSIX ou non).  
- **Surveiller les verrous orphelins** pouvant bloquer le système.  

---

## Synthèse finale

| Concept | Définition | Commandes associées |
|----------|-------------|--------------------|
| **Fichier partagé** | Fichier accessible à plusieurs processus | `read`, `echo` |
| **Section critique** | Zone du code nécessitant un accès exclusif | — |
| **Mutex (verrou)** | Mécanisme assurant l’exclusion mutuelle | `P.sh`, `V.sh` |
| **Interblocage** | Blocage mutuel de plusieurs processus | — |

Le **verrouillage de fichiers** est une méthode simple mais essentielle pour assurer la **cohérence des données** dans les systèmes concurrents.

---

[[10_Tubes]] ← → [[Fiche_Revision_IF110]]
