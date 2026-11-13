---
tags: [stats, quiz, regression]
---
# Quiz 2 — Régression linéaire (≈ 25 min)

Chapitre : [[Stats 06 - Régression linéaire]] · Retour : [[00 - Stats Sommaire]]

> [!info] Règles
> Sur 15. **≥ 12** → [[Stats TD2 - Régression linéaire (corrigé)|TD2]].

1. Écrire le modèle matriciel et la taille de chaque objet. Que contient la 1ère colonne de $X$ ?
2. Énoncer les hypothèses de Gauss–Markov.
3. Donner les équations normales et $\hat\beta$.
4. Pourquoi $X^TX$ est-elle inversible ?
5. Que vaut $H=X(X^TX)^{-1}X^T$ géométriquement ? Donner $H^2$, $H^T$, $\text{tr}(H)$.
6. Montrer en une ligne que le résidu vaut $(I-H)\varepsilon$.
7. Biais et matrice de covariance de $\hat\beta$ ?
8. Risque quadratique de $\hat\beta$ ?
9. Pourquoi divise-t-on par $n-p-1$ dans $\hat\sigma^2$ ?
10. Énoncer Gauss–Markov en une phrase. Que veut dire BLUE ?
11. Dans la preuve de Gauss–Markov, à quelle condition matricielle équivaut « $Ay$ sans biais » ?
12. Énoncer $SST=SSR+SSE$ et donner l'argument clé.
13. Cas gaussien : loi de $(n-p-1)\hat\sigma^2/\sigma^2$ ?
14. Pourquoi $\hat\beta$ et $\hat\sigma^2$ sont-ils indépendants ?
15. Donner l'IC de niveau $1-\alpha$ pour $\beta_k$.

---
> [!success]- Correction
> 1. $y=X\beta+\varepsilon$ ; $y,\varepsilon\in\mathbb R^n$, $X\in\mathbb R^{n\times(p+1)}$, $\beta\in\mathbb R^{p+1}$. 1ère colonne : des 1 (constante $\beta_0$).
> 2. $\text{rg}X=p+1$ ; $\mathbb E\varepsilon=0$, $\mathbb E\varepsilon\varepsilon^T=\sigma^2I$.
> 3. $X^TX\beta=X^Ty$, $\hat\beta=(X^TX)^{-1}X^Ty$.
> 4. $X^TXv=0\Rightarrow\|Xv\|^2=0\Rightarrow v=0$ (rang plein).
> 5. Projecteur orthogonal sur $\text{Im}X$ ; $H^2=H=H^T$ ; $\text{tr}H=p+1$.
> 6. $(I-H)y=(I-H)X\beta+(I-H)\varepsilon$ et $HX=X$.
> 7. Sans biais ; $\sigma^2(X^TX)^{-1}$.
> 8. $\sigma^2\text{tr}\big((X^TX)^{-1}\big)$.
> 9. $\mathbb E\|r\|^2=\sigma^2\text{tr}(I-H)=\sigma^2(n-p-1)$ ⇒ sans biais.
> 10. Parmi les estimateurs linéaires sans biais, $\hat\beta$ a la plus petite covariance (au sens $\succeq$). *Best Linear Unbiased Estimator*.
> 11. $AX=I_{p+1}$.
> 12. $\|y-\bar y\mathbf1\|^2=\|y-X\hat\beta\|^2+\|X\hat\beta-\bar y\mathbf1\|^2$ ; Pythagore car $r\perp\text{Im}X\ni X\hat\beta-\bar y\mathbf1$ ($\mathbf1\in\text{Im}X$).
> 13. $\chi^2(n-p-1)$.
> 14. Gaussiens conjointement et covariance croisée $\sigma^2(X^TX)^{-1}X^T(I-H)=0$.
> 15. $\hat\beta_k\pm t_{n-p-1,1-\alpha/2}\,\hat\sigma\sqrt{[(X^TX)^{-1}]_{kk}}$.
