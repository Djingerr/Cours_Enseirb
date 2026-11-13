---
tags: [partiel, TNS, filtres-numeriques, 2A, vrai-faux]
---

# Vrai/Faux : filtres numériques & estimation (2A) · 60 questions

> [!tip] Même règle
> V/F **+ justification** avant d'ouvrir. Les pièges 2A portent surtout sur la stabilité, le zero-padding, la phase linéaire et la bilinéaire.

## A. TFTD, TFD, FFT, fenêtres

**1.** La TF d'un signal à temps discret échantillonné à $f_e$ est périodique de période $f_e$.
> [!check]- Réponse
> **VRAI**.

**2.** Pour un signal réel, le module de sa TF sur $[0,f_e/2]$ suffit à connaître celui sur $[-f_e/2,0]$.
> [!check]- Réponse
> **VRAI**. Symétrie hermitienne, donc $|X|$ est pair.

**3.** Pour un signal complexe, le module de la TF sur $[-f_e/2,0]$ se déduit de celui sur $[0,f_e/2]$.
> [!check]- Réponse
> **FAUX**. Il n'y a pas de symétrie hermitienne pour un signal complexe (TD 1.9 Q2).

**4.** Une TFD sur $N$ points observe les fréquences $kf_e/N$, $k=0,\dots,N-1$.
> [!check]- Réponse
> **VRAI**.

**5.** Avec $N=100$ et $f_e=500$ Hz, la TFD observe la fréquence 32 Hz.
> [!check]- Réponse
> **FAUX**. Le pas vaut 5 Hz : 30 et 35 Hz sont observées, pas 32 Hz.

**6.** La FFT et la TFD donnent des résultats différents ; la FFT est une approximation.
> [!check]- Réponse
> **FAUX**. La FFT est un algorithme **rapide** qui calcule **exactement** la TFD, en $N\log_2N$ opérations (pour $N=2^m$).

**7.** Le zero-padding améliore la résolution fréquentielle, c'est-à-dire la capacité à séparer deux sinusoïdes proches.
> [!check]- Réponse
> **FAUX**. Il affine la **grille** (interpolation) mais n'ajoute aucune information. La résolution dépend de la durée d'observation réelle.

**8.** Passer de 1000 à 1024 échantillons par zero-padding permet d'utiliser une FFT radix-2.
> [!check]- Réponse
> **VRAI**.

**9.** Tronquer un signal de 1000 à 512 échantillons pour faire une FFT ne fait perdre aucune information.
> [!check]- Réponse
> **FAUX**. On perd 488 échantillons, et la résolution se dégrade ($f_e/512$ au lieu de $f_e/1000$).

**10.** Si $f_0$ n'est pas un multiple de $f_e/N$, le pic d'une sinusoïde n'est pas exactement observé par la TFD.
> [!check]- Réponse
> **VRAI**. C'est l'effet du fenêtrage : l'énergie fuit dans les lobes.

**11.** Le premier lobe secondaire de la fenêtre rectangulaire est à −13 dB.
> [!check]- Réponse
> **VRAI**.

**12.** La fenêtre de Hamming a un lobe principal plus étroit que la fenêtre rectangulaire.
> [!check]- Réponse
> **FAUX**. Il est **deux fois plus large**, en échange de lobes secondaires bien plus bas (−41 dB).

**13.** La fenêtre de Blackman a des lobes secondaires plus bas que la fenêtre de Hanning.
> [!check]- Réponse
> **VRAI**. −59 dB contre −31 dB, avec un lobe principal triple.

**14.** La largeur du lobe principal de la fenêtre rectangulaire de $N$ points vaut $2f_e/N$.
> [!check]- Réponse
> **VRAI**.

## B. Analyse spectrale

**15.** La DSP théorique correspond à un moyennage sur une infinité de réalisations.
> [!check]- Réponse
> **VRAI**. Le spectre d'**une** réalisation n'en est qu'une estimation.

**16.** La méthode de Bartlett réduit la variance de l'estimation de la DSP sans dégrader la résolution.
> [!check]- Réponse
> **FAUX**. Les segments sont plus courts, donc la résolution se dégrade (effet de fenêtrage plus fort).

**17.** La méthode de Welch utilise un recouvrement entre segments et une fenêtre éventuellement non rectangulaire.
> [!check]- Réponse
> **VRAI**. Elle lisse plus que Bartlett, mais demande plus de calculs.

**18.** Le corrélogramme est la TF de la fonction d'autocorrélation estimée.
> [!check]- Réponse
> **VRAI**.

**19.** Le spectrogramme suppose le signal stationnaire sur toute sa durée.
> [!check]- Réponse
> **FAUX**. Il suppose une **quasi-stationnarité** sur chaque fenêtre d'analyse (20-40 ms pour la parole) et permet de suivre l'évolution, par exemple d'un chirp.

## C. Filtres : causalité, stabilité, RIF/RII

**20.** Un filtre RIF est toujours stable.
> [!check]- Réponse
> **VRAI**. $\sum|h(n)|$ est une somme finie.

**21.** Un filtre défini par une équation aux différences récursive est forcément RII.
> [!check]- Réponse
> **FAUX**. Les pôles peuvent être simplifiés par des zéros. Exemple : $\frac{1-z^{-3}}{1-z^{-1}}=1+z^{-1}+z^{-2}$ est RIF (TD 1.6).

**22.** Un filtre causal est stable si et seulement si tous ses pôles sont strictement à l'intérieur du cercle unité.
> [!check]- Réponse
> **VRAI**.

**23.** Un filtre avec un pôle simple sur le cercle unité est stable.
> [!check]- Réponse
> **FAUX**. Il est instable (marginalement) : la réponse impulsionnelle ne décroît pas.

**24.** $y(n)=x(n)+x(n+1)$ est un filtre causal.
> [!check]- Réponse
> **FAUX**. Il utilise l'échantillon **futur** $x(n+1)$.

**25.** $y(n)=x(n)+0{,}9x(n-1)+0{,}81x(n-2)$ est un RIF causal dont les zéros sont $0{,}9e^{\pm j2\pi/3}$.
> [!check]- Réponse
> **VRAI**. $z^2+0{,}9z+0{,}81=0$ donne $|z|=0{,}9$ et un angle de $\pm120°$. Il y a donc une forte atténuation (non totale) en $\pm f_e/3$.

**26.** $y(n)=x(n)+x(n-1)+x(n-2)$ rejette totalement les fréquences $\pm f_e/3$.
> [!check]- Réponse
> **VRAI**. Ses zéros $e^{\pm j2\pi/3}$ sont **sur** le cercle ; $|H(f)|=|1+2\cos(2\pi f/f_e)|$.

**27.** $y(n)=0{,}8y(n-1)-0{,}64y(n-2)+x(n)$ est instable car ses coefficients sont proches de 1.
> [!check]- Réponse
> **FAUX**. Ses pôles valent $0{,}8e^{\pm j\pi/3}$, de module 0,8 < 1 : le filtre est stable, avec une résonance vers $\pm f_e/6$.

**28.** Pour $H(z)=1/(1+a_1z^{-1}+a_2z^{-2})$, la stabilité équivaut à $|a_2|<1$ et $|a_1|<1+a_2$.
> [!check]- Réponse
> **VRAI**. C'est le triangle de stabilité (TD 1.10).

**29.** Les pôles de $1/(1+a_1z^{-1}+a_2z^{-2})$ sont complexes conjugués si $a_1^2>4a_2$.
> [!check]- Réponse
> **FAUX**. Ils sont complexes si $a_1^2<4a_2$ (discriminant négatif) ; leur module vaut alors $\sqrt{a_2}$.

**30.** Plus un pôle est proche du cercle unité, plus la résonance associée est étroite et haute.
> [!check]- Réponse
> **VRAI**.

**31.** Un zéro placé exactement sur le cercle unité à l'angle $\theta_0$ annule $|H|$ à la fréquence $f_0=\theta_0f_e/2\pi$.
> [!check]- Réponse
> **VRAI**.

**32.** Pour rejeter $\pm1000$ Hz avec $f_e=10$ kHz, on place des zéros en $e^{\pm j\pi/5}$ et des pôles en $re^{\pm j\pi/5}$ avec $r$ proche de 1 (inférieur à 1).
> [!check]- Réponse
> **VRAI**. C'est un filtre notch (TD 1.8).

**33.** Un filtre à coefficients réels a des pôles et zéros réels ou en paires conjuguées.
> [!check]- Réponse
> **VRAI**. D'où $|H(f)|$ pair.

## D. RIF : phase linéaire, synthèse

**34.** Un RIF à phase linéaire vérifie $h(n)=\pm h(N-1-n)$.
> [!check]- Réponse
> **VRAI**.

**35.** Le retard de groupe d'un RIF à phase linéaire de longueur $N$ vaut $(N-1)/2$ échantillons.
> [!check]- Réponse
> **VRAI**.

**36.** Un RIF à réponse impulsionnelle antisymétrique peut réaliser un passe-bas.
> [!check]- Réponse
> **FAUX**. $H(0)=\sum h(n)=0$.

**37.** Selon la convention du cours, le type IV ($N$ impair, antisymétrique) impose $h\big(\frac{N-1}{2}\big)=0$.
> [!check]- Réponse
> **VRAI**.

**38.** Si $z_i$ est un zéro d'un RIF à phase linéaire, alors $1/z_i$ est aussi un zéro.
> [!check]- Réponse
> **VRAI**. Avec des coefficients réels, les zéros vont même par quadruplets $z_i,\ z_i^*,\ 1/z_i,\ 1/z_i^*$.

**39.** Un RIF à phase linéaire peut être à minimum de phase.
> [!check]- Réponse
> **FAUX** (hors zéros sur le cercle). $z_i$ et $1/z_i$ ne peuvent pas être tous deux dans le disque unité.

**40.** Dans la méthode de la fenêtre avec une fenêtre rectangulaire, augmenter l'ordre réduit l'amplitude des oscillations de Gibbs.
> [!check]- Réponse
> **FAUX**. La transition se resserre, mais l'amplitude des oscillations reste la même. Il faut changer de fenêtre.

**41.** La réponse impulsionnelle idéale d'un passe-bas est infinie et non causale ; on la tronque puis on la décale pour la rendre causale.
> [!check]- Réponse
> **VRAI**. Le décalage ne modifie que la phase.

**42.** Un passe-haut s'obtient par $h_{ph}(k)=\delta(k-L)-h_{pb}(k)$.
> [!check]- Réponse
> **VRAI**.

**43.** La méthode de Remez (minimax) répartit l'erreur en ondulations égales dans les bandes passante et atténuée.
> [!check]- Réponse
> **VRAI**. Théorème d'alternance de Tchebychev.

**44.** À gabarit égal, un RIF demande en général un ordre plus faible qu'un RII.
> [!check]- Réponse
> **FAUX**. C'est l'inverse : 25-400 pour un RIF, 5-20 pour un RII.

## E. RII : passe-tout, minimum de phase, synthèse

**45.** Un filtre passe-tout vérifie $|H(f)|=1$ pour tout $f$, et ses zéros sont les inverses conjugués de ses pôles.
> [!check]- Réponse
> **VRAI**.

**46.** Un filtre causal stable à minimum de phase a tous ses zéros dans le disque unité.
> [!check]- Réponse
> **VRAI**. Il a le plus petit retard de groupe parmi les filtres de même module.

**47.** Tout filtre causal stable peut se décomposer en un filtre à minimum de phase en cascade avec un passe-tout.
> [!check]- Réponse
> **VRAI**.

**48.** Le filtre inverse $1/H(z)$ d'un filtre causal stable est toujours stable.
> [!check]- Réponse
> **FAUX**. Il ne l'est que si les zéros de $H$ sont dans le disque unité (minimum de phase).

**49.** Pour $H(z/\rho)$ avec $\rho<1$, les pôles se rapprochent de l'origine et les résonances s'atténuent.
> [!check]- Réponse
> **VRAI**. Les pôles $p$ deviennent $\rho p$.

**50.** La transformation bilinéaire peut rendre instable un filtre analogique stable.
> [!check]- Réponse
> **FAUX**. Elle envoie le demi-plan gauche **dans** le disque unité : la stabilité est conservée.

**51.** La transformation bilinéaire introduit un repliement spectral.
> [!check]- Réponse
> **FAUX**. Il n'y a **pas** de repliement, mais une **distorsion non linéaire des fréquences** (warping) : $\omega_c=\frac2{T_e}\tan\frac{\omega_dT_e}2$. On pré-distord le gabarit.

**52.** La bilinéaire s'obtient en approchant l'intégrale par la méthode des trapèzes.
> [!check]- Réponse
> **VRAI**.

**53.** La méthode de l'invariance impulsionnelle convient bien à la synthèse d'un passe-haut.
> [!check]- Réponse
> **FAUX**. $H(f)=\frac1{T_e}\sum H_c(f-k/T_e)$ : un passe-haut n'est pas à bande limitée, donc il y a repliement.

**54.** L'invariance impulsionnelle conserve la stabilité.
> [!check]- Réponse
> **VRAI**. Les pôles $p_i$ deviennent $e^{p_iT_e}$, et $|e^{p_iT_e}|=e^{\Re(p_i)T_e}<1$.

**55.** L'approximation de la dérivée par différence progressive ($p=(z-1)/T$) garantit un filtre numérique stable.
> [!check]- Réponse
> **FAUX**. Le demi-plan gauche est envoyé sur $\Re z<1$, qui déborde du disque. La différence **rétrograde**, elle, conserve la stabilité.

## F. Prototypes analogiques, retards, filtre adapté

**56.** Tous les filtres de Butterworth passent par −3 dB à la fréquence de coupure, quel que soit leur ordre.
> [!check]- Réponse
> **VRAI**. $|H(1)|^2=\frac12$.

**57.** Le filtre de Tchebychev de type I ondule dans la bande atténuée.
> [!check]- Réponse
> **FAUX**. Il ondule dans la bande **passante**. C'est le type II qui ondule dans la bande atténuée, et Cauer dans les deux.

**58.** À ordre égal, Tchebychev I est plus sélectif que Butterworth.
> [!check]- Réponse
> **VRAI**. Dans l'exemple du cours, le même gabarit demande un ordre 10 avec Tchebychev contre 26 avec Butterworth.

**59.** Le filtre de Bessel-Thomson est choisi pour sa forte sélectivité.
> [!check]- Réponse
> **FAUX**. On le choisit pour son **retard de groupe maximalement plat** (phase quasi linéaire) ; sa sélectivité est faible.

**60.** Le filtre adapté à un signal réel $s(t)$ dans un bruit blanc a pour réponse impulsionnelle $h(t)=s(t_1-t)$, et son RSB maximal ne dépend que de l'énergie de $s$.
> [!check]- Réponse
> **VRAI**. Il est causal si $t_1\ge$ la fin du signal. Le RSB max ∝ $E_s/\sigma_b^2$ et ne dépend pas de la forme du signal.
