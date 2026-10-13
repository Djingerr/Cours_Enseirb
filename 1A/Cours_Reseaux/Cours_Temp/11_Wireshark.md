
## Introduction
**Wireshark** est l’outil d’analyse réseau le plus utilisé au monde.  
Il permet de capturer, filtrer, inspecter et analyser en détail les paquets circulant sur un réseau.

Il est indispensable pour :
- diagnostiquer des problèmes réseau,
- comprendre le fonctionnement des protocoles,
- analyser des attaques (MITM, scans…),
- vérifier la conformité des communications,
- étudier les performances.

---

# 11.1 — Fonctionnement général

Wireshark capture les paquets en utilisant la bibliothèque **libpcap** (ou WinPcap/Npcap).  
Les paquets observés peuvent provenir de :
- l’interface Ethernet,
- le WiFi,
- un fichier `.pcap` ou `.pcapng`,
- un tunnel VPN,
- une interface virtuelle (loopback).

Il ne modifie jamais le trafic :  
➡️ **Wireshark est PASSIF**, purement observationnel.

---

# 11.2 — Interface de Wireshark

L’interface se divise en trois zones principales :

### 1. Liste des paquets
Chaque ligne représente un paquet :  
- numéro  
- temps  
- source  
- destination  
- protocole  
- info résumée

### 2. Décomposition détaillée
Arborescence des couches :  
Ethernet → IP → TCP/UDP → protocole applicatif (HTTP, DNS…)

### 3. Vue hexadécimale
Affichage binaire/hexadécimal du paquet original.

---

# 11.3 — Filtres de capture vs filtres d’affichage

## Filtres de capture
Appliqués **avant** la capture.  
Ils définissent quels paquets seront enregistrés.

Syntaxe : type libpcap

Exemples :
- `tcp port 80`
- `host 192.168.1.10`
- `net 10.0.0.0/24`
- `port 53`
- `arp`

## Filtres d’affichage
Appliqués **après** la capture.  
Beaucoup plus puissants, syntaxe différente.

Exemples :
- `ip.addr == 192.168.1.10`
- `tcp.flags.syn == 1`
- `http.request`
- `dns.qry.name == "google.com"`
- `icmp`

➡️ Très utilisés pour isoler les paquets pertinents.

---

# 11.4 — Analyse de protocoles

## DNS
On peut observer :
- les requêtes DNS (`Standard query`)
- les réponses (`Standard query response`)
- les codes d’erreur
- les records (A, AAAA, MX, NS…)

## TCP
Points analysés :
- handshake (SYN → SYN/ACK → ACK)
- fermeture de connexion
- retransmissions
- segments hors ordre
- perte de paquets
- lenteur liée au RTT

Filtres utiles :
- `tcp.analysis.retransmission`
- `tcp.flags.syn == 1`
- `tcp.port == 443`

## HTTP / HTTPS
HTTP visible en clair :  
méthodes (GET/POST), headers, codes 200/404…

HTTPS : contenu chiffré, mais handshake TLS visible :
- version TLS
- certificats
- algorithmes de chiffrement

## ARP
Idéal pour diagnostiquer :
- conflits d’IP
- attaque ARP spoofing
- machines inconnues

---

# 11.5 — Diagnostiquer des problèmes réseau

## Problème de DNS
- latence avant la résolution  
- serveur DNS qui ne répond pas  
- mauvais enregistrement DNS  

Filtre :
`dns`

## Problèmes TCP
- pertes, retransmissions  
- congestion  
- handshake incomplet  
- ports fermés

Filtres :
- `tcp.analysis.flags`
- `tcp.flags.syn == 1`

## Attaque ARP spoofing
Symptômes :
- réponses ARP multiples contradictoires  
- une même IP renvoyée par deux MAC  
- pollution de la table ARP  

Filtre :
`arp`

## Scans réseau
Nmap produit :
- de nombreuses requêtes SYN
- des paquets inhabituels  
- ports séquentiels testés

Filtre :
`tcp.flags.syn == 1`

---

# 11.6 — Export, sauvegarde, exploitation

Wireshark permet :
- d’exporter au format `.pcap` / `.pcapng`
- d’extraire des flux TCP/HTTP
- de reconstituer des fichiers transférés
- d’exporter les statistiques

Fonctions utiles :
- **Follow TCP stream**  
- **Statistics → Protocol hierarchy**  
- **Statistics → Conversations**  
- **Statistics → I/O Graphs**  

---

# 11.7 — Outils en ligne de commande associés

## tcpdump
Capture en CLI, très puissant :

Exemples :
- `tcpdump -i eth0`
- `tcpdump -n port 53`
- `tcpdump -w capture.pcap`

## tshark
Version CLI de Wireshark.  
Analyse, filtrage, décodage.

Exemples :
- `tshark -r capture.pcap`
- `tshark -Y http`
- `tshark -T fields -e ip.src -e ip.dst`

---

# 11.8 — Bonnes pratiques avec Wireshark

- Être sûr d’avoir le droit de capturer le trafic  
- Filtrer avant d’analyser  
- Utiliser les colonnes personnalisées  
- Capturer du côté “proche de la source”  
- Sauvegarder des **petites traces précises** plutôt qu’immenses  
- Ne pas analyser des captures en production sans autorisation  

---

# Synthèse
Wireshark est un outil essentiel pour :
- comprendre les protocoles réseau,
- diagnostiquer des problèmes,
- analyser des attaques,
- inspecter en profondeur le trafic.

Avec ses filtres puissants, ses vues détaillées et ses outils complémentaires (tshark, tcpdump), il constitue la référence mondiale de l’analyse réseau.

---

# Backlinks
[[10_Securite_reseau]] ← → [[12_Mise_en_pratique]]
