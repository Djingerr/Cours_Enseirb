# Chapitre 8 — Code de Huffman

## Introduction

Le théorème fondamental du codage source a montré l’existence de codes
**quasi-optimaux**, atteignant l’entropie à une constante additive près.

Le **code de Huffman**, proposé par David Huffman en 1952, fournit une
**méthode algorithmique explicite** permettant de construire un
**code préfixe de longueur moyenne minimale**.

➡️ Il s’agit de l’algorithme de compression sans perte le plus célèbre
en théorie de l’information.

---

## 8.1 Principe général

### Idée clé

Le code de Huffman repose sur une intuition simple :

> **Les symboles les moins probables doivent avoir les mots de code les plus longs,
et partager une structure commune.**

Cela conduit à une construction **hiérarchique** sous forme d’arbre binaire.

---

## 8.2 Hypothèses et cadre

On considère :
- une source discrète $X$ à valeurs dans $\mathcal{X} = \{x_1,\dots,x_m\}$,
- des probabilités strictement positives :
  
$$
p_X(x_1) \ge \dots \ge p_X(x_m) > 0
$$

- un alphabet binaire $\mathcal{A} = \{0,1\}$.

---

## 8.3 Algorithme de Huffman (alphabet binaire)

### Cas de base

Si $m = 2$, on définit directement :

$$
\varphi(x_1) = 0,
\qquad
\varphi(x_2) = 1
$$

---

### Étape récursive

Si $m > 2$ :

1. Sélectionner les **deux symboles les moins probables** :
   
$$
x_{m-1}, \; x_m
$$

2. Construire un **supersymbole** :

$$
x_{m-1}x_m
$$

de probabilité :

$$
p_X(x_{m-1}x_m)
=
p_X(x_{m-1}) + p_X(x_m)
$$

3. Construire récursivement un code de Huffman pour la source réduite :

$$
\mathcal{X}' = \{x_1,\dots,x_{m-2},x_{m-1}x_m\}
$$

4. Déduire le code final :

$$
\varphi(x) =
\begin{cases}
\varphi'(x) & \text{si } x \in \{x_1,\dots,x_{m-2}\} \\
(\varphi'(x_{m-1}x_m),0) & \text{si } x = x_{m-1} \\
(\varphi'(x_{m-1}x_m),1) & \text{si } x = x_m
\end{cases}
$$

---

### Propriété immédiate

- Les deux symboles les moins probables ont :
  - la **même longueur**,
  - des mots de code qui ne diffèrent que par le **dernier bit**.

---

## 8.4 Représentation par arbre binaire

Le code de Huffman peut être représenté par un **arbre binaire** :

- chaque feuille correspond à un symbole,
- chaque arête est étiquetée par 0 ou 1,
- le mot de code est le chemin racine → feuille.

➡️ Cette représentation garantit que le code est **préfixe**.

---

## 8.5 Exemple détaillé

Considérons une source $\mathcal{X} = \{x_1,x_2,x_3,x_4\}$ avec :

$$
p_X(x_1)=0.5,
\quad
p_X(x_2)=0.25,
\quad
p_X(x_3)=0.125,
\quad
p_X(x_4)=0.125
$$

---

### Étape 1 — tri des probabilités

$$
x_1 : 0.5,
\quad
x_2 : 0.25,
\quad
x_3 : 0.125,
\quad
x_4 : 0.125
$$

---

### Étape 2 — regroupement

On regroupe $x_3$ et $x_4$ :

$$
p(x_3x_4) = 0.25
$$

Nouvelle source :

$$
\{x_1, x_2, x_3x_4\}
$$

---

### Étape 3 — itération

On regroupe :

$$
x_2 \text{ et } x_3x_4
$$

---

### Étape 4 — code final

On obtient :

| Symbole | Mot de code |
|-------|-------------|
| $x_1$ | 0 |
| $x_2$ | 10 |
| $x_3$ | 110 |
| $x_4$ | 111 |

---

### Longueur moyenne

$$
L(\varphi)
=
0.5 \times 1
+ 0.25 \times 2
+ 0.125 \times 3
+ 0.125 \times 3
=
1.75
$$

➡️ Le code de Huffman est **optimal**.

---

## 8.6 Optimalité du code de Huffman

### Théorème

Le code de Huffman est :
- **préfixe**,
- de **longueur moyenne minimale** parmi tous les codes préfixes.

---

### Idée de la preuve

- Utilise la **structure des codes optimaux** (chapitre 7)
- Montre que la fusion des deux symboles les moins probables est nécessaire
- Procède par **récurrence**

---

## 8.7 Avantages et limites

### Avantages
- Optimal pour une source connue
- Décodage simple via arbre
- Implémentation efficace

### Limites
- Nécessite la connaissance des probabilités
- Peu robuste aux variations de source
- Moins performant que le codage arithmétique pour certaines sources

---

## Synthèse du chapitre

- Le code de Huffman est un algorithme optimal de compression
- Il construit un code préfixe de longueur moyenne minimale
- Il repose sur une fusion récursive des symboles rares
- Il est central en compression sans perte

---

## Liens
- ⏮️ Chapitre précédent : [[07_Theoreme_codage_source]]
- ⏭️ Chapitre suivant : [[09a_Codage_canal_Modelisation]]
