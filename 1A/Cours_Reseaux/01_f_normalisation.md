# 01F — Normalisation des Réseaux

## Introduction
La **normalisation** joue un rôle central dans l’évolution des réseaux informatiques et télécoms. Sans normes, il serait impossible d’assurer :
- la **compatibilité** entre équipements de fournisseurs différents,
- l’**interopérabilité** à l’échelle mondiale,
- la **pérennité** des technologies,
- l’**uniformisation** des protocoles et méthodes de communication.

Dans ce sous-chapitre, nous explorons l’histoire, les enjeux et les acteurs majeurs de la normalisation.

---

# 1. Pourquoi normaliser ?
La normalisation répond à plusieurs besoins fondamentaux :

### 1.1 Compatibilité des équipements
Un routeur Cisco doit pouvoir communiquer avec un switch Juniper ou Huawei. Les normes garantissent un langage commun.

### 1.2 Interopérabilité mondiale
Les réseaux modernes sont globaux : les équipements doivent pouvoir fonctionner partout.

### 1.3 Harmonisation des technologies
Avant les années 1980, chaque opérateur national développait ses propres standards. Résultat : fragmentation et incompatibilités.

La normalisation a permis de :
- réduire les coûts,
- favoriser l’innovation,
- permettre l’arrivée d’Internet telle que nous la connaissons.

### 1.4 Dynamique et complexité du milieu
Les réseaux évoluent très vite : haute disponibilité, sécurité, débits, mobilité. Il faut des règles précises et partagées.

---

# 2. Historique rapide de la normalisation
- **1947** : création de l’ISO (International Standardization Organization)
- **Années 70–80** : multiplication des réseaux nationaux incompatibles
- **Dès les années 90** : mondialisation et harmonisation

L’avènement de l’Internet a renforcé le besoin de normes internationales solides.

---

# 3. Les grands organismes de normalisation
Les réseaux impliquent de nombreux acteurs, chacun spécialisé dans un domaine.

## 3.1 ISO — International Organization for Standardization
Responsable de :
- standards génériques,
- modèle **OSI**, fondement théorique de l’architecture réseau.

## 3.2 UIT-T — Union Internationale des Télécommunications (Télécom)
Définit les normes mondiales pour :
- la téléphonie,
- les réseaux fixes et mobiles,
- la signalisation,
- les débits, interfaces, codecs.

Sous-division :
- **UIT-R** : radiocommunications.

## 3.3 ETSI — Institut Européen des Standards Télécom
Rôle :
- normalisation européenne,
- intervient notamment dans les réseaux mobiles (GSM, TETRA).

## 3.4 IEEE — Institute of Electrical and Electronics Engineers
Organisation majeure dans les réseaux locaux.

Standards importants :
- **IEEE 802.3** : Ethernet
- **IEEE 802.11** : Wi-Fi
- **IEEE 802.15** : Bluetooth, ZigBee
- **IEEE 802.1X** : sécurité réseau

## 3.5 IETF — Internet Engineering Task Force
Organisation responsable de la normalisation d’Internet.

Les normes publiées sont les **RFC** (Request For Comments).

Protocoles standardisés par l’IETF :
- **IP** (IPv4, IPv6)
- **TCP**, **UDP**
- **BGP**, **OSPF**
- **DNS**, **DHCP**

## 3.6 3GPP — Third Generation Partnership Project
Organisation qui définit :
- **3G**, **4G/LTE**, **5G**
- architecture des réseaux mobiles

## 3.7 DVB — Digital Video Broadcasting
Organisme européen pour la normalisation de la télévision numérique :
- DVB-T (TNT), DVB-S (satellite), DVB-C (câble).

---

# 4. Processus de normalisation

### 4.1 Création d’une norme
1. Proposition par un groupe d’experts
2. Étude en comité technique
3. Versions successives et expérimentation
4. Vote et adoption internationale

### 4.2 Types de normes
- **Recommandations** (UIT, IETF)
- **Standards** (ISO, IEEE)
- **Spécifications techniques** (3GPP)

### 4.3 Importance stratégique
Les normes conditionnent :
- la compétitivité d’un marché,
- les choix technologiques des États,
- l'innovation industrielle.

Exemple : la réussite mondiale du GSM (ETSI) face au CDMA américain.

---

# 5. Exemples d’impacts de la normalisation

## 5.1 Ethernet (IEEE 802.3)
Standard dominant des réseaux locaux.
- Débits de 10 Mb/s à plus de 400 Gb/s
- Fiabilité et compatibilité totale

## 5.2 Wi-Fi (IEEE 802.11)
Un standard mondial de communication sans fil.
- Coordination indispensable entre bandes de fréquences, sécurité, modulation.

## 5.3 Internet (IETF)
L’une des plus grandes réussites de normalisation.
- Les RFC définissent tout : IP, TCP, DNS, HTTP.
- Interopérabilité mondiale.

## 5.4 Télévision numérique (DVB)
Permet la diffusion harmonisée dans plusieurs pays.

## 5.5 Réseaux mobiles (3GPP)
Les normes 3G/4G/5G ont permis :
- l’itinérance internationale,
- l’explosion de l’Internet mobile.

---

# 6. Pourquoi la normalisation est essentielle aujourd’hui
- Explosion des objets connectés (IoT)
- Réseaux 5G et futurs 6G
- Cybersécurité
- Intelligence artificielle dans les réseaux
- Cloud computing et virtualisation

Sans normes communes, l’interopérabilité serait impossible.

---

# Synthèse
Ce sous-chapitre montre que la normalisation :
- est indispensable au fonctionnement des réseaux modernes,
- garantit l’interopérabilité, la sécurité et la pérennité,
- est gérée par de nombreux organismes internationaux,
- influence les technologies utilisées au quotidien (Ethernet, Wi-Fi, 5G, Internet).

Le prochain sous-chapitre porte sur la **couche physique**, un domaine essentiel pour comprendre comment les bits transitent réellement sur un support.

---

## Navigation
- ⬅️ Sous-chapitre précédent : [[01E_Architecture_Reseaux]]
- ➡️ Sous-chapitre suivant : [[01G_Couche_Physique]]
- 🏠 Sommaire du chapitre : [[01_Sommaire_Concepts_Generaux]]
- 📘 Sommaire général du cours : [[00_Sommaire]]