---
tags: [stats, cours, estimation]
---
# 05 — Estimation bayésienne

Précédent : [[Stats 04 - Intervalles de confiance]] · Suivant : [[Stats 06 - Régression linéaire]]

## Le changement de point de vue
- Fréquentiste : $\theta$ **déterministe** inconnu.
- Bayésien : $\theta$ **aléatoire** de loi **a priori** $\pi$ (ce qu'on croit avant de voir les données).
- **Modèle bayésien** = modèle $\{f_\theta\}$ + loi a priori $\pi$.
- $f_\theta(x)=f(x\mid\theta)$ ; loi des données $f(x)=\int f(x|\theta)\pi(\theta)d\theta$ = **évidence**.
- **Loi a posteriori** (Bayes) :
$$\boxed{\pi(\theta\mid x_1,\dots,x_n)=\frac{\prod_k f(x_k|\theta)\,\pi(\theta)}{f(x_1,\dots,x_n)}\ \propto\ \underbrace{\prod_k f(x_k|\theta)}_{\text{vraisemblance}}\times\underbrace{\pi(\theta)}_{\text{a priori}}}$$

> [!tip] Astuce qui fait gagner 10 minutes
> On calcule la posterior **à une constante près** (en $\theta$) : on garde seulement ce qui dépend de $\theta$, et on **reconnaît** une loi connue (Beta, Gamma, Normale). La constante se déduit toute seule.

## Risque bayésien et estimateur de Bayes
- **Risque bayésien** : $R_\pi(\hat\theta_n)=\mathbb E[R(\hat\theta_n,\theta)]=\int_\Theta R(\hat\theta_n,\theta)\pi(\theta)d\theta$ — un **nombre** (on moyenne aussi sur $\theta$).
- **Estimateur de Bayes** : celui qui minimise $R_\pi$ parmi tous les estimateurs.

> [!important] Les deux estimateurs bayésiens
> | Perte | Estimateur de Bayes | Nom |
> |---|---|---|
> | Quadratique $L^2$ | **moyenne a posteriori** $\mathbb E[\theta\mid X_1,\dots,X_n]$ | MMSE |
> | 0-1 ($\epsilon$ petit) | **mode a posteriori** $\arg\max_\theta\pi(\theta|X)$ | MAP |
>
> - Prior uniforme sur un compact ⇒ **MAP = MV**.
> - Posterior gaussienne ⇒ moyenne = mode ⇒ **MAP = MMSE**. En général ils diffèrent.

## Exemple du cours : Gaussien – Gaussien
$X_k|\theta\sim\mathcal N(\theta,\sigma^2)$, $\theta\sim\mathcal N(\theta^*,\gamma^2)$. Alors
$$\theta\mid x\sim\mathcal N\Big(\frac{n\bar x\gamma^2+\sigma^2\theta^*}{n\gamma^2+\sigma^2},\ \frac{\sigma^2\gamma^2}{n\gamma^2+\sigma^2}\Big),\qquad \hat\theta_n=\frac{\gamma^2\bar X_n+\frac{\sigma^2}n\theta^*}{\gamma^2+\frac{\sigma^2}n}.$$
**Lecture** : moyenne pondérée entre la donnée $\bar X_n$ et l'a priori $\theta^*$.
- $\gamma^2\to\infty$ (a priori non informatif) ⇒ $\hat\theta_n\to\bar X_n$ (= MV).
- $n\to\infty$ ⇒ les données l'emportent, on retrouve le MV.

## Exemple clé du TD : Bernoulli – Beta (« conjugaison »)
$\pi(\theta)\propto\theta^{\alpha-1}(1-\theta)^{\beta-1}$, vraisemblance $\theta^S(1-\theta)^{n-S}$ ⇒
$$\theta\mid X\sim\text{Beta}(\alpha+S,\ \beta+n-S),\qquad \hat\theta^{\text{Bayes}}=\frac{\alpha+S}{\alpha+\beta+n}.$$
Interprétation : $\alpha,\beta$ = « succès/échecs fictifs » ajoutés aux données.

> [!note] Fréquentiste vs bayésien sur le même estimateur
> On peut calculer le **biais et le risque fréquentistes** d'un estimateur de Bayes (à $\theta$ fixé) : c'est ce que fait le TD1 ex 2. Un estimateur de Bayes dont le risque fréquentiste est **constant** en $\theta$ est **minimax** (il minimise le pire risque).

---
## Exos de base

**E1.** Poisson–Gamma : $X_k|\theta\sim\mathcal P(\theta)$, $\theta\sim\Gamma(a,b)$. Posterior et estimateur MMSE ?
> [!success]- Solution
> $\pi(\theta|x)\propto\theta^{S}e^{-n\theta}\cdot\theta^{a-1}e^{-b\theta}=\theta^{a+S-1}e^{-(b+n)\theta}$ ⇒ $\Gamma(a+S,b+n)$. MMSE $=\frac{a+S}{b+n}$. MAP $=\frac{a+S-1}{b+n}$ (si $a+S>1$).

**E2.** Bernoulli–Beta avec $\alpha=\beta=1$ (prior uniforme). MMSE et MAP ?
> [!success]- Solution
> Posterior $\text{Beta}(1+S,1+n-S)$. MMSE $=\frac{S+1}{n+2}$ (règle de Laplace). MAP = mode $=\frac{S}{n}$ = MV (prior uniforme).

**E3.** Mode d'une $\text{Beta}(a,b)$, $a,b>1$ ?
> [!success]- Solution
> Maximiser $(a-1)\ln x+(b-1)\ln(1-x)$ : $\frac{a-1}x=\frac{b-1}{1-x}\Rightarrow x=\frac{a-1}{a+b-2}$.

**E4.** Pourquoi le risque bayésien est-il un nombre alors que le risque classique est une fonction ?
> [!success]- Solution
> Le risque classique $R(\hat\theta,\theta)$ dépend de $\theta$ ; on l'intègre contre $\pi(\theta)$, ce qui donne un nombre → on peut **toujours** comparer deux estimateurs (ce qui n'était pas le cas, cf. exemple Bernoulli du chap. 02).
