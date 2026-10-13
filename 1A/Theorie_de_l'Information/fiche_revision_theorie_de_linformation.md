# 📘 FICHE DE RÉVISION — THÉORIE DE L’INFORMATION

---

## 🧠 1. Origine & objectif

- Fondée en **1948 par Claude Shannon**
- Objectif : transmettre un message efficacement et sans erreur

> Problème : reproduire un message malgré le bruit

---

## 🔄 2. Modèle de Shannon

```
Source → Canal → Récepteur
```

### 🔹 Source
- Génère des données (texte, image, son…)
- Modélisée par une variable aléatoire **X**

👉 **Information = incertitude**

---

## 📊 3. Entropie (notion centrale)

### Définition

```
H(X) = - Σ P(X=x) log P(X=x)
```

👉 Mesure :
- incertitude moyenne
- quantité d’information

### 💡 Intuition
- événement rare → beaucoup d’info
- événement probable → peu d’info

### 📌 Exemples
- Pile/face équilibré → H = 1 bit (max)
- Deux dés → H ≈ 3.27 bits

### ⚠️ Propriétés
- H(X) ≥ 0
- H(X) ≤ log(|X|)
- max si loi uniforme

---

## 🔗 4. Entropies avancées

### Entropie jointe
```
H(X,Y)
```

### Entropie conditionnelle
```
H(X|Y)
```

### Relation clé
```
H(X,Y) = H(Y) + H(X|Y)
```

---

## 🔁 5. Information mutuelle

### Définition
```
I(X;Y) = H(X) - H(X|Y)
```

👉 Interprétation : info gagnée sur X grâce à Y

### Propriétés
- I ≥ 0
- = 0 si indépendance
- max si dépendance totale

---

## 📏 6. Divergence de Kullback-Leibler

### Définition
```
D(p||q) = Σ p(x) log(p(x)/q(x))
```

👉 Mesure la différence entre distributions

### ⚠️
- ≥ 0
- = 0 si identiques
- pas symétrique

---

## 📦 7. Codage source (compression)

### Objectif
Réduire la taille sans perte

### Code
```
ψ : x → mot binaire
```

### Longueur moyenne
```
L(ψ) = Σ ℓ(ψ(x)) P(X=x)
```

👉 Idée : symboles fréquents → codes courts

---

## 🔐 8. Propriétés des codes

### Code déchiffrable
→ décodage unique

### Code préfixe
→ aucun mot n’est préfixe d’un autre

👉 Tout code préfixe est déchiffrable

---

## 📐 9. Théorème de Shannon (codage source)

```
L(φ) ≥ H(X)
```

👉 Impossible de compresser sous l’entropie

```
H(X) ≤ L(φ) ≤ H(X) + 1
```

---

## 🌳 10. Code de Huffman

### Principe
1. Prendre les 2 plus faibles probabilités
2. Les regrouper
3. Répéter

👉 Code optimal (préfixe)

---

## 📡 11. Codage canal

### Objectif
Corriger les erreurs

### Code
```
φ : m → message plus long
```

### Rendement
```
R = k/n
```

### Probabilité d’erreur
```
Pe = P(M̂ ≠ M)
```

### Compromis
- + redondance → - erreurs
- - rendement

---

## 🚀 12. Théorème de Shannon (canal)

👉 Il existe une capacité max :
- transmission fiable si débit < capacité

---

## 🌍 13. Applications

- Compression (ZIP, JPEG)
- Télécoms (WiFi, 4G)
- Cryptographie
- Machine learning

---

# 🧠 RÉSUMÉ EXPRESS

- Entropie = incertitude
- Info mutuelle = info partagée
- KL = différence entre lois
- Compression → limite = entropie
- Huffman = optimal
- Canal = compromis débit/erreur

---

# 🎯 ASTUCES EXAM

✔ Connaître : H(X), I(X;Y), D(p||q)
✔ Vérifier indépendance
✔ Associer :
- compression → Huffman
- transmission → canal + bruit

