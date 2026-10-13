# Exercices_Théorie-de-l'Information

## Niveau 1 — Vérification de compréhension

### Exercice 1.1 — Qu'est-ce que l'entropie ?

*Temps estimé : 5 minutes*

Répondre sans calcul aux questions suivantes :

1. Une variable aléatoire $X$ prend la valeur $1$ avec probabilité $1$. Quelle est son [[entropie]] ? Justifier intuitivement.
2. Parmi une loi de Bernoulli $p = 0.01$ et une loi de Bernoulli $p = 0.5$, laquelle a la plus grande entropie ? Pourquoi ?
3. L'[[entropie différentielle]] d'une variable continue peut-elle être négative ? Donner un exemple.

> [!WARNING] Piège fréquent
> L'entropie discrète est toujours **positive ou nulle**. En revanche, l'[[entropie différentielle]] peut être négative — par exemple pour une loi uniforme sur $[0, 0.1]$.

> [!NOTE] À retenir
> L'entropie mesure l'**incertitude moyenne**. Certitude totale $\Rightarrow$ entropie nulle. Incertitude maximale $\Rightarrow$ entropie maximale (atteinte par la loi uniforme dans le cas discret fini).

**Correction**

1. $\mathbb{H}(X) = -1 \cdot \log(1) = 0$. Il n'y a aucune incertitude : on sait toujours ce que $X$ vaut.
2. $p = 0.5$ donne l'entropie maximale pour une Bernoulli. Plus $p$ est proche de $0$ ou $1$, plus le résultat est prévisible, donc moins il y a d'information.
3. Oui. Pour $X \sim \mathcal{U}([0, a])$ avec $a < 1$, on obtient $\mathbb{H}(X) = \log(a) < 0$.

---

### Exercice 1.2 — Code préfixe ou pas ?

*Temps estimé : 5 minutes*

Les codes suivants sont-ils des [[codes préfixes]] ? Justifier.

| Code | Mots de code |
|------|-------------|
| A | $\{0,\ 10,\ 11\}$ |
| B | $\{0,\ 01,\ 10\}$ |
| C | $\{0,\ 1,\ 00\}$ |

> [!TIP] Méthode
> Un code est préfixe si **aucun mot de code n'est le début (préfixe) d'un autre**. Vérifier toutes les paires.

**Correction**

- **A** : Préfixe ✓. `0` n'est préfixe ni de `10` ni de `11`. `10` et `11` ne se préfixent pas mutuellement.
- **B** : Pas préfixe ✗. `0` est préfixe de `01`.
- **C** : Pas préfixe ✗. `0` est préfixe de `00`, et `1` est préfixe de `10` (si on avait `10`) — ici `0` préfixe `00` suffit.

---

### Exercice 1.3 — Divergence de Kullback-Leibler

*Temps estimé : 5 minutes*

Répondre sans calcul :

1. Est-il possible que $D(p \| q) < 0$ ? Et $D(p \| q) = D(q \| p)$ ?
2. Si $p = q$, que vaut $D(p \| q)$ ?
3. La [[divergence de Kullback-Leibler]] est-elle une distance au sens mathématique ? Pourquoi ?

> [!NOTE] À retenir
> $D(p \| q) \geq 0$ toujours ([[inégalité de Gibbs]]), avec égalité ssi $p = q$. Elle n'est **pas symétrique** : $D(p \| q) \neq D(q \| p)$ en général, donc ce n'est pas une distance.

**Correction**

1. Non, $D(p \| q) \geq 0$ par l'[[inégalité de Gibbs]]. Elle n'est pas symétrique en général.
2. $D(p \| p) = 0$.
3. Non : elle n'est pas symétrique et ne vérifie pas l'inégalité triangulaire. C'est une **divergence**, pas une distance.

---

### Exercice 1.4 — Information mutuelle et indépendance

*Temps estimé : 5 minutes*

1. Si $X$ et $Y$ sont indépendantes, que vaut $\mathbb{I}(X; Y)$ ? Justifier à partir de la formule $\mathbb{I}(X;Y) = \mathbb{H}(X) - \mathbb{H}(X|Y)$.
2. Peut-on avoir $\mathbb{I}(X;Y) > \mathbb{H}(X)$ ?
3. Que signifie $\mathbb{I}(X;Y) = \mathbb{H}(X)$ intuitivement ?

> [!NOTE] À retenir
> L'[[information mutuelle]] vérifie $0 \leq \mathbb{I}(X;Y) \leq \min(\mathbb{H}(X), \mathbb{H}(Y))$.

**Correction**

1. Si $X \perp Y$, connaître $Y$ n'apporte rien sur $X$, donc $\mathbb{H}(X|Y) = \mathbb{H}(X)$, et $\mathbb{I}(X;Y) = 0$.
2. Non. Connaître $Y$ ne peut pas réduire l'incertitude sur $X$ au-delà de sa valeur initiale.
3. Connaître $Y$ détermine complètement $X$ : l'incertitude résiduelle $\mathbb{H}(X|Y) = 0$.

---

## Niveau 2 — Application directe

### Exercice 2.1 — Calcul d'entropie d'une loi discrète

*Temps estimé : 10 minutes*

Soit $X$ une variable aléatoire prenant les valeurs $\{1, 2, 3, 4\}$ avec les probabilités :

$$p_1 = \tfrac{1}{2},\quad p_2 = \tfrac{1}{4},\quad p_3 = \tfrac{1}{8},\quad p_4 = \tfrac{1}{8}$$

1. Calculer $\mathbb{H}(X)$ en bits.
2. Comparer avec $\mathbb{H}_{\max} = \log_2(4) = 2$ bits. Commenter.

> [!TIP] Méthode
> Utiliser $\mathbb{H}(X) = -\sum_x p(x) \log_2 p(x)$. Les puissances de $2$ simplifient les calculs : $\log_2(2^{-k}) = -k$.

**Correction**

$$\mathbb{H}(X) = -\frac{1}{2}\log_2\frac{1}{2} - \frac{1}{4}\log_2\frac{1}{4} - \frac{1}{8}\log_2\frac{1}{8} - \frac{1}{8}\log_2\frac{1}{8}$$
$$= \frac{1}{2} + \frac{2}{4} + \frac{3}{8} + \frac{3}{8} = \frac{4+4+3+3}{8} = \frac{14}{8} = 1.75 \text{ bits}$$

La loi n'est pas uniforme, donc $\mathbb{H}(X) = 1.75 < 2$ bits. L'entropie est strictement inférieure au maximum, ce qui reflète la redondance de la distribution.

---

### Exercice 2.2 — Construction d'un code de Huffman

*Temps estimé : 15 minutes*

On reprend les probabilités de l'exercice 2.1 : $p_1 = 1/2$, $p_2 = 1/4$, $p_3 = 1/8$, $p_4 = 1/8$.

1. Construire le [[code de Huffman]] binaire pour cette source.
2. Calculer la longueur moyenne $\mathcal{L}(\varphi)$.
3. Vérifier que $\mathcal{L}(\varphi) \geq \mathbb{H}(X) / \log_2(2) = 1.75$ bits.

> [!TIP] Méthode
> Algorithme de Huffman : trier par probabilité croissante, fusionner les deux plus petites, répéter. Étiqueter les branches `0` et `1`.

**Correction**

**Étapes :**
- Tri initial : $p_3 = 1/8$, $p_4 = 1/8$, $p_2 = 1/4$, $p_1 = 1/2$
- Fusion 1 : $\{3,4\} \to 1/4$. File : $1/4$, $1/4$, $1/2$
- Fusion 2 : $\{2, \{3,4\}\} \to 1/2$. File : $1/2$, $1/2$
- Fusion 3 : racine $= 1$

**Codes obtenus (un choix possible) :**

| Symbole | Probabilité | Code | Longueur |
|---------|-------------|------|----------|
| 1 | 1/2 | `0` | 1 |
| 2 | 1/4 | `10` | 2 |
| 3 | 1/8 | `110` | 3 |
| 4 | 1/8 | `111` | 3 |

**Longueur moyenne :**
$$\mathcal{L} = \frac{1}{2}(1) + \frac{1}{4}(2) + \frac{1}{8}(3) + \frac{1}{8}(3) = 0.5 + 0.5 + 0.375 + 0.375 = 1.75 \text{ bits}$$

Le code est optimal : $\mathcal{L} = \mathbb{H}(X)$. Cela arrive quand toutes les probabilités sont des puissances de $1/2$.

---

### Exercice 2.3 — Entropie jointe et conditionnelle

*Temps estimé : 15 minutes*

Soit la loi jointe de $(X, Y)$ :

$$\begin{array}{c|cc}
p(x,y) & Y=0 & Y=1 \\\hline
X=0 & 1/4 & 1/4 \\
X=1 & 1/4 & 1/4
\end{array}$$

1. Calculer $\mathbb{H}(X)$, $\mathbb{H}(Y)$, $\mathbb{H}(X,Y)$.
2. Calculer $\mathbb{H}(X|Y)$.
3. Calculer $\mathbb{I}(X;Y)$. Interpréter.

> [!TIP] Méthode
> Utiliser la règle de la chaîne : $\mathbb{H}(X,Y) = \mathbb{H}(Y) + \mathbb{H}(X|Y)$.
> Et : $\mathbb{I}(X;Y) = \mathbb{H}(X) - \mathbb{H}(X|Y)$.

**Correction**

Les marginales : $p_X(0) = p_X(1) = 1/2$, $p_Y(0) = p_Y(1) = 1/2$.

$$\mathbb{H}(X) = \mathbb{H}(Y) = 1 \text{ bit}$$

$$\mathbb{H}(X,Y) = -4 \times \frac{1}{4}\log_2\frac{1}{4} = 2 \text{ bits}$$

$$\mathbb{H}(X|Y) = \mathbb{H}(X,Y) - \mathbb{H}(Y) = 2 - 1 = 1 \text{ bit}$$

$$\mathbb{I}(X;Y) = \mathbb{H}(X) - \mathbb{H}(X|Y) = 1 - 1 = 0$$

$X$ et $Y$ sont **indépendants** : connaître $Y$ n'apporte aucune information sur $X$.

---

### Exercice 2.4 — Calcul de divergence KL

*Temps estimé : 10 minutes*

Soient deux lois de Bernoulli $p = \text{Ber}(1/3)$ et $q = \text{Ber}(1/2)$.

Calculer $D(p \| q)$ et $D(q \| p)$. Vérifier que les deux valeurs diffèrent.

> [!WARNING] Piège fréquent
> $D(p \| q) \neq D(q \| p)$ en général. Ne pas confondre avec une distance symétrique.

**Correction**

$$D(p \| q) = \frac{1}{3}\log_2\frac{1/3}{1/2} + \frac{2}{3}\log_2\frac{2/3}{1/2}$$
$$= \frac{1}{3}\log_2\frac{2}{3} + \frac{2}{3}\log_2\frac{4}{3}$$
$$= \frac{1}{3}(-0.585) + \frac{2}{3}(0.415) \approx -0.195 + 0.277 \approx 0.082 \text{ bits}$$

$$D(q \| p) = \frac{1}{2}\log_2\frac{1/2}{1/3} + \frac{1}{2}\log_2\frac{1/2}{2/3}$$
$$= \frac{1}{2}\log_2\frac{3}{2} + \frac{1}{2}\log_2\frac{3}{4}$$
$$= \frac{1}{2}(0.585) + \frac{1}{2}(-0.415) \approx 0.292 - 0.207 \approx 0.085 \text{ bits}$$

Les deux valeurs sont proches mais distinctes, confirmant l'asymétrie de la [[divergence de Kullback-Leibler]].

---

## Niveau 3 — Exercices type examen

### Exercice 3.1 — Le paradoxe du météorologue *(inspiré Annale 2021)*

*Temps estimé : 20 minutes*

Un prévisionniste prédit chaque jour « pluie » ou « soleil ». Soit $X$ la météo réelle et $Y$ la prévision.

On observe la loi jointe suivante :

$$\begin{array}{c|cc}
p(x,y) & Y=\text{pluie} & Y=\text{soleil} \\\hline
X=\text{pluie} & 0.09 & 0.01 \\
X=\text{soleil} & 0.01 & 0.89
\end{array}$$

1. Calculer la probabilité que le prévisionniste ait raison.
2. Calculer $\mathbb{H}(X)$, $\mathbb{H}(Y)$, puis $\mathbb{I}(X;Y)$.
3. Un nouveau prévisionniste prédit toujours « soleil » (probabilité 1). Sa précision est-elle bonne ? Quelle est son information mutuelle avec $X$ ?
4. Conclure : pourquoi la précision brute est-elle une mauvaise mesure de la qualité d'une prévision ?

> [!WARNING] Piège fréquent
> Un prévisionniste qui dit toujours « soleil » dans un pays ensoleillé peut avoir 90% de bonnes réponses tout en transmettant **zéro information**. Précision $\neq$ information.

> [!NOTE] À retenir
> L'[[information mutuelle]] capture ce que la prévision apporte **au-delà de ce que l'on savait déjà** via la loi marginale de $X$.

**Barème suggéré :** Q1 : 2 pts — Q2 : 5 pts — Q3 : 3 pts — Q4 : 2 pts

**Correction**

**Q1.** $P(\text{correct}) = 0.09 + 0.89 = 0.98$. Le prévisionniste a raison 98% du temps.

**Q2.** Marginales : $p_X(\text{pluie}) = 0.10$, $p_X(\text{soleil}) = 0.90$.

$$\mathbb{H}(X) = -0.1\log_2(0.1) - 0.9\log_2(0.9) \approx 0.332 + 0.152 = 0.469 \text{ bits}$$

De même $p_Y(\text{pluie}) = 0.10$, $p_Y(\text{soleil}) = 0.90$, donc $\mathbb{H}(Y) \approx 0.469$ bits.

$$\mathbb{H}(X,Y) = -0.09\log_2(0.09) - 0.01\log_2(0.01) - 0.01\log_2(0.01) - 0.89\log_2(0.89)$$
$$\approx 0.313 + 0.066 + 0.066 + 0.152 = 0.597 \text{ bits}$$

$$\mathbb{I}(X;Y) = \mathbb{H}(X) + \mathbb{H}(Y) - \mathbb{H}(X,Y) \approx 0.469 + 0.469 - 0.597 = 0.341 \text{ bits}$$

**Q3.** Si $Y = \text{soleil}$ toujours : $P(\text{correct}) = 0.90$, soit 90% — encore élevé. Mais $Y$ est constante, donc $\mathbb{H}(Y) = 0$ et $\mathbb{I}(X;Y) = 0$.

**Q4.** La précision brute est biaisée par la fréquence de base (ici 90% de jours ensoleillés). L'[[information mutuelle]] mesure objectivement l'apport informationnel réel, indépendamment de ce biais.

---

### Exercice 3.2 — Huffman ternaire avec symbole fictif *(inspiré Annale 2021)*

*Temps estimé : 25 minutes*

Une source produit 6 symboles avec les probabilités :

$$p_1=0.30,\quad p_2=0.25,\quad p_3=0.20,\quad p_4=0.12,\quad p_5=0.08,\quad p_6=0.05$$

1. Calculer $\mathbb{H}(X)$ en bits.
2. Rappeler la condition sur le nombre de feuilles pour un [[code de Huffman]] ternaire. Faut-il ajouter un symbole fictif ici ?
3. Construire le code de Huffman ternaire.
4. Calculer la longueur moyenne et comparer à $\mathbb{H}(X) / \log_2(3)$.

> [!TIP] Méthode
> Pour un code $d$-aire, à chaque étape on fusionne $d$ symboles. Le nombre de feuilles $n$ doit vérifier $n \equiv 1 \pmod{d-1}$. Si ce n'est pas le cas, ajouter des symboles fictifs de probabilité 0.

> [!WARNING] Piège fréquent
> Pour Huffman **ternaire**, on regroupe par **3** à chaque étape, pas par 2. Oublier ce point conduit à un arbre invalide.

**Barème suggéré :** Q1 : 2 pts — Q2 : 3 pts — Q3 : 5 pts — Q4 : 2 pts

**Correction**

**Q1.**
$$\mathbb{H}(X) = -(0.30\log_2 0.30 + 0.25\log_2 0.25 + 0.20\log_2 0.20 + 0.12\log_2 0.12 + 0.08\log_2 0.08 + 0.05\log_2 0.05)$$
$$\approx 0.521 + 0.500 + 0.464 + 0.369 + 0.292 + 0.216 = 2.362 \text{ bits}$$

**Q2.** Pour $d=3$ : condition $n \equiv 1 \pmod{2}$, soit $n$ impair. Ici $n = 6$ est pair. Il faut ajouter **un symbole fictif** $p_7 = 0$ pour avoir $n = 7$ (impair).

**Q3.** Tri initial (croissant) : $0, 0.05, 0.08, 0.12, 0.20, 0.25, 0.30$

- Fusion 1 : regrouper $\{p_7, p_6, p_5\} = 0 + 0.05 + 0.08 = 0.13$
- Nouvelle file : $0.12, 0.13, 0.20, 0.25, 0.30$
- Fusion 2 : regrouper $\{p_4, S_1\} $... 

On regroupe les 3 plus petits : $\{0.12, 0.13, 0.20\} = 0.45$
- Nouvelle file : $0.25, 0.30, 0.45$
- Fusion 3 (racine) : $\{0.25, 0.30, 0.45\} = 1.00$

**Longueurs résultantes :**

| Symbole | $p_i$ | Longueur |
|---------|--------|----------|
| $p_1 = 0.30$ | nœud racine branche | 1 |
| $p_2 = 0.25$ | nœud racine branche | 1 |
| $p_3 = 0.20$ | profondeur 2 | 2 |
| $p_4 = 0.12$ | profondeur 2 | 2 |
| $p_5 = 0.08$ | profondeur 3 | 3 |
| $p_6 = 0.05$ | profondeur 3 | 3 |
| $p_7 = 0$ | profondeur 3 | (non utilisé) |

**Q4.**
$$\mathcal{L} = 0.30(1)+0.25(1)+0.20(2)+0.12(2)+0.08(3)+0.05(3) = 0.55 + 0.64 + 0.39 = 1.58 \text{ trits}$$

Borne de Shannon : $\mathbb{H}(X)/\log_2(3) = 2.362/1.585 \approx 1.490$ trits. On a bien $\mathcal{L} \geq 1.490$. ✓

---

### Exercice 3.3 — Canal gaussien et capacité *(inspiré TD3 & Annale 2022)*

*Temps estimé : 25 minutes*

On considère un [[canal gaussien]] $Y = X + Z$ où $Z \sim \mathcal{N}(0, \sigma^2)$ est indépendant de $X$, et $X$ est soumis à la contrainte de puissance $\mathbb{E}[X^2] \leq \gamma^2$.

1. Rappeler la formule de la [[capacité du canal gaussien]]. Quel type de loi $p_X$ atteint ce maximum ?
2. Calculer $C$ pour $\gamma^2 = 1$ et $\sigma^2 = 1$. Donner le résultat en bits.
3. Si on double la puissance d'émission ($\gamma^2 = 2$, $\sigma^2 = 1$), de combien augmente $C$ ?
4. Si on double le bruit ($\gamma^2 = 1$, $\sigma^2 = 2$), comment évolue $C$ ? Comparer les effets des questions 3 et 4.
5. Quel énoncé le [[2ème théorème de Shannon]] donne-t-il sur la transmissibilité fiable de l'information à travers ce canal ?

> [!NOTE] À retenir
> La loi gaussienne maximise l'[[entropie différentielle]] à variance fixée. C'est pourquoi la capacité du canal gaussien est atteinte par une entrée gaussienne.

> [!WARNING] Piège fréquent
> Le $\log$ dans la formule de capacité est en base 2 pour des bits, en base $e$ pour des nats. Préciser toujours la base.

**Barème suggéré :** Q1 : 2 pts — Q2 : 2 pts — Q3 : 3 pts — Q4 : 3 pts — Q5 : 2 pts

**Correction**

**Q1.**
$$C = \frac{1}{2}\log_2\!\left(1 + \frac{\gamma^2}{\sigma^2}\right)$$

Le maximum est atteint pour $X \sim \mathcal{N}(0, \gamma^2)$ (entrée gaussienne), car la loi gaussienne maximise l'entropie à variance fixée.

**Q2.** $\gamma^2 = \sigma^2 = 1$ :
$$C = \frac{1}{2}\log_2(1+1) = \frac{1}{2}\log_2(2) = \frac{1}{2} \text{ bit/utilisation}$$

**Q3.** $\gamma^2 = 2$, $\sigma^2 = 1$ :
$$C = \frac{1}{2}\log_2(3) \approx \frac{1}{2}(1.585) \approx 0.792 \text{ bits}$$

Augmentation : $0.792 - 0.5 = +0.292$ bits. Doubler la puissance n'est que **sous-linéaire** en gain de capacité (le log freine la croissance).

**Q4.** $\gamma^2 = 1$, $\sigma^2 = 2$ :
$$C = \frac{1}{2}\log_2\!\left(1 + \frac{1}{2}\right) = \frac{1}{2}\log_2(1.5) \approx \frac{1}{2}(0.585) \approx 0.292 \text{ bits}$$

Doubler le bruit est **plus pénalisant** que doubler la puissance ne l'est bénéfique. La capacité tombe à 0.292 bits contre 0.792 bits dans le cas favorable.

**Q5.** Par le [[2ème théorème de Shannon]] : pour tout taux $R < C$, il existe une suite de codes dont la probabilité d'erreur tend vers 0 quand la longueur du bloc tend vers l'infini. Ici, toute communication à moins de $1/2$ bit par utilisation peut être rendue arbitrairement fiable.

---

#théorie-de-l-information #entropie #codage-source #codage-canal #révision
