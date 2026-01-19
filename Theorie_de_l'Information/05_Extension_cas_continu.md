# Chapitre 5 — Extension au cas continu

## Introduction

Jusqu’à présent, nous avons travaillé avec des **variables aléatoires discrètes**.
Cependant, de nombreux phénomènes réels sont mieux modélisés par des
**variables aléatoires continues** (signaux physiques, bruit, mesures, etc.).

Ce chapitre étend les notions :
- d’entropie,
- d’entropie jointe et conditionnelle,
- de divergence de Kullback–Leibler,
- d’information mutuelle,

au **cas continu**, en soulignant les différences conceptuelles importantes
avec le cadre discret.

---

## 5.1 Entropie différentielle

### Définition

Soit $X$ une variable aléatoire continue de densité $f_X$, définie sur un support
$\mathcal{X} \subset \mathbb{R}$.

L’**entropie différentielle** de $X$ est définie par :

$$
H(X)
=
-\int_{\mathcal{X}}
f_X(x)\,\log\big(f_X(x)\big)\,\mathrm{d}x
$$

---

### Remarques importantes

- L’entropie différentielle **n’est pas toujours définie**
- Elle peut être **négative**
- Elle dépend du **choix d’unité** (changement d’échelle)

➡️ Contrairement au cas discret, l’entropie différentielle **n’est pas une
mesure absolue d’information**.

---

## 5.2 Exemples classiques

### Loi uniforme continue

Soit :

$$
X \sim \mathcal{U}([a,b])
$$

Alors :

$$
H(X) = \log(b-a)
$$

Si $b-a < 1$, alors :

$$
H(X) < 0
$$

---

### Loi normale (gaussienne)

Soit :

$$
X \sim \mathcal{N}(\mu,\sigma^2)
$$

Alors :

$$
H(X)
=
\frac{1}{2}
\log\!\big(2\pi e\,\sigma^2\big)
$$

---

### Observations

- L’entropie **ne dépend pas de $\mu$**
- Si :

$$
\sigma^2 < \frac{1}{2\pi e}
$$

alors :

$$
H(X) < 0
$$

---

## 5.3 Entropie jointe (cas continu)

### Définition

Soit :

$$
\mathbf{X} = (X_1,\dots,X_n)
$$

un vecteur aléatoire continu de densité jointe $f_{\mathbf{X}}$.

L’entropie différentielle jointe est définie par :

$$
H(\mathbf{X})
=
-\int_{\mathcal{X}}
f_{\mathbf{X}}(x)\,
\log\big(f_{\mathbf{X}}(x)\big)\,
\mathrm{d}x
$$

où $\mathcal{X} = \mathrm{supp}(f_{\mathbf{X}})$.

---

### Exemple : loi normale multivariée

Soit :

$$
\mathbf{X} \sim \mathcal{N}_n(\mu,\Sigma)
$$

de densité :

$$
f_{\mathbf{X}}(x)
=
\frac{1}{(2\pi)^{n/2}\sqrt{\det(\Sigma)}}
\exp\!\left(
-\frac{1}{2}
(x-\mu)^\top\Sigma^{-1}(x-\mu)
\right)
$$

Alors :

$$
H(\mathbf{X})
=
\frac{1}{2}
\log\!\big((2\pi e)^n \det(\Sigma)\big)
$$

---

## 5.4 Entropie conditionnelle (cas continu)

### Définition

Soit $(X,Y)$ un couple aléatoire continu de densité jointe $f_{X,Y}$.

L’**entropie différentielle conditionnelle** de $X$ sachant $Y$ est définie par :

$$
H(X \mid Y)
=
-\int_{\mathcal{X}\times\mathcal{Y}}
f_{X,Y}(x,y)\,
\log\big(f_{X\mid Y=y}(x)\big)\,
\mathrm{d}x\,\mathrm{d}y
$$

où :

$$
f_{X\mid Y=y}(x)
=
\frac{f_{X,Y}(x,y)}{f_Y(y)}
\quad
\text{si } f_Y(y)>0
$$

---

### Propriétés

Sous réserve d’existence finie des entropies :

$$
H(X,Y) = H(Y) + H(X \mid Y)
$$

et :

$$
H(X \mid Y) \le H(X)
$$

---

## 5.5 Divergence de Kullback–Leibler (cas continu)

### Définition

Soient $f$ et $g$ deux densités définies sur $\mathbb{R}$,
telles que :

$$
\mathrm{supp}(g) \subset \mathrm{supp}(f)
$$

La divergence KL est définie par :

$$
D(f \| g)
=
\int
f(x)\,
\log\!\left(
\frac{f(x)}{g(x)}
\right)
\mathrm{d}x
$$

---

### Propriété fondamentale (lemme de Gibbs)

$$
D(f \| g) \ge 0
$$

avec égalité **si et seulement si** $f = g$ presque partout.

---

### Exemple : lois normales

Soient :

$$
f_i = \mathcal{N}(\mu_i,\sigma_i^2),
\quad i \in \{1,2\}
$$

Alors :

$$
D(f_1 \| f_2)
=
\frac{1}{2}
\left(
\frac{\sigma_1^2}{\sigma_2^2}
-
\log\!\left(\frac{\sigma_1^2}{\sigma_2^2}\right)
+
\frac{(\mu_1-\mu_2)^2}{\sigma_2^2}
-
1
\right)
$$

---

## 5.6 Information mutuelle (cas continu)

### Définition

Soit $(X,Y)$ un couple aléatoire continu.

L’information mutuelle est définie par :

$$
I(X;Y)
=
\int
f_{X,Y}(x,y)\,
\log\!\left(
\frac{f_{X,Y}(x,y)}
{f_X(x)\,f_Y(y)}
\right)
\mathrm{d}x\,\mathrm{d}y
$$

---

### Propriété clé

$$
I(X;Y)
=
D\big(f_{X,Y} \| f_X \otimes f_Y\big)
\ge 0
$$

avec égalité **si et seulement si** $X$ et $Y$ sont indépendantes.

---

## 5.7 Théorème du maximum d’entropie différentielle

### Énoncé

Soit $X$ une variable aléatoire continue de moyenne $\mu$ et de variance $\sigma^2$.

Alors :

$$
H(X)
\le
\frac{1}{2}
\log\!\big(2\pi e\,\sigma^2\big)
$$

avec égalité **si et seulement si** :

$$
X \sim \mathcal{N}(\mu,\sigma^2)
$$

---

### Interprétation

➡️ Parmi toutes les variables continues de variance donnée,
la **loi gaussienne est la plus incertaine**.

---

## Synthèse du chapitre

- L’entropie différentielle généralise l’entropie discrète
- Elle peut être négative et dépend de l’échelle
- La loi gaussienne maximise l’entropie à variance fixée
- Les relations entropiques restent valables sous conditions
- L’information mutuelle reste une mesure robuste de dépendance

---

## Liens
- ⏮️ Chapitre précédent : [[04_Divergence_KL_Information_mutuelle]]
- ⏭️ Chapitre suivant : [[06_Codage_source_Codes]]
