# Le Shell Bash
[[02_Ordinateur]] ← → [[04_Systeme_de_Fichiers]]

---

## Introduction

Le **shell** est un programme qui permet à l’utilisateur de **dialoguer avec le système d’exploitation** à travers une interface textuelle : le **terminal**.  
Sous Linux, le **shell le plus courant** est **Bash** (*Bourne Again SHell*).  
C’est à la fois un **interpréteur de commandes** et un **langage de script**.

### Objectifs du chapitre

- Comprendre le rôle du shell dans un système UNIX/Linux.  
- Apprendre à manipuler les commandes de base.  
- Découvrir la logique de programmation en Bash : variables, tests, boucles et scripts.

---

## Chapitre 1 — Terminal, Shell et Commandes

### 1.1 Terminal vs Shell

- **Terminal** : programme d’affichage qui permet d’écrire et lire des commandes.  
- **Shell** : programme qui interprète et exécute ces commandes.  

Exemples de shells : `bash`, `sh`, `zsh`, `fish`.

### 1.2 Structure d’une commande

```
commande [options] [arguments]
```

Exemple :  
```bash
ls -l /home/user
```

- `ls` → la commande  
- `-l` → une option (affichage long)  
- `/home/user` → argument (le répertoire à lister)

### 1.3 Commandes de base

| Commande | Fonction |
|-----------|-----------|
| `pwd` | Affiche le répertoire courant |
| `ls` | Liste les fichiers |
| `cd` | Change de répertoire |
| `mkdir` | Crée un dossier |
| `rm` | Supprime un fichier |
| `cp` | Copie un fichier |
| `mv` | Déplace ou renomme un fichier |
| `cat` | Affiche le contenu d’un fichier |
| `man` | Ouvre le manuel d’une commande |

---

## Chapitre 2 — Variables et Substitutions

### 2.1 Variables

Déclaration :
```bash
nom="Alice"
echo "Bonjour $nom"
```

⚠️ Il ne doit pas y avoir d’espace autour du `=`.

### 2.2 Variables d’environnement

Quelques variables importantes :
- `$HOME` → répertoire personnel de l’utilisateur  
- `$USER` → nom d’utilisateur  
- `$PATH` → liste des répertoires où chercher les exécutables

Afficher toutes les variables :  
```bash
printenv
```

### 2.3 Substitution de commandes

Le résultat d’une commande peut être stocké dans une variable :  
```bash
date=$(date)
echo "Nous sommes le $date"
```

---

## Chapitre 3 — Opérateurs et Structures conditionnelles

### 3.1 Test de conditions

La commande `test` ou les crochets `[` `]` permettent de vérifier des conditions :

| Type de test | Exemple | Signification |
|---------------|----------|----------------|
| Numérique | `[ $a -lt 10 ]` | inférieur à 10 |
| Chaîne | `[ "$x" = "oui" ]` | égalité de chaînes |
| Fichier | `[ -f fichier.txt ]` | existe et est un fichier |

### 3.2 Structure `if`

```bash
if [ $age -ge 18 ]; then
    echo "Majeur"
else
    echo "Mineur"
fi
```

### 3.3 Structure `case`

```bash
read -p "Entrer une lettre : " c
case $c in
    [a-z]) echo "Minuscule";;
    [A-Z]) echo "Majuscule";;
    [0-9]) echo "Chiffre";;
    *) echo "Autre";;
esac
```

---

## Chapitre 4 — Boucles et Répétitions

### 4.1 Boucle `for`

```bash
for i in 1 2 3 4 5
do
    echo "Itération $i"
done
```

### 4.2 Boucle `while`

```bash
n=1
while [ $n -le 5 ]
do
    echo "n vaut $n"
    n=$((n+1))
done
```

### 4.3 Boucle `until`

```bash
n=0
until [ $n -eq 3 ]
do
    echo "Compteur : $n"
    n=$((n+1))
done
```

---

## Chapitre 5 — Scripts Bash

### 5.1 Création d’un script

1. Créer un fichier texte :
```bash
nano script.sh
```
2. Écrire le contenu :
```bash
#!/bin/bash
echo "Bonjour, utilisateur $USER"
```
3. Donner les droits d’exécution :
```bash
chmod +x script.sh
```
4. Exécuter :
```bash
./script.sh
```

### 5.2 Paramètres et arguments

Les arguments sont accessibles via `$1`, `$2`, etc.  
```bash
#!/bin/bash
echo "Premier argument : $1"
echo "Deuxième argument : $2"
```

### 5.3 Retour d’une commande

La variable `$?` contient le **code de retour** de la dernière commande (0 = succès).  
```bash
ls /root
if [ $? -ne 0 ]; then
    echo "Erreur : accès refusé"
fi
```

---

## Chapitre 6 — Commandes imbriquées et redirections

### 6.1 Redirection de flux

| Opération | Symbole | Exemple |
|------------|----------|----------|
| Sortie standard | `>` | `ls > liste.txt` |
| Ajout à un fichier | `>>` | `echo "Texte" >> log.txt` |
| Entrée standard | `<` | `wc -l < fichier.txt` |
| Erreur standard | `2>` | `commande 2> erreur.log` |

### 6.2 Pipe (`|`)

Le **pipe** envoie la sortie d’une commande vers une autre :  
```bash
ls -l | grep ".txt"
```

### 6.3 Commandes imbriquées

```bash
echo "Il y a $(ls | wc -l) fichiers dans ce dossier."
```

---

## Chapitre 7 — Bonnes pratiques et erreurs fréquentes

- Toujours **tester un script** avec `bash -n script.sh` avant exécution.  
- Utiliser `set -e` pour arrêter le script dès qu’une erreur survient.  
- Commenter le code (`# ...`) pour améliorer la lisibilité.  
- Ne pas oublier de donner les **droits d’exécution**.  
- Éviter les **chemins absolus** : privilégier les variables (`$HOME`, `$PWD`).

---

## Synthèse finale

Le **shell Bash** est un outil puissant à la fois pour l’**administration système** et l’**automatisation** de tâches répétitives.  
Sa maîtrise repose sur :
- la compréhension des **commandes de base**,  
- la **gestion des variables et structures de contrôle**,  
- et la capacité à **écrire des scripts robustes**.

---

[[02_Ordinateur]] ← → [[04_Systeme_de_Fichiers]]
