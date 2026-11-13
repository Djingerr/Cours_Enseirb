---
tags: [stats, td, tests]
---
# TD3 — Tests d'hypothèses (méthodes + corrigés)

Prérequis : [[Stats 07 - Tests d'hypothèses]] (recette RV), [[Stats TD2 - Régression linéaire (corrigé)]] ex 3
Retour : [[00 - Stats Sommaire]]

Notation : $q_\alpha=\Phi^{-1}(1-\alpha)$, $S=\sum_kX_k$.

---
## Exercice 1 (★) — Proportion, $H_0:\theta=\theta_0$ vs $H_1:\theta=\theta_1$ ($\theta_0<\theta_1$)

**1. RV et forme du test.**
> [!success]- Corrigé
> $$R_n=\frac{\theta_1^S(1-\theta_1)^{n-S}}{\theta_0^S(1-\theta_0)^{n-S}},\qquad\ln R_n=S\underbrace{\ln\frac{\theta_1(1-\theta_0)}{\theta_0(1-\theta_1)}}_{>0\text{ car }\theta_1>\theta_0}+n\ln\frac{1-\theta_1}{1-\theta_0}.$$
> Fonction strictement croissante de $S$ ⇒ $R_n>\epsilon\iff S>\epsilon'$ : $T_n=\mathbf 1_{]\epsilon,\infty[}(S)$.
> Seuil : sous $H_0$, $S\sim\text{Bin}(n,\theta_0)$. $\epsilon_n(\alpha,\theta_0)$ = plus petit $\epsilon$ tel que $P(\text{Bin}(n,\theta_0)>\epsilon)\le\alpha$. (Loi discrète : niveau exactement $\alpha$ pas toujours atteignable.)

**2. Seuil asymptotique et risque de 2nde espèce.**
> [!success]- Corrigé
> TLC sous $H_0$ : $\frac{S-n\theta_0}{\sqrt{n\theta_0(1-\theta_0)}}\to\mathcal N(0,1)$ ⇒
> $$\epsilon_n=n\theta_0+q_\alpha\sqrt{n\theta_0(1-\theta_0)}\quad\Rightarrow\quad P_{\theta_0}(S>\epsilon_n)\to\alpha.$$
> Sous $H_1$, avec $s_j=\sqrt{\theta_j(1-\theta_j)}$ :
> $$\beta_n=P_{\theta_1}(S\le\epsilon_n)=P\Big(\frac{S-n\theta_1}{\sqrt n s_1}\le\frac{\sqrt n(\theta_0-\theta_1)+q_\alpha s_0}{s_1}\Big).$$
> - **$\theta_1$ fixe** : le membre de droite $\to-\infty$ ⇒ $\beta_n\to0$ (puissance → 1, test **consistant**).
> - **$\theta_1=\theta_0+\Delta/\sqrt n$** : $\sqrt n(\theta_0-\theta_1)=-\Delta$, $s_1\to s_0$ ⇒ $\boxed{\beta_n\to\Phi\Big(q_\alpha-\frac{\Delta}{\sqrt{\theta_0(1-\theta_0)}}\Big)}\in]0,1-\alpha[$.
> **Commentaire** : un écart d'ordre $1/\sqrt n$ n'est détecté qu'avec une puissance limitée ; c'est la plus petite échelle détectable. Plus $\Delta$ grand, plus $\beta$ petit.

---
## Exercice 2 (★) — Exponentielle, $\theta_0<\theta_1$

**1. RV et test.**
> [!success]- Corrigé
> $R_n=\frac{\theta_1^ne^{-\theta_1S}}{\theta_0^ne^{-\theta_0S}}=\Big(\frac{\theta_1}{\theta_0}\Big)^ne^{-(\theta_1-\theta_0)S}$ : **décroissant** en $S$ ⇒ on rejette si $S$ **petit** : $T_n=\mathbf 1(S<\epsilon)$ (soit $\mathbf 1_{]-\epsilon,\infty[}(-S)$).
> Seuil exact : sous $H_0$, $2\theta_0S\sim\chi^2(2n)$ ⇒ $\epsilon=\frac{F^{-1}_{\chi^2(2n)}(\alpha)}{2\theta_0}$.
> *Intuition : $\theta$ grand ⇔ moyenne $1/\theta$ petite ⇔ observations petites.*

**2. Asymptotique.**
> [!success]- Corrigé
> Sous $H_0$ : $\mathbb EX=1/\theta_0$, $\mathbb VX=1/\theta_0^2$. Rejet si $\bar X_n<\epsilon_n$ avec
> $$\epsilon_n=\frac1{\theta_0}\Big(1-\frac{q_\alpha}{\sqrt n}\Big)\ \Rightarrow\ P_{\theta_0}(\bar X_n<\epsilon_n)=P\big(\sqrt n(\theta_0\bar X_n-1)<-q_\alpha\big)\to\alpha.$$
> Sous $H_1$ :
> $$\beta_n=P_{\theta_1}(\bar X_n\ge\epsilon_n)=P\Big(\sqrt n(\theta_1\bar X_n-1)\ge\sqrt n\Big(\frac{\theta_1}{\theta_0}-1\Big)-\frac{\theta_1}{\theta_0}q_\alpha\Big).$$
> - $\theta_1$ fixe : droite $\to+\infty$ ⇒ $\beta_n\to0$.
> - $\theta_1=\theta_0+\Delta/\sqrt n$ : $\sqrt n(\frac{\theta_1}{\theta_0}-1)=\frac\Delta{\theta_0}$, $\frac{\theta_1}{\theta_0}\to1$ ⇒ $\boxed{\beta_n\to1-\Phi\Big(\frac\Delta{\theta_0}-q_\alpha\Big)=\Phi\Big(q_\alpha-\frac\Delta{\theta_0}\Big)}$.
> Même commentaire qu'à l'ex 1.

---
## Exercice 3 (★★) — Bilatère gaussien, $\mu,\sigma^2$ inconnues

**1. RV.**
> [!hint]- Indice
> Deux sup à calculer = deux MV gaussiens : sur $(\mu,\sigma^2)$ libre (H1) et sur $\sigma^2$ seul avec $\mu=\mu_0$ (H0). Valeur au max : $(2\pi\hat v)^{-n/2}e^{-n/2}$.

> [!success]- Corrigé
> - Sous $H_1$ (sup sur $\mu\ne\mu_0$ = sup sur $\mathbb R$ p.s.) : $\hat\mu=\bar X_n$, $\hat\sigma_1^2=\frac1n\sum(X_k-\bar X_n)^2$, sup $=(2\pi\hat\sigma_1^2)^{-n/2}e^{-n/2}$.
> - Sous $H_0$ : $\hat\sigma_0^2=\frac1n\sum(X_k-\mu_0)^2=\hat\sigma_1^2+(\bar X_n-\mu_0)^2$ (Huygens), sup $=(2\pi\hat\sigma_0^2)^{-n/2}e^{-n/2}$.
> $$R_n=\Big(\frac{\hat\sigma_0^2}{\hat\sigma_1^2}\Big)^{n/2}=\Bigg(1+\frac{(\bar X_n-\mu_0)^2}{\frac1n\sum_k(X_k-\bar X_n)^2}\Bigg)^{n/2}.$$

**2. Loi de $S_n$ sous $H_0$.**
> [!success]- Corrigé
> $S_n=\sqrt{n(n-1)}\frac{\bar X_n-\mu_0}{\sqrt{\sum(X_k-\bar X_n)^2}}=\sqrt n\frac{\bar X_n-\mu_0}{s_n}$ avec $s_n^2=\frac1{n-1}\sum(X_k-\bar X_n)^2$.
> C'est TD2 ex 3 avec $p=0$, $X=\mathbf1$ : $\hat\beta_0=\bar X_n$, $\hat\sigma^2=s_n^2$, $c_0=1/n$ ⇒ $\boxed{S_n\sim t(n-1)}$ sous $H_0$.

**3. Seuil.**
> [!success]- Corrigé
> $R_n=\big(1+\frac{S_n^2}{n-1}\big)^{n/2}$ est fonction croissante de $|S_n|$ ⇒ le test RV est $T_n=\mathbf 1_{]\epsilon,\infty[}(|S_n|)$ (**valeur absolue** : test bilatère — l'énoncé écrit $S_n$, à corriger/signaler).
> $P_{H_0}(|S_n|>\epsilon)=\alpha\iff\boxed{\epsilon=t_{n-1,1-\alpha/2}}$ (quantile de Student). C'est le **test de Student**.

---
## Exercice 4 (★★) — Unilatère gaussien, $\sigma^2$ connue, $H_0:\mu\le\mu_0$ vs $\mu>\mu_0$

**1. $R_n=f(\bar X_n)$.**
> [!hint]- Indice
> $\ell_n(\mu)=c-\frac n{2\sigma^2}(\bar X_n-\mu)^2$ (développer). Maximiser une parabole sur une demi-droite : distinguer $\bar X_n>\mu_0$ et $\bar X_n\le\mu_0$.

> [!success]- Corrigé
> $\sum(X_k-\mu)^2=\sum(X_k-\bar X_n)^2+n(\bar X_n-\mu)^2$, donc $\ell_n(\mu)=c-\frac n{2\sigma^2}(\bar X_n-\mu)^2$.
> - Si $\bar X_n>\mu_0$ : sup sur $\mu>\mu_0$ en $\bar X_n$ (vaut $c$), sup sur $\mu\le\mu_0$ en $\mu_0$ ⇒ $\ln R_n=\frac n{2\sigma^2}(\bar X_n-\mu_0)^2$.
> - Si $\bar X_n\le\mu_0$ : inversement ⇒ $\ln R_n=-\frac n{2\sigma^2}(\bar X_n-\mu_0)^2$.
> $$R_n=f(\bar X_n),\qquad f(x)=\exp\Big(\frac n{2\sigma^2}(x-\mu_0)|x-\mu_0|\Big),$$
> strictement croissante ($x\mapsto(x-\mu_0)|x-\mu_0|$ l'est).

**2. Test et puissance.**
> [!success]- Corrigé
> $T_n=\mathbf 1(\bar X_n>\epsilon)$. $P_\mu(\bar X_n>\epsilon)=1-\Phi\big(\frac{\sqrt n(\epsilon-\mu)}\sigma\big)$ croissante en $\mu$ ⇒ niveau $=\sup_{\mu\le\mu_0}=$ valeur en $\mu_0$ :
> $$\epsilon=\mu_0+\frac\sigma{\sqrt n}q_\alpha.$$
> Fonction puissance ($\mu>\mu_0$) : $\boxed{\gamma(\mu)=1-\Phi\Big(q_\alpha-\frac{\sqrt n(\mu-\mu_0)}\sigma\Big)}$ — croissante en $\mu$, vaut $\alpha$ en $\mu_0$, → 1 quand $\mu\to\infty$ ou $n\to\infty$.

---
## Exercice 5 (★★) — Unilatère proportion, $H_0:\theta\le\theta_0$ vs $\theta>\theta_0$

**1. $R_n=f(\bar X_n)$.**
> [!success]- Corrigé
> $\ell_n(\theta)=n\big[\bar X_n\ln\theta+(1-\bar X_n)\ln(1-\theta)\big]$, concave, max en $\bar X_n$. Même raisonnement qu'à l'ex 4 :
> $$\ln R_n=n\,\text{sgn}(\bar X_n-\theta_0)\,K(\bar X_n),\quad K(x)=x\ln\frac x{\theta_0}+(1-x)\ln\frac{1-x}{1-\theta_0}$$
> ($K$ = divergence de Kullback–Leibler entre $\mathcal B(x)$ et $\mathcal B(\theta_0)$, $\ge0$).
> $K'(x)=\ln\frac{x(1-\theta_0)}{\theta_0(1-x)}$ : $>0$ si $x>\theta_0$, $<0$ si $x<\theta_0$, et $K(\theta_0)=0$. Donc $f(x)=\exp\big(n\,\text{sgn}(x-\theta_0)K(x)\big)$ est strictement croissante.

**2. Test et puissance.**
> [!success]- Corrigé
> $T_n=\mathbf 1(\bar X_n>\epsilon)$. $\theta\mapsto P_\theta(S>n\epsilon)$ est croissante (binomiale stochastiquement croissante en $\theta$) ⇒ seuil calculé en $\theta_0$ :
> - exact : $n\epsilon$ = plus petit entier $c$ tel que $P(\text{Bin}(n,\theta_0)>c)\le\alpha$ ;
> - asymptotique : $\epsilon=\theta_0+q_\alpha\sqrt{\theta_0(1-\theta_0)/n}$.
> Puissance : $\gamma(\theta)=P(\text{Bin}(n,\theta)>n\epsilon)\approx1-\Phi\Big(\frac{\sqrt n(\theta_0-\theta)+q_\alpha\sqrt{\theta_0(1-\theta_0)}}{\sqrt{\theta(1-\theta)}}\Big)$.

---
## Exercice 6 (★★) — Égalité de deux moyennes, $\sigma^2$ connue

**1. RV.**
> [!success]- Corrigé
> $H_1$ : $\hat\mu_1=\bar X$, $\hat\mu_2=\bar Y$. $H_0$ : moyenne commune $\hat\mu=\frac{n\bar X+m\bar Y}{n+m}$.
> $$\ln R_n=\frac1{2\sigma^2}\big[n(\bar X-\hat\mu)^2+m(\bar Y-\hat\mu)^2\big]=\frac{nm}{2\sigma^2(n+m)}(\bar X-\bar Y)^2$$
> (car $\bar X-\hat\mu=\frac m{n+m}(\bar X-\bar Y)$, $\bar Y-\hat\mu=-\frac n{n+m}(\bar X-\bar Y)$).

**2. Test et puissance.**
> [!success]- Corrigé
> $Z=\dfrac{\bar X-\bar Y}{\sigma\sqrt{\frac1n+\frac1m}}$, $\ln R_n=Z^2/2$ ⇒ rejet si $|Z|>\epsilon$. Sous $H_0$, $Z\sim\mathcal N(0,1)$ ⇒ $\epsilon=\Phi^{-1}(1-\alpha/2)=:q$.
> Sous $(\mu_1,\mu_2)$ : $Z\sim\mathcal N(\delta,1)$, $\delta=\frac{\mu_1-\mu_2}{\sigma\sqrt{1/n+1/m}}$ ⇒
> $$\gamma=1-\Phi(q-\delta)+\Phi(-q-\delta).$$

**3. $\sigma^2$ inconnue.**
> [!success]- Corrigé
> $\hat\sigma_1^2=\frac{\sum(X_i-\bar X)^2+\sum(Y_j-\bar Y)^2}{n+m}$ (H1), $\hat\sigma_0^2=\hat\sigma_1^2+\frac{nm}{(n+m)^2}(\bar X-\bar Y)^2$ (H0).
> $R_n=(\hat\sigma_0^2/\hat\sigma_1^2)^{(n+m)/2}=\big(1+\frac{T^2}{n+m-2}\big)^{(n+m)/2}$ avec
> $$T=\frac{\bar X-\bar Y}{s_p\sqrt{\frac1n+\frac1m}},\quad s_p^2=\frac{\sum(X_i-\bar X)^2+\sum(Y_j-\bar Y)^2}{n+m-2}.$$
> Sous $H_0$, $T\sim t(n+m-2)$ (numérateur gaussien, $(n+m-2)s_p^2/\sigma^2\sim\chi^2(n-1)+\chi^2(m-1)=\chi^2(n+m-2)$, indépendants) ⇒ rejet si $|T|>t_{n+m-2,1-\alpha/2}$.

---
## Exercice 7 (★★) — Détection RADAR
$H_0:y=v$ vs $H_1:y=as+v$ ($a\ne0$ inconnu ; je note $a$ l'amplitude pour ne pas confondre avec le niveau $\alpha$). $y,s\in\mathbb R^N$, $v\sim\mathcal N(0,\sigma^2I_N)$.

**1. RV.**
> [!success]- Corrigé
> Sous $H_1$, MV de $a$ : minimiser $\|y-as\|^2$ ⇒ $\hat a=\frac{\langle s,y\rangle}{\|s\|^2}$ (moindres carrés, $p=0$ sans constante).
> $$\ln R_n=\frac{\|y\|^2-\|y-\hat as\|^2}{2\sigma^2}=\frac{\langle s,y\rangle^2}{2\sigma^2\|s\|^2}.$$
> Quantité centrale : $\langle s,y\rangle=\sum_{n=0}^{N-1}s_ny_n$ = **corrélation avec le signal émis = sortie du filtre adapté**.

**2. Test et puissance.**
> [!success]- Corrigé
> $Z=\frac{\langle s,y\rangle}{\sigma\|s\|}$ ; rejet si $|Z|>\epsilon$. Sous $H_0$, $\langle s,v\rangle\sim\mathcal N(0,\sigma^2\|s\|^2)$ ⇒ $Z\sim\mathcal N(0,1)$ ⇒ $\epsilon=\Phi^{-1}(1-\alpha/2)=:q$ (niveau = probabilité de fausse alarme).
> Sous $H_1$ : $Z\sim\mathcal N(d,1)$, $d=\frac{a\|s\|}\sigma$ ⇒
> $$\gamma(a)=1-\Phi(q-d)+\Phi(-q-d).$$
> $d^2=\frac{a^2\|s\|^2}{\sigma^2}$ = **rapport signal sur bruit** (énergie reçue / puissance du bruit) : la probabilité de détection ne dépend que du SNR. Signal plus long/énergétique ⇒ meilleure détection.
