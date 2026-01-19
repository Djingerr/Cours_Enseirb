# Chapitre 7 — Théorème fondamental du codage source

## Introduction

Les chapitres précédents ont introduit :
- l’**entropie**, comme mesure fondamentale de l’information,
- les **codes source**, comme outils concrets de compression.

Une question centrale demeure :

> **Quelle est la meilleure compression possible, indépendamment de l’algorithme utilisé ?**

Le **théorème fondamental du codage source**, dû à Shannon, répond précisément
à cette question en établissant une **borne théorique infranchissable**.

---

## 7.1 Codes optimaux

### Définition

Un code source $\varphi$ est dit **optimal** s’il est :
- déchiffrable,
- et de **longueur moyenne minimale** parmi tous les codes déchiffrables.

---

### Remarques importantes

- Il existe toujours au moins **un code optimal**
- On peut toujours choisir un **code préfixe optimal**

➡️ Cela justifie l’étude privilégiée des codes préfixes.

---

## 7.2 Structure d’un code optimal

### Théorème (structure)

Soit $X$ une source discrète et $\varphi$ un code optimal.

1. Si :

$$
p_X(x) > p_X(y)
$$

alors :

$$
\ell(\varphi(x)) \le \ell(\varphi(y))
$$

➡️ Les symboles les plus probables ont des mots **plus courts**.

---

2. Si $\varphi$ est préfixe et si $\varphi(x)$ est de longueur maximale,
alors il existe $y \neq x$ tel que :
- $\ell(\varphi(x)) = \ell(\varphi(y))$,
- les deux mots de code ne diffèrent que par leur **dernier symbole**.

➡️ Cette propriété est à la base de l’algorithme de Huffman.

---

## 7.3 Théorème de Shannon — borne inférieure

### Énoncé (1ʳᵉ partie)

Soit :
- $X$ une source discrète,
- $\varphi$ un code déchiffrable d’alphabet $\mathcal{A}$ de cardinal $d$.

Alors :

$$
L(\varphi)
\ge
\frac{H(X)}{\log d}
$$

---

### Interprétation

- $\log d$ correspond à l’entropie d’un symbole de l’alphabet
- $\dfrac{H(X)}{\log d}$ est l’**entropie exprimée dans la base du code**

➡️ **Aucun code ne peut battre l’entropie.**

---

### Cas d’égalité

L’égalité est atteinte si et seulement si :

$$
\ell(\varphi(x)) = -\log_d p_X(x)
\quad
\forall x \in \mathcal{X}
$$

➡️ Ces longueurs idéales ne sont pas toujours entières.

---

## 7.4 Exemple d’optimalité

Soit une source $\mathcal{X} = \{x_1,x_2,x_3,x_4\}$ telle que :

$$
p_X(x_1)=\frac{1}{2},
\quad
p_X(x_2)=\frac{1}{4},
\quad
p_X(x_3)=p_X(x_4)=\frac{1}{8}
$$

Alors :

$$
H(X) = 1.75 \ \text{bits}
$$

Un code préfixe atteignant cette valeur est :

| Symbole | Mot de code |
|-------|-------------|
| $x_1$ | 0 |
| $x_2$ | 10 |
| $x_3$ | 110 |
| $x_4$ | 111 |

On a alors :

$$
L(\varphi) = H(X)
$$

➡️ La borne de Shannon est **atteignable**.

---

## 7.5 Codes de Shannon–Fano

### Définition

Un **code de Shannon–Fano** est un code dont les longueurs vérifient :

$$
\ell(\varphi(x)) = \lceil -\log_d p_X(x) \rceil
$$

---

### Propriété

On vérifie que :

$$
\sum_{x \in \mathcal{X}} d^{-\ell(\varphi(x))} \le 1
$$

➡️ Le théorème de Kraft garantit alors l’existence
d’un **code préfixe** associé.

---

## 7.6 Théorème de Shannon — borne supérieure

### Énoncé (2ᵉ partie)

Il existe toujours un code préfixe $\varphi$ tel que :

$$
\frac{H(X)}{\log d}
\le
L(\varphi)
\le
\frac{H(X)}{\log d} + 1
$$

---

### Conséquence fondamentale

➡️ La longueur moyenne d’un code optimal est à **moins d’un symbole**
de l’entropie.

C’est une **limite universelle**, indépendante de l’algorithme utilisé.

---

## 7.7 Codage par blocs

### Principe

Pour réduire l’écart de $+1$ symbole, on peut :
- regrouper les symboles par blocs de taille $n$,
- coder la source étendue $X^n$.

---

### Résultat

Il existe un code préfixe $\varphi_n$ tel que :

$$
\frac{H(X)}{\log d}
\le
L_n(\varphi_n)
<
\frac{H(X)}{\log d} + \frac{1}{n}
$$

où :

$$
L_n(\varphi_n)
=
\frac{1}{n}
\sum_{x \in \mathcal{X}^n}
p_X(x)\,
\ell(\varphi_n(x))
$$

---

### Interprétation

➡️ En augmentant la taille des blocs :
- la longueur moyenne **tend vers l’entropie**,
- au prix d’une **complexité accrue**.

---

## Synthèse du chapitre

- L’entropie fixe une limite fondamentale à la compression
- Aucun code ne peut avoir une longueur moyenne inférieure à $H(X)$
- Des codes préfixes peuvent approcher cette limite à $+1$ symbole près
- Le codage par blocs permet d’atteindre l’entropie asymptotiquement

---

## Liens
- ⏮️ Chapitre précédent : [[06_Codage_source_Codes]]
- ⏭️ Chapitre suivant : [[08_Code_de_Huffman]]
