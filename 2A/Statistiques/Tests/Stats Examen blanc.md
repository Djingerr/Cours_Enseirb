---
tags: [stats, examen]
---
# Examen blanc — Statistiques (1h30, sans document)

Retour : [[00 - Stats Sommaire]] · À faire **après** les 3 TD. Barème indicatif sur 20.

## Exercice 1 — Loi de Rayleigh (8 pts)
$X_1,\dots,X_n$ i.i.d. de densité $f_\theta(x)=\dfrac{x}{\theta}e^{-x^2/(2\theta)}\mathbf 1_{x\ge0}$, $\theta>0$.
1. (1) Donner le modèle statistique. Est-il paramétrique ?
2. (1) Montrer que $Y=X^2$ suit une loi exponentielle dont on donnera le paramètre.
3. (2) Calculer l'estimateur MV $\hat\theta_n$ (justifier qu'il s'agit d'un maximum).
4. (2) Biais, EQM. Est-il consistant ?
5. (2) Montrer la normalité asymptotique et en déduire un IC asymptotique de niveau $1-\alpha$.

## Exercice 2 — Bayésien exponentiel (4 pts)
$X_k|\theta\sim\mathcal E(\theta)$ i.i.d., a priori $\theta\sim\Gamma(a,b)$.
1. (2) Loi a posteriori.
2. (1) Estimateur de Bayes pour le risque quadratique ; estimateur MAP.
3. (1) Que deviennent-ils quand $n\to\infty$ ? Comparer au MV.

## Exercice 3 — Test sur la loi de Rayleigh (6 pts)
Même modèle qu'à l'exercice 1. On teste $H_0:\theta=\theta_0$ contre $H_1:\theta=\theta_1$, $\theta_0<\theta_1$.
1. (2) Calculer le ratio de vraisemblances et montrer que le test RV est de la forme $\mathbf 1\big(\sum X_k^2>\epsilon\big)$.
2. (2) Sachant que $\frac1\theta\sum X_k^2\sim\chi^2(2n)$ sous $P_\theta$ (le justifier), déterminer $\epsilon$ pour un niveau $\alpha$ exact.
3. (2) Exprimer la puissance à l'aide de la f.d.r. $F$ de $\chi^2(2n)$. Comment évolue-t-elle quand $\theta_1$ augmente ?

## Question de cours (2 pts)
Énoncer le théorème de Gauss–Markov et donner l'idée de la preuve en 3 lignes.

---
> [!success]- Correction Exercice 1
> 1. $\mathcal X=\mathbb R_+$, $\mathcal M=\{f_\theta:\theta>0\}$ ; paramétrique ($\Theta\subset\mathbb R$).
> 2. $P(Y>y)=P(X>\sqrt y)=\int_{\sqrt y}^\infty\frac x\theta e^{-x^2/2\theta}dx=e^{-y/(2\theta)}$ ⇒ $Y\sim\mathcal E\big(\frac1{2\theta}\big)$, $\mathbb EY=2\theta$, $\mathbb VY=4\theta^2$.
> 3. $\ell_n=\sum\ln X_k-n\ln\theta-\frac1{2\theta}\sum X_k^2$ ; $\ell'=-\frac n\theta+\frac{\sum X_k^2}{2\theta^2}=0$ ⇒ $\hat\theta_n=\frac1{2n}\sum X_k^2$. Signe de $\ell'$ : $>0$ pour $\theta<\hat\theta$, $<0$ après ⇒ max global unique.
> 4. $\mathbb E\hat\theta_n=\frac{2\theta}2=\theta$ : sans biais. $R=\mathbb V=\frac{4\theta^2}{4n}=\frac{\theta^2}n\to0$ : consistant.
> 5. TLC sur $Y_k/2$ (moyenne $\theta$, variance $\theta^2$) : $\sqrt n(\hat\theta_n-\theta)\to\mathcal N(0,\theta^2)$. Slutsky : $I=\big[\hat\theta_n(1\pm q/\sqrt n)\big]$, $q=\Phi^{-1}(1-\alpha/2)$.

> [!success]- Correction Exercice 2
> 1. $\pi(\theta|x)\propto\theta^ne^{-\theta S}\theta^{a-1}e^{-b\theta}$ ⇒ $\Gamma(a+n,\,b+S)$.
> 2. MMSE $=\frac{a+n}{b+S}$ ; MAP $=\frac{a+n-1}{b+S}$.
> 3. Les deux $\sim\frac n S=\frac1{\bar X_n}$ = MV : l'a priori est oublié.

> [!success]- Correction Exercice 3
> 1. $R_n=\big(\frac{\theta_0}{\theta_1}\big)^n\exp\big(\big(\frac1{2\theta_0}-\frac1{2\theta_1}\big)\sum X_k^2\big)$ ; coefficient $>0$ car $\theta_0<\theta_1$ ⇒ croissant en $\sum X_k^2$.
> 2. $X_k^2/\theta\sim\mathcal E(1/2)=\chi^2(2)$, somme de $n$ ⇒ $\chi^2(2n)$. $P_{\theta_0}(\sum X_k^2>\epsilon)=1-F(\epsilon/\theta_0)=\alpha$ ⇒ $\epsilon=\theta_0F^{-1}(1-\alpha)$.
> 3. $\gamma=P_{\theta_1}(\sum X_k^2>\epsilon)=1-F\big(\frac{\theta_0}{\theta_1}F^{-1}(1-\alpha)\big)$ ; croissante en $\theta_1$ (argument de $F$ décroît).

> [!success]- Correction Question de cours
> Voir [[Stats 06 - Régression linéaire]] §3 : $\tilde\beta=Ay$ sans biais ⇔ $AX=I$ ; $A=(X^TX)^{-1}X^T+D$, $DX=0$ ; $\mathbb V[\tilde\beta]=\mathbb V[\hat\beta]+\sigma^2DD^T\succeq\mathbb V[\hat\beta]$.
