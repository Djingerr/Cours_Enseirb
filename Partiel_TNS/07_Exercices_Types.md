---
tags: [partiel, TNS, exercices, 1A, 2A]
---

# Exercices types (style Grivel), avec corrigés

> [!tip] Règle d'or
> Fais chaque exercice **sur papier, sans corrigé, chronométré** (temps indiqué). Ensuite seulement, ouvre la correction. Si tu bloques plus de 3 min, regarde **uniquement la 1re ligne** du corrigé, puis repars.

---

# Partie 1A

## E1. Gaussiennes express (5 min)
Pour chaque cas : densité de $X$, puis l'intervalle contenant 95,4 % des valeurs de $Y$.
a) $X\sim N(0,1)$, $Y=3X+1$  b) $X\sim N(0,2)$, $Y=2X+1$  c) $X\sim N(2,3)$, $Y=4X-3$  d) $X\sim N(-3,2)$, $Y=4X-1$

> [!check]- Corrigé
> Règle : $m_Y=am+b$, $\sigma_Y=|a|\sigma$, intervalle $[m_Y\pm2\sigma_Y]$.
> a) $p(x)=\frac1{\sqrt{2\pi}}e^{-x^2/2}$ ; $Y\sim N(1,9)$, d'où $[-5;7]$.
> b) $p(x)=\frac1{\sqrt{4\pi}}e^{-x^2/4}$ ; $Y\sim N(1,8)$, d'où $[1-4\sqrt2;1+4\sqrt2]\approx[-4{,}66;6{,}66]$.
> c) $p(x)=\frac1{\sqrt{6\pi}}e^{-(x-2)^2/6}$ ; $Y\sim N(5,48)$, d'où $[5-8\sqrt3;5+8\sqrt3]\approx[-8{,}86;18{,}86]$.
> d) $p(x)=\frac1{\sqrt{4\pi}}e^{-(x+3)^2/4}$ ; $Y\sim N(-13,32)$, d'où $[-13-8\sqrt2;-13+8\sqrt2]\approx[-24{,}3;-1{,}7]$.

## E2. Processus MA (sujet 2015) (15 min)
$y(n)=b(n-1)+3b(n-2)+3b(n-3)+b(n-4)$, avec $b$ blanc de moyenne $\mu$ et de variance $\sigma^2$.
1. Moyenne et $R_{yy}(\tau)$ dans le cas général.
2. Valeurs de $R_{yy}(0..4)$ pour $\mu=\sigma^2=1$.
3. Le processus est-il SSL ?
4. Matrices de covariance de $[y(n),y(n-1)]^T$ et de $[y(n),\dots,y(n-3)]^T$ pour $\mu=\sigma^2=1$.

> [!check]- Corrigé
> 1. $m_y=\mu(1+3+3+1)=8\mu$. Avec $R_{bb}(k)=\sigma^2\delta(k)+\mu^2$ et les coefficients $[0,1,3,3,1]$ :
> $R_{yy}(\tau)=\sigma^2\sum_jb_jb_{j+|\tau|}+64\mu^2$, avec $\sum_jb_jb_j=20$, $\sum b_jb_{j+1}=3+9+3=15$, $\sum b_jb_{j+2}=3+3=6$, $\sum b_jb_{j+3}=1$, et 0 au-delà.
> 2. $R(0)=84$, $R(1)=79$, $R(2)=70$, $R(3)=65$, $R(4)=64$ (et 64 pour tous les $|\tau|\ge4$).
> 3. Oui : la moyenne est constante et $R$ ne dépend que de $\tau$. Un MA fini sur un bruit blanc est toujours SSL.
> 4. Covariance $C(\tau)=R(\tau)-m^2=20,15,6,1,0$. D'où $\begin{pmatrix}20&15\\15&20\end{pmatrix}$ et la matrice Toeplitz de première ligne $[20,15,6,1]$.

## E3. MA à moyenne nulle cachée (5 min)
$y(n)=b(n)+3b(n-2)-4b(n-4)$, avec $\mu=\sigma^2=1$. Moyenne, $R_{yy}(0..4)$, SSL ?

> [!check]- Corrigé
> $m_y=\mu(1+3-4)=0$ (piège : la moyenne est nulle alors que $\mu=1$). Coefficients $[1,0,3,0,-4]$ :
> $R(0)=1+9+16=26$, $R(1)=0$, $R(2)=1\cdot3+3\cdot(-4)=-9$, $R(3)=0$, $R(4)=1\cdot(-4)=-4$. Le terme $\mu^2(\sum b)^2$ est nul. Le processus est SSL.

## E4. AR(1) (15 min)
$x(n)=-a_1x(n-1)+v(n)$, avec $v$ BBGC de variance $\sigma^2$, $|a_1|<1$, processus supposé SSL.
1. Moyenne. 2. $R_{xx}(0)$ et une relation récursive sur $R_{xx}(\tau)$. 3. Matrice de corrélation de $[x(n),x(n-1),x(n-2)]^T$ pour $a_1=-\frac12$, $\sigma^2=2$.

> [!check]- Corrigé
> 1. $m=-a_1m+0$, d'où $m(1+a_1)=0$ et $m=0$.
> 2. $R(0)=E[x^2(n)]=a_1^2R(0)+\sigma^2$, car $v(n)$ est décorrélé de $x(n-1)$ (qui ne dépend que des $v$ passés). Donc $R(0)=\frac{\sigma^2}{1-a_1^2}$.
> Pour $\tau\ge1$ : $R(\tau)=E[x(n)x(n-\tau)]=-a_1R(\tau-1)$, d'où $R(\tau)=(-a_1)^{|\tau|}\frac{\sigma^2}{1-a_1^2}$.
> 3. $R(0)=2/0{,}75=8/3$, $R(1)=4/3$, $R(2)=2/3$, d'où $R=\frac83\begin{pmatrix}1&\frac12&\frac14\\\frac12&1&\frac12\\\frac14&\frac12&1\end{pmatrix}$ (Toeplitz, symétrique).

## E5. Stationnarité (sujets 2012-2013) (15 min)
$p_A(a)=|a|$ sur $[-1,1]$ (0 ailleurs). $X(t)=A\sin(2\pi f_0t)$ et $Y(t)=A\sin(2\pi f_0t+\phi)$, avec $\phi\sim U[0,2\pi]$ indépendante de $A$.
1. Vérifier que $p_A$ est une densité ; calculer $E[A]$, $E[A^2]$, $\operatorname{Var}A$.
2. $X$ est-il SSL ? 3. $Y$ est-il SSL ? Pourquoi choisir $\phi$ uniforme ?

> [!check]- Corrigé
> 1. $p_A\ge0$ et $\int_{-1}^1|a|da=2\cdot\frac12=1$. $E[A]=0$ (intégrande impaire). $E[A^2]=2\int_0^1a^3da=\frac12$, donc $\operatorname{Var}A=\frac12$.
> 2. $m_X(t)=E[A]\sin(\cdot)=0$, mais $R_X(t_1,t_2)=\frac12\sin(2\pi f_0t_1)\sin(2\pi f_0t_2)=\frac14[\cos2\pi f_0(t_1-t_2)-\cos2\pi f_0(t_1+t_2)]$ dépend de $t_1+t_2$ : **non SSL**.
> 3. $m_Y=E[A]E[\sin(\cdot+\phi)]=0$. $R_Y=E[A^2]\cdot\frac12E[\cos2\pi f_0\tau-\cos(2\pi f_0(t_1+t_2)+2\phi)]=\frac14\cos(2\pi f_0\tau)$ : **SSL**. La phase uniforme traduit l'absence d'information a priori (origine des temps arbitraire), et c'est elle qui « moyenne » le terme en $t_1+t_2$.

## E6. Estimateurs de l'autocorrélation (sujet 2012) (10 min)
$v(n)$ blanc de moyenne $\mu=2$ et de variance $\sigma^2=3$, avec $N$ échantillons.
1. $R_{vv}(\tau)$ théorique. 2. Expressions et biais des deux estimateurs. 3. Allure de leur espérance, et intervalle de $\tau$.

> [!check]- Corrigé
> 1. $R(\tau)=3\delta(\tau)+4$ : pic de 7 en 0, plateau de 4 ailleurs.
> 2. Non biaisé : $\hat R(\tau)=\frac1{N-|\tau|}\sum_{n=0}^{N-1-|\tau|}v(n+\tau)v(n)$, avec $E\hat R=R$. Biaisé : $\tilde R(\tau)=\frac1N\sum\dots$, avec $E\tilde R=(1-\frac{|\tau|}N)R(\tau)$, asymptotiquement non biaisé. Conditions : processus SSL et ergodique.
> 3. $\tau\in[-(N-1),N-1]$. Non biaisé : 7 en 0 et 4 partout ailleurs (de plus en plus bruité quand $|\tau|\to N$). Biaisé : 7 en 0, puis un **triangle** $4(1-|\tau|/N)$ qui tombe à ≈ 0 en $\pm(N-1)$. MATLAB : `xcorr(v,'unbiased')`, `xcorr(v,'biased')`.

## E7. Maximum de vraisemblance (démo de cours) (8 min)
Observations $y_1..y_N$ indépendantes, $N(m,\sigma_0^2)$ avec $\sigma_0^2$ connue. Estimer $m$ au sens du MV. Bonus : estimer $\sigma^2$ si $m$ est connue.

> [!check]- Corrigé
> $p(\mathbf y;m)=\prod_i\frac1{\sqrt{2\pi}\sigma_0}e^{-(y_i-m)^2/2\sigma_0^2}$. Log-vraisemblance : $L=-\frac N2\ln(2\pi\sigma_0^2)-\frac1{2\sigma_0^2}\sum(y_i-m)^2$.
> $\frac{\partial L}{\partial m}=\frac1{\sigma_0^2}\sum(y_i-m)=0$, d'où $\hat m=\frac1N\sum y_i$. La dérivée seconde $-N/\sigma_0^2<0$ confirme un maximum. Cet estimateur est non biaisé et consistant.
> Bonus : $\frac{\partial L}{\partial\sigma^2}=-\frac N{2\sigma^2}+\frac{1}{2\sigma^4}\sum(y_i-m)^2=0$, d'où $\hat\sigma^2=\frac1N\sum(y_i-m)^2$.

## E8. Karhunen-Loève (cours §2.9.2) (15 min)
$R_{xx}(0)=3$, $R_{xx}(1)=2$, $R_{xx}(2)=1$, vecteur de 3 échantillons.
1. Matrice $R$ et ses valeurs propres. 2. EQM si $\hat{\mathbf x}=k_1\boldsymbol\varphi_1$ (plus grande $\lambda$) ; EQM si $\hat{\mathbf x}=k_2\boldsymbol\varphi_2+k_3\boldsymbol\varphi_3$. Laquelle préférer ?

> [!check]- Corrigé
> $R=\begin{pmatrix}3&2&1\\2&3&2\\1&2&3\end{pmatrix}$. Vecteur antisymétrique $(1,0,-1)$ : $\lambda=3-1=2$. Vecteurs symétriques $(1,x,1)$ : $4+2x=\lambda$ et $4+3x=\lambda x$, d'où $2x^2+x-4=0$ et $x=\frac{-1\pm\sqrt{33}}4$, soit $\lambda=\frac{7\pm\sqrt{33}}{2}\approx6{,}37$ et $0{,}63$. Vérification : la somme vaut la trace, 9.
> EQM = somme des $\lambda$ écartées. Avec $\varphi_1$ seul : $2+0{,}63\approx2{,}63$. Avec $\varphi_2,\varphi_3$ : $\approx6{,}37$. On préfère donc **un seul** vecteur, celui de la plus grande valeur propre : il porte 71 % de la puissance.

## E9. Moyenne et matrices empiriques (exo 5.2.1) (10 min)
$\mathbf x(1)=(1,0)^T$, $\mathbf x(2)=(-2,1)^T$, $\mathbf x(3)=(2,-2)^T$, $\mathbf x(4)=(0,2)^T$. Calculer $\hat{\mathbf m}$, $\hat R$, $\hat C$ et vérifier $\hat C=\hat R-\hat{\mathbf m}\hat{\mathbf m}^T$.

> [!check]- Corrigé
> $\hat{\mathbf m}=\frac14(1,1)^T$. $\hat R=\frac14\sum\mathbf x\mathbf x^T=\frac14\begin{pmatrix}9&-6\\-6&9\end{pmatrix}=\begin{pmatrix}9/4&-3/2\\-3/2&9/4\end{pmatrix}$.
> $\hat C=\hat R-\frac1{16}\begin{pmatrix}1&1\\1&1\end{pmatrix}=\frac1{16}\begin{pmatrix}35&-25\\-25&35\end{pmatrix}$. Si les données sont gaussiennes, $p(\mathbf x)=\frac{1}{2\pi|\hat C|^{1/2}}e^{-\frac12(\mathbf x-\hat{\mathbf m})^T\hat C^{-1}(\mathbf x-\hat{\mathbf m})}$.

## E10. Markov : vente de voitures (exo 5.3.4) (20 min)
Classe 1 : 60 % restent, 40 % passent en 2. Classe 2 : 20 % passent en 1, 60 % restent, 20 % passent en 3. Classe 3 : 40 % passent en 2, 60 % restent.
1. Matrice stochastique, graphe. 2. Répartition après 3 achats pour la France $(0{,}5;0{,}3;0{,}2)$ et les USA $(0{,}1;0{,}6;0{,}3)$. 3. Régime permanent.

> [!check]- Corrigé
> 1. $P=\begin{pmatrix}0{,}6&0{,}4&0\\0{,}2&0{,}6&0{,}2\\0&0{,}4&0{,}6\end{pmatrix}$ (lignes de somme 1).
> 2. $\mathbf P(3)=\mathbf P(0)P^3$. France : $(0{,}283;\ 0{,}498;\ 0{,}218)$. USA : $(0{,}228;\ 0{,}501;\ 0{,}271)$.
> 3. La chaîne est irréductible et apériodique (boucles), donc il y a une limite unique. On résout $\pi=\pi P$ : $\pi_1=0{,}6\pi_1+0{,}2\pi_2$ donne $\pi_2=2\pi_1$ ; par symétrie $\pi_3=\pi_1$ ; avec $\sum=1$ : $\boldsymbol\pi=(\frac14,\frac12,\frac14)$. Les deux pays convergent vers la **même** répartition (indépendance vis-à-vis de $\mathbf P(0)$).

## E11. Démo $F_{ij}$ (sujets 2011-2015, à savoir par cœur) (5 min)
Démontrer $F_{ij}=p_{ij}+\sum_{k\neq j}p_{ik}F_{kj}$, donner le sens des notations, et interpréter $F_{ii}=1$ et $F_{ii}<1$.

> [!check]- Corrigé
> $F_{ij}$ = probabilité d'atteindre $j$ **au moins une fois** en partant de $i$ ; $p_{ij}$ = probabilité de transition en un pas.
> On conditionne sur le premier pas $X_1$. Si $X_1=j$ (probabilité $p_{ij}$), c'est atteint. Si $X_1=k\neq j$ (probabilité $p_{ik}$), il reste à atteindre $j$ depuis $k$ (probabilité $F_{kj}$, par la propriété de Markov et l'homogénéité). La formule des probabilités totales donne le résultat.
> $F_{ii}=1$ : état **récurrent** (on y revient sûrement). $F_{ii}<1$ : **transitoire**. Chaîne irréductible finie : $F_{ij}=1$ pour tous $i,j$.

## E12. Signaux continus (15 min)
1. $\mathrm{TF}$ de $x(t)=\Pi_T(t-T/2)$ ; module et phase.
2. $\Pi_T*\Pi_T$ : allure.
3. Autocorrélation et densité spectrale d'énergie de $\Pi_T$.
4. $x(t)=3+2\cos(2\pi f_0t)+\sin(6\pi f_0t)$ : coefficients $c_k$, spectre d'amplitude, puissance.

> [!check]- Corrigé
> 1. $X(f)=T\,\mathrm{sinc}(\pi fT)e^{-j\pi fT}$ : $|X|=T|\mathrm{sinc}(\pi fT)|$ et une phase linéaire $-\pi fT$ (plus des sauts de $\pi$ là où le sinc change de signe).
> 2. Un triangle de base $[-T,T]$ et de hauteur $T$ (les durées s'additionnent).
> 3. $R_{xx}=\Pi_T*\Pi_T$ (signal réel pair), c'est-à-dire le même triangle. Sa TF vaut $T^2\mathrm{sinc}^2(\pi fT)=|X|^2$ (Wiener-Khintchine).
> 4. $c_0=3$, $c_{\pm1}=1$, $c_{\pm3}=\mp\frac j2$ (car $\sin=\frac{e^{j\cdot}-e^{-j\cdot}}{2j}$), d'où des raies d'amplitude 3 en 0, 1 en $\pm f_0$, ½ en $\pm3f_0$. $P=9+1+1+\frac14+\frac14=11{,}5$ (vérification : $9+\frac{4}{2}+\frac12=11{,}5$).

---

# Partie 2A (TD traité : 1.1 à 1.5)

## F1. Méthode du TD 1.1 (schéma → tout le reste) (10 min)
Schéma décrit : $x(n)$ entre dans un sommateur, dont la sortie est $y(n)$ ; $y(n)$ repasse par un retard $z^{-1}$, puis est multipliée par $a$ et réinjectée dans le sommateur. Donner l'équation aux différences, $H(z)$, la causalité, la nature RIF/RII (justifiée de plusieurs façons), $h(n)$ et un schéma équivalent.

> [!check]- Corrigé
> Équation : $y(n)=x(n)+a\,y(n-1)$. $H(z)=\frac1{1-az^{-1}}$. Le filtre est causal (seulement présent et passé).
> RII, pour trois raisons : (i) la sortie dépend des sorties passées (récursif) ; (ii) $h(n)=a^nu(n)$ est infinie ; (iii) il y a un pôle en $z=a\neq0$, non compensé.
> Stable ⇔ $|a|<1$. Schéma équivalent : la forme non récursive infinie $y(n)=\sum_{k\ge0}a^kx(n-k)$.
> **Checklist à appliquer à chaque schéma** : (1) nommer les nœuds intermédiaires ($t(n)$…) ; (2) écrire une équation par sommateur ; (3) éliminer les variables intermédiaires ; (4) passer en $z$ ; (5) causalité = pas de $z^{+k}$ ; (6) RIF/RII par trois arguments ; (7) premiers $h(n)$ par récurrence avec $x=\delta$.

## F2. TD 1.2 : TF, TFD, FFT (10 min)
$N=100$, $f_e=500$ Hz. 1. TF du signal à temps discret. 2. TFD. 3. Fréquences observées utiles pour la puissance dans 30-58 Hz. 4. Choix possibles pour une FFT.

> [!check]- Corrigé
> 1. $X(f)=\sum_{k=0}^{99}x(k)e^{-j2\pi kf/f_e}$, périodique de période 500 Hz.
> 2. $X(m)=\sum_{k=0}^{99}x(k)e^{-j2\pi km/100}$, $m=0..99$, aux fréquences $f_m=5m$ Hz.
> 3. **30, 35, 40, 45, 50, 55 Hz** ($m=6..11$), et pour un signal réel aussi $m=89..94$ (de −55 à −30 Hz). Ce sont des valeurs de fréquences, pas une bande.
> 4. (a) Zero-padding à 128 : pas de 3,906 Hz, fréquences 31,25 ; 35,16 ; 39,06 ; 42,97 ; 46,88 ; 50,78 ; 54,69 Hz. Aucune information perdue, mais la grille est décalée et il n'y a pas de gain de résolution. (b) Troncature à 64 : pas de 7,81 Hz, fréquences 31,25 ; 39,06 ; 46,88 ; 54,69 Hz. Les calculs sont plus rapides, mais on perd des échantillons et de la résolution.

## F3. TD 1.3 : analyse d'une sinusoïde (15 min)
$x(k)=\cos(2\pi kf_0/f_e)$, $k=0..99$. $X(z)$, $X(f)$, $|X(f)|$, allure, zero-padding.

> [!check]- Corrigé
> $X(z)=\frac12\frac{1-e^{j2\pi Nf_0/f_e}z^{-N}}{1-e^{j2\pi f_0/f_e}z^{-1}}+\frac12\frac{1-e^{-j2\pi Nf_0/f_e}z^{-N}}{1-e^{-j2\pi f_0/f_e}z^{-1}}$ (somme géométrique).
> $X(f)=\frac12e^{-j\pi(N-1)\frac{f-f_0}{f_e}}\frac{\sin(\pi N(f-f_0)/f_e)}{\sin(\pi(f-f_0)/f_e)}+\frac12e^{-j\pi(N-1)\frac{f+f_0}{f_e}}\frac{\sin(\pi N(f+f_0)/f_e)}{\sin(\pi(f+f_0)/f_e)}$.
> Allure : deux noyaux de Dirichlet centrés en $\pm f_0$, de hauteur $N/2=50$, de lobe principal de largeur $2f_e/N$ (zéros en $f_0\pm kf_e/N$), avec des lobes secondaires à −13 dB. Le tout est périodique de période $f_e$.
> Zero-padding : ajouter **28** zéros pour $N=128$ ; on observe les fréquences $kf_e/128$ (on échantillonne plus finement la **même** courbe).

## F4. TD 1.4 : deux RIF (15 min)
(a) $y(n)=x(n)+0{,}9x(n-1)+0{,}81x(n-2)$  (b) $y(n)=x(n)+x(n-1)+x(n-2)$

> [!check]- Corrigé
> (a) $H=1+0{,}9z^{-1}+0{,}81z^{-2}$, $h=\{1;0{,}9;0{,}81\}$, RIF, causal, stable. Double pôle en 0, zéros $0{,}9e^{\pm j2\pi/3}$. $|H(0)|=2{,}71$, $|H(\pm f_e/3)|\approx0{,}16$ (minimum, sans annulation totale), $|H(f_e/2)|=0{,}91$.
> (b) $H=1+z^{-1}+z^{-2}=e^{-j2\pi f/f_e}(1+2\cos(2\pi f/f_e))$, $h=\{1;1;1\}$ (moyenneur/peigne), RIF, causal, stable. Zéros $e^{\pm j2\pi/3}$ **sur** le cercle : $|H(\pm f_e/3)|=0$, $|H(0)|=3$, $|H(f_e/2)|=1$. Phase linéaire (symétrique, retard de 1 échantillon).

## F5. TD 1.5 : un RII du 2e ordre (15 min)
$y(n)=0{,}8y(n-1)-0{,}64y(n-2)+x(n)$.

> [!check]- Corrigé
> $H(z)=\frac{1}{1-0{,}8z^{-1}+0{,}64z^{-2}}$. Premiers termes (récurrence avec $x=\delta$) : $h=1;\ 0{,}8;\ 0;\ -0{,}512;\ -0{,}4096;\ 0;\ 0{,}262\dots$
> Pôles : $z^2-0{,}8z+0{,}64=0$, d'où $z=0{,}4\pm j0{,}693=0{,}8e^{\pm j\pi/3}$. Double zéro en 0.
> Le filtre est causal, RII (pôles non nuls), et stable ($|p|=0{,}8<1$ ; triangle : $|a_2|=0{,}64<1$ et $|a_1|=0{,}8<1{,}64$).
> $|H|$ : 1,19 en 0, une résonance ≈ 3,2 vers $\pm f_e/6$, 0,41 en $f_e/2$.

## F6. TD 1.7 : DSP d'un AR(2) et d'un ARMA (10 min)
AR : $a_1=0{,}8$, $a_2=0{,}64$. ARMA : même structure avec $a_1=0{,}7$, $a_2=0{,}49$ et une partie MA $1+z^{-1}+z^{-2}$.

> [!check]- Corrigé
> AR : $A(z)=1+0{,}8z^{-1}+0{,}64z^{-2}$, pôles $0{,}8e^{\pm j2\pi/3}$. $S_y(f)=\frac{\sigma_u^2}{|A(e^{j2\pi f/f_e})|^2}$ présente un **pic** vers $\pm f_e/3$ (signal à « formant »).
> ARMA : pôles $0{,}7e^{\pm j2\pi/3}$ et zéros $e^{\pm j2\pi/3}$ **sur** le cercle, au **même angle**. Le zéro l'emporte : $S_y(\pm f_e/3)=0$ exactement (un creux là où l'AR seul aurait un pic). On a ≈ 1,88 $\sigma_u^2$ en $f=0$ et ≈ 1,6 $\sigma_u^2$ en $f_e/2$.

## F7. TD 1.8 : réjecteur (10 min)
Rejeter très sélectivement ±1000 Hz avec $f_e=10$ kHz. Donner $H(z)$ et l'équation aux différences.

> [!check]- Corrigé
> $\theta_0=2\pi\cdot1000/10000=\pi/5$. Zéros $e^{\pm j\pi/5}$ (réjection totale), pôles $re^{\pm j\pi/5}$ avec $r=0{,}95$ par exemple (sélectivité, stabilité).
> $H(z)=\frac{1-2\cos\frac\pi5z^{-1}+z^{-2}}{1-2r\cos\frac\pi5z^{-1}+r^2z^{-2}}\approx\frac{1-1{,}618z^{-1}+z^{-2}}{1-1{,}537z^{-1}+0{,}9025z^{-2}}$.
> $y(n)=x(n)-1{,}618x(n-1)+x(n-2)+1{,}537y(n-1)-0{,}9025y(n-2)$.

## F8. TD 1.10 : triangle de stabilité (10 min)
$H(z)=\frac1{1+a_1z^{-1}+a_2z^{-2}}$, avec $a_1,a_2$ réels.

> [!check]- Corrigé
> $p_{1,2}=\frac{-a_1\pm\sqrt{a_1^2-4a_2}}2$ : réels si $a_1^2\ge4a_2$, complexes conjugués sinon, de module $\sqrt{a_2}$ et d'angle $\pm\arccos\frac{-a_1}{2\sqrt{a_2}}$.
> Stable ⇔ $|a_2|<1$ et $|a_1|<1+a_2$ : triangle de sommets $(-2,1)$, $(2,1)$, $(0,-1)$. La parabole $a_2=a_1^2/4$ sépare les pôles complexes (au-dessus) des pôles réels (en dessous). Plus on monte vers $a_2=1$, plus le module $\sqrt{a_2}$ approche 1 et plus la résonance est aiguë.

## F9. TD 1.13 : $G(z)=H(-z^2)$ (10 min)
$H(z)=\frac{1+b_1z^{-1}}{1+a_1z^{-1}+a_2z^{-2}}$, avec $b_1=1$, $a_1=0$, $a_2=-\frac14$.

> [!check]- Corrigé
> Q1 : $y(n)=x(n)+b_1x(n-1)-a_1y(n-1)-a_2y(n-2)$, un filtre **RII** (récursif, pôles non nuls non simplifiés).
> Ici $H(z)=\frac{1+z^{-1}}{1-\frac14z^{-2}}=\frac{1+z^{-1}}{(1-\frac12z^{-1})(1+\frac12z^{-1})}$. Pôles $\pm\frac12$, dans le disque : le filtre est **stable**. Le zéro $-1$ ne simplifie aucun pôle.
> Par éléments simples : $H=\frac{3/2}{1-\frac12z^{-1}}-\frac{1/2}{1+\frac12z^{-1}}$, d'où $h(k)=\big[\frac32(\frac12)^k-\frac12(-\frac12)^k\big]u(k)$ (vérification : $h(0)=1$, $h(1)=1$, $h(2)=\frac14$, $h(3)=\frac14$).
> En général, $G(z)=\sum h(k)(-z^2)^{-k}=\sum(-1)^kh(k)z^{-2k}$, d'où $g(2k)=(-1)^kh(k)$ et $g(\text{impair})=0$.
> Ici $G(z)=\frac{1-z^{-2}}{1-\frac14z^{-4}}$ (car $(-z^2)^{-2}=z^{-4}$), d'où l'équation $y(n)=x(n)-x(n-2)+\frac14y(n-4)$. Les 5 premiers termes non nuls sont $g(0)=1$, $g(2)=-1$, $g(4)=\frac14$, $g(6)=-\frac14$, $g(8)=\frac1{16}$.

## F10. Bilinéaire avec pré-distorsion (5 min)
On veut un passe-bas numérique de coupure 1 kHz pour $f_e=8$ kHz, par la bilinéaire. Quelle coupure donner au prototype analogique ?

> [!check]- Corrigé
> $f_a=\frac{f_e}{\pi}\tan\left(\frac{\pi f_d}{f_e}\right)=\frac{8000}{\pi}\tan\frac\pi8\approx1055$ Hz. Sans pré-distorsion, la coupure numérique obtenue serait **inférieure** à 1 kHz (compression des fréquences par l'arctangente).
