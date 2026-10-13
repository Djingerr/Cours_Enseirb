# 01E — Architecture des Réseaux

## Introduction
L’architecture des réseaux est un élément fondamental pour comprendre comment les systèmes communiquent. Elle organise les fonctions nécessaires à la transmission de données en différentes **couches**, chacune remplissant une mission bien définie. Cette structuration permet :
- d’assurer l’interopérabilité entre équipements,
- de réduire la complexité,
- de faciliter la maintenance,
- de favoriser l’évolution des technologies.

Ce sous-chapitre détaille les modèles en couches (OSI et TCP/IP), la notion d’encapsulation, les PDU, ainsi que les modes connecté/non connecté.

---
# 1. Pourquoi une architecture en couches ?
Les réseaux sont des systèmes extrêmement complexes, impliquant :
- signaux physiques,
- adressage,
- contrôle d’erreur,
- routage,
- sessions,
- applications.

Pour gérer cette complexité, on utilise un **modèle en couches** où :
- chaque couche réalise une fonction précise,
- les couches supérieures s’appuient sur les services des couches inférieures,
- les couches inférieures ignorent le contenu sémantique des couches supérieures.

### Avantages :
- modularité,
- évolutivité,
- standardisation,
- indépendance matérielle/logicielle,
- simplification de la conception.

---
# 2. Principes fondamentaux

## 2.1 Les couches
Une couche représente un ensemble de fonctions homogènes. Elle communique uniquement avec :
- la couche immédiatement supérieure,
- la couche immédiatement inférieure,
- son homologue sur un autre système (via un protocole).

## 2.2 Les interfaces
Les interfaces définissent les services qu’une couche propose aux couches voisines.

## 2.3 Les protocoles
Un protocole est un ensemble de règles permettant aux entités homologues (de même couche) de dialoguer.

Un protocole définit :
- le **format** des messages,
- les **actions** à réaliser à l’envoi et à la réception,
- les règles de **synchronisation**, de **détection d’erreurs**, etc.

Exemple : IP, TCP, Ethernet.

---
# 3. Encapsulation & PDU

Lorsqu’un message traverse les couches d’un système émetteur, chaque couche ajoute ses propres informations de contrôle. Ce processus est appelé **encapsulation**.

### Processus :
- Couche Application : message M
- Couche Transport : segment (M + entête)
- Couche Réseau : paquet (segment + entête)
- Couche Liaison : trame (paquet + entête + contrôle)
- Couche Physique : bits transmis

À la réception, le processus inverse (désencapsulation) reconstruit le message.

Les PDU (Protocol Data Units) :
- Couche 4 : **Segment**
- Couche 3 : **Paquet**
- Couche 2 : **Trame**
- Couche 1 : **Bits**

---
# 4. Le modèle OSI (Open Systems Interconnection)

Le modèle OSI, proposé par l’ISO en 1984, est une référence descriptive pour organiser les fonctions réseau en **7 couches**.

## 4.1 Couche 1 — Physique
- Transmet les bits bruts.
- Définit : signaux, tensions, supports, connecteurs.
- Exemple : fibre optique, cuivre, modulation.

## 4.2 Couche 2 — Liaison de données
- Transporte des trames entre deux nœuds adjacents.
- Détecte/corrige les erreurs.
- Gère l’accès au support.
- Adressage **MAC**.
- Exemples : Ethernet, PPP, HDLC.

## 4.3 Couche 3 — Réseau
- Transporte des **paquets** à travers un réseau de nœuds.
- Réalise le **routage**.
- Adressage **IP**.
- Exemple : IPv4, IPv6.

## 4.4 Couche 4 — Transport
- Fournit une communication de bout en bout.
- Gère : multiplexage, contrôle d’erreur, ports.
- Protocoles : **TCP** (fiable), **UDP** (non fiable).

## 4.5 Couche 5 — Session
- Établit, maintient, termine les sessions.
- Points de reprise.
- Gestion du dialogue.

## 4.6 Couche 6 — Présentation
- Conversion syntaxique : formats, encodages.
- Compression, chiffrement.

## 4.7 Couche 7 — Application
- Point d’accès aux services réseau.
- Protocoles : HTTP, SMTP, FTP, DNS.

### Rôle du modèle OSI
- Facilite la compréhension
- Sert de guide pédagogique
- Pas utilisé tel quel dans les réseaux réels

---
# 5. Le modèle TCP/IP
Le modèle TCP/IP est le modèle **réellement utilisé** dans Internet.

Il comporte 4 couches :

## 5.1 Couche Application
Inclut : HTTP, FTP, DNS, SMTP…  
Elle regroupe les couches 5, 6 et 7 du modèle OSI.

## 5.2 Couche Transport
- TCP : fiable, orienté connexion
- UDP : non fiable, léger

## 5.3 Couche Internet
- Protocole IP (IPv4/IPv6)
- Routage, adressage logique

## 5.4 Couche Accès réseau
- Combine les couches 1 et 2 OSI
- Interfaces matérielles : Ethernet, Wi-Fi, etc.

---
# 6. Comparaison OSI vs TCP/IP

| Fonction | Modèle OSI | Modèle TCP/IP |
|----------|-------------|----------------|
| Couches | 7 | 4 |
| Orientation | pédagogique, théorique | pratique, utilisé dans Internet |
| Session/Présentation | séparées | incluses dans Application |
| Physique/Liaison | séparées | fusionnées dans Accès réseau |

### Points clés :
- TCP/IP = modèle opérationnel
- OSI = modèle d’apprentissage
- Ils sont compatibles conceptuellement

---
# 7. Modes de communication

## 7.1 Mode connecté
- Établissement → transfert → terminaison
- Réservation potentielle de ressources
- Exemple : **TCP**, X.25, PPP

### Avantages :
- Qualité de transfert
- Suivi de l’état

### Inconvénients :
- Établissement lourd
- Moins adapté à la diffusion

---
## 7.2 Mode non connecté
- Pas d’établissement préalable
- Messages auto-suffisants (datagrammes)
- Exemple : **IP**, UDP

### Avantages :
- Rapide
- Flexible
- Optimisé pour la donnée utile

### Inconvénients :
- Pas de garantie de livraison
- Pas de contrôle d’ordre

---
# 8. Exemple de conversation OSI
Communication entre deux hôtes A et B via routeur intermédiaire :
- A encapsule les données couche par couche.
- Le routeur traite jusqu’à la couche 3 (réseau).
- B désencapsule les données pour reconstruire le message.

Ce schéma illustre la puissance du découpage fonctionnel.

---
# Synthèse
Dans ce sous-chapitre, nous avons vu :
- l'intérêt des architectures en couches,
- le modèle OSI et ses 7 couches,
- le modèle TCP/IP utilisé dans Internet,
- les mécanismes d’encapsulation,
- les PDU et la circulation verticale / horizontale des données,
- les modes connecté et non connecté.

Ces notions sont indispensables pour comprendre, dans les sous-chapitres suivants, la normalisation et la couche physique.

---
## Navigation
- ⬅️ Sous-chapitre précédent : [[01D_Types_Reseaux]]
- ➡️ Sous-chapitre suivant : [[01F_Normalisation]]
- 🏠 Sommaire du chapitre : [[01_Sommaire_Concepts_Generaux]]
- 📘 Sommaire général du cours : [[00_Sommaire]]