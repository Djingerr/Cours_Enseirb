---
tags: [communications-numériques, DSP, processus-aléatoire]
---

# 08 — DSP des signaux codés en ligne

[[00 - Index - Communications Numériques|← Retour à l'index]]

> Comment décrire la **distribution fréquentielle de l'énergie** d'un signal aléatoire.

---

## 🎯 Pourquoi cette section ?

En pratique, la TF $S_l(f) = \mathrm{TF}(s_l(t))$ dépend du **message envoyé** (qui est aléatoire).

→ On veut une grandeur qui dépend **uniquement des statistiques** du message envoyé, pas du tirage particulier.

Cette grandeur, c'est la **Densité Spectrale de Puissance (DSP)** $\Gamma_X(f)$.

---

## 🌊 Processus aléatoire (PA)

Un **processus aléatoire** $X(\omega, t)$ est une fonction de deux paramètres :
- $\omega$ : un événement aléatoire
- $t$ : le temps

→ C'est une **VA qui dépend du temps**, dont la densité, moyenne et variance peuvent varier dans le temps.

| Type | Notation |
|------|---------|
| Temps continu | $X(t)$ |
| Temps discret | $X_k$ ou $X(k)$ |

---

## 📊 Caractérisation : moyenne et autocorrélation

**Moyenne d'ensemble** (espérance) :
$$
\mathbb{E}[X(t)] = \int_{-\infty}^{+\infty} x \, f_{X(t)}(x)\,dx
$$

où $f_{X(t)}(x)$ est la densité de $X$ à l'instant $t$.

**Fonction d'autocorrélation** :
$$
R_X(t_1, t_2) = \mathbb{E}[X(t_1) \, X^*(t_2)]
$$

ou plus souvent (avec $\tau$ = écart temporel) :
$$
R_X(t, \tau) = \mathbb{E}[X(t) \, X^*(t - \tau)]
$$

→ $R_X$ mesure le **lien entre deux instants** d'un PA.

---

## 🟰 Stationnarité au sens large

Un PA est **stationnaire au sens large** si :
- $m_X(t) = m_X = $ constante (moyenne indépendante de $t$)
- $R_X(t, \tau) = R_X(\tau)$ (autocorrélation ne dépend que de l'écart)

### Propriétés de $R_X(\tau)$

| Hypothèse | Propriété |
|-----------|-----------|
| $X(t) \in \mathbb{R}$ | $R_X(\tau) = R_X(-\tau)$ (parité) |
| $X(t) \in \mathbb{C}$ | $R_X(\tau) = R_X^*(-\tau)$ (symétrie hermitienne) |
| Toujours | $\forall \tau, \; R_X(\tau) \leq R_X(0)$ (max en 0) |
| **Puissance moyenne** | $P_X = \mathbb{E}[|X(t)|^2] = R_X(0)$ |

---

## 🎼 Densité Spectrale de Puissance (DSP)

> **Théorème de Wiener-Khintchine** : pour un PA stationnaire au sens large, la DSP s'obtient en calculant la **TF de l'autocorrélation**.

$$
\boxed{\, \Gamma_X(f) = \mathrm{TF}(R_X(\tau)) = \int_{-\infty}^{+\infty} R_X(\tau) \, e^{-j 2\pi f \tau} \, d\tau \,}
$$

→ La DSP $\Gamma_X(f)$ décrit la **répartition de la puissance** du signal en fréquence.

→ Puissance totale : $P_X = \int_{-\infty}^{+\infty} \Gamma_X(f) \, df = R_X(0)$.

---

## 🔁 PA cyclostationnaires

En couche PHY, les signaux comme $s_l(t)$ sont souvent **cyclostationnaires** : leurs propriétés statistiques sont **périodiques** de période $T_s$.

$$
m_X(t) = m_X(t + T_s), \quad R_X(t, \tau) = R_X(t + T_s, \tau)
$$

Pour ces signaux, on définit l'**autocorrélation moyennée** sur une période :
$$
\widetilde{R}_X(\tau) = \dfrac{1}{T_s} \int_0^{T_s} R_X(t, \tau)\,dt
$$

et la DSP devient :
$$
\boxed{\, \Gamma_X(f) = \mathrm{TF}(\widetilde{R}_X(\tau)) \,}
$$

---

## 🔧 Formule du filtrage d'un PA

Si $Y(t) = (h \star X)(t)$ :

- $Y$ conserve les propriétés de **stationnarité** ou **cyclostationnarité** de $X$
- $\boxed{\, \Gamma_Y(f) = |H(f)|^2 \, \Gamma_X(f) \,}$ (filtrage en DSP)

→ C'est la formule **clé** utilisée partout dans le cours.

---

## 📐 DSP de $s_l(t)$ pour une chaîne en bande de base

Le signal $s_l(t) = \sum_n a_n \, h(t - nT_s)$ est cyclostationnaire de période $T_s$.

On peut montrer (résultat à connaître) que :
$$
\boxed{\, \Gamma_{s_l}(f) = \dfrac{\sigma_a^2 \, |H(f)|^2}{T_s} \,}
$$

où $\sigma_a^2 = \mathbb{E}[|a_n|^2]$ est la variance des symboles (en supposant $\mathbb{E}[a_n] = 0$).

→ Cette formule est **utilisée pour calculer $E_b$** dans [[09 - Eb sur N0]].

**Conséquence** : la **forme spectrale** de $s_l(t)$ est **directement donnée par $|H(f)|^2$**.

---

## 🧪 Exemple : filtre porte

Si $h(t)$ est le **filtre porte** entre $0$ et $T_s$ (largeur $T_s$, hauteur 1) :

$$
H(f) = T_s \cdot \mathrm{sinc}(\pi f T_s) \cdot e^{-j\pi f T_s}
$$

$$
|H(f)|^2 = T_s^2 \cdot \mathrm{sinc}^2(\pi f T_s)
$$

D'où :
$$
\Gamma_{s_l}(f) = \sigma_a^2 \, T_s \, \mathrm{sinc}^2(\pi f T_s)
$$

→ Spectre en $\mathrm{sinc}^2$, centré en 0, avec un lobe principal de largeur $2/T_s$.

---

## ✅ À retenir

| Concept | Formule clé |
|---------|-------------|
| **DSP (stat.)** | $\Gamma_X(f) = \mathrm{TF}(R_X(\tau))$ |
| **Filtrage PA** | $\Gamma_Y(f) = |H(f)|^2 \Gamma_X(f)$ |
| **DSP de $s_l(t)$** | $\Gamma_{s_l}(f) = \dfrac{\sigma_a^2 |H(f)|^2}{T_s}$ |
| **Puissance** | $P = \int \Gamma(f)\,df = R(0)$ |

- Les signaux **cyclostationnaires** doivent être moyennés sur la période
- La DSP donne la **forme spectrale**, indépendante du tirage des symboles
- Sert directement à calculer l'**énergie par bit** $E_b$ → [[09 - Eb sur N0]]
