
## Introduction
La sécurité réseau regroupe l’ensemble des mécanismes permettant de protéger les communications, les données et les équipements contre les attaques, intrusions et défaillances.  
Elle repose sur plusieurs objectifs fondamentaux :
- **Confidentialité** : empêcher la lecture non autorisée
- **Intégrité** : garantir que les données ne sont pas modifiées
- **Disponibilité** : garantir l’accès continu aux services
- **Authentification** : vérifier l’identité des utilisateurs/équipements
- **Traçabilité** : conserver des preuves et logs

---

# 10.1 — Menaces et attaques courantes

## 10.1.1 — Attaques réseau
- **Sniffing** : capture du trafic (Wireshark)  
- **Spoofing** : usurpation d'identité (IP/ARP/DNS spoofing)  
- **MITM — Man In The Middle** : interception et modification du trafic  
- **DoS / DDoS** : surcharge d’un service pour le rendre indisponible  
- **Scanning** : reconnaissance réseau (Nmap)  
- **Injection** : altération de flux (DNS poisoning, injection HTTP…)  

---

# 10.1.2 — Vulnérabilités
- Services non mis à jour  
- Mots de passe faibles  
- Port ouvert inutile  
- Mauvaise configuration réseau  
- Absence de segmentation (tout le monde voit tout)  
- Pare-feu mal configuré  
- Protocoles non chiffrés (HTTP, FTP…)

---

# 10.2 — Sécurisation des communications

## 10.2.1 — Chiffrement
Le chiffrement protège la **confidentialité**.

### Chiffrement symétrique
Une seule clé (AES, DES). Très rapide.

### Chiffrement asymétrique
Clé publique / clé privée (RSA, ECC).  
Utilisé pour :
- certificats,
- HTTPS,
- SSH.

### TLS (Transport Layer Security)
Couche de sécurité pour :
- HTTPS  
- SMTP sécurisé  
- IMAP/POP sécurisé  
- VPN TLS  
Assure : chiffrement, intégrité, authentification.

---

# 10.2.2 — VPN
Un **VPN** crée un tunnel sécurisé entre deux points.

Fonctions :
- Chiffrement du trafic  
- Isolation du trafic  
- Accès distant sécurisé  

Technos :
- IPsec  
- OpenVPN  
- WireGuard  
- L2TP  

---

# 10.3 — Protection de l'infrastructure

## 10.3.1 — Pare-feu (Firewall)
Filtre le trafic selon :
- adresses IP,
- ports,
- protocoles,
- états de connexion (stateful).

Types de règles :
- autoriser  
- bloquer  
- journaliser

Pare-feu matériels ou logiciels (pf, iptables, UFW…).

---

# 10.3.2 — IDS / IPS
### IDS — Intrusion Detection System
Détecte les comportements suspects, génère des alertes.

### IPS — Intrusion Prevention System
Bloque automatiquement les attaques.  
Ex : Snort, Suricata.

---

# 10.3.3 — Segmentation réseau
Séparer le réseau en zones :

- VLAN utilisateurs  
- VLAN serveurs  
- VLAN VoIP  
- DMZ pour services publics  
- réseau admin séparé  

Objectifs :
- réduire la propagation d’attaques,
- limiter la visibilité,
- isoler les services critiques.

---

# 10.3.4 — Proxy
Intermédiaire entre l’utilisateur et Internet.

Rôles :
- filtrage des sites  
- cache (accélération)  
- anonymisation  
- contrôle du trafic sortant

---

# 10.4 — Sécurité des protocoles

## DNSSEC
Ajoute une signature cryptographique aux réponses DNS pour garantir leur authenticité.

## HTTPS
Remplace HTTP, protège contre :
- interception,
- modification,
- usurpation.

## SSH
Accès distant sécurisé via clés.  
Protège contre interception/MITM en clair (contrairement à Telnet).

---

# 10.5 — Bonnes pratiques réseau

- Mettre à jour les équipements  
- Désactiver les services inutiles  
- Utiliser des mots de passe forts / MFA  
- Filtrer les ports au strict minimum  
- Activer TLS partout où c’est possible  
- Séparer les réseaux sensibles  
- Surveiller les logs régulièrement  
- Sauvegarder la configuration des routeurs/switchs  
- Utiliser des outils de monitoring (Nagios, Zabbix…)  

---

# 10.6 — Outils de sécurité

- **Wireshark** : analyse du trafic  
- **Nmap** : scan de réseau  
- **Fail2Ban** : protection brute force  
- **OpenVAS** : scan de vulnérabilités  
- **Metasploit** : tests d’intrusion  
- **Tcpdump** : capture réseau en CLI  

---

# Synthèse

La sécurité réseau repose sur :
- la protection des communications (TLS, VPN),
- la segmentation (VLAN, DMZ),
- les contrôles (pare-feu, IDS/IPS),
- l’analyse régulière (logs, monitoring),
- la réduction de surface d’attaque (ports/services),
- la mise à jour systématique des équipements.

Elle vise à garantir **confidentialité**, **intégrité**, **disponibilité**, **authentification** et **traçabilité**.  
C’est une discipline essentielle pour maintenir un réseau fiable et sécurisé.

---

# Backlinks
[[09_Protocoles_reseau]] ← → [[11_Wireshark]]
