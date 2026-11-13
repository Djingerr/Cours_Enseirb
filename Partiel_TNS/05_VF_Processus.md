---
tags: [partiel, TNS, processus, 1A, vrai-faux]
---

# Vrai/Faux : processus aléatoires, estimation, Markov (1A) · 70 questions

> [!tip] C'est le fichier le plus rentable
> Fais-le **trois fois** : J-4 (tout), J-2 (seulement les erreurs), J-1 (tout, en chrono, ≤ 25 min). Écris V/F **+ justification** avant d'ouvrir la réponse.

## A. Variables aléatoires & gaussienne

**1.** Si $X\sim N(0,1)$, environ 95,4 % des valeurs de $Y=3X+1$ sont dans $[-5;7]$.
> [!check]- Réponse
> **VRAI**. $Y\sim N(1,9)$, $\sigma_Y=3$, donc $[1-6;1+6]=[-5;7]$.

**2.** Si $X\sim N(2,3)$, alors $Y=4X-3\sim N(5,12)$.
> [!check]- Réponse
> **FAUX**. La moyenne vaut bien $4\cdot2-3=5$, mais la variance vaut $4^2\cdot3=48$ (et non 12). $\operatorname{Var}(aX+b)=a^2\operatorname{Var}X$.

**3.** Pour une gaussienne, 99,7 % des valeurs sont dans $[m-3\sigma,m+3\sigma]$.
> [!check]- Réponse
> **VRAI**. 68,3 / 95,4 / 99,7 %.

**4.** La largeur à mi-hauteur d'une gaussienne vaut $2\sigma$.
> [!check]- Réponse
> **FAUX**. Elle vaut $2{,}3548\,\sigma=2\sqrt{2\ln2}\,\sigma$.

**5.** La fonction de répartition $F$ est croissante, vaut 0 en $-\infty$ et 1 en $+\infty$, et sa dérivée est la densité.
> [!check]- Réponse
> **VRAI**.

**6.** Si la loi de $X$ est symétrique par rapport à 0, tous ses moments d'ordre impair sont nuls.
> [!check]- Réponse
> **VRAI** (s'ils existent).

**7.** Le kurtosis normalisé $\mu_4/\sigma^4-3$ d'une gaussienne vaut 3.
> [!check]- Réponse
> **FAUX**. Il vaut **0** : c'est $\mu_4/\sigma^4$ qui vaut 3, et le « −3 » sert justement à centrer sur la gaussienne.

**8.** La première fonction caractéristique est $\Phi_X(u)=E[e^{juX}]$, et ses dérivées en 0 donnent les moments.
> [!check]- Réponse
> **VRAI**. $E[X^k]=\frac1{j^k}\Phi^{(k)}(0)$.

**9.** Les cumulants s'obtiennent à partir du logarithme de la première fonction caractéristique.
> [!check]- Réponse
> **VRAI**. C'est la seconde fonction caractéristique $\Psi=\ln\Phi$.

**10.** Le cumulant d'ordre 2 est égal au moment d'ordre 2.
> [!check]- Réponse
> **FAUX**. $\mathrm{Cum}_2$ = **variance** = $E[X^2]-E[X]^2$. Il n'est égal au moment d'ordre 2 que si la moyenne est nulle.

**11.** $p_A(a)=|a|$ pour $a\in[-1,1]$ (0 ailleurs) est une densité de probabilité, et $E[A^2]=1/2$.
> [!check]- Réponse
> **VRAI**. $\int_{-1}^1|a|da=1$ et $E[A^2]=2\int_0^1a^3da=\frac12$.

## B. Définitions processus, corrélations

**12.** À réalisation $\omega$ fixée, $X(\omega,t)$ est une variable aléatoire.
> [!check]- Réponse
> **FAUX**. À $\omega$ fixé, c'est une **fonction du temps** (réalisation, trajectoire). C'est à $t$ fixé qu'on a une variable aléatoire.

**13.** Le nombre de clients présents dans un magasin en fonction du temps est un processus à temps continu et à états discrets.
> [!check]- Réponse
> **VRAI**.

**14.** La moyenne et la fonction d'autocorrélation suffisent toujours à caractériser complètement un processus aléatoire.
> [!check]- Réponse
> **FAUX**. C'est une description **partielle** (ordre 2). Elle n'est complète que pour un processus **gaussien**.

**15.** $C_{XX}(t_1,t_2)=R_{XX}(t_1,t_2)-m_X(t_1)m_X^*(t_2)$.
> [!check]- Réponse
> **VRAI**.

**16.** La fonction d'autocovariance d'un processus est la fonction d'autocorrélation du processus centré.
> [!check]- Réponse
> **VRAI**.

**17.** $R_{XX}(t,t)$ est un nombre réel positif, même si le processus est complexe.
> [!check]- Réponse
> **VRAI**. $E|X(t)|^2\ge0$ : c'est la puissance moyenne instantanée.

**18.** Pour un processus complexe, $R_{XX}(t_2,t_1)=R_{XX}(t_1,t_2)$.
> [!check]- Réponse
> **FAUX**. $R_{XX}(t_2,t_1)=R^*_{XX}(t_1,t_2)$ (symétrie hermitienne).

**19.** Deux processus indépendants sont décorrélés.
> [!check]- Réponse
> **VRAI**.

**20.** Deux processus décorrélés sont indépendants.
> [!check]- Réponse
> **FAUX** en général. C'est vrai s'ils sont **conjointement gaussiens**.

**21.** Deux processus orthogonaux sont forcément décorrélés.
> [!check]- Réponse
> **FAUX**. Orthogonal signifie $E[XY^*]=0$, décorrélé signifie $E[XY^*]=E[X]E[Y^*]$. Les deux coïncident seulement si l'un des deux est **centré**.

**22.** Le coefficient de corrélation $r_{XX}(t_1,t_2)$ vaut $\pm1$ lorsque $X(t_1)=aX(t_2)+b$.
> [!check]- Réponse
> **VRAI**.

**23.** Le coefficient de corrélation de $X$ est égal à la fonction d'autocovariance du processus normalisé $X(t)/\sqrt{C_{XX}(t,t)}$.
> [!check]- Réponse
> **VRAI**. C'est une question de cours déjà tombée.

## C. Stationnarité & ergodicité

**24.** Un processus SSL a une moyenne constante et une autocorrélation qui ne dépend que de $t_1-t_2$.
> [!check]- Réponse
> **VRAI**. C'est la définition.

**25.** Un processus de moyenne constante est stationnaire au sens large.
> [!check]- Réponse
> **FAUX**. Il faut **aussi** $R(t_1,t_2)=R(t_1-t_2)$.

**26.** Un processus SSL est stationnaire au sens strict.
> [!check]- Réponse
> **FAUX** en général (vrai pour un processus gaussien). C'est SSS (d'ordre 2) ⇒ SSL.

**27.** $X(t)=A\sin(2\pi f_0t)$, avec $A\sim N(0,\sigma^2)$ et $f_0$ fixe, est SSL.
> [!check]- Réponse
> **FAUX**. La moyenne est nulle, mais $R(t_1,t_2)=\sigma^2\sin(2\pi f_0t_1)\sin(2\pi f_0t_2)$ dépend de $t_1$ et $t_2$, pas seulement de leur différence.

**28.** $Y(t)=A\sin(2\pi f_0t+\phi)$, avec $\phi\sim U[0,2\pi]$ indépendante de $A$, est SSL avec $R(\tau)=\frac{E[A^2]}{2}\cos(2\pi f_0\tau)$.
> [!check]- Réponse
> **VRAI**.

**29.** On choisit une phase uniforme sur $[0,2\pi]$ parce qu'on n'a pas d'information a priori sur la phase.
> [!check]- Réponse
> **VRAI**. Et c'est ce qui rend le processus stationnaire.

**30.** Pour un processus réel SSL, $R(\tau)$ est paire.
> [!check]- Réponse
> **VRAI**. Pour un processus complexe : $R(-\tau)=R^*(\tau)$.

**31.** Pour un processus SSL, on peut avoir $|R(\tau_0)|>R(0)$ pour un certain $\tau_0$.
> [!check]- Réponse
> **FAUX**. $|R(\tau)|\le R(0)$ (Schwarz).

**32.** Si $R(T_0)=R(0)$ pour un processus SSL, alors $R$ est périodique de période $T_0$.
> [!check]- Réponse
> **VRAI**. Démo : $|R(\tau)-R(\tau-T_0)|^2=|E[(v(t)-v(t-T_0))v^*(t-\tau)]|^2\le E|v(t)-v(t-T_0)|^2\,R(0)=2(R(0)-\Re R(T_0))R(0)=0$.

**33.** $R(0)$ est égal à la variance d'un processus SSL.
> [!check]- Réponse
> **FAUX**. $R(0)=\sigma^2+|m|^2$ : il n'est égal à la variance que si le processus est centré.

**34.** Un processus ergodique au sens de la moyenne permet d'estimer la moyenne d'ensemble par une moyenne temporelle sur une seule réalisation.
> [!check]- Réponse
> **VRAI**.

**35.** $A\sin(2\pi f_0t+\phi)$, avec $A$ aléatoire et $\phi$ uniforme, est ergodique au sens de l'autocorrélation.
> [!check]- Réponse
> **FAUX**. Sur une réalisation, l'autocorrélation temporelle vaut $\frac{a^2}2\cos(2\pi f_0\tau)$ et dépend de la valeur tirée $a$, alors que la statistique vaut $\frac{E[A^2]}2\cos$. Avec $A$ **constante**, ce serait vrai.

**36.** Deux processus SSL sont toujours conjointement SSL.
> [!check]- Réponse
> **FAUX**. Il faut en plus que $R_{XY}(t_1,t_2)$ ne dépende que de $t_1-t_2$.

## D. Processus classiques

**37.** Un processus de Bernoulli à valeurs $\pm1$ (probas $p$, $1-p$) a pour moyenne $2p-1$ et pour variance $4p(1-p)$.
> [!check]- Réponse
> **VRAI**.

**38.** Un bruit blanc binaire est un processus de Bernoulli avec $p=1/2$ : moyenne 0, variance 1.
> [!check]- Réponse
> **VRAI**.

**39.** Le processus de comptage associé à un Bernoulli suit une loi de Poisson.
> [!check]- Réponse
> **FAUX**. Il suit une loi **binomiale** $C_n^rp^r(1-p)^{n-r}$.

**40.** Une marche aléatoire équiprobable ($p=1/2$) est stationnaire car sa moyenne est nulle.
> [!check]- Réponse
> **FAUX**. Sa variance vaut $n-n_0$ et croît indéfiniment : le processus n'est pas stationnaire. Elle est aussi appelée processus de Wiener discret.

**41.** Un bruit blanc est toujours stationnaire.
> [!check]- Réponse
> **VRAI** (au sens large) : $R(k)=\sigma^2\delta(k)$.

**42.** Les échantillons d'un bruit blanc sont toujours indépendants.
> [!check]- Réponse
> **FAUX**. Blanc signifie **décorrélé**. Ils sont indépendants si le bruit est en plus **gaussien**.

**43.** Un bruit blanc de moyenne $\mu\neq0$ et de variance $\sigma^2$ a pour autocorrélation $\sigma^2\delta(k)$.
> [!check]- Réponse
> **FAUX**. $R(k)=\sigma^2\delta(k)+\mu^2$ : il y a un plateau $\mu^2$.

**44.** Le filtrage linéaire d'un processus gaussien donne un processus gaussien.
> [!check]- Réponse
> **VRAI**. Une combinaison linéaire de gaussiennes reste gaussienne.

## E. MA / AR

**45.** Un processus MA d'ordre fini construit sur un bruit blanc est toujours SSL.
> [!check]- Réponse
> **VRAI**.

**46.** Pour $y(n)=b(n)+3b(n-2)-4b(n-4)$ avec $b$ blanc de moyenne 1, la moyenne de $y$ vaut 8.
> [!check]- Réponse
> **FAUX**. $m_y=\mu(1+3-4)=0$.

**47.** Pour $t(n)=4v(n-1)+2v(n-2)+v(n-3)$, avec $v$ blanc de moyenne 1 et de variance 1, $R_{tt}(0)=70$.
> [!check]- Réponse
> **VRAI**. $\sigma^2(16+4+1)+\mu^2(4+2+1)^2=21+49=70$.

**48.** L'autocovariance d'un MA($q$) est nulle pour $|\tau|>q$.
> [!check]- Réponse
> **VRAI**. Mémoire finie (c'est l'**autocovariance** qui s'annule ; l'autocorrélation tend vers $m^2$).

**49.** Pour un AR(1) $x(n)=-a_1x(n-1)+v(n)$ stationnaire, $R_{xx}(0)=\dfrac{\sigma^2}{1-a_1^2}$.
> [!check]- Réponse
> **VRAI**. Et $R(\tau)=(-a_1)^{|\tau|}R(0)$.

**50.** Un processus AR est stationnaire quels que soient ses coefficients.
> [!check]- Réponse
> **FAUX**. Il faut que les pôles de $1/A(z)$ soient dans le cercle unité (ex. AR(1) : $|a_1|<1$).

**51.** Pour $y(n)=-a_2y(n-2)+v(n)$, l'autocorrélation est nulle pour tous les retards impairs.
> [!check]- Réponse
> **VRAI**. $R(\tau)\neq0$ seulement pour $\tau$ multiple de 2.

**52.** Un modèle AR correspond à un filtre « tout pôle » excité par un bruit blanc, et l'erreur de prédiction linéaire est ce bruit blanc.
> [!check]- Réponse
> **VRAI**.

## F. Matrice de corrélation & Karhunen-Loève

**53.** La matrice de corrélation d'un vecteur d'échantillons consécutifs d'un processus SSL est Toeplitz et hermitienne.
> [!check]- Réponse
> **VRAI**.

**54.** Une matrice de corrélation peut avoir une valeur propre strictement négative.
> [!check]- Réponse
> **FAUX**. Elle est semi-définie positive, donc ses valeurs propres sont **≥ 0**.

**55.** $\begin{pmatrix}2&3\\3&2\end{pmatrix}$ peut être une matrice de corrélation.
> [!check]- Réponse
> **FAUX**. $|R(1)|=3>R(0)=2$ (valeurs propres 5 et −1).

**56.** La matrice de corrélation d'un vecteur de 3 échantillons d'un BBGC de variance 1 est $I_3$.
> [!check]- Réponse
> **VRAI**.

**57.** En Karhunen-Loève, pour approcher $\mathbf x$ avec $M$ vecteurs, on garde ceux associés aux plus **petites** valeurs propres.
> [!check]- Réponse
> **FAUX**. On garde les **plus grandes**. L'EQM vaut la somme des valeurs propres **écartées**.

**58.** Les coefficients de la décomposition de Karhunen-Loève sont décorrélés.
> [!check]- Réponse
> **VRAI**. $E[k_ik_j^*]=\lambda_i\delta_{ij}$.

**59.** Pour $R_{xx}(0)=3$, $R_{xx}(1)=2$, $R_{xx}(2)=1$, garder uniquement le vecteur propre de plus grande valeur propre donne une EQM d'environ 2,63.
> [!check]- Réponse
> **VRAI**. Les valeurs propres sont $\approx6{,}37$ ; 2 ; 0,63, donc $\xi=2+0{,}63\approx2{,}63$ (la trace vaut 9).

## G. Estimation

**60.** L'estimateur $\frac1N\sum_{n=0}^{N-1-m}x(n+m)x^*(n)$ de l'autocorrélation est non biaisé.
> [!check]- Réponse
> **FAUX**. Il est **biaisé** : $E=(1-\frac{|m|}N)R(m)$ (fenêtre triangulaire), et asymptotiquement non biaisé. C'est la normalisation $\frac1{N-|m|}$ qui donne l'estimateur non biaisé.

**61.** L'estimateur non biaisé de l'autocorrélation a une variance plus faible que l'estimateur biaisé pour les grands retards.
> [!check]- Réponse
> **FAUX**. C'est l'inverse : pour $|m|$ proche de $N$, on moyenne très peu de termes et la variance explose.

**62.** Sous MATLAB, `xcorr(x,'biased')` et `xcorr(x,'unbiased')` donnent les deux estimateurs de l'autocorrélation.
> [!check]- Réponse
> **VRAI**. `randn` sert à générer un bruit blanc gaussien.

**63.** Pour estimer l'autocorrélation à partir d'une seule réalisation, il faut supposer le processus stationnaire et ergodique.
> [!check]- Réponse
> **VRAI**.

**64.** L'estimateur au sens du MV de la moyenne d'observations gaussiennes iid de variance connue est la moyenne arithmétique.
> [!check]- Réponse
> **VRAI**.

**65.** L'estimateur des moindres carrés $\hat\theta=(H^TH)^{-1}H^TY$ est toujours non biaisé.
> [!check]- Réponse
> **FAUX**. Il est biaisé si le bruit est corrélé avec $H$ ou s'il est de moyenne non nulle.

**66.** Un estimateur consistant vérifie $\lim_{N\to\infty}P(|\hat\theta_N-\theta|<\varepsilon)=1$.
> [!check]- Réponse
> **VRAI**.

## H. Chaînes de Markov

**67.** Dans une matrice stochastique $P$ ($p_{ij}=P(X_{n+1}=j|X_n=i)$), la somme de chaque colonne vaut 1.
> [!check]- Réponse
> **FAUX**. C'est chaque **ligne** qui somme à 1. La matrice de transition $M=P^T$ a ses colonnes qui somment à 1.

**68.** Une chaîne de Markov irréductible et périodique admet une distribution limite $\lim\mathbf P(n)$ indépendante de $\mathbf P(0)$.
> [!check]- Réponse
> **FAUX**. Il faut l'**apériodicité**. Une chaîne périodique a une solution $\pi=\pi P$, mais c'est la proportion du temps passé dans chaque état, pas une limite.

**69.** On a $F_{ij}=p_{ij}+\sum_{k\neq j}p_{ik}F_{kj}$, où $F_{ij}$ est la probabilité d'atteindre un jour $j$ en partant de $i$.
> [!check]- Réponse
> **VRAI**. On décompose selon le premier pas : soit on va directement en $j$, soit on passe par $k\neq j$.

**70.** Un état $i$ tel que $F_{ii}<1$ est récurrent.
> [!check]- Réponse
> **FAUX**. Il est **transitoire** ($F_{ii}=1$ : récurrent ; $F_{ii}=0$ : éphémère). Dans une chaîne irréductible finie, tous les états sont récurrents et $F_{ij}=1$.

---

> [!question] Bonus (ex-question d'examen)
> Pour $P=\begin{pmatrix}0{,}8&0{,}2\\0{,}5&0{,}5\end{pmatrix}$ (état 1 = +1, état 2 = −1) : $P(-1\text{ en }n+2\mid+1\text{ en }n)=0{,}8\cdot0{,}2+0{,}2\cdot0{,}5=\mathbf{0{,}26}$ et $\pi=(5/7,\,2/7)$. Vérifie-le toi-même.
