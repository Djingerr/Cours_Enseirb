# Chapitre 6 — Codage source : notions fondamentales

## Introduction

Les chapitres précédents ont montré que l’**entropie** fixe une limite
fondamentale à la compression de l’information.

Ce chapitre introduit les **outils concrets de codage source**, c’est-à-dire
les méthodes permettant de **représenter une source d’information par des mots
binaires** de manière efficace, tout en garantissant une **reconstruction sans perte**.

---

## 6.1 Source d’information

### Définition

On appelle **source discrète** une variable aléatoire $X$ prenant ses valeurs
dans un ensemble fini $\mathcal{X}$, telle que :

$$
\mathbb{P}(X=x) > 0
\quad \text{pour tout } x \in \mathcal{X}
$$

---

### Objectif du codage source

Trouver une nouvelle représentation des symboles de la source telle que :
- les messages soient **les plus courts possibles en moyenne**,
- le décodage soit **sans ambiguïté**,
- l’information initiale puisse être **retrouvée exactement**.

➡️ Principe fondamental :  
**associer les mots les plus courts aux symboles les plus probables**.

---

## 6.2 Mots et alphabets de codage

### Alphabet du code

Soit $\mathcal{A}$ un ensemble fini appelé **alphabet du code**
(exemple : $\mathcal{A} = \{0,1\}$).

---

### Mots

Un **mot** sur l’alphabet $\mathcal{A}$ est un vecteur fini de symboles de
$\mathcal{A}$.

L’ensemble de tous les mots est noté :

$$
\mathcal{A}^*
=
\bigcup_{n \ge 1} \mathcal{A}^n
$$

---

### Longueur d’un mot

Pour un mot $c \in \mathcal{A}^*$, on note :

$$
\ell(c)
$$

le **nombre de symboles** qui le composent.

---

## 6.3 Codes source

### Définition

Un **code source** est une application :

$$
\varphi : \mathcal{X} \longrightarrow \mathcal{A}^*
$$

Les éléments de $\varphi(\mathcal{X})$ sont appelés **mots de code**.

---

### Longueur moyenne d’un code

La **longueur moyenne** du code $\varphi$ est définie par :

$$
L(\varphi)
=
\sum_{x \in \mathcal{X}}
\ell\big(\varphi(x)\big)\,
p_X(x)
$$

➡️ Le problème central du codage source est :

> **Minimiser $L(\varphi)$ parmi tous les codes décodables.**

---

## 6.4 Exemple illustratif

Soit une source $\mathcal{X} = \{x_1,x_2,x_3,x_4\}$ avec :

$$
p_X(x_1)=\frac{1}{2},
\quad
p_X(x_2)=\frac{1}{4},
\quad
p_X(x_3)=p_X(x_4)=\frac{1}{8}
$$

Considérons trois codes binaires :

| Symbole | $\varphi_1(x)$ | $\varphi_2(x)$ | $\varphi_3(x)$ |
|-------|---------------|---------------|---------------|
| $x_1$ | 1 | 0 | 0 |
| $x_2$ | 0 | 1 | 10 |
| $x_3$ | 0 | 10 | 110 |
| $x_4$ | 1 | 01 | 111 |

Les longueurs moyennes associées sont :

$$
L(\varphi_1)=1,
\quad
L(\varphi_2)=1.5,
\quad
L(\varphi_3)\approx1.75
$$

➡️ Tous les codes ne sont **pas également efficaces**.

---

## 6.5 Extension d’un code

### Définition

L’**extension** d’un code $\varphi$ est l’application :

$$
\varphi^* : \mathcal{X}^* \longrightarrow \mathcal{A}^*
$$

définie par concaténation :

$$
\varphi^*(x_1,\dots,x_n)
=
\big(
\varphi(x_1),
\dots,
\varphi(x_n)
\big)
$$

---

### Remarque pratique

En pratique :
- les mots de code sont **concaténés sans séparateur**,
- le décodage doit être possible **sans ambiguïté**.

---

## 6.6 Décodabilité

### Définition

Un code $\varphi$ est dit **déchiffrable**
(sans ambiguïté) si son extension $\varphi^*$ est **injective**.

➡️ Une même séquence binaire ne doit jamais correspondre à deux messages différents.

---

### Limitation

Un code déchiffrable **n’est pas nécessairement facile à décoder** :
- il peut nécessiter la lecture complète du message,
- le décodage peut être coûteux.

---

## 6.7 Codes préfixes (ou instantanés)

### Définition

Un code $\varphi$ est dit **préfixe** si aucun mot de code n’est le début d’un autre :

$$
\forall x \neq y,
\quad
\varphi(x) \nprec \varphi(y)
$$

---

### Exemple

- $\{0,10,110,111\}$ : code préfixe  
- $\{0,1,10,11\}$ : **non** préfixe

---

### Propriété fondamentale

Tout **code préfixe** est **déchiffrable**.

➡️ Avantage majeur : le décodage peut être effectué **symboles par symboles**.

---

## 6.8 Représentation par arbre

Un code préfixe peut être représenté par un **arbre** :
- chaque branche correspond à un symbole de l’alphabet,
- chaque feuille correspond à un mot de code.

➡️ Cette représentation permet un **décodage immédiat**.

---

## 6.9 Théorème de Kraft

### Énoncé

Soit $\mathcal{A}$ un alphabet de taille $d$, et $(\ell_x)_{x\in\mathcal{X}}$
une famille d’entiers positifs.

Il existe un **code préfixe** tel que :

$$
\ell(\varphi(x)) = \ell_x
$$

si et seulement si :

$$
\sum_{x \in \mathcal{X}} d^{-\ell_x} \le 1
$$

---

### Importance

Le théorème de Kraft :
- caractérise les **longueurs admissibles**,
- garantit l’existence d’un code préfixe,
- est fondamental pour la preuve du théorème de Shannon.

---

## Synthèse du chapitre

- Un code associe des mots binaires aux symboles d’une source
- L’objectif est de minimiser la longueur moyenne
- La décodabilité est une contrainte essentielle
- Les codes préfixes permettent un décodage efficace
- Le théorème de Kraft donne une condition d’existence clé

---

## Liens
- ⏮️ Chapitre précédent : [[05_Extension_cas_continu]]
- ⏭️ Chapitre suivant : [[07_Theoreme_codage_source]]
