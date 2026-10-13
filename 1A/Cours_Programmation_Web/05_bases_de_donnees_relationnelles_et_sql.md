# Bases de données relationnelles et SQL

## Introduction

Les applications web dynamiques ont besoin de **stocker durablement des données** : articles, utilisateurs, commentaires, commandes, etc. Les bases de données relationnelles répondent à ce besoin en offrant un stockage structuré, performant et sûr.

Ce chapitre introduit les **principes des bases de données relationnelles**, le rôle des **SGBD** et le langage **SQL**, utilisé pour interagir avec ces bases.

---

## Chapitre 1 : Pourquoi utiliser une base de données ?

### 1.1 Limites des fichiers texte

Stocker des données dans des fichiers texte pose de nombreux problèmes :
- difficulté à structurer les données
- accès lent pour de gros volumes
- complexité des recherches
- gestion délicate des accès concurrents

### 1.2 Objectifs d’une base de données

Une base de données permet :
- de stocker des **données structurées**
- d’accéder rapidement aux données
- d’assurer la cohérence des informations
- de gérer plusieurs accès simultanés

---

## Chapitre 2 : Bases de données relationnelles

### 2.1 Principe général

Une base de données relationnelle organise les données sous forme de **tables** composées de :
- **lignes** (enregistrements)
- **colonnes** (attributs)

Les tables peuvent être **liées entre elles** par des relations.

### 2.2 Exemple de modélisation

Exemple simplifié :

- **Articles** (`id`, `titre`, `contenu`, `auteur`, `date`)
- **Commentaires** (`id`, `commentaire`, `auteur`, `date`, `article_id`)

Le champ `article_id` permet de relier un commentaire à un article.

---

## Chapitre 3 : Systèmes de Gestion de Bases de Données (SGBD)

### 3.1 Définition

Un **SGBD** est un logiciel chargé :
- de stocker les données
- d’exécuter les requêtes
- de garantir l’intégrité des données

### 3.2 Exemples de SGBD

- **MySQL / MariaDB**
- **PostgreSQL**
- **Oracle**
- **Microsoft SQL Server**
- **SQLite** (base stockée dans un fichier)

---

## Chapitre 4 : Connexion à une base de données

### 4.1 Clients possibles

Pour interagir avec un SGBD, on peut utiliser :
- un client en ligne de commande (`mysql`, `psql`, `sqlite3`)
- une interface web (phpMyAdmin, Adminer)
- un logiciel graphique (MySQL Workbench, SQLiteStudio)
- une API dans un langage de programmation (PHP, Python, etc.)

### 4.2 Informations nécessaires

Pour une base distante :
- adresse du serveur
- port
- nom d’utilisateur
- mot de passe
- nom de la base

Pour SQLite :
- chemin du fichier

---

## Chapitre 5 : Le langage SQL

### 5.1 Définition

**SQL (Structured Query Language)** est un langage standard permettant :
- d’interroger une base de données
- d’ajouter, modifier et supprimer des données
- de définir la structure des tables

### 5.2 Grandes catégories de requêtes

- **DDL** : définition des structures (`CREATE`, `DROP`)
- **DML** : manipulation des données (`INSERT`, `UPDATE`, `DELETE`)
- **DQL** : interrogation des données (`SELECT`)

---

## Chapitre 6 : Requêtes SQL fondamentales

### 6.1 Création d’une table

```sql
CREATE TABLE articles (
  id INT PRIMARY KEY,
  titre TEXT,
  contenu TEXT,
  auteur TEXT,
  date DATE
);
```

### 6.2 Insertion de données

```sql
INSERT INTO articles VALUES (1, 'Titre', 'Contenu', 'Alice', '2024-01-01');
```

### 6.3 Sélection de données

```sql
SELECT * FROM articles;
```

### 6.4 Filtrage

```sql
SELECT * FROM articles WHERE auteur = 'Alice';
```

---

## Chapitre 7 : Relations entre tables

### 7.1 Clé primaire

Une **clé primaire** identifie de manière unique une ligne dans une table.

### 7.2 Clé étrangère

Une **clé étrangère** référence la clé primaire d’une autre table.

Exemple :
```sql
article_id INT REFERENCES articles(id)
```

Ces relations garantissent la **cohérence des données**.

---

## Chapitre 8 : SQL et applications web

Dans une application web :
- PHP envoie des requêtes SQL au SGBD
- le SGBD renvoie les résultats
- PHP transforme les résultats en HTML

La base de données devient le **cœur des données** de l’application.

---

## Chapitre 9 : Bonnes pratiques

- toujours valider les données avant insertion
- limiter les droits des utilisateurs SQL
- sauvegarder régulièrement les bases
- séparer logique applicative et données

---

## Synthèse du chapitre

Les bases de données relationnelles permettent :
- un stockage structuré et efficace
- des relations entre données
- une intégration naturelle avec PHP

Le langage SQL est incontournable pour toute application web dynamique.

---

[[04_php_programmation_web_cote_serveur]] | [[06_java_script_pages_dynamiques_cote_client]]