---
tags: [stats, cours, estimation]
---
# 03 — Construire un estimateur : moments et maximum de vraisemblance

Précédent : [[Stats 02 - Estimateurs et risque]] · Suivant : [[Stats 04 - Intervalles de confiance]]

## 1. Méthode des moments
> [!abstract] Principe
> On écrit un moment théorique comme fonction de $\theta$ : $\mathbb E_\theta[\varphi(X)]=g(\theta)$. On remplace l'espérance par la moyenne empirique (LGN) et on inverse :
> $$\hat\theta_n=g^{-1}\Big(\frac1n\sum_{k=1}^n\varphi(X_k)\Big).$$
> Consistant si $g^{-1}$ continue (LGN + continuité). Asymptotiquement normal par TLC + delta-méthode.

Exemples : $\mathcal E(\theta)$ : $\mathbb E X=1/\theta$ ⇒ $\hat\theta_n=1/\bar X_n$, $\sqrt n(\hat\theta_n-\theta)\to\mathcal N(0,\theta^2)$.
$\mathcal U([0,\theta])$ : $\mathbb EX=\theta/2$ ⇒ $\hat\theta_n=2\bar X_n$, variance asymptotique $\theta^2/3$.

## 2. Maximum de vraisemblance (MV)
**Vraisemblance** : $L_n(\theta)=\prod_{k=1}^n f_\theta(X_k)$ (fonction de $\theta$, aléatoire car évaluée en les $X_k$).
**Estimateur MV** : $\hat\theta_n\in\arg\max_{\theta\in\Theta}L_n(\theta)$.
Pas toujours existence ni unicité. Pour une large classe de modèles : consistant et asymptotiquement normal.

> [!important] Recette MV (à appliquer mécaniquement)
> 1. Écrire $L_n(\theta)=\prod f_\theta(X_k)$ **avec les indicatrices** si le support dépend de $\theta$.
> 2. Passer au log : $\ell_n(\theta)=\sum\ln f_\theta(X_k)$ (même argmax car $\ln$ croissant).
> 3. Dériver : $\ell_n'(\theta)=0$ → candidat $\hat\theta$.
> 4. **Justifier que c'est un max global** : $\ell_n''<0$ (concavité stricte) **ou** tableau de variation ($\ell_n'>0$ avant, $<0$ après). C'est ça qui donne l'**unicité**.
> 5. Vérifier que $\hat\theta\in\Theta$ (cas limites : ex. $\sum X_k=0$).
>
> ⚠️ Si le support dépend de $\theta$ (uniforme...) : **on ne dérive pas**, on étudie la fonction directement.

### Exemples à savoir refaire
**Bernoulli / Poisson / Exponentielle** :

| Modèle | $\ell_n(\theta)$ (à constante près) | MV |
|---|---|---|
| $\mathcal B(\theta)$ | $S\ln\theta+(n-S)\ln(1-\theta)$ | $\bar X_n$ |
| $\mathcal P(\theta)$ | $S\ln\theta-n\theta$ | $\bar X_n$ |
| $\mathcal E(\theta)$ | $n\ln\theta-\theta S$ | $1/\bar X_n$ |
| $\mathcal N(\mu,\sigma^2)$ | $-\frac n2\ln\sigma^2-\frac1{2\sigma^2}\sum(X_k-\mu)^2$ | $\bar X_n$, $\hat\sigma_n^2=\frac1n\sum(X_k-\bar X_n)^2$ |

(avec $S=\sum X_k$)

**Uniforme $\mathcal U([0,\theta])$** — le piège classique :
$$L_n(\theta)=\prod\frac1\theta\mathbf 1_{0\le X_k\le\theta}=\theta^{-n}\,\mathbf 1_{\theta\ge\max_k X_k}.$$
Nulle pour $\theta<\max X_k$, puis décroissante ⇒ $\boxed{\hat\theta_n=\max(X_1,\dots,X_n)=X_{(n)}}$.
Loi : $P(X_{(n)}\le x)=(x/\theta)^n$ ⇒ densité $n x^{n-1}/\theta^n$ ⇒ $\mathbb E=\frac n{n+1}\theta$, biais $-\frac\theta{n+1}$, $R=\frac{2\theta^2}{(n+1)(n+2)}$.
→ risque en $1/n^2$ : **bien meilleur** que $2\bar X_n$ (en $1/n$).

**Non-existence** : si $L_n(\theta)\to+\infty$ quand $\theta\to X_\ell$ (densité non bornée), le MV n'existe pas.

> [!tip] Gaussienne à deux paramètres
> Dériver en $\mu$ : $\sum(X_k-\mu)=0$ ⇒ $\hat\mu=\bar X_n$. Dériver en $v=\sigma^2$ (pas en $\sigma$, plus simple) : $-\frac n{2v}+\frac1{2v^2}\sum(X_k-\mu)^2=0$ ⇒ $\hat v=\frac1n\sum(X_k-\bar X_n)^2$.
> Valeur du max : $L_n=(2\pi\hat\sigma^2)^{-n/2}e^{-n/2}$ — **utile pour les tests** (TD3).

---
## Exos de base

**E1.** MV pour la loi géométrique $P(X=k)=\theta(1-\theta)^{k-1}$, $k\ge1$.
> [!success]- Solution
> $\ell_n=n\ln\theta+(S-n)\ln(1-\theta)$. $\ell_n'=\frac n\theta-\frac{S-n}{1-\theta}=0\Rightarrow\hat\theta=n/S=1/\bar X_n$. $\ell''<0$ ⇒ max unique.

**E2.** Poisson : MV, biais, risque. Que se passe-t-il si tous les $X_k=0$ ?
> [!success]- Solution
> $\hat\theta=\bar X_n$, sans biais, $R=\theta/n$. Si $S=0$, $\ell_n=-n\theta$ décroissante : le sup est en $\theta\to0$. Si $\Theta=\mathbb R_+$ on prend $\hat\theta=0=\bar X_n$ ; si $\Theta=\mathbb R_+^*$ le max n'est pas atteint (événement de probabilité $e^{-n\theta}\to0$). À **mentionner** dans une copie.

**E3.** Densité $f_\theta(x)=\theta x^{\theta-1}$ sur $[0,1]$, $\theta>0$. MV ?
> [!success]- Solution
> $\ell_n=n\ln\theta+(\theta-1)\sum\ln X_k$. $\ell_n'=\frac n\theta+\sum\ln X_k=0\Rightarrow\hat\theta=-\dfrac n{\sum\ln X_k}$ (positif car $\ln X_k<0$). $\ell''=-n/\theta^2<0$.

**E4.** $\mathcal U([\theta,\theta+1])$ : le MV est-il unique ?
> [!success]- Solution
> $L_n=\mathbf 1_{\theta\le X_{(1)}}\mathbf 1_{\theta\ge X_{(n)}-1}$ : vaut 1 sur tout $[X_{(n)}-1,X_{(1)}]$. **Infinité** de MV.

**E5.** Méthode des moments pour $\mathcal N(\mu,\sigma^2)$ avec $\varphi(x)=(x,x^2)$.
> [!success]- Solution
> $\mathbb E X=\mu$, $\mathbb E X^2=\mu^2+\sigma^2$. Donc $\hat\mu=\bar X_n$, $\hat\sigma^2=\frac1n\sum X_k^2-\bar X_n^2=\hat\sigma_n^2$ (même chose que le MV).
