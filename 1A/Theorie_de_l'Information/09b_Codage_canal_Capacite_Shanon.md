# Chapitre 9b — Capacité du canal et théorème de Shannon

## Introduction

La partie précédente a montré que le codage canal permet de réduire
la probabilité d’erreur, au prix d’une baisse du rendement.

Une question fondamentale apparaît alors :

> **Existe-t-il une limite théorique au débit fiable de transmission ?**

La réponse est donnée par la notion de **capacité du canal**
et le **théorème fondamental du codage canal de Shannon**.

---

## 9.5 Information mutuelle et canal

Dans un contexte de communication :
- $X$ : symbole transmis
- $Y$ : symbole reçu

L’**information mutuelle** $I(X;Y)$ mesure la quantité d’information
effectivement transmise.

---

## 9.6 Capacité d’un canal

### Définition

La **capacité** d’un canal discret est définie par :

$$
C
=
\sup_{p_X}
I(X;Y)
$$

où le supremum est pris sur toutes les lois possibles de $X$.

---

### Interprétation

- $C$ est le **débit maximal théorique** atteignable
- Elle dépend uniquement du **canal**, pas du code utilisé

➡️ Aucun système ne peut transmettre de manière fiable
au-delà de la capacité.

---

## 9.7 Théorème du codage canal de Shannon

### Énoncé fondamental

Soit un canal de capacité $C$.

1. **Atteignabilité**

Pour tout débit :

$$
R < C
$$

il existe une suite de codes telle que :

$$
P_e \longrightarrow 0
\quad \text{quand } n \to \infty
$$

---

2. **Impossibilité**

Pour tout débit :

$$
R > C
$$

la probabilité d’erreur ne peut pas tendre vers zéro :

$$
P_e \nrightarrow 0
$$

---

## 9.8 Sens et portée du théorème

- Le résultat est **asymptotique**
- Il garantit l’existence de codes performants
- Il ne donne pas leur construction explicite

➡️ Le théorème trace une **frontière absolue**
entre transmission possible et impossible.

---

## 9.9 Au-delà du théorème

Dans la pratique, on étudie :
- les **codes correcteurs d’erreurs** explicites,
- les codes linéaires,
- les codes LDPC, Turbo, etc.

Ces codes cherchent à **s’approcher de la capacité**
avec une complexité raisonnable.

---

## Synthèse de la partie 2

- La capacité est une limite fondamentale
- En dessous de $C$, la transmission fiable est possible
- Au-dessus de $C$, elle est impossible
- Le théorème de Shannon est central en télécommunications

---

## Liens
- ⏮️ Partie précédente : [[09a_Codage_canal_Modelisation]]
- ⏭️ Chapitre suivant : [[Theorie_de_l'Information/10_Synthese_glossaire]]
