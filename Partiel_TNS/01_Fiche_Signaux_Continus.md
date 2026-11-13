---
tags: [partiel, TNS, signaux-continus, 1A, fiche]
source: "[[TD1A_Signaux.pdf]] + [[Signaux_Continus_Cours_Marco.pdf]]"
prof: E. Grivel
---

# Fiche 1A : signaux continus déterministes

## 1. Classification & grandeurs

- À temps continu (observable à tout instant), à temps discret (à $t=kT_e$), échantillonné ; déterministe ou aléatoire.
- Moyenne : $\bar x=\lim_{T\to\infty}\frac1T\int_{-T/2}^{T/2}x(t)dt$. Pour un signal périodique : $\frac1{T_0}\int_{T_0}x=c_0$.
- **Énergie** $E=\int|x|^2dt$. **Puissance** $P=\lim\frac1T\int_{-T/2}^{T/2}|x|^2dt$.
  - Énergie finie (signal transitoire) ⇒ $P=0$.
  - Périodique ⇒ énergie **infinie**, puissance finie : $P=\frac1{T_0}\int_{T_0}|x|^2$.
- Signaux élémentaires : porte $\Pi_\tau(t)$ (amplitude 1, durée $\tau$, centrée), échelon $u(t)$, rampe $r(t)=t\,u(t)$ (avec $r'=u$), triangle $\Lambda$, $\delta$ (avec $u'=\delta$).
- Décalage/échelle : $x(at-b)=x\big(a(t-\frac ba)\big)$ : on **comprime** d'un facteur $a$, puis on **décale** de $b/a$. $\Pi_\tau(at)=\Pi_{\tau/|a|}(t)$.

## 2. Distributions & Dirac

- $\int\delta=1$ ; $f(t)\delta(t-t_0)=f(t_0)\delta(t-t_0)$ ; $\int f(t)\delta(t-t_0)dt=f(t_0)$.
- $f*\delta(t-t_0)=f(t-t_0)$ : convoler avec un Dirac **décale**. $\delta$ est l'élément neutre de $*$.
- $\delta(at)=\frac{1}{|a|}\delta(t)$.
- Dérivée au sens des distributions : un saut de hauteur $h$ en $t_0$ donne un terme $h\,\delta(t-t_0)$. Exemple : $\Pi_\tau'(t)=\delta(t+\frac\tau2)-\delta(t-\frac\tau2)$.
- Peigne de Dirac $Ш_T(t)=\sum_k\delta(t-kT)$. Fonction-test : $C^\infty$ à support borné. Fonction plate en $a$ : toutes ses dérivées y sont nulles (ex. $e^{-1/x}$ prolongée par 0).

## 3. Convolution & systèmes LTI

$$(x*h)(t)=\int x(\tau)h(t-\tau)d\tau$$
- Commutative, associative, distributive. Neutre : $\delta$.
- Supports $[a,b]$ et $[c,d]$ donnent le support $[a+c,b+d]$ : les **durées s'additionnent**.
- $\Pi_T*\Pi_T=T\,\Lambda$ : triangle de base $2T$ et de hauteur $T$.
- $e^{-at}u(t)*e^{-bt}u(t)=\frac{e^{-at}-e^{-bt}}{b-a}u(t)$ si $a\neq b$, et $t\,e^{-at}u(t)$ si $a=b$.
- Système LTI : $y=h*x$, où $h$ est la **réponse impulsionnelle**. Causal ⇔ $h(t)=0$ pour $t<0$. Stable (EBSB) ⇔ $\int|h|<\infty$.

## 4. Corrélation

- Énergie finie : $R_{xy}(\tau)=\int x(t)y^*(t-\tau)dt=x(\tau)*y^*(-\tau)$.
- Puissance finie : $R_{xy}(\tau)=\lim\frac1T\int_{-T/2}^{T/2}x(t)y^*(t-\tau)dt$.
- Propriétés de $R_{xx}$ :
  - $R_{xx}(0)=E$ (ou $P$) : maximum en module, $|R_{xx}(\tau)|\le R_{xx}(0)$ ;
  - $R_{xx}(-\tau)=R^*_{xx}(\tau)$, donc paire pour un signal réel ;
  - **invariante par retard** : $x(t-t_0)$ a la même autocorrélation que $x(t)$, la phase est perdue ;
  - signal périodique ⇒ $R_{xx}$ périodique de **même période**.
- $A\cos(2\pi f_0t+\varphi)$ a pour autocorrélation $\frac{A^2}{2}\cos(2\pi f_0\tau)$ (indépendante de $\varphi$).
- **Radar/GPS** : l'intercorrélation entre le signal émis et le signal reçu (copie retardée bruitée) présente un pic au **retard** $\tau_0$. Distance radar : $d=c\tau_0/2$ (aller-retour).
- Lien avec l'aléatoire : pour un processus SSL **ergodique**, l'autocorrélation statistique est égale à l'autocorrélation temporelle d'une réalisation.

## 5. Séries de Fourier (signal $T_0$-périodique)

$$x(t)=\sum_kc_ke^{j2\pi kt/T_0},\qquad c_k=\frac1{T_0}\int_{T_0}x(t)e^{-j2\pi kt/T_0}dt$$
- $x$ réel ⇒ $c_{-k}=c_k^*$, donc $|c_k|$ est pair, et $x(t)=c_0+\sum_{k\ge1}2|c_k|\cos(2\pi kt/T_0+\varphi_k)$, avec $c_k=\frac{a_k-jb_k}2$.
- $x$ réel pair ⇒ $c_k$ réels ; $x$ réel impair ⇒ $c_k$ imaginaires purs.
- **Spectre discret** (raies en $k/T_0$). $c_0$ est la valeur moyenne.
- **Parseval** : $P=\frac1{T_0}\int_{T_0}|x|^2=\sum_k|c_k|^2$ (la puissance totale est la somme des puissances des harmoniques).

## 6. Transformée de Fourier

$$X(f)=\int x(t)e^{-j2\pi ft}dt,\qquad x(t)=\int X(f)e^{j2\pi ft}df$$

| Propriété | Temps | Fréquence |
|---|---|---|
| Retard | $x(t-t_0)$ | $e^{-j2\pi ft_0}X(f)$ (même $|X|$) |
| Modulation | $x(t)e^{j2\pi f_0t}$ | $X(f-f_0)$ |
| Échelle | $x(at)$ | $\frac1{|a|}X(f/a)$ |
| Conjugaison | $x^*(t)$ | $X^*(-f)$ |
| Retournement | $x(-t)$ | $X(-f)$ |
| Convolution | $x*y$ | $XY$ |
| Produit | $xy$ | $X*Y$ |
| Dérivation | $x'(t)$ | $j2\pi fX(f)$ |
| Dualité | $X(t)$ | $x(-f)$ |

- $x$ **réel** ⇒ $X(-f)=X^*(f)$ (hermitienne) : $|X|$ **paire**, phase **impaire**.
  - réel pair ⇒ $X$ réelle paire ; réel impair ⇒ $X$ imaginaire pure impaire.
- Paires à connaître :
  - $\Pi_T(t)\leftrightarrow T\,\mathrm{sinc}(\pi fT)=T\frac{\sin(\pi fT)}{\pi fT}$ : zéros en $k/T$ ($k\neq0$), lobe principal de largeur $2/T$, lobes secondaires décroissants ;
  - $\delta(t)\leftrightarrow1$ et $1\leftrightarrow\delta(f)$ ;
  - $e^{j2\pi f_0t}\leftrightarrow\delta(f-f_0)$ ;
  - $\cos(2\pi f_0t)\leftrightarrow\frac12[\delta(f-f_0)+\delta(f+f_0)]$ et $\sin(2\pi f_0t)\leftrightarrow\frac1{2j}[\delta(f-f_0)-\delta(f+f_0)]$ ;
  - $Ш_T(t)\leftrightarrow\frac1TШ_{1/T}(f)$ ;
  - $\Lambda$ (triangle) $\leftrightarrow\mathrm{sinc}^2$.
- Signal périodique : $X(f)=\sum_kc_k\delta(f-k/T_0)$.
- **Parseval/Plancherel** : $\int|x|^2dt=\int|X|^2df$.
- Plus un signal est court en temps, plus il est large en fréquence (et inversement).
- Laplace : $X(p)=\int x(t)e^{-pt}dt$. Avec $p=j2\pi f$, on retrouve la TF (si elle converge).

## 7. Densité spectrale & Wiener-Khintchine

- **Wiener-Khintchine** : $S_{xx}(f)=\mathrm{TF}[R_{xx}(\tau)]$.
- Énergie finie : $S_{xx}(f)=|X(f)|^2$ (densité spectrale **d'énergie**) et $\int S_{xx}=E=R_{xx}(0)$.
- Puissance finie / aléatoire SSL : DSP, avec $\int S_{xx}=P=R_{xx}(0)$.
- Signal périodique : $S_{xx}(f)=\sum|c_k|^2\delta(f-k/T_0)$.
- La DSP est **réelle et ≥ 0**, et paire si le signal est réel.
- **Filtrage** : $S_{yy}(f)=|H(f)|^2S_{xx}(f)$ et $S_{yx}(f)=H(f)S_{xx}(f)$. Moyenne de sortie : $m_y=H(0)\,m_x$.
- Bruit blanc : DSP constante, $R(\tau)\propto\delta(\tau)$.

## 8. Échantillonnage (Shannon)

- $x_e(t)=x(t)\,Ш_{T_e}(t)$, d'où $X_e(f)=\frac1{T_e}\sum_kX(f-kf_e)$ : le spectre est **périodisé** avec la période $f_e$.
- **Shannon** : si $x$ est à bande limitée $[-B,B]$ et $f_e>2B$, on reconstruit $x$ par un passe-bas idéal de coupure $f_e/2$ (interpolation en sinc).
- Sinon, il y a **repliement (aliasing)**, **irréversible**. On place donc un filtre **anti-repliement** **avant** l'échantillonnage.
- Bloqueur d'ordre 0 (CNA en marches d'escalier) : il multiplie le spectre par $T_e\,\mathrm{sinc}(\pi fT_e)e^{-j\pi fT_e}$, ce qui distord les hautes fréquences.

## 9. Modulation, Hilbert, hétérodynage

- $x(t)\cos(2\pi f_0t)\leftrightarrow\frac12[X(f-f_0)+X(f+f_0)]$ : translation du spectre.
- **Hétérodynage** : on multiplie par une sinusoïde puis on filtre, pour changer de bande.
- **Transformée de Hilbert** : filtre $H(f)=-j\,\mathrm{sgn}(f)$, soit $\hat x=x*\frac1{\pi t}$. Elle transforme $\cos$ en $\sin$.
- **Signal analytique** $z=x+j\hat x$ : $Z(f)=2X(f)u(f)$, **aucune fréquence négative**. L'enveloppe vaut $|z(t)|$.

---

## Pièges

> [!danger] À relire le jour J
> 1. Un signal périodique n'est **pas** à énergie finie (il est à puissance finie).
> 2. Un retard ne change **pas** le spectre d'amplitude, seulement la phase (linéaire en $f$).
> 3. Signal réel ⇒ spectre hermitien, mais pas forcément réel (il ne l'est que si le signal est **pair**).
> 4. $\mathrm{TF}[x(at)]=\frac1{|a|}X(f/a)$ : compresser en temps **élargit** le spectre.
> 5. L'autocorrélation perd la phase : deux signaux différents peuvent avoir la même $R_{xx}$.
> 6. $|R_{xx}(\tau)|\le R_{xx}(0)$, toujours ; le maximum est atteint en $\tau=0$ (et en $kT_0$ si le signal est périodique).
> 7. Le repliement est **irréversible** : on filtre **avant** d'échantillonner, pas après.
> 8. Convolution : les supports (durées) **s'additionnent**.
> 9. Le spectre d'un signal à temps discret est **périodique** (période $f_e$).
> 10. Le signal analytique n'a pas de fréquences négatives ; un signal réel en a toujours (symétrie hermitienne).
