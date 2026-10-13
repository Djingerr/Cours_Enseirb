---
tags: [communications-numériques, diagramme-oeil, IES]
---

# 04 — Diagramme de l'œil

[[00 - Index - Communications Numériques|← Retour à l'index]]

---

## 👁️ Qu'est-ce que c'est ?

Le **diagramme de l'œil** est une visualisation pratique du signal reçu $r_l(t)$ obtenu en :
1. Découpant le signal en segments de durée $T_s$ (ou $2T_s$)
2. **Superposant** tous ces segments sur un même graphe

→ La forme finale ressemble à un œil ouvert.

```
Amplitude
   ↑
 +1┤    ╱╲      ╱╲      ╱╲
   │   ╱  ╲    ╱  ╲    ╱  ╲     ← Pic positif
   │  ╱    ╲  ╱    ╲  ╱    ╲    ┐
   │ ╱      ╲╱      ╲╱      ╲   │ Ouverture
   │  ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─    ─┼ verticale
   │ ╲      ╱╲      ╱╲      ╱   │
   │  ╲    ╱  ╲    ╱  ╲    ╱    ┘
   │   ╲  ╱    ╲  ╱    ╲  ╱
 -1┤    ╲╱      ╲╱      ╲╱      ← Pic négatif
   └──┬───────┬───────┬───────→ t
     -Ts/2    0      Ts/2
        ←─────→
       Ouverture
       horizontale
```

---

## 🔎 Comment l'analyser

L'analyse du diagramme de l'œil permet de **diagnostiquer la qualité** du système :

### ✅ Présence/absence d'IES
- **Œil bien ouvert** (croisements nets en 0) → pas d'IES → critère de Nyquist respecté
- **Œil fermé** (lignes qui s'écartent) → IES présente

### 📏 Ouverture verticale = robustesse au bruit
- Plus l'œil est ouvert verticalement, plus on tolère du bruit avant de faire des erreurs de décision
- L'ouverture verticale ≈ marge entre la valeur reçue et le seuil de décision

### ⏱️ Ouverture horizontale = robustesse aux décalages temporels
- Plus l'œil est large horizontalement, plus on tolère un mauvais réglage de l'instant d'échantillonnage $nT_s$
- Utile en pratique car la synchronisation parfaite est impossible

---

## 📊 Résumé visuel

| Caractéristique | Ce qu'elle indique |
|-----------------|---------------------|
| Œil ouvert | Pas d'IES |
| **Hauteur** ↗ | Robustesse au **bruit** ↗ |
| **Largeur** ↗ | Robustesse aux **erreurs d'échantillonnage** ↗ |
| Œil fermé | IES sévère ou bruit excessif |

---

## ✅ À retenir

- C'est un **outil pratique** pour diagnostiquer l'IES (lié à [[03 - Critère de Nyquist (IES)]])
- L'instant **optimal** d'échantillonnage = là où l'œil est **le plus ouvert**
- Trois indicateurs : ouverture verticale, ouverture horizontale, présence/absence de croisements à 0
