# Chapitre 9a — Codage canal : modélisation et notions fondamentales

## Introduction

Contrairement au codage source, qui vise à **réduire la redondance**,
le **codage canal** a pour objectif inverse :

> **Ajouter de la redondance afin de lutter contre le bruit du canal.**

Ce chapitre introduit les concepts fondamentaux nécessaires à la
compréhension de la transmission fiable de l’information.

---

## 9.1 Modèle général d’un canal de communication

### Chaîne de transmission


- $X$ : symbole transmis
- $Y$ : symbole reçu
- Le canal introduit des erreurs aléatoires

---

### Canal discret sans mémoire

Un **canal discret sans mémoire** est entièrement caractérisé par les
probabilités conditionnelles :

$$
\mathbb{P}(Y=y \mid X=x)
$$

➡️ « Sans mémoire » signifie que chaque utilisation du canal est
indépendante des précédentes.

---

## 9.2 Code canal

### Définition

Un **code canal binaire** est une application :

$$
\varphi : \{0,1\}^k \longrightarrow \{0,1\}^n
$$

avec :

$$
n \ge k
$$

- $k$ : nombre de bits d’information
- $n$ : nombre de bits transmis

---

### Rendement (ou taux)

Le **rendement** du code est défini par :

$$
R = \frac{k}{n}
$$

➡️ Plus $R$ est grand, plus la transmission est efficace,
mais moins elle est robuste face au bruit.

---

## 9.3 Décodage et probabilité d’erreur

Le décodeur produit une estimation $\hat{M}$ du message $M$.

La **probabilité d’erreur** est définie par :

$$
P_e = \mathbb{P}(\hat{M} \neq M)
$$

➡️ L’objectif du codage canal est de rendre $P_e$ aussi petit que possible.

---

## 9.4 Exemple : canal binaire symétrique

### Modèle

Le **canal binaire symétrique (CBS)** est caractérisé par une probabilité $p$ :

- $0 \to 1$ avec probabilité $p$
- $1 \to 0$ avec probabilité $p$

---

### Transmission sans codage

Si l’on transmet directement :

$$
\varphi = \mathrm{Id}
$$

alors :

- rendement :

$$
R = 1
$$

- probabilité d’erreur :

$$
P_e = p
$$

---

### Codage par répétition

On code chaque bit $x$ par :

$$
\varphi(x) = (x,x,\dots,x)
$$

sur $n$ bits.

- rendement :

$$
R = \frac{1}{n}
$$

- la probabilité d’erreur décroît exponentiellement :

$$
P_e = \mathcal{O}\big(e^{-c n}\big),
\quad c>0
$$

➡️ On observe un **compromis fondamental** entre
rendement et fiabilité.

---

## Synthèse de la partie 1

- Le canal est modélisé probabilistiquement
- Le codage canal ajoute de la redondance
- Le rendement mesure l’efficacité
- La fiabilité se mesure par $P_e$
- Il existe un compromis rendement / robustesse

---

## Liens
- ⏮️ Partie précédente : [[08_Code_de_Huffman]]
- ⏭️ Partie suivante : [[09b_Codage_canal_Capacite_Shanon]]
