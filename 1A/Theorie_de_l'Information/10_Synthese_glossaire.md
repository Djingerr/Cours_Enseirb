# Chapitre 10 — Synthèse générale et glossaire

## Introduction

Ce chapitre final a pour objectif de :
- **relier l’ensemble des concepts** vus dans le cours,
- proposer une **vision globale cohérente** de la théorie de l’information,
- rappeler les **résultats fondamentaux à retenir**,
- lister les **erreurs classiques**,
- fournir un **glossaire de référence**.

Il constitue une **fiche de révision complète**.

---

## 10.1 Vision d’ensemble du cours

La théorie de l’information étudie la **production**, la **représentation**
et la **transmission** de l’information à l’aide d’outils probabilistes.

Elle repose sur trois piliers fondamentaux :

1. **Mesure de l’information**
2. **Codage source (compression)**
3. **Codage canal (transmission fiable)**

---

## 10.2 Mesure de l’information

### Concepts clés

- **Quantité d’information** d’un événement :

$$
h(p) = -\log(p)
$$

- **Entropie** d’une source discrète :

$$
H(X) = -\sum_x p_X(x)\log p_X(x)
$$

- **Entropie maximale** :
  - loi uniforme (discret),
  - loi gaussienne (continu, variance fixée).

---

### Relations fondamentales

- Entropie jointe :

$$
H(X,Y)
$$

- Entropie conditionnelle :

$$
H(X \mid Y)
$$

- Relation clé :

$$
H(X,Y) = H(Y) + H(X \mid Y)
$$

---

## 10.3 Dépendance statistique et information mutuelle

### Divergence de Kullback–Leibler

- Mesure l’écart entre deux distributions :

$$
D(p \| q) \ge 0
$$

- Nulle si et seulement si $p=q$.

---

### Information mutuelle

- Définition :

$$
I(X;Y) = H(X) - H(X \mid Y)
$$

- Expression équivalente :

$$
I(X;Y)
=
D\big(p_{X,Y} \| p_X \otimes p_Y\big)
$$

➡️ Elle mesure la **dépendance statistique** entre deux variables.

---

## 10.4 Codage source : compression sans perte

### Objectif

- Représenter une source avec le **moins de bits possible en moyenne**
- Sans perdre d’information

---

### Résultats fondamentaux

- **Longueur moyenne** :

$$
L(\varphi) = \sum_x p_X(x)\,\ell(\varphi(x))
$$

- **Théorème de Shannon (codage source)** :

$$
L(\varphi) \ge \frac{H(X)}{\log d}
$$

- Existence de codes tels que :

$$
\frac{H(X)}{\log d}
\le
L(\varphi)
\le
\frac{H(X)}{\log d} + 1
$$

---

### Code de Huffman

- Code préfixe optimal
- Longueur moyenne minimale
- Construction algorithmique explicite

---

## 10.5 Codage canal : transmission fiable

### Problématique

- Le canal introduit des **erreurs**
- Le codage canal ajoute de la **redondance**

---

### Notions clés

- Rendement :

$$
R = \frac{k}{n}
$$

- Probabilité d’erreur :

$$
P_e = \mathbb{P}(\hat{M} \neq M)
$$

---

### Capacité du canal

- Définition :

$$
C = \sup_{p_X} I(X;Y)
$$

- **Théorème du codage canal de Shannon** :
  - si $R < C$ : transmission fiable possible,
  - si $R > C$ : transmission fiable impossible.

---

## 10.6 Erreurs et confusions classiques

- ❌ Confondre entropie et information mutuelle
- ❌ Croire que l’entropie différentielle est toujours positive
- ❌ Penser que la divergence KL est une distance
- ❌ Croire que le théorème de Shannon fournit un code explicite
- ❌ Oublier le compromis rendement / fiabilité en codage canal

---

## 10.7 Glossaire

**Entropie**  
— Mesure de l’incertitude moyenne d’une variable aléatoire.

**Information mutuelle**  
— Quantité d’information partagée entre deux variables aléatoires.

**Divergence de Kullback–Leibler**  
— Mesure de dissimilarité entre deux distributions de probabilité.

**Code préfixe**  
— Code dans lequel aucun mot n’est le préfixe d’un autre.

**Longueur moyenne**  
— Espérance de la longueur des mots de code.

**Capacité du canal**  
— Débit maximal permettant une transmission fiable.

**Codage source**  
— Compression sans perte de l’information.

**Codage canal**  
— Ajout de redondance pour corriger les erreurs.

---

## 10.8 Conclusion générale

La théorie de l’information fournit :
- des **limites fondamentales universelles**,
- des **outils concrets de compression et de transmission**,
- un langage commun à de nombreux domaines scientifiques.

Elle montre que :
> **l’information n’est pas une notion vague, mais une grandeur mesurable,
soumise à des lois mathématiques précises.**

---

## Liens
- ⏮️ Chapitre précédent : [[09b_Codage_canal_Capacite_Shanon]]
