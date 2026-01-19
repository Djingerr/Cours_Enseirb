# 01A — Introduction aux Réseaux

## Introduction générale
Les réseaux constituent une infrastructure essentielle dans la société moderne. Ils permettent à des systèmes distants de communiquer, d’échanger des informations et de partager des ressources. Leur rôle va bien au-delà du simple transport de données : ils assurent un fonctionnement coordonné et fiable entre des millions de dispositifs interconnectés.

Ce premier sous-chapitre pose les bases nécessaires pour comprendre ce qu’est un réseau, quels en sont les composants, les services qu’il rend, ainsi que les concepts fondamentaux utiles pour aborder le reste du cours.

---

## 1. Définition d’un réseau
Le mot **réseau** possède plusieurs sens selon le contexte :
- **Sens concret** : un ensemble de lignes entrelacées (réseau routier, réseau électrique, réseau sanguin).
- **Sens figuré** : un ensemble de relations organisées (réseau social, réseau de collaborateurs).
- **Sens technique (informatique & télécom)** :
  > **Un ensemble de nœuds interconnectés permettant l’acheminement de l’information**, sous forme électrique, lumineuse ou électromagnétique.

Ainsi, un réseau informatique est un **système de communication** permettant :
- la transmission de données,
- l’accès à des ressources,
- la mise à disposition de services.

---

## 2. Finalité d’un réseau
La **vocation principale** d’un réseau est d’acheminer une information d’un point émetteur A à un point récepteur B **en la détériorant le moins possible**.

Pour remplir cet objectif, un réseau doit :
- fournir un support de communication fiable,
- utiliser des protocoles de transmission adaptés,
- gérer la synchronisation, les erreurs, la congestion,
- assurer un transport d’information efficace pour les utilisateurs.

Ces mécanismes forment la **base** de l’étude des réseaux.

---

## 3. Les éléments fondamentaux d’un réseau
Un réseau informatique repose sur trois types d’entités essentielles :

### 3.1. Les nœuds
Un nœud est tout dispositif connecté au réseau. Il existe deux grandes catégories :

#### ● Les hôtes (ou terminaux)
Ce sont des équipements **utilisateurs** du réseau.
- Ordinateurs
- Smartphones
- Tablettes
- Serveurs

Ils exécutent des applications (Web, email, stockage, calcul…), **génèrent** ou **consomment** l’information.

#### ● Les équipements de réseau
Ils ne consomment pas l’information : ils l’acheminent, la traitent ou la distribuent.
- Répéteurs
- Hubs
- Switchs
- Ponts (bridges)
- Routeurs
- Passerelles

Chaque type joue un rôle particulier dans la transmission et la structuration du réseau.

---

### 3.2. Les lignes de transmission
Ce sont les **supports** sur lesquels circule l'information.

On distingue :
- **Les supports métalliques** : paire torsadée, coaxial (courant en Ethernet)
- **La fibre optique** : transmission lumineuse à très haut débit
- **Les supports sans fil** : radio, micro-ondes, infrarouge

Ces supports déterminent :
- le débit possible,
- la portée de la communication,
- la résistance aux perturbations,
- le coût d'installation.

---

## 4. Les services offerts par un réseau
Les réseaux informatiques permettent un très large panel d'applications. Parmi les plus courantes :

- **Accès au Web** (HTTP/HTTPS)
- **Messagerie électronique** (SMTP, IMAP, POP)
- **Transfert de fichiers** (FTP, SFTP)
- **Partage d’applications et de ressources** (imprimantes, disques)
- **Accès distant** (SSH, VPN)
- **Services multimédias** (streaming, visioconférence)
- **Services temps réel** (VoIP, jeux en ligne)

Ces services imposent des contraintes différentes en termes de **débit**, **latence**, **fiabilité**, ou **sécurité**.

---

## 5. Objectifs principaux des réseaux
Un réseau informatique a trois objectifs fondamentaux :

### 5.1. Le partage des ressources
- Les ressources **logiques** : logiciels, bases de données, fichiers.
- Les ressources **physiques** : imprimantes, scanners, serveurs.

L'idée centrale est d'éviter la duplication et d'améliorer la disponibilité.

### 5.2. La communication entre utilisateurs
Elle peut être :
- interne (messagerie locale),
- externe (Internet),
- synchrone (visioconférence),
- asynchrone (email).

### 5.3. Le travail collaboratif
Les réseaux permettent :
- le suivi de projets,
- la synchronisation des agendas,
- la gestion des versions,
- le partage de documents,
- des environnements collaboratifs complets.

---

## 6. Notions clés pour l'étude des réseaux
Pour progresser dans ce cours, il est indispensable de maîtriser les notions suivantes :

- **Données vs information** : représentation logique et physique.
- **Topologie** : structure d'organisation d’un réseau.
- **Protocole** : ensemble de règles permettant la communication.
- **Modèle OSI / TCP-IP** : organisation fonctionnelle en couches.
- **Adresses réseau** : MAC, IP, noms de domaine.
- **Transmission** : signaux, codage, erreurs, débit.

Ces éléments seront détaillés dans les sous-chapitres suivants.

---

## Synthèse de ce sous-chapitre
Ce premier module pose les bases nécessaires à l’étude des réseaux :
- un réseau est un système d’échange d’informations entre nœuds ;
- il s’appuie sur des supports physiques, des équipements de communication et des protocoles ;
- il vise à fournir des services variés tout en optimisant la qualité et l’efficacité du transport des données.

Les sous-chapitres suivants approfondiront :
- la nature de l’information,
- l’évolution historique des réseaux,
- les types et topologies,
- les architectures (OSI, TCP/IP),
- la normalisation,
- la couche physique.

---
## Navigation
- ⬅️ Retour au sommaire du chapitre : [[01_Sommaire_Concepts_Generaux]]
- ➡️ Sous-chapitre suivant : [[01B_Nature_Information]]
- 🏠 Sommaire général du cours : [[00_Sommaire]]

