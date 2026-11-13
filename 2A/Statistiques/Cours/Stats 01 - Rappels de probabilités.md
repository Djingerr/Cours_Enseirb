---
tags: [stats, cours]
---
# 01 — Rappels de probabilités (la boîte à outils)

Retour : [[00 - Stats Sommaire]] · Suivant : [[Stats 02 - Estimateurs et risque]]

Tout le cours repose sur ces outils. Si un calcul de TD bloque, c'est presque toujours ici.

## 1. Lois usuelles

| Loi | Support | Masse / densité | $\mathbb E$ | $\mathbb V$ |
|---|---|---|---|---|
| Bernoulli $\mathcal B(p)$ | $\{0,1\}$ | $p^x(1-p)^{1-x}$ | $p$ | $p(1-p)$ |
| Binomiale $\text{Bin}(n,p)$ | $[\![0,n]\!]$ | $\binom nk p^k(1-p)^{n-k}$ | $np$ | $np(1-p)$ |
| Poisson $\mathcal P(\theta)$ | $\mathbb N$ | $e^{-\theta}\theta^k/k!$ | $\theta$ | $\theta$ |
| Uniforme $\mathcal U([a,b])$ | $[a,b]$ | $\frac1{b-a}$ | $\frac{a+b}2$ | $\frac{(b-a)^2}{12}$ |
| Exponentielle $\mathcal E(\theta)$ | $\mathbb R_+$ | $\theta e^{-\theta x}$ | $1/\theta$ | $1/\theta^2$ |
| Gamma $\Gamma(k,\lambda)$ | $\mathbb R_+$ | $\frac{\lambda^k}{\Gamma(k)}x^{k-1}e^{-\lambda x}$ | $k/\lambda$ | $k/\lambda^2$ |
| Normale $\mathcal N(\mu,\sigma^2)$ | $\mathbb R$ | $\frac1{\sqrt{2\pi\sigma^2}}e^{-\frac{(x-\mu)^2}{2\sigma^2}}$ | $\mu$ | $\sigma^2$ |
| Beta $\text{Beta}(a,b)$ | $]0,1[$ | $\frac{x^{a-1}(1-x)^{b-1}}{C(a,b)}$ | $\frac a{a+b}$ | $\frac{ab}{(a+b)^2(a+b+1)}$ |
| Khi-deux $\chi^2(k)$ | $\mathbb R_+$ | $=\Gamma(k/2, 1/2)$ | $k$ | $2k$ |

> [!tip] Stabilité à connaître par cœur
> - $X_1,\dots,X_n$ i.i.d. $\mathcal B(p)$ ⇒ $\sum X_k\sim\text{Bin}(n,p)$
> - i.i.d. $\mathcal P(\theta)$ ⇒ $\sum X_k\sim\mathcal P(n\theta)$
> - i.i.d. $\mathcal E(\theta)$ ⇒ $\sum X_k\sim\Gamma(n,\theta)$, et $2\theta\sum X_k\sim\chi^2(2n)$
> - i.i.d. $\mathcal N(\mu,\sigma^2)$ ⇒ $\bar X_n\sim\mathcal N(\mu,\sigma^2/n)$
> - $Z_1,\dots,Z_k$ i.i.d. $\mathcal N(0,1)$ ⇒ $\sum Z_i^2\sim\chi^2(k)$

**Moments de $1/T$ pour $T\sim\Gamma(n,\lambda)$** (sert dans TD1 ex 4) :
$$\mathbb E[1/T]=\frac{\lambda}{n-1}\ (n>1),\qquad \mathbb E[1/T^2]=\frac{\lambda^2}{(n-1)(n-2)}\ (n>2).$$
(Preuve : $\mathbb E[T^{-1}]=\int \frac{\lambda^n}{\Gamma(n)}x^{n-2}e^{-\lambda x}dx=\frac{\lambda^n}{\Gamma(n)}\frac{\Gamma(n-1)}{\lambda^{n-1}}$, et $\Gamma(n)=(n-1)\Gamma(n-1)$.)

## 2. Espérance, variance : règles de calcul
- $\mathbb E[aX+b]=a\mathbb E[X]+b$, $\ \mathbb V[aX+b]=a^2\mathbb V[X]$
- $\mathbb V[X]=\mathbb E[X^2]-\mathbb E[X]^2$
- Indépendance ⇒ $\mathbb V[\sum X_k]=\sum\mathbb V[X_k]$
- Donc pour $\bar X_n=\frac1n\sum X_k$ i.i.d. : $\boxed{\mathbb E[\bar X_n]=\mu,\ \mathbb V[\bar X_n]=\sigma^2/n}$

**Vectoriel** : pour $Y=AX$, $\mathbb E[Y]=A\mathbb E[X]$ et $\text{Cov}(Y)=A\,\text{Cov}(X)\,A^T$.
Astuce trace : $\mathbb E[X^TMX]=\text{tr}(M\,\mathbb E[XX^T])$.

## 3. Inégalités
- **Markov** : $P(|Y|>\epsilon)\le \dfrac{\mathbb E[|Y|^p]}{\epsilon^p}$
- **Bienaymé–Tchebychev** ($p=2$, $Y=X-\mathbb E X$) : $P(|X-\mathbb E X|>\epsilon)\le\dfrac{\mathbb V[X]}{\epsilon^2}$

## 4. La gaussienne standard
$\Phi(x)=P(Z\le x)$, $Z\sim\mathcal N(0,1)$. Symétrie : $\Phi(-x)=1-\Phi(x)$.
Standardisation : $X\sim\mathcal N(\mu,\sigma^2)\Rightarrow \frac{X-\mu}\sigma\sim\mathcal N(0,1)$.

| $1-\alpha$ | 0,90 | 0,95 | 0,975 | 0,99 | 0,995 |
|---|---|---|---|---|---|
| $\Phi^{-1}(1-\alpha)$ | 1,282 | **1,645** | **1,960** | 2,326 | 2,576 |

> [!warning] Unilatère vs bilatère
> $P(Z>q)=\alpha\Rightarrow q=\Phi^{-1}(1-\alpha)$ ; $\ P(|Z|>q)=\alpha\Rightarrow q=\Phi^{-1}(1-\alpha/2)$.
> À 5 % : **1,645** (un côté), **1,96** (deux côtés).

## 5. Convergences (le cœur de l'asymptotique)

**En probabilité** : $X_n\xrightarrow{P}X$ si $\forall\epsilon>0$, $P(|X_n-X|>\epsilon)\to0$.
Stable par $+$, $\times$, $/$ (si limite $\ne0$), et par $\varphi$ continue.

**En loi** : $X_n\xrightarrow{\mathcal L}X$ si $F_{X_n}(x)\to F_X(x)$ en tout point de continuité de $F_X$.

**Loi des grands nombres (LGN)** : i.i.d. de moyenne $\mu$ ⇒ $\bar X_n\xrightarrow{P}\mu$.

**Théorème central limite (TLC)** : i.i.d., $\mathbb E[X_1^2]<\infty$ ⇒
$$\sqrt n\,\frac{\bar X_n-\mu}{\sigma}\xrightarrow{\mathcal L}\mathcal N(0,1).$$
En pratique : $\sum_{k=1}^n X_k\approx\mathcal N(n\mu,\,n\sigma^2)$.

**Slutsky** : si $X_n\xrightarrow{\mathcal L}X$ et $Y_n\xrightarrow{P}c$ (constante) alors $X_n+Y_n\xrightarrow{\mathcal L}X+c$ et $X_nY_n\xrightarrow{\mathcal L}cX$.
→ sert à **remplacer un paramètre inconnu par un estimateur consistant** dans le TLC.

**Delta-méthode** : si $\sqrt n(X_n-\mu)\xrightarrow{\mathcal L}\mathcal N(0,\sigma^2)$ et $\varphi$ dérivable en $\mu$, $\varphi'(\mu)\ne0$ :
$$\sqrt n\big(\varphi(X_n)-\varphi(\mu)\big)\xrightarrow{\mathcal L}\mathcal N\big(0,\sigma^2\varphi'(\mu)^2\big).$$

## 6. Vecteurs gaussiens, $\chi^2$, Student (pour TD2/TD3)
- $X\sim\mathcal N_{\mathbb R^n}(\mu,R)$ ⇒ $AX+b\sim\mathcal N(A\mu+b,\ ARA^T)$.
- Pour un vecteur gaussien : **covariance nulle ⇔ indépendance** (faux en général !).
- **Cochran** : $\varepsilon\sim\mathcal N(0,\sigma^2I_n)$, $P$ projecteur orthogonal de rang $r$ ⇒ $\|P\varepsilon\|^2/\sigma^2\sim\chi^2(r)$, et $P\varepsilon\perp\!\!\!\perp (I-P)\varepsilon$.
- **Student** : $X\sim\mathcal N(0,1)$, $Y\sim\chi^2(k)$ indépendantes ⇒ $T=\dfrac{X}{\sqrt{Y/k}}\sim t(k)$ (symétrique, queues plus lourdes que $\mathcal N(0,1)$, tend vers $\mathcal N(0,1)$ quand $k\to\infty$).
- **Fondamental (échantillon gaussien)** : $\bar X_n\sim\mathcal N(\mu,\sigma^2/n)$, $\frac{(n-1)s_n^2}{\sigma^2}\sim\chi^2(n-1)$ avec $s_n^2=\frac1{n-1}\sum(X_k-\bar X_n)^2$, **indépendants**, donc
$$\sqrt n\,\frac{\bar X_n-\mu}{s_n}\sim t(n-1).$$

---
## Exos de base

**E1.** $X_1,\dots,X_n$ i.i.d. $\mathcal U([0,\theta])$. Calculer $\mathbb E[\bar X_n]$ et $\mathbb V[\bar X_n]$.
> [!success]- Solution
> $\mathbb E[\bar X_n]=\theta/2$, $\mathbb V[\bar X_n]=\dfrac{\theta^2}{12n}$.

**E2.** Avec le TLC, approcher $P(\sum_{k=1}^{100}X_k>60)$ pour $X_k$ i.i.d. $\mathcal B(1/2)$.
> [!success]- Solution
> $\sum X_k\approx\mathcal N(50, 25)$, donc $P\approx 1-\Phi\big(\frac{60-50}{5}\big)=1-\Phi(2)\approx0{,}023$.

**E3.** $X_i$ i.i.d. $\mathcal E(\theta)$. Loi asymptotique de $\sqrt n(1/\bar X_n-\theta)$ ?
> [!success]- Solution
> TLC : $\sqrt n(\bar X_n-1/\theta)\to\mathcal N(0,1/\theta^2)$. Delta-méthode avec $\varphi(x)=1/x$, $\varphi'(1/\theta)=-\theta^2$ :
> variance $\frac1{\theta^2}\theta^4=\theta^2$. Donc $\sqrt n(1/\bar X_n-\theta)\to\mathcal N(0,\theta^2)$.

**E4.** $X$ de densité $f$, $Y=-\ln X$ où $P(X\le t)=t^{\lambda}$ sur $[0,1]$. Loi de $Y$ ?
> [!success]- Solution
> $P(Y>y)=P(X<e^{-y})=e^{-\lambda y}$ : $Y\sim\mathcal E(\lambda)$. (Technique « fonction de répartition » : toujours passer par $P(Y\le y)$ ou $P(Y>y)$.)

**E5.** $X\sim\mathcal N_{\mathbb R^n}(0,\sigma^2 I)$, $a\in\mathbb R^n$. Loi de $\langle a,X\rangle$ ?
> [!success]- Solution
> $a^TX\sim\mathcal N(0,\sigma^2 a^Ta)=\mathcal N(0,\sigma^2\|a\|^2)$.
