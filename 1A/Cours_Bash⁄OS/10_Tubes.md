# Les Tubes
[[09_Signaux]] ← → [[11_Concurrence]]

---

## Introduction

Les **tubes** sont un mécanisme de **communication inter-processus (IPC)** permettant l’échange de données entre deux processus.  
Ils servent de **canal de communication** où les messages transitent **sans perte** et dans **l’ordre d’émission** (FIFO).

### Objectifs
- Comprendre le principe et le fonctionnement des tubes.  
- Savoir utiliser les **tubes nommés** (`mkfifo`) et **anonymes** (`|`).  
- Maîtriser les **redirections avancées** et les cas d’usage pratiques.

---

## Chapitre 1 — Principe général

Un **tube** relie deux processus via un canal de communication :  
l’un **écrit** dans le tube, l’autre **lit** ce qui a été écrit.

```
Émetteur ──> [ Tube ] ──> Récepteur
```

- Le **tube** est vu comme un **fichier spécial** dans le système de fichiers.  
- Les messages sont transmis **dans l’ordre d’envoi**.  
- Aucune donnée n’est perdue.  

Exemple de cas d’usage :
- communication entre un serveur et un client,  
- coordination entre deux scripts,  
- échange d’informations entre programmes.

---

## Chapitre 2 — Tubes nommés

### 2.1 Définition

Un **tube nommé** est un fichier spécial créé sur le disque.  
Il permet à des processus **indépendants** de communiquer.

Création d’un tube :
```bash
mkfifo /tmp/canal
```

Écriture dans le tube :
```bash
echo "Bonjour" > /tmp/canal
```

Lecture depuis le tube :
```bash
read message < /tmp/canal
```

Suppression :
```bash
rm /tmp/canal
```

### 2.2 Exemple complet

**fichier : `bonjour.sh`**
```bash
#!/bin/bash
mkfifo /tmp/canal
echo "Bonjour" > /tmp/canal
read a < /tmp/canal
echo "Reçoit : $a"
```

**fichier : `au-revoir.sh`**
```bash
#!/bin/bash
read a < /tmp/canal
echo "Reçoit : $a"
echo "Au revoir" > /tmp/canal
```

Flux d’exécution :
```
1. bonjour.sh crée le tube et envoie "Bonjour"
2. au-revoir.sh lit le message, répond "Au revoir"
3. bonjour.sh lit la réponse
```

---

## Chapitre 3 — Fonctionnement et blocages

### 3.1 Comportement des tubes nommés

- L’**émetteur bloque** tant qu’aucun récepteur n’est connecté.  
- La **lecture bloque** tant qu’aucune donnée n’est disponible.  
- Si le récepteur se ferme, l’émetteur reçoit une **erreur d’écriture**.

### 3.2 Exemple de problème typique

```bash
while true; do
  echo "yes" > tube
done
```

et

```bash
while true; do
  read line < tube
done
```

→ Si le récepteur ferme le tube, l’émetteur **plante** lors du prochain envoi.

---

## Chapitre 4 — Redirections avancées

Pour éviter les fermetures intempestives, il faut **ouvrir le tube en lecture/écriture** simultanément.

```bash
exec 3<>tube
```

### 4.1 Exemple : émetteur
```bash
#!/bin/bash
exec 3<>tube
while true; do
  echo "yes" >&3
done
```

### 4.2 Exemple : récepteur
```bash
#!/bin/bash
exec 3<>tube
while true; do
  read line <&3
done
```

✅ Avantages :
- Ni l’émetteur ni le récepteur ne bloquent à l’ouverture.  
- Les échanges sont plus fiables.  

---

## Chapitre 5 — Tubes anonymes

### 5.1 Définition

Un **tube anonyme** est créé automatiquement lors de l’utilisation du symbole `|` dans le shell.  
Il n’a pas de nom sur le disque.

Exemple :
```bash
cat /etc/passwd | grep root
```

Fonctionnement :
- `cat` écrit dans la **sortie standard**, reliée au tube.  
- `grep` lit depuis **l’entrée standard**, reliée au même tube.

Représentation :
```
cat ──> [ Tube anonyme ] ──> grep
```

### 5.2 Équivalence avec un tube nommé

L’instruction ci-dessus est équivalente à :
```bash
mkfifo tube
cat /etc/passwd > tube &
grep root < tube
rm tube
```

### 5.3 Chaînage de commandes

Les tubes permettent de **chaîner** plusieurs processus :
```bash
cat /etc/passwd | grep root | sort | less
```

Chaque commande s’exécute en **parallèle**, les flux étant transmis directement sans fichier temporaire.

---

## Chapitre 6 — Commande `tee`

`tee` lit sur l’entrée standard, écrit à la fois :
- sur la **sortie standard**,  
- et dans un **fichier**.

Exemple :
```bash
cat /etc/passwd | grep root | tee /tmp/result
```

Ce qui produit :
- affichage du résultat à l’écran,  
- et sauvegarde simultanée dans `/tmp/result`.

---

## Chapitre 7 — Schéma récapitulatif

### 7.1 Tube nommé
```
Processus A ──> /tmp/tube ──> Processus B
      (mkfifo, read, write)
```

### 7.2 Tube anonyme
```
cmd1 | cmd2 | cmd3
```
→ Chaque commande reçoit la sortie de la précédente.

---

## Chapitre 8 — Bonnes pratiques et remarques

- Toujours utiliser `exec 3<>tube` pour ouvrir un tube en **lecture/écriture**.  
- Nettoyer les tubes avec `rm` après usage.  
- Utiliser les tubes anonymes pour **chaîner** des commandes ponctuelles.  
- Vérifier que l’émetteur et le récepteur sont prêts avant d’échanger.

---

## Synthèse finale

Les tubes sont un outil fondamental pour la **communication inter-processus** sous UNIX/Linux.  
Ils permettent :
- un échange **séquentiel et fiable** de données,  
- sans recours à un fichier temporaire,  
- et avec une **synchronisation naturelle** entre processus.

**À retenir :**
- `mkfifo` → crée un tube nommé.  
- `|` → crée un tube anonyme.  
- `exec 3<>tube` → évite les blocages.  
- `tee` → duplique la sortie d’un flux.  

---

[[09_Signaux]] ← → [[11_Concurrence]]
