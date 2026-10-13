# 01D — Types de Réseaux & Topologies

## Introduction
Les réseaux peuvent être classés selon plusieurs critères : leur mode de transmission, leur taille, leur support physique ou encore leur organisation interne (topologie). Ces classifications permettent de comprendre les architectures réseau existantes et leurs usages. Ce sous-chapitre présente en détail les différents types de réseaux ainsi que les topologies courantes.

---

# 1. Classification des réseaux
Un réseau peut être décrit selon plusieurs axes :

- **Mode de transmission**
- **Taille ou étendue géographique**
- **Type de support de transmission**
- **Organisation structurelle (topologie)**

Nous étudierons chaque critère en profondeur.

---

# 2. Modes de transmission
Les réseaux transmettent l’information selon deux modes principaux.

## 2.1 Mode point-à-point
Deux nœuds communiquent directement via un lien dédié.

**Caractéristiques :**
- Très simple à gérer
- Pas de risque de collision
- Débit dédié

**Limites :**
- Nécessite un lien par paire d’équipements
- Peu adapté aux grands réseaux

## 2.2 Mode multipoint (ou mode diffusion)
Plusieurs nœuds partagent un même support de transmission.

**Caractéristiques :**
- Communication de type broadcasting
- Risque de collisions (nécessite des méthodes d’accès : CSMA, etc.)
- Moins coûteux car un seul support

Exemples : Ethernet coaxial, Wi-Fi, réseaux radio.

---

# 3. Classification par taille

## 3.1 PAN (Personal Area Network)
Réseau de très courte portée autour d’un individu.
- Bluetooth
- ZigBee
- USB sans fil

## 3.2 LAN (Local Area Network)
Réseau local couvrant un bâtiment ou un campus.
- Très haut débit
- Faible latence
- Contrôle propriétaire
- Exemple : réseau Ethernet d'entreprise

## 3.3 MAN (Metropolitan Area Network)
Couvre une ville ou une zone métropolitaine.
- Technologies : WiMAX, fibres métropolitaines
- Très utilisé par les opérateurs

## 3.4 WAN (Wide Area Network)
Réseau étendu à l’échelle régionale, nationale ou mondiale.
- Débits variables
- Routage complexe
- Exemple : Internet

## 3.5 WLAN, WMAN, WWAN
### Réseaux sans fil classés par portée :
- **WLAN** : Wi-Fi (portée locale)
- **WMAN** : WiMAX (portée métropolitaine)
- **WWAN** : Réseaux mobiles (GSM, 3G, 4G, 5G)

---

# 4. Classification par type de support
Les réseaux peuvent être :

## 4.1 Filaire
- Paires torsadées
- Câble coaxial
- Fibre optique

## 4.2 Sans fil
- Ondes radio (Wi-Fi, GSM)
- Micro-ondes
- Infrarouge

Chaque support a des caractéristiques propres (débit, portée, sensibilité aux perturbations).

---

# 5. Topologies de réseau
La topologie décrit la manière dont les nœuds sont organisés sur le support.
On distingue **topologie physique** et **topologie logique**.

- **Topologie physique** : disposition réelle des câbles
- **Topologie logique** : circulation de l’information

Nous étudions ici les principales topologies.

---

# 5.1 Topologie en bus
Toutes les stations sont connectées sur un même câble linéaire.

### Avantages :
- Simplicité d’installation
- Faible coût

### Inconvénients :
- Une rupture du câble = panne du réseau
- Collisions fréquentes
- Peu évolutif

Usage : Ethernet coaxial historique.

---

# 5.2 Topologie en étoile
Toutes les stations sont reliées à un nœud central (hub ou switch).

### Avantages :
- Une panne d’une station n’affecte pas le réseau
- Facile à diagnostiquer
- Très évolutif

### Inconvénients :
- Le nœud central est un point de défaillance

Usage : Ethernet moderne (switch central).

---

# 5.3 Topologie en arbre
Des étoiles interconnectées forment une hiérarchie.

### Avantages :
- Structure claire
- Pas de boucles

### Inconvénients :
- Si un nœud parent tombe, une partie du réseau est coupée

Usage : réseaux d’entreprise organisés par étages.

---

# 5.4 Topologie en anneau
Chaque station est connectée à deux voisines, formant un cercle.

### Avantages :
- Débit stable
- Absence de collisions lorsqu'un jeton (token) régule la transmission

### Inconvénients :
- Panne d’une station = panne totale (sauf mécanismes de contournement)

Usage : anciennes technologies Token Ring.

---

# 5.5 Topologie maillée (mesh)
Chaque nœud est relié à plusieurs autres.

### Avantages :
- Très grande robustesse
- Plusieurs chemins possibles

### Inconvénients :
- Coût élevé
- Complexité de gestion

Usage : backbone Internet, réseaux de capteurs.

---

# 5.6 Topologies hybrides
La plupart des réseaux modernes combinent plusieurs topologies.
Exemple :
- backbone maillé
- structures locales en étoile

---

# 6. Choix d’une topologie : critères
- **Coût**
- **Évolutivité**
- **Robustesse**
- **Performance**
- **Maintenance**
- **Usage prévu (LAN, WAN, sans-fil, etc.)**

Chaque topologie répond à des besoins différents.

---

# Synthèse
Dans ce sous-chapitre, nous avons :
- classé les réseaux selon plusieurs critères (taille, transmission, support),
- étudié en détail les topologies (bus, étoile, anneau, arbre, maillée),
- identifié leurs avantages, inconvénients et usages.

Ces notions sont essentielles pour comprendre l’architecture des réseaux, abordée dans le sous-chapitre 01E.

---

## Navigation
- ⬅️ Sous-chapitre précédent : [[01C_Historique_Reseaux]]
- ➡️ Sous-chapitre suivant : [[01E_Architecture_Reseaux]]
- 🏠 Sommaire du chapitre : [[01_Sommaire_Concepts_Generaux]]
- 📘 Sommaire général : [[00_Sommaire]]

