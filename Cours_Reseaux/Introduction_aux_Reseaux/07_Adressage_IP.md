
## Introduction

L’adressage IP permet d’identifier chaque machine sur un réseau. Sans adresses IP, aucune communication n’est possible : ni sur Internet, ni au sein d’un réseau local. Deux versions du protocole existent :  
- **IPv4** : historique, encore majoritaire, limité à ~4 milliards d’adresses  
- **IPv6** : moderne, conçu pour remplacer IPv4 avec un espace d’adressage colossal

---

# 7.1 — Adressage IPv4

## Représentation
Une adresse IPv4 est codée sur **32 bits**, notée en **décimal pointé** :
192.168.1.10

Structure :  
- 4 octets (0–255)  
- Exemple en binaire : 11000000.10101000.00000001.00001010

---

# 7.2 — Masque de sous-réseau

Le masque divise l’adresse en deux parties : partie réseau / partie hôte.

Exemple : 255.255.255.0  
Notation CIDR : /24  

Rôles : définir les hôtes appartenant au réseau, trouver l’adresse réseau et broadcast.

---

# 7.3 — Adresse réseau et broadcast

Pour 192.168.1.0/24 :  
- Adresse réseau : 192.168.1.0  
- Broadcast : 192.168.1.255  
- Hôtes : 192.168.1.1 → 192.168.1.254  
- Nombre d’hôtes : 254

---

# 7.4 — Classes IPv4 (historique)

| Classe | Plage | Taille |
| A | 0–127 | énorme |
| B | 128–191 | moyenne |
| C | 192–223 | petite |

Aujourd’hui remplacées par CIDR mais utile historiquement.

---

# 7.5 — Adresses privées et publiques

Adresses privées (non routables) :  
- 10.0.0.0/8  
- 172.16.0.0/12  
- 192.168.0.0/16  

Adresses publiques : routables, attribuées par RIPE/ARIN.

---

# 7.6 — NAT (Network Address Translation)

Partage d’une adresse publique entre plusieurs hôtes privés.

Avantages : économie d’IPv4, sécurité, utilisé dans toutes les box.  
Ex : PC 192.168.1.10 → Box NAT → 82.xxx.xxx.xxx

---

# 7.7 — DHCP (Dynamic Host Configuration Protocol)

Attribue automatiquement IP, masque, passerelle, DNS.

Avantages : automatisation, éviter les conflits, gestion centrale.  
Ports : UDP 67 (serveur), UDP 68 (client).

---

# 7.8 — ARP (Address Resolution Protocol)

Associe IP ↔ MAC.

Fonctionnement :  
1. diffusion « Qui a 192.168.1.10 ? »  
2. réponse avec l’adresse MAC  
3. mise à jour table ARP

---

# 7.9 — Adressage IPv6

IPv4 est saturé → IPv6 fournit un espace immense.

Caractéristiques :  
- 128 bits  
- notation hexadécimale (ex : 2001:db8::1)  
Avantages : pas de NAT, auto-config (SLAAC), IPsec, routage simplifié.

---

# 7.10 — Types d’adresses IPv6

- Global Unicast (publique)  
- Link-Local (fe80::/10) obligatoire  
- Multicast (remplace broadcast)  
- **Pas de broadcast** en IPv6

---

# 7.11 — Transition IPv4 ↔ IPv6

Méthodes :  
- dual stack  
- tunnels  
- NAT64 / DNS64  

Transition lente mais en progression.

---

# Synthèse

IPv4 : 32 bits, masque, réseau/broadcast, privé/public, NAT, DHCP, ARP.  
IPv6 : 128 bits, pas de broadcast, auto-config, sécurité native.

Comprendre l’adressage est essentiel pour la configuration réseau et le routage.

---

# Backlinks

[[06_Materiel_reseau]] ← → [[08_Routage]]
