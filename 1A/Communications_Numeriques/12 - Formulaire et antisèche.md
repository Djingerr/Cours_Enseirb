---
tags:
  - communications-numériques
  - formulaire
  - révision
  - examen
share_link: https://share.note.sx/aqyvviw7#jufL6EyDJem4NWQG5DU6UNZiVSquwWMF6FNNHZWZPas
share_updated: 2026-05-21T20:34:10+02:00
---

# 12 — Formulaire et antisèche

[[00 - Index - Communications Numériques|← Retour à l'index]]

> 📌 **À imprimer / relire la veille de l'examen.** Toutes les formules sur 2 pages.

---

## 🏗️ La chaîne de communication

$$
b_k \xrightarrow{\text{bits→sym}} a_n \xrightarrow{h(t)} s_l(t) \xrightarrow{h_c, z_l} y_l(t) \xrightarrow{h_a(t)} r_l(t) \xrightarrow{\text{éch. } nT_s} r_n \xrightarrow{\text{décision}} \hat{a}_n
$$
![[comnum_archi_commu.png]]

**Modèle équivalent après échantillonnage :**
$$
r_n = g_0 \, a_n + \underbrace{\sum_{m \neq 0} g_m \, a_{n-m}}_{\text{IES}} + z_n'
$$

avec $g(t) = (h_a \star h_c \star h)(t)$ le **filtre global** et $g_n = g(nT_s)$.

---

## 📊 Débits et symboles

| Grandeur | Formule |
|----------|---------|
| Temps bit / débit binaire | $D_b = 1/T_b$ |
| Temps symbole / débit symbole | $D_s = 1/T_s$ |
| Nombre de symboles | $M = 2^{n_b}$ |
| Relation bits/symboles | $D_b = n_b D_s = \log_2(M) \cdot D_s$ |
| Lien temporel | $T_s = \log_2(M) \cdot T_b$ |

---

## 🎯 Critère de Nyquist (pas d'IES)

| Version | Condition |
|---------|-----------|
| **Temporelle** | $g(nT_s) = g_0 \, \delta_n$  ⇔  $g(t) \mathrm{III}_{T_s}(t) = g_0 \, \delta(t)$ |
| **Fréquentielle** | $\dfrac{1}{T_s} \displaystyle\sum_{m} G\!\left(f - \dfrac{m}{T_s}\right) = g_0$ |
| **Support borné** | Point $(1/(2T_s), g_0/2)$ centre de symétrie de $G(f)$ |

**Fréquence de Nyquist** : $f_N = 1/(2T_s)$.

---

## 🎲 Probabilités utiles

| Outil                                                  | Formule                                                                      |
| ------------------------------------------------------ | ---------------------------------------------------------------------------- |
| Gaussienne                                             | $f_X(x) = \dfrac{1}{\sqrt{2\pi\sigma^2}} e^{-(x-\mu)^2/(2\sigma^2)}$         |
| Si $Y = aX + b$ et $X \sim \mathcal{N}(\mu, \sigma^2)$ | $Y \sim \mathcal{N}(a\mu+b, a^2\sigma^2)$                                    |
| Fonction $Q$                                           | $Q(x) = \dfrac{1}{\sqrt{2\pi}} \displaystyle\int_x^{+\infty} e^{-u^2/2}\,du$ |
| Variance                                               | $\text{VAR}(X) = \mathbb{E}[\vert X \vert^2] - \vert \mathbb{E}[X] \vert^2$  |
| $R \sim \mathcal{N}(\mu, \sigma^2)$                    | $P(R > \gamma) = Q\!\left(\dfrac{\gamma - \mu}{\sigma}\right)$               |

---

## ⚖️ Probabilités d'erreur

| Quantité | Formule |
|----------|---------|
| Pb symbole | $P_s = P(\hat{a}_n \neq a_n)$ |
| Pb binaire | $P_b = P(\hat{b}_k \neq b_k)$ |
| **Gray** | $P_b \simeq P_s / \log_2(M)$ |
| Étiquetage quelconque | $P_b \geq P_s / \log_2(M)$ |

### Seuil de décision optimal (cas binaire)

$$
\gamma^*(p_0) = \log\!\left(\dfrac{p_0}{1-p_0}\right) \cdot \dfrac{\sigma^2}{2 g_0}
$$

→ $\gamma^* = 0$ si symboles équiprobables.

### Pb en bande de base (M-PAM, Gray, équiprobable)

$$
P_b = \dfrac{2(M-1)}{M \log_2(M)} \, Q\!\left(\dfrac{g_0}{\sigma}\right)
$$

---

## 🔧 Filtre adapté et récepteur optimal

| Résultat                  | Formule                                                          |
| ------------------------- | ---------------------------------------------------------------- |
| **Filtre adapté** (idéal) | $h_a(t) = h^*(-t)$                                               |
| **Causal en pratique**    | $h_a(t) = h^*(T_h - t)$, échantillonnage en $t = T_h$            |
| **Énergie de $h$**        | $E_h = \int \vert h(t) \vert^2 dt = \int \vert H(f) \vert^2 df$  |
| **SNR optimal**           | $(g_0^2/\sigma^2)_{\max} = 2 E_h / N_0$                          |
| **$P_{b,\min}$**          | $\dfrac{2(M-1)}{M \log_2(M)} Q\!\left(\sqrt{2 E_h / N_0}\right)$ |
| **Demi-Nyquist**          | $H(f) = H_a(f) = \sqrt{\mathrm{Ny}(f)}$                          |

---

## 🎼 DSP et énergie par bit

| Grandeur            | Formule                                                            |
| ------------------- | ------------------------------------------------------------------ |
| Wiener-Khintchine   | $\Gamma_X(f) = \mathrm{TF}(R_X(\tau))$                             |
| Filtrage en DSP     | $\Gamma_Y(f) = \vert H(f) \vert^2 \, \Gamma_X(f)$                  |
| **DSP de $s_l$**    | $\Gamma_{s_l}(f) = \dfrac{\sigma_a^2 \vert H(f) \vert^2}{T_s}$     |
| Puissance moyenne   | $P = \int \Gamma(f)\,df = R(0)$, $P = \dfrac{\sigma_a^2 E_h}{T_s}$ |
| **Énergie par bit** | $E_b = P T_b = \dfrac{\sigma_a^2 E_h}{\log_2(M)}$                  |
| M-PAM équiprobable  | $\sigma_a^2 = (M^2-1)/3$                                           |

---

## 📡 Fréquence porteuse

| Concept | Formule |
|---------|---------|
| Signal réel | $s(t) = \mathrm{Re}\{s_l(t) \, e^{j 2\pi f_c t}\}$ |
| Décomposition I/Q | $s(t) = p(t)\cos(2\pi f_c t) - q(t)\sin(2\pi f_c t)$ |
| Enveloppe complexe | $s_l(t) = p(t) + j q(t)$ |
| Symbole complexe | $S_n = A_n e^{j\varphi_n}$ |
| Signal modulé général | $s(t) = \sum_n A_n h(t - nT_s) \cos(2\pi f_c t + \varphi_n)$ |
| Modèle BdB équivalent | $r_n = g_0 \, S_n + z_n'$ |

---

## 🎯 Pb des modulations (formules clés)

| Modulation | $P_b$ |
|------------|-------|
| **M-ASK / M-PAM** | $\dfrac{2(M-1)}{M \log_2 M} \, Q\!\left(\sqrt{\dfrac{6 \log_2 M}{M^2 - 1} \cdot \dfrac{E_b}{N_0}}\right)$ |
| **M-PSK** | $2 \, Q\!\left(\sqrt{2 \log_2 M \cdot \sin^2\!\left(\dfrac{\pi}{M}\right) \cdot \dfrac{E_b}{N_0}}\right)$ |
| **M-FSK** | $2 \, Q\!\left(\sqrt{E_b/N_0}\right)$ |

### Cas particuliers à savoir

| Modulation | $P_b$ simplifié |
|------------|-----------------|
| BPSK (= 2-PAM) | $Q\!\left(\sqrt{2 E_b/N_0}\right)$ |
| QPSK (= 4-QAM) | $\approx Q\!\left(\sqrt{2 E_b/N_0}\right)$ |

---

## 🧠 Synoptique pour résoudre un exo

**Étape 1 — Identifier la modulation** : M-PAM, BPSK, QPSK, QAM, FSK, PSK ?

**Étape 2 — Vérifier les hypothèses** :
- Critère de Nyquist (pas d'IES) ?
- Symboles équiprobables ?
- Bruit gaussien blanc de DSP $N_0/2$ ?
- Filtre adapté utilisé ?

**Étape 3 — Choisir la bonne formule** :
- Si SNR donné en $g_0/\sigma$ : utilise $P_b = Q(g_0/\sigma)$ (BPSK) ou la formule M-PAM brute
- Si SNR donné en $E_b/N_0$ : utilise les formules avec $E_b/N_0$

**Étape 4 — Si pas de filtre adapté** :
- Calculer $g_0 = \int H(f) H_a(f) df$
- Calculer $\sigma^2 = \dfrac{N_0}{2} \int |H_a(f)|^2 df$
- Conclure avec $P_b = Q(g_0/\sigma)$ (pour BPSK) ou la formule M-PAM

---

## 🌟 Identités utiles (Cauchy-Schwarz, Parseval)

- **Parseval** : $\int |h(t)|^2 dt = \int |H(f)|^2 df = E_h$
- **Cauchy-Schwarz** : $\left|\int u v^* dt\right|^2 \leq \int |u|^2 dt \cdot \int |v|^2 dt$, égalité ssi $u = \lambda v^*$
- **Convolution → produit en F** : $\mathrm{TF}(h_1 \star h_2) = H_1(f) \cdot H_2(f)$
- **Translation en fréquence** : $\mathrm{TF}\!\left(x(t) e^{j 2\pi f_0 t}\right) = X(f - f_0)$

---

## 🎓 Pour aller plus loin

- [[01 - Introduction et modèle de Shannon]]
- [[02 - Signaux en bande de base]]
- [[03 - Critère de Nyquist (IES)]]
- [[04 - Diagramme de l'œil]]
- [[05 - Rappels de probabilités]]
- [[06 - Probabilité d'erreur]]
- [[07 - Récepteur optimal et filtre adapté]]
- [[08 - DSP des signaux codés en ligne]]
- [[09 - Eb sur N0]]
- [[10 - Transmission sur fréquence porteuse]]
- [[11 - Modulations numériques]]
