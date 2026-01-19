# Les Signaux
[[08_Processus]] ← → [[10_Tubes]]

---

## Introduction

Les **signaux** constituent un mécanisme de **communication inter-processus** simple, utilisé pour informer un processus d’un événement particulier.  
Un signal est un **message numérique** envoyé par un processus à un autre (ou par le noyau) pour déclencher une action spécifique.

### Objectifs
- Comprendre le fonctionnement des signaux sous UNIX/Linux.  
- Savoir **envoyer** et **intercepter** un signal.  
- Manipuler les commandes **`kill`** et **`trap`**.  

---

## Chapitre 1 — Définition et principe général

### 1.1 Qu’est-ce qu’un signal ?

Un **signal** est un **entier compris entre 1 et 31**, envoyé à un processus.  
Il sert à :
- notifier un événement (erreur, arrêt, etc.),  
- interrompre ou suspendre un programme,  
- déclencher une action prédéfinie.

### 1.2 Caractéristiques principales

- Communication **unidirectionnelle** (de l’émetteur vers le récepteur).  
- **Pas de file d’attente** : un signal identique émis deux fois peut être perdu si le premier n’a pas encore été reçu.  
- **Ordre de réception aléatoire** : les signaux peuvent être traités dans un ordre différent de celui d’émission.

### 1.3 Fonctionnement général

```
Émetteur ──(signal n°)──▶ Récepteur
```

Lorsqu’un processus reçoit un signal :
1. Le noyau interrompt son exécution.  
2. Il déclenche une **routine de traitement** du signal.  
3. Par défaut, cette routine **tue** le processus (sauf exceptions).

---

## Chapitre 2 — Exemples de signaux courants

| Nom | Numéro | Description |
|------|---------|-------------|
| `SIGHUP` | 1 | Fermeture du terminal |
| `SIGINT` | 2 | Interruption (Ctrl + C) |
| `SIGQUIT` | 3 | Quitte le programme (souvent Ctrl + D) |
| `SIGILL` | 4 | Instruction illégale |
| `SIGFPE` | 8 | Erreur arithmétique (division par zéro) |
| `SIGKILL` | 9 | Forçage immédiat de la terminaison |
| `SIGSEGV` | 11 | Accès mémoire invalide |
| `SIGTERM` | 15 | Signal d’arrêt standard |
| `SIGCHLD` | 17 | Fin d’un processus fils |
| `SIGSTP` | 18 | Suspension (Ctrl + Z) |
| `SIGCONT` | 19 | Reprise d’un processus suspendu |
| `SIGUSR1` | 30 | Signal utilisateur libre |
| `SIGUSR2` | 31 | Signal utilisateur libre |

---

## Chapitre 3 — Commandes et utilisation

### 3.1 Envoyer un signal

```bash
kill -SIGUSR1 <pid>
kill -9 <pid>      # SIGKILL
kill -15 <pid>     # SIGTERM
```

Le signal par défaut de `kill` est `SIGTERM` (15).  
Seul `root` peut envoyer certains signaux à tous les processus.

### 3.2 Associer une action à un signal (`trap`)

```bash
trap 'commande_ou_expression' SIGNAL
```

Exemple :
```bash
trap 'echo "Signal reçu !" ' SIGUSR1
```

Désactiver le piégeage :
```bash
trap - SIGUSR1
```

---

## Chapitre 4 — Exemple complet : communication entre processus

### 4.1 Script récepteur

```bash
#!/bin/bash
trap 'echo "Coucou ! Signal USR1 reçu."' USR1
echo "PID : $$"
while true; do
    sleep 1
done
```

### 4.2 Script émetteur

```bash
#!/bin/bash
kill -USR1 $1
```

### 4.3 Exécution

**Terminal 1 :**
```bash
$ ./recepteur.sh
PID : 52075
```

**Terminal 2 :**
```bash
$ ./emetteur.sh 52075
```

Résultat :
```
Coucou ! Signal USR1 reçu.
```

Le gestionnaire défini par `trap` est exécuté au moment de la réception du signal, puis le processus reprend son exécution normale.

---

## Chapitre 5 — Suspension et reprise d’un processus

Deux signaux importants :
- **`SIGSTP`** : suspend le processus (Ctrl + Z).  
- **`SIGCONT`** : le reprend (commandes `fg` ou `bg`).

### Exemple d’utilisation dans Bash

- `Ctrl + Z` → envoie `SIGSTP` au processus actif.  
- `bg` → envoie `SIGCONT` pour le relancer en arrière-plan.  
- `fg` → envoie `SIGCONT` pour le relancer en avant-plan.

---

## Chapitre 6 — Notions avancées

### 6.1 Perte et ordre des signaux

- Si plusieurs signaux identiques sont envoyés avant réception, **les doublons sont perdus**.  
- L’ordre d’arrivée **n’est pas garanti**.  

### 6.2 Signaux non interceptables

Certains signaux ne peuvent pas être capturés ni ignorés :
- `SIGKILL` (9)  
- `SIGSTOP` (19)

Ils sont directement gérés par le noyau.

### 6.3 Enchaînement des signaux

Un processus peut **recevoir plusieurs signaux différents** successivement.  
Le système gère leur traitement via une file interne non ordonnée.

---

## Chapitre 7 — Résumé et bonnes pratiques

- Un **signal** est un message entre processus, représenté par un entier (1 à 31).  
- Commande `kill` → envoie un signal.  
- Commande `trap` → définit une action à la réception.  
- `SIGSTP` / `SIGCONT` → suspend et reprend un processus.  
- Certains signaux (ex. : `SIGKILL`) ne peuvent être interceptés.  
- Les signaux sont **asynchrones** : ils peuvent arriver à tout moment.

---

## Synthèse finale

Les signaux sont un **mécanisme de communication asynchrone** entre processus, simple mais puissant.  
Ils permettent :
- de **synchroniser** des actions,  
- de **notifier** des événements,  
- ou de **contrôler** l’exécution de programmes (pause, reprise, fin).  

Maîtriser `kill`, `trap`, et les signaux système est essentiel pour tout administrateur ou développeur sous UNIX/Linux.

---

[[08_Processus]] ← → [[10_Tubes]]
