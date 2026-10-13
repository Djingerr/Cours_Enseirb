# L’ordinateur et son fonctionnement
[[01_Introduction_Systemes_Exploitation]] ← → [[03_Shell_Bash]]

---

## Introduction

Ce chapitre présente le **fonctionnement général de l’ordinateur**, les composants matériels essentiels, et la manière dont ils interagissent pour exécuter des programmes.  
Il sert de base pour comprendre le rôle du **système d’exploitation**, qui coordonne ces éléments.

---

## Chapitre 1 — Qu’est-ce qu’un ordinateur ?

### 1.1 Définition

Un **ordinateur** est une machine capable de **traiter automatiquement des informations** selon un ensemble d’instructions appelé **programme**.  
Son rôle est de **recevoir**, **traiter** et **produire** des données.

### 1.2 Architecture de von Neumann

Le modèle de von Neumann définit l’organisation fondamentale d’un ordinateur :

```
+-------------------------------+
|     Programmes et données     |
|     (Mémoire principale)      |
+---------------+---------------+
                |
                v
+---------------+---------------+
|   Unité de traitement (CPU)   |
|   - Unité de commande         |
|   - Unité arithmétique/logique|
+---------------+---------------+
                |
                v
+---------------+---------------+
|     Entrées / Sorties         |
+-------------------------------+
```

**Principe clé :** les **programmes et les données** sont stockés dans la même mémoire.

### 1.3 Composants principaux

- **Unité centrale (CPU)** : exécute les instructions.  
- **Mémoire** : contient les programmes et les données.  
- **Périphériques** : assurent la communication avec l’extérieur (clavier, écran, disque, etc.).

---

## Chapitre 2 — Le processeur (CPU)

### 2.1 Rôle et fonctionnement

Le **processeur** (Central Processing Unit) est le cœur de l’ordinateur.  
Il effectue le **cycle d’instruction** :

1. **Fetch** : lecture d’une instruction en mémoire.  
2. **Decode** : interprétation de l’instruction.  
3. **Execute** : exécution sur les données concernées.  
4. **Store** : enregistrement du résultat.

Ce cycle se répète **des milliards de fois par seconde**.

### 2.2 Organisation interne

Le CPU contient :
- une **unité de commande** : pilote le déroulement du programme,  
- une **unité arithmétique et logique (UAL)** : réalise les opérations,  
- des **registres** : mémoire très rapide pour stocker temporairement les données.

**Schéma simplifié :**

```
+-------------------------+
|   Unité de commande     |
|  - Compteur ordinal (PC)|
|  - Décodeur             |
+-----------+-------------+
            |
            v
+-----------+-------------+
| UAL : opérations logiques|
| et arithmétiques         |
+-----------+-------------+
            |
            v
+-----------+-------------+
| Registres de travail    |
+-------------------------+
```

### 2.3 Jeu d’instructions

Le **jeu d’instructions** définit l’ensemble des opérations que le processeur peut exécuter.  
Chaque architecture (Intel, ARM, RISC-V…) possède son propre jeu d’instructions.

Exemples :
- `LOAD R1, A` : charger la valeur à l’adresse A dans le registre R1.  
- `ADD R2, R1` : additionner la valeur du registre R2 avec celle de R1.  
- `STORE R2, B` : sauvegarder le contenu de R2 à l’adresse B.

---

## Chapitre 3 — Mémoire et hiérarchie

### 3.1 Typologie de la mémoire

| Type | Rôle | Vitesse | Volatilité |
|------|------|----------|-------------|
| **Registres** | Stockage interne au CPU | Très rapide | Volatile |
| **Cache** | Tampon entre CPU et RAM | Très rapide | Volatile |
| **RAM** | Mémoire principale | Rapide | Volatile |
| **Disque dur / SSD** | Stockage permanent | Lent | Non volatile |

### 3.2 Hiérarchie mémoire

```
+---------------------------+
| Registres (ns)            |
+---------------------------+
| Cache L1 / L2 (ns à µs)   |
+---------------------------+
| RAM (µs)                  |
+---------------------------+
| Disque / SSD (ms)         |
+---------------------------+
| Réseau / Cloud (s)        |
+---------------------------+
```

Le système d’exploitation gère cette hiérarchie pour **optimiser l’accès aux données**.

---

## Chapitre 4 — Du matériel au logiciel

### 4.1 Instructions et programmes

Un **programme** est une suite d’instructions machine.  
Lorsqu’il est exécuté, il devient un **processus** (concept vu au prochain chapitre).

### 4.2 Langages et niveaux d’abstraction

| Niveau | Exemple | Traduction |
|--------|----------|------------|
| **Machine** | Code binaire | Directement interprété par le CPU |
| **Assembleur** | `MOV AX, BX` | Langage bas niveau |
| **Langage C** | `x = y + z;` | Traduit en assembleur par le compilateur |

Le système d’exploitation assure la **traduction et la coordination** entre ces niveaux.

### 4.3 Exemple d’exécution simplifiée

```
Programme : afficher la somme de deux nombres
→ Le code est compilé → traduit en instructions machine
→ Le processeur exécute ces instructions
→ Le système d’exploitation gère l’affichage du résultat
```

---

## Chapitre 5 — Entrées / Sorties (I/O)

Les périphériques (clavier, écran, disques…) échangent des données avec le processeur via des **canaux d’entrée/sortie**.

### 5.1 Principe de fonctionnement

```
Utilisateur
   ↓
Logiciel
   ↓
Système d’exploitation
   ↓
Pilote (driver)
   ↓
Matériel
```

Le **driver** traduit les requêtes logicielles en signaux compréhensibles par le matériel.

### 5.2 Gestion par interruptions

Lorsqu’une opération I/O est terminée, le périphérique **interrompt le processeur** pour signaler la fin du transfert.  
Cela évite au CPU d’attendre inutilement (gain de performance).

---

## Synthèse finale

L’ordinateur repose sur une organisation **hiérarchisée et coordonnée** :
- le **processeur** exécute les instructions,  
- la **mémoire** stocke programmes et données,  
- les **périphériques** assurent les échanges,  
- le **système d’exploitation** orchestre l’ensemble.

Ce modèle de fonctionnement prépare la compréhension du concept de **processus**, abordé dans le chapitre suivant.

---

[[01_Introduction_Systemes_Exploitation]] ← → [[03_Shell_Bash]]
