---
tags: [communications-numériques, Nyquist, IES]
---

# 03 — Critère de Nyquist (IES)

[[00 - Index - Communications Numériques|← Retour à l'index]]

> **Concept central #1 du cours.** Sans Nyquist, pas de communication sans erreur, même sans bruit.

---

## ⚠️ Le problème : l'IES

Après échantillonnage on a (cf [[02 - Signaux en bande de base]]) :
$$
r_n = g_0 a_n + \underbrace{\sum_{m \neq 0} g_m \, a_{n-m}}_{\text{IES}} + z_n'
$$

**IES = Interférence Entre Symboles** : interférence provoquée par les symboles voisins $..., a_{n-2}, a_{n-1}, a_{n+1}, a_{n+2}, ...$ sur la réception du symbole d'intérêt $a_n$.

🚨 **Si les filtres $h(t)$ et $h_a(t)$ sont mal choisis, la communication sans erreur peut être impossible — même en l'absence de bruit !**

---

## 🎯 Critère de Nyquist (version temporelle)

**Annulation de l'IES** ⇔ $g_m = 0$ pour tout $m \neq 0$ et $g_0 \neq 0$.

Formulation compacte :
$$
\boxed{\, g(t) \cdot \mathrm{III}_{T_s}(t) = g_0 \, \delta(t) \,}
$$

où $\mathrm{III}_{T_s}(t) = \sum_n \delta(t - nT_s)$ est le peigne de Dirac.

Cela revient à : **$g(t)$ s'annule à tous les multiples de $T_s$, sauf en 0**.

```
    g(t)
     │
   g₀│      .
     │     .·.
     │   .·   ·.
     │  ·  ·   ·  ·.
─────●──●──●──●──●──●──●──●──→ t
    -3Ts -2Ts -Ts  0  Ts 2Ts 3Ts
                    ↑
                 g(nTs)=0 pour n≠0
```

---

## 🎯 Critère de Nyquist (version fréquentielle)

Si $G(f) = \mathrm{TF}(g(t)) = H(f) \cdot H_a(f)$ vérifie :
$$
\boxed{\, \frac{1}{T_s} \sum_{m=-\infty}^{+\infty} G\left(f - \frac{m}{T_s}\right) = g_0 \,}
$$

alors **il n'y a pas d'IES**.

→ La somme des "copies" décalées de $G(f)$ par multiples de $1/T_s$ doit donner une **constante**.

### 📝 Cas particulier : $G(f)$ à support borné dans $[-1/T_s, 1/T_s]$

Le critère devient :
> Le point $\left(\dfrac{1}{2T_s}, \dfrac{g_0}{2}\right)$ est un **centre de symétrie** pour $G(f)$ sur $[0, 1/T_s]$.

La fréquence $\boxed{f_N = \dfrac{1}{2T_s}}$ est la **fréquence de Nyquist**.

---

## 🌊 Exemple : filtre en cosinus surélevé

Famille de filtres très utilisée en pratique. Paramètre $\beta \in [0, 1]$ : facteur de **roll-off**.

| $\beta$ | Comportement |
|---------|--------------|
| $\beta = 0$ | Sinc parfait — bande minimale mais lobes secondaires importants |
| $\beta = 0.5$ | Compromis classique |
| $\beta = 1$ | Plus large en fréquence, lobes très atténués |

**Bande passante** du cosinus surélevé : $B = \dfrac{1 + \beta}{2 T_s}$

→ Plus $\beta$ augmente, plus on consomme de bande, mais plus le filtre est tolérant aux décalages temporels.

---

## 🛠️ Méthode pratique pour un exercice

Pour vérifier si un filtre $g(t)$ ou $G(f)$ satisfait Nyquist :

**En temps** :
1. Tracer $g(t)$
2. Vérifier que $g(nT_s) = 0$ pour tout $n \neq 0$

**En fréquence** :
1. Tracer $G(f)$
2. Vérifier la condition de symétrie autour de $f = 1/(2T_s)$ (cas support borné)
3. Ou faire la somme des translatées et voir si on obtient une constante

---

## 🔑 Conclusion

> Les **IES** résultent d'un mauvais choix de $(h(t), h_a(t))$.
> Les IES peuvent rendre la communication **sans erreur impossible**, même sans bruit.
> Le **critère de Nyquist** garantit leur absence.

| Forme | Condition |
|-------|-----------|
| Temporelle | $g_n = g(nT_s) = g_0 \delta_n$ |
| Fréquentielle | $\dfrac{1}{T_s} \sum_m G\left(f - \dfrac{m}{T_s}\right) = g_0$ |

→ Pour visualiser concrètement l'IES, voir [[04 - Diagramme de l'œil]]
→ Pour le choix optimal des filtres avec bruit, voir [[07 - Récepteur optimal et filtre adapté]]
