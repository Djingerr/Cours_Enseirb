# Les flux
[[05_Complements_Bash]] ← → [[07_Outils_Indispensables]]

---

## Introduction

Les **flux** représentent le mécanisme de communication standard entre un **programme** et son **environnement**.  
Ils permettent de **lire** et **écrire** des données à partir de fichiers, du terminal ou d’autres processus.  
Chaque flux est associé à un **numéro**, un **mode d’ouverture** et un **fichier**.

---

## Chapitre 1 — Notion de flux

Un **flux** correspond à un canal de communication entre un programme et une source ou destination de données.  
Il est défini par :
- un **fichier associé**,  
- une **fonction de lecture**,  
- une **fonction d’écriture**,  
- et une **tête de lecture/écriture** (position courante dans le fichier).

### 1.1 Les trois flux standards

Chaque processus dispose par défaut de trois flux :

| Nom | Numéro | Rôle | Source/Destination par défaut |
|------|---------|------|-------------------------------|
| **stdin** | 0 | Entrée standard | Clavier |
| **stdout** | 1 | Sortie standard | Écran |
| **stderr** | 2 | Sortie d’erreur | Écran |

Exemple :
```bash
read nom    # lit à partir de stdin (clavier)
echo $nom   # écrit sur stdout (écran)
```

---

## Chapitre 2 — Redirections simples

Une **redirection** permet de modifier la destination ou la source d’un flux.

### 2.1 Syntaxe générale

```
cmd n[<,>,>>,<>]fichier
```

- `>` : redirection de sortie (écriture, écrasement)
- `>>` : redirection en ajout
- `<` : redirection d’entrée (lecture)
- `<>` : lecture/écriture
- `n` : numéro du flux (facultatif)

### 2.2 Exemples

```bash
echo "Bonjour" > fic.txt     # écrit dans un fichier (stdout → fichier)
cat < fic.txt                # lit depuis le fichier (stdin ← fichier)
echo "Suite" >> fic.txt      # ajoute à la fin du fichier
```

Par défaut :
- Si `n` n’est pas précisé et qu’il s’agit d’une **écriture**, `n=1` (stdout).  
- Si c’est une **lecture**, `n=0` (stdin).

### 2.3 Tableau récapitulatif

| Opérateur | Lecture | Écriture | Position tête | Effet |
|------------|----------|-----------|----------------|--------|
| `<` | Oui | Non | Début | Lecture |
| `>` | Non | Oui | Début | Écrase le contenu |
| `>>` | Non | Oui | Fin | Ajout |
| `<>` | Oui | Oui | Début | Lecture/Écriture |

---

## Chapitre 3 — Lecture d’un flux ligne à ligne

La commande `read` lit une ligne à la fois et déplace la tête de lecture.

### 3.1 Exemple simple

```bash
while read ligne; do
    echo ":: $ligne"
done < fic.txt
```

- `read` retourne **vrai** tant qu’il n’a pas atteint la fin du fichier (EOF).  
- La boucle s’arrête automatiquement lorsque le flux est épuisé.

### 3.2 Détection de la fin de flux

- Sur un terminal, `EOF` est généré avec `Ctrl + D`.
- Dans un fichier, `EOF` apparaît automatiquement quand la lecture atteint la fin.

---

## Chapitre 4 — Redirections avancées

### 4.1 Commande `exec`

`exec` modifie les flux du processus courant (pas d’ouverture de nouveau processus).

```bash
exec n[<,>,>>,<>]fichier
```

Exemple :
```bash
exec 3>fic.txt     # ouvre le flux 3 en écriture vers fic.txt
echo "Bonjour" >&3 # envoie le texte dans fic.txt
```

### 4.2 Redirection entre flux

On peut rediriger un flux vers un autre :
```bash
cmd n[<,>,<>]&k
```
Exemple :
```bash
echo "erreur" 1>&2   # envoie stdout vers stderr
```

### 4.3 Exemple complet

```bash
#!/bin/bash
exec 3>redoublants
while read nom note; do
    if [ $note -lt 10 ]; then
        echo $nom >&3
    fi
    echo "Étudiant $nom a eu $note/20"
done < notes.txt
```

Ce script écrit les noms des étudiants redoublants dans le fichier *redoublants* via le flux 3.

---

## Chapitre 5 — Les tubes (pipes)

### 5.1 Principe

Le **pipe** (`|`) relie la sortie d’une commande à l’entrée d’une autre :
```bash
cmd1 | cmd2
```
Cela équivaut (grosso modo) à :
```bash
cmd1 > temp
cmd2 < temp
rm temp
```
Mais sans création réelle de fichier intermédiaire.

### 5.2 Exemple pratique

```bash
ls -l | grep ".sh"
cat fichier.txt | wc -l
ps aux | grep firefox
```

Les deux commandes s’exécutent en **parallèle** : la sortie de `cmd1` est directement transmise à `cmd2`.

---

## Chapitre 6 — Fichiers de périphériques

### 6.1 Périphériques matériels et logiciels

Sous Linux, **chaque périphérique est représenté comme un fichier** dans `/dev`.

| Exemple | Description |
|----------|--------------|
| `/dev/sda` | Premier disque dur |
| `/dev/sda1` | Première partition du disque |
| `/dev/null` | Détruit toute donnée écrite, lit EOF |
| `/dev/tty` | Terminal courant |
| `/dev/urandom` | Générateur de nombres aléatoires |

### 6.2 Utilisation avec redirections

```bash
read a </dev/urandom     # lecture pseudo-aléatoire
echo "Test" > /dev/null  # sortie ignorée
```

⚠️ Exemple dangereux (à ne pas exécuter) :
```bash
echo "J’ai cassé mon disque" > /dev/sda
```

---

## Chapitre 7 — Résumé et bonnes pratiques

### 7.1 Concepts essentiels

- Un **flux** associe :
  - un **numéro** (0, 1, 2, …),  
  - un **mode d’ouverture**,  
  - et un **fichier associé**.

- Une commande peut rediriger un flux vers :
  - un **fichier** → `cmd n[<,>,>>,<>]fic`,  
  - un **autre flux** → `cmd n[<,>,<>]&k`.

- Le **pipe (`|`)** relie la sortie d’un programme à l’entrée d’un autre.

### 7.2 Bonnes pratiques

- Toujours **tester les redirections** avant automatisation.  
- Utiliser des noms de fichiers explicites.  
- Éviter d’écrire directement sur des périphériques réels (`/dev/sda`).  
- Utiliser `/dev/null` pour ignorer des sorties.

---

## Synthèse finale

Les flux sont au cœur du fonctionnement d’un système UNIX : ils permettent aux processus de **communiquer** et de **manipuler les données** sans dépendre du type de support (fichier, terminal, périphérique…).  
Les concepts de **redirection**, **tube**, et **périphérique-fichier** sont essentiels pour comprendre le modèle d’E/S de Linux.

---

[[05_Complements_Bash]] ← → [[07_Outils_Indispensables]]
