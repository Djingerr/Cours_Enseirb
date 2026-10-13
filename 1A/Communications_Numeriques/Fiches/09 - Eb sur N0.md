---
tags: [communications-numériques, Eb-N0, énergie-bit, SNR]
---

# 09 — Énergie par bit ($E_b / N_0$)

[[00 - Index - Communications Numériques|← Retour à l'index]]

> Pourquoi on exprime $P_b$ en fonction de $E_b/N_0$ plutôt que $g_0/\sigma$ ?
> → Pour comparer **équitablement** des modulations qui ont des $M$ et des $D_b$ différents.

---

## 🎯 Définition de $E_b$

L'**énergie moyenne par bit d'information transmis** est :
$$
\boxed{\, E_b = P \cdot T_b = \dfrac{P}{D_b} \,}
$$

où :
- $P$ : puissance moyenne du signal utile transmis (en W)
- $T_b$ : temps bit (en s)
- $D_b$ : débit binaire (en bits/s)

---

## 🧮 Calcul de $E_b$ à partir de la chaîne

### Étape 1 — Puissance $P$ du signal transmis

Pour $s_l(t)$ cyclo-stationnaire (cf [[08 - DSP des signaux codés en ligne]]) :
$$
P = \int_{\mathbb{R}} \Gamma_{s_l}(f) \, df
$$

Avec $\Gamma_{s_l}(f) = \dfrac{\sigma_a^2 |H(f)|^2}{T_s}$ et $E_h = \int |H(f)|^2 df = \int |h(t)|^2 dt$ :
$$
\boxed{\, P = \dfrac{\sigma_a^2 \, E_h}{T_s} \,}
$$

### Étape 2 — Lien $T_b$ et $T_s$

Chaque symbole transporte $\log_2(M)$ bits, donc $T_s = \log_2(M) \cdot T_b$.

### Étape 3 — Expression de $E_b$

$$
E_b = P \cdot T_b = \dfrac{\sigma_a^2 E_h}{T_s} \cdot \dfrac{T_s}{\log_2(M)} = \dfrac{\sigma_a^2 E_h}{\log_2(M)}
$$

$$
\boxed{\, E_b = \dfrac{\sigma_a^2 \, E_h}{\log_2(M)} \,}
$$

---

## ⭐ Expression unifiée de $P_{b,\min}$

On part de (cf [[07 - Récepteur optimal et filtre adapté]]) :
$$
P_{b,\min} = \dfrac{2(M-1)}{M \log_2(M)} \, Q\!\left(\sqrt{\dfrac{2 E_h}{N_0}}\right)
$$

Or $E_h = \dfrac{E_b \log_2(M)}{\sigma_a^2}$, donc :
$$
\dfrac{2 E_h}{N_0} = \dfrac{2 \log_2(M)}{\sigma_a^2} \cdot \dfrac{E_b}{N_0}
$$

D'où :
$$
\boxed{\, P_{b,\min} = \dfrac{2(M-1)}{M \log_2(M)} \, Q\!\left(\sqrt{\dfrac{2 \log_2(M)}{\sigma_a^2} \cdot \dfrac{E_b}{N_0}}\right) \,}
$$

---

## 🎯 Cas M-PAM (à savoir par cœur)

Pour une M-PAM avec symboles équiprobables dans $\{-(M-1), -(M-3), ..., M-1\}$, la variance des symboles vaut :
$$
\sigma_a^2 = \dfrac{M^2 - 1}{3}
$$

Donc :
$$
\boxed{\, P_{b,\min}^{\text{M-PAM}} = \dfrac{2(M-1)}{M \log_2(M)} \, Q\!\left(\sqrt{\dfrac{6 \log_2(M)}{M^2 - 1} \cdot \dfrac{E_b}{N_0}}\right) \,}
$$

### Cas particuliers à connaître

| Modulation | $\sigma_a^2$ | $P_b$ |
|------------|--------------|-------|
| 2-PAM (BPSK) | $1$ | $Q\!\left(\sqrt{2 E_b/N_0}\right)$ |
| 4-PAM | $5$ | $\tfrac{3}{4} Q\!\left(\sqrt{\tfrac{4}{5} E_b/N_0}\right)$ |
| 8-PAM | $21$ | $\tfrac{7}{12} Q\!\left(\sqrt{\tfrac{6}{21} E_b/N_0}\right)$ |

---

## 📊 Interprétation : SNR ou $E_b/N_0$ ?

| Grandeur | Notation | Type |
|----------|----------|------|
| Rapport d'**amplitudes** | $g_0 / \sigma$ | "SNR" classique |
| Rapport d'**énergies** | $E_b / N_0$ | Plus universel |

**En dB** : $\left(\dfrac{E_b}{N_0}\right)_{\text{dB}} = 10 \log_{10}\!\left(\dfrac{E_b}{N_0}\right)$.

→ $E_b/N_0$ permet de comparer des modulations sur la même échelle (indépendant du débit, de $M$, etc.).

---

## ✅ À retenir

- $E_b = P T_b = P / D_b$ (énergie par bit)
- $E_b = \dfrac{\sigma_a^2 \, E_h}{\log_2(M)}$ (forme calculatoire)
- Pour M-PAM équiprobable : $\sigma_a^2 = (M^2-1)/3$
- **Formule finale M-PAM** :
$$
P_b = \dfrac{2(M-1)}{M \log_2(M)} Q\!\left(\sqrt{\dfrac{6 \log_2(M)}{M^2-1} \cdot \dfrac{E_b}{N_0}}\right)
$$
- Pour les autres modulations (PSK, FSK, QAM), voir [[11 - Modulations numériques]]
