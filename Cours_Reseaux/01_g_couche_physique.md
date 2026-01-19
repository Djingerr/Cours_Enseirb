# 01G — La Couche Physique

## Introduction
La **couche physique** constitue la base de toute communication réseau. Elle assure la **transmission des bits** sur un support matériel, sans se préoccuper de leur signification. C’est la couche la plus proche du matériel : elle définit le signal, les supports, les connecteurs, la synchronisation et les contraintes physiques.

Dans ce sous-chapitre, nous explorons :
- les modes de transmission,
- la nature des signaux,
- les techniques de codage et de modulation,
- les méthodes de multiplexage,
- les différents supports (cuivre, fibre, radio),
- les phénomènes physiques influençant la transmission.

---
# 1. Définition et rôle de la couche physique
La couche physique fournit les moyens **mécaniques, électriques, optiques et fonctionnels** permettant de transmettre un flot de bits d’une machine à une autre.

Elle spécifie :
- les types de signaux (électriques, lumineux, radio),
- les caractéristiques des supports (câble, fibre…),
- les connecteurs,
- les procédés de synchronisation,
- les procédures d’activation/désactivation de la liaison,
- les modes de transmission (simplex, duplex),
- les techniques de codage/modulation.

---
# 2. Modes de transmission

## 2.1 Simplex
Transmission **unidirectionnelle**.
- Exemple : télévision classique.

## 2.2 Half-duplex (semi-duplex)
Transmission **bidirectionnelle**, mais **pas simultanée**.
- Exemple : talkie-walkie.

## 2.3 Full-duplex
Transmission bidirectionnelle **simultanée**.
- Exemple : Ethernet moderne, téléphonie.

Le mode utilisé dépend du support et du matériel.

---
# 3. Transmission du signal
Les données numériques doivent être converties en signaux physiques pour être transmises.

Types d’ondes utilisées :
- **ondes électriques** (cuivre),
- **ondes lumineuses** (fibre optique),
- **ondes radio** (Wi-Fi, 4G),
- **ondes acoustiques** (systèmes sous-marins).

### Contraintes physiques :
- atténuation,
- bruit,
- interférences,
- dispersion,
- réflexions,
- capacité du canal.

Ces phénomènes influencent fortement les débits possibles.

---
# 4. Codage en bande de base
Le codage convertit les bits en signaux avant transmission.

## 4.1 NRZ (Non Return to Zero)
- Bit 1 = niveau haut
- Bit 0 = niveau bas
- Simple mais sensible à la perte de synchronisation.

## 4.2 Manchester
Chaque bit comporte une **transition au milieu** :
- 0 = transition haute → basse
- 1 = transition basse → haute

Avantages : synchronisation intégrée.
Usage : **Ethernet 10 Mb/s**.

## 4.3 Manchester différentiel
La transition dépend du bit précédent : plus robuste au bruit.

## 4.4 Codage Miller
- Transition à mi-période pour transmettre un 1
- Transition en fin de période pour deux 0 consécutifs
Utilisé dans les cartes magnétiques.

### Pourquoi coder ?
- synchronisation émetteur/récepteur,
- représentation physique adaptée au support,
- réduction des erreurs.

---
# 5. Modulation (bande large)
Lorsque le support n’accepte pas la bande de base (ex : radio, téléphonie), il faut **moduler** un signal porteur.

## 5.1 Modulation d’amplitude — ASK
Amplitude faible = 0  
Amplitude forte = 1

Usage : technologies simples, rarement seules.

## 5.2 Modulation de fréquence — FSK
Fréquence f1 = 0  
Fréquence f2 = 1

Usage : radio FM, modems anciens.

## 5.3 Modulation de phase — PSK
La phase du signal change pour coder les bits.

Exemple :
- 0 = phase 0°
- 1 = phase 180°

### 5.4 Modulations avancées
- QPSK (2 bits par symbole)
- QAM (combinaison amplitude + phase)

Utilisées dans :  
- Wi-Fi,  
- 4G/5G,  
- CPL.

---
# 6. Multiplexage
Pour faire partager un même canal à plusieurs utilisateurs.

## 6.1 Multiplexage en fréquence — FDM / FDMA
- La bande passante est **découpée en sous-bandes**.
- Chaque canal a une fréquence dédiée.

Usage :
- Radio, TV,
- Systèmes analogiques,
- GSM 2G (bandes de 200 kHz).

## 6.2 Multiplexage temporel — TDM / TDMA
- Le temps est divisé en **tranches fixes (IT)**.
- Chaque utilisateur obtient une tranche à intervalle régulier.

Usage :
- Téléphonie numérique,
- GSM.

## 6.3 Signalisation
- In-band : information dans les IT,
- Out-of-band : IT dédiées à la signalisation.

---
# 7. Supports de transmission

## 7.1 Paires torsadées
- UTP (non blindées)
- STP (blindées)
Débits : jusqu’à 10 Gb/s (Cat 6/7).
Portée : ~100 m.

## 7.2 Câble coaxial
- Très résistant aux interférences
- Utilisé historiquement en Ethernet et télévision câble.

## 7.3 Fibre optique
Deux types :
- **Monomode** (longue distance, très haut débit)
- **Multimode** (réseaux locaux)

Avantages :
- débit énorme,
- faible atténuation,
- insensibilité aux EMI.

## 7.4 Supports sans fil
- Wi-Fi (2,4 / 5 / 6 GHz)
- GSM/UMTS/LTE/5G
- Bluetooth
- Infrarouge

Avantages : mobilité, flexibilité.  
Limites : interférences, sécurité.

---
# 8. Équipements liés à la couche physique

## 8.1 ETTD — Équipement Terminal de Transmission de Données
Exemples : ordinateur, carte réseau.

Fonctions :
- sérialisation,
- détection d’erreurs,
- gestion du lien physique.

## 8.2 ETCD — Équipement Terminal de Circuit de Données
Exemples : modem ADSL, modem câble.

Fonctions :
- modulation / démodulation,
- codage,
- synchronisation,
- gestion duplex.

---
# 9. Contraintes physiques & capacité du canal

## 9.1 Atténuation
Perte de puissance du signal avec la distance.

## 9.2 Bruit
Interférences dues au support ou à l’environnement.

## 9.3 Diaphonie
Couplage entre deux câbles proches.

## 9.4 Capacité de Shannon
Débit maximal théorique d’un canal :
```
C = B log2(1 + S/N)
```
Où :
- **C** = capacité (bits/s),
- **B** = largeur de bande (Hz),
- **S/N** = rapport signal/bruit.

Ce théorème fixe les limites ultimes du débit.

---
# Synthèse
Dans ce sous-chapitre, nous avons étudié :
- le rôle fondamental de la couche physique,
- les supports et modes de transmission,
- les signaux et techniques de codage/modulation,
- le multiplexage,
- les équipements associés,
- les phénomènes physiques influençant la transmission.

La couche physique constitue la base indispensable pour comprendre les couches supérieures et les technologies comme Ethernet ou Wi-Fi.

---
## Navigation
- ⬅️ Sous-chapitre précédent : [[01F_Normalisation]]
- 🏁 Fin du Chapitre 1 — revenir au sommaire : [[01_Sommaire_Concepts_Generaux]]
- 📘 Sommaire général : [[00_Sommaire]]

