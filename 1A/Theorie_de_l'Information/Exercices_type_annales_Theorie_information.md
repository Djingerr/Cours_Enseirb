---
title: "Exercices type annales — Théorie de l'information"
tags: [theorie-information, annales, exercices, corrections, entropie, huffman]
---

# Exercices type annales — avec corrigés

Objectif : s'entraîner sur les formats qui reviennent en annales TS115.

---

# Exercice 1 — Tableau joint classique 2019

On considère la loi jointe :

| | X1 | X2 |
|---|---:|---:|
| Y1 | 1/2 | 1/4 |
| Y2 | 0 | 1/4 |

1. Calculer `H(X)` et `H(Y)` en bits.
2. Calculer `H(Y|X)`.
3. Calculer `H(X,Y)`.
4. Calculer `I(X;Y)`.

## Correction

Marginales :

$$
P(X_1)=1/2,\quad P(X_2)=1/2
$$

$$
P(Y_1)=3/4,\quad P(Y_2)=1/4
$$

Donc :

$$
H(X)=1
$$

$$
H(Y)=-\frac34\log_2\frac34-\frac14\log_2\frac14\simeq0.811
$$

Pour l'entropie conditionnelle :

- si `X=X1`, alors `Y=Y1` avec probabilité 1, donc `H(Y|X1)=0`;
- si `X=X2`, alors `Y` vaut `Y1` ou `Y2` avec probabilités `1/2,1/2`, donc `H(Y|X2)=1`.

Donc :

$$
H(Y|X)=\frac12\cdot0+\frac12\cdot1=0.5
$$

Puis :

$$
H(X,Y)=H(X)+H(Y|X)=1.5
$$

Enfin :

$$
I(X;Y)=H(Y)-H(Y|X)=0.811-0.5=0.311
$$

---

# Exercice 2 — Tableau joint classique 2021

On considère :

| | X1 | X2 |
|---|---:|---:|
| Y1 | 1/3 | 1/3 |
| Y2 | 0 | 1/3 |

1. Calculer `H(X)` et `H(Y)`.
2. Calculer `H(Y|X)` et `H(X,Y)`.
3. Les variables sont-elles indépendantes ?

## Correction

Marginales :

$$
P(X_1)=1/3,\quad P(X_2)=2/3
$$

$$
P(Y_1)=2/3,\quad P(Y_2)=1/3
$$

Donc :

$$
H(X)=H(Y)= -\frac13\log_2\frac13-\frac23\log_2\frac23\simeq0.918
$$

Conditionnellement à `X1`, `Y` est certain. Conditionnellement à `X2`, `Y` est uniforme sur deux valeurs.

$$
H(Y|X)=\frac13\cdot0+\frac23\cdot1=\frac23\simeq0.667
$$

Donc :

$$
H(X,Y)=H(X)+H(Y|X)\simeq0.918+0.667=1.585
$$

Indépendance ? Non, car :

$$
p(X_1,Y_2)=0\neq P(X_1)P(Y_2)=\frac13\cdot\frac13=\frac19
$$

---

# Exercice 3 — Tableau joint 2022

On considère :

| | X1 | X2 | P(Y) |
|---|---:|---:|---:|
| Y1 | 0.5 | 0.1 | 0.6 |
| Y2 | 0.3 | 0.1 | 0.4 |
| P(X) | 0.8 | 0.2 | 1 |

1. Calculer `H(X,Y)`, `H(X)` et `H(Y)`.
2. Démontrer `H(X,Y)=H(Y)+H(X|Y)`.
3. Calculer `H(X|Y)`.

## Correction

$$
H(X)=-0.8\log_2(0.8)-0.2\log_2(0.2)\simeq0.722
$$

$$
H(Y)=-0.6\log_2(0.6)-0.4\log_2(0.4)\simeq0.971
$$

$$
H(X,Y)= -\sum p(x,y)\log_2p(x,y)
$$

avec les probabilités `0.5,0.1,0.3,0.1`, donc :

$$
H(X,Y)\simeq1.685
$$

Démonstration :

$$
H(X|Y)=-\sum_{x,y}p(x,y)\log p(x|y)
$$

or :

$$
p(x|y)=\frac{p(x,y)}{p(y)}
$$

donc :

$$
H(X|Y)
=-\sum_{x,y}p(x,y)\log\frac{p(x,y)}{p(y)}
$$

$$
=-\sum_{x,y}p(x,y)\log p(x,y)+\sum_{x,y}p(x,y)\log p(y)
$$

$$
=H(X,Y)-H(Y)
$$

Donc :

$$
H(X,Y)=H(Y)+H(X|Y)
$$

Enfin :

$$
H(X|Y)=H(X,Y)-H(Y)\simeq1.685-0.971=0.715
$$

---

# Exercice 4 — Fonction déterministe `Y=g(X)`

Soit `H(X)=8` bits. On pose `Y=g(X)`.

1. Si `g` prend des valeurs différentes pour chaque valeur de `X`, calculer `H(Y)`, `H(Y|X)` et `I(X;Y)`.
2. Si `g` n'est pas injective, que peut-on dire de `H(Y)` et `H(Y|X)` ?

## Correction

Si `g` est injective sur le support de `X`, connaître `Y` revient à connaître `X`.

Donc :

$$
H(Y)=H(X)=8
$$

Comme `Y` est déterministe à partir de `X` :

$$
H(Y|X)=0
$$

Donc :

$$
I(X;Y)=H(Y)-H(Y|X)=8
$$

Si `g` n'est pas injective, plusieurs valeurs de `X` peuvent donner le même `Y`.

Alors :

$$
H(Y)<H(X)=8
$$

mais toujours :

$$
H(Y|X)=0
$$

car `Y` reste une fonction de `X`.

---

# Exercice 5 — Entropies simples

Calculer l'entropie en bits :

1. `X` uniforme sur `{0,...,255}`.
2. `X` déterministe.
3. `X` a trois valeurs de probabilités `1/4,1/4,1/2`.
4. `X` est binaire équilibrée.

## Correction

1. Uniforme sur 256 valeurs :

$$
H(X)=\log_2(256)=8
$$

2. Déterministe :

$$
H(X)=0
$$

3.

$$
H(X)=-\frac14\log_2\frac14-\frac14\log_2\frac14-\frac12\log_2\frac12=1.5
$$

4.

$$
H(X)=1
$$

---

# Exercice 6 — `Y=cos(X)`

On suppose :

$$
X\in\{0,\pi/2,\pi,3\pi/2,2\pi\}
$$

avec probabilités :

$$
\left\{\frac13,\frac13,\frac1{12},\frac1{12},\frac16\right\}
$$

On pose `Y=cos(X)`. Calculer `H(Y)`.

## Correction

Valeurs de `Y` :

- `Y=1` pour `X=0` ou `X=2π` :

$$
P(Y=1)=\frac13+\frac16=\frac12
$$

- `Y=0` pour `X=π/2` ou `X=3π/2` :

$$
P(Y=0)=\frac13+\frac1{12}=\frac5{12}
$$

- `Y=-1` pour `X=π` :

$$
P(Y=-1)=\frac1{12}
$$

Donc :

$$
H(Y)=-\frac12\log_2\frac12-\frac5{12}\log_2\frac5{12}-\frac1{12}\log_2\frac1{12}
$$

$$
H(Y)\simeq1.325\text{ bits}
$$

---

# Exercice 7 — Inégalité de Gibbs et maximum d'entropie

Montrer que si `X` prend ses valeurs dans un ensemble de taille `K`, alors :

$$
H(X)\le\log K
$$

avec égalité si et seulement si `X` est uniforme.

## Correction

Soit `p_i=P(X=x_i)` et soit `q_i=1/K`.

Par Gibbs :

$$
D(p\|q)=\sum_i p_i\log\frac{p_i}{q_i}\ge0
$$

Donc :

$$
\sum_i p_i\log p_i-\sum_i p_i\log\frac1K\ge0
$$

Or :

$$
\sum_i p_i\log\frac1K=\log\frac1K=-\log K
$$

Donc :

$$
\sum_i p_i\log p_i+\log K\ge0
$$

Ainsi :

$$
-\sum_i p_i\log p_i\le\log K
$$

Donc :

$$
H(X)\le\log K
$$

Égalité si et seulement si `p=q`, donc si et seulement si :

$$
p_i=\frac1K
$$

pour tout `i`.

---

# Exercice 8 — Inégalités d'entropie jointe

Montrer :

$$
H(X,Y)\le H(X)+H(Y)
$$

et préciser le cas d'égalité.

## Correction

Par la formule chaîne :

$$
H(X,Y)=H(X)+H(Y|X)
$$

Or le conditionnement réduit l'entropie :

$$
H(Y|X)\le H(Y)
$$

Donc :

$$
H(X,Y)\le H(X)+H(Y)
$$

Égalité si et seulement si :

$$
H(Y|X)=H(Y)
$$

c'est-à-dire si et seulement si `X` et `Y` sont indépendantes.

---

# Exercice 9 — Information mutuelle et indépendance

Soient `X,Y` deux variables discrètes. Montrer que :

$$
I(X;Y)\ge0
$$

avec égalité si et seulement si `X` et `Y` sont indépendantes.

## Correction

On écrit :

$$
I(X;Y)=\sum_{x,y}p(x,y)\log\frac{p(x,y)}{p_X(x)p_Y(y)}
$$

C'est une divergence KL :

$$
I(X;Y)=D(p_{X,Y}\|p_Xp_Y)
$$

Par Gibbs :

$$
D(p_{X,Y}\|p_Xp_Y)\ge0
$$

Donc :

$$
I(X;Y)\ge0
$$

Égalité si et seulement si :

$$
p_{X,Y}=p_Xp_Y
$$

c'est-à-dire si et seulement si `X` et `Y` sont indépendantes.

---

# Exercice 10 — Chaîne de Markov et information conditionnelle

Montrer que `X-Y-Z` forme une chaîne de Markov si et seulement si `X` et `Z` sont conditionnellement indépendantes sachant `Y`.

En déduire la valeur de :

$$
I(X;Z|Y)
$$

## Correction

Une chaîne de Markov `X-Y-Z` signifie que, conditionnellement à `Y`, `Z` ne dépend plus de `X` :

$$
P(Z=z|X=x,Y=y)=P(Z=z|Y=y)
$$

Cela équivaut à :

$$
P(X=x,Z=z|Y=y)=P(X=x|Y=y)P(Z=z|Y=y)
$$

Donc `X` et `Z` sont conditionnellement indépendantes sachant `Y`.

Or :

$$
I(X;Z|Y)=\sum_{x,z,y}p(x,z,y)\log\frac{p(x,z|y)}{p(x|y)p(z|y)}
$$

Si l'indépendance conditionnelle est vraie, le quotient vaut `1`, donc le log vaut `0`.

Ainsi :

$$
I(X;Z|Y)=0
$$

---

# Exercice 11 — Information mutuelle gaussienne corrélée

Soit `(X,Y)` un couple gaussien centré, de variances `σ²`, et de corrélation `ρ`.

Calculer `I(X;Y)` et commenter pour `ρ=0`, `ρ=1`, `ρ=-1`.

## Correction

Pour un couple gaussien :

$$
I(X;Y)=-\frac12\log(1-\rho^2)
$$

- Si `ρ=0` :

$$
I(X;Y)=0
$$

Dans le cas gaussien, décorrélation implique indépendance.

- Si `ρ=1` ou `ρ=-1` :

$$
1-\rho^2=0
$$

donc :

$$
I(X;Y)=+\infty
$$

Interprétation : une variable détermine parfaitement l'autre.

---

# Exercice 12 — KL entre deux gaussiennes centrées

Soient :

$$
p=N(0,\sigma_1^2),\quad q=N(0,\sigma_2^2)
$$

Calculer :

$$
D(p\|q)
$$

## Correction

Densités :

$$
p(x)=\frac1{\sqrt{2\pi\sigma_1^2}}\exp\left(-\frac{x^2}{2\sigma_1^2}\right)
$$

$$
q(x)=\frac1{\sqrt{2\pi\sigma_2^2}}\exp\left(-\frac{x^2}{2\sigma_2^2}\right)
$$

Alors :

$$
\log\frac{p(x)}{q(x)}
=
\log\frac{\sigma_2}{\sigma_1}
-\frac{x^2}{2\sigma_1^2}
+\frac{x^2}{2\sigma_2^2}
$$

On prend l'espérance sous `p`, donc `E_p[X²]=σ1²`.

$$
D(p\|q)
=\log\frac{\sigma_2}{\sigma_1}
-\frac12
+\frac{\sigma_1^2}{2\sigma_2^2}
$$

Donc :

$$
D(p\|q)=
\log\left(\frac{\sigma_2}{\sigma_1}\right)
+\frac{\sigma_1^2}{2\sigma_2^2}
-\frac12
$$

---

# Exercice 13 — Huffman binaire 2019

On considère une source de probabilités :

$$
0.1,\;0.2,\;0.15,\;0.3,\;0.25
$$

1. Construire les longueurs d'un code de Huffman binaire.
2. Calculer la longueur moyenne.
3. Comparer à l'entropie.

## Correction

Un arbre de Huffman donne par exemple les longueurs :

| probabilité | longueur |
|---:|---:|
| 0.30 | 2 |
| 0.25 | 2 |
| 0.20 | 2 |
| 0.15 | 3 |
| 0.10 | 3 |

Longueur moyenne :

$$
L=0.30\cdot2+0.25\cdot2+0.20\cdot2+0.15\cdot3+0.10\cdot3=2.25
$$

Entropie :

$$
H\simeq2.228
$$

Donc :

$$
H\le L < H+1
$$

Le résultat est conforme au théorème de Shannon.

---

# Exercice 14 — Huffman binaire et ternaire 2021

Source de probabilités :

$$
0.49,\;0.26,\;0.12,\;0.04,\;0.04,\;0.03,\;0.02
$$

1. Donner des longueurs de Huffman binaire.
2. Donner des longueurs de Huffman ternaire.
3. Comparer avec l'entropie.

## Correction

## Binaire

Longueurs possibles :

| probabilité | longueur |
|---:|---:|
| 0.49 | 1 |
| 0.26 | 2 |
| 0.12 | 3 |
| 0.04 | 5 |
| 0.04 | 5 |
| 0.03 | 5 |
| 0.02 | 5 |

Longueur moyenne :

$$
L_2=2.02
$$

Entropie binaire :

$$
H_2\simeq2.013
$$

Donc `L2` est quasi optimal.

## Ternaire

Un arbre ternaire nécessite un nombre impair de feuilles. Ici il y a 7 symboles, donc c'est compatible.

Longueurs possibles :

| probabilité | longueur ternaire |
|---:|---:|
| 0.49 | 1 |
| 0.26 | 1 |
| 0.12 | 2 |
| 0.04 | 3 |
| 0.04 | 2 |
| 0.03 | 3 |
| 0.02 | 3 |

Longueur moyenne :

$$
L_3=1.34
$$

Entropie en trits :

$$
H_3\simeq1.270
$$

Donc :

$$
H_3\le L_3 < H_3+1
$$

---

# Exercice 15 — Huffman 2022

Source :

| symbole | a | b | c | d | e | f | g |
|---|---:|---:|---:|---:|---:|---:|---:|
| probabilité | 0.20 | 0.12 | 0.08 | 0.15 | 0.25 | 0.10 | 0.10 |

1. Construire des longueurs de Huffman binaire.
2. Calculer la longueur moyenne.
3. Comparer à l'entropie.

## Correction

Longueurs possibles :

| symbole | proba | longueur |
|---|---:|---:|
| e | 0.25 | 2 |
| a | 0.20 | 2 |
| d | 0.15 | 3 |
| b | 0.12 | 3 |
| f | 0.10 | 4 |
| g | 0.10 | 3 |
| c | 0.08 | 4 |

Longueur moyenne :

$$
L=2.73
$$

Entropie :

$$
H\simeq2.698
$$

Conclusion :

$$
H\le L < H+1
$$

Le résultat était prévisible par le théorème du codage source de Shannon.

---

# Exercice 16 — Codes possibles ou impossibles

Dire si les codes suivants peuvent être des codes de Huffman binaires :

1. `{0,10,11}`
2. `{00,01,10,110,111}`
3. `{01,10}`

## Correction

## 1. `{0,10,11}`

C'est un code préfixe complet. Il peut être un Huffman.

Longueurs : `1,2,2`.

Kraft :

$$
2^{-1}+2^{-2}+2^{-2}=1
$$

Possible.

## 2. `{00,01,10,110,111}`

Code préfixe complet.

Kraft :

$$
3\cdot2^{-2}+2\cdot2^{-3}=\frac34+\frac14=1
$$

Cependant, dans un arbre binaire de Huffman, les deux mots les plus longs doivent être frères. Ici `110` et `111` sont frères, donc ce n'est pas éliminé par cette propriété. Il peut être compatible selon certaines probabilités.

## 3. `{01,10}`

Code préfixe mais non complet :

$$
2^{-2}+2^{-2}=\frac12<1
$$

Pour un code de Huffman binaire avec deux symboles, l'arbre optimal aurait deux mots de longueur 1 : `{0,1}`. Donc `{01,10}` ne peut pas être un Huffman optimal.

---

# Exercice 17 — Code non préfixe mais décodable ?

On considère :

$$
a\to010,\quad b\to0100,\quad c\to0010
$$

1. Le code est-il préfixe ?
2. Est-il décodable de façon unique ?

## Correction

Il n'est pas préfixe car :

$$
010
$$

est préfixe de :

$$
0100
$$

Donc le code n'est pas instantanément décodable.

Pour la décodabilité unique, il faut tester si une concaténation peut être ambiguë. Ici :

- `b = 0100`;
- `a` suivi d'un début éventuel ne suffit pas automatiquement à refaire `0100`, car `a=010` laisse un `0`, qui n'est pas un mot complet.

On ne conclut pas seulement avec la non-préfixité. En annale, il faut justifier par un test d'ambiguïté ou Sardinas-Patterson.

Test rapide : les suffixes créés par l'inclusion `010` préfixe de `0100` donnent le suffixe `0`. Aucun mot ne commence par un suffixe permettant de boucler vers un mot complet ambigu. On conclut que le code peut rester décodable de façon unique, même s'il n'est pas préfixe.

Phrase type : “le code ne respecte pas la loi du préfixe, mais la non-préfixité ne suffit pas à dire qu'il n'est pas décodable.”

---

# Exercice 18 — Théorème du codage source

Rappeler le théorème du codage source et l'interpréter.

## Correction

Pour une source `X` et un code déchiffrable sur un alphabet de taille `d` :

$$
L(\phi)\ge\frac{H(X)}{\log d}
$$

Il existe un code préfixe tel que :

$$
\frac{H(X)}{\log d}\le L(\phi)\le\frac{H(X)}{\log d}+1
$$

En binaire :

$$
H_2(X)\le L(\phi)\le H_2(X)+1
$$

Interprétation :
- on ne peut pas compresser en moyenne en dessous de l'entropie;
- Huffman construit un code optimal parmi les codes préfixes;
- le codage par blocs permet de rapprocher la longueur moyenne par symbole de l'entropie.

---

# Exercice 19 — Canal additif gaussien

On considère :

$$
Y=X+W
$$

avec `W~N(0,σ²)` indépendant de `X`.

1. Montrer que `h(Y|X)=1/2 log(2πeσ²)`.
2. Si `X~N(0,γ²)`, calculer `I(X;Y)`.
3. Donner la capacité si `Var(X)≤γ²`.

## Correction

Sachant `X=x`, on a :

$$
Y|X=x=x+W
$$

Une translation ne change pas l'entropie différentielle, donc :

$$
h(Y|X)=h(W)=\frac12\log(2\pi e\sigma^2)
$$

Si `X~N(0,γ²)`, alors :

$$
Y\sim N(0,\gamma^2+\sigma^2)
$$

Donc :

$$
h(Y)=\frac12\log(2\pi e(\gamma^2+\sigma^2))
$$

Ainsi :

$$
I(X;Y)=h(Y)-h(Y|X)
$$

$$
I(X;Y)=\frac12\log\left(\frac{\gamma^2+\sigma^2}{\sigma^2}\right)
$$

$$
I(X;Y)=\frac12\log\left(1+\frac{\gamma^2}{\sigma^2}\right)
$$

Capacité :

$$
C=\frac12\log\left(1+\frac{\gamma^2}{\sigma^2}\right)
$$

atteinte pour `X` gaussienne.

---

# Exercice 20 — Sujet blanc complet

Durée recommandée : 1h.

## Partie 1 — Calculs d'entropie

Soit :

| | X1 | X2 | X3 |
|---|---:|---:|---:|
| Y1 | 0.20 | 0.10 | 0.10 |
| Y2 | 0.05 | 0.25 | 0.30 |

1. Calculer `H(X)`, `H(Y)`, `H(X,Y)`.
2. Calculer `H(Y|X)`, `H(X|Y)` et `I(X;Y)`.

## Partie 2 — Théorie

Montrer que :

$$
I(X;Y)=0
$$

si et seulement si `X` et `Y` sont indépendantes.

## Partie 3 — Huffman

Source de probabilités :

$$
0.40,\;0.20,\;0.15,\;0.10,\;0.10,\;0.05
$$

1. Construire un code de Huffman binaire.
2. Calculer `L`.
3. Comparer avec `H`.

## Partie 4 — Gaussien

Soit `(X,Y)` gaussien de corrélation `ρ=0.8`. Calculer `I(X;Y)` en nats puis en bits.

## Correction rapide

## Partie 1

Marginales :

$$
P(X)=(0.25,0.35,0.40)
$$

$$
P(Y)=(0.40,0.60)
$$

Calculs :

$$
H(X)\simeq1.559
$$

$$
H(Y)\simeq0.971
$$

$$
H(X,Y)\simeq2.409
$$

Donc :

$$
H(Y|X)=H(X,Y)-H(X)\simeq0.850
$$

$$
H(X|Y)=H(X,Y)-H(Y)\simeq1.438
$$

$$
I(X;Y)=H(X)+H(Y)-H(X,Y)\simeq0.121
$$

## Partie 2

Voir Exercice 9 : `I(X;Y)=D(p_{X,Y}||p_Xp_Y)`.

## Partie 3

Longueurs Huffman possibles :

| p | longueur |
|---:|---:|
| 0.40 | 1 |
| 0.20 | 3 |
| 0.15 | 3 |
| 0.10 | 3 |
| 0.10 | 4 |
| 0.05 | 4 |

Longueur :

$$
L=0.40\cdot1+0.20\cdot3+0.15\cdot3+0.10\cdot3+0.10\cdot4+0.05\cdot4=2.35
$$

Entropie :

$$
H\simeq2.285
$$

Donc :

$$
H\le L<H+1
$$

## Partie 4

En nats :

$$
I(X;Y)=-\frac12\ln(1-0.8^2)
$$

$$
I(X;Y)=-\frac12\ln(0.36)\simeq0.511
$$

En bits :

$$
I_2=\frac{0.511}{\ln2}\simeq0.737
$$
