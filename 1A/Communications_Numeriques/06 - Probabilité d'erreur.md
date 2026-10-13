---
tags: [communications-numériques, probabilité-erreur, Pb, Ps]
---

# 06 — Probabilité d'erreur

[[00 - Index - Communications Numériques|← Retour à l'index]]

> **Concept central #2 du cours.** Ce que toute la chaîne cherche à minimiser.

---

## 🎯 Définitions

| Quantité | Définition | Notation |
|----------|------------|----------|
| **Probabilité d'erreur symbole** | $P(\hat{a}_n \neq a_n)$ | $P_s$ |
| **Probabilité d'erreur binaire** | $P(\hat{b}_k \neq b_k)$ | $P_b$ |

Décomposition par conditionnement :
$$
P_s = \sum_{a \in \mathcal{A}} P(a_n = a) \cdot P(\hat{a}_n \neq a_n \mid a_n = a)
$$

$$
P_b = P(b_k = 0) \cdot P(\hat{b}_k = 1 \mid b_k = 0) + P(b_k = 1) \cdot P(\hat{b}_k = 0 \mid b_k = 1)
$$

---

## 🟦 Cas binaire (modulation BPSK : $a_n \in \{-1, +1\}$)

**Hypothèses** :
- Critère de Nyquist vérifié ($g(t) \cdot \mathrm{III}_{T_s}(t) = g_0 \delta(t)$) → pas d'IES
- $b_n = 0 \Leftrightarrow a_n = -1$, $b_n = 1 \Leftrightarrow a_n = +1$

Modèle simplifié : $\boxed{r_n = g_0 a_n + z_n'}$

Avec un seuil de décision $\gamma$ :
- Si $r_n < \gamma$ → on décide $\hat{a}_n = -1$ (i.e. $\hat{b}_n = 0$)
- Si $r_n \geq \gamma$ → on décide $\hat{a}_n = +1$ (i.e. $\hat{b}_n = 1$)

### Calcul

Quand $b_n = 0$, $a_n = -1$, donc $r_n = -g_0 + z_n'$ → $r_n \sim f_{Z'}(z + g_0)$.
Quand $b_n = 1$, $a_n = +1$, donc $r_n = +g_0 + z_n'$ → $r_n \sim f_{Z'}(z - g_0)$.

$$
P(\hat{b}_n = 1 \mid b_n = 0) = P(r_n \geq \gamma \mid b_n = 0) = \int_\gamma^{+\infty} f_{Z'}(z + g_0)\,dz
$$

$$
P(\hat{b}_n = 0 \mid b_n = 1) = P(r_n \leq \gamma \mid b_n = 1) = \int_{-\infty}^\gamma f_{Z'}(z - g_0)\,dz
$$

$$
P_b(\gamma) = p_0 \int_\gamma^{+\infty} f_{Z}(z+g_0)\,dz + p_1 \int_{-\infty}^\gamma f_{Z}(z-g_0)\,dz
$$

### 🎯 Seuil optimal $\gamma^*$

Minimiser $P_b$ revient à annuler $\dfrac{dP_b}{d\gamma}$ :
$$
-p_0 f_Z(\gamma + g_0) + p_1 f_Z(\gamma - g_0) = 0
\;\Longleftrightarrow\;
\dfrac{f_Z(\gamma - g_0)}{f_Z(\gamma + g_0)} = \dfrac{p_0}{p_1}
$$

Pour un bruit gaussien $Z \sim \mathcal{N}(0, \sigma^2)$ :
$$
\boxed{\, \gamma^*(p_0) = \log\left(\dfrac{p_0}{1-p_0}\right) \cdot \dfrac{\sigma^2}{2 g_0} \,}
$$

| Cas | Seuil |
|-----|-------|
| $p_0 \to 0$ | $\gamma^* \to -\infty$ |
| $p_0 \to 1$ | $\gamma^* \to +\infty$ |
| **$p_0 = 0.5$** (équiprobable) | $\boxed{\gamma^* = 0}$ |

---

## 🔑 Cas équiprobable ($p_0 = p_1 = 0.5$, seuil $\gamma = 0$)

Calcul (en posant $z' = z/\sigma$) :
$$
P_b = 0.5 \int_0^{+\infty} \dfrac{1}{\sigma\sqrt{2\pi}} e^{-\frac{(z+g_0)^2}{2\sigma^2}}\,dz + 0.5 \int_{-\infty}^{0} \dfrac{1}{\sigma\sqrt{2\pi}} e^{-\frac{(z-g_0)^2}{2\sigma^2}}\,dz
$$

Par symétrie, les deux intégrales sont égales et valent $Q(g_0/\sigma)$, d'où :
$$
\boxed{\, P_b = Q\left(\dfrac{g_0}{\sigma}\right) \,}
$$

→ Le rapport $\dfrac{g_0}{\sigma}$ s'appelle **Rapport Signal sur Bruit (RSB / SNR)**, généralement exprimé en dB : $20 \log_{10}(g_0/\sigma)$.

📝 **Voir** [[09 - Eb sur N0]] pour la version en énergie ($E_b/N_0$).

---

## 🟪 Cas M-aire (modulation M-PAM)

Constellation : $\mathcal{A} = \{a_0, ..., a_{M-1}\}$, par exemple $\{-3,-1,1,3\}$ pour 4-PAM.

**Si tous les symboles sont équiprobables** ($P(a_n = a_i) = 1/M$) :
$$
P_s = \dfrac{1}{M} \sum_{i=0}^{M-1} P(\hat{a}_n \neq a_n \mid a_n = a_i)
$$

### Seuils optimaux pour symboles équiprobables

→ **Au milieu de chaque intervalle**.
Pour 4-PAM $\{-3, -1, 1, 3\}$ : $(\gamma_0, \gamma_1, \gamma_2) = (-2g_0, 0, +2g_0)$.

### Probabilités conditionnelles d'erreur

- **Aux extrémités** ($a_0 = -3$ et $a_3 = +3$) : 1 seul voisin gênant → $Q(g_0/\sigma)$
- **À l'intérieur** ($a_1 = -1$ et $a_2 = +1$) : 2 voisins gênants → $2Q(g_0/\sigma)$

Donc pour 4-PAM :
$$
P_s = \dfrac{1}{4}\left[2 \cdot Q\left(\dfrac{g_0}{\sigma}\right) + 2 \cdot 2Q\left(\dfrac{g_0}{\sigma}\right)\right] = \dfrac{3}{2} Q\left(\dfrac{g_0}{\sigma}\right)
$$

### 🎯 Généralisation pour M-PAM

$$
\boxed{\, P_s = 2 \cdot \dfrac{M-1}{M} \cdot Q\left(\dfrac{g_0}{\sigma}\right) \,}
$$

**Cas particuliers :**
| $M$ | $P_s$ |
|-----|-------|
| $M=2$ (BPSK) | $Q(g_0/\sigma)$ |
| $M=4$ | $\tfrac{3}{2} Q(g_0/\sigma)$ |
| $M \to \infty$ | $2 Q(g_0/\sigma)$ |

### 🔗 Relation $P_b$ et $P_s$

Pour un **étiquetage de Gray** (les symboles voisins diffèrent d'un seul bit) :
$$
\boxed{\, P_b \simeq \dfrac{P_s}{\log_2(M)} \,}
$$

Pour un étiquetage quelconque, on a seulement l'inégalité : $P_b \geq P_s / \log_2(M)$.

**Expression de $P_b$ pour M-PAM avec étiquetage de Gray** :
$$
\boxed{\, P_b = \dfrac{2(M-1)}{M \log_2(M)} \, Q\left(\dfrac{g_0}{\sigma}\right) \,}
$$

---

## ✅ À retenir

- **$P_b$ est une fonction décroissante de $g_0/\sigma$** → maximiser le SNR = minimiser $P_b$
- Seuil optimal : **milieu** si équiprobable, sinon formule logarithmique
- **Formule magique** pour M-PAM : $P_b = \dfrac{2(M-1)}{M \log_2(M)} Q(g_0/\sigma)$
- Le **codage de Gray** est essentiel pour avoir $P_b \approx P_s/\log_2(M)$

→ Pour maximiser $g_0/\sigma$, voir [[07 - Récepteur optimal et filtre adapté]]
