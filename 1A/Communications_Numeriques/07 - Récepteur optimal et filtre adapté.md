---
tags: [communications-numériques, filtre-adapté, récepteur-optimal]
---

# 07 — Récepteur optimal et filtre adapté

[[00 - Index - Communications Numériques|← Retour à l'index]]

> **Concept central #3.** Comment choisir $h_a(t)$ pour minimiser $P_b$.

---

## 🎯 Objectif

On a vu dans [[06 - Probabilité d'erreur]] que :
$$
P_b = Q\left(\dfrac{g_0}{\sigma}\right)
$$

$Q$ étant **décroissante**, **minimiser $P_b$ ⇔ maximiser le rapport** $\dfrac{g_0}{\sigma}$ aux instants de décision.

**Définition** : un **filtre adapté** ("matched filter") est un filtre linéaire $h_a(t)$ qui **maximise le rapport $g_0/\sigma$**.

---

## 🧮 Expressions de $g_0$ et $\sigma^2$

### $g_0$ (signal utile)

Si le critère de Nyquist est vérifié, $r_n = g_0 a_n + z_n'$ avec :
$$
g_0 = \int_{-\infty}^{+\infty} h(u) \, h_a(-u) \, du = \int_{-\infty}^{+\infty} H(f) \, H_a(f) \, df
$$

### $\sigma^2$ (puissance du bruit filtré)

On suppose $z_l(t)$ gaussien stationnaire centré, de DSP $\Gamma_{z_l}(f) = \dfrac{N_0}{2}$ (bruit blanc).

Après filtrage par $h_a(t)$ :
- Moyenne : $m_{z_l'}(t) = 0$
- DSP : $\Gamma_{z_l'}(f) = \dfrac{N_0}{2} |H_a(f)|^2$

En utilisant le théorème de Parseval :
$$
\sigma^2 = \dfrac{N_0}{2} \int_{-\infty}^{+\infty} |H_a(f)|^2\,df = \dfrac{N_0}{2} \int_{-\infty}^{+\infty} |h_a(t)|^2\,dt
$$

---

## 🔧 Démonstration du filtre adapté (Cauchy-Schwarz)

Rapport à maximiser :
$$
\dfrac{g_0^2}{\sigma^2} = \dfrac{\left|\int_{-\infty}^{+\infty} h(u) h_a(-u) du\right|^2}{\dfrac{N_0}{2} \int_{-\infty}^{+\infty} |h_a(t)|^2 dt}
$$

**Inégalité de Cauchy-Schwarz** :
$$
\left|\int_{-\infty}^{+\infty} u(t) v^*(t) \, dt\right|^2 \leq \int_{-\infty}^{+\infty} |u(t)|^2\,dt \cdot \int_{-\infty}^{+\infty} |v(t)|^2\,dt
$$

avec **égalité** ssi $u(x) = \lambda \, v^*(x)$.

→ Appliqué ici, on obtient :
$$
\boxed{\, h_a(t) = h^*(-t) \,}
$$

C'est le **filtre adapté** : la réponse impulsionnelle du récepteur est la **version conjuguée et retournée** dans le temps du filtre d'émission.

---

## 📊 Valeur optimale du SNR

En notant $\boxed{E_h = \displaystyle\int_{\mathbb{R}} |h(t)|^2 \, dt}$ (énergie du filtre de mise en forme), on obtient :

$$
\boxed{\, \left(\dfrac{g_0^2}{\sigma^2}\right)_{\max} = \dfrac{2 E_h}{N_0} \,}
$$

---

## 🎯 Probabilité d'erreur minimale

En combinant ce résultat avec la formule de $P_b$ pour M-PAM avec Gray (voir [[06 - Probabilité d'erreur]]) :

$$
\boxed{\, P_{b,\min} = \dfrac{2(M-1)}{M \log_2(M)} \, Q\!\left(\sqrt{\dfrac{2 E_h}{N_0}}\right) \,}
$$

🚨 C'est **LA formule fondamentale** : la performance optimale d'une chaîne de communication M-PAM.

---

## ⚙️ Remarques pratiques

### Filtre global = autocorrélation

$$
g(t) = \int h(u) \, h_a(t-u)\,du = \int h(u) \, h^*(u-t)\,du = R_h(t)
$$

→ Avec un filtre adapté, le filtre global $g(t)$ est l'**autocorrélation déterministe** de $h(t)$.

### Causalité

- $h(t)$ causal ⇒ $h_a(t) = h^*(-t)$ **non causal** (problème pratique !)
- **Solution** : on retarde $h_a$ d'une durée $T \geq T_h$ (longueur de $h$) :
$$
h_a(t) = h^*(T_h - t)
$$
- Conséquence : $g(t) = R_h(t - T_h)$ → **instant optimal d'échantillonnage = $T_h$** (car $R_h$ est max en 0).

---

## 🎁 Bonus : Filtres demi-Nyquist

Quand le canal est **plat** ($H_c(f) \approx \text{cste}$), on a $G(f) = H(f) H_a(f)$.

Pour réaliser un **canal de Nyquist** $\mathrm{Ny}(f)$, on prend :
$$
\boxed{\, H(f) = H_a(f) = \sqrt{\mathrm{Ny}(f)} \,}
$$

→ Même filtre à l'émission et à la réception ! Ce filtre est appelé **demi-Nyquist** (ou "racine de Nyquist").

✅ Cohérent avec $h_a(t) = h^*(-t)$ quand le filtre est à **symétrie paire** ($h(t)$ réel pair).

→ C'est cette solution qui est utilisée en pratique avec le **cosinus surélevé racine** (root raised cosine).

---

## ✅ À retenir

| Résultat | Formule |
|----------|---------|
| **Filtre adapté** | $h_a(t) = h^*(-t)$ |
| **SNR optimal** | $\left(\dfrac{g_0^2}{\sigma^2}\right)_{\max} = \dfrac{2 E_h}{N_0}$ |
| **Pb minimal** | $P_{b,\min} = \dfrac{2(M-1)}{M \log_2(M)} Q\!\left(\sqrt{\tfrac{2 E_h}{N_0}}\right)$ |
| **Filtres demi-Nyquist** | $H(f) = H_a(f) = \sqrt{\mathrm{Ny}(f)}$ |

→ Pour la version en $E_b/N_0$, voir [[09 - Eb sur N0]]
