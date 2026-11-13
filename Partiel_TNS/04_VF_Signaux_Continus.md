---
tags: [partiel, TNS, signaux-continus, 1A, vrai-faux]
---

# Vrai/Faux : signaux continus (1A) · 45 questions

> [!tip] Mode d'emploi
> Pour chaque affirmation, écris **V ou F + une justification d'une ligne** sur papier, **puis** ouvre la réponse. Une bonne réponse sans la bonne justification compte comme une erreur dans ton carnet. Objectif : ≥ 40/45.

## A. Signaux, énergie, puissance

**1.** Un signal périodique non nul est à énergie finie.
> [!check]- Réponse
> **FAUX**. $\int_{-\infty}^{+\infty}|x|^2=\infty$ : il est à **puissance** moyenne finie.

**2.** Un signal à énergie finie a une puissance moyenne nulle.
> [!check]- Réponse
> **VRAI**. $P=\lim\frac{1}{T}\int_{-T/2}^{T/2}|x|^2\le\lim E/T=0$.

**3.** Le signal $x(t)=\Pi_\tau(2t-3)$ est une porte de durée $\tau/2$ centrée en $t=3/2$.
> [!check]- Réponse
> **VRAI**. $\Pi_\tau(2(t-\frac32))$ : on comprime d'un facteur 2 (durée $\tau/2$), puis on décale de $3/2$.

**4.** La dérivée de la rampe $r(t)=t\,u(t)$ est l'échelon $u(t)$, et la dérivée de l'échelon (au sens des distributions) est $\delta(t)$.
> [!check]- Réponse
> **VRAI**.

**5.** $\delta(3t)=3\,\delta(t)$.
> [!check]- Réponse
> **FAUX**. $\delta(at)=\frac{1}{|a|}\delta(t)$, donc $\delta(3t)=\frac13\delta(t)$.

**6.** $\cos(t)\,\delta(t-\pi)=-\delta(t-\pi)$.
> [!check]- Réponse
> **VRAI**. $f(t)\delta(t-t_0)=f(t_0)\delta(t-t_0)$ et $\cos\pi=-1$.

**7.** La dérivée au sens des distributions de $\Pi_\tau(t)$ est $\delta(t+\tau/2)-\delta(t-\tau/2)$.
> [!check]- Réponse
> **VRAI**. Saut de $+1$ en $-\tau/2$, saut de $-1$ en $+\tau/2$.

## B. Convolution

**8.** $x(t)*\delta(t-t_0)=x(t_0)$.
> [!check]- Réponse
> **FAUX**. Cela donne $x(t-t_0)$ (le signal décalé). C'est le **produit** $x(t)\delta(t-t_0)$ qui fait intervenir $x(t_0)$.

**9.** La convolution de deux signaux de durées $T_1$ et $T_2$ a une durée $T_1+T_2$.
> [!check]- Réponse
> **VRAI**. Supports $[a,b]$ et $[c,d]$ donnent $[a+c,b+d]$.

**10.** $\Pi_T*\Pi_T$ est un triangle de base $2T$ et de hauteur $T$.
> [!check]- Réponse
> **VRAI**.

**11.** La convolution est commutative mais pas associative.
> [!check]- Réponse
> **FAUX**. Elle est commutative, **associative** et distributive.

**12.** Un système LTI de réponse impulsionnelle $h(t)=e^{-t}u(t)$ est causal et stable.
> [!check]- Réponse
> **VRAI**. $h=0$ pour $t<0$ et $\int|h|=1<\infty$.

**13.** $e^{-at}u(t)*e^{-at}u(t)=t\,e^{-at}u(t)$ pour $a>0$.
> [!check]- Réponse
> **VRAI**.

## C. Corrélation

**14.** L'autocorrélation d'un signal réel à énergie finie est paire et maximale en $\tau=0$.
> [!check]- Réponse
> **VRAI**. $R(-\tau)=R^*(\tau)=R(\tau)$ et $|R(\tau)|\le R(0)=E$.

**15.** Deux signaux différents ont nécessairement des fonctions d'autocorrélation différentes.
> [!check]- Réponse
> **FAUX**. L'autocorrélation perd la phase : $x(t)$ et $x(t-t_0)$ ont la même autocorrélation.

**16.** L'autocorrélation de $A\cos(2\pi f_0t+\varphi)$ vaut $\frac{A^2}{2}\cos(2\pi f_0\tau+\varphi)$.
> [!check]- Réponse
> **FAUX**. Elle vaut $\frac{A^2}2\cos(2\pi f_0\tau)$ : la phase $\varphi$ disparaît.

**17.** L'autocorrélation d'un signal périodique de période $T_0$ est périodique de période $T_0$.
> [!check]- Réponse
> **VRAI**.

**18.** $R_{xy}(\tau)=x(\tau)*y^*(-\tau)$ pour des signaux à énergie finie.
> [!check]- Réponse
> **VRAI**.

**19.** En radar, la position du maximum de l'intercorrélation entre le signal émis et le signal reçu donne le retard aller-retour, donc la distance $d=c\tau_0$.
> [!check]- Réponse
> **FAUX**. Le retard se lit bien sur le pic, mais c'est un aller-retour : $d=c\tau_0/2$.

**20.** $R_{xx}(0)$ est l'énergie (ou la puissance) du signal.
> [!check]- Réponse
> **VRAI**.

## D. Séries et transformée de Fourier

**21.** Pour un signal réel périodique, $c_{-k}=c_k^*$.
> [!check]- Réponse
> **VRAI**. D'où $|c_k|$ pair.

**22.** Le spectre d'un signal périodique est continu.
> [!check]- Réponse
> **FAUX**. Il est **discret** (raies en $k/T_0$) : $X(f)=\sum c_k\delta(f-k/T_0)$.

**23.** D'après Parseval, la puissance d'un signal périodique est égale à $\sum_k|c_k|^2$.
> [!check]- Réponse
> **VRAI**.

**24.** La TF d'un signal réel est toujours réelle.
> [!check]- Réponse
> **FAUX**. Elle est **hermitienne** ($X(-f)=X^*(f)$). Elle n'est réelle que si le signal est réel **et pair**.

**25.** La TF d'un signal réel impair est imaginaire pure et impaire.
> [!check]- Réponse
> **VRAI**.

**26.** Retarder un signal de $t_0$ modifie son spectre d'amplitude.
> [!check]- Réponse
> **FAUX**. $X(f)e^{-j2\pi ft_0}$ : seule la phase change (d'un terme linéaire en $f$).

**27.** $\mathrm{TF}[x(2t)]=2X(2f)$.
> [!check]- Réponse
> **FAUX**. $\mathrm{TF}[x(at)]=\frac1{|a|}X(f/a)$, donc $\frac12X(f/2)$ : comprimer en temps **élargit** le spectre.

**28.** $\mathrm{TF}[x(t)e^{j2\pi f_0t}]=X(f-f_0)$.
> [!check]- Réponse
> **VRAI**. C'est la modulation (translation fréquentielle).

**29.** La TF de $\Pi_T(t)$ est $T\,\mathrm{sinc}(\pi fT)$, qui s'annule aux fréquences $k/T$, $k\neq0$.
> [!check]- Réponse
> **VRAI**. Le lobe principal a une largeur $2/T$.

**30.** Plus une porte est longue en temps, plus le lobe principal de sa TF est large.
> [!check]- Réponse
> **FAUX**. Il est **plus étroit** ($2/T$) : c'est la dualité temps-fréquence.

**31.** $\mathrm{TF}[\cos(2\pi f_0t)]=\frac12[\delta(f-f_0)+\delta(f+f_0)]$.
> [!check]- Réponse
> **VRAI**.

**32.** La TF d'un peigne de Dirac de période $T$ est un peigne de Dirac de période $1/T$ (à un facteur $1/T$ près).
> [!check]- Réponse
> **VRAI**.

**33.** La TF d'un produit de convolution est le produit de convolution des TF.
> [!check]- Réponse
> **FAUX**. Convolution en temps ↔ **produit** en fréquence (et produit ↔ convolution).

**34.** $\int|x(t)|^2dt=\int|X(f)|^2df$.
> [!check]- Réponse
> **VRAI**. Parseval/Plancherel.

## E. DSP, Wiener-Khintchine, filtrage

**35.** D'après Wiener-Khintchine, la DSP est la TF de la fonction d'autocorrélation.
> [!check]- Réponse
> **VRAI**.

**36.** La densité spectrale d'énergie d'un signal à énergie finie vaut $|X(f)|^2$.
> [!check]- Réponse
> **VRAI**. C'est la TF de $R_{xx}$, puisque $R_{xx}=x*x^*(-t)\leftrightarrow XX^*$.

**37.** Une DSP peut prendre des valeurs négatives à certaines fréquences.
> [!check]- Réponse
> **FAUX**. Une DSP est réelle et **≥ 0**.

**38.** En sortie d'un filtre de réponse $H(f)$, la DSP vaut $H(f)S_{xx}(f)$.
> [!check]- Réponse
> **FAUX**. Elle vaut $|H(f)|^2S_{xx}(f)$. C'est l'**interspectre** $S_{yx}$ qui vaut $H(f)S_{xx}(f)$.

**39.** Un bruit blanc a une DSP constante et une autocorrélation proportionnelle à $\delta(\tau)$.
> [!check]- Réponse
> **VRAI**. À temps continu, c'est une idéalisation de puissance infinie.

## F. Échantillonnage, modulation, Hilbert

**40.** Échantillonner à $f_e$ rend le spectre périodique de période $f_e$.
> [!check]- Réponse
> **VRAI**. $X_e(f)=\frac1{T_e}\sum_kX(f-kf_e)$.

**41.** Un signal de bande $[-B,B]$ échantillonné à $f_e=1{,}5B$ peut être reconstruit parfaitement.
> [!check]- Réponse
> **FAUX**. Il faut $f_e>2B$ (Shannon), sinon il y a repliement.

**42.** Un repliement spectral peut être corrigé après l'échantillonnage par un filtrage numérique adapté.
> [!check]- Réponse
> **FAUX**. Le repliement est **irréversible** : il faut un filtre anti-repliement **avant** l'échantillonnage.

**43.** Multiplier $x(t)$ par $\cos(2\pi f_0t)$ translate son spectre en $\pm f_0$ avec un facteur ½.
> [!check]- Réponse
> **VRAI**. $\frac12[X(f-f_0)+X(f+f_0)]$.

**44.** Le signal analytique $z=x+j\hat x$ a un spectre nul pour les fréquences négatives.
> [!check]- Réponse
> **VRAI**. $Z(f)=2X(f)u(f)$.

**45.** La transformée de Hilbert correspond au filtre $H(f)=-j\,\mathrm{sgn}(f)$ et transforme $\cos(2\pi f_0t)$ en $\sin(2\pi f_0t)$.
> [!check]- Réponse
> **VRAI**.
