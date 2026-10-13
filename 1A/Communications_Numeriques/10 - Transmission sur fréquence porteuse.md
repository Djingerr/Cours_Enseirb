---
tags: [communications-numériques, fréquence-porteuse, enveloppe-complexe, IQ]
---

# 10 — Transmission sur fréquence porteuse

[[00 - Index - Communications Numériques|← Retour à l'index]]

> **Concept central #4.** Tout ce qui est "sans fil" passe par une fréquence porteuse $f_c > 0$.

---

## 🎯 Pourquoi communiquer sur fréquence porteuse ?

| Raison | Détail |
|--------|--------|
| **Physique** | Taille des antennes (proportionnelle à $\lambda = c/f$), propagation EM |
| **Débits atteignables** | Bandes plus larges aux fréquences élevées |
| **Standards** | 5G, WiFi, Bluetooth, etc. utilisent tous une porteuse |
| **Partage du spectre** | Plusieurs utilisateurs sur des $f_c$ différentes |

---

## 🏗️ Architecture complexe

```
                                MODULATEUR NUMÉRIQUE
   ┌──────────────────────────────────────────────────────────┐
   │  Bk    Asso.    Sn=Anejφn         h(t)          ej2πfct  │  Re   s(t)
─→ │ ────→ bits→sym ─────→ ─────────→ filtre ─────→ × ─────→  │ ──→ ─────→ canal
   │                       ss(t)       sl(t)                  │
   └──────────────────────────────────────────────────────────┘
                    BdB (complexe)                            RF (réel)
```

**Définitions clés :**
- $f_c$ : fréquence porteuse (en Hz)
- $S_n = A_n e^{j\varphi_n}$ : **symboles complexes**
- $s_s(t), s_l(t), y_l(t), r_l(t)$ : signaux **complexes** ($\in \mathbb{C}$)
- $s(t), y(t), z(t)$ : signaux **réels** ($\in \mathbb{R}$) — transmis effectivement

---

## 🌐 Hypothèses du modèle

1. **Canal passe-bande idéal** :
$$
H_c(f) = \begin{cases} 1 & \text{si } |f - f_c| \leq B_c/2 \\ 0 & \text{sinon} \end{cases}
$$
($B_c$ = bande passante du canal, dite "bande de cohérence")

2. **Bruit** : $z(t) \sim \mathcal{N}(0, \sigma_z^2)$, **blanc**

3. **Bande du signal** $B \leq B_c$

---

## 📐 Enveloppe complexe d'un signal passe-bande

### Rappels TF

- Si $s(t) \in \mathbb{R}$, alors $S(f) = S^*(-f)$ (**symétrie hermitienne**)
- $|S(f)|$ est paire, $\arg(S(f))$ est impaire
- $\mathrm{TF}\!\left(s_l(t) e^{j 2\pi f_c t}\right) = S_l(f - f_c)$ (translation en fréquence)

### Construction de l'enveloppe complexe

À tout signal passe-bande réel $s(t)$ correspond une **unique enveloppe complexe** $s_l(t)$ :
$$
\boxed{\, s(t) = \mathrm{Re}\{s_l(t) \, e^{j 2\pi f_c t}\} \,}
$$

En décomposant $s_l(t) = p(t) + j q(t)$ :
$$
s(t) = p(t) \cos(2\pi f_c t) - q(t) \sin(2\pi f_c t)
$$

où :
- $p(t) = \mathrm{Re}\{s_l(t)\}$ : module l'amplitude de la **porteuse en phase** ($\cos$) — voie **I** (In-phase)
- $q(t) = \mathrm{Im}\{s_l(t)\}$ : module l'amplitude de la **porteuse en quadrature** ($\sin$) — voie **Q** (Quadrature)

→ $p(t)$ et $q(t)$ **véhiculent chacune une partie du message binaire** : c'est ce qui permet de transporter 2 fois plus d'info à bande de base équivalente.

---

## 🛠️ Architecture réelle d'émission (projections orthogonales)

En pratique, le modulateur est implémenté avec deux voies :

```
                                  p(t)
            Re{Sn}    h(t)   ───────→ × ───┐
   Sn = An ejφn         ↓              ↑   │
─────→ ┬─────→         BDB        cos(2πfct)│   +
       │                                    ├──→●──→ s(t)
       └─────→         BDB         π/2     │   ↑
            Im{Sn}    h(t)         ↓        │  somme
                              ───────→ × ───┘
                                  q(t)    sin(2πfct)
```

- $p(t) = \mathrm{Re}\{s_l(t)\}$ envoyé sur $\cos$
- $q(t) = \mathrm{Im}\{s_l(t)\}$ envoyé sur $-\sin$ (sinus déphasé de $\pi/2$)
- On somme les deux pour obtenir $s(t)$ réel

---

## 🔄 Architecture réelle de démodulation

```
                       ←× ─── 2cos(2πfct) ───┐
                       ↓                     │
                      h*(t)                  │
              y(t) ───┤                       
                      ↓                     │
                       ←× ─── -2sin(2πfct) ──┘
                       ↓                     
                      h*(t)
```

→ Multiplication par $2\cos(2\pi f_c t)$ et $-2\sin(2\pi f_c t)$, puis filtrage passe-bas (filtre adapté).

→ Cela permet de **récupérer $p(t)$ et $q(t)$** (donc $s_l(t) = p + jq$).

---

## ⚙️ Conséquence pratique : modèle équivalent BdB

Après démodulation, l'enveloppe complexe se comporte **comme un signal en bande de base**, mais à symboles **complexes** :
$$
\boxed{\, s_l(t) = \sum_n S_n \, h(t - n T_s) = \sum_n A_n e^{j\varphi_n} \, h(t - n T_s) \,}
$$

### Modèle après échantillonnage

Sous les hypothèses (canal large bande, étages RF idéaux) :
$$
\boxed{\, r_n = g_0 \, A_n \, e^{j\varphi_n} + z_n' \,}
$$

où $z_n'$ est l'enveloppe complexe du bruit filtré.

→ **Tous les résultats du cas réel restent valables** :
- Critère de Nyquist : $h(t)$ et $h_a(t)$ demi-Nyquist
- Filtre adapté : $h_a(t) = h^*(T - t)$

---

## 🧠 Intuition graphique

```
Voie Q
  ↑
  │       ●     ●
  │
  │   ●           ●
  │             →  rotation et amplitude
  │              ↘   = symbole Sn
  │   ●           ●          
  │              
  │       ●     ●
  └───────────────────→ Voie I
```

Chaque symbole $S_n$ est un **point dans le plan complexe** :
- Sa **distance à l'origine** = amplitude $A_n$
- Son **angle** = phase $\varphi_n$

→ Sert de base à toutes les modulations vues dans [[11 - Modulations numériques]].

---

## ✅ À retenir

| Concept | Formule |
|---------|---------|
| **Décomposition** | $s(t) = \mathrm{Re}\{s_l(t) e^{j 2\pi f_c t}\} = p\cos - q\sin$ |
| **Voie I (en phase)** | $p(t) = \mathrm{Re}\{s_l(t)\}$ |
| **Voie Q (quadrature)** | $q(t) = \mathrm{Im}\{s_l(t)\}$ |
| **Symbole complexe** | $S_n = A_n e^{j\varphi_n}$ |
| **Modèle BdB équivalent** | $r_n = g_0 S_n + z_n'$ |

- Tous les outils du cas réel (Nyquist, filtre adapté) **se généralisent** au cas complexe
- L'enveloppe complexe = représentation compacte d'un signal réel passe-bande
- Voir [[11 - Modulations numériques]] pour les choix concrets de constellations
