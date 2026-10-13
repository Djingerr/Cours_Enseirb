# Fiche — Théorie de l'Information

## Vue d'ensemble

La **théorie de l'information** répond à une question fondamentale : combien d'information contient un message, et jusqu'où peut-on le comprimer ou le transmettre de façon fiable ? Le cours s'articule autour de trois blocs logiques emboîtés — *mesure* de l'information, *codage source* (compression), *codage canal* (protection contre le bruit) — chacun culminant dans un théorème de Shannon. La logique globale : l'[[entropie]] est la limite théorique absolue, et tous les algorithmes pratiques cherchent à l'atteindre.

---

## Concepts fondamentaux

### Mesure de l'information

- **Quantité d'information** d'un événement $A$ : `h(P(A)) = -log(P(A))`. Plus un événement est rare, plus il est informatif. *Analogie : apprendre qu'il a neigé en juillet apporte plus d'info qu'apprendre qu'il a plu.*
- **[[Entropie]]** `H(X) = -Σ p(x) log p(x)` : incertitude *moyenne* d'une source. Maximisée par la loi uniforme (discret) ou la loi gaussienne (continu à variance fixée).
- **[[Entropie différentielle]]** : même formule avec une intégrale. Attention — elle peut être **négative**, contrairement au cas discret.
- **[[Entropie jointe et conditionnelle]]** : `H(X,Y)` et `H(X|Y)`. Règle de la chaîne : `H(X,Y) = H(X) + H(Y|X)`.
- **[[Information mutuelle]]** : `I(X;Y) = H(X) - H(X|Y)`. Mesure ce que Y apprend sur X. Symétrique, toujours ≥ 0.
- **[[Divergence de Kullback-Leibler]]** : `D(p||q) = Σ p(z) log(p(z)/q(z))`. Mesure l'écart entre deux distributions. Non symétrique.

> [!WARNING] Piège fréquent
> L'entropie différentielle d'une v.a. continue **peut être négative** (ex : loi uniforme sur $[0, 0.5]$). Ce n'est pas une erreur de calcul — l'entropie continue n'est pas une mesure de probabilité.

> [!WARNING] Piège fréquent
> `D(p||q) ≠ D(q||p)` : la divergence KL n'est **pas une distance** au sens mathématique. Ne pas confondre avec une métrique symétrique.

---

### Codage source

- **[[Code préfixe]]** (ou instantané) : aucun mot de code n'est préfixe d'un autre → décodage immédiat, sans ambiguïté.
- **[[Théorème de Kraft]]** : un code déchiffrable d'alphabet de taille $d$ et longueurs $l_x$ existe ssi `Σ d^{-l_x} ≤ 1`.
- **[[1er Théorème de Shannon]]** (codage source) : `L(φ) ≥ H(X) / log(d)`. L'entropie est la borne inférieure incompressible.
- **[[Algorithme de Huffman]]** : construit le code préfixe *optimal* (longueur moyenne minimale).

```
1. Trier les symboles par probabilité décroissante
2. Fusionner les 2 (ou d) moins probables → supersymbole (somme des proba)
3. Répéter jusqu'à un seul symbole
4. Étiqueter les branches 0/1 (ou 0/1/2 pour ternaire)
⚠️ Ternaire : ajouter des symboles muets (proba 0) pour que
   (n - 1) soit divisible par (d - 1)
```

> [!WARNING] Piège fréquent
> Pour un Huffman **ternaire**, le nombre de feuilles doit satisfaire une condition de parité. Si ce n'est pas le cas, ajouter des **symboles fictifs de probabilité 0** avant de commencer — oubli très fréquent en examen.

---

### Codage canal

- **[[Capacité de canal]]** : `C = sup_{p_X} I(X,Y)`. Taux maximal de transmission fiable.
- **[[2ème Théorème de Shannon]]** (codage canal) : si le rendement `R < C`, il existe des codes avec probabilité d'erreur → 0. En dessous de la capacité, la communication fiable est *toujours possible*.
- **[[Canal gaussien]]** : `C = ½ log(1 + γ²/σ²)`. La capacité croît logarithmiquement avec le rapport signal/bruit.

---

## Ce que le prof veut que tu retiennes

- [ ] Savoir calculer `H(X)` numériquement, y compris pour une loi géométrique infinie
- [ ] Connaître et appliquer la règle de la chaîne : `H(X,Y) = H(X) + H(Y|X)`
- [ ] Démontrer que `D(p||q) ≥ 0` (inégalité de Gibbs) et en déduire que la loi uniforme maximise l'entropie
- [ ] Construire un arbre de Huffman binaire **et** ternaire (avec symboles muets)
- [ ] Énoncer les deux théorèmes de Shannon et identifier la grandeur limite dans chaque cas
- [ ] Calculer `I(X;Y)` à partir d'une matrice de canal
- [ ] Ne pas confondre entropie discrète (≥ 0) et entropie différentielle (signe libre)

---

## Carte mentale textuelle

```
Source aléatoire X
  → [incertitude moyenne] → Entropie H(X)
  → [borne compression] → 1er Théorème de Shannon
  → [algorithme optimal] → Huffman

H(X) + H(Y|X)
  → [règle de la chaîne] → Entropie jointe H(X,Y)
  → [information partagée] → Information mutuelle I(X;Y)
  → [maximisée sur p_X] → Capacité C
  → [seuil transmission fiable] → 2ème Théorème de Shannon

Distribution p vs q
  → [écart non symétrique] → Divergence KL D(p||q)
  → [≥ 0, = 0 ssi p = q] → Inégalité de Gibbs
```

---

## Méthode de révision recommandée

> [!TIP] Stratégie
> Ce cours mêle **mémorisation de formules**, **compréhension de mécanismes** (pourquoi l'entropie est une limite ?) et **entraînement procédural** (Huffman, calculs matriciels). La priorité absolue : refaire les annales 2019, 2021 et 2022 *sans regarder les solutions*, puis vérifier les pièges listés ci-dessus. Pour Huffman, s'entraîner sur des alphabets de 5–8 symboles en binaire *et* ternaire jusqu'à ce que le réflexe « symboles muets » soit automatique. Les preuves (Gibbs, Shannon) doivent être reconstituées à la main au moins une fois.

---

*Voir aussi : [[Flashcards_Théorie de l'Information]] · [[Exercices_Théorie de l'Information]] · [[Annale_Théorie de l'Information]]*

#théorie-de-linformation #information-entropie #révision
