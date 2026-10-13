# Compléments sur le Shell Bash
[[04_Systeme_de_Fichiers]] ← → [[06_Flux]]

---

## Introduction

Ce module approfondit l’usage du **shell Bash**, en abordant des notions essentielles pour l’administration et la configuration d’un environnement Linux.  
Nous verrons notamment :  
- les **variables d’environnement**,  
- les **codes de retour** et la gestion d’erreurs,  
- les **alias** et **fichiers de configuration**,  
- ainsi que la **substitution de commandes** et les **motifs (wildcards)**.

---

## Chapitre 1 — Variables et environnement

### 1.1 Variables d’environnement

Les **variables d’environnement** influencent le comportement du shell et des programmes.  
Elles sont accessibles à tout processus enfant lancé depuis le shell.

Afficher toutes les variables :
```bash
printenv
env
```

Créer une variable temporaire :
```bash
export NOM="Alice"
echo $NOM
```

Quelques variables importantes :

| Variable | Rôle |
|-----------|------|
| `$HOME` | Répertoire personnel |
| `$USER` | Nom de l’utilisateur |
| `$SHELL` | Shell utilisé |
| `$PATH` | Répertoires de recherche des exécutables |
| `$PWD` | Répertoire courant |
| `$PS1` | Invite de commande principale |
| `$PS2` | Invite secondaire (ex : lors d’une commande incomplète) |

### 1.2 La variable PATH

La variable **PATH** est une liste de répertoires séparés par des `:`.  
Quand une commande est exécutée, Bash la cherche dans ces dossiers.

```bash
echo $PATH
/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin
```

Ajouter un répertoire à PATH :
```bash
export PATH=$PATH:/home/alice/bin
```

⚠️ **Attention à la sécurité :**
Ne jamais placer `.` (le répertoire courant) en tête du PATH :
```bash
export PATH=.:$PATH   # dangereux !
```
Cela pourrait permettre à un utilisateur malveillant d’exécuter un programme du répertoire courant à la place d’une commande système.

---

## Chapitre 2 — Codes de retour et contrôle d’exécution

### 2.1 Code de retour d’une commande

Chaque commande retourne un **code de sortie** (ou **exit code**) :  
- `0` → succès,  
- autre → erreur.

Consulter le dernier code de retour :
```bash
echo $?
```

Exemple :
```bash
ls /root
echo $?   # retournera 2 (accès refusé)
```

### 2.2 Utiliser `exit` dans un script

```bash
#!/bin/bash
if [ $# -ne 1 ]; then
    echo "Usage : $0 <fichier>"
    exit 1
fi
echo "Fichier valide : $1"
exit 0
```

Un **exit code non nul** signale une erreur. Il peut être testé dans des scripts automatisés.

---

## Chapitre 3 — Alias de commandes

Les **alias** permettent de simplifier ou de personnaliser les commandes.

Créer un alias :
```bash
alias ll='ls -l --color=auto'
alias maj='sudo apt update && sudo apt upgrade'
```

Lister les alias :
```bash
alias
```

Supprimer un alias temporaire :
```bash
unalias ll
```

Pour le rendre **permanent**, l’ajouter dans le fichier `~/.bashrc` :
```bash
echo "alias ll='ls -l --color=auto'" >> ~/.bashrc
source ~/.bashrc
```

---

## Chapitre 4 — Fichiers de configuration Bash

### 4.1 Hiérarchie des fichiers

À chaque ouverture de terminal, Bash lit des fichiers de configuration :

| Fichier | Portée | Rôle |
|----------|---------|------|
| `/etc/profile` | Global | Initialisation du système pour tous les utilisateurs |
| `~/.bash_profile` | Individuel | Exécuté à la connexion |
| `~/.bashrc` | Individuel | Chargé à chaque ouverture d’un terminal interactif |
| `/etc/bash.bashrc` | Global | Paramètres communs à tous les utilisateurs |

Exemple de personnalisation du prompt dans `~/.bashrc` :
```bash
PS1="\u@\h:\w$ "
```

### 4.2 Recharger la configuration

```bash
source ~/.bashrc
# ou plus court :
. ~/.bashrc
```

---

## Chapitre 5 — Substitution et expansion

### 5.1 Substitution de commande

Permet d’utiliser le **résultat d’une commande** dans une autre :
```bash
echo "Il est $(date +%H:%M)"
```

### 5.2 Expansion arithmétique

```bash
a=5
b=3
echo $((a + b))  # 8
```

### 5.3 Expansion de variables

```bash
nom="Alice"
echo "Bonjour ${nom} !"
```

### 5.4 Substitution de paramètres par défaut

```bash
echo "Utilisateur : ${USER:-inconnu}"
```

---

## Chapitre 6 — Filtrage de fichiers (globbing)

Le **globbing** permet de sélectionner des fichiers selon un motif.

| Symbole | Signification | Exemple |
|----------|----------------|----------|
| `*` | n’importe quelle suite de caractères | `*.txt` |
| `?` | un seul caractère | `data?.csv` |
| `[abc]` | un caractère parmi la liste | `note[12].txt` |
| `[a-z]` | plage de caractères | `fichier[a-z].log` |
| `{a,b}` | choix entre plusieurs motifs | `{main,test}.c` |

Exemple :
```bash
ls *.sh
cp note[12].txt sauvegarde/
```

---

## Chapitre 7 — Historique et productivité

### 7.1 Historique des commandes

Afficher l’historique :
```bash
history
```

Répéter la dernière commande :
```bash
!!
```

Relancer une commande spécifique :
```bash
!42    # exécute la commande n°42
```

### 7.2 Raccourcis utiles

| Touche | Fonction |
|--------|-----------|
| `Ctrl + A` | Début de ligne |
| `Ctrl + E` | Fin de ligne |
| `Ctrl + R` | Recherche dans l’historique |
| `Ctrl + C` | Interruption de la commande |
| `Ctrl + D` | Quitter le shell |

---

## Chapitre 8 — Sécurité et bonnes pratiques

- Éviter d’exécuter des scripts non vérifiés.  
- Toujours tester un script avec `bash -n fichier.sh`.  
- Ajouter `set -e` en début de script pour arrêter à la première erreur.  
- Ne jamais exécuter `rm -rf /` (même en test !).  
- Sauvegarder et versionner les scripts importants.

---

## Synthèse finale

Ce chapitre complète la maîtrise du **shell Bash** en introduisant :
- les **variables d’environnement** et le **PATH**,  
- les **codes de retour** et l’**exit code**,  
- la gestion des **alias** et **fichiers de configuration**,  
- ainsi que les **motifs de recherche** et les **raccourcis d’efficacité**.

Ces outils font du shell un environnement puissant, modulable et productif pour tout utilisateur Linux.

---

[[04_Systeme_de_Fichiers]] ← → [[06_Flux]]
