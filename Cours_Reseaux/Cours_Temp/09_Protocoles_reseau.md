
## Introduction
Un protocole réseau est un ensemble de règles permettant la communication entre machines.  
Il définit :
- le format des messages,
- leur ordre d’envoi/réception,
- les comportements en cas d’erreur.

Les protocoles garantissent l’interopérabilité entre équipements, logiciels et réseaux hétérogènes.  
On distingue plusieurs familles : transport, application, résolution de noms, sécurisation, etc.

---

# 9.1 — Protocoles applicatifs

## HTTP — HyperText Transfer Protocol
Utilisé pour le Web.  
Fonctionne en mode client–serveur, sur TCP port 80 (ou 443 via HTTPS).

Caractéristiques :
- stateless  
- méthodes : GET, POST, PUT, DELETE…  
- utilisé par les navigateurs et API Web  

## HTTPS
Version sécurisée de HTTP via **TLS**.  
Confidentialité, authentification, intégrité.

---

## DNS — Domain Name System
Associe un **nom de domaine** à une **adresse IP**.  
Exemples :
- google.com → 142.250.xxx.xxx  
- wikipedia.org → 208.80.xxx.xxx  

Fonctionnement :
- requête récursive ou itérative  
- hiérarchie mondiale (root → TLD → domain)

Ports : UDP/TCP 53.

---

## DHCP — Dynamic Host Configuration Protocol
Attribue automatiquement :
- adresse IP  
- masque  
- passerelle (gateway)  
- DNS  

Ports : UDP 67 / 68.

---

## FTP — File Transfer Protocol
Transfert de fichiers.  
Ports :
- 21 : contrôle  
- 20 : données  

Peu sécurisé (mot de passe en clair).  
Remplacé par SFTP/FTPS.

---

## SMTP / POP / IMAP
Protocoles de messagerie email.

- **SMTP** : envoi de mail (port 25 / 587)
- **POP** : récupération simple (port 110)
- **IMAP** : synchronisation complète (port 143)

Aujourd’hui utilisés avec TLS (en version sécurisée).

---

# 9.2 — Protocoles de transport

## TCP — Transmission Control Protocol
Transport **fiable**, **orienté connexion**.

Fonctionnalités :
- handshake 3-way  
- retransmission  
- contrôle de flux  
- contrôle de congestion  
- garantie d’ordre  

Idéal pour :
- Web (HTTPS)  
- mails  
- téléchargements  

## UDP — User Datagram Protocol
Transport **non fiable**, **sans connexion**, très rapide.

Caractéristiques :
- pas de retransmission  
- pas de garantie d’ordre  
- faible latence  

Idéal pour :
- streaming  
- VoIP  
- jeux en ligne  

---

# 9.3 — Protocoles de résolution et découverte

## ARP — Address Resolution Protocol
Associe IP ↔ MAC en IPv4.  
Base du fonctionnement Ethernet.

## NDP — Neighbor Discovery Protocol
Équivalent d'ARP pour IPv6.  
Fonctions supplémentaires : détection de routeur, auto-configuration.

## ICMP — Internet Control Message Protocol
Messages de diagnostic :
- echo request / reply (**ping**)  
- destination unreachable  
- TTL exceeded (traceroute)

ICMP est indispensable au bon fonctionnement IP.

---

# 9.4 — Protocoles sécurisés

## TLS — Transport Layer Security
Chiffre les communications.  
Utilisé par HTTPS, SMTP sécurisé, IMAP sécurisé…

Apporte :
- confidentialité  
- intégrité  
- authentification via certificats

## SSH — Secure Shell
Connexion distante sécurisée.  
Utilise clés publiques/privées.  
Port 22.

---

# 9.5 — Protocoles réseau internes

## STP — Spanning Tree Protocol
Évite les **boucles** dans les réseaux commutés (switchs).  
Versions modernes : **RSTP**, **MSTP**.

## VLAN — 802.1Q
Segmentation logique d’un LAN sur un même switch.  
Permet de séparer trafic utilisateur, serveur, VoIP, etc.

## LLDP — Link Layer Discovery Protocol
Découverte des équipements voisins.  
Très utile en administration réseau.

---

# 9.6 — Protocoles intermédiaires : NAT, VPN, tunnels

## NAT — Network Address Translation
Traduit les adresses IP privées ↔ publiques.  
Indispensable en IPv4.

## VPN — Virtual Private Network
Crée un tunnel sécurisé entre deux réseaux (ou un client ↔ un réseau).

Techno courantes :
- IPsec  
- OpenVPN  
- WireGuard  

## Tunnels
Enveloppent un protocole dans un autre.

Exemples :
- GRE  
- L2TP  
- 6to4 (IPv4 ↔ IPv6)

---

# 9.7 — Protocoles de routage
(aperçu, car détaillés dans le chapitre précédent)

- **RIP**  
- **OSPF**  
- **IS-IS**  
- **BGP**  

Ils permettent l’échange d’informations de topologie entre routeurs.

---

# 9.8 — Hiérarchie des protocoles : modèle TCP/IP

| Couche | Protocoles |
|--------|------------|
| **Application** | HTTP, DNS, FTP, SMTP, DHCP… |
| **Transport** | TCP, UDP |
| **Internet** | IP, ICMP, ARP, NDP |
| **Accès réseau** | Ethernet, WiFi… |

Les protocoles sont organisés pour permettre une communication modulaire, évolutive et cohérente.

---

# Synthèse
Les protocoles réseau :
- définissent le fonctionnement du Web, du mail, du DNS, du fichier…  
- reposent sur TCP ou UDP selon les besoins,  
- utilisent ARP, ICMP, DHCP, DNS pour la découverte et la résolution,  
- se sécurisent via TLS et SSH,  
- permettent le routage via OSPF/BGP,  
- sont organisés selon le modèle TCP/IP.

Ils constituent la base du fonctionnement d’Internet et des réseaux locaux.

---

# Backlinks
[[08_Routage]] ← → [[10_Securite_reseau]]
