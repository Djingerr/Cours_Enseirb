# Flashcards_Théorie de l'Information

## Liens vers les autres fiches

- [[Fiche_Théorie de l'Information]]
- [[Exercices_Théorie de l'Information]]
- [[Annale_Théorie de l'Information]]

---

## Cartes Application ★ prioritaires

---

START Basic Comment construire un [[code de Huffman]] binaire pour une source à $n$ symboles ? Back: 1. Trier les probabilités par ordre décroissant. 2. Fusionner itérativement les deux symboles les moins probables (additionner leurs probabilités). 3. Étiqueter les branches 0/1. Répéter jusqu'à la racine. Tags: codage-source application ★ END

---

START Basic Pour un [[code de Huffman]] **ternaire**, quelle condition doit vérifier le nombre de symboles $n$ ? Back: Il faut $(n-1) \equiv 0 \pmod{2}$, i.e. $n$ impair. Si $n$ est pair, ajouter **un symbole fictif** de probabilité 0 avant de démarrer l'algorithme. Tags: codage-source application ★ END

---

START Basic Comment calculer l'[[information mutuelle]] $\mathbb{I}(X;Y)$ à partir des entropies ? Back: $$\mathbb{I}(X;Y) = \mathbb{H}(X) - \mathbb{H}(X|Y) = \mathbb{H}(X) + \mathbb{H}(Y) - \mathbb{H}(X,Y)$$ Tags: mesure-information application ★ END

---

START Basic Comment calculer la [[capacité du canal gaussien]] de bruit $\sigma^2$ et signal de variance $\gamma^2$ ? Back: $$C = \frac{1}{2}\log!\left(1 + \frac{\gamma^2}{\sigma^2}\right)$$ L'unité dépend de la base du log (bits si $\log_2$, nats si $\ln$). Tags: codage-canal application ★ END

---

START Basic Comment calculer la [[divergence de Kullback-Leibler]] $D(p | q)$ pour deux lois discrètes ? Back: $$D(p|q) = \sum_{z} p(z),\log\frac{p(z)}{q(z)}$$ Attention : $D(p|q) \neq D(q|p)$ — ce n'est **pas** une distance symétrique. Tags: mesure-information application ★ END

---

START Basic Comment vérifier qu'un code déchiffrable peut exister avec des longueurs $l_1, \dots, l_n$ sur un alphabet de taille $d$ ? Back: Vérifier l'[[inégalité de Kraft]] : $$\sum_{x} d^{-l_x} \leq 1$$ Si satisfaite, un code préfixe existe ; sinon, aucun code déchiffrable n'est possible. Tags: codage-source application ★ END

---

START Basic Comment borner inférieurement la longueur moyenne $\mathcal{L}(\varphi)$ d'un code déchiffrable sur un alphabet de taille $d$ ? Back: D'après le [[premier théorème de Shannon]] : $$\mathcal{L}(\varphi) \geq \frac{\mathbb{H}(X)}{\log d}$$ L'entropie normalisée est la limite incompressible. Tags: codage-source application ★ END

---

START Basic Quelle loi maximise l'[[entropie différentielle]] à variance fixée $\sigma^2$ ? Back: La [[loi gaussienne]] $\mathcal{N}(0, \sigma^2)$, d'entropie différentielle $\mathbb{H}(X) = \frac{1}{2}\log(2\pi e,\sigma^2)$. Tags: entropie-continue application ★ END

---

START Basic Quelle loi discrète sur un alphabet fini maximise l'[[entropie]] ? Back: La **loi uniforme**. Pour $|\mathcal{X}| = n$ symboles : $\mathbb{H}(X) = \log n$ (maximum). Preuve via l'[[inégalité de Gibbs]] : $D(p|q) \geq 0$. Tags: mesure-information application ★ END

---

START Basic Quand le [[deuxième théorème de Shannon]] garantit-il une communication fiable ? Back: Si le rendement $R < C$ (capacité du canal), il existe une suite de codes dont la probabilité d'erreur tend vers $0$. En dessous de $C$ : fiable. Au-dessus : impossible. Tags: codage-canal application ★ END

---

## Cartes Compréhension

---

START Basic Pourquoi $D(p | q) \geq 0$, avec égalité ssi $p = q$ ? Back: C'est l'[[inégalité de Gibbs]], conséquence de la **concavité du logarithme** (inégalité de Jensen). Elle garantit que la KL est toujours non-négative. Tags: mesure-information compréhension ★ END

---

START Basic Que signifie qu'un code est **[[code préfixe|préfixe]]** (ou instantané) ? Back: Aucun mot de code n'est le préfixe d'un autre. Conséquence : le décodage est immédiat, symbole par symbole, sans lire la suite du message. Tags: codage-source compréhension END

---

START Basic Quelle inégalité relie [[entropie jointe]] et entropies marginales ([[sous-additivité]]) ? Back: $$\mathbb{H}(X,Y) \leq \mathbb{H}(X) + \mathbb{H}(Y)$$ Égalité ssi $X$ et $Y$ sont **indépendantes**. (Annale 2022 : preuve demandée.) Tags: mesure-information compréhension ★ END

---

START Basic Que mesure l'[[information mutuelle]] $\mathbb{I}(X;Y)$ intuitivement ? Back: La réduction d'incertitude sur $X$ apportée par la connaissance de $Y$. Elle vaut 0 si $X \perp Y$, et $\mathbb{H}(X)$ si $Y$ détermine $X$ entièrement. Tags: mesure-information compréhension END

---

START Basic Pourquoi $\mathbb{H}(g(X)) \leq \mathbb{H}(X)$ pour toute fonction déterministe $g$ ? Back: Toute fonction déterministe réduit ou conserve l'information : **Data Processing Inequality**. Égalité ssi $g$ est **bijective** sur le support de $X$. Tags: mesure-information compréhension END

---

START Basic Quelle est la **règle de la chaîne** pour l'[[entropie jointe]] de $n$ variables ? Back: $$\mathbb{H}(X_1, \dots, X_n) = \sum_{i=1}^{n} \mathbb{H}(X_i \mid X_1, \dots, X_{i-1})$$ Tags: mesure-information compréhension END

---

START Basic Que vaut la [[capacité de canal]] $C$ d'un canal discret sans mémoire ? Back: $$C = \sup_{p_X} \mathbb{I}(X;Y)$$ C'est le maximum de l'information mutuelle sur toutes les lois d'entrée possibles. Tags: codage-canal compréhension END

---

START Basic Peut-on avoir une [[entropie différentielle]] négative pour une variable continue ? Back: **Oui.** Exemple : loi uniforme sur $[0, a]$ avec $a < 1$ donne $\mathbb{H}(X) = \log a < 0$. L'entropie différentielle n'est pas une probabilité. Tags: entropie-continue compréhension END

---

START Basic Quelle double inégalité relie $\mathbb{H}(X,Y)$, $\mathbb{H}(X)$ et $\mathbb{H}(Y)$ ? (Annale 2022) Back: $$\mathbb{H}(X,Y) \leq \mathbb{H}(X) + \mathbb{H}(Y) \leq 2,\mathbb{H}(X,Y)$$ Borne gauche : sous-additivité. Borne droite : $\mathbb{H}(X) \leq \mathbb{H}(X,Y)$. Tags: mesure-information compréhension END

---

## Cartes Base (Définitions)

---

START Basic Définir l'[[entropie]] d'une variable aléatoire discrète $X$. Back: $$\mathbb{H}(X) = -\sum_{x} p_X(x),\log p_X(x)$$ Mesure l'**incertitude moyenne** sur $X$. Toujours $\geq 0$ dans le cas discret. Tags: mesure-information base END

---

START Basic Définir la [[quantité d'information]] (ou surprise) d'un événement $A$. Back: $$h(\mathbb{P}(A)) = -\log \mathbb{P}(A)$$ Plus un événement est rare, plus il apporte d'information. Unité : bits ($\log_2$) ou nats ($\ln$). Tags: mesure-information base END

---

START Basic Définir l'[[entropie différentielle]] d'une variable continue de densité $f_X$. Back: $$\mathbb{H}(X) = -\int f_X(x),\log f_X(x),dx$$ Différence clé avec le cas discret : peut être **négative**. Tags: entropie-continue base END

---

START Basic Définir l'[[entropie conditionnelle]] $\mathbb{H}(X|Y)$. Back: $$\mathbb{H}(X|Y) = \sum_{y} p_Y(y),\mathbb{H}(X|Y=y) = \mathbb{H}(X,Y) - \mathbb{H}(Y)$$ Mesure l'incertitude résiduelle sur $X$ quand $Y$ est connue. Tags: mesure-information base END

---

START Basic Énoncer le [[théorème de Kraft]]. Back: Il existe un code déchiffrable sur un alphabet de taille $d$ avec longueurs $l_x$ **ssi** : $$\sum_{x} d^{-l_x} \leq 1$$ Tags: codage-source base END

---

START Basic Définir la [[divergence de Kullback-Leibler]] et citer ses deux propriétés clés. Back: $D(p|q) = \sum_z p(z)\log\frac{p(z)}{q(z)}$. Propriétés : $D(p|q) \geq 0$ avec égalité ssi $p=q$, et **non symétrique** ($D(p|q) \neq D(q|p)$ en général). Tags: mesure-information base END

---

START Basic Qu'est-ce que le rendement $R$ d'un code canal et quand est-il admissible ? Back: $R$ est le nombre de bits d'information par usage du canal. Transmission fiable possible ssi $R < C$ ([[capacité de canal]]). Au-delà, l'erreur est inévitable ([[deuxième théorème de Shannon]]). Tags: codage-canal base END

---

START Basic Quelle est l'[[entropie différentielle]] de la loi exponentielle $\mathcal{E}(\lambda)$ ? Back: $$\mathbb{H}(X) = 1 - \log \lambda$$ (logarithme naturel). Résultat standard du TD 3. Tags: entropie-continue base END

---

> [!WARNING] Piège fréquent L'[[entropie différentielle]] peut être **négative**. Ne jamais affirmer que l'entropie est toujours positive sans préciser qu'on est dans le cas discret.

> [!WARNING] Piège fréquent Pour le [[code de Huffman]] ternaire, vérifier la parité de $n-1$ **avant** de commencer. Oublier le symbole fictif (probabilité 0) est l'erreur la plus courante en examen.

> [!NOTE] À retenir La [[divergence de Kullback-Leibler]] n'est **pas** une distance : elle n'est ni symétrique ni ne vérifie l'inégalité triangulaire.

> [!NOTE] À retenir Loi à entropie maximale : **uniforme** (discret fini) / **gaussienne** (continu, variance fixée). Ces deux résultats tombent souvent en exam (Annales 2019, 2021).

> [!TIP] Méthode Pour toute preuve d'inégalité d'entropie, réfléchir à utiliser l'[[inégalité de Gibbs]] ($D(p|q) \geq 0$) ou la **concavité du log** (Jensen).

> [!TIP] Méthode Calcul rapide de $\mathbb{I}(X;Y)$ : partir de $\mathbb{H}(X) + \mathbb{H}(Y) - \mathbb{H}(X,Y)$ quand les marginales sont plus faciles à calculer que les conditionnelles.

---

#théorie-de-l-information #mesure-information #codage-source #codage-canal #entropie-continue #révision