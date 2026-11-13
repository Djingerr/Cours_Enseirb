---
tags: [stats, cours, tests]
---
# 07 — Tests d'hypothèses

Précédent : [[Stats 06 - Régression linéaire]] · Fiche : [[Stats - Fiche mémo]]

## 1. Le cadre
$\Theta=\Theta_0\cup\Theta_1$ disjoints. $H_0:\theta\in\Theta_0$ (hypothèse nulle) contre $H_1:\theta\in\Theta_1$ (alternative).
**Statistique de test** : $T_n=T_n(X_1,\dots,X_n)\in\{0,1\}$. $T_n=1$ ⇔ on **rejette $H_0$** (on décide $H_1$).
Presque toujours : $T_n=\mathbf 1_{]\epsilon,\infty[}(S_n)$ = « rejeter si $S_n>\epsilon$ ».

- **Simple** : $\Theta_0$ (ou $\Theta_1$) réduit à un point ($\theta=\theta_0$).
- **Unilatère** : $\mu\le\mu_0$ vs $\mu>\mu_0$. **Bilatère** : $\mu=\mu_0$ vs $\mu\ne\mu_0$.

## 2. Erreurs, niveau, puissance

| | Vérité $H_0$ | Vérité $H_1$ |
|---|---|---|
| Décide $H_0$ ($T_n=0$) | ✅ | **Erreur II** ($\beta$) |
| Décide $H_1$ ($T_n=1$) | **Erreur I** ($\alpha$, fausse alarme) | ✅ (puissance) |

- **Risque de 1ère espèce** : $\alpha(\theta)=P_\theta(T_n=1)$ pour $\theta\in\Theta_0$.
- **Niveau** : $\alpha^*=\sup_{\theta\in\Theta_0}P_\theta(T_n=1)$ (pire fausse alarme).
- **Risque de 2nde espèce** : $\beta(\theta)=P_\theta(T_n=0)$, $\theta\in\Theta_1$.
- **Puissance** : $\gamma(\theta)=P_\theta(T_n=1)=1-\beta(\theta)$, $\theta\in\Theta_1$.

> [!important] Convention
> On ne peut pas minimiser $\alpha$ et $\beta$ en même temps (monter $\epsilon$ baisse $\alpha$ mais monte $\beta$). On **fixe le niveau** $\alpha$ (ex. 5 %), on en déduit le seuil $\epsilon$, puis on calcule la puissance.

## 3. Le ratio de vraisemblances (RV)
$$R_n=\frac{\sup_{\theta\in\Theta_1}\prod_kf_\theta(X_k)}{\sup_{\theta\in\Theta_0}\prod_kf_\theta(X_k)},\qquad T_n=\mathbf 1_{]\epsilon,\infty[}(R_n).$$
Idée : rejeter $H_0$ si les données sont bien plus vraisemblables sous $H_1$.

> [!important] Recette « test du RV » (90 % du TD3)
> 1. **Calculer $R_n$** (ou $\ln R_n$, plus simple). Pour un sup : c'est le **MV restreint** à $\Theta_0$ ou $\Theta_1$.
> 2. **Simplifier** : montrer $R_n=g(S_n)$ avec $S_n$ simple ($\bar X_n$, $\sum X_k$, $|Z|$...) et $g$ **monotone**.
>    - $g$ croissante ⇒ $R_n>\epsilon\iff S_n>\epsilon'$.
>    - $g$ décroissante ⇒ $R_n>\epsilon\iff S_n<\epsilon'$.
> 3. **Seuil** : trouver la loi de $S_n$ **sous $H_0$** (exacte ou TLC) et choisir $\epsilon'$ tel que $P_{H_0}(\text{rejet})=\alpha$.
>    Si $H_0$ composite ($\mu\le\mu_0$) : le sup est en général atteint **à la frontière** $\mu=\mu_0$.
> 4. **Puissance** : loi de $S_n$ **sous $H_1$**, calculer $P_{H_1}(\text{rejet})$.

## 4. Les exemples du cours

**Moyenne gaussienne, $\sigma^2$ connue, $H_0:\mu=\mu_0$ vs $H_1:\mu=\mu_1$ ($\mu_0<\mu_1$)**
$\ln R_n=\frac n{\sigma^2}(\mu_1-\mu_0)\big(\bar X_n-\frac{\mu_0+\mu_1}2\big)$ croissant en $\bar X_n$ ⇒ $T_n=\mathbf 1(\bar X_n>\epsilon)$.
Sous $H_0$, $\bar X_n\sim\mathcal N(\mu_0,\sigma^2/n)$ :
$$\epsilon=\mu_0+\frac{\sigma}{\sqrt n}\Phi^{-1}(1-\alpha),\qquad\gamma=1-\Phi\Big(\Phi^{-1}(1-\alpha)-\frac{\sqrt n(\mu_1-\mu_0)}\sigma\Big).$$
→ puissance ↑ avec $n$ et avec l'écart $\mu_1-\mu_0$ ; puissance → 1 quand $n\to\infty$.

**Variance gaussienne, $\mu$ connue, $\sigma_0^2<\sigma_1^2$** : $Y_n=\sum\frac{(X_k-\mu)^2}{\sigma_0^2}$, $R_n$ croissant en $Y_n$, sous $H_0$ $Y_n\sim\chi^2(n)$ ⇒ $\epsilon=F_{\chi^2(n)}^{-1}(1-\alpha)$, puissance $1-F\big(\frac{\sigma_0^2}{\sigma_1^2}F^{-1}(1-\alpha)\big)$.

## 5. Les réflexes à avoir
> [!tip] Seuils standards (niveau $\alpha$)
> | Stat. sous $H_0$ | Unilatère (rejet si $S>\epsilon$) | Bilatère (rejet si $|S|>\epsilon$) |
> |---|---|---|
> | $\mathcal N(0,1)$ | $\Phi^{-1}(1-\alpha)$ | $\Phi^{-1}(1-\alpha/2)$ |
> | $t(k)$ | $t_{k,1-\alpha}$ | $t_{k,1-\alpha/2}$ |
> | $\chi^2(k)$ | $F^{-1}_{\chi^2(k)}(1-\alpha)$ | — |

> [!tip] Puissance d'un test bilatère gaussien
> Si sous $H_1$, $Z\sim\mathcal N(\delta,1)$ et on rejette si $|Z|>q$ :
> $$\gamma=P(|Z|>q)=1-\Phi(q-\delta)+\Phi(-q-\delta).$$

> [!tip] Alternatives locales ($\theta_1=\theta_0+\Delta/\sqrt n$)
> Alternative fixe : puissance → 1 (test **consistant**). Alternative à distance $\Delta/\sqrt n$ : puissance → une limite $<1$ ⇒ $1/\sqrt n$ est l'**échelle minimale détectable**.

---
## Exos de base

**E1.** $n=16$, $\mathcal N(\mu,4)$, $H_0:\mu=0$ vs $H_1:\mu=1$, $\alpha=5\%$. Seuil et puissance ?
> [!success]- Solution
> $\epsilon=0+\frac24\cdot1{,}645=0{,}82$. $\gamma=1-\Phi(1{,}645-\frac{4\cdot1}{2})=1-\Phi(-0{,}355)=\Phi(0{,}355)\approx0{,}64$.

**E2.** Même test : quel $n$ pour avoir une puissance de 90 % ?
> [!success]- Solution
> $1{,}645-\frac{\sqrt n}{2}=-1{,}282$ ⇒ $\sqrt n=5{,}854$ ⇒ $n\ge35$.

**E3.** Si $R_n=\exp(-c\,\bar X_n+d)$ avec $c>0$, quelle forme a le test ?
> [!success]- Solution
> $g$ décroissante ⇒ rejeter $H_0$ si $\bar X_n<\epsilon'$.

**E4.** Pourquoi, pour $H_0:\mu\le\mu_0$, le seuil se calcule-t-il en $\mu=\mu_0$ ?
> [!success]- Solution
> $P_\mu(\bar X_n>\epsilon)=1-\Phi\big(\sqrt n(\epsilon-\mu)/\sigma\big)$ est croissante en $\mu$ ⇒ son sup sur $\mu\le\mu_0$ est atteint en $\mu_0$.

**E5.** Vrai/faux : « Un test de niveau 5 % qui ne rejette pas $H_0$ prouve que $H_0$ est vraie. »
> [!success]- Solution
> **Faux.** On contrôle seulement $P(\text{rejet}|H_0)$. Ne pas rejeter peut venir d'un manque de puissance (petit $n$, petit écart).
