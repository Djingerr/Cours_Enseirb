# 01B — Nature de l’Information & Numérisation

## Introduction
La transmission de données est au cœur du fonctionnement des réseaux. Avant de pouvoir être transportée, l’information doit être **représentée**, **codée**, puis **numérisée**. Cette section explique la nature des données, la transition entre analogique et numérique, et les principes fondamentaux qui rendent possible le transport d’information dans un réseau.

Ce chapitre est essentiel pour comprendre la couche physique et les couches supérieures.

---

## 1. Nature de l’information
L’information peut être représentée sous deux grandes formes :

### 1.1 Données discrètes
Ce sont des données qui prennent leurs valeurs dans un ensemble **dénombrable**.
- Exemple : texte → lettres → bits
- Autres exemples : chiffres, codes, symboles

Les données discrètes sont naturellement adaptées aux systèmes numériques.

### 1.2 Données continues
Elles proviennent d’un phénomène **physique à variation continue** :
- Voix humaine
- Musique
- Images analogiques
- Vidéo

Leur représentation est une **courbe lisse** dépendante du temps.

### 1.3 Objectif de la numérisation
Pour être traitée par un ordinateur ou transmise dans un réseau :
> Toute information doit être représentée sous la forme d’une suite de bits {0,1}.

Cela nécessite plusieurs étapes :
1. Échantillonnage
2. Quantification
3. Codage

---

## 2. Représentation binaire
### 2.1 Bit et byte
- **Bit** : unité d’information binaire (0 ou 1)
- **Octet (Byte)** : 8 bits

### 2.2 Préfixes
| Unité | Valeur |
|-------|--------|
| 1 Kbit | 10³ bits |
| 1 Mbit | 10⁶ bits |
| 1 Gbit | 10⁹ bits |
| 1 Tbit | 10¹² bits |

Les capacités des supports et les débits se mesurent en bits par seconde (bit/s).

---

## 3. Numérisation : analogique → numérique

### 3.1 Principe général
Pour convertir un signal analogique (continu) en représentation numérique (discrète) :
- on **échantillonne** le signal,
- on **quantifie** les valeurs obtenues,
- on encode chaque valeur sur un nombre fini de bits.

### 3.2 Échantillonnage
L’échantillonnage consiste à mesurer le signal analogique à intervalles **réguliers**.

Le paramètre crucial est la **fréquence d’échantillonnage fe**.

Selon le **théorème de Shannon-Nyquist** :
> Pour reconstruire un signal sans perte, il faut échantillonner à une fréquence au moins **deux fois supérieure** à sa fréquence maximale.

Exemples :
- Téléphonie : signal vocal ≈ 4 kHz → fe = 8 kHz
- Audio CD : bande ≈ 20 kHz → fe = 44,1 kHz

### 3.3 Quantification
Chaque échantillon est arrondi à la valeur la plus proche dans un ensemble **fini** de valeurs.

La finesse de la quantification dépend du **nombre de bits** par échantillon.
- 8 bits → 256 niveaux
- 16 bits → 65 536 niveaux

Plus on utilise de bits, plus la représentation est précise.

### 3.4 Codage
La valeur quantifiée est transformée en un mot binaire :
> plus le nombre de bits est élevé, meilleure est la qualité.

---

## 4. Convertisseurs (CAN et CNA)
La numérisation et la dénumérisation nécessitent des composants matériels spécialisés.

### 4.1 CAN — Convertisseur Analogique → Numérique
Il réalise :
- Échantillonnage
- Quantification
- Conversion binaire

Exemples d’équipements contenant un CAN :
- Microphones / cartes son
- Webcams / caméras
- Scanners
- Modems (réception)

### 4.2 CNA — Convertisseur Numérique → Analogique
Il reconstruit un signal analogique à partir de données binaires.

On le retrouve dans :
- Cartes son (sortie audio)
- Convertisseurs vidéo
- Imprimantes
- Modems (émission)

---

## 5. Représentation des supports physiques
### 5.1 Signaux utilisés
Un réseau transporte des signaux :
- **électriques** (cuivre),
- **lumineux** (fibre optique),
- **électromagnétiques** (ondes radio).

Ces signaux transportent les bits encodés selon :
- une technique de **codage** en bande de base,
- ou une **modulation** sur porteuse.

Le détail de ces techniques sera vu dans le sous-chapitre 01G.

---

## 6. Travail de l’ingénieur réseau
Comprendre la nature de l’information permet :
- de choisir des formats de données adaptés,
- d’évaluer les besoins en bande passante,
- d’analyser la qualité du signal,
- de détecter les sources d’erreurs,
- d’optimiser les transmissions.

C’est une compétence fondamentale pour toutes les couches du modèle OSI.

---

## Synthèse
Ce sous-chapitre a introduit les notions essentielles autour de la nature de l’information :
- données discrètes / continues,
- représentation binaire,
- numérisation via échantillonnage, quantification et codage,
- rôle des convertisseurs,
- importance de ces opérations pour la transmission.

Ces bases serviront à aborder :
- l’historique des réseaux,
- les types de réseaux,
- la couche physique.

---
## Navigation
- ⬅️ Sous-chapitre précédent : [[01A_Introduction_Reseaux]]
- ➡️ Sous-chapitre suivant : [[01C_Historique_Reseaux]]
- 🏠 Sommaire du chapitre : [[01_Sommaire_Concepts_Generaux]]
- 📘 Sommaire général : [[00_Sommaire]]