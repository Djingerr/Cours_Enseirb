---
tags: [partiel, TNS, examen-blanc]
---

# Examen blanc : Filtres numériques & estimation

> [!important] Conditions réelles (J-1)
> **1 h 30**, sans document ni calculatrice, téléphone éteint. Partie A : 40 V/F (≈ 45 min, justification d'**une ligne** obligatoire). Partie B : 2 exercices (≈ 45 min).
> Barème indicatif : V/F juste et justifié = 1 ; juste sans justification = 0,5 ; faux = 0. B1 = 10, B2 = 10. Total sur 60.
> **N'ouvre le corrigé qu'à la fin.**

## Partie A : Vrai/Faux (mélangé)

1. Un processus aléatoire SSL de moyenne non nulle a une autocorrélation qui tend vers 0 quand $|\tau|\to\infty$.
2. Si $X\sim N(1,4)$, alors 68,3 % des valeurs de $X$ sont dans $[-1;3]$.
3. La TF d'un signal réel et pair est réelle et paire.
4. Une chaîne de Markov dont un état a une boucle (et qui est irréductible) est apériodique.
5. La matrice $\begin{pmatrix}4&-2\\-2&4\end{pmatrix}$ peut être la matrice de corrélation de deux échantillons consécutifs d'un processus SSL réel.
6. Un filtre RII causal peut avoir une phase exactement linéaire.
7. L'estimateur biaisé de l'autocorrélation est asymptotiquement non biaisé.
8. Le temps de séjour dans un état d'une CMTD suit une loi géométrique.
9. La puissance d'un signal $T_0$-périodique se calcule sur une seule période.
10. Le spectre d'amplitude de $x(t-t_0)$ est égal à celui de $x(t)$ multiplié par $|e^{-j2\pi ft_0}|$, donc inchangé.
11. Deux processus gaussiens conjointement gaussiens et décorrélés sont indépendants.
12. Pour un AR(1) $x(n)=0{,}9x(n-1)+v(n)$, l'autocorrélation alterne de signe.
13. Avec $N=256$ points et $f_e=8$ kHz, la TFD a un pas fréquentiel de 31,25 Hz.
14. Un processus MA d'ordre 3 a une autocovariance nulle pour $|\tau|\ge4$.
15. Le filtre $y(n)=x(n)-x(n-1)$ est un passe-bas.
16. Le processus $X(t)=e^{At}$, avec $A$ une variable aléatoire, est en général non stationnaire.
17. La moyenne de la sortie d'un filtre de réponse $H(f)$ excité par un processus SSL de moyenne $m_x$ vaut $H(0)m_x$.
18. Le périodogramme est un estimateur de la DSP dont la variance diminue quand $N$ augmente.
19. La fenêtre de Hanning réduit la fuite spectrale par rapport à la fenêtre rectangulaire.
20. Dans un ensemble d'états d'une CMTD, un état éphémère est un état où l'on ne repasse jamais.
21. La transformée de Karhunen-Loève d'un bruit blanc de variance $\sigma^2$ permet une compression efficace.
22. Pour un processus SSL complexe, $R_{XX}(\tau)$ est toujours réelle.
23. Échantillonner $\cos(2\pi\cdot3\,\text{kHz}\cdot t)$ à 4 kHz donne la même suite que $\cos(2\pi\cdot1\,\text{kHz}\cdot t)$ échantillonné à 4 kHz.
24. Le filtre adapté maximise le rapport signal à bruit à un instant donné.
25. La convolution d'un signal par $\delta(t)$ laisse le signal inchangé.
26. Si $\hat\theta$ est sans biais, alors $\hat\theta$ est consistant.
27. Un processus de Wiener discret a une variance proportionnelle au temps écoulé.
28. La transformation bilinéaire conserve la position des fréquences de coupure.
29. Les valeurs propres de la matrice de corrélation sont les puissances portées par les composantes de Karhunen-Loève.
30. Un filtre à coefficients réels dont tous les zéros sont sur le cercle unité et dont la réponse impulsionnelle est symétrique est à phase linéaire.
31. Pour un processus réel, $C_{XX}(t_1,t_2)=C_{XX}(t_2,t_1)$.
32. La DSP d'un processus AR présente des creux aux fréquences des pôles.
33. Le théorème de Wiener-Khintchine s'applique à un processus SSL.
34. Une chaîne de Markov avec deux sous-chaînes absorbantes est irréductible.
35. Pour l'estimation MV d'une moyenne, maximiser la vraisemblance ou la log-vraisemblance donne le même estimateur.
36. Augmenter le recouvrement dans la méthode de Welch augmente le nombre de segments moyennés.
37. Pour $y(n)=v(n)-v(n-1)$ avec $v$ blanc de moyenne 5 et de variance 1, $R_{yy}(1)=-1$.
38. Le signal analytique d'un signal réel a une TF hermitienne.
39. Le filtre de Cauer atteint un gabarit donné avec un ordre inférieur à Butterworth et Tchebychev.
40. Les moindres carrés pour estimer les paramètres AR reviennent à minimiser l'énergie de l'erreur de prédiction.

## Partie B : Exercices

### B1. Processus (10 pts)
Soit $v(n)$ blanc de moyenne $\mu$ et de variance $\sigma^2$, et $y(n)=2v(n)-v(n-1)+v(n-3)$.
1. (2) Moyenne et $R_{vv}(\tau)$. 2. (4) $R_{yy}(\tau)$ en général, puis valeurs pour $\mu=1$, $\sigma^2=2$ et $\tau=0..4$. 3. (2) $y$ est-il SSL ? Matrice de covariance de $[y(n),y(n-1)]^T$. 4. (2) Si $v$ est gaussien, quelle est la loi de $y(n)$ ? Donner l'intervalle à 95,4 % pour $\mu=1$, $\sigma^2=2$.

### B2. Filtre numérique (10 pts)
$y(n)=x(n)-x(n-2)+0{,}81\,y(n-2)$.
1. (2) $H(z)$, causalité, RIF/RII (2 justifications). 2. (3) Pôles, zéros ; stabilité. 3. (3) Allure de $|H(f)|$ sur $[-f_e/2,f_e/2]$ avec les valeurs en $0$, $\pm f_e/4$ et $\pm f_e/2$. Quel type de filtre ? 4. (2) 4 premiers termes de $h(n)$.

---

> [!check]- CORRIGÉ PARTIE A (ouvre seulement à la fin)
> 1. **F** : $R(\tau)\to|m|^2$ (si les échantillons lointains sont décorrélés), pas 0.
> 2. **V** : $\sigma=2$, donc $[1-2;1+2]$.
> 3. **V**.
> 4. **V** : il y a un circuit de longueur 1, donc le pgcd vaut 1.
> 5. **V** : Toeplitz, symétrique, $|R(1)|=2\le4$, valeurs propres 6 et 2 (> 0).
> 6. **F** : seul un RIF (symétrique) l'est exactement.
> 7. **V** : $E=(1-|m|/N)R(m)\to R(m)$.
> 8. **V**.
> 9. **V** : $P=\frac1{T_0}\int_{T_0}|x|^2$.
> 10. **V** : seule la phase change.
> 11. **V** : c'est le cas gaussien.
> 12. **F** : $R(\tau)\propto0{,}9^{|\tau|}>0$, décroissance sans alternance (signal basse fréquence). Ici $a_1=-0{,}9$.
> 13. **V** : $8000/256=31{,}25$ Hz.
> 14. **V** : la covariance est nulle pour $|\tau|>q=3$.
> 15. **F** : $H=1-z^{-1}$ a un zéro en $z=1$, donc $H(0)=0$ : c'est un **passe-haut** (dérivateur).
> 16. **V** : $E[e^{At}]$ dépend de $t$ (sauf cas trivial).
> 17. **V**.
> 18. **F** : la variance du périodogramme ne tend **pas** vers 0 quand $N$ augmente (estimateur non consistant), d'où Bartlett et Welch.
> 19. **V** : lobes secondaires à −31 dB contre −13 dB.
> 20. **V** : $F_{ii}=0$.
> 21. **F** : toutes les valeurs propres sont égales ($\sigma^2$), il n'y a aucune direction privilégiée, donc rien à compresser.
> 22. **F** : elle est hermitienne, $R(-\tau)=R^*(\tau)$ ; seule $R(0)$ est réelle.
> 23. **V** : repliement, $3\text{ kHz}=4-1$ kHz et le cosinus est pair, donc les échantillons sont identiques.
> 24. **V**.
> 25. **V** : $\delta$ est l'élément neutre.
> 26. **F** : il faut aussi que la variance tende vers 0 (sans biais ⇏ consistant).
> 27. **V** : $\operatorname{Var}=n-n_0$.
> 28. **F** : warping, d'où la pré-distorsion.
> 29. **V** : $E|k_i|^2=\lambda_i$.
> 30. **V** : la symétrie de $h$ suffit (RIF).
> 31. **V**.
> 32. **F** : les pôles donnent des **pics** ; les creux viennent des zéros (MA).
> 33. **V** : la DSP est la TF de $R(\tau)$.
> 34. **F** : on ne peut pas sortir d'une sous-chaîne absorbante pour atteindre l'autre.
> 35. **V** : $\ln$ est croissant.
> 36. **V** : à longueur de segment fixée, il y a plus de segments, donc plus de moyennage (et plus de calculs).
> 37. **V** : $R_{yy}(\tau)=\sigma^2\sum b_jb_{j+\tau}+\mu^2(\sum b)^2$, avec $\sum b=0$ et des coefficients $[1,-1]$, d'où $R(1)=-\sigma^2=-1$.
> 38. **F** : il n'a pas de fréquences négatives, donc ce n'est pas hermitien (le signal analytique est complexe).
> 39. **V**.
> 40. **V** : $J=\sum u^2(n)$, où $u$ est l'erreur de prédiction.

> [!check]- CORRIGÉ B1
> 1. $E[v]=\mu$ ; $R_{vv}(\tau)=\sigma^2\delta(\tau)+\mu^2$.
> 2. Coefficients $[2,-1,0,1]$, $\sum b=2$, d'où $m_y=2\mu$. $R_{yy}(\tau)=\sigma^2\sum_jb_jb_{j+|\tau|}+4\mu^2$, avec $\sum b_j^2=6$, $\sum b_jb_{j+1}=-2$, $\sum b_jb_{j+2}=-1$, $\sum b_jb_{j+3}=2$, et 0 au-delà.
> Pour $\mu=1$, $\sigma^2=2$ : $R(0)=16$, $R(1)=0$, $R(2)=2$, $R(3)=8$, $R(4)=4$.
> 3. SSL (MA fini sur un bruit blanc). Covariance $C(\tau)=R(\tau)-4$, soit $C(0)=12$ et $C(1)=-4$, d'où $\begin{pmatrix}12&-4\\-4&12\end{pmatrix}$.
> 4. C'est une combinaison linéaire de gaussiennes, donc $y(n)\sim N(2\mu,6\sigma^2)=N(2,12)$. Intervalle $[2-4\sqrt3;2+4\sqrt3]\approx[-4{,}93;8{,}93]$.

> [!check]- CORRIGÉ B2
> 1. $H(z)=\frac{1-z^{-2}}{1-0{,}81z^{-2}}$. Le filtre est causal. Il est **RII** : récursif ($y(n-2)$), et ses pôles $\pm0{,}9$ ne sont pas simplifiés (les zéros sont en $\pm1$), donc $h$ est infinie.
> 2. Zéros $z=\pm1$ (sur le cercle). Pôles $z=\pm0{,}9$, de module < 1 : le filtre est **stable**.
> 3. $|H(0)|=0$ (zéro en $z=1$), $|H(\pm f_e/2)|=0$ (zéro en $z=-1$). En $f_e/4$ ($z=j$) : $\frac{|1-(-1)|}{|1-0{,}81\cdot(-1)|}=\frac{2}{1{,}81}\approx1{,}10$. C'est un **passe-bande** centré sur $\pm f_e/4$.
> 4. Avec $x=\delta$ : $h(0)=1$, $h(1)=0$, $h(2)=-1+0{,}81=-0{,}19$, $h(3)=0$ (puis $h(4)=-0{,}1539$…).
