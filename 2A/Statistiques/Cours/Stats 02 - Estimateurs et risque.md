---
tags: [stats, cours, estimation]
---
# 02 — Modèle statistique, estimateurs, risque

Précédent : [[Stats 01 - Rappels de probabilités]] · Suivant : [[Stats 03 - Construire un estimateur (moments, MV)]]

## 1. Le cadre

> [!abstract] Idée en une phrase
> On observe des données aléatoires dont la loi est connue **à un paramètre $\theta$ près**. On veut retrouver $\theta$.

- **Observation** $X$ : v.a. à valeurs dans $\mathcal X$ (ex. $\mathbb R$, $\{0,1\}$).
- **Modèle statistique** : $\mathcal M=\{f_\theta:\theta\in\Theta\}$ — famille de densités (ou fonctions de masse).
  - **Paramétrique** si $\Theta\subset\mathbb R^d$ (dimension finie) ; sinon **non paramétrique** (ex. « toutes les densités »).
- **Identifiable** si $\theta\mapsto f_\theta$ est injective (deux paramètres différents ⇒ deux lois différentes).
  Ex. : $\mathcal N(\theta^2,1)$, $\theta\in\mathbb R$ **non** identifiable ($\pm\theta$ donnent la même loi) ; OK si $\theta\ge0$.
- **$n$-échantillon** : $X_1,\dots,X_n$ **i.i.d.** de loi $f_\theta$.
- **Statistique** : $T=T(X_1,\dots,X_n)$ où la fonction $T$ **ne dépend pas de $\theta$** (on doit pouvoir la calculer avec les données seules). Sa **loi**, elle, dépend de $\theta$ → notations $\mathbb E_\theta$, $\mathbb V_\theta$, $P_\theta$.

> [!example] « Donner le modèle statistique » (question type TD)
> Poisson : $\mathcal M=\{\mathcal P(\theta):\theta>0\}$, $\Theta=\mathbb R_+^*\subset\mathbb R$ ⇒ **paramétrique**.
> Réponse attendue : l'ensemble des observations $\mathcal X=\mathbb N$, la famille de lois, $\Theta$, et « paramétrique car $\Theta\subset\mathbb R^d$ ».

Statistiques classiques :
$$\bar X_n=\frac1n\sum_{k=1}^n X_k,\qquad \hat\sigma_n^2=\frac1n\sum_{k=1}^n(X_k-\bar X_n)^2.$$

## 2. Estimateur
Un **estimateur** de $\theta$ est une statistique à valeurs dans $\Theta$ : $\hat\theta_n=\hat\theta_n(X_1,\dots,X_n)$.
Exemple ($\mathcal N(\theta,\sigma^2)$) : $\bar X_n$, $0$, $X_1$ sont tous des estimateurs ! Il faut des **critères** pour les comparer.

## 3. Perte et risque
- **Fonction de perte** $\ell(\theta,\hat\theta)\ge0$, symétrique, nulle si $\theta=\hat\theta$. Exemples : $L^2$ : $(\theta-\hat\theta)^2$ ; $L^1$ : $|\theta-\hat\theta|$ ; 0-1 : $\mathbf 1_{|\theta-\hat\theta|>\epsilon}$.
- **Risque** = perte moyenne : $R(\hat\theta_n,\theta)=\mathbb E_\theta[\ell(\hat\theta_n,\theta)]$ (c'est une fonction de $\theta$, pas une v.a.).

### Risque quadratique (EQM / MSE) — LE critère du cours
$$R(\hat\theta_n,\theta)=\mathbb E_\theta\big[(\hat\theta_n-\theta)^2\big]$$

> [!important] Décomposition biais–variance (à savoir redémontrer)
> $$R(\hat\theta_n,\theta)=B_\theta[\hat\theta_n]^2+\mathbb V_\theta[\hat\theta_n],\qquad B_\theta[\hat\theta_n]=\mathbb E_\theta[\hat\theta_n]-\theta.$$
> *Preuve* : écrire $\hat\theta_n-\theta=(\hat\theta_n-\mathbb E\hat\theta_n)+(\mathbb E\hat\theta_n-\theta)$, développer le carré ; le double produit a une espérance nulle.

- **Sans biais** : $B_\theta=0$ pour **tout** $\theta$. Alors $R=\mathbb V$.
- Vectoriel ($\Theta\subset\mathbb R^d$) : $R=\mathbb E\|\hat\theta_n-\theta\|^2=\sum_i(B_i^2+\mathbb V_i)=\|B\|^2+\text{tr}(\text{Cov}(\hat\theta_n))$.
- Markov : $P_\theta(|\hat\theta_n-\theta|>\epsilon)\le R(\hat\theta_n,\theta)/\epsilon^2$.

> [!example] Exemples du cours à connaître
> **Variance gaussienne** : $\hat\sigma_n^2=\frac1n\sum(X_k-\bar X_n)^2$ a un biais $-\sigma^2/n$ et $R=\frac{(2n-1)\sigma^4}{n^2}$.
> $\hat s_n^2=\frac n{n-1}\hat\sigma_n^2$ est **sans biais**, $R=\frac{2\sigma^4}{n-1}$.
> → Remarque : $\frac{2n-1}{n^2}<\frac2{n-1}$ : l'estimateur biaisé a un **risque plus petit** ! Sans biais ≠ meilleur.
>
> **Bernoulli** : $\hat\theta^{(1)}=\bar X_n$ : $R=\theta(1-\theta)/n$ ; $\hat\theta^{(2)}=\frac{n\bar X_n+\sqrt n/2}{n+\sqrt n}$ : $R=\frac1{4(1+\sqrt n)^2}$ (constant !) ; $\hat\theta^{(3)}=1/2$ : $R=(\theta-1/2)^2$.
> **Aucun n'est meilleur que les autres pour tout $\theta$** → on ne peut pas toujours classer des estimateurs.

## 4. Performances asymptotiques ($n\to\infty$)

### Consistance
$\hat\theta_n$ **consistant** si $\forall\theta$, $\hat\theta_n\xrightarrow{P}\theta$.

> [!tip] Méthodes pour prouver la consistance
> 1. **LGN** + continuité : si $\hat\theta_n=g(\bar X_n)$ avec $g$ continue et $\bar X_n\to\mathbb E X$, alors $\hat\theta_n\to g(\mathbb EX)$.
> 2. **Risque → 0** : si $R(\hat\theta_n,\theta)\to0$ alors Markov ⇒ consistant. (Le plus rapide quand on a déjà calculé le risque.)

Contre-exemple du cours : $\sqrt{\frac1n\sum(X_k^2-\sigma^2)}$ pour $\mathcal N(\theta,\sigma^2)$ tend vers $\sqrt{\theta^2}=|\theta|$ → consistant seulement si $\theta>0$.

### Normalité asymptotique
$\hat\theta_n$ **asymptotiquement normal** si $\sqrt n(\hat\theta_n-\theta)\xrightarrow{\mathcal L}\mathcal N(0,\sigma^2(\theta))$.
$\sigma^2(\theta)$ = **variance asymptotique** (plus petite = meilleur).
Outils : **TLC** (si $\hat\theta_n=\bar X_n$) puis **delta-méthode** (si $\hat\theta_n=\varphi(\bar X_n)$).

---
## Exos de base

**E1.** $X_i$ i.i.d. $\mathcal N(\theta,\sigma^2)$. Biais et risque de $\bar X_n$, de $X_1$, de $0$.
> [!success]- Solution
> $\bar X_n$ : biais 0, $R=\sigma^2/n$. $X_1$ : biais 0, $R=\sigma^2$ (ne décroît pas → non consistant). $0$ : biais $-\theta$, variance 0, $R=\theta^2$ (excellent si $\theta\approx0$, nul sinon).

**E2.** Démontrer la décomposition biais–variance.
> [!success]- Solution
> $m=\mathbb E\hat\theta$. $(\hat\theta-\theta)^2=(\hat\theta-m)^2+2(\hat\theta-m)(m-\theta)+(m-\theta)^2$. Espérance : $\mathbb V[\hat\theta]+2(m-\theta)\underbrace{\mathbb E[\hat\theta-m]}_{0}+B^2$.

**E3.** $X_i$ i.i.d. $\mathcal U([0,\theta])$, $\hat\theta_n=2\bar X_n$. Biais, risque, consistance, loi asymptotique.
> [!success]- Solution
> $\mathbb E=2\cdot\theta/2=\theta$ : sans biais. $R=\mathbb V=4\cdot\frac{\theta^2}{12n}=\frac{\theta^2}{3n}\to0$ ⇒ consistant. TLC : $\sqrt n(\hat\theta_n-\theta)=2\sqrt n(\bar X_n-\theta/2)\to\mathcal N(0,4\cdot\theta^2/12)=\mathcal N(0,\theta^2/3)$.

**E4.** $\hat\theta_n$ avec $\mathbb E[\hat\theta_n]=\frac{n}{n+1}\theta$, $\mathbb V=\frac{\theta^2}{n^2}$. Risque ? Consistant ? Proposer un estimateur sans biais.
> [!success]- Solution
> $B=-\frac\theta{n+1}$, $R=\frac{\theta^2}{(n+1)^2}+\frac{\theta^2}{n^2}\to0$ ⇒ consistant. Sans biais : $\frac{n+1}n\hat\theta_n$.

**E5.** Montrer que $\hat\sigma_n^2=\frac1n\sum(X_k-\bar X_n)^2$ a pour espérance $\frac{n-1}n\sigma^2$ (loi quelconque de variance $\sigma^2$).
> [!success]- Solution
> $\sum(X_k-\bar X_n)^2=\sum(X_k-\mu)^2-n(\bar X_n-\mu)^2$. Espérance : $n\sigma^2-n\cdot\frac{\sigma^2}n=(n-1)\sigma^2$. Diviser par $n$.
