---
tags: [communications-numériques, probabilités, rappels]
---

# 05 — Rappels de probabilités

[[00 - Index - Communications Numériques|← Retour à l'index]]

> Indispensable pour comprendre [[06 - Probabilité d'erreur]] et [[08 - DSP des signaux codés en ligne]].

---

## 🎲 Variable aléatoire (VA)

Une VA $X(\omega)$ traduit le résultat d'une expérience aléatoire. Deux types :

| Type | Ensemble de valeurs |
|------|---------------------|
| **Discrète** | $\mathcal{X} = \{x_1, ..., x_N\}$ (fini ou dénombrable) |
| **Continue** | $\mathcal{X} = \mathbb{R}$, $[a,b]$, etc. |

Exemples discrets : $\{0,1\}$, $\{-1,1\}$, $\{-3,-1,1,3\}$, $\{1,...,6\}$ (dé).
Exemples continus : $\mathbb{R}$, $[0,1]$.

---

## 📐 Fonctions caractérisant une VA continue

**Fonction de répartition** :
$$
F_X(x) = P(X \leq x)
$$

Propriétés :
- $F_X(x) \in [0,1]$
- $F_X(-\infty) = 0$, $F_X(+\infty) = 1$
- $F_X$ est croissante

**Densité de probabilité** :
$$
f_X(x) = \dfrac{dF_X(x)}{dx}
$$

Propriétés :
- $f_X(x) \geq 0$
- $P(x_1 \leq X \leq x_2) = \displaystyle\int_{x_1}^{x_2} f_X(x)\,dx$
- $\displaystyle\int_{-\infty}^{+\infty} f_X(x)\,dx = 1$

---

## 📊 Espérance

**Cas discret** ($\mathcal{X} = \{x_1, ..., x_N\}$) :
$$
\mathbb{E}[X] = \sum_{k=1}^N x_k \, P(X = x_k)
$$
$$
\mathbb{E}[h(X)] = \sum_{k=1}^N h(x_k) \, P(X = x_k)
$$

**Cas continu** :
$$
\mathbb{E}[X] = \int_{\mathbb{R}} x \, f_X(x)\,dx
$$
$$
\mathbb{E}[h(X)] = \int_{\mathbb{R}} h(x) \, f_X(x)\,dx
$$

### Propriétés essentielles de l'espérance

- $\mathbb{E}[aX + b] = a\,\mathbb{E}[X] + b$ (**linéarité**)
- $\mathbb{E}[X + Y] = \mathbb{E}[X] + \mathbb{E}[Y]$
- Si $X, Y$ **indépendantes** : $\mathbb{E}[XY] = \mathbb{E}[X]\,\mathbb{E}[Y]$

---

## 📏 Variance et écart-type

$$
\mathrm{VAR}(X) = \mathbb{E}\left[|X - \mathbb{E}[X]|^2\right] = \mathbb{E}[|X|^2] - |\mathbb{E}[X]|^2
$$

Écart-type : $\sigma_X = \sqrt{\mathrm{VAR}(X)}$.

---

## 🔔 Loi gaussienne (normale)

Densité d'une VA $X \sim \mathcal{N}(\mu, \sigma^2)$ :
$$
\boxed{\, f_X(x) = \dfrac{1}{\sqrt{2\pi\sigma^2}} \, e^{-\frac{(x-\mu)^2}{2\sigma^2}} \,}
$$

### Propriétés

- Si $X \sim \mathcal{N}(\mu, \sigma^2)$ et $Y = aX + b$ alors $Y \sim \mathcal{N}(a\mu + b, \, a^2 \sigma^2)$
- En particulier : si $X \sim \mathcal{N}(0,1)$, alors $Y = \sigma X + \mu \sim \mathcal{N}(\mu, \sigma^2)$
- Intervalles de confiance : $\pm \sigma \approx 67\%$, $\pm 3\sigma \approx 99\%$

### Fonction $\Phi$ (répartition de la normale centrée réduite)

$$
\Phi(u) = \dfrac{1}{\sqrt{2\pi}} \int_{-\infty}^u e^{-x^2/2} \, dx
$$

### ⭐ Fonction $Q$ (la plus utilisée dans le cours)

$$
\boxed{\, Q(x) = \dfrac{1}{\sqrt{2\pi}} \int_x^{+\infty} e^{-u^2/2}\,du = 1 - \Phi(x) \,}
$$

**Interprétation** : $Q(x)$ est la probabilité qu'une gaussienne centrée réduite dépasse $x$.

Propriétés :
- $Q(0) = 0.5$
- $Q(-\infty) = 1$, $Q(+\infty) = 0$
- $Q$ est strictement décroissante
- $Q(-x) = 1 - Q(x)$

---

## 🧪 Exemple type : VA gaussienne avec décalage

Soit $Z \sim \mathcal{N}(0, \sigma^2)$ et $R = g_0 + Z$.

**Loi de $R$** : $R \sim \mathcal{N}(g_0, \sigma^2)$.

**Calcul de $P(R < 0)$** :
$$
P(R < 0) = P(g_0 + Z < 0) = P(Z < -g_0) = P\left(\frac{Z}{\sigma} < -\frac{g_0}{\sigma}\right) = \Phi\left(-\frac{g_0}{\sigma}\right) = Q\left(\frac{g_0}{\sigma}\right)
$$

> **C'est exactement le calcul de Pb pour une modulation binaire !** Voir [[06 - Probabilité d'erreur]].

---

## ✅ À retenir

- **Linéarité** de l'espérance toujours, indépendance pour le produit
- **VAR** = espérance des carrés moins carré de l'espérance
- $\mathcal{N}(\mu, \sigma^2)$ → fonction $Q(x)$ pour calculer les probabilités de dépassement
- $\boxed{P(R > \gamma) = Q\left(\dfrac{\gamma - \mu}{\sigma}\right)}$ quand $R \sim \mathcal{N}(\mu, \sigma^2)$
