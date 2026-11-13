---
tags: [stats, cours, regression]
---
# 06 — Régression linéaire

Précédent : [[Stats 05 - Estimation bayésienne]] · Suivant : [[Stats 07 - Tests d'hypothèses]]

> [!info] Ce chapitre n'est pas dans les slides : il est **entièrement dans le TD2**. Il faut donc le maîtriser à partir d'ici.

## 1. Le modèle
$$y_i=\beta_0+\beta_1x_{i,1}+\dots+\beta_px_{i,p}+\varepsilon_i\quad\Longleftrightarrow\quad \boxed{y=X\beta+\varepsilon}$$
- $y\in\mathbb R^n$ : données observées (à expliquer)
- $X\in\mathbb R^{n\times(p+1)}$ : variables explicatives **connues**, **1ère colonne = que des 1** (pour $\beta_0$)
- $\beta\in\mathbb R^{p+1}$ : paramètres inconnus ; $\varepsilon$ : bruit

**Hypothèses de Gauss–Markov** : (1) $\text{rg}(X)=p+1$ (colonnes indépendantes) ; (2) $\mathbb E[\varepsilon]=0$, $\mathbb E[\varepsilon\varepsilon^T]=\sigma^2I$ (bruit centré, non corrélé, même variance).

## 2. Moindres carrés
$$\hat\beta=\arg\min_\beta\|y-X\beta\|_2^2=(X^TX)^{-1}X^Ty.$$

> [!important] Preuve (TD2 ex 1.1)
> - $J(\beta)=\|y-X\beta\|^2=y^Ty-2\beta^TX^Ty+\beta^TX^TX\beta$.
> - Gradient : $\nabla J=-2X^Ty+2X^TX\beta=0$ ⇒ **équations normales** $X^TX\beta=X^Ty$.
> - $X^TX$ inversible : si $X^TXv=0$ alors $v^TX^TXv=\|Xv\|^2=0$ ⇒ $Xv=0$ ⇒ $v=0$ (rang plein).
> - Hessienne $2X^TX$ **définie positive** ⇒ $J$ strictement convexe ⇒ minimum global **unique**.

### Interprétation géométrique (très utile !)
$X\hat\beta=Hy$ avec $H=X(X^TX)^{-1}X^T$ = **projecteur orthogonal** sur $\text{Im}(X)$.
- $H^2=H$, $H^T=H$, $\text{tr}(H)=\text{rg}(H)=p+1$, $HX=X$.
- Résidu $r=y-X\hat\beta=(I-H)y$, avec $I-H$ projecteur sur $\text{Im}(X)^\perp$, $\text{tr}(I-H)=n-p-1$.
- $(I-H)X=0$ ⇒ $r=(I-H)\varepsilon$ (le résidu ne voit que le bruit).
- $r\perp\text{Im}(X)$, en particulier $r\perp\mathbf 1$ et $r\perp X\hat\beta$.

## 3. Propriétés de $\hat\beta$
- $\hat\beta=\beta+(X^TX)^{-1}X^T\varepsilon$ ⇒ **sans biais**.
- $\text{Cov}(\hat\beta)=(X^TX)^{-1}X^T(\sigma^2I)X(X^TX)^{-1}=\boxed{\sigma^2(X^TX)^{-1}}$.
- Risque : $\mathbb E\|\hat\beta-\beta\|^2=\sigma^2\,\text{tr}\big((X^TX)^{-1}\big)$.

> [!important] Théorème de Gauss–Markov
> Parmi les estimateurs **linéaires** ($\tilde\beta=Ay$) **sans biais**, $\hat\beta$ a la plus petite covariance : $\mathbb V[\tilde\beta]\succeq\mathbb V[\hat\beta]$ (BLUE = *Best Linear Unbiased Estimator*).
> **Idée de preuve** : sans biais ∀β ⇒ $AX=I$. Écrire $A=(X^TX)^{-1}X^T+D$ ⇒ $DX=0$ ⇒ $\mathbb V[\tilde\beta]=\sigma^2AA^T=\mathbb V[\hat\beta]+\sigma^2DD^T$ (les termes croisés valent $(X^TX)^{-1}(DX)^T=0$).

## 4. Estimer $\sigma^2$
$$\hat\sigma^2=\frac{1}{n-p-1}\|y-X\hat\beta\|^2\quad\text{sans biais.}$$
Preuve : $\mathbb E\|(I-H)\varepsilon\|^2=\mathbb E[\varepsilon^T(I-H)\varepsilon]=\text{tr}\big((I-H)\sigma^2I\big)=\sigma^2(n-p-1)$.
(On divise par le nombre de **degrés de liberté** : $n$ données − $(p+1)$ paramètres estimés.)

## 5. Décomposition de la variance
$$\underbrace{\|y-\bar y\mathbf 1\|^2}_{SST}=\underbrace{\|y-X\hat\beta\|^2}_{SSR}+\underbrace{\|X\hat\beta-\bar y\mathbf 1\|^2}_{SSE}$$
Preuve : Pythagore. $y-\bar y\mathbf1=r+(X\hat\beta-\bar y\mathbf1)$, $r\perp\text{Im}X$ et $X\hat\beta-\bar y\mathbf1\in\text{Im}X$ (car $\mathbf1$ = 1ère colonne de $X$).
**Coefficient de détermination** $R^2=SSE/SST\in[0,1]$ : part de variabilité expliquée par le modèle.

## 6. Cas gaussien : $\varepsilon\sim\mathcal N(0,\sigma^2I)$
- $\hat\beta\sim\mathcal N\big(\beta,\sigma^2(X^TX)^{-1}\big)$, donc $\langle a,\hat\beta\rangle\sim\mathcal N\big(\langle a,\beta\rangle,\sigma^2a^T(X^TX)^{-1}a\big)$.
- $(n-p-1)\dfrac{\hat\sigma^2}{\sigma^2}=\dfrac{\|(I-H)\varepsilon\|^2}{\sigma^2}\sim\chi^2(n-p-1)$ (Cochran).
- $\hat\beta\perp\!\!\!\perp\hat\sigma^2$ : $(X^TX)^{-1}X^T\varepsilon$ et $(I-H)\varepsilon$ sont conjointement gaussiens de covariance croisée $\sigma^2(X^TX)^{-1}X^T(I-H)=0$.
- Donc, avec $c_k=[(X^TX)^{-1}]_{kk}$ :
$$\frac{\hat\beta_k-\beta_k}{\hat\sigma\sqrt{c_k}}\sim t(n-p-1)\ \Rightarrow\ \text{IC : }\hat\beta_k\pm t_{n-p-1,1-\alpha/2}\,\hat\sigma\sqrt{c_k}.$$

> [!tip] Le lien avec TD3 ex 3
> Pour $p=0$ ($X=\mathbf1$, on estime juste une moyenne) : $\hat\beta_0=\bar y$, $\hat\sigma^2=s_n^2$, $c_0=1/n$ ⇒ on retrouve $\sqrt n\frac{\bar y-\mu}{s_n}\sim t(n-1)$.

---
## Exos de base

**E1.** Régression simple $y_i=\beta_0+\beta_1x_i+\varepsilon_i$. Écrire $X$, $X^TX$ et retrouver $\hat\beta_1=\frac{\sum(x_i-\bar x)(y_i-\bar y)}{\sum(x_i-\bar x)^2}$.
> [!success]- Solution
> $X^TX=\begin{pmatrix}n&\sum x_i\\\sum x_i&\sum x_i^2\end{pmatrix}$, $X^Ty=\begin{pmatrix}\sum y_i\\\sum x_iy_i\end{pmatrix}$. Équations normales : $\beta_0+\beta_1\bar x=\bar y$ et $\beta_0\sum x_i+\beta_1\sum x_i^2=\sum x_iy_i$. Substituer $\beta_0=\bar y-\beta_1\bar x$ ⇒ formule.

**E2.** Pour $X=\mathbf 1$ (n×1), calculer $\hat\beta$, $H$ et $\hat\sigma^2$.
> [!success]- Solution
> $X^TX=n$ ⇒ $\hat\beta=\bar y$. $H=\frac1n\mathbf1\mathbf1^T$ (tout à $1/n$). $\hat\sigma^2=\frac1{n-1}\sum(y_i-\bar y)^2$.

**E3.** Montrer $H^2=H$ et $\text{tr}(H)=p+1$.
> [!success]- Solution
> $H^2=X(X^TX)^{-1}X^TX(X^TX)^{-1}X^T=H$. $\text{tr}(H)=\text{tr}\big((X^TX)^{-1}X^TX\big)=\text{tr}(I_{p+1})=p+1$ (cyclicité).

**E4.** Pourquoi $\sum_i r_i=0$ (résidus de somme nulle) ?
> [!success]- Solution
> $X^Tr=X^T(I-H)y=0$ ; la 1ère ligne de $X^T$ est $\mathbf1^T$ ⇒ $\mathbf1^Tr=0$.
