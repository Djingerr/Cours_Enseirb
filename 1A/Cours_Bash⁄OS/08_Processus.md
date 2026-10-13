# Les Processus
[[07_Outils_Indispensables]] ← → [[09_Signaux]]

---

## Introduction

Un **processus** est un **programme en cours d’exécution**.  
Chaque commande ou script lancé dans un terminal crée au moins **un processus**.  
Le système d’exploitation en gère plusieurs simultanément, chacun ayant son propre **espace mémoire** et **contexte d’exécution**.

### Objectifs du cours

- Observer et gérer les processus d’un système Linux.  
- Comprendre leur **cycle de vie**.  
- Manipuler les processus : suspension, reprise, terminaison.  
- Découvrir les principes d’**ordonnancement** et de **partage des ressources**.

---

## Chapitre 1 — Notion de processus

### 1.1 Définition

Un **processus** correspond à :
- un **programme exécuté** avec son propre **contexte mémoire**,  
- des **fichiers ouverts**,  
- et des **ressources allouées** (CPU, mémoire, E/S).

### 1.2 Caractéristiques

- **PID** (*Process Identifier*) : identifiant unique du processus.  
- **PPID** (*Parent Process Identifier*) : identifiant du processus parent.  
- **Utilisateur propriétaire** et **droits d’accès**.  
- **Caractéristiques dynamiques** : priorité, temps CPU consommé, etc.

---

## Chapitre 2 — Observation des processus

### 2.1 Commande `ps`

Affiche la liste des processus à un instant donné.

```bash
ps -l
```

Exemple de sortie :
```
F S  UID   PID  PPID  C PRI NI ADDR SZ WCHAN TTY TIME CMD
0 S 1000 22995 1403  0 80  0 - 6285 - pts/1 00:00:00 bash
0 S 1000 29526 22995 0 80  0 - 128631 - pts/1 00:00:05 emacs
0 R 1000 30323 22995 0 80  0 - 2790 - pts/1 00:00:00 ps
```

### 2.2 Commande `pstree`

Affiche l’arborescence des processus.

```bash
pstree -pA
```

Schéma simplifié :
```
systemd(1)─┬─bash(22995)───emacs(29526)
            └─pstree(30412)
```

### 2.3 Commande `top`

Affiche dynamiquement les processus en cours d’exécution.

```bash
top
```

Permet de visualiser :
- la charge CPU et mémoire,  
- les processus actifs et dormants,  
- les priorités et le temps processeur utilisé.

---

## Chapitre 3 — Variables liées aux processus

| Variable | Description |
|-----------|-------------|
| `$$` | PID du shell courant |
| `$PPID` | PID du processus parent |
| `$!` | PID du dernier processus lancé en arrière-plan |
| `$?` | Code de retour de la dernière commande |

Exemple :
```bash
echo $$      # PID du bash courant
echo $PPID   # PID du parent
```

---

## Chapitre 4 — Processus en avant et arrière-plan

### 4.1 Avant-plan (foreground)

Par défaut, les commandes s’exécutent en avant-plan :  
le shell **attend la fin du processus**.

```bash
xeyes
```

Le terminal est bloqué tant que le programme n’est pas terminé.

### 4.2 Arrière-plan (background)

Pour exécuter une commande sans bloquer le terminal :  
ajouter `&` à la fin de la commande.

```bash
xeyes &
[1] 35794
```

- `[1]` : numéro de job (JobID)  
- `35794` : PID du processus fils

### 4.3 Reprendre ou suspendre un processus

- **Ctrl + Z** → suspendre le processus courant.  
- **fg** → reprendre un job en avant-plan.  
- **bg** → reprendre un job en arrière-plan.

---

## Chapitre 5 — Cycle de vie d’un processus

Un processus passe par plusieurs **états** :

```
        ┌──────────────┐
        │   Création   │
        └──────┬───────┘
               │
        ┌──────▼───────┐
        │   Prêt       │
        └──────┬───────┘
               │ (élu)
        ┌──────▼───────┐
        │   Exécution  │
        └──────┬───────┘
               │ (attente ressource)
        ┌──────▼───────┐
        │   Attente    │
        └──────┬───────┘
               │ (fin)
        ┌──────▼───────┐
        │  Terminé     │
        └──────────────┘
```

### 5.1 Suppression et terminaison

Un processus peut se terminer :  
- naturellement (fin du programme),  
- par `exit`,  
- par réception d’un **signal** (`Ctrl + C`, `kill`, `killall`).

```bash
kill %1
kill 35794
killall firefox
```

`-9` (SIGKILL) force la terminaison.

### 5.2 Attendre la fin d’un processus

```bash
wait          # attend la fin de tous les fils
wait %1       # attend un job spécifique
wait 35794    # attend un PID spécifique
```

---

## Chapitre 6 — Variables et exportation

Les **variables Bash** sont locales au processus.  
Elles ne sont **pas héritées** automatiquement par les processus enfants.

### 6.1 Exemple

```bash
a="existe"
./script.sh
# a n’est pas visible dans le script
```

### 6.2 Exportation

Pour rendre une variable accessible aux processus enfants :
```bash
export a="visible"
```

### 6.3 Variable d’environnement

Une variable **exportée** devient une **variable d’environnement**.

Variables fréquentes :
| Nom | Rôle |
|------|------|
| `$HOME` | Répertoire personnel |
| `$PATH` | Répertoires de recherche |
| `$PS1` | Invite de commande |
| `$USER` | Nom d’utilisateur |

---

## Chapitre 7 — Gestion par le système d’exploitation

### 7.1 Partage des ressources

Le système d’exploitation gère :
- le **processeur (CPU)**,  
- la **mémoire**,  
- les **entrées/sorties (E/S)**.

Il garantit :
- l’**exclusion mutuelle**,  
- le **contrôle d’accès**,  
- la **stabilité** du système.

### 7.2 Ordonnancement

L’ordonnanceur choisit **quel processus** exécuter à un instant donné.

- Chaque processus a une **priorité**.  
- Le CPU est partagé selon un **quantum de temps** (*timeslice*).  
- Après chaque quantum, le processus peut être **préempté**.

```
File d’attente de processus prêts
┌──────────────┬──────────────┬──────────────┐
│  priorité 0  │  priorité 1  │  priorité 2  │
└──────────────┴──────────────┴──────────────┘
```

### 7.3 Commandes de priorité

| Commande | Description |
|-----------|--------------|
| `nice -n valeur cmd` | Lance une commande avec priorité donnée |
| `renice -n valeur PID` | Modifie la priorité d’un processus existant |

Exemple :
```bash
nice -n 10 make
renice -n 5 1234
```

---

## Chapitre 8 — Concurrence et exclusion

Plusieurs processus peuvent accéder simultanément à une même ressource (fichier, périphérique, terminal).  
Le système assure **l’exclusion mutuelle** pour éviter les conflits.

Exemple :
```bash
#!/bin/bash
while true; do
  echo "ping"
done
```
et
```bash
#!/bin/bash
while true; do
  echo "pong"
done
```

Exécutés simultanément, ils s’intercalent dans la sortie :
```
ping
pong
ping
pong
```

---

## Synthèse finale

Le système d’exploitation assure la **création, l’exécution et la coordination** des processus.  
Un processus est :
- identifié par un **PID**,  
- organisé en **arborescence**,  
- contrôlé via **signaux** et **ordonnancement**.

### Commandes à retenir

- Observation : `ps`, `pstree`, `top`  
- Gestion : `fg`, `bg`, `kill`, `wait`  
- Priorité : `nice`, `renice`  
- Variables : `$$`, `$PPID`, `$!`, `$?`

---

[[07_Outils_Indispensables]] ← → [[09_Signaux]]
