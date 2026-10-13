---
tags: [communications-numériques, index, MOC]
---

# 📡 Communications Numériques — Cours complet

> Fiches de révision pour l'examen — basées sur le cours de **Romain Tajan**.
> Format : Markdown + LaTeX (compatible Obsidian).

---

## 🎯 Vue d'ensemble : la chaîne de communication

Toute la matière tourne autour d'une seule figure que tu dois savoir par cœur :

```
[Source] → [bits→symboles] → [filtre h(t)] → [canal hc(t) + bruit z(t)] → [filtre ha(t)] → [échant. nTs] → [décision] → [symboles→bits] → [Destination]
   bk            an              sl(t)              yl(t)                      rl(t)              rn             ân
```

**Quatre questions essentielles :**
1. Comment éviter les **interférences entre symboles (IES)** ? → [[02 - Critère de Nyquist (IES)]]
2. Comment minimiser la **probabilité d'erreur** en présence de bruit ? → [[04 - Probabilité d'erreur]]
3. Comment choisir un **récepteur optimal** ? → [[05 - Récepteur optimal et filtre adapté]]
4. Comment **transmettre sur fréquence porteuse** (sans fil) ? → [[08 - Transmission sur fréquence porteuse]]

---

## 📚 Plan des fiches

| # | Fiche | Contenu |
|---|---|---|
| 01 | [[01 - Introduction et modèle de Shannon]] | Définitions, modèle Shannon-Weaver, bande de base vs transposée |
| 02 | [[02 - Signaux en bande de base]] | bk, sb(t), an, sa(t), sl(t), débits, constellation |
| 03 | [[03 - Critère de Nyquist (IES)]] | IES, critère temporel et fréquentiel, cosinus surélevé |
| 04 | [[04 - Diagramme de l'œil]] | Lecture du diagramme, robustesse |
| 05 | [[05 - Rappels de probabilités]] | VA, espérance, variance, loi gaussienne, fonction Q |
| 06 | [[06 - Probabilité d'erreur]] | Pb, Ps, modulation binaire, M-aire, seuil optimal |
| 07 | [[07 - Récepteur optimal et filtre adapté]] | Maximisation du SNR, filtre adapté, Cauchy-Schwarz |
| 08 | [[08 - DSP des signaux codés en ligne]] | Processus aléatoires, stationnarité, Wiener-Khintchin |
| 09 | [[09 - Eb sur N0]] | Énergie par bit, expression unifiée de Pb |
| 10 | [[10 - Transmission sur fréquence porteuse]] | Enveloppe complexe, voie I/Q, projections orthogonales |
| 11 | [[11 - Modulations numériques]] | ASK, PSK, APK/QAM, FSK, performances |
| 12 | [[12 - Formulaire et antisèche]] | Toutes les formules en 1 page |

---

## 🧠 Stratégie de révision (ordre conseillé)

**Si tu as peu de temps :** lis dans cet ordre →
1. [[12 - Formulaire et antisèche]] (vue globale en 5 min)
2. [[01 - Introduction et modèle de Shannon]] + [[02 - Signaux en bande de base]] (vocabulaire)
3. [[03 - Critère de Nyquist (IES)]] (concept central #1)
4. [[06 - Probabilité d'erreur]] (concept central #2)
5. [[07 - Récepteur optimal et filtre adapté]] (point clé)
6. [[09 - Eb sur N0]] (synthèse)
7. [[11 - Modulations numériques]] (résultats à connaître)
8. Le reste si tu as le temps.

---

## 🔑 Concepts à maîtriser absolument

- **IES** (Interférence Entre Symboles) et son annulation par le critère de Nyquist
- **Fonction Q** : $Q(x) = \frac{1}{\sqrt{2\pi}} \int_x^{+\infty} e^{-u^2/2} du$
- **Filtre adapté** : $h_a(t) = h^*(-t)$
- **Pb pour M-PAM/QAM/PSK/FSK** en fonction de $E_b/N_0$
- **Enveloppe complexe** : $s(t) = \mathrm{Re}\{s_l(t) e^{j2\pi f_c t}\}$
