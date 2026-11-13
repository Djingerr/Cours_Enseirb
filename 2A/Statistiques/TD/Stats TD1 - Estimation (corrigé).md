---
tags: [stats, td, estimation]
---
# TD1 — Estimation (méthodes + corrigés)

Prérequis : [[Stats 02 - Estimateurs et risque]], [[Stats 03 - Construire un estimateur (moments, MV)]], [[Stats 04 - Intervalles de confiance]], [[Stats 05 - Estimation bayésienne]]
Retour : [[00 - Stats Sommaire]]

> [!warning] Mode d'emploi
> Pour chaque question : lis l'**indice**, cherche 10 min sur papier, **puis** déplie le corrigé.

---
## Exercice 1 (★) — Poisson

**1. Modèle.**
> [!hint]- Indice
> Ensemble d'observations, famille de lois, $\Theta$.

> [!success]- Corrigé
> $\mathcal X=\mathbb N$, $\mathcal M=\{\mathcal P(\theta):\theta\in\Theta\}$ avec $\Theta=\mathbb R_+^*$. $\Theta\subset\mathbb R$ ⇒ **paramétrique** (et identifiable : $\mathbb E_\theta X=\theta$).

**2. MV, biais, EQM, consistance.**
> [!hint]- Indice
> Recette MV : log-vraisemblance, dérivée, concavité. Attention au cas $\sum X_k=0$.

> [!success]- Corrigé
> Avec $S=\sum X_k$ :
> $$\ell_n(\theta)=\sum_k\big(X_k\ln\theta-\theta-\ln X_k!\big)=S\ln\theta-n\theta-c.$$
> - Si $S>0$ : $\ell_n'(\theta)=\frac S\theta-n$, $\ell_n''(\theta)=-\frac S{\theta^2}<0$ ⇒ strictement concave, unique max en $\hat\theta_n=S/n=\bar X_n$.
> - Si $S=0$ : $\ell_n=-n\theta$ décroissante, sup en $0$ ; on pose $\hat\theta_n=0=\bar X_n$ (en prenant $\Theta=\mathbb R_+$ ; sinon, événement de proba $e^{-n\theta}\to0$).
>
> Donc $\boxed{\hat\theta_n=\bar X_n}$.
> - Biais : $\mathbb E_\theta[\bar X_n]=\theta$ ⇒ **sans biais**.
> - EQM : $R=\mathbb V[\bar X_n]=\frac{\mathbb V[X_1]}n=\boxed{\frac\theta n}$.
> - Consistance : $R\to0$ ⇒ (Markov) $P(|\hat\theta_n-\theta|>\epsilon)\le\frac{\theta}{n\epsilon^2}\to0$. (Ou directement LGN.)

**3. Normalité asymptotique.**
> [!success]- Corrigé
> TLC ($\mathbb E X_1^2<\infty$, $\mathbb V X_1=\theta$) : $\sqrt n(\bar X_n-\theta)\xrightarrow{\mathcal L}\mathcal N(0,\theta)$, donc $\boxed{v(\theta)=\theta}$.

**4. IC asymptotique.**
> [!hint]- Indice
> Normaliser par $\sqrt{v(\theta)}$ puis remplacer $\theta$ par $\hat\theta_n$ (Slutsky).

> [!success]- Corrigé
> $\sqrt n\frac{\bar X_n-\theta}{\sqrt{\bar X_n}}=\sqrt n\frac{\bar X_n-\theta}{\sqrt\theta}\cdot\sqrt{\frac\theta{\bar X_n}}$ ; 1er facteur $\to\mathcal N(0,1)$, 2nd $\xrightarrow{P}1$ (LGN + continuité de $x\mapsto\sqrt{\theta/x}$ en $\theta>0$). Slutsky ⇒ $\to\mathcal N(0,1)$. Avec $q=\Phi^{-1}(1-\alpha/2)$ :
> $$I_{\alpha,n}=\Big[\bar X_n-q\sqrt{\tfrac{\bar X_n}n},\ \bar X_n+q\sqrt{\tfrac{\bar X_n}n}\Big],\qquad P(\theta\in I_{\alpha,n})\to1-\alpha.$$

---
## Exercice 2 (★) — Bayésien Bernoulli–Beta

**1. Espérance de la Beta.**
> [!hint]- Indice
> $\mathbb E[\theta]=\frac{C(\alpha+1,\beta)}{C(\alpha,\beta)}$. IPP sur $C(\alpha+1,\beta)$ en dérivant $t^\alpha$ et intégrant $(1-t)^{\beta-1}$.

> [!success]- Corrigé
> $$C(\alpha+1,\beta)=\int_0^1t^\alpha(1-t)^{\beta-1}dt=\Big[-t^\alpha\frac{(1-t)^\beta}\beta\Big]_0^1+\frac\alpha\beta\int_0^1t^{\alpha-1}(1-t)^\beta dt=\frac\alpha\beta C(\alpha,\beta+1).$$
> En divisant par $C(\alpha,\beta)$ : $\mathbb E[\theta]=\frac\alpha\beta\mathbb E[1-\theta]=\frac\alpha\beta(1-\mathbb E[\theta])$ ⇒ $\boxed{\mathbb E[\theta]=\frac\alpha{\alpha+\beta}}$.

**2. Estimateur de Bayes (risque quadratique). Biais ?**
> [!hint]- Indice
> MMSE = moyenne a posteriori. Calculer la posterior à constante près et reconnaître une Beta.

> [!success]- Corrigé
> $\pi(\theta|X)\propto\theta^S(1-\theta)^{n-S}\cdot\theta^{\alpha-1}(1-\theta)^{\beta-1}$ ⇒ $\theta|X\sim\text{Beta}(\alpha+S,\beta+n-S)$. Par Q1 :
> $$\boxed{\hat\theta^B_n=\frac{\alpha+S}{\alpha+\beta+n}}.$$
> Biais (à $\theta$ fixé, $\mathbb E_\theta S=n\theta$) :
> $$B_\theta=\frac{\alpha+n\theta}{\alpha+\beta+n}-\theta=\frac{\alpha-(\alpha+\beta)\theta}{\alpha+\beta+n}.$$
> Nul **pour tout $\theta$** ssi $\alpha=0$ et $\alpha+\beta=0$, impossible car $\alpha,\beta>0$ ⇒ **jamais sans biais** ; le biais ne s'annule qu'en $\theta=\frac\alpha{\alpha+\beta}$ (moyenne a priori). Il tend vers 0 quand $n\to\infty$ (asymptotiquement sans biais).

**3. Risque quadratique ; choix de $\alpha,\beta$ rendant le risque constant.**
> [!success]- Corrigé
> $\mathbb V_\theta[\hat\theta^B]=\frac{n\theta(1-\theta)}{(\alpha+\beta+n)^2}$ ⇒
> $$R(\hat\theta^B,\theta)=\frac{n\theta(1-\theta)+(\alpha-(\alpha+\beta)\theta)^2}{(\alpha+\beta+n)^2}.$$
> Numérateur : $\theta^2\big[(\alpha+\beta)^2-n\big]+\theta\big[n-2\alpha(\alpha+\beta)\big]+\alpha^2$.
> Indépendant de $\theta$ ⇔ $(\alpha+\beta)^2=n$ et $2\alpha(\alpha+\beta)=n$ ⇔ $\boxed{\alpha=\beta=\frac{\sqrt n}2}$.
> Alors $\hat\theta^B=\frac{S+\sqrt n/2}{n+\sqrt n}=\frac{n\bar X_n+\sqrt n/2}{n+\sqrt n}$ et $R=\frac{n/4}{(n+\sqrt n)^2}=\frac1{4(1+\sqrt n)^2}$.
> **Commentaire** : c'est l'estimateur $\hat\theta^{(2)}$ du cours. Un estimateur de Bayes à risque constant est **minimax** : il minimise le pire risque $\sup_\theta R$.

**4. MV et biais.**
> [!success]- Corrigé
> $\ell_n=S\ln\theta+(n-S)\ln(1-\theta)$, $\ell_n'=\frac S\theta-\frac{n-S}{1-\theta}=0\Rightarrow\hat\theta^{MV}=\bar X_n$ (concave). **Sans biais**, $R=\frac{\theta(1-\theta)}n$.

**5. Comparaison.**
> [!success]- Corrigé
> Avec $\alpha=\beta=\sqrt n/2$ : $R^{MV}(\theta)=\frac{\theta(1-\theta)}n$ vs $R^B=\frac1{4(1+\sqrt n)^2}$.
> - En $\theta=1/2$ : $R^{MV}=\frac1{4n}>R^B$ ⇒ Bayes meilleur au centre.
> - Près de $0$ ou $1$ : $R^{MV}\to0$ ⇒ MV meilleur aux bords.
> - $\sup_\theta R^{MV}=\frac1{4n}>R^B$ : Bayes meilleur **dans le pire cas**.
> - Quand $n\to\infty$, les deux sont $\sim\frac1{4n}$ au centre : différence négligeable.
> Pour $\alpha,\beta$ généraux : Bayes est meilleur quand $\theta$ est proche de $\frac\alpha{\alpha+\beta}$ (a priori juste), moins bon sinon ; l'écart disparaît quand $n\to\infty$.

---
## Exercice 3 (★★) — Distributeur (TLC appliqué)
Retraits $X_k$ i.i.d., $\mu=70$, $\sigma=30$. $S_k=X_1+\dots+X_k\approx\mathcal N(70k,\,900k)$.

**1.** Somme minimale $m$ telle que $P(S_{400}\le m)\ge0{,}95$.
> [!success]- Corrigé
> $S_{400}\approx\mathcal N(28000,600^2)$. $P(S\le m)=\Phi\big(\frac{m-28000}{600}\big)\ge0{,}95\iff m\ge28000+1{,}645\times600$ ⇒ $\boxed{m\approx28\,987\text{ €}}$.

**2.** 30 000 €, 441 retraits.
> [!success]- Corrigé
> $S_{441}\approx\mathcal N(30870,630^2)$. $P(S_{441}\le30000)\approx\Phi\big(\frac{-870}{630}\big)=\Phi(-1{,}38)\approx\boxed{0{,}08}$. Très peu probable que tous soient servis (la moyenne dépasse déjà le stock).

**3.** Jusqu'à quel retrait $k$ est-on servi avec proba $\ge0{,}95$ ?
> [!hint]- Indice
> Le $k$-ième retrait est servi ssi $S_k\le30000$. Résoudre $70k+1{,}645\cdot30\sqrt k\le30000$ en posant $u=\sqrt k$.

> [!success]- Corrigé
> $70u^2+49{,}35u-30000\le0$ ⇒ $u\le\frac{-49{,}35+\sqrt{49{,}35^2+4\cdot70\cdot30000}}{140}\approx20{,}35$ ⇒ $k\le414{,}2$.
> **Retrait n°414** (vérif : $k=414$ : $28980+1{,}645\cdot30\sqrt{414}\approx29984\le30000$ ✓ ; $k=415$ : $\approx30055$ ✗).

---
## Exercice 4 (★★) — $f_\theta(x)=\frac{1+\theta}2|x|^\theta\mathbf 1_{[-1,1]}(x)$

**1. Densité.**
> [!success]- Corrigé
> $f_\theta\ge0$ et, par parité, $\int_{-1}^1f_\theta=(1+\theta)\int_0^1x^\theta dx=(1+\theta)\frac1{1+\theta}=1$.

**2. MV.**
> [!success]- Corrigé
> $\ell_n(\theta)=n\ln\frac{1+\theta}2+\theta\sum\ln|X_k|$. Posons $T=-\sum\ln|X_k|>0$ p.s.
> $\ell_n'=\frac n{1+\theta}-T=0\Rightarrow\theta=\frac nT-1$ ; $\ell_n''=-\frac n{(1+\theta)^2}<0$.
> $$\boxed{\hat\theta_n=\frac nT-1=-\frac n{\sum_k\ln|X_k|}-1}$$
> *(Rigueur : comme $\Theta=\mathbb R_+$, si $n/T-1<0$ le max sur $\Theta$ est en 0 : $\max(0,n/T-1)$. Le TD attend $n/T-1$ ; signale-le en une ligne.)*

**3. Biais et risque.**
> [!hint]- Indice
> Loi de $Y_k=-\ln|X_k|$ : calculer $P(Y_k>y)$. Puis $T$ = somme d'exponentielles ⇒ Gamma. Utiliser $\mathbb E[1/T]$, $\mathbb E[1/T^2]$ (voir [[Stats 01 - Rappels de probabilités]]). C'est là que sert $n>2$.

> [!success]- Corrigé
> $P(|X|\le t)=t^{1+\theta}$ sur $[0,1]$ ⇒ $P(Y>y)=P(|X|<e^{-y})=e^{-(1+\theta)y}$ : $Y_k\sim\mathcal E(\lambda)$, $\lambda=1+\theta$. Donc $T\sim\Gamma(n,\lambda)$.
> $\mathbb E[1/T]=\frac\lambda{n-1}$, $\mathbb E[1/T^2]=\frac{\lambda^2}{(n-1)(n-2)}$.
> - $\mathbb E[\hat\theta_n]=\frac{n\lambda}{n-1}-1$ ⇒ $\boxed{B=\frac{n\lambda}{n-1}-\lambda=\frac{1+\theta}{n-1}}$.
> - $\mathbb V[\hat\theta_n]=n^2\mathbb V[1/T]=n^2\lambda^2\Big(\frac1{(n-1)(n-2)}-\frac1{(n-1)^2}\Big)=\frac{n^2\lambda^2}{(n-1)^2(n-2)}$.
> - $R=B^2+\mathbb V=\frac{\lambda^2(n-2+n^2)}{(n-1)^2(n-2)}=\boxed{\frac{(1+\theta)^2(n+2)}{(n-1)(n-2)}}$ (car $n^2+n-2=(n+2)(n-1)$).
> → $R\to0$ : consistant. Sans biais : $\frac{n-1}{T}-1$.

---
## Exercice 5 (★★★) — Médiane empirique

**1. Densité jointe des statistiques d'ordre.**
> [!hint]- Indice
> Pour $A\subset D$, l'événement $\{(X_{(1)},\dots,X_{(n)})\in A\}$ est l'union disjointe (à un ensemble de proba nulle près — égalités) sur les $n!$ permutations $\sigma$ de $\{(X_{\sigma(1)},\dots,X_{\sigma(n)})\in A\}$.

> [!success]- Corrigé
> Les $X_k$ ont une densité ⇒ $P(X_i=X_j)=0$ pour $i\ne j$. Pour $A\subset D$ borélien :
> $$P\big((X_{(k)})_k\in A\big)=\sum_{\sigma\in\mathfrak S_n}P\big((X_{\sigma(k)})_k\in A\big)=n!\int_A\prod_kf(x_k)\,dx,$$
> car chaque $(X_{\sigma(1)},\dots,X_{\sigma(n)})$ a la même densité $\prod f(x_k)$ (i.i.d.). D'où $g=n!\prod_kf(x_k)\mathbf 1_D$.

**2. Marginale $g_k$.**
> [!success]- Corrigé
> On intègre $g$ sur toutes les variables sauf $x_k=x$ :
> - variables à gauche $x_1\le\dots\le x_{k-1}\le x$ : $\int\prod_{i<k}f(x_i)=\frac{F(x)^{k-1}}{(k-1)!}$ (volume ordonné = $1/(k-1)!$ du volume total $F(x)^{k-1}$) ;
> - à droite $x\le x_{k+1}\le\dots\le x_n$ : $\frac{(1-F(x))^{n-k}}{(n-k)!}$.
> D'où $g_k(x)=\frac{n!}{(k-1)!(n-k)!}f(x)F(x)^{k-1}(1-F(x))^{n-k}$.
> *(Intuition : $k-1$ points avant $x$, un en $x$, $n-k$ après — coefficient multinomial.)*

**3. Cas $\mathcal U([0,\theta])$.**
> [!success]- Corrigé
> $f=\frac1\theta$, $F(x)=\frac x\theta$ sur $[0,\theta]$ :
> $$g_k(x)=\frac{n!}{(k-1)!(n-k)!}\frac{x^{k-1}(\theta-x)^{n-k}}{\theta^n}\mathbf 1_{[0,\theta]}(x).$$
> Autrement dit $X_{(k)}/\theta\sim\text{Beta}(k,n-k+1)$.

**4. Médiane $\tilde X_n=X_{((n+1)/2)}$ : biais et risque.**
> [!hint]- Indice
> Avec $m=\frac{n+1}2$ : $\tilde X_n/\theta\sim\text{Beta}(m,m)$. Utiliser l'ex 2 (moyenne Beta) + variance de la Beta. La médiane vraie de $\mathcal U([0,\theta])$ est $\theta/2$.

> [!success]- Corrigé
> $\mathbb E[\tilde X_n]=\theta\frac m{2m}=\frac\theta2$ ⇒ **sans biais** pour la médiane $\theta/2$.
> $\mathbb V[\tilde X_n]=\theta^2\frac{m\cdot m}{(2m)^2(2m+1)}=\frac{\theta^2}{4(2m+1)}=\boxed{\frac{\theta^2}{4(n+2)}}=R$.
> *(Variance Beta : $\mathbb E[\theta^2]=\frac{a(a+1)}{(a+b)(a+b+1)}$ via la même IPP qu'à l'ex 2.)*
> Comparaison : $\bar X_n$ (aussi sans biais pour $\theta/2$) a $R=\frac{\theta^2}{12n}$ ⇒ la médiane est ≈3× moins précise ici (mais elle est robuste aux valeurs aberrantes).
