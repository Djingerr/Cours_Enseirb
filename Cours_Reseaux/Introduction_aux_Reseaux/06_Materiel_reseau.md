
## Introduction

Le fonctionnement d’un réseau informatique repose sur divers équipements ayant chacun un rôle spécifique : acheminer les données, segmenter le réseau, filtrer le trafic, connecter les utilisateurs, etc.

Connaître ces équipements permet de comprendre comment les réseaux sont construits physiquement et comment ils interagissent.

---

# 6.1 Hub (répéteur multi-ports)

Le **hub** est l’équipement réseau le plus simple.

### Fonction
- Répète tout signal reçu sur **tous** les ports.
- Agit au niveau **physique** (couche 1 OSI).

### Caractéristiques
- Pas d’intelligence : aucune analyse des trames.
- Partage de bande passante entre ports.
- Collisions fréquentes (Ethernet half-duplex).

### Inconvénients
- Non sécurisé  
- Non performant  
- Obsolète dans les réseaux modernes  

---

# 6.2 Switch (commutateur)

Le **switch** est aujourd’hui l’équipement central des réseaux LAN.

### Fonction
- Envoie les trames uniquement **au bon destinataire** grâce à la table MAC.
- Opère en **couche 2** (liaison de données).

### Avantages
- Réduction des collisions  
- Bande passante dédiée par port  
- Support du **full-duplex**  
- Faible latence  

### Fonctions avancées
- VLAN (802.1Q)  
- STP / RSTP (boucles réseau)  
- QoS (qualité de service)  
- LACP (agrégation de liens)  

---

# 6.3 Routeur

Le **routeur** permet d’interconnecter plusieurs réseaux différents (LAN, WAN…).

### Fonction
- Transmission basée sur les **adresses IP**.  
- Opère en **couche 3** (réseau).  

### Rôles principaux
- Routage (OSPF, RIP, BGP…)  
- NAT (traduction d’adresses)  
- Filtrage de base  
- Accès Internet  

---

# 6.4 Passerelle (Gateway)

Une **passerelle** permet de **traduire des protocoles** ou formats différents.

### Exemples
- VoIP ↔ téléphonie classique  
- IPv4 ↔ IPv6  
- MQTT ↔ HTTP (IoT)  

Elle peut se situer à **plusieurs couches OSI** selon sa fonction.

---

# 6.5 Modem (Modulateur–Démodulateur)

Le **modem** convertit les signaux numériques en signaux analogiques (et inversement).

### Exemples
- Modem ADSL  
- Modem câble  
- Modem 4G / 5G  

### Utilité
- Permet la communication via supports non nativement numériques.

---

# 6.6 Point d’accès sans fil (AP — Access Point)

Le **point d’accès WiFi** permet la connexion d’appareils sans fil à un réseau LAN.

### Caractéristiques
- Couverture radio (802.11)  
- Authentification (WPA2, WPA3)  
- Gestion des canaux et bandes de fréquences  

### AP vs Routeur
- Un **AP pur** ne fait pas de routage.
- Les routeurs domestiques regroupent AP + switch + NAT.

---

# 6.7 Pare-feu (Firewall)

Le **firewall** filtre le trafic selon des règles.

### Types
- Pare-feu réseau (entre LAN et Internet)  
- Pare-feu applicatif (WAF)  
- Pare-feu personnel (machine locale)  

### Fonctions
- Filtrage IP / ports  
- Inspection profonde des paquets (DPI)  
- Détection d’intrusions  

Opère entre les couches **3 à 7**.

---

# 6.8 Load Balancer (répartiteur de charge)

Répartit le trafic entre plusieurs serveurs.

### Objectifs
- Haute disponibilité  
- Performance  
- Résilience  

### Modes
- L4 (IP/port)  
- L7 (HTTP/URL)  

---

# 6.9 Serveurs réseau

Rôles possibles :
- serveur DNS  
- serveur DHCP  
- serveur Web  
- serveur mail  
- serveur fichier  
- serveur proxy  

Les serveurs forment l’infrastructure logicielle au-dessus du matériel physique.

---

# 6.10 Câbles, fibre et connectiques

### Cuivre (RJ45)
- Ethernet 10/100/1000 Mb/s  
- Catégories : Cat5e, Cat6, Cat6a, Cat7…

### Fibre optique
- Très longue distance  
- Très haut débit (Gb/s → Tb/s)  
- Monomode / multimode  

### Connectiques
- RJ45  
- LC / SC (fibre)  
- SMA, N (radio)  

---

# 6.11 Matériel réseau dans une architecture moderne

Exemple classique dans une entreprise :

1. **Routeur opérateur**  
2. **Périmètre de sécurité** (firewall)  
3. **Switch cœur de réseau**  
4. **Switchs d’étage**  
5. **Points d’accès WiFi**  
6. **Serveurs internes**  
7. **Passerelles spécifiques** (VPN, VoIP…)  

Chaque élément participe à la construction du réseau global.

---

# Synthèse

Les équipements réseau permettent :
- la transmission (modem, AP, câbles),
- la commutation locale (switch),
- le routage inter-réseaux (routeur),
- la sécurité (firewall),
- l’équilibrage (load balancer),
- les services (serveurs réseau).

Le matériel forme la base physique indispensable au fonctionnement des réseaux modernes.

---

# Backlinks

[[05_Normalisation_des_reseaux]] ← → [[07_Adressage_IP]]
