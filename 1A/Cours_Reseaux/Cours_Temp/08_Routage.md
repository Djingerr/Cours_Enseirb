
## Introduction
Le routage permet d’acheminer des paquets entre réseaux distincts. Contrairement à un switch (couche 2), le routeur travaille en **couche 3**, utilise les **adresses IP** et choisit le meilleur chemin vers la destination. Le routage est indispensable pour relier LAN, WAN, et Internet.

---

# 8.1 — Rôle du routeur
Le routeur :
- lit l’adresse IP de destination,
- consulte la table de routage,
- choisit le prochain saut (**next hop**),
- transmet le paquet sur la bonne interface.

Il permet de relier :  
LAN ↔ LAN, LAN ↔ WAN, WAN ↔ Internet.

---

# 8.2 — Table de routage
La table de routage contient les réseaux connus, leur masque, le next hop, l’interface et une métrique.

Exemple :
- 192.168.1.0/24 → via 192.168.0.1
- 10.0.0.0/8 → via eth0
- 0.0.0.0/0 → route par défaut (vers Internet)

La route **0.0.0.0/0** sert lorsque le routeur ne connaît pas la destination.

---

# 8.3 — Routage statique
Routes configurées manuellement.

Avantages :
- simplicité,
- aucun trafic de contrôle,
- contrôle total.

Inconvénients :
- ne s’adapte pas aux pannes,
- peu adapté aux grands réseaux.

Exemple :
ip route add 10.0.0.0/24 via 192.168.1.1

---

# 8.4 — Routage dynamique
Les routeurs échangent automatiquement des informations pour s’adapter aux changements du réseau.

Avantages : adaptation rapide, résilience, performance.  
Inconvénients : complexité, consommation de CPU/bande passante.

Deux familles :
- **Distance vector**
- **Link state**

---

# 8.5 — Protocoles IGP (routage interne)
Utilisés à l’intérieur d’un réseau (AS).

## RIP
- Distance vector
- Métrique = nombre de sauts (max 15)
- Simple mais limité

## OSPF
- Link state
- Algorithme de Dijkstra (chemin le plus court)
- Rapide, scalable
- Fonctionne avec des *aires*

## IS-IS
- Similarités avec OSPF
- Très utilisé chez les opérateurs

---

# 8.6 — BGP (routage externe)
BGP est utilisé **entre** réseaux autonomes.  
C’est le protocole qui fait fonctionner **Internet**.

Caractéristiques :
- extrêmement robuste,
- décisions basées sur les politiques,
- métrique principale : **AS-Path**.

---

# 8.7 — Types de routage
## Unicast
1 source → 1 destination.

## Multicast
1 source → plusieurs destinataires choisis.  
Utilisé pour IPTV, visio, streaming optimisé.

## Anycast
Plusieurs serveurs partagent la même adresse IP.  
Le routeur choisit le **plus proche**.  
Très utilisé pour les serveurs DNS mondiaux.

---

# 8.8 — Métriques de routage
Critères possibles :
- nombre de sauts,
- bande passante,
- latence,
- fiabilité,
- coût administrateur,
- charge.

Exemples :
- RIP → sauts
- OSPF → coût basé sur le débit
- BGP → politiques + longueur AS-Path

---

# 8.9 — Sous-réseaux et CIDR
Le routeur utilise les masques/CIDR pour déterminer :
- la partie réseau,
- la plage d’hôtes,
- les frontières entre sous-réseaux,
- la meilleure route.

Le sous-adressage améliore performance, sécurité et organisation.

---

# 8.10 — Parcours d’un paquet
1. Le PC envoie à la **passerelle** (via DHCP).  
2. Le routeur lit l’IP de destination.  
3. Il choisit un **next hop**.  
4. Le paquet traverse plusieurs routeurs.  
5. Le routeur final le remet au LAN cible.  
6. La machine destinataire reçoit le paquet.

Ce chemin est appelé **routing path**.

---

# Synthèse
Le routage :
- relie les réseaux entre eux,
- utilise des tables de routage,
- peut être statique ou dynamique,
- repose sur RIP/OSPF/IS-IS pour l’interne,
- sur BGP pour l’Internet mondial,
- prend en compte des métriques pour optimiser les chemins,
- s’appuie sur le CIDR pour l’organisation du réseau.

Il constitue la colonne vertébrale de la communication entre réseaux locaux et Internet.

---

# Backlinks
[[07_Adressage_IP]] ← → [[09_Protocoles_reseau]]
