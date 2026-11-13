---
tags: [stats, quiz, estimation]
---
# Quiz 1 — Estimation (≈ 30 min)

Chapitres : [[Stats 02 - Estimateurs et risque]] → [[Stats 05 - Estimation bayésienne]] · Retour : [[00 - Stats Sommaire]]

> [!info] Règles
> Papier + crayon, sans notes. Note-toi sur 20 (1 pt par question). **≥ 16** → passe au [[Stats TD1 - Estimation (corrigé)|TD1]]. Sinon relis la section indiquée dans la correction.

## Partie A — Cours (vrai/faux, justifier en une ligne)
1. Une statistique peut dépendre de $\theta$ si elle est sans biais.
2. Un estimateur sans biais a toujours un risque quadratique plus petit qu'un estimateur biaisé.
3. Si $R(\hat\theta_n,\theta)\to0$ pour tout $\theta$, alors $\hat\theta_n$ est consistant.
4. Le modèle $\{\mathcal N(\theta^2,1):\theta\in\mathbb R\}$ est identifiable.
5. L'estimateur MV existe toujours.
6. L'estimateur de Bayes pour la perte quadratique est le mode a posteriori.
7. Avec un a priori uniforme sur un compact, MAP = MV.

## Partie B — Calculs rapides
8. Donner la décomposition biais-variance de l'EQM.
9. $X_i$ i.i.d. $\mathcal B(\theta)$. EQM de $\bar X_n$ ?
10. MV de $\theta$ pour $\mathcal E(\theta)$ ?
11. MV de $\theta$ pour $\mathcal U([0,\theta])$ ? Est-il sans biais ?
12. Loi limite de $\sqrt n(\bar X_n-\theta)$ pour $\mathcal P(\theta)$ ?
13. Delta-méthode : loi limite de $\sqrt n(\bar X_n^2-\mu^2)$ si $\sqrt n(\bar X_n-\mu)\to\mathcal N(0,\sigma^2)$, $\mu\neq0$ ?
14. IC exact à 95 % pour $\mu$, $\mathcal N(\mu,\sigma^2)$, $\sigma$ connu ?
15. Même chose si $\sigma$ inconnu.
16. $X_k|\theta\sim\mathcal B(\theta)$, $\theta\sim\text{Beta}(2,2)$, $n=10$, $S=7$. Estimateur MMSE ?
17. Pourquoi le risque bayésien permet-il toujours de comparer deux estimateurs ?

## Partie C — Mini-problème
$X_1,\dots,X_n$ i.i.d. de densité $f_\theta(x)=\theta x^{-\theta-1}\mathbf 1_{x\ge1}$, $\theta>0$ (loi de Pareto).
18. Calculer l'estimateur MV $\hat\theta_n$.
19. Loi de $\ln X_1$ ? En déduire la loi de $\sum\ln X_k$.
20. Biais de $\hat\theta_n$ ? Proposer un estimateur sans biais.

---
> [!success]- Correction
> 1. **Faux** — une statistique ne dépend jamais de $\theta$ (chap. 02 §1).
> 2. **Faux** — ex. $\hat\sigma_n^2$ (biaisé) a un EQM $<$ celui de $s_n^2$.
> 3. **Vrai** — Markov : $P(|\hat\theta-\theta|>\epsilon)\le R/\epsilon^2$.
> 4. **Faux** — $\theta$ et $-\theta$ donnent la même loi.
> 5. **Faux** — ex. densité non bornée du cours ; et unicité non plus (ex. $\mathcal U[\theta,\theta+1]$).
> 6. **Faux** — c'est la **moyenne** a posteriori ; le mode correspond à la perte 0-1.
> 7. **Vrai** — posterior ∝ vraisemblance.
> 8. $R=B^2+\mathbb V$, $B=\mathbb E\hat\theta-\theta$.
> 9. $\theta(1-\theta)/n$.
> 10. $1/\bar X_n$.
> 11. $\max X_k$ ; non, $\mathbb E=\frac n{n+1}\theta$.
> 12. $\mathcal N(0,\theta)$.
> 13. $\varphi(x)=x^2$, $\varphi'(\mu)=2\mu$ ⇒ $\mathcal N(0,4\mu^2\sigma^2)$.
> 14. $\bar X_n\pm1{,}96\,\sigma/\sqrt n$.
> 15. $\bar X_n\pm t_{n-1;0,975}\,s_n/\sqrt n$.
> 16. Posterior Beta$(9,5)$ ⇒ $9/14\approx0{,}643$.
> 17. C'est un **nombre** (moyenne du risque sur $\theta$), pas une fonction de $\theta$.
> 18. $\ell_n=n\ln\theta-(\theta+1)\sum\ln X_k$ ; $\ell'=\frac n\theta-\sum\ln X_k=0$ ⇒ $\hat\theta_n=\frac n{\sum\ln X_k}$ ; $\ell''=-n/\theta^2<0$.
> 19. $P(\ln X>y)=P(X>e^y)=e^{-\theta y}$ ⇒ $\ln X\sim\mathcal E(\theta)$ ; $T=\sum\ln X_k\sim\Gamma(n,\theta)$.
> 20. $\mathbb E[n/T]=\frac{n\theta}{n-1}$ ⇒ biais $\frac\theta{n-1}$ ; $\frac{n-1}{\sum\ln X_k}$ est sans biais.
