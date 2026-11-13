---
tags: [stats, fiche]
---
# Fiche mémo — Statistiques (PS204)

Retour : [[00 - Stats Sommaire]]

## Définitions express
| Notion | Définition |
|---|---|
| Modèle | $\mathcal M=\{f_\theta:\theta\in\Theta\}$ ; paramétrique si $\Theta\subset\mathbb R^d$ |
| Identifiable | $\theta\mapsto f_\theta$ injective |
| Statistique | fonction des données **seules** (pas de $\theta$) |
| Biais | $B=\mathbb E_\theta[\hat\theta]-\theta$ |
| EQM | $R=\mathbb E_\theta[(\hat\theta-\theta)^2]=B^2+\mathbb V$ |
| Consistant | $\hat\theta_n\xrightarrow{P}\theta$ (suffit : $R\to0$) |
| Asympt. normal | $\sqrt n(\hat\theta_n-\theta)\xrightarrow{\mathcal L}\mathcal N(0,\sigma^2(\theta))$ |
| IC niveau $1-\alpha$ | $P_\theta(\theta\in I)\ge1-\alpha$, bornes = statistiques |
| Niveau d'un test | $\sup_{\Theta_0}P_\theta(T_n=1)$ |
| Puissance | $P_\theta(T_n=1)$, $\theta\in\Theta_1$ ; $\beta=1-\gamma$ |

## Théorèmes outils
- **LGN** : $\bar X_n\xrightarrow{P}\mu$. **TLC** : $\sqrt n(\bar X_n-\mu)/\sigma\xrightarrow{\mathcal L}\mathcal N(0,1)$.
- **Slutsky** : $X_n\xrightarrow{\mathcal L}X$, $Y_n\xrightarrow{P}c$ ⇒ $X_nY_n\to cX$, $X_n+Y_n\to X+c$.
- **Delta** : $\sqrt n(\varphi(X_n)-\varphi(\mu))\to\mathcal N(0,\sigma^2\varphi'(\mu)^2)$.
- **Markov** : $P(|Y|>\epsilon)\le\mathbb E|Y|^p/\epsilon^p$.
- **Student** : $\sqrt n(\bar X_n-\mu)/s_n\sim t(n-1)$ (gaussien), $s_n^2=\frac1{n-1}\sum(X_k-\bar X_n)^2$.

## Quantiles
$\Phi^{-1}$ : 0,95 → **1,645** ; 0,975 → **1,96** ; 0,99 → 2,326 ; 0,995 → 2,576.

## Résultats à connaître par cœur
| Modèle | Estimateur | Biais | EQM / var. asympt. |
|---|---|---|---|
| $\mathcal B(\theta)$ | $\bar X_n$ (MV) | 0 | $\theta(1-\theta)/n$ |
| $\mathcal P(\theta)$ | $\bar X_n$ (MV) | 0 | $\theta/n$ |
| $\mathcal E(\theta)$ | $1/\bar X_n$ (MV, moments) | — | asympt. $\theta^2$ |
| $\mathcal U[0,\theta]$ | $2\bar X_n$ (moments) | 0 | $\theta^2/(3n)$ |
| $\mathcal U[0,\theta]$ | $\max X_k$ (MV) | $-\frac\theta{n+1}$ | $\frac{2\theta^2}{(n+1)(n+2)}$ |
| $\mathcal N(\mu,\sigma^2)$ | $\hat\sigma_n^2$ (MV, $\frac1n$) | $-\sigma^2/n$ | $\frac{(2n-1)\sigma^4}{n^2}$ |
| $\mathcal N(\mu,\sigma^2)$ | $s_n^2$ ($\frac1{n-1}$) | 0 | $\frac{2\sigma^4}{n-1}$ |
| Bern.–Beta$(\alpha,\beta)$ | $\frac{\alpha+S}{\alpha+\beta+n}$ (Bayes) | $\frac{\alpha-(\alpha+\beta)\theta}{\alpha+\beta+n}$ | minimax si $\alpha=\beta=\sqrt n/2$ |
| Gauss–Gauss | $\frac{\gamma^2\bar X_n+\frac{\sigma^2}n\theta^*}{\gamma^2+\frac{\sigma^2}n}$ | | MAP = MMSE |
| Régression | $(X^TX)^{-1}X^Ty$ | 0 | Cov $\sigma^2(X^TX)^{-1}$ |
| Régression | $\frac{\|y-X\hat\beta\|^2}{n-p-1}$ | 0 | $\chi^2(n-p-1)$ (gaussien) |

## Recettes
> [!important] MV
> $\ln L$ → dériver → $=0$ → **vérifier max** ($\ell''<0$) → vérifier $\in\Theta$. Support dépendant de $\theta$ : **ne pas dériver**.

> [!important] Bayes
> Posterior $\propto$ vraisemblance × prior → reconnaître la loi → **moyenne** (L2) ou **mode** (MAP).

> [!important] IC
> Pivot (loi sans $\theta$) → $P(|Z|\le q)=1-\alpha$ → isoler $\theta$ → Slutsky si $\theta$ reste dans la variance.

> [!important] Test RV
> $\ln R_n$ → $=g(S_n)$ monotone → loi de $S_n$ **sous $H_0$** → seuil → loi **sous $H_1$** → puissance.
> $H_0$ composite unilatère : seuil calculé à la frontière.
> Bilatère : $|S_n|$ et quantile $1-\alpha/2$.

## Pièges classiques
- Oublier l'indicatrice du support (uniforme) → MV faux.
- « Sans biais » = pour **tout** $\theta$.
- Un estimateur biaisé peut avoir un **plus petit** EQM.
- Quantile $1-\alpha$ (unilatère) vs $1-\alpha/2$ (bilatère).
- $R_n$ décroissant en $S_n$ ⇒ on rejette pour $S_n$ **petit**.
- IC : bornes ne doivent **pas** contenir $\theta$.
- Ne pas rejeter $H_0$ ≠ prouver $H_0$.
- Covariance nulle ⇒ indépendance **seulement** pour un vecteur gaussien.
