---
tags: [communications-numériques, bande-de-base, signaux]
---

# 02 — Signaux en bande de base

[[00 - Index - Communications Numériques|← Retour à l'index]]

---

## 🏗️ Architecture complète bande de base

```
                       CODEUR EN LIGNE                           CANAL
       ┌──────────────────────────────────────┐
 bk    │  Asso.        an              h(t)   │  sl(t)   hc(t)
─────→ │  bits→sym ────→  sa(t) ─────→ filtre │ ───────→ canal ───→ + ───→
       └──────────────────────────────────────┘                     ↑
                                                                   zl(t)
                                                                   bruit
                       DÉCODEUR EN LIGNE
       ┌──────────────────────────────────────┐    yl(t)
 b̂k    │ Asso.   ân           rn      ha(t)  │  ←───────
←───── │ sym→bits ←─ Décision ←── échant. ←── │  filtre
       │                       nTs            │  récept.
       └──────────────────────────────────────┘
```

🔑 **Apprends ce schéma par cœur** — c'est la trame de tout le cours.

---

## 1️⃣ Bits émis : $b_k$ et $s_b(t)$

**Côté discret** : $b_k$ est la séquence de bits (variables aléatoires **iid**, loi de **Bernoulli**) :
$$
P(b_k = 0) = p_0, \quad P(b_k = 1) = p_1, \quad p_0 + p_1 = 1
$$

**Côté continu** : on associe à $b_k$ le signal à temps continu
$$
s_b(t) = \sum_{k=-\infty}^{+\infty} b_k \, \delta(t - kT_b)
$$

- $T_b$ : **temps bit** (en secondes)
- $D_b = \dfrac{1}{T_b}$ : **débit binaire** (bits/s)

> **Exemple** : $T_b = 1\,\mu s \Rightarrow D_b = 1\,\text{Mbits/s}$

---

## 2️⃣ Symboles : $a_n$ et $s_a(t)$

L'**association bits → symboles** prend des paquets de $n_b$ bits et leur associe un **symbole** :
- $n_b$ bits → $M = 2^{n_b}$ symboles
- L'ensemble des symboles = **constellation**
- Bande de base : symboles **réels** ; bande transposée : symboles **complexes**

Exemple (4-PAM, $M=4$, $n_b=2$) :
```
   [00]    [01]    [11]    [10]
─────●───────●───────●───────●─────→ Voie en phase
    -3      -1       1       3
```

**Signal symbole** :
$$
s_a(t) = \sum_{m=-\infty}^{+\infty} a_m \, \delta(t - mT_s)
$$

- $T_s$ : **temps symbole**
- $D_s = \dfrac{1}{T_s}$ : **débit symbole** (symboles/s)
- **Relation clé** : $\boxed{D_b = n_b \cdot D_s = \log_2(M) \cdot D_s}$

> **Exemple** : $T_s = 1\,\mu s$, $n_b = 2$ → $D_s = 1$ Msym/s, $D_b = 2$ Mbits/s.

---

## 3️⃣ Filtrage de mise en forme : $s_l(t)$

$h(t)$ est le **filtre de mise en forme** à l'émission (linéaire, invariant). On a :
$$
s_l(t) = (h \star s_a)(t) = \sum_{m=-\infty}^{+\infty} a_m \, h(t - mT_s)
$$

→ Le filtre transforme les impulsions $\delta$ en formes d'onde réelles.

---

## 4️⃣ Canal et bruit : $y_l(t)$

Avec $h_c(t)$ la réponse impulsionnelle du canal et $z_l(t)$ un bruit **gaussien blanc réel** :
$$
y_l(t) = (h_c \star s_l)(t) + z_l(t) = \sum_m a_m \, (h_c \star h)(t - mT_s) + z_l(t)
$$

---

## 5️⃣ Filtre de réception : $r_l(t)$

$h_a(t)$ est le **filtre de réception**. On obtient :
$$
r_l(t) = (h_a \star y_l)(t) = \sum_m a_m \, g(t - mT_s) + z_l'(t)
$$

où l'on définit le **filtre global** :
$$
\boxed{\, g(t) = (h_a \star h_c \star h)(t) \,}
$$

et $z_l'(t) = (h_a \star z_l)(t)$ est le bruit filtré.

---

## 6️⃣ Échantillonnage : $r_n$

À l'instant $t = nT_s$ on obtient :
$$
r_n = r_l(nT_s) = \sum_m a_m \, g((n-m)T_s) + z_l'(nT_s)
$$

En posant $g_n = g(nT_s)$ et $z_n' = z_l'(nT_s)$ :
$$
\boxed{\,r_n = g_0 a_n + \underbrace{\sum_{m \neq 0} g_m \, a_{n-m}}_{\text{IES}} + z_n'\,}
$$

→ Le premier terme est le **symbole d'intérêt** ; le second est l'**Interférence Entre Symboles** (voir [[03 - Critère de Nyquist (IES)]]).

---

## 7️⃣ Décision : $\hat{a}_n$

Le bloc de décision détermine dans **quelle région de décision** se trouve $r_n$, en utilisant des **seuils** (frontières) :

```
   ân=-3      ân=-1       ân=1      ân=3
─────●──┬─────●──┬────●──┬────●─────→
    -3  γ0   -1  γ1   1  γ2   3
```

⚠️ Les seuils ne sont pas forcément équidistants : ils dépendent des probabilités d'apparition des symboles (voir [[06 - Probabilité d'erreur]]).

---

## ✅ À retenir

- Toujours **distinguer bits ($b_k$) et symboles ($a_n$)** : un symbole transporte $\log_2(M)$ bits
- Le **filtre global** $g(t) = h_a \star h_c \star h$ détermine toute la qualité de la transmission
- Le modèle final : $r_n = g_0 a_n + \text{IES} + \text{bruit}$
