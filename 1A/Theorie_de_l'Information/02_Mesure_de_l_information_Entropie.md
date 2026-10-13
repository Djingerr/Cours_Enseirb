# Chapitre 2 — Mesure de l’information : l’entropie

## Introduction

Dans le chapitre précédent, nous avons posé le principe fondamental suivant :

> **L’information est liée à l’incertitude.**

Ce chapitre introduit la mesure mathématique de cette incertitude à travers la notion
d’**entropie**, qui jouera un rôle central dans tout le reste du cours
(compression, codage, transmission).

Objectifs :
- définir rigoureusement la **quantité d’information**,
- introduire l’**entropie d’une source discrète**,
- comprendre ses **propriétés fondamentales** et son **interprétation**.

---

## 2.1 Quantité d’information d’un événement

### Intuition

Un événement est d’autant plus **informatif** qu’il est **improbable**.

Exemples :
- « Le soleil se lève » → information faible
- « Une panne totale en vol » → information élevée

---

### Axiomatisation

On cherche une fonction

$$
h : (0,1] \longrightarrow \mathbb{R}^+
$$

qui associe à une probabilité $p$ une quantité d’information, et qui vérifie :

1. **Décroissance** :  
   si $p_1 < p_2$, alors $h(p_1) > h(p_2)$
2. **Continuité**
3. **Additivité** (événements indépendants) :

$$
h(pq) = h(p) + h(q)
$$

---

### Théorème (forme de la fonction d’information)

Toute fonction $h$ satisfaisant ces axiomes est de la forme :

$$
h(p) = -C \log(p),
\qquad C > 0
$$

Par convention, on prend $C = 1$.

---

### Définition (quantité d’information)

La **quantité d’information** associée à un événement $A$ est :

$$
h\big(\mathbb{P}(A)\big)
=
-\log\big(\mathbb{P}(A)\big)
$$

#### Unités
- $\log_2$ : **bit**
- $\log_{10}$ : **decit**
- $\ln$ : **nat**

---

## 2.2 Entropie d’une variable aléatoire discrète

### Définition

Soit $X$ une variable aléatoire discrète à valeurs dans un ensemble fini $\mathcal{X}$,
de fonction de masse $p_X(x) = \mathbb{P}(X=x)$.

L’**entropie** de $X$ est définie par :

$$
H(X)
=
-\sum_{x \in \mathcal{X}}
p_X(x)\,\log\big(p_X(x)\big)
$$

---

### Interprétation

L’entropie peut s’écrire comme une espérance :

$$
H(X) = \mathbb{E}\big[-\log p_X(X)\big]
$$

➡️ Elle représente la **quantité moyenne d’information** produite par la source.

---

### Remarques

- Par convention :

$$
0 \log 0 = 0
$$

- L’entropie dépend **uniquement** de la loi de $X$
- Elle est exprimée dans l’unité du logarithme choisi

---

## 2.3 Exemple fondamental : loi de Bernoulli

Soit :

$$
X \sim \mathcal{B}(p)
$$

Alors :

$$
H(X)
=
-(1-p)\log(1-p) - p\log(p)
$$

Cette fonction est appelée **entropie binaire**, notée :

$$
H_2(p)
$$

---

### Propriétés de l’entropie binaire

- $H_2(p)$ est **concave**
- Elle est **maximale** pour :

$$
p = \frac{1}{2}
$$

- Valeur maximale :

$$
H(X) = 1 \ \text{bit}
$$

Voir schéma : *fonction d’entropie binaire*

---

## 2.4 Exemple : source discrète non uniforme

Soit $X$ prenant ses valeurs dans :

$$
\mathcal{X} = \{00, 10, 01, 11\}
$$

avec :

$$
p_X(00) = 0.5,
\qquad
p_X(10) = p_X(01) = 0.25
$$

Alors :

$$
H(X) = 1.5 \ \text{bits}
$$

➡️ Bien que chaque symbole nécessite 2 bits pour être représenté,
l’information moyenne est **strictement inférieure** à 2 bits.

---

## 2.5 Exemple : loi uniforme discrète

Si :

$$
X \sim \mathcal{U}(\mathcal{X})
$$

alors :

$$
H(X) = \log|\mathcal{X}|
$$

et :

$$
\lceil \log|\mathcal{X}| \rceil
$$

est le nombre minimal de bits nécessaires pour représenter tous les symboles.

---

### Théorème (entropie maximale)

Pour toute variable aléatoire discrète $X$ :

$$
H(X) \le \log|\mathcal{X}|
$$

avec égalité **si et seulement si** $X$ suit une loi uniforme.

➡️ La loi uniforme est la loi **la plus incertaine** possible sur un ensemble fini.

---
### Rappel : Inégalité de Jensen

Soit $X$ une variable aléatoire intégrable et  
$\varphi : I \to \mathbb{R}$ une fonction **convexe** sur un intervalle $I$
contenant l’image de $X$.

$$
\varphi\!\big(\mathbb{E}[X]\big)
\;\le\;
\mathbb{E}\!\big[\varphi(X)\big].
$$

---

### Forme discrète (pondérée)

Soient $x_1,\dots,x_n \in I$ et $p_1,\dots,p_n \ge 0$ tels que
$\sum_{i=1}^n p_i = 1$. Alors :

$$
\varphi\!\left(\sum_{i=1}^n p_i x_i\right)
\;\le\;
\sum_{i=1}^n p_i\,\varphi(x_i).
$$

---

### Cas concave

Si $\varphi$ est **concave**, l’inégalité est inversée :

$$
\varphi\!\big(\mathbb{E}[X]\big)
\;\ge\;
\mathbb{E}\!\big[\varphi(X)\big].
$$

---

### Cas d’égalité (fonction convexe)

On a égalité si :
- $X$ est **presque sûrement constante**, ou
- $\varphi$ est **affine** sur le support de $X$.

---

### Cas strictement convexe

Si $\varphi$ est **strictement convexe**, alors :

$$
\varphi\!\big(\mathbb{E}[X]\big)
=
\mathbb{E}\!\big[\varphi(X)\big]
\quad\Longleftrightarrow\quad
X \text{ est constante p.s.}
$$

et si $X$ n’est pas constante p.s. :

$$
\varphi\!\big(\mathbb{E}[X]\big)
\;<\;
\mathbb{E}\!\big[\varphi(X)\big].
$$

---

## Synthèse du chapitre

- L’information est liée à la **rareté** des événements
- L’entropie mesure une **incertitude moyenne**
- Elle dépend uniquement de la **distribution de probabilité**
- Elle fixe une **limite fondamentale** pour la compression sans perte

---

## Liens
- ⏮️ Chapitre précédent : [[01_Paradigme_de_Shannon]]
- ⏭️ Chapitre suivant : [[03_Entropies_jointes_conditionnelles]]
