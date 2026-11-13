---
tags: [partiel, TNS, filtres-numeriques, 2A, fiche]
source: "[[Notions_SFN_T2_TS224.pdf]] + [[Complements_SFN_T2_TS224.pdf]] + notes de cours + [[TD.pdf]]"
prof: E. Grivel
---

# Fiche 2A : filtres numériques & estimation

> [!note] Ce que couvre la fiche
> Ch. 1 (filtres analogiques), ch. 2 (RIF), ch. 3 (RII), ch. 4 (filtre adapté), et le cours en amphi (TFD/FFT, fenêtres, périodogrammes, pôles/zéros, AR/ARMA, moindres carrés). Le TD n'a traité que les exercices 1.1 à 1.5 : ce sont les méthodes à maîtriser.

## 1. Signaux à temps discret : TFTD, TFD, FFT

- **TFTD** : $X(f)=\sum_nx(n)e^{-j2\pi nf/f_e}$. Elle est **périodique de période $f_e$** : on l'observe sur $[-\frac{f_e}2,\frac{f_e}2]$.
- Fréquence normalisée $\nu=f/f_e\in[-\frac12,\frac12]$, pulsation $\theta=2\pi f/f_e\in[-\pi,\pi]$.
- Plan $z$ : $z=e^{j2\pi f/f_e}$ décrit le **cercle unité**. $z=1$ correspond à $f=0$, $z=-1$ à $\pm f_e/2$, $z=j$ à $f_e/4$.
- Transformée en z : $X(z)=\sum x(n)z^{-n}$ ; un retard d'un échantillon multiplie par $z^{-1}$.
- Signal **réel** : $|X(f)|$ pair, donc $[0,f_e/2]$ suffit. Signal **complexe** : pas de symétrie, la partie négative ne se déduit pas de la positive (TD 1.9).
- **TFD sur $N$ points** : $X(k)=\sum_{n=0}^{N-1}x(n)e^{-j2\pi nk/N}$, aux fréquences $f_k=k\frac{f_e}N$, $k=0..N-1$. Pas fréquentiel : $f_e/N$.
  - Le point $k$ et le point $N-k$ correspondent à $\pm f_k$ : pour $k>N/2$, on lit des fréquences négatives (d'où `fftshift`).
- **FFT** : algorithme rapide de la TFD (même résultat), en $N\log_2N$ opérations au lieu de $N^2$, pour $N=2^m$. Décimation temporelle : $X(k)=U(k)+e^{-j2\pi k/N}V(k)$ (TFD des échantillons pairs + TFD des impairs).
- **Zero-padding** (ajout de zéros jusqu'à $2^m$, ex. 1000 → 1024) :
  - il permet la FFT et donne une **grille plus fine** (interpolation du spectre) ;
  - il n'ajoute **aucune information** et n'améliore **pas** la résolution réelle, qui est fixée par la durée d'observation ($\approx f_e/N_{\text{réel}}$) ;
  - il ne change pas la TFTD théorique.
- Alternative : **tronquer** à $2^m$ échantillons (ex. 512) : pas de zéro ajouté, mais on **perd de l'information** et la résolution se dégrade.

> [!example] TD 1.2 : $N=100$, $f_e=500$ Hz, bande 30-58 Hz
> TFD : pas de 5 Hz, fréquences observées **30, 35, 40, 45, 50, 55 Hz** ($k=6..11$), plus les symétriques $k=89..94$ pour un signal réel.
> FFT avec zero-padding à 128 : pas de 3,906 Hz, donc **31,25 ; 35,16 ; 39,06 ; 42,97 ; 46,88 ; 50,78 ; 54,69 Hz** ($k=8..14$).
> FFT avec troncature à 64 : pas de 7,81 Hz, donc **31,25 ; 39,06 ; 46,88 ; 54,69 Hz** (information perdue).

### Fenêtrage
- Observer $N$ points revient à multiplier par une fenêtre, donc à **convoluer** le spectre par $W(f)$.
- Fenêtre rectangulaire : $|W(f)|=\left|\frac{\sin(\pi Nf/f_e)}{\sin(\pi f/f_e)}\right|$. Elle vaut $N$ en 0, s'annule aux multiples de $f_e/N$, a un lobe principal de largeur $2f_e/N$ et un 1er lobe secondaire à **−13 dB**.
- Une sinusoïde $f_0$ qui n'est **pas** multiple de $f_e/N$ voit son pic mal placé et son énergie **fuir** dans les lobes secondaires.

| Fenêtre | Lobes secondaires | Lobe principal | Décroissance |
|---|---|---|---|
| Rectangulaire | −13 dB (mauvais) | référence | 20 dB/déc |
| Triangulaire | −25 dB | ×2 | 40 dB/déc |
| Hanning | −31 dB | ×2 | 60 dB/déc |
| Hamming | −41 dB | ×2 | 20 dB/déc |
| Blackman | −59 dB | ×3 | 60 dB/déc |
| Kaiser | −30 à −40 dB (réglable) | ~×2 | 20 dB/déc |

**Compromis** : un lobe principal étroit donne une bonne **résolution** ; des lobes secondaires bas donnent une bonne **dynamique** (peu de fuite). On ne peut pas gagner sur les deux tableaux.

### Analyse spectrale (estimation de la DSP)
- **Périodogramme** : $\frac1N|X(f)|^2$ sur une réalisation. Estimateur de forte variance.
- **Bartlett** : on découpe la réalisation en $K$ segments **sans recouvrement**, on calcule un périodogramme par segment et on **moyenne**. La variance diminue mais la résolution se dégrade, car $N$ par segment est plus petit (fenêtrage).
- **Welch** : comme Bartlett, avec **recouvrement** (souvent 50 %) et une fenêtre non rectangulaire (Hamming/Hanning). Il lisse davantage, au prix de plus de calculs.
- **Corrélogramme** : TF de l'autocorrélation estimée (Wiener-Khintchine).
- **Spectrogramme** : TF sur une fenêtre glissante (avec recouvrement), ce qui donne une représentation **temps-fréquence**. Fenêtre de 20-40 ms pour la parole (quasi-stationnarité), soit 160 à 320 échantillons à 8 kHz. Utile pour un **chirp** (fréquence qui varie au cours du temps, radar/sonar).
- La DSP théorique est une moyenne sur une **infinité** de réalisations ; le spectre d'une réalisation n'est qu'une estimation.

## 2. Filtres numériques : bases

Équation aux différences : $\sum_{i=0}^{M-1}a_iy(n-i)=\sum_{j=0}^{N-1}b_jx(n-j)$, avec $a_0=1$, ce qui donne
$$H(z)=\frac{B(z)}{A(z)}=\frac{\sum b_jz^{-j}}{1+\sum_{i\ge1}a_iz^{-i}},\qquad y=h*x.$$
- **Causal** : $h(n)=0$ pour $n<0$. L'équation n'utilise que des entrées présentes/passées (pas de $x(n+k)$).
- **Stable** (EBSB) : $\sum|h(n)|<\infty$. Pour un filtre **causal**, c'est équivalent à **tous les pôles strictement dans le cercle unité**.
- **RIF** (réponse impulsionnelle finie) : tous les $a_i=0$ pour $i\ge1$, $h(n)=b_n$, **non récursif**, **toujours stable**. Ses pôles sont tous en $z=0$ (s'il est causal).
- **RII** : récursif ($y$ dépend de $y$ passés), avec au moins un pôle non nul **non compensé**.
  - Piège (TD 1.6) : une structure récursive peut être RIF si ses pôles sont **simplifiés** par des zéros. Exemple : $\frac{1-z^{-3}}{1-z^{-1}}=1+z^{-1}+z^{-2}$.
- Trois façons de justifier RIF/RII : la forme de l'équation aux différences, la réponse impulsionnelle finie ou non, les pôles hors de 0 non simplifiés.
- Structures : forme directe, cascade, **treillis (lattice)**, **échelle**.

### Lecture géométrique pôles/zéros
$$|H(f)|=|b_0|\frac{\prod_i|e^{j2\pi f/f_e}-z_i|}{\prod_k|e^{j2\pi f/f_e}-p_k|}$$
Le module est le produit des distances aux zéros divisé par le produit des distances aux pôles.
- Un **zéro sur le cercle** en $e^{j\theta_0}$ donne une **réjection totale** en $f_0=\theta_0f_e/(2\pi)$. Près du cercle, l'atténuation est forte mais pas totale.
- Un **pôle près du cercle** donne une **résonance** (pic), d'autant plus aiguë que $r\to1$. Un pôle **sur** le cercle donne un filtre instable (résonance infinie).
- Pôles et zéros à l'origine : effet nul sur $|H|$ (simple retard).
- Coefficients **réels** ⇒ pôles/zéros réels ou par paires **conjuguées** ⇒ $|H(f)|$ pair.
- **Filtre réjecteur (notch)** de $\pm f_0$ (TD 1.8) : avec $\theta_0=2\pi f_0/f_e$,
$$H(z)=\frac{1-2\cos\theta_0z^{-1}+z^{-2}}{1-2r\cos\theta_0z^{-1}+r^2z^{-2}},\quad r\lesssim1$$
  Les zéros sur le cercle tuent $f_0$ ; les pôles juste derrière, au même angle, rendent le creux très étroit. Pour 1000 Hz avec $f_e=10$ kHz : $\theta_0=\pi/5$, $\cos\theta_0\approx0{,}809$.
  Équation aux différences : $y(n)=x(n)-2\cos\theta_0\,x(n-1)+x(n-2)+2r\cos\theta_0\,y(n-1)-r^2y(n-2)$.

### 2e ordre $H=1/(1+a_1z^{-1}+a_2z^{-2})$ (TD 1.10)
- Stable ⇔ $|a_2|<1$ **et** $|a_1|<1+a_2$ (**triangle** dans le plan $(a_1,a_2)$).
- Pôles **complexes** si $a_1^2<4a_2$ (sous la parabole $a_2=a_1^2/4$) : alors $|p|=\sqrt{a_2}$ et $\cos\theta=-a_1/(2\sqrt{a_2})$.

## 3. Filtres RIF

- $H(z)=\sum_{n=0}^{N-1}h(n)z^{-n}$. Ordre typique : **25 à 400**.
- Exemples : $\frac12[\delta(k)+\delta(k-1)]$ donne $H(f)=e^{-j\pi f/f_e}\cos(\pi f/f_e)$ (« **cosinusoïde** », passe-bas, nul en $\pm f_e/2$, retard $T_e/2$). Si tous les coefficients sont égaux, on parle de filtre en **peigne**. Mettre deux filtres en cascade rend la coupure plus sélective.
- **Avantages** : phase linéaire possible (pas de distorsion de phase), toujours stables, bruit de calcul maîtrisé. **Inconvénient** : ordre élevé pour un gabarit donné, donc plus de calculs.

### Phase linéaire
$\varphi(f)=\beta-2\pi\alpha\frac f{f_e}$. Il faut $h(n)=\pm h(N-1-n)$ (symétrie ou antisymétrie). On a alors $\alpha=\frac{N-1}2$ et le **retard de groupe est constant**, égal à $\frac{N-1}2$ échantillons.

**Convention du prof (table 2.2), à retenir telle quelle :**

| | $h(n)=h(N-1-n)$ (sym.) | $h(n)=-h(N-1-n)$ (antisym.) |
|---|---|---|
| **$N$ pair** | **Type I** ($\beta=0$ ou $\pi$) | **Type III** ($\beta=\pm\pi/2$) |
| **$N$ impair** | **Type II** | **Type IV** |

- Antisymétrique : $H(0)=\sum h=0$, donc **pas de passe-bas**.
- Sym. avec $N$ pair (type I du prof) : zéro forcé en $z=-1$, donc $H(f_e/2)=0$ et **pas de passe-haut**.
- Antisym. avec $N$ impair (type IV du prof) : $h(\frac{N-1}2)=0$ et des zéros en $z=\pm1$, donc il ne peut faire que du **passe-bande**.
- Zéros : si $z_i$ est un zéro, $1/z_i$ aussi, et avec des coefficients réels $z_i^*$ et $1/z_i^*$ aussi (**quadruplets**). Un RIF à phase linéaire **ne peut donc pas être à minimum de phase** (sauf zéros sur le cercle).

> [!warning] Les numéros de type varient selon les livres
> Beaucoup de livres appellent « type I » le cas symétrique avec $N$ **impair**. Au partiel, utilise la table **du prof** ci-dessus.

### Synthèse par la méthode de la fenêtre
1. Passe-bas idéal de coupure $f_c$ : $h_{id}(k)=2\frac{f_c}{f_e}\frac{\sin(2\pi kf_c/f_e)}{2\pi kf_c/f_e}$, avec $h_{id}(0)=2f_c/f_e$. Cette réponse est **infinie et non causale**.
2. On **tronque** avec une fenêtre (support $N=2L+1$), puis on **décale** de $L$ pour rendre le filtre causal. Le décalage ne change que la phase.
3. Passe-haut : $h_{ph}(k)=\delta(k-L)-h_{pb}(k)$, car $H_{ph}+H_{pb}=1$.
- Avec une fenêtre rectangulaire, augmenter l'ordre **resserre la transition** mais **ne réduit pas** l'amplitude des oscillations (**Gibbs**). Il faut changer de fenêtre (Hamming…) pour baisser les ondulations, au prix d'une transition plus large.
- La méthode est optimale au sens de l'erreur quadratique $\int|H_{id}-H|^2$, mais elle **ne permet pas de répartir l'erreur** entre les bandes : l'erreur se concentre dans la transition.

### Synthèse optimale (Remez / Parks-McClellan)
- Critère **minimax** pondéré par $W(f)$ : ondulations **égales** (equiripple) dans la bande passante ($\delta_1$) et dans la bande atténuée ($\delta_2$).
- **Théorème d'alternance** de Tchebychev : la fonction d'erreur présente au moins $\frac{N-1}{2}+m$ extrema alternés.
- On contrôle directement $f_p,f_a,\delta_1,\delta_2$. Ordre de Kaiser : $M\approx\dfrac{-20\log_{10}\sqrt{\delta_1\delta_2}-13}{14{,}6\,\Delta f}+1$, avec $\Delta f=(f_a-f_p)/f_e$. Plus la transition est étroite ou les ondulations faibles, plus l'ordre augmente.

## 4. Filtres RII

- Récursifs, réponse impulsionnelle infinie, ordre typique **5 à 20** (plus faible qu'un RIF pour le même gabarit). Ils peuvent être **instables** et n'ont pas de phase linéaire exacte.
- **Sans perte** (énergie conservée) + stable + ordre fini ⇔ **passe-tout** : $|H(f)|=1$ pour tout $f$. Les zéros sont les **inverses conjugués** des pôles ($z_k=1/p_k^*$). Exemples RIF : $\pm z^{-m}$.
- **Minimum de phase** : causal, stable, **tous les zéros dans le disque unité**. Parmi tous les filtres de même $|H|$, c'est celui qui a le **retard de groupe minimal**.
- Tout filtre se décompose en $H=H_{\min\varphi}\times H_{\text{passe-tout}}$ : on « retourne » les zéros extérieurs $z_i\to1/z_i^*$.
- **Filtre inverse** $1/H$ : stable seulement si les zéros de $H$ sont dans le disque unité (donc $H$ à minimum de phase). Sinon, on stabilise via la décomposition ci-dessus.
- $H(z/\rho)$ (TD 1.11) : les pôles $p$ deviennent $\rho p$. Avec $\rho<1$, ils se rapprochent de 0 et les résonances **s'aplatissent** ; avec $\rho>1$, elles **s'accentuent**, avec un risque d'instabilité si $\rho|p|\ge1$.
- DSP en sortie de $1/A(z)$ pour un bruit blanc d'entrée de variance $\sigma^2$ : $\sigma^2/|A(e^{j2\pi f/f_e})|^2$.

## 5. Synthèse RII à partir d'un filtre analogique

| Méthode | Principe | Stabilité | Défaut |
|---|---|---|---|
| **Invariance impulsionnelle** | $h(n)=h_c(nT_e)$. On décompose $H_c(p)=\sum\frac{r_i}{p-p_i}$, d'où $H(z)=\sum\frac{r_i}{1-e^{p_iT_e}z^{-1}}$ | conservée ($|e^{p_iT_e}|<1$ si $\Re p_i<0$) | **repliement**, car $H(f)=\frac1{T_e}\sum_kH_c(f-k/T_e)$ : valable seulement pour une réponse à bande limitée (passe-bas, pas passe-haut), sans discontinuité de $h_c$ |
| **Invariance indicielle** | on conserve la réponse **indicielle** : même procédure sur $H_c(p)/p$ | conservée | idem |
| **Bilinéaire** | $p=\frac{2}{T_e}\frac{1-z^{-1}}{1+z^{-1}}$, issue de l'intégration par la méthode des **trapèzes** | **toujours conservée** : le demi-plan gauche est envoyé dans le disque unité, l'axe $j\omega$ sur le cercle | **distorsion des fréquences (warping)** : $\omega_c=\frac2{T_e}\tan\frac{\omega_dT_e}2$, linéaire seulement en BF. Il faut **pré-distordre** les fréquences du gabarit. Pas de repliement |
| Différence **rétrograde** | $p=\frac{1-z^{-1}}{T}$ | conservée (le demi-plan gauche va dans le disque de centre ½ et de rayon ½) | n'utilise qu'une petite zone du disque |
| Différence **progressive** | $p=\frac{z-1}{T}$ | **pas garantie** (le demi-plan gauche va dans $\Re z<1$, qui déborde du disque) | peut donner un filtre **instable** |

- Transformations passe-bas → passe-haut, passe-bande, coupe-bande : $z^{-1}\to f(Z^{-1})$. Pour le passe-haut : $z^{-1}\to-\frac{Z^{-1}+\alpha}{1+\alpha Z^{-1}}$.

## 6. Prototypes analogiques (ch. 1)

Atténuation $A^2(jx)=1/|H(jx)|^2=1+\varepsilon^2|\varphi(jx)|^2$ avec $x=f/f_c$. Un filtre idéal est **irréalisable** (théorème de Paley-Wiener) : on travaille avec un **gabarit** (bande passante, bande de transition, bande atténuée).

| Filtre | $|H|^2$ | Bande passante | Bande atténuée | À retenir |
|---|---|---|---|---|
| **Butterworth** (MFM) | $\frac1{1+x^{2n}}$ | **maximalement plate**, monotone | monotone | −3 dB en $x=1$ **quel que soit $n$** ; pôles sur le **cercle** unité ; −20$n$ dB/décade ; ordre élevé |
| **Tchebychev I** | $\frac1{1+\varepsilon^2C_n^2(f/f_p)}$ | **ondulations égales** ($n$ extrema) | monotone | plus raide que Butterworth à ordre égal ; pôles sur une **ellipse** ; $|H(f_p)|^2=\frac1{1+\varepsilon^2}$ ; $C_n(1)=1$ |
| **Tchebychev II** (inverse) | pôles **et zéros** | plate (monotone) | ondulations égales | zéros de transmission dans la bande atténuée |
| **Cauer** (elliptique) | fraction rationnelle | ondulations | ondulations | **ordre minimal** pour un gabarit donné |
| **Bessel-Thomson** | $\frac{K}{B_n(p)}$ | — | — | **retard de groupe maximalement plat**, phase ≈ linéaire, faible sélectivité |
| **Papoulis** ($O_n$) | $\frac1{1+\varepsilon^2L_n(x^2)}$ | **sans ondulation** | monotone | plus raide que Butterworth : compromis entre Butterworth et Tchebychev |

- Polynômes de Tchebychev : $C_n(x)=\cos(n\arccos x)$ pour $|x|\le1$, $\cosh(n\,\mathrm{argch}\,x)$ au-delà. $C_{n}=2xC_{n-1}-C_{n-2}$, $C_0=1$, $C_1=x$.
- Exemple du cours (40 dB à 4000 Hz, 0,5 dB à 3200 Hz) : Butterworth d'**ordre 26**, Tchebychev d'**ordre 10**.
- Ordre de Butterworth (pour mémoire) : $n\ge\dfrac{\log\sqrt{\frac{10^{A_a/10}-1}{10^{A_p/10}-1}}}{\log(f_a/f_p)}$. Pour Tchebychev, même formule avec $\operatorname{argch}$ à la place de $\log$.

## 7. Retards
- Retard de phase $\tau_\varphi=-\frac{\varphi(f)}{2\pi f}$ ; **retard de groupe** $\tau_g=-\frac1{2\pi}\frac{d\varphi}{df}$.
- Phase linéaire ⇒ $\tau_g=\tau_\varphi$ constant ⇒ toutes les fréquences sont retardées pareil : **pas de distorsion de phase**.
- Une phase affine $\varphi=\beta f+\chi$ (avec $\chi\neq0$) est aussi appelée « linéaire », mais elle introduit une distorsion de phase.

## 8. Modélisation paramétrique & estimation (amphi)
- **MA** : $x(n)=\sum b_ju(n-j)$, tout zéro (RIF). **AR** : tout pôle (RII), causal, stable si les pôles sont dans le disque. **ARMA** : les deux.
- DSP : $S_x(f)=\sigma_u^2|H(f)|^2$. Les pics viennent des pôles (formants de la parole) et les creux des zéros.
- Estimation AR par **moindres carrés** : $\mathbf x=A\boldsymbol\theta+\mathbf u$, avec $J=\mathbf u^T\mathbf u$ et $\nabla J=-2A^T\mathbf x+2A^TA\boldsymbol\theta=0$, d'où $\hat{\boldsymbol\theta}=(A^TA)^{-1}A^T\mathbf x$ ($A\hat\theta$ est la projection orthogonale de $\mathbf x$).
- Marqueurs temporels (moyenne, puissance, énergie, taux de passage par zéro, kurtosis/skewness, entropie, divergence KL) et fréquentiels (puissance par bande, platitude spectrale), EMD → IMF.
- **Décimation** : filtrer en passe-bas **avant**, sinon on ne respecte plus Shannon (repliement).

## 9. Filtre adapté (ch. 4)
- Objectif : détecter un signal **connu** $s_1(t)$ noyé dans un bruit, en **maximisant le RSB** à l'instant $t_1$ : $R_0(t_1)=\frac{|s_2(t_1)|^2}{E[b_2^2(t_1)]}$.
- Bruit blanc : Schwarz donne $H_{opt}(f)=\lambda S_1^*(f)e^{-j2\pi ft_1}$, soit $h_{opt}(t)=\lambda\,s_1^*(t_1-t)$ (pour un signal réel : $s_1(t_1-t)$, la forme du signal **retournée et décalée**).
- **Causalité** : il faut $t_1\ge$ la fin du signal (tout le signal a « traversé » le filtre).
- La sortie ressemble à l'**autocorrélation** de $s_1$ : pic en $t_1$.
- Le RSB maximal est **proportionnel à l'énergie** du signal, divisée par la DSP du bruit. Il **ne dépend pas de la forme** de $s_1$. Le gain $\lambda$ n'a aucune influence (il agit pareil sur le signal et le bruit).
- Applications : radar, communications numériques (récepteur optimal).

---

## Pièges

> [!danger] À relire le jour J
> 1. Le zero-padding n'améliore **pas** la résolution ; il interpole.
> 2. Un RIF est **toujours stable** ; un filtre récursif n'est pas forcément RII (simplification pôle/zéro).
> 3. Un filtre causal est stable ⇔ ses pôles sont **strictement** dans le disque. Un pôle sur le cercle donne un filtre instable.
> 4. Un zéro **sur** le cercle donne une réjection **totale** ; près du cercle, seulement une forte atténuation.
> 5. Phase linéaire ⇔ symétrie/antisymétrie de $h$ ; retard de groupe $(N-1)/2$. Un RII causal ne peut **pas** avoir une phase exactement linéaire.
> 6. Types I-IV : **convention du prof**.
> 7. Bilinéaire : stabilité **conservée**, pas de repliement, mais **warping** (il faut pré-distordre).
> 8. Invariance impulsionnelle : stabilité conservée, mais **repliement** ; pas adaptée au passe-haut.
> 9. Différence progressive : risque d'**instabilité**.
> 10. Butterworth : −3 dB à $f_c$ quel que soit l'ordre ; Tchebychev I : ondulations dans la bande **passante** ; Tchebychev II : dans la bande **atténuée** ; Cauer : dans les **deux**.
> 11. Bessel = la **phase** (retard de groupe plat), pas la sélectivité.
> 12. Fenêtre rectangulaire : la meilleure résolution, mais les pires lobes secondaires (−13 dB).
> 13. Welch : moins de variance, plus de calculs, une résolution qui se dégrade (segments plus courts).
> 14. Filtre adapté : $h(t)=s(t_1-t)$, RSB max ∝ énergie, indépendant de la forme.
> 15. Spectre d'un signal réel : symétrique ; d'un signal complexe : **pas forcément**.
