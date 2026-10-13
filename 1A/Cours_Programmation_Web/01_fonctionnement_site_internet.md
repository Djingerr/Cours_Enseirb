# Fonctionnement d’un site Internet

## Introduction

Avant d’écrire la moindre ligne de code HTML, CSS ou PHP, il est indispensable de comprendre **comment fonctionne un site Internet**. Ce chapitre pose les bases techniques nécessaires pour comprendre ce qui se passe lorsqu’un utilisateur consulte une page web.

Nous allons étudier :
- l’architecture **client/serveur**
- le rôle du **navigateur**
- le chemin complet entre une **adresse web** et l’affichage d’une page
- le fonctionnement du **protocole HTTP**
- la différence entre **sites statiques** et **sites dynamiques**

---

## Chapitre 1 : Architecture client / serveur

### 1.1 Principe général

Le web repose sur une **architecture client/serveur** :

- Le **client** est un programme qui formule des demandes
- Le **serveur** est un programme (souvent sur une autre machine) qui traite ces demandes et renvoie des réponses

La communication se fait à travers un **réseau**, généralement Internet.

### 1.2 Le client

Le **client** :
- demande des ressources (pages HTML, images, fichiers CSS, etc.)
- envoie une **requête** au serveur

Exemples de clients :
- navigateurs web (Firefox, Chrome, Edge…)
- outils en ligne de commande (`curl`, `wget`, `telnet`, `nc`)

👉 Un navigateur n’est donc **pas le seul** type de client possible.

### 1.3 Le serveur

Le **serveur** :
- reçoit les requêtes des clients
- les traite
- renvoie une **réponse**

Caractéristiques importantes :
- peut servir **plusieurs clients simultanément**
- est généralement **disponible en permanence**
- est souvent une machine dédiée, mais reste un ordinateur « classique »

Par métonymie, le terme *serveur* peut désigner :
- la **machine**
- le **logiciel serveur**

---

## Chapitre 2 : Le navigateur web

### 2.1 Rôle principal

Le **navigateur web** est un programme qui permet :
- d’envoyer des requêtes HTTP
- de recevoir des réponses HTTP
- d’interpréter et afficher des pages web

Il joue un rôle central dans l’expérience utilisateur.

### 2.2 Fonctions du navigateur

Un navigateur est capable de :
- afficher des documents **HTML**
- appliquer des règles **CSS**
- exécuter du **JavaScript**
- gérer les cookies, le cache, l’historique

👉 Il agit comme un **interprète** entre le code reçu et l’affichage visuel.

### 2.3 Navigateurs graphiques et textuels

- Navigateurs graphiques : Firefox, Chrome, Edge, Opera, Brave
- Navigateurs textuels : Lynx, w3m

Tous reposent sur les mêmes principes fondamentaux.

---

## Chapitre 3 : De l’adresse web à la page affichée

### 3.1 Qu’est-ce qu’une URL ?

Une **URL (Uniform Resource Locator)** est l’adresse complète d’une ressource web.

Exemple :
```
http://user:password@www.serveur.org:8080/chemin/truc.php?param=foo#ancre
```

Une URL peut contenir :
- le **protocole** (http, https)
- l’**hôte** (nom de domaine)
- le **port**
- le **chemin** vers la ressource
- des **paramètres**
- une **ancre**

### 3.2 Étape 1 : résolution DNS

Le navigateur doit traduire le **nom de domaine** en **adresse IP**.

- Il interroge un serveur **DNS (Domain Name System)**
- Le DNS répond avec une adresse IP

Exemple :
```
mon-super-site.fr → 123.254.65.12
```

### 3.3 Étape 2 : requête HTTP

Une fois l’adresse IP connue :
- le client envoie une **requête HTTP** au serveur
- généralement une requête **GET**

Exemple simplifié :
```
GET / HTTP/1.0
```

### 3.4 Étape 3 : réponse HTTP

Le serveur renvoie une **réponse HTTP** composée de :
1. **en-têtes** (métadonnées)
2. **contenu** (souvent du HTML)

Exemple :
- code de statut : `200 OK`
- type de contenu : `text/html`
- corps : code HTML

Le navigateur interprète ensuite cette réponse.

---

## Chapitre 4 : Le protocole HTTP

### 4.1 Définition

**HTTP (HyperText Transfer Protocol)** est le protocole utilisé pour échanger des données entre client et serveur web.

Caractéristiques :
- basé sur **TCP**
- protocole **texte**
- protocole **sans état** (stateless)

### 4.2 Méthodes HTTP principales

- **GET** : demander une ressource
- **POST** : envoyer des données
- **DELETE** : supprimer une ressource

### 4.3 Codes de réponse courants

- `200 OK`
- `404 Not Found`
- `500 Internal Server Error`

Ces codes indiquent le résultat du traitement de la requête.

### 4.4 HTTP vs HTTPS

- **HTTP** : non sécurisé (port 80)
- **HTTPS** : version sécurisée (port 443)
  - données chiffrées via **TLS**

HTTPS est aujourd’hui indispensable.

---

## Chapitre 5 : Sites statiques et dynamiques

### 5.1 Site statique

Un **site statique** :
- repose sur des fichiers existants
- le serveur se contente de les renvoyer

Types de fichiers :
- HTML
- CSS
- JavaScript
- images

### 5.2 Site dynamique

Un **site dynamique** :
- exécute du code côté serveur
- génère le contenu à la volée

Il peut :
- interagir avec une **base de données**
- appeler d’autres services
- produire du HTML dynamiquement

### 5.3 Rôle du serveur

- lecture de fichiers (statique)
- exécution de code (dynamique)
- communication avec d’autres composants (BDD, API)

---

## Synthèse du chapitre

Dans ce chapitre, nous avons vu que :
- le web repose sur une **architecture client/serveur**
- le navigateur est un **client interprète**
- une page web est obtenue via **DNS + HTTP**
- HTTP structure les échanges
- les sites peuvent être **statiques ou dynamiques**

Ces notions sont fondamentales pour comprendre la suite du cours.

---

[[00_introduction_a_la_programmation_web]] | [[02_html_structuration_du_contenu]]

