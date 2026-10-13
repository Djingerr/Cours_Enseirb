# Chapitre 3 — Entropies jointes et conditionnelles

## Introduction

Dans le chapitre précédent, nous avons défini l’**entropie d’une variable aléatoire**
comme une mesure de l’incertitude moyenne associée à une source.

Dans de nombreuses situations, plusieurs variables aléatoires interagissent.
Il est alors nécessaire de mesurer :
- l’information portée par **plusieurs variables simultanément**,
- l’information restante sur une variable **lorsqu’une autre est connue**.

Ces notions sont formalisées par l’**entropie jointe** et l’**entropie conditionnelle**.

---

## 3.1 Entropie jointe

### Définition

Soient $X$ et $Y$ deux variables aléatoires discrètes, à valeurs dans des ensembles
finis $\mathcal{X}$ et $\mathcal{Y}$.

L’**entropie jointe** du couple $(X,Y)$ est définie par :

$$
H(X,Y)
=
-\sum_{(x,y)\in\mathcal{X}\times\mathcal{Y}}
p_{X,Y}(x,y)\,
\log\big(p_{X,Y}(x,y)\big)
$$

où :

$$
p_{X,Y}(x,y) = \mathbb{P}(X=x,\,Y=y)
$$

---

### Interprétation

- $H(X,Y)$ mesure l’**incertitude globale** portée par le couple $(X,Y)$
- Il s’agit simplement de l’entropie de la variable vectorielle $(X,Y)$

---

### Propriétés fondamentales

On a toujours :

$$
\max\big(H(X),\,H(Y)\big)
\le
H(X,Y)
\le
H(X) + H(Y)
$$

---

### Cas d’égalité

- $H(X,Y) = H(X) + H(Y)$  
  **si et seulement si** $X$ et $Y$ sont **indépendantes**

➡️ L’indépendance correspond à une absence totale de redondance d’information.

---

## 3.2 Entropie conditionnelle

### Définition

L’**entropie conditionnelle** de $X$ sachant $Y$ est définie par :

$$
H(X \mid Y)
=
-\sum_{(x,y)\in\mathcal{X}\times\mathcal{Y}}
p_{X,Y}(x,y)\,
\log\big(p_{X\mid Y=y}(x)\big)
$$

où :

$$
p_{X\mid Y=y}(x) = \mathbb{P}(X=x \mid Y=y)
$$

---

### Interprétation

$H(X \mid Y)$ mesure la **quantité d’information restante sur $X$**
lorsque la valeur de $Y$ est connue.

- Si $Y$ donne beaucoup d’informations sur $X$, alors $H(X \mid Y)$ est faible
- Si $Y$ n’apporte aucune information sur $X$, alors $H(X \mid Y)=H(X)$

---

### Relation fondamentale (règle de chaîne)

On a la relation clé :

$$
H(X,Y) = H(Y) + H(X \mid Y)
$$

➡️ Cette relation est l’analogue entropique de la factorisation :

$$
p_{X,Y}(x,y) = p_Y(y)\,p_{X\mid Y=y}(x)
$$

---

## 3.3 Propriétés de l’entropie conditionnelle

On a toujours :

$$
0 \le H(X \mid Y) \le H(X)
$$

---

### Cas d’égalité

- $H(X \mid Y) = 0$  
  **si et seulement si** il existe une fonction déterministe $f$ telle que :

$$
X = f(Y)
\quad \text{presque sûrement}
$$

- $H(X \mid Y) = H(X)$  
  **si et seulement si** $X$ et $Y$ sont **indépendantes**

---

## 3.4 Lecture intuitive

- L’entropie jointe augmente avec le **nombre de variables**
- L’entropie conditionnelle mesure ce qui **reste à apprendre**
- Connaître une variable ne peut **jamais augmenter** l’incertitude sur une autre

---

## 3.5 Lien avec la suite du cours

Ces notions permettent d’introduire naturellement :
- l’**information mutuelle**,
- la **divergence de Kullback–Leibler**,
- la **capacité d’un canal**.

Elles constituent donc une étape essentielle vers l’étude du **codage canal**.

---

## Synthèse du chapitre

- $H(X,Y)$ mesure l’incertitude globale d’un couple
- $H(X \mid Y)$ mesure l’incertitude restante
- La relation $H(X,Y)=H(Y)+H(X\mid Y)$ est fondamentale
- L’indépendance joue un rôle central dans les cas d’égalité

---

## Liens
- ⏮️ Chapitre précédent : [[02_Mesure_de_l_information_Entropie]]
- ⏭️ Chapitre suivant : [[04_Divergence_KL_Information_mutuelle]]
