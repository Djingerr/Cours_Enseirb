
## Introduction

Une architecture réseau définit **la manière dont les systèmes communiquent**, **les rôles des équipements**, et **les règles (protocoles)** permettant la transmission des données.

Deux grands modèles structurent la compréhension des architectures :
- le **modèle OSI** (référence théorique),
- le **modèle TCP/IP** (référence pratique).

Ils permettent de standardiser le dialogue entre machines hétérogènes.

---

# 4.1 Notion de couche

Une architecture en couches permet de **diviser les fonctions réseau** en blocs indépendants.

### Objectifs d’une architecture en couches :
- séparer les responsabilités techniques,
- permettre l’interopérabilité,
- faciliter les évolutions technologiques,
- isoler les problèmes,
- normaliser les interfaces entre couches.

Chaque couche fournit des **services** à la couche supérieure et s'appuie sur la couche inférieure.

---

# 4.2 Le modèle OSI (Open Systems Interconnection)

Le modèle OSI comporte **7 couches**, chacune ayant un rôle précis.

## Les 7 couches OSI

1. **Physique**  
   Transmission des signaux, support, modulation, câbles, fibre.

2. **Liaison de données**  
   Encapsulation en trames, détection d’erreurs, MAC, Ethernet.

3. **Réseau**  
   Routage, adressage IP, fragmentation des paquets.

4. **Transport**  
   Transport fiable ou non fiable : TCP, UDP.

5. **Session**  
   Gestion des sessions, synchronisation.

6. **Présentation**  
   Format des données, cryptage, compression, encodage.

7. **Application**  
   Services aux applications : HTTP, DNS, SMTP, FTP…

### Remarques :
- Les couches 5, 6, 7 sont peu distinguées dans la pratique moderne.
- Le modèle OSI est **conceptuel**, mais extrêmement utile pour comprendre les communications.

---

# 4.3 Le modèle TCP/IP

Le modèle TCP/IP simplifie OSI en **4 couches** :

1. **Accès réseau** (équivalent OSI 1-2)  
2. **Internet** (équivalent OSI 3)  
3. **Transport** (équivalent OSI 4)  
4. **Application** (équivalent OSI 5-7)

## Pourquoi TCP/IP s’est imposé ?
- C’est le modèle fondamental d’Internet.  
- Il est simple, robuste et efficace.  
- Il repose sur des protocoles normalisés mondialement.

### Protocole clé : IP  
- Fournit un service **non fiable**, **sans connexion**.  
- Acheminement des paquets au mieux : *best effort*.  
- Nécessite des couches supérieures fiables comme TCP lorsque nécessaire.

---

# 4.4 Comparaison OSI vs TCP/IP

| Aspect | OSI | TCP/IP |
|--------|-----|---------|
| But | Référence théorique | Référence pratique |
| Nombre de couches | 7 | 4 |
| Adoption | faible | mondiale |
| Transport | unifié mais conceptuel | TCP/UDP utilisés partout |
| Importance | pédagogique | opérationnelle |

---

# 4.5 Mode connecté vs non connecté

## Mode connecté (ex : TCP)
- Établissement préalable d’une connexion  
- Contrôle d’erreur  
- Congestion, retransmissions  
- Ordre garanti  
- Débit adapté

→ Idéal pour : navigation Web, téléchargement, messageries

## Mode non connecté (ex : UDP)
- Pas d’établissement de connexion  
- Pas de retransmission  
- Pas de garantie d’ordre  
- Très faible latence

→ Idéal pour : jeux en ligne, VoIP, streaming temps réel

---

# 4.6 Encapsulation et découpage

Lors d’une communication :

- chaque couche ajoute son propre **en-tête** (header),  
- les données descendent progressivement dans les couches,  
- les trames sont transmises physiquement,  
- à la réception, chaque couche enlève son en-tête.

Processus appelé :

### 🔹 **Encapsulation → Transmission → Décapsulation**

---

# 4.7 Equipements réseau selon les couches

| Équipement | Fonction | Couches |
|------------|----------|---------|
| **Hub** | Répétition du signal | Physique |
| **Switch** | Commutation de trames | Liaison |
| **Routeur** | Routage IP | Réseau |
| **Pare-feu** | Filtrage | 3-7 |
| **Passerelle** | Traduction de protocoles | Variable |

---

# 4.8 Architecture client–serveur vs pair-à-pair

## Client–serveur
- Un serveur central fournit ressources / services.
- Les clients demandent et reçoivent.

**Exemples :**
- HTTP
- DNS
- SMTP

## Peer-to-peer (P2P)
- Tous les nœuds peuvent être clients et serveurs.
- Échange direct et distribué.

**Exemples :**
- BitTorrent
- Réseaux blockchain

---

# Synthèse

Les architectures réseau reposent sur :

- le principe des **couches**,  
- les **modèles OSI et TCP/IP**,  
- différents **services** (connecté/non connecté),  
- l’**encapsulation**,  
- les rôles des **équipements réseau**.

Comprendre ces structures est essentiel avant l’étude des protocoles et technologies plus avancés.

---

# Backlinks

[[03_Types_de_reseaux]] ← → [[05_Normalisation_des_reseaux]]
