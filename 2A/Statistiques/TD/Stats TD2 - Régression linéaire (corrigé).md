---
tags: [stats, td, regression]
---
# TD2 — Régression linéaire (méthodes + corrigés)

Prérequis : [[Stats 06 - Régression linéaire]], §6 de [[Stats 01 - Rappels de probabilités]]
Retour : [[00 - Stats Sommaire]]

Notations : $H=X(X^TX)^{-1}X^T$ (projecteur sur $\text{Im}X$), $r=y-X\hat\beta=(I-H)y$.

---
## Exercice 1 (★★) — Gauss–Markov

**1. Existence et unicité des moindres carrés.**
> [!hint]- Indice
> Gradient de $J(\beta)=\|y-X\beta\|^2$, puis inversibilité de $X^TX$ via le rang, puis convexité stricte.

> [!success]- Corrigé
> $J(\beta)=y^Ty-2\beta^TX^Ty+\beta^TX^TX\beta$, $\nabla J(\beta)=2X^TX\beta-2X^Ty$, $\nabla^2J=2X^TX$.
> - $X^TX$ est définie positive : $v^TX^TXv=\|Xv\|^2\ge0$, et $=0\Rightarrow Xv=0\Rightarrow v=0$ car $\text{rg}X=p+1$ (colonnes libres). Donc inversible.
> - $J$ strictement convexe (hessienne DP) ⇒ tout point critique est l'unique minimum global.
> - $\nabla J=0\iff X^TX\beta=X^Ty\iff\beta=(X^TX)^{-1}X^Ty$.

**2. Biais et risque.**
> [!success]- Corrigé
> $\hat\beta=(X^TX)^{-1}X^T(X\beta+\varepsilon)=\beta+(X^TX)^{-1}X^T\varepsilon$.
> - $\mathbb E[\hat\beta]=\beta$ ⇒ **sans biais**.
> - $\text{Cov}(\hat\beta)=(X^TX)^{-1}X^T\,\mathbb E[\varepsilon\varepsilon^T]\,X(X^TX)^{-1}=\sigma^2(X^TX)^{-1}$.
> - $R=\mathbb E\|\hat\beta-\beta\|^2=\text{tr}\,\text{Cov}(\hat\beta)=\boxed{\sigma^2\,\text{tr}\big((X^TX)^{-1}\big)}$.

**3. $\mathbb V[\tilde\beta]\succeq\mathbb V[\hat\beta]$.**
> [!hint]- Indice
> $f$ linéaire ⇒ $\tilde\beta=Ay$. Traduire « sans biais pour tout $\beta$ » en une égalité matricielle, puis décomposer $A=(X^TX)^{-1}X^T+D$.

> [!success]- Corrigé
> $\tilde\beta=Ay$, $A\in\mathbb R^{(p+1)\times n}$. $\mathbb E[\tilde\beta]=AX\beta=\beta\ \forall\beta\iff AX=I_{p+1}$.
> Posons $D=A-(X^TX)^{-1}X^T$ : $DX=AX-I=0$.
> $\tilde\beta-\beta=A\varepsilon$ ⇒ $\mathbb V[\tilde\beta]=\sigma^2AA^T$ et
> $$AA^T=(X^TX)^{-1}+(X^TX)^{-1}\underbrace{X^TD^T}_{(DX)^T=0}+\underbrace{DX}_{0}(X^TX)^{-1}+DD^T.$$
> Donc $\mathbb V[\tilde\beta]-\mathbb V[\hat\beta]=\sigma^2DD^T\succeq0$ ($u^TDD^Tu=\|D^Tu\|^2\ge0$). ∎
> **Commentaire** : $\hat\beta$ est **BLUE** — meilleur estimateur linéaire sans biais. En particulier chaque $\hat\beta_k$ a la plus petite variance (diagonale), et $R(\tilde\beta)\ge R(\hat\beta)$ (trace). Hors de cette classe (biaisé ou non linéaire, ex. ridge), on peut faire mieux.

---
## Exercice 2 (★★) — Variance et décomposition

**1. $\hat\sigma^2$ sans biais.**
> [!hint]- Indice
> $r=(I-H)\varepsilon$, puis astuce trace : $\mathbb E[\varepsilon^TM\varepsilon]=\text{tr}(M\,\mathbb E[\varepsilon\varepsilon^T])$.

> [!success]- Corrigé
> $(I-H)X=X-X=0$ ⇒ $r=(I-H)(X\beta+\varepsilon)=(I-H)\varepsilon$. $I-H$ symétrique idempotente ⇒ $\|r\|^2=\varepsilon^T(I-H)\varepsilon$.
> $$\mathbb E\|r\|^2=\text{tr}\big((I-H)\sigma^2I\big)=\sigma^2\big(n-\text{tr}H\big)=\sigma^2(n-p-1),$$
> car $\text{tr}H=\text{tr}\big((X^TX)^{-1}X^TX\big)=p+1$. Donc $\mathbb E[\hat\sigma^2]=\sigma^2$. ∎

**2. $SST=SSR+SSE$.**
> [!success]- Corrigé
> $y-\bar y\mathbf1=\underbrace{(y-X\hat\beta)}_{r}+\underbrace{(X\hat\beta-\bar y\mathbf1)}_{u}$.
> $r\in\text{Im}(X)^\perp$ (car $X^Tr=X^T(I-H)y=0$), et $u\in\text{Im}(X)$ car $X\hat\beta\in\text{Im}X$ et $\mathbf1$ est la 1ère colonne de $X$. Donc $r\perp u$ et Pythagore donne $\|y-\bar y\mathbf1\|^2=\|r\|^2+\|u\|^2$. ∎
> **Commentaire** : variabilité totale = variabilité résiduelle (non expliquée) + variabilité expliquée par le modèle. $R^2=SSE/SST=1-SSR/SST\in[0,1]$ mesure la qualité d'ajustement. **Le terme constant $\beta_0$ est indispensable** pour cette décomposition.

---
## Exercice 3 (★★) — Hypothèse gaussienne $\varepsilon\sim\mathcal N(0,\sigma^2I)$

**1. Lois de $\langle a,\hat\beta\rangle$ et $\hat\sigma^2/\sigma^2$.**
> [!success]- Corrigé
> $\hat\beta=\beta+(X^TX)^{-1}X^T\varepsilon$ est une transformation affine d'un vecteur gaussien :
> $$\hat\beta\sim\mathcal N\big(\beta,\sigma^2(X^TX)^{-1}\big)\ \Rightarrow\ \langle a,\hat\beta\rangle\sim\mathcal N\big(\langle a,\beta\rangle,\ \sigma^2a^T(X^TX)^{-1}a\big).$$
> $(n-p-1)\frac{\hat\sigma^2}{\sigma^2}=\big\|(I-H)\tfrac\varepsilon\sigma\big\|^2$ avec $\varepsilon/\sigma\sim\mathcal N(0,I_n)$ et $I-H$ projecteur orthogonal de rang $n-p-1$.
> *Justification* : diagonaliser $I-H=U\,\text{diag}(1,\dots,1,0,\dots,0)U^T$ ($n-p-1$ uns), $U$ orthogonale ; $W=U^T\varepsilon/\sigma\sim\mathcal N(0,I)$ ; $\|(I-H)\varepsilon/\sigma\|^2=\sum_{i=1}^{n-p-1}W_i^2\sim\chi^2(n-p-1)$.
> Donc $\boxed{\frac{\hat\sigma^2}{\sigma^2}\sim\frac{\chi^2(n-p-1)}{n-p-1}}$.

**2. Indépendance.**
> [!success]- Corrigé
> $(\hat\beta-\beta,\ r)=\big((X^TX)^{-1}X^T\varepsilon,\ (I-H)\varepsilon\big)$ est un vecteur gaussien (image linéaire de $\varepsilon$). Covariance croisée :
> $$\mathbb E\big[(X^TX)^{-1}X^T\varepsilon\varepsilon^T(I-H)\big]=\sigma^2(X^TX)^{-1}\underbrace{X^T(I-H)}_{=0}=0.$$
> Gaussien + décorrélés ⇒ **indépendants**. Donc $\langle a,\hat\beta\rangle$ (fonction de $\hat\beta$) et $\hat\sigma^2$ (fonction de $r$) sont indépendants.

**3. IC pour $\beta_k$.**
> [!success]- Corrigé
> $a=e_k$, $c_k=[(X^TX)^{-1}]_{kk}$. $Z=\frac{\hat\beta_k-\beta_k}{\sigma\sqrt{c_k}}\sim\mathcal N(0,1)$, $Y=(n-p-1)\frac{\hat\sigma^2}{\sigma^2}\sim\chi^2(n-p-1)$, indépendants :
> $$T=\frac{Z}{\sqrt{Y/(n-p-1)}}=\frac{\hat\beta_k-\beta_k}{\hat\sigma\sqrt{c_k}}\sim t(n-p-1)\quad(\sigma\text{ disparaît !}).$$
> $$\boxed{I=\Big[\hat\beta_k\pm t_{n-p-1,1-\alpha/2}\ \hat\sigma\sqrt{[(X^TX)^{-1}]_{kk}}\Big]}$$
> de niveau **exact** $1-\alpha$. (Attention : $\beta$ indexé de 0 à $p$, donc $\beta_k$ ↔ $(k+1)$-ième élément diagonal.)
