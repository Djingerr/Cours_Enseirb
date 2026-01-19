# Chapitre 4 — Divergence de Kullback–Leibler et information mutuelle

## Introduction

Dans les chapitres précédents, nous avons introduit l’entropie comme mesure
d’incertitude, puis étudié comment cette incertitude se répartit entre plusieurs
variables aléatoires.

Ce chapitre introduit deux notions fondamentales :
- la **divergence de Kullback–Leibler**, qui mesure la différence entre deux lois de probabilité,
- l’**information mutuelle**, qui quantifie l’information partagée entre deux variables.

Ces outils sont centraux en :
- théorie de l’information,
- statistiques,
- apprentissage automatique,
- télécommunications.

---

## 4.1 Divergence de Kullback–Leibler (cas discret)

### Objectif

Comparer deux distributions de probabilité définies sur le même ensemble.

➡️ Contrairement à l’entropie, il ne s’agit plus de mesurer une incertitude,
mais une **dissemblance** entre deux lois.

---

### Définition

Soient $p$ et $q$ deux fonctions de masse définies sur un ensemble fini $\mathcal{Z}$,
telles que :

$$
\mathrm{supp}(p) \subset \mathrm{supp}(q)
$$

La **divergence de Kullback–Leibler** de $q$ par rapport à $p$ est définie par :

$$
D(p \| q)
=
\sum_{z \in \mathcal{Z}}
p(z)\,
\log\!\left(
\frac{p(z)}{q(z)}
\right)
$$

---

### Interprétation

- $D(p \| q)$ mesure la **perte d’information** lorsque $q$ est utilisée
  pour approximer $p$
- Elle compare une loi vraie ($p$) à une loi de référence ($q$)

➡️ Plus $D(p \| q)$ est grande, plus les distributions sont différentes.

---

### Propriété fondamentale (inégalité de Gibbs)

On a toujours :

$$
D(p \| q) \ge 0
$$

avec égalité **si et seulement si** :

$$
p = q
$$

---

### Remarques importantes

- $D(p \| q)$ **n’est pas une distance**
- Elle n’est :
  - ni symétrique : $D(p \| q) \neq D(q \| p)$
  - ni soumise à l’inégalité triangulaire

---

## 4.2 Exemple : divergence entre lois de Bernoulli

Soient :
- $p$ la loi de Bernoulli de paramètre $\alpha$,
- $q$ la loi de Bernoulli de paramètre $\beta$.

Alors :

$$
D(p \| q)
=
\alpha \log\!\left(\frac{\alpha}{\beta}\right)
+
(1-\alpha)\log\!\left(\frac{1-\alpha}{1-\beta}\right)
$$

---

### Cas particulier

- $D(p \| q) = 0$  
  ⟺ $\alpha = \beta$

➡️ La divergence mesure bien une **différence de paramétrisation**.

---

## 4.3 Information mutuelle (cas discret)

### Définition

Soient $X$ et $Y$ deux variables aléatoires discrètes.

L’**information mutuelle** entre $X$ et $Y$ est définie par :

$$
I(X;Y)
=
H(X) - H(X \mid Y)
$$

---

### Interprétation

\[
\text{information mutuelle}
=
\text{incertitude initiale}
-
\text{incertitude restante}
\]

➡️ $I(X;Y)$ mesure la **quantité d’information apportée par $Y$ sur $X$**.

---

### Symétrie

Bien que la définition semble asymétrique :

$$
I(X;Y) = I(Y;X)
$$

➡️ L’information partagée est réciproque.

---

## 4.4 Expression via la divergence de Kullback–Leibler

### Théorème fondamental

L’information mutuelle peut s’écrire comme une divergence :

$$
I(X;Y)
=
D\big(
p_{X,Y}
\;\|\;
p_X \otimes p_Y
\big)
$$

c’est-à-dire :

$$
I(X;Y)
=
\sum_{x,y}
p_{X,Y}(x,y)\,
\log\!\left(
\frac{p_{X,Y}(x,y)}
{p_X(x)\,p_Y(y)}
\right)
$$

---

### Interprétation

- $p_X \otimes p_Y$ correspond au cas **indépendant**
- $I(X;Y)$ mesure l’écart entre :
  - la loi jointe réelle,
  - la loi jointe sous hypothèse d’indépendance

➡️ Toute dépendance statistique génère de l’information mutuelle.

---

## 4.5 Propriétés de l’information mutuelle

On a toujours :

$$
0 \le I(X;Y) \le H(X)
$$

et, par symétrie :

$$
0 \le I(X;Y) \le H(Y)
$$

---

### Cas d’égalité

- $I(X;Y) = 0$  
  **si et seulement si** $X$ et $Y$ sont indépendantes

- $I(X;Y) = H(X)$  
  **si et seulement si** il existe une fonction déterministe $f$ telle que :

$$
X = f(Y)
\quad \text{presque sûrement}
$$

---

## 4.6 Lien avec les télécommunications

Dans un canal de communication :
- $X$ : symbole émis,
- $Y$ : symbole reçu.

$I(X;Y)$ mesure la **dégradation de l’information** introduite par le canal.

La **capacité du canal** est définie par :

$$
C
=
\sup_{p_X}
I(X;Y)
$$

où le supremum est pris sur toutes les lois possibles de $X$.

---

## Synthèse du chapitre

- La divergence KL compare deux distributions
- Elle est toujours positive et nulle uniquement à l’égalité
- L’information mutuelle mesure une dépendance statistique
- Elle s’exprime comme une divergence KL
- Elle joue un rôle central dans la capacité des canaux

---

## Liens
- ⏮️ Chapitre précédent : [[03_Entropies_jointes_conditionnelles]]
- ⏭️ Chapitre suivant : [[05_Extension_cas_continu]]
