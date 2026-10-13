# Annale_Théorie_de_l'Information

## Sujet d'examen — Théorie de l'Information
**Durée : 1h00 — Sans document — Calculatrice non autorisée**
*Tous les logarithmes sont en base 2 (bits). Justifiez soigneusement chaque étape.*

---

## Exercice 1 — Entropie et information mutuelle (5 points)

Soit $(X, Y)$ un couple de variables aléatoires discrètes de loi jointe donnée par le tableau suivant :

|         | $Y = 0$ | $Y = 1$ | $Y = 2$ |
|---------|---------|---------|---------|
| $X = 0$ | 1/8     | 1/8     | 1/4     |
| $X = 1$ | 1/4     | 1/8     | 1/8     |

**1.a** Calculer les lois marginales $p_X$ et $p_Y$.

**1.b** Calculer $\mathbb{H}(X)$, $\mathbb{H}(Y)$ et l'[[entropie jointe]] $\mathbb{H}(X, Y)$.

**1.c** En déduire l'[[entropie conditionnelle]] $\mathbb{H}(X \mid Y)$ et vérifier la [[règle de la chaîne]] :
$$\mathbb{H}(X, Y) = \mathbb{H}(Y) + \mathbb{H}(X \mid Y)$$

**1.d** Calculer l'[[information mutuelle]] $\mathbb{I}(X; Y)$. Conclure sur la dépendance de $X$ et $Y$.

---

## Exercice 2 — Paradoxe et entropie conditionnelle (3 points)

Un modèle de prévision météo prédit chaque jour « Pluie » (R) ou « Soleil » (S). La météo réelle $W$ suit une loi de Bernoulli de paramètre $p = 0{,}9$ (il pleut 90 % du temps). Le modèle $\hat{W}$ prédit toujours « Pluie ».

**2.a** Calculer $\mathbb{H}(W)$.

**2.b** Calculer $\mathbb{I}(W; \hat{W})$.

**2.c** Le modèle a un taux de réussite de 90 %. Est-il pour autant utile d'un point de vue informationnel ? Justifier rigoureusement en une ou deux phrases.

> [!WARNING] Piège fréquent
> Un taux de réussite élevé ne garantit pas une information mutuelle non nulle. Un prédicteur constant est informatiquement inutile quelle que soit sa précision apparente.

---

## Exercice 3 — Codage de Huffman (5 points)

Une source émet des symboles sur l'alphabet $\mathcal{A} = \{a, b, c, d, e, f, g\}$ avec les probabilités suivantes :

| Symbole | $a$   | $b$   | $c$   | $d$   | $e$   | $f$   | $g$   |
|---------|-------|-------|-------|-------|-------|-------|-------|
| Prob.   | 1/2   | 1/8   | 1/8   | 1/16  | 1/16  | 1/16  | 1/16  |

**3.a** Calculer l'[[entropie]] $\mathbb{H}(\mathcal{A})$ de cette source.

**3.b** Construire un [[code de Huffman]] binaire pour cette source. Dessiner l'arbre et donner le tableau des mots de code.

**3.c** Calculer la longueur moyenne $\mathcal{L}(\varphi)$ du code obtenu et vérifier l'encadrement du [[premier théorème de Shannon]] :
$$\mathbb{H}(\mathcal{A}) \leq \mathcal{L}(\varphi) < \mathbb{H}(\mathcal{A}) + 1$$

**3.d** On souhaite maintenant construire un [[code de Huffman]] **ternaire** (alphabet de codage $\{0, 1, 2\}$) pour cette même source. Combien de symboles muets faut-il éventuellement ajouter ? Construire cet arbre ternaire.

> [!TIP] Méthode
> Pour un code Huffman ternaire sur $n$ symboles, la condition de validité est que $n \equiv 1 \pmod{2}$. Plus généralement pour un code $d$-aire, il faut que $n \equiv 1 \pmod{d-1}$. Ajouter des symboles de probabilité nulle si nécessaire.

---

## Exercice 4 — Question de synthèse (7 points)

Soit $X$ une variable aléatoire discrète à valeurs dans $\{1, 2, 3, \ldots\}$ de loi géométrique de paramètre $\alpha \in (0,1)$ :
$$\forall k \geq 1, \quad p_X(k) = (1-\alpha)^{k-1} \alpha$$

Soit $Y = \mathbf{1}_{X \geq 2}$ la variable indicatrice de l'événement $\{X \geq 2\}$.

**4.a** Calculer $\mathbb{H}(Y)$ en fonction de $\alpha$.

**4.b** Montrer que $\mathbb{H}(X \mid Y = 1) = 0$ et calculer $\mathbb{H}(X \mid Y = 0)$.

> [!NOTE] À retenir
> $\mathbb{H}(X \mid Y = 0)$ requiert de reconnaître la loi conditionnelle de $X$ sachant $\{X \geq 2\}$ — qui est une [[loi géométrique]] translatée de 1, par la propriété de [[perte de mémoire]].

**4.c** En déduire l'[[entropie conditionnelle]] $\mathbb{H}(X \mid Y)$, puis l'[[entropie]] $\mathbb{H}(X)$ via la [[règle de la chaîne]] :
$$\mathbb{H}(X) = \mathbb{H}(Y) + \mathbb{H}(X \mid Y)$$

**4.d** Vérifier votre résultat en calculant directement $\mathbb{H}(X) = -\sum_{k=1}^{\infty}(1-\alpha)^{k-1}\alpha \log\bigl((1-\alpha)^{k-1}\alpha\bigr)$ et en identifiant les séries classiques utilisées.

**4.e** (Bonus) Montrer que $\mathbb{I}(X ; Y) = \mathbb{H}(Y)$ et interpréter ce résultat.

> [!WARNING] Piège fréquent
> En 4.c, ne pas confondre $\mathbb{H}(X \mid Y)$ (entropie conditionnelle, moyenne sur $Y$) avec $\mathbb{H}(X \mid Y = y)$ (entropie conditionnelle pour une valeur fixée). La relation correcte est $\mathbb{H}(X \mid Y) = \sum_y p_Y(y)\,\mathbb{H}(X \mid Y = y)$.

---

---

# Corrigé_Théorie_de_l'Information

## Corrigé type — Annale simulée

---

## Exercice 1 — Corrigé

**1.a — Lois marginales**

$$p_X(0) = \tfrac{1}{8}+\tfrac{1}{8}+\tfrac{1}{4} = \tfrac{1}{2}, \quad p_X(1) = \tfrac{1}{4}+\tfrac{1}{8}+\tfrac{1}{8} = \tfrac{1}{2}$$
$$p_Y(0) = \tfrac{3}{8}, \quad p_Y(1) = \tfrac{2}{8} = \tfrac{1}{4}, \quad p_Y(2) = \tfrac{3}{8}$$

**1.b — Entropies**

$$\mathbb{H}(X) = -2 \cdot \tfrac{1}{2}\log\tfrac{1}{2} = 1 \text{ bit}$$

$$\mathbb{H}(Y) = -\tfrac{3}{8}\log\tfrac{3}{8} - \tfrac{1}{4}\log\tfrac{1}{4} - \tfrac{3}{8}\log\tfrac{3}{8}$$
$$= -\tfrac{3}{4}\log\tfrac{3}{8} - \tfrac{1}{4}\log\tfrac{1}{4} = \tfrac{3}{4}(3 - \log 3) + \tfrac{1}{2} \approx 1{,}56 \text{ bits}$$

$$\mathbb{H}(X,Y) = -\tfrac{1}{8}\log\tfrac{1}{8} \times 4 - \tfrac{1}{4}\log\tfrac{1}{4} \times 2 = 4 \cdot \tfrac{3}{8} + 2 \cdot \tfrac{1}{2} = \tfrac{3}{2} + 1 = 2{,}5 \text{ bits}$$

**1.c — Entropie conditionnelle et règle de la chaîne**

$$\mathbb{H}(X \mid Y) = \mathbb{H}(X,Y) - \mathbb{H}(Y) \approx 2{,}5 - 1{,}56 = 0{,}94 \text{ bit}$$

Vérification : $\mathbb{H}(Y) + \mathbb{H}(X\mid Y) = 1{,}56 + 0{,}94 = 2{,}5 = \mathbb{H}(X,Y)$. ✓

**1.d — Information mutuelle**

$$\mathbb{I}(X;Y) = \mathbb{H}(X) - \mathbb{H}(X \mid Y) = 1 - 0{,}94 = 0{,}06 \text{ bit}$$

$\mathbb{I}(X;Y) > 0$ donc $X$ et $Y$ sont **dépendantes** (bien que faiblement).

---

## Exercice 2 — Corrigé

**2.a**

$$\mathbb{H}(W) = -0{,}9\log(0{,}9) - 0{,}1\log(0{,}1) \approx 0{,}469 \text{ bit}$$

**2.b**

$\hat{W}$ est la constante « Pluie » avec probabilité 1, donc $\mathbb{H}(\hat{W}) = 0$.

Comme $\mathbb{I}(W;\hat{W}) = \mathbb{H}(\hat{W}) - \mathbb{H}(\hat{W}\mid W) = 0 - 0 = \mathbf{0}$.

**2.c**

Le modèle n'apporte **aucune information** sur la météo réelle : $\mathbb{I}(W;\hat{W}) = 0$. Connaître la prédiction ne réduit pas l'incertitude sur $W$. Le taux de réussite de 90 % est entièrement dû à la déséquilibre de la loi de $W$, pas à une capacité prédictive réelle.

---

## Exercice 3 — Corrigé

**3.a — Entropie**

$$\mathbb{H}(\mathcal{A}) = -\tfrac{1}{2}\log\tfrac{1}{2} - 2\cdot\tfrac{1}{8}\log\tfrac{1}{8} - 4\cdot\tfrac{1}{16}\log\tfrac{1}{16}$$
$$= \tfrac{1}{2} + \tfrac{6}{8} + \tfrac{16}{16} = \tfrac{1}{2} + \tfrac{3}{4} + 1 = \tfrac{9}{4} = 2{,}25 \text{ bits}$$

**3.b — Arbre de Huffman binaire**

Étapes de fusion (probabilités) :

```
Étape 1 : {d,e,f,g} → fusionner d(1/16) + e(1/16) = de(1/8)
Étape 2 : fusionner de(1/8) + f(1/16) ... 
```

Ordre décroissant initial : a(1/2), b(1/8), c(1/8), d(1/16), e(1/16), f(1/16), g(1/16)

```
Fusion 1 : f+g → fg (1/8)
Fusion 2 : d+e → de (1/8)
Fusion 3 : de+fg → defg (1/4)
Fusion 4 : b+c → bc (1/4)
Fusion 5 : bc+defg → bcdefg (1/2)
Fusion 6 : a+bcdefg → racine (1)
```

| Symbole | Code  | Longueur |
|---------|-------|----------|
| $a$     | 0     | 1        |
| $b$     | 100   | 3        |
| $c$     | 101   | 3        |
| $d$     | 1100  | 4        |
| $e$     | 1101  | 4        |
| $f$     | 1110  | 4        |
| $g$     | 1111  | 4        |

**3.c — Longueur moyenne**

$$\mathcal{L}(\varphi) = \tfrac{1}{2}\cdot1 + 2\cdot\tfrac{1}{8}\cdot3 + 4\cdot\tfrac{1}{16}\cdot4 = \tfrac{1}{2}+\tfrac{6}{8}+1 = 0{,}5+0{,}75+1 = 2{,}25 \text{ bits}$$

Vérification : $2{,}25 \leq 2{,}25 < 3{,}25$ ✓

> [!NOTE] À retenir
> Ici $\mathcal{L}(\varphi) = \mathbb{H}(\mathcal{A})$ exactement : le code est **parfait** car toutes les probabilités sont des puissances de 2 en base 2. C'est un cas remarquable que les étudiants excellents doivent signaler.

**3.d — Huffman ternaire**

7 symboles, $d=3$. Condition : $n \equiv 1 \pmod{2}$, donc $7 \equiv 1 \pmod{2}$ ✓. Aucun symbole muet nécessaire.

```
Fusion 1 (ternaire) : d+e+f → def (3/16)
Fusion 2 : g(1/16)+c(1/8)+def(3/16) ... 
```

Ordre : a(8/16), b(2/16), c(2/16), d(1/16), e(1/16), f(1/16), g(1/16)

```
Fusion 1 : d+e+g → deg (3/16)
Fusion 2 : b+c+f → bcf (5/16) ... (plusieurs arbres valides)
Fusion 3 : deg + bcf + a → racine
```

Un arbre valide (non unique) :

| Symbole | Code |
|---------|------|
| $a$     | 0    |
| $b$     | 10   |
| $c$     | 11   |
| $d$     | 120  |
| $e$     | 121  |
| $f$     | 122  |
| $g$     | 2    |

*(D'autres constructions valides sont acceptées si l'arbre est ternaire préfixe et optimal.)*

---

## Exercice 4 — Corrigé

**4.a**

$\mathbb{P}(Y=1) = \mathbb{P}(X \geq 2) = 1-\alpha$, $\mathbb{P}(Y=0) = \alpha$.

$$\mathbb{H}(Y) = -\alpha\log\alpha - (1-\alpha)\log(1-\alpha) =: h_b(\alpha)$$

**4.b**

$\{Y=1\} = \{X=1\}$ donc $\mathbb{P}(X=1 \mid Y=1) = 1$ : $X$ est **déterminé**, donc $\mathbb{H}(X\mid Y=1) = 0$.

Pour $\{Y=0\} = \{X \geq 2\}$, par la [[propriété de perte de mémoire]] de la loi géométrique :

$$\mathbb{P}(X = k+1 \mid X \geq 2) = \mathbb{P}(X = k), \quad k \geq 1$$

La loi de $X-1$ sachant $Y=0$ est donc une loi géométrique de paramètre $\alpha$, et :

$$\mathbb{H}(X \mid Y=0) = \mathbb{H}(X-1 \mid Y=0) = \mathbb{H}(X)$$

**4.c**

$$\mathbb{H}(X \mid Y) = \alpha \cdot \mathbb{H}(X\mid Y=1) + (1-\alpha)\cdot\mathbb{H}(X\mid Y=0) = 0 + (1-\alpha)\mathbb{H}(X)$$

Règle de la chaîne :

$$\mathbb{H}(X) = \mathbb{H}(Y) + \mathbb{H}(X\mid Y) = h_b(\alpha) + (1-\alpha)\mathbb{H}(X)$$

$$\alpha\,\mathbb{H}(X) = h_b(\alpha) \implies \boxed{\mathbb{H}(X) = \frac{h_b(\alpha)}{\alpha}}$$

**4.d — Calcul direct**

$$\mathbb{H}(X) = -\sum_{k=1}^{\infty}(1-\alpha)^{k-1}\alpha\bigl[(k-1)\log(1-\alpha)+\log\alpha\bigr]$$

$$= -\log\alpha - \log(1-\alpha)\cdot\frac{1-\alpha}{\alpha}$$

$$= \frac{-\alpha\log\alpha-(1-\alpha)\log(1-\alpha)}{\alpha} = \frac{h_b(\alpha)}{\alpha} \checkmark$$

Les deux séries utilisées sont $\sum_{k=0}^{\infty}(1-\alpha)^k = 1/\alpha$ et $\sum_{k=0}^{\infty}k(1-\alpha)^k = (1-\alpha)/\alpha^2$.

**4.e — Bonus**

$$\mathbb{I}(X;Y) = \mathbb{H}(X) - \mathbb{H}(X\mid Y) = \mathbb{H}(X) - (1-\alpha)\mathbb{H}(X) = \alpha\,\mathbb{H}(X) = h_b(\alpha) = \mathbb{H}(Y)$$

*Interprétation :* Observer $Y$ apporte autant d'information sur $X$ que $Y$ en contient elle-même, ce qui signifie que $Y$ est une **statistique suffisante** pour la partie « l'information que l'on peut extraire de $X$ via $Y$ » — autrement dit, $Y$ « résume » complètement sa propre incertitude sans perte de ce côté-là.

---

# Critères_Notation_Théorie_de_l'Information

## Barème recommandé

| Exercice | Points | Thèmes clés |
|----------|--------|-------------|
| Ex. 1    | 5 pts  | Marginales, entropies, chaîne |
| Ex. 2    | 3 pts  | Paradoxe météo, $\mathbb{I}=0$ |
| Ex. 3    | 5 pts  | Huffman binaire + ternaire |
| Ex. 4    | 7 pts  | Géométrique, chaîne, séries |
| **Total**| **20 pts** | |

### Détail Exercice 1 (5 pts)
- 1.a : 1 pt (marginales correctes)
- 1.b : 1,5 pt (3 entropies, 0,5 pt chacune)
- 1.c : 1 pt (chaîne vérifiée)
- 1.d : 1,5 pt (calcul + conclusion sur dépendance)

### Détail Exercice 2 (3 pts)
- 2.a : 0,5 pt
- 2.b : 1 pt (identification variable constante, raisonnement)
- 2.c : 1,5 pt (argumentation informationnelle complète)

### Détail Exercice 3 (5 pts)
- 3.a : 1 pt
- 3.b : 2 pts (arbre + tableau)
- 3.c : 1 pt (longueur + encadrement)
- 3.d : 1 pt (condition validité + arbre ternaire)

### Détail Exercice 4 (7 pts)
- 4.a : 1 pt
- 4.b : 1,5 pt (perte de mémoire justifiée)
- 4.c : 2 pts (entropie conditionnelle + résolution)
- 4.d : 2 pts (séries identifiées + vérification)
- 4.e (bonus) : 1 pt

---

## Ce qui distingue une copie moyenne d'une excellente copie

**Copie moyenne :**
- Calcule mécaniquement les entropies sans erreur de base
- Construit un arbre de Huffman correct mais sans mentionner l'optimalité ni la condition ternaire de validité
- En Ex. 2, conclut « le modèle est mauvais » sans mobiliser formellement $\mathbb{I}(W;\hat{W}) = 0$
- En Ex. 4, applique la règle de la chaîne sans justifier $\mathbb{H}(X\mid Y=0) = \mathbb{H}(X)$ via la perte de mémoire

**Copie excellente :**
- Signale en 3.c que $\mathcal{L}(\varphi) = \mathbb{H}(\mathcal{A})$ exactement et relie ce cas à la structure en puissances de 2 des probabilités
- En Ex. 2, démontre formellement $\mathbb{I}(W;\hat{W}) = 0$ en notant que $\hat{W}$ est une constante de variance nulle
- En 4.b, cite et applique explicitement la [[propriété de perte de mémoire]] (ou sans mémoire) de la [[loi géométrique]]
- En 4.d, identifie nommément les deux séries $\sum r^k$ et $\sum k r^k$ et vérifie l'accord avec 4.c
- En 4.e, donne une interprétation probabiliste rigoureuse (statistique suffisante ou équivalent)
- Soigne la rigueur des notations ($\mathbb{H}(X\mid Y)$ vs $\mathbb{H}(X\mid Y=y)$) en Ex. 4

#théorie-de-linformation #entropie #codage-source #codage-canal #huffman #révision #annale
