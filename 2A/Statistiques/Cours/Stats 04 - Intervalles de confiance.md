---
tags: [stats, cours, estimation]
---
# 04 — Intervalles de confiance

Précédent : [[Stats 03 - Construire un estimateur (moments, MV)]] · Suivant : [[Stats 05 - Estimation bayésienne]]

## Définition
$[\underline\theta_{\alpha,n},\overline\theta_{\alpha,n}]$ (deux **statistiques**, bornes ne dépendant pas de $\theta$) est un IC de niveau $1-\alpha$ si
$$P_\theta\big(\theta\in[\underline\theta,\overline\theta]\big)\ge1-\alpha\quad\forall\theta.$$
**Asymptotique** si $P_\theta(\theta\in I_{\alpha,n})\to1-\alpha$.

> [!warning] Interprétation
> C'est l'**intervalle** qui est aléatoire, pas $\theta$. « 95 % » = sur beaucoup d'expériences, 95 % des intervalles contiennent $\theta$.

## La méthode : la quantité pivotale
> [!important] Recette
> 1. Trouver $Z=h(X_1,\dots,X_n,\theta)$ dont la loi **ne dépend pas de $\theta$** (exacte ou limite) : $\mathcal N(0,1)$, $t(k)$, $\chi^2(k)$...
> 2. Écrire $P(|Z|\le q)=1-\alpha$ avec $q$ le quantile ($q=\Phi^{-1}(1-\alpha/2)$ pour $\mathcal N(0,1)$).
> 3. **Isoler $\theta$** dans l'inégalité $|Z|\le q$.
> 4. Si les bornes contiennent encore $\theta$ (ex. variance $\theta(1-\theta)$) : remplacer par un estimateur consistant → **Slutsky** (IC asymptotique).

## Les 4 IC du cours (+1 classique)
**1. Gaussien, $\sigma^2$ connue (exact)** : $\sqrt n\frac{\bar X_n-\mu}\sigma\sim\mathcal N(0,1)$
$$I=\Big[\bar X_n\pm\frac{\sigma}{\sqrt n}\Phi^{-1}(1-\tfrac\alpha2)\Big].$$

**2. Gaussien, $\sigma^2$ inconnue (exact)** : $\sqrt n\frac{\bar X_n-\mu}{s_n}\sim t(n-1)$
$$I=\Big[\bar X_n\pm\frac{s_n}{\sqrt n}\,t_{n-1,1-\alpha/2}\Big].$$

**3. Bernoulli via Tchebychev (non asymptotique, grossier)** : $P(|\bar X_n-\theta|\ge\epsilon)\le\frac{\theta(1-\theta)}{n\epsilon^2}\le\frac1{4n\epsilon^2}$. On pose $\frac1{4n\epsilon^2}=\alpha$ :
$$I=\Big[\bar X_n\pm\sqrt{\tfrac1{4\alpha n}}\Big].$$

**4. Bernoulli via TLC + Slutsky (asymptotique)** :
$$I=\Big[\bar X_n\pm\sqrt{\tfrac{\bar X_n(1-\bar X_n)}n}\,\Phi^{-1}(1-\tfrac\alpha2)\Big].$$

**5. Cas général asymptotique** : si $\sqrt n(\hat\theta_n-\theta)\to\mathcal N(0,v(\theta))$ et $v$ continue, $\hat\theta_n$ consistant :
$$\sqrt n\frac{\hat\theta_n-\theta}{\sqrt{v(\hat\theta_n)}}\xrightarrow{\mathcal L}\mathcal N(0,1)\ \Rightarrow\ I=\Big[\hat\theta_n\pm q\sqrt{v(\hat\theta_n)/n}\Big].$$
*Justification Slutsky* : $\frac{\sqrt n(\hat\theta_n-\theta)}{\sqrt{v(\hat\theta_n)}}=\underbrace{\frac{\sqrt n(\hat\theta_n-\theta)}{\sqrt{v(\theta)}}}_{\to\mathcal N(0,1)}\cdot\underbrace{\sqrt{\frac{v(\theta)}{v(\hat\theta_n)}}}_{\xrightarrow{P}1}$.

---
## Exos de base

**E1.** 25 mesures $\mathcal N(\mu,4)$, $\bar x=10{,}3$. IC à 95 % ?
> [!success]- Solution
> $10{,}3\pm\frac{2}{5}\times1{,}96=10{,}3\pm0{,}784=[9{,}52;\,11{,}08]$.

**E2.** Même chose avec $\sigma$ inconnue, $s=2$, $t_{24;0,975}=2{,}064$.
> [!success]- Solution
> $10{,}3\pm0{,}4\times2{,}064=[9{,}47;\,11{,}13]$ — plus large (on paie l'ignorance de $\sigma$).

**E3.** Sondage : 520 « oui » sur 1000. IC asymptotique à 95 % ?
> [!success]- Solution
> $0{,}52\pm1{,}96\sqrt{0{,}52\cdot0{,}48/1000}=0{,}52\pm0{,}031$.

**E4.** $\mathcal E(\theta)$, $\hat\theta_n=1/\bar X_n$. IC asymptotique de $\theta$.
> [!success]- Solution
> $v(\theta)=\theta^2$ ⇒ $I=\big[\hat\theta_n(1\pm q/\sqrt n)\big]$, $q=\Phi^{-1}(1-\alpha/2)$.

**E5.** Combien d'observations pour que l'IC à 95 % d'une proportion ait une demi-largeur $\le0{,}01$ (pire cas) ?
> [!success]- Solution
> $1{,}96\sqrt{\frac{1/4}n}\le0{,}01\Rightarrow n\ge\big(\frac{1{,}96}{0{,}02}\big)^2=9604$.
