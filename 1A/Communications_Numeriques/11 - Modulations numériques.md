---
tags: [communications-numériques, modulations, ASK, PSK, QAM, FSK]
---

# 11 — Modulations numériques

[[00 - Index - Communications Numériques|← Retour à l'index]]

> Les choix de **constellation** $S_n = A_n e^{j\varphi_n}$ et leurs performances.

---

## 📡 Formule générale du signal modulé

Quelle que soit la modulation :
$$
s(t) = \sum_{n \in \mathbb{Z}} A_n \, h(t - n T_s) \cos(2\pi f_c t + \varphi_n)
$$

- $A_n$ : module du symbole (variable aléatoire discrète)
- $\varphi_n$ : phase du symbole
- $A_n, \varphi_n$ obtenus à partir de $n_b = \log_2(M)$ bits et d'une **constellation**
- **Étiquetage** : toujours de **Gray** (symboles voisins diffèrent d'1 bit)

---

## 1️⃣ M-ASK (Amplitude Shift Keying)

Modulation **d'amplitude** uniquement → $\varphi_n = 0$ ($\forall n$).

**Équivalent** à la **M-PAM** vue en bande de base !

Constellation 4-ASK : $A_n \in \{-3, -1, 1, 3\}$ (sur l'axe réel)

```
   [00]    [01]    [11]    [10]
─────●───────●───────●───────●─────→ Voie I (en phase)
    -3      -1       1       3
                                   ← Voie Q reste à 0
```

### 🎯 Probabilité d'erreur binaire M-ASK
$$
\boxed{\, P_b^{\text{M-ASK}} = \dfrac{2(M-1)}{M \log_2(M)} \, Q\!\left(\sqrt{\dfrac{6 \log_2(M)}{M^2 - 1} \cdot \dfrac{E_b}{N_0}}\right) \,}
$$

→ Identique à la M-PAM (cf [[09 - Eb sur N0]]).

---

## 2️⃣ M-PSK (Phase Shift Keying)

Modulation de **phase** uniquement → $\forall n,\, A_n = 1$.
$$
s(t) = \sum_n h(t - nT_s) \cos(2\pi f_c t + \varphi_n)
$$

Phases possibles : $\varphi_n = \dfrac{2\pi i}{M} + \varphi_{\text{ini}}$ avec $i \in \{0, ..., M-1\}$.

### Constellations courantes

```
   BPSK (M=2)            QPSK (M=4)              8-PSK (M=8)
                                                     ⃝
                       ●                          ⃝   ⃝
   ←●━━━━━━●→     ←●         ●→               ⃝          ⃝
                                                  ⃝   ⃝
                       ●                            ⃝
```

- **BPSK** : 2 phases (0, π) — équivalent à 2-PAM
- **QPSK** (M=4, $\varphi_{\text{ini}} = \pi/4$) : 4 points sur le cercle
- **8-PSK** : 8 points équirépartis sur le cercle

### 🎯 Probabilité d'erreur binaire M-PSK
$$
\boxed{\, P_b^{\text{M-PSK}} = 2 \, Q\!\left(\sqrt{2 \log_2(M) \cdot \sin^2\!\left(\dfrac{\pi}{M}\right) \cdot \dfrac{E_b}{N_0}}\right) \,}
$$

### Cas particuliers

| Modulation | $P_b$ |
|------------|-------|
| BPSK (M=2) | $Q\!\left(\sqrt{2 E_b/N_0}\right)$ (cf 2-PAM) |
| QPSK (M=4) | ≈ même perf que BPSK car $\sin^2(\pi/4) = 1/2$ |

⚠️ Plus $M$ augmente, plus $\sin(\pi/M)$ diminue, plus la performance **se dégrade**.

---

## 3️⃣ M-APK (Amplitude-Phase Keying)

Combinaison amplitude + phase → constellation dans le plan complexe avec **plusieurs cercles**.

```
   8-APK
        ●
     ●     ●     ← cercle extérieur
   ●         ●
     ●     ●
        ●         ← cercle intérieur
```

→ Offre le **meilleur compromis** (puissance, $P_b$) à bande passante fixée :
- M-ASK : plus $M$ ↗, plus on consomme d'énergie (constellation s'étire)
- M-PSK : plus $M$ ↗, plus le $P_b$ se dégrade (symboles trop proches angulairement)
- M-APK / QAM : meilleur compromis

---

## 4️⃣ M-QAM (Quadrature Amplitude Modulation) — cas particulier d'APK

Cas particulier où les $S_n$ sont distribués sur une **grille rectangulaire** :
$$
S_n \in \{\pm 1 \pm j, \, \pm 3 \pm j, \, \pm 1 \pm 3j, \, \pm 3 \pm 3j, ...\}
$$

### Constellations

```
   4-QAM (= QPSK)              16-QAM
   Voie Q                      Voie Q
     ↑                           ↑
   ●   ●                       ● ● ● ●
   ↔  ↔   → Voie I             ● ● ● ●  → Voie I
   ●   ●                       ● ● ● ●
                               ● ● ● ●
```

→ **4-QAM = QPSK** (deux noms pour la même chose).

→ Voir étiquetages de Gray sur la grille 16-QAM dans le cours.

→ Les performances sont équivalentes à une **M-ASK sur chaque voie**.

---

## 5️⃣ M-FSK (Frequency Shift Keying)

Modulation de **fréquence** : $\forall n, A_n = 1$ et $\varphi_n = 2\pi f_n t + \varphi_{\text{ini}}$.
$$
s(t) = \sum_n h(t - nT_s) \cos(2\pi (f_c + f_n) t + \varphi_{\text{ini}})
$$

avec :
- $f_n = (2i - (M-1)) \dfrac{\Delta f}{2}$, $i \in \{0, ..., M-1\}$
- $\Delta f$ : écart entre porteuses adjacentes
- $f_n \ll f_c$

→ Chaque symbole correspond à une **fréquence différente**.

### 🎯 Probabilité d'erreur M-FSK
$$
\boxed{\, P_b^{\text{M-FSK}} = 2 \, Q\!\left(\sqrt{\dfrac{E_b}{N_0}}\right) \,}
$$

(Cette formule simple suppose des conditions de cohérence et orthogonalité des porteuses.)

---

## 🔬 Comparaison des modulations (mémoriser ces ordres de grandeur)

### Pour atteindre $P_b = 10^{-3}$ (référence) :

| Modulation | $E_b/N_0$ requis (env.) | Efficacité spectrale |
|------------|:-----------------------:|:--------------------:|
| BPSK | ~7 dB | 1 bit/s/Hz |
| QPSK / 4-QAM | ~7 dB | 2 bits/s/Hz |
| 8-PSK | ~10 dB | 3 bits/s/Hz |
| 16-QAM | ~11 dB | 4 bits/s/Hz |
| 64-QAM | ~15 dB | 6 bits/s/Hz |

→ **Plus $M$ ↗, plus l'efficacité spectrale ↗ mais plus l'énergie nécessaire ↗.**

---

## 📊 Efficacité spectrale et capacité de Shannon

Efficacité spectrale : $\eta = \dfrac{D_b}{B}$ (en bits/s/Hz).

**Capacité de Shannon** = limite théorique ultime :
$$
\eta_{\max} = \log_2\!\left(1 + \dfrac{E_b}{N_0} \cdot \eta\right) \quad \text{(implicite)}
$$

→ Les modulations classiques (sans codage canal) sont à plusieurs dB de cette limite.

```
η (bits/s/Hz)
  ↑
  │                  Capacité de Shannon (limite)
8 ┤      .・・・・・・・・・・                   ●  64-QAM
  │   .・              ●  16-QAM
6 ┤  ・        ●  8-PSK
  │ ・       ●  4-QAM
4 ┤・   ●  BPSK
2 ┤
  └──┬──────┬──────┬─────→ Eb/N0 (dB)
     0      5     10     15
```

---

## 🎯 Critères de conception (conclusion du cours)

Le concepteur doit trouver le **meilleur compromis** entre :
- Maximiser l'**efficacité spectrale** $\eta = D_b/B$
- Minimiser la **probabilité d'erreur** $P_b$
- Minimiser la **puissance émise** $E_b$
- Minimiser la **bande passante** $B$
- Minimiser la **complexité** du système

Ces objectifs sont **antagonistes** : impossible de tous les optimiser simultanément.

---

## ✅ Tableau-récap final

| Modulation | $P_b$ |
|------------|-------|
| **M-ASK / M-PAM** | $\dfrac{2(M-1)}{M\log_2 M} \, Q\!\left(\sqrt{\dfrac{6 \log_2(M)}{M^2-1} \, \dfrac{E_b}{N_0}}\right)$ |
| **M-PSK** | $2 \, Q\!\left(\sqrt{2 \log_2(M) \sin^2\!\left(\dfrac{\pi}{M}\right) \, \dfrac{E_b}{N_0}}\right)$ |
| **M-FSK** | $2 \, Q\!\left(\sqrt{\dfrac{E_b}{N_0}}\right)$ |

→ Pour la version récap ultra-condensée : [[12 - Formulaire et antisèche]]
