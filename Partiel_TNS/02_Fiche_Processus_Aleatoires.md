---
tags: [partiel, TNS, processus, 1A, fiche]
source: "[[Cours_TD_Processus_Signaux.pdf]] + notes amphi"
prof: E. Grivel
---

# Fiche 1A : processus & signaux aléatoires

> [!important] Priorité n°1 du partiel
> Les questions des anciens sujets sont citées entre crochets **[EXAM]**.

---

## 1. Variable aléatoire : rappels

- Densité : $p(x)\ge 0$, $\int p=1$. Répartition : $F(x)=P(X\le x)$, croissante de 0 à 1, $p=F'$, $P(x_1<X\le x_2)=F(x_2)-F(x_1)$.
- $E$ est **linéaire**. $\operatorname{Var}X=E[X^2]-E[X]^2$, $\operatorname{Var}(aX+b)=a^2\operatorname{Var}X$.
- Moment d'ordre $k$ : $E[X^k]$. Moment centré : $\mu_k=E[(X-E X)^k]$.
- Loi **symétrique** (autour de 0) ⇒ moments impairs nuls.
- Skewness (asymétrie) $S=\mu_3/\sigma^3$. Kurtosis (aplatissement) $K=\mu_4/\sigma^4-3$, qui vaut 0 pour une gaussienne.

### Gaussienne **[EXAM, à chaque fois]**
$$p(x)=\frac{1}{\sqrt{2\pi}\,\sigma}\exp\!\left(-\frac{(x-m)^2}{2\sigma^2}\right)$$
- $[m\pm\sigma]$ : **68,3 %**, $[m\pm2\sigma]$ : **95,4 %**, $[m\pm3\sigma]$ : **99,7 %**. Largeur à mi-hauteur $H=2{,}3548\,\sigma$.
- $X\sim N(m,\sigma^2)$ ⇒ $Y=aX+b\sim N(am+b,\ a^2\sigma^2)$, donc 95,4 % des valeurs de $Y$ sont dans $[am+b-2|a|\sigma,\ am+b+2|a|\sigma]$.
  - Exemple : $X\sim N(-3,2)$, $Y=4X-1$ ⇒ $m_Y=-13$, $\sigma_Y=4\sqrt2$ ⇒ $[-13-8\sqrt2;\,-13+8\sqrt2]\approx[-24{,}3;\,-1{,}7]$.
- Complexe circulaire : $p(x)=\frac{1}{\pi\sigma^2}\exp(-|x-m|^2/\sigma^2)$.
- Vecteur réel de dimension $N$ : $p(\mathbf x)=\frac{1}{(2\pi)^{N/2}|C|^{1/2}}\exp\!\big(-\tfrac12(\mathbf x-\mathbf m)^TC^{-1}(\mathbf x-\mathbf m)\big)$.
- Gaussiennes **décorrélées ⇒ indépendantes** (spécifique au cas gaussien). Toute transformation **linéaire** (filtrage) d'un processus gaussien donne un processus gaussien.

### Fonctions caractéristiques
- 1re : $\Phi_X(u)=E[e^{juX}]$, avec $E[X^k]=\dfrac{1}{j^k}\dfrac{d^k\Phi}{du^k}\Big|_{u=0}$.
- 2nde : $\Psi_X(u)=\ln\Phi_X(u)$, qui donne les **cumulants**. $\mathrm{Cum}_1$ = moyenne, $\mathrm{Cum}_2$ = variance, $\mathrm{Cum}_3$ = moment d'ordre 3 **si moyenne nulle**.

---

## 2. Processus aléatoire : définitions

- $X(\omega,t)$ : à **$t$ fixé**, c'est une **variable aléatoire** ; à **$\omega$ fixé**, c'est une **réalisation** (trajectoire).
- Temps continu/discret × états continus/discrets. Exemples du cours :
  - temps discret, états discrets : nombre d'appels par jour ;
  - temps continu, états discrets : nombre de clients dans un magasin ;
  - temps discret, états continus : temps d'attente au RU par jour ;
  - temps continu, états continus : débit d'un fleuve.
- Description **complète** = densités d'ordre $n$ pour tous les instants (inaccessible). En pratique, description **partielle à l'ordre 2** : moyenne + autocorrélation.

| Grandeur | Définition |
|---|---|
| Moyenne | $m_X(t)=E[X(t)]$ |
| Autocorrélation | $R_{XX}(t_1,t_2)=E[X(t_1)X^*(t_2)]=\iint x_1x_2^*\,p(x_1,x_2;t_1,t_2)\,dx_1dx_2$ |
| Autocovariance | $C_{XX}(t_1,t_2)=R_{XX}(t_1,t_2)-m_X(t_1)m_X^*(t_2)$ = autocorrélation du processus centré |
| Variance | $\sigma_X^2(t)=C_{XX}(t,t)$ |
| Coef. de corrélation | $r_{XX}=\dfrac{C_{XX}(t_1,t_2)}{\sqrt{C_{XX}(t_1,t_1)C_{XX}(t_2,t_2)}}\in[-1,1]$, vaut $\pm1$ ssi lien affine ; c'est l'autocovariance du processus normalisé $X/\sqrt{C_{XX}(t,t)}$ **[EXAM]** |
| Intercorrélation | $R_{XY}(t_1,t_2)=E[X(t_1)Y^*(t_2)]=R^*_{YX}(t_2,t_1)$ |

Propriétés :
- Symétrie hermitienne : $R(t_2,t_1)=R^*(t_1,t_2)$.
- $R(t,t)=E|X(t)|^2\ge0$, **réel** : c'est la puissance moyenne instantanée.
- Schwarz : $|R(t_1,t_2)|^2\le R(t_1,t_1)R(t_2,t_2)$.
- Processus **d'ordre 2** : $E|X(t)|^2<\infty$.

> [!warning] Indépendance, décorrélation, orthogonalité
> - **Indépendants ⇒ décorrélés** ($C_{XY}=0$). La **réciproque est fausse**, sauf pour des processus conjointement gaussiens.
> - **Orthogonaux** : $R_{XY}=E[XY^*]=0$. Décorrélés : $E[XY^*]=E[X]E[Y^*]$.
> - Si au moins l'un des deux est **centré**, décorrélés ⇔ orthogonaux.

---

## 3. Stationnarité & ergodicité

- **Stationnaire au sens strict (SSS)** : toutes les lois sont invariantes par translation dans le temps.
- **Stationnaire au sens large (SSL)** : (1) $m_X$ **constante** et (2) $R_{XX}(t_1,t_2)$ ne dépend que de $\tau=t_1-t_2$.
  - Convention du prof : $R_{XX}(\tau)=E[X(t+\tau)X^*(t)]$.
- SSS (d'ordre 2) ⇒ SSL. La **réciproque est fausse**, sauf si le processus est **gaussien**.
- **Conjointement SSL** : $X$ et $Y$ SSL **et** $R_{XY}$ ne dépend que de $\tau$.

Propriétés d'un processus SSL :
- $R(-\tau)=R^*(\tau)$, donc $R$ est **paire** si le processus est réel ;
- $|R(\tau)|\le R(0)$ (Schwarz) ;
- $R(0)=E|X|^2=\sigma^2+|m|^2$ (puissance) et $C(\tau)=R(\tau)-|m|^2$ ;
- si $R(T_0)=R(0)$, alors $R$ est **périodique** de période $T_0$ **[EXAM]**.

### Matrice de corrélation $R_M=E[\mathbf x\mathbf x^H]$ (processus SSL)
- **Toeplitz** (diagonales constantes), **hermitienne** ($R^H=R$), **semi-définie positive** ($\mathbf a^HR\mathbf a\ge0$ pour tout $\mathbf a$).
- Conséquences : valeurs propres **réelles ≥ 0**, diagonale $=R(0)$, $|R(k)|\le R(0)$. C'est le test standard pour vérifier qu'une matrice donnée « est bien une matrice de corrélation ».
- Covariance : $C=R-\mathbf m\mathbf m^H$.

### Ergodicité
- **Au sens de la moyenne** : moyenne temporelle = moyenne d'ensemble, au sens $\lim_{n\to\infty}E\big|\frac1n\sum X(k)-m\big|^2=0$.
- **Au sens de la covariance** : la covariance s'estime par moyenne temporelle **sur une seule réalisation**.
- En traitement du signal c'est souvent un **postulat**. Il permet de tout estimer à partir d'**une seule** réalisation (ex. : débruitage de parole).

---

## 4. Processus classiques (à savoir refaire)

| Processus | Moyenne | Corrélation / variance | SSL ? |
|---|---|---|---|
| **Bernoulli** $\pm1$ (probas $p$, $1-p$) | $2p-1$ | $\operatorname{Var}=4p(1-p)$ | oui (iid) |
| **Bruit blanc binaire** (Bernoulli, $p=\tfrac12$) | 0 | var 1 | oui |
| **Comptage** $c_n$ (nombre de +1) | | loi **binomiale** $C_n^rp^r(1-p)^{n-r}$ | non |
| **Marche aléatoire** $\sum_{k=n_0+1}^n\varepsilon(k)$ | $(2p-1)(n-n_0)$ | $\operatorname{Var}=4p(1-p)(n-n_0)$ croît sans fin | **non** |
| Marche équiprobable ($p=\tfrac12$) = **processus de Wiener discret** (mouvement brownien) | 0 | var $=n-n_0$ | **non** |
| $X(t)=A\sin(2\pi f_0t)$, $E[A]=0$ | 0 | $R=E[A^2]\sin(2\pi f_0t_1)\sin(2\pi f_0t_2)$ dépend de $t_1,t_2$ | **NON** |
| $Y(t)=A\sin(2\pi f_0t+\phi)$, $\phi\sim U[0,2\pi]$ indép. de $A$ | 0 | $R(\tau)=\dfrac{E[A^2]}{2}\cos(2\pi f_0\tau)$ | **OUI** |
| $\sum_iA_ie^{j2\pi f_it}$, $A_i$ indép., centrées, var $\sigma_i^2$ | 0 | $R(\tau)=\sum_i\sigma_i^2e^{j2\pi f_i\tau}$ | oui |
| $Ae^{j2\pi f n}+b(n)$, $A$ centrée, $b$ BBGC | 0 | $R(\tau)=E|A|^2e^{j2\pi f\tau}+\sigma_b^2\delta(\tau)$ | oui |
| **BBGC** (blanc gaussien centré) | 0 | $R(k)=\sigma^2\delta(k)$, DSP $=\sigma^2$ constante | oui |
| Blanc **non centré** (moy. $\mu$) | $\mu$ | $R(k)=\sigma^2\delta(k)+\mu^2$ | oui |

> [!example] Démo clé : $Y(t)=A\sin(2\pi f_0t+\phi)$
> $R(t_1,t_2)=E[A^2]\,E[\sin(2\pi f_0t_1+\phi)\sin(2\pi f_0t_2+\phi)]$ (indépendance)
> $=\frac{E[A^2]}{2}E[\cos(2\pi f_0(t_1-t_2))-\cos(2\pi f_0(t_1+t_2)+2\phi)]$.
> Le 2e terme a une espérance nulle car $\phi$ est uniforme sur $[0,2\pi]$. Il reste $\frac{E[A^2]}{2}\cos(2\pi f_0\tau)$ : SSL.
> **Pourquoi une phase uniforme ?** On n'a aucune information a priori sur la phase (origine des temps arbitraire), et c'est ce qui rend le processus stationnaire.

> [!example] Densité $p_A(a)=|a|$ sur $[-1,1]$ (sujets 2012 et 2013)
> $\int_{-1}^1|a|\,da=1$ : c'est bien une densité. $E[A]=0$ (densité paire), $E[A^2]=2\int_0^1a^3da=\tfrac12$, $\operatorname{Var}A=\tfrac12$.
> Donc $A\sin(2\pi f_0t)$ n'est **pas** SSL, et $A\sin(2\pi f_0t+\phi)$ est SSL avec $R(\tau)=\tfrac14\cos(2\pi f_0\tau)$.

- **BBGC** : **b**lanc (échantillons décorrélés, DSP plate), **g**aussien, **c**entré. Blanc ⇒ SSL. Blanc **et** gaussien ⇒ échantillons **indépendants**.
- Le bruit blanc à temps continu est une idéalisation : variance (puissance) infinie.

---

## 5. Modèles MA / AR / ARMA (amphi et TD)

On note $v(n)$ un bruit blanc de moyenne $\mu$ et de variance $\sigma^2$.

### MA($q$), moyenne ajustée (filtre RIF, « tout zéro »)
$$x(n)=\sum_{j=0}^{q}b_j\,v(n-j)$$
- $m_x=\mu\sum_jb_j$.
- $R_{xx}(\tau)=\sigma^2\sum_jb_jb_{j+|\tau|}+\mu^2\Big(\sum_jb_j\Big)^2$.
- Toujours **SSL**. Covariance **nulle pour $|\tau|>q$** (mémoire finie).

> [!tip] Méthode express pour $\sum_jb_jb_{j+\tau}$
> Écris les coefficients en ligne **avec les zéros** (ex. $t(n)=3v(n-1)+4v(n-3)+5v(n-4)$ donne $[0,3,0,4,5]$), décale la ligne de $\tau$ et fais le produit scalaire avec elle-même.
> Pour $\mu=\sigma^2=1$ : $m=12$, $R(0..4)=194,\ 164,\ 156,\ 159,\ 144$.
> Piège : si $\sum b_j=0$ (ex. $b(n)+3b(n-2)-4b(n-4)$), alors la moyenne est **nulle** même si $\mu\neq0$.

### AR($p$), autorégressif (filtre RII « tout pôle »)
$$x(n)=-\sum_{i=1}^{p}a_i\,x(n-i)+v(n),\qquad H(z)=\frac{1}{A(z)}=\frac{1}{1+\sum a_iz^{-i}}$$
- C'est une **prédiction linéaire** : $\hat x(n)=-\sum a_ix(n-i)$, et l'erreur de prédiction est $v(n)$.
- SSL si les **pôles sont dans le cercle unité**.
- **AR(1)** ($|a_1|<1$, $v$ centré) : $m=0$, $R(0)=\dfrac{\sigma^2}{1-a_1^2}$, $R(\tau)=-a_1R(\tau-1)$, donc $R(\tau)=\dfrac{\sigma^2(-a_1)^{|\tau|}}{1-a_1^2}$.
  - $a_1<0$ ($x(n)=+|a_1|x(n-1)+\dots$) : $R$ décroît exponentiellement (basse fréquence).
  - $a_1>0$ : $R$ alterne en signe (haute fréquence).
- $y(n)=-a_py(n-p)+v(n)$ : $R(\tau)=\dfrac{\sigma^2(-a_p)^{\tau/p}}{1-a_p^2}$ si $\tau$ est multiple de $p$, **0 sinon**.
- **Yule-Walker** (réel) : $R(\tau)+\sum_ia_iR(\tau-i)=0$ pour $\tau\ge1$, et $R(0)+\sum_ia_iR(i)=\sigma^2$.
- Méthode d'estimation (ordre, $a_p$, $\sigma^2$) : estimer $R$ (estimateur biaisé), repérer les retards non nuls (ce qui donne l'ordre $p$), puis $\hat a_p=-\hat R(p)/\hat R(0)$ et $\hat\sigma^2=\hat R(0)(1-\hat a_p^2)$.

### ARMA($p,q$)
$x(n)=-\sum a_ix(n-i)+\sum b_jv(n-j)$, avec $H(z)=B(z)/A(z)$.
- **DSP** (bruit blanc filtré) : $S_x(f)=\sigma^2|H(f)|^2=\sigma^2\dfrac{|B(e^{j2\pi f/f_e})|^2}{|A(e^{j2\pi f/f_e})|^2}$.
- **Pôles** proches du cercle : pics (résonances, formants de la parole). **Zéros** : creux.

---

## 6. Transformée de Karhunen-Loève **[EXAM]**

- Principe : décomposer $\mathbf x$ dans la base des **vecteurs propres** (orthonormés) de $R_x$, soit $\mathbf x=\sum_ik_i\boldsymbol\varphi_i$ avec $k_i=\boldsymbol\varphi_i^H\mathbf x$.
- Les coefficients sont **décorrélés** : $E[k_ik_j^*]=\lambda_i\delta_{ij}$.
- On garde les $M$ vecteurs associés aux **plus grandes** valeurs propres. L'erreur quadratique moyenne vaut alors $\xi=\sum_{\text{écartées}}\lambda_i$ : c'est l'approximation optimale au sens de l'EQM.
- Applications : compression, rehaussement/débruitage de parole, réduction de dimension (ACP), **blanchiment** ($A=\Lambda^{-1/2}U^H$ donne $E[A\mathbf x(A\mathbf x)^H]=I$).
- Si toutes les $\lambda$ sont égales, le nuage est isotrope (bruit blanc) : aucune direction privilégiée, et KL ne compresse rien.
- Signal $Ae^{j2\pi fn}+$BBGC sur $N$ points : $R=E|A|^2\mathbf s\mathbf s^H+\sigma_b^2I$. La plus grande valeur propre est $NE|A|^2+\sigma_b^2$, de vecteur propre $\mathbf s$ (qui donne la fréquence). Toutes les autres valent $\sigma_b^2$, ce qui donne la variance du bruit.

---

## 7. Estimation

### Autocorrélation (SSL + ergodique ; N échantillons $x(0..N-1)$) **[EXAM]**
| | Formule ($m\ge0$) | Biais | Variance |
|---|---|---|---|
| Non biaisé | $\hat R(m)=\dfrac{1}{N-m}\sum_{n=0}^{N-1-m}x(n+m)x^*(n)$ | $E\hat R=R$ | **grande** quand $m\to N$ (peu de termes) |
| Biaisé | $\tilde R(m)=\dfrac1N\sum_{n=0}^{N-1-m}x(n+m)x^*(n)$ | $E\tilde R=\big(1-\tfrac{|m|}N\big)R(m)$ : fenêtre **triangulaire**, **asymptotiquement** non biaisé | plus faible |
- $\tilde R=\frac{N-|m|}N\hat R$. Les retards observables vont de $-(N-1)$ à $N-1$.
- MATLAB : `xcorr(x,'biased')`, `xcorr(x,'unbiased')`. Bruit blanc gaussien : `randn`. Puis `mean`, `var`.
- Allure pour un bruit blanc de moyenne $\mu$ et de variance $\sigma^2$ : pic $\sigma^2+\mu^2$ en 0, plateau $\mu^2$ ailleurs. En **biaisé**, ce plateau devient un **triangle** qui décroît vers 0 en $\pm(N-1)$.

### Qualités d'un estimateur
- Biais $b=E[\hat\theta]-\theta$. Variance. **Consistance** : $\lim_{N\to\infty}P(|\hat\theta_N-\theta|<\varepsilon)=1$.

### Maximum de vraisemblance (MV) **[EXAM : démo à savoir]**
$\hat\theta_{MV}=\arg\max_\theta p(\mathbf y;\theta)$. On maximise la **log-vraisemblance**, ce qui revient au même car $\ln$ est croissant.
Observations iid $N(m,\sigma_0^2)$ :
$\ln p=-\frac N2\ln(2\pi\sigma_0^2)-\sum\frac{(y_i-m)^2}{2\sigma_0^2}$, puis $\frac{\partial}{\partial m}=\frac1{\sigma_0^2}\sum(y_i-m)=0$, d'où $\boxed{\hat m=\frac1N\sum y_i}$ (non biaisé, consistant).
Cas difficiles (données cachées) : **algorithme EM** (Expectation-Maximization).

### Moindres carrés (MC)
Modèle $Y=H\theta+V$, critère $J(\theta)=\|Y-H\theta\|^2$. On annule le gradient : $\frac{\partial J}{\partial\theta}=-2H^T(Y-H\theta)=0$, d'où
$$\boxed{\hat\theta=(H^TH)^{-1}H^TY}$$
(il faut $H^TH$ inversible). Application : estimation des paramètres AR, avec $H$ = matrice des échantillons passés.
**Biaisé si** : (1) $V$ est **corrélé** avec $H$, ou (2) $V$ est de **moyenne non nulle**.

### Moyenne et matrices empiriques (exos 5.2)
$\hat{\mathbf m}=\frac1N\sum\mathbf x(i)$, $\hat R=\frac1N\sum\mathbf x(i)\mathbf x(i)^H$, $\hat C=\hat R-\hat{\mathbf m}\hat{\mathbf m}^H$.

---

## 8. Chaînes de Markov à temps discret (CMTD)

- **Ordre 1** : $P(X_n\mid X_{n-1},X_{n-2},\dots)=P(X_n\mid X_{n-1})$. **Homogène** : les transitions ne dépendent pas de $n$.
- **Matrice stochastique** $P$ : $p_{ij}=P(X_{n+1}=j\mid X_n=i)$, avec **somme de chaque ligne = 1** et $0\le p_{ij}\le1$.
  - La matrice **de transition** du cours vaut $M=P^T$ (somme de chaque **colonne** = 1). **Lis toujours l'énoncé** pour savoir laquelle on te donne.
- Chapman-Kolmogorov : $p_{ij}(n+k)=\sum_kp_{ik}(k)p_{kj}(n)$. Régime transitoire : $\mathbf P(n)=\mathbf P(0)P^n$ (vecteur ligne), ou $\mathbf P(n)=M^n\mathbf P(0)$ (vecteur colonne).
- Temps de séjour dans un état : loi **géométrique**.
- **Irréductible** : tout état est accessible depuis tout état. Test : $(I+A)^{m}$ booléen (avec $m\le N-1$) rempli de 1, où $A$ est la matrice d'adjacence.
- **Période** $d(i)=\mathrm{pgcd}\{n:p_{ii}(n)>0\}$ = pgcd des longueurs des circuits. Si $d=1$, l'état est apériodique. Une **boucle** sur un état d'une chaîne irréductible la rend apériodique.
- $F_{ij}$ = probabilité d'atteindre $j$ **un jour** en partant de $i$. **[EXAM, démo]** En décomposant selon le 1er pas :
$$F_{ij}=p_{ij}+\sum_{k\neq j}p_{ik}F_{kj}$$
(soit on va directement en $j$, soit on passe par $k\neq j$ puis on atteint $j$ un jour).
  - $F_{ii}<1$ : **transitoire**. $F_{ii}=1$ : **récurrent** (non nul si le temps moyen de retour $\mu_{ii}$ est fini, nul sinon). $F_{ii}=0$ : **éphémère**.
  - Chaîne **irréductible finie** : tous les états sont récurrents non nuls, donc $F_{ij}=1$ pour tous $i,j$.
  - **Ergodique** = récurrent non nul **et** apériodique.
- **Régime permanent** : si la chaîne est irréductible, apériodique (et homogène, finie), alors $\mathbf P(n)\to\boldsymbol\pi$ **indépendamment de $\mathbf P(0)$**, avec
$$\boldsymbol\pi=\boldsymbol\pi P,\qquad\sum_i\pi_i=1.$$
  - Chaîne **périodique** : le système a une solution mais $\mathbf P(n)$ **ne converge pas**. $\pi_i$ s'interprète alors comme la **proportion du temps** passé dans l'état $i$ (ex. : cycle à 3 états, $\pi=(\frac13,\frac13,\frac13)$).
  - Temps moyen de retour : $\mu_{ii}=1/\pi_i$.
- Chaîne à 2 états, $P=\begin{pmatrix}1-a&a\\b&1-b\end{pmatrix}$ : $\boldsymbol\pi=\left(\frac{b}{a+b},\frac{a}{a+b}\right)$.
- Probabilité d'une suite : $P(x_0)\,p_{x_0x_1}\,p_{x_1x_2}\cdots$.

---

## Pièges (à relire le jour J)

> [!danger] Les 15 pièges classiques
> 1. Décorrélé ⇏ indépendant (sauf gaussien).
> 2. SSL ⇏ SSS (sauf gaussien) ; SSS ⇒ SSL.
> 3. Moyenne constante ne suffit pas pour SSL : il faut aussi $R(\tau)$.
> 4. $A\sin(2\pi f_0t)$ n'est **pas** SSL ; $A\sin(2\pi f_0t+\phi)$ avec $\phi$ uniforme **l'est**.
> 5. Marche aléatoire : moyenne nulle si $p=\frac12$, mais variance $n-n_0$, donc **non** stationnaire.
> 6. MA avec bruit non centré : $R(\tau)$ contient $+\mu^2(\sum b)^2$, et il ne tend **pas** vers 0.
> 7. $R(0)$ = puissance = variance + moyenne² (pas seulement la variance).
> 8. Pour un processus réel, $R$ est paire ; pour un complexe, elle est **hermitienne** : $R(-\tau)=R^*(\tau)$.
> 9. Matrice de corrélation : Toeplitz + hermitienne + **semi-définie positive** (valeurs propres ≥ 0).
> 10. L'estimateur en $1/N$ est **biaisé** (triangle), celui en $1/(N-|m|)$ est non biaisé mais a une plus grande variance.
> 11. Les MC sont biaisés si le bruit est corrélé aux régresseurs ou non centré.
> 12. KL : erreur = somme des valeurs propres **écartées** ; on garde les **plus grandes**.
> 13. $P$ stochastique : **lignes** de somme 1 ; $M=P^T$ : **colonnes** de somme 1.
> 14. Chaîne périodique : $\pi$ existe mais il n'y a **pas** de limite.
> 15. Blanc ⇒ décorrélé ; blanc **gaussien** ⇒ indépendant.
