# Chapitre 1 — Le paradigme de Shannon

## Introduction
Le paradigme de Shannon constitue le **socle conceptuel** de toute la théorie de l’information.  
Il formalise le processus de communication comme une **chaîne probabiliste** soumise au bruit.

---

## 1.1 Le schéma fondamental de communication

Le problème fondamental de la communication est :
> *Reproduire, en un point, exactement ou approximativement, un message sélectionné en un autre point.*

### Chaîne de communication
Voir schéma : **Chaîne de Shannon**

- **Source** : génère l’information  
- **Canal** : support de transmission (bruité)  
- **Récepteur** : reconstruit le message  

---

## 1.2 La source d’information

### Modélisation
La source est modélisée par une **variable aléatoire discrète** :

$$
X \sim p_X
$$

Elle peut représenter :
- un texte,
- une image,
- un signal audio,
- une suite de bits.

### Information = incertitude
Plus un événement est improbable, plus il est **informatif**.

L’**incertitude moyenne** délivrée par la source est mesurée par l’**entropie** :

$$
H(X) = - \sum_{x} \mathbb{P}(X=x)\,\log\big(\mathbb{P}(X=x)\big)
$$

---

## 1.3 Exemples d’entropie

### Pile ou face biaisé

$$
\mathbb{P}(X=\text{pile}) = p,
\quad
\mathbb{P}(X=\text{face}) = 1-p
$$

- Entropie maximale pour $p = \frac{1}{2}$
- Entropie nulle si l’issue est certaine

Voir schéma : **Entropie binaire**

---

### Lancer de deux dés
La variable $X$ représente la somme obtenue.

$$
H(X) \approx 3.27 \ \text{bits}
$$

➡️ Bien que deux dés nécessitent 6 bits pour être décrits naïvement, l’entropie réelle est plus faible.

---

## 1.4 Le canal de transmission

### Modélisation probabiliste
Le canal est caractérisé par les probabilités conditionnelles :

$$
\mathbb{P}(Y=y \mid X=x)
$$

où :
- $X$ est le message émis,
- $Y$ est le message reçu.

### Information mutuelle
L’**information mutuelle** mesure la quantité d’information conservée malgré le bruit :

$$
I(X;Y) =
\sum_{x,y}
\mathbb{P}(x,y)\,
\log\!\left(
\frac{\mathbb{P}(x,y)}
{\mathbb{P}(x)\mathbb{P}(y)}
\right)
$$

➡️ Elle représente l’**incertitude supprimée sur $X$** lorsque $Y$ est connu.

---

## 1.5 Le récepteur et la fiabilité

Le récepteur produit une estimation $\hat{X}$.

La fiabilité est mesurée par la **probabilité d’erreur** :

$$
P_e = \mathbb{P}(\hat{X} \neq X)
$$

---

## 1.6 Deux grandes problématiques

### Codage source
- Objectif : **réduire la quantité de données**
- Compression sans perte
- Exemples : ASCII, Morse, Braille

### Codage canal
- Objectif : **corriger les erreurs**
- Ajout de redondance
- Codes correcteurs d’erreurs

---

## Liens
- ⏮️ Chapitre précédent : [[00_Introduction]]
- ⏭️ Chapitre suivant : [[02_Mesure_de_l_information_Entropie]]
