---
tags: [partiel, TNS, vrai-faux, QCM, cours]
---

# QCM Vrai/Faux « collé au cours » · 100 questions

> [!info] Différence avec les fichiers 04 à 06
> Ici, chaque affirmation reprend (ou déforme exprès) une **phrase des polys** de Grivel : définitions, remarques, exemples, ordres de grandeur. C'est le style le plus probable d'un V/F sur le cours. La référence (§) indique où relire en cas d'erreur.
> Les questions déjà posées dans 04-06 ne sont pas répétées.

> [!tip] Mode d'emploi
> 1. Coche V/F sur papier **sans ouvrir** (≈ 30 s par question, 50 min en tout).
> 2. Corrige, puis note ton score par bloc dans le tableau.
> 3. Toute erreur va dans le carnet d'erreurs de [[00_Strategie_Planning]], avec la phrase exacte du cours.

| Bloc | Questions | Score | 2e passage |
|---|---|---|---|
| A. Processus : définitions | 1-15 | /15 | /15 |
| B. Corrélation, stationnarité, ergodicité | 16-32 | /17 | /17 |
| C. Gaussien, BBGC, Karhunen-Loève | 33-42 | /10 | /10 |
| D. Estimation | 43-52 | /10 | /10 |
| E. Markov & graphes | 53-66 | /14 | /14 |
| F. Signaux continus | 67-74 | /8 | /8 |
| G. Filtres analogiques (ch. 1) | 75-86 | /12 | /12 |
| H. RIF / RII / synthèse (ch. 2-3) | 87-96 | /10 | /10 |
| I. Analyse spectrale & filtre adapté | 97-100 | /4 | /4 |
| **Total** | | **/100** | **/100** |

---

## A. Processus aléatoires : définitions (poly 1A, partie 1 et §2.2-2.4)

**1.** Pour $t$ fixé, $X(\omega,t)$ est une variable aléatoire, caractérisée notamment par sa densité, sa fonction de répartition, sa moyenne et sa variance.
> [!check]- Réponse
> **VRAI** (partie 1).

**2.** En mathématiques, la fonction $X(t)$ obtenue pour une réalisation $\omega$ fixée s'appelle la « trajectoire » du processus.
> [!check]- Réponse
> **VRAI** (partie 1). On dit aussi réalisation, échantillon ou observation.

**3.** Si $X(t)$ prend ses valeurs dans le plan euclidien, on parle de signal aléatoire.
> [!check]- Réponse
> **FAUX**. On parle d'**image aléatoire** ou de **champ stochastique**. « Signal aléatoire » (processus stochastique) désigne le cas où $X(t)$ est un signal.

**4.** Le temps moyen d'attente au RU selon les jours du mois est un processus à temps discret et à espace d'état continu.
> [!check]- Réponse
> **VRAI** (fig. 1).

**5.** L'évolution du débit d'un fleuve au cours du temps est un processus à temps continu et à espace d'état discret.
> [!check]- Réponse
> **FAUX**. Temps continu **et états continus**. L'exemple à états discrets en temps continu est le nombre de clients dans un magasin.

**6.** Le nombre d'appels téléphoniques chaque jour de l'année est un processus à temps discret et à états discrets.
> [!check]- Réponse
> **VRAI**.

**7.** Une image binaire numérisée peut être vue comme une réalisation d'un champ stochastique discret 2D.
> [!check]- Réponse
> **VRAI** (fig. 3).

**8.** Les processus aléatoires servent aussi à la théorie des files d'attente (temps de transfert de paquets dans les réseaux).
> [!check]- Réponse
> **VRAI** (partie 1).

**9.** La fonction de répartition $F(x)$ peut être décroissante sur certains intervalles.
> [!check]- Réponse
> **FAUX**. Elle est **croissante** sur $]-\infty;+\infty[$, à valeurs dans $[0;1]$ (§2.2).

**10.** La variance est le moment central d'ordre 2.
> [!check]- Réponse
> **VRAI** (§2.2).

**11.** Le skewness mesure le degré d'écrasement (aplatissement) de la distribution, et le kurtosis son asymétrie.
> [!check]- Réponse
> **FAUX**. C'est l'inverse : skewness = **asymétrie**, kurtosis = **écrasement** (§2.2).

**12.** En général, la densité d'ordre 1 $p(x;t)$ d'un processus est la même à chaque instant $t$.
> [!check]- Réponse
> **FAUX**. « De manière générale, $p(x;t)$ est différente pour chaque valeur de $t$ » (§2.3). Les exemples de Bernoulli sont un cas particulier.

**13.** Le processus de comptage $c_n$ compte le nombre de valeurs positives d'un processus de Bernoulli jusqu'à l'instant $n$.
> [!check]- Réponse
> **VRAI** (§2.3.1).

**14.** « Processus de Wiener » est un autre nom du mouvement brownien.
> [!check]- Réponse
> **VRAI** (§2.3.2).

**15.** La moyenne d'un processus contient de l'information statistique du second ordre sur le lien entre les échantillons pris à des instants différents.
> [!check]- Réponse
> **FAUX**. Elle n'en contient **pas** : c'est pour cela qu'on introduit les fonctions d'autocorrélation et d'autocovariance (§2.4).

## B. Corrélation, stationnarité, ergodicité (§2.5-2.6)

**16.** L'espace des variables aléatoires de carré intégrable, muni du produit scalaire $E(XY^*)$, est un espace de Hilbert.
> [!check]- Réponse
> **VRAI** (§2.5).

**17.** L'inégalité de Schwarz s'écrit $|E(XY^*)|^2\le E(|X|^2)E(|Y|^2)$, l'égalité ayant lieu quand $X$ et $Y$ sont indépendantes.
> [!check]- Réponse
> **FAUX**. L'égalité a lieu quand $X=aY$ (colinéarité), pas quand elles sont indépendantes (§2.5). C'est cette inégalité qui donne $|R(\tau)|\le R(0)$.

**18.** Un processus d'ordre 2 a une espérance et une variance finies à chaque instant.
> [!check]- Réponse
> **VRAI** (§2.5) : $E|X(t)|^2<+\infty$.

**19.** Quand $R_{XX}(t_1,t_2)$ est grande et positive, les valeurs du processus en $t_1$ et $t_2$ s'écartent peu.
> [!check]- Réponse
> **VRAI** (§2.5.1). Si $R<0$, $X(t_1)$ et $X(t_2)$ ont tendance à être de signes opposés.

**20.** On parle de caractérisation du second ordre car l'autocorrélation fait intervenir le produit de deux variables aléatoires (homogène à un « carré »).
> [!check]- Réponse
> **VRAI** (§2.5.1).

**21.** Pour $X(t)=\sum_iA_ie^{j2\pi f_it}$ avec des $A_i$ indépendantes, centrées, de variance $\sigma_i^2$, on a $R_{XX}(t_1,t_2)=\sum_i\sigma_i^2e^{j2\pi f_i(t_1+t_2)}$.
> [!check]- Réponse
> **FAUX**. C'est $e^{j2\pi f_i(t_1-t_2)}$ : le processus est SSL (§2.5.1, éq. 2.33).

**22.** L'intercorrélation vérifie $R_{XY}(t_1,t_2)=R^*_{YX}(t_2,t_1)$.
> [!check]- Réponse
> **VRAI** (éq. 2.42).

**23.** Si $C_{XY}(t_1,t_2)=0$ pour tous $t_1,t_2$, les processus $X$ et $Y$ sont dits orthogonaux.
> [!check]- Réponse
> **FAUX**. Ils sont **non corrélés** (décorrélés). Orthogonaux signifie $R_{XY}=0$ (§2.5.3 et §2.5.7).

**24.** Pour un moment d'ordre $k$ d'un processus complexe, le cas $k=2$ redonne la fonction d'autocorrélation.
> [!check]- Réponse
> **VRAI** (§2.5.4) ; $k=1$ redonne la moyenne d'ensemble.

**25.** Le cumulant d'ordre 3 d'un signal à moyenne nulle est égal à son moment d'ordre 3.
> [!check]- Réponse
> **VRAI** (éq. 2.58).

**26.** Le cumulant d'ordre 1 est égal à la variance.
> [!check]- Réponse
> **FAUX**. $\mathrm{Cum}_1$ = **moment d'ordre 1** = moyenne (éq. 2.56).

**27.** Il existe aussi la stationnarité à l'ordre $n$, la stationnarité sur un intervalle de temps et les processus asymptotiquement stationnaires.
> [!check]- Réponse
> **VRAI** (§2.6.1.3).

**28.** Un processus complexe $Z=X+jY$ est stationnaire si $X$ et $Y$ sont chacun stationnaires, même s'ils ne le sont pas conjointement.
> [!check]- Réponse
> **FAUX**. Il faut que $X$ et $Y$ soient **conjointement** stationnaires (§2.6.1.1).

**29.** En règle générale, dire qu'un processus est « stationnaire » signifie qu'il est stationnaire au sens large.
> [!check]- Réponse
> **VRAI** (§2.6.1.2).

**30.** La propriété « semi-définie positive » de la matrice de corrélation se justifie par le fait que la puissance en sortie d'un système linéaire doit être positive.
> [!check]- Réponse
> **VRAI** (§2.6.1.3).

**31.** En traitement du signal, l'ergodicité est le plus souvent démontrée rigoureusement avant d'être utilisée.
> [!check]- Réponse
> **FAUX**. C'est « le plus souvent un **postulat** » (§2.6.2).

**32.** L'ergodicité au sens de la covariance peut s'entendre au sens de la convergence simple ou de la convergence quadratique.
> [!check]- Réponse
> **VRAI** (§2.6.2.2, éq. 2.76-2.77).

## C. Gaussien, BBGC, Karhunen-Loève (§2.7-2.9)

**33.** La séquence de BBGC discrète est l'homologue du bruit blanc continu, qui est un processus idéalisé de variance infinie.
> [!check]- Réponse
> **VRAI** (§2.7).

**34.** Un processus blanc est stationnaire.
> [!check]- Réponse
> **VRAI** (§2.7) : $R_{BB}(k)=\sigma^2\delta(k)$.

**35.** Un processus est gaussien si, pour tout ensemble d'instants, le vecteur correspondant a une densité conjointe gaussienne.
> [!check]- Réponse
> **VRAI** (§2.7).

**36.** Un processus gaussien complexe monodimensionnel a pour densité $\frac{1}{\sqrt{2\pi}\sigma}\exp\left(-\frac{|x-m|^2}{2\sigma^2}\right)$.
> [!check]- Réponse
> **FAUX**. C'est $\frac{1}{\pi\sigma^2}\exp\left(-\frac{|x-m|^2}{\sigma^2}\right)$ (éq. 2.81). La formule donnée est celle du cas réel. Le cas complexe se rencontre en radar, sonar et télécoms.

**37.** Les statistiques d'un processus gaussien sont entièrement déterminées par sa moyenne et sa fonction d'autocovariance.
> [!check]- Réponse
> **VRAI** (§2.7).

**38.** Si les variables d'un vecteur gaussien sont mutuellement non corrélées, la matrice de covariance est diagonale et la densité conjointe se factorise.
> [!check]- Réponse
> **VRAI** (éq. 2.84) : non corrélées et gaussiennes donnent l'indépendance.

**39.** Le filtrage d'un processus gaussien produit un processus gaussien, car toute combinaison linéaire de gaussiennes est gaussienne.
> [!check]- Réponse
> **VRAI** (remarque §2.7).

**40.** La transformée de Karhunen-Loève décompose la séquence dans la base des vecteurs propres de la matrice de **covariance du bruit**.
> [!check]- Réponse
> **FAUX**. C'est la base des vecteurs propres de la **matrice de corrélation** $R_x$ du signal (§2.9.1).

**41.** Dans Karhunen-Loève, on approxime $x$ par $\hat x=\sum_{i=1}^Mk_i\varphi_i$ avec $M<N$, et l'on minimise l'énergie moyenne de l'erreur sous contrainte d'orthonormalité (lagrangien).
> [!check]- Réponse
> **VRAI** (§2.9.1).

**42.** Le cours cite le rehaussement de la parole comme application de Karhunen-Loève.
> [!check]- Réponse
> **VRAI** (§2.9.1).

## D. Estimation (partie 3)

**43.** L'estimation de l'autocorrélation par moyenne temporelle suppose le processus ergodique.
> [!check]- Réponse
> **VRAI** (§3.2.1).

**44.** Le biais de l'estimateur en $1/N$ de l'autocorrélation « constitue une fenêtre triangulaire ».
> [!check]- Réponse
> **VRAI** (§3.2.2).

**45.** Pour $m$ fixé, la variance de l'estimateur de l'autocorrélation tend vers zéro quand le nombre d'échantillons augmente.
> [!check]- Réponse
> **VRAI** (§3.2.2).

**46.** Le maximum de vraisemblance cherche $\theta$ minimisant la densité de probabilité des observations.
> [!check]- Réponse
> **FAUX**. On **maximise** $p_{y,\theta}(y,\theta)$ (§3.3.2).

**47.** L'algorithme EM a été proposé par Dempster ; il maximise itérativement l'espérance de la log-vraisemblance des données complètes.
> [!check]- Réponse
> **VRAI** (§3.3.3). Les observations sont les « données incomplètes » ; le couple observations + données cachées forme les « données complètes ».

**48.** On préfère en général l'algorithme EM à la maximisation directe de la vraisemblance pour limiter la complexité calculatoire.
> [!check]- Réponse
> **VRAI** (§3.3.3).

**49.** La méthode des moindres carrés a été introduite par Gauss en 1809 pour prévoir le mouvement des planètes.
> [!check]- Réponse
> **VRAI** (§3.4).

**50.** Dans le cas d'observations non bruitées, la détermination des paramètres AR est triviale si $H_N^TH_N$ est inversible.
> [!check]- Réponse
> **VRAI** (§3.4.1). Avec du bruit, le problème n'est plus de **déterminer** mais d'**estimer** $\theta$.

**51.** Le critère des moindres carrés minimise la somme des erreurs élémentaires en valeur absolue.
> [!check]- Réponse
> **FAUX**. Il minimise la somme des erreurs **au carré** $\sum\tilde y^2(k-i)$ (§3.4.2).

**52.** L'estimée est une variable aléatoire, caractérisée par son biais et sa variance.
> [!check]- Réponse
> **VRAI** (§3.4.3).

## E. Chaînes de Markov & graphes (partie 4)

**53.** Le processus de Bernoulli est un processus dont les échantillons sont indépendants.
> [!check]- Réponse
> **VRAI** (§4.1). C'est pour modéliser une dépendance qu'on introduit Markov.

**54.** Une chaîne de Markov est un processus de Markov qui prend un ensemble fini de valeurs.
> [!check]- Réponse
> **VRAI** (§4.1).

**55.** L'utilisation de chaînes de Markov d'ordre supérieur à 1 est facile, surtout quand on dispose de peu de données.
> [!check]- Réponse
> **FAUX**. Elle est « généralement difficile, particulièrement lorsque le nombre de données est petit » (§4.1).

**56.** Un chemin élémentaire est un chemin qui ne passe pas deux fois par un même sommet.
> [!check]- Réponse
> **VRAI** (§4.2).

**57.** Une boucle est un circuit de longueur 2.
> [!check]- Réponse
> **FAUX**. C'est un circuit de longueur **1** (§4.2).

**58.** Une arborescence est un graphe orienté qui ne comprend pas de circuit.
> [!check]- Réponse
> **VRAI** (§4.2).

**59.** En élevant la matrice d'adjacence à la puissance $j$, on obtient le nombre de chemins de longueur $j$ entre les sommets.
> [!check]- Réponse
> **VRAI** (§4.2). En version booléenne, on sait seulement s'il existe au moins un chemin.

**60.** Une chaîne est dite homogène si les probabilités de transition ne dépendent que de l'intervalle de temps séparant les deux instants.
> [!check]- Réponse
> **VRAI** (§4.3.1).

**61.** Dire qu'initialement un processus est dans un certain état revient à donner une probabilité 1 à cet état dans $\mathbf P(0)$.
> [!check]- Réponse
> **VRAI** (§4.3.4.2).

**62.** La période d'une chaîne de Markov est le PPCM des longueurs de ses circuits.
> [!check]- Réponse
> **FAUX**. C'est le **PGCD** (§4.3.4.6).

**63.** Un état récurrent dont la durée moyenne de récurrence $\mu_{ii}$ est infinie est dit récurrent nul.
> [!check]- Réponse
> **VRAI** (§4.3.4.6).

**64.** Un état ergodique est un état récurrent non nul et périodique.
> [!check]- Réponse
> **FAUX**. Il est récurrent non nul et **apériodique** (§4.3.4.6).

**65.** Calculer le régime stationnaire en diagonalisant $P$ et en faisant tendre $D^n$ vers l'infini est faux en général.
> [!check]- Réponse
> **FAUX**. Cette approche est **juste** mais « peut rapidement s'avérer fastidieuse » ; on lui préfère $\pi=\pi P$, $\sum\pi_i=1$ (§4.3.5).

**66.** Dans l'exemple du cours, la chaîne converge vers la même distribution $\pi=(5,4,4,6)/19$ quelle que soit la distribution initiale.
> [!check]- Réponse
> **VRAI** (§4.3.5) : quatre distributions initiales différentes mènent au même $\pi$.

## F. Signaux continus (TD/cours 1A)

**67.** Un signal périodique est de carré intégrable sur $]-\infty;+\infty[$.
> [!check]- Réponse
> **FAUX** (remarque §1.1 du TD) : il n'est pas à énergie finie.

**68.** Pour un signal réel, $c_k=\frac12(a_k-jb_k)$ et $c_{-k}=\frac12(a_k+jb_k)$.
> [!check]- Réponse
> **VRAI** (§1.1 du TD).

**69.** La valeur moyenne d'un signal périodique est $\frac1{T}\int_{(T)}v(t)dt$, c'est-à-dire $c_0$.
> [!check]- Réponse
> **VRAI**.

**70.** Pour un signal aléatoire stationnaire **ergodique**, la corrélation statistique est égale à la corrélation temporelle d'une réalisation.
> [!check]- Réponse
> **VRAI** (§1.2 du TD).

**71.** L'intercorrélation est une mesure de similarité entre deux signaux, et elle ne s'applique qu'aux signaux déterministes.
> [!check]- Réponse
> **FAUX**. Elle s'applique aussi aux signaux aléatoires ; seule l'expression diffère (§1.2 du TD).

**72.** Une fonction-test est une fonction $C^\infty$ à support borné.
> [!check]- Réponse
> **VRAI** (partie 3 du TD).

**73.** $f(x)=x^2\sin(1/x)$, prolongée par $f(0)=0$, est de classe $C^1$ sur $\mathbb R$.
> [!check]- Réponse
> **FAUX**. C'est le contre-exemple du cours : elle est dérivable, mais sa dérivée n'est pas continue en 0.

**74.** $f(x)=e^{-1/x}$ pour $x>0$, prolongée par 0, est plate en 0 (toutes ses dérivées y sont nulles).
> [!check]- Réponse
> **VRAI** (§3.1 du TD).

## G. Filtres analogiques (poly 2A, ch. 1)

**75.** La synthèse des filtres numériques tire profit de nombreux résultats établis pour les filtres à temps continu.
> [!check]- Réponse
> **VRAI** (§1.1).

**76.** D'après le théorème de Paley-Wiener, un filtre idéal qui rejette totalement une bande finie de fréquences est réalisable si son ordre est assez grand.
> [!check]- Réponse
> **FAUX**. C'est **impossible** ; on définit donc un **gabarit**, et l'on parle de bande « atténuée » plutôt que « coupée » (§1.2).

**77.** Le module de la fonction de transfert est une fonction paire de $f$, et sa phase une fonction impaire.
> [!check]- Réponse
> **VRAI** (§1.2).

**78.** Pour obtenir un passe-bas, on prend dans $|H(jx)|^2$ le degré du numérateur supérieur à celui du dénominateur.
> [!check]- Réponse
> **FAUX**. C'est $m<n$ : le dénominateur domine, donc $|H|^2\to0$ à l'infini (éq. 1.4).

**79.** Pour les fonctions MFM (maximally flat magnitude), on annule les dérivées successives de $|H(jx)|^2$ à l'origine.
> [!check]- Réponse
> **VRAI** (§1.3.1).

**80.** Les pôles de $H_n(p)H_n(-p)$ (Butterworth) sont sur le cercle unité, et l'on garde ceux du demi-plan **droit** pour la stabilité.
> [!check]- Réponse
> **FAUX**. On garde ceux du demi-plan **gauche** (§1.3.2.2).

**81.** Pour un Tchebychev I, le nombre d'extrema dans la bande passante est égal à l'ordre du filtre.
> [!check]- Réponse
> **VRAI** (§1.4.2.2, fig. 1.8).

**82.** Dans le Tchebychev I, la fréquence est normalisée par la fréquence de coupure à −3 dB.
> [!check]- Réponse
> **FAUX**. Elle est normalisée par $f_p$, la fréquence **limite de la bande passante** (§1.4.2.2).

**83.** $C_n(0)=0$ si $n$ est impair et $\pm1$ si $n$ est pair, et $C_n(1)=1$ pour tout $n$.
> [!check]- Réponse
> **VRAI** (éq. 1.23-1.24).

**84.** Les filtres de Bessel-Thomson ont tous leurs zéros de transmission à l'infini.
> [!check]- Réponse
> **VRAI** (§1.7.3). On obtient leurs coefficients par la méthode de Storch (approximation de $\coth p$).

**85.** Les filtres de Papoulis (optimum) utilisent les polynômes de Legendre et ne présentent pas d'ondulations dans la bande passante.
> [!check]- Réponse
> **VRAI** (§1.8).

**86.** Pour comparer les filtres à ordre égal (§1.9), on fixe la fréquence de coupure et on compare les atténuations.
> [!check]- Réponse
> **FAUX**. On fixe l'**atténuation** dans la bande atténuée (et l'erreur dans la bande de référence) : ce sont les **fréquences de coupure** qui changent. La référence est Butterworth.

## H. RIF, RII, synthèse (poly 2A, ch. 2-3)

**87.** Les RIF sont utilisés en traitement d'images et ont un ordre qui varie en général de 25 à 400.
> [!check]- Réponse
> **VRAI** (§2.1).

**88.** Le filtre $y(k)=\frac12x(k)+\frac12x(k-1)$ (cosinusoïde) conserve la composante continue et élimine $\pm f_e/2$, avec un retard de $T_e$.
> [!check]- Réponse
> **FAUX**. Le retard est de $T_e/2$ (le terme $e^{-j\pi f/f_e}$) ; le reste est vrai (§2.1.1).

**89.** Le filtre RIF $\frac14[\delta(k)+2\delta(k-1)+\delta(k-2)]$ est le filtre cosinusoïde convolué avec lui-même, ce qui le rend plus sélectif.
> [!check]- Réponse
> **VRAI** (§2.1.1, exemple 2 : cosinusoïde surélevée).

**90.** Si $h(n)$ est réelle, $|H(f)|$ est une fonction paire de $f$.
> [!check]- Réponse
> **VRAI** (§2.1.2.1).

**91.** Les RIF permettent un bruit de calcul réduit et calculable, car ils ne présentent pas de boucle.
> [!check]- Réponse
> **VRAI** (§2.1.3).

**92.** Dans l'algorithme de Remez, on ne peut pas éviter l'inversion matricielle.
> [!check]- Réponse
> **FAUX**. Une technique fondée sur la **FFT** permet de l'éviter (remarque §2.3).

**93.** Un filtre RII d'ordre fini, stable et sans perte est forcément un passe-tout de gain unité.
> [!check]- Réponse
> **VRAI** (§3.1.1). Cela vaut pour tout filtre linéaire sans perte, stable et d'ordre fini.

**94.** Pour un passe-tout causal stable, les pôles sont dans le disque unité et les zéros à l'extérieur.
> [!check]- Réponse
> **VRAI** (§3.1.1, fig. 3.1).

**95.** La dérivée de la phase d'un passe-tout par rapport à la fréquence est positive ou nulle.
> [!check]- Réponse
> **FAUX**. Elle est $\le0$ (éq. 3.18), d'où le retard de groupe minimal du filtre à minimum de phase.

**96.** Avec la bilinéaire, pour de faibles valeurs de la pulsation, $\omega_{\text{continu}}\approx\omega_{\text{discret}}$.
> [!check]- Réponse
> **VRAI** (éq. 3.36). La distorsion n'apparaît qu'aux fréquences élevées.

## I. Analyse spectrale & filtre adapté

**97.** Dans le spectrogramme, on décale en général la fenêtre d'analyse avec un recouvrement d'environ 50 %, et la couleur code le niveau d'énergie.
> [!check]- Réponse
> **VRAI** (cours 2A).

**98.** Un chirp est une sinusoïde dont l'amplitude évolue au cours du temps.
> [!check]- Réponse
> **FAUX**. C'est sa **fréquence** qui évolue (radar, sonar).

**99.** Pour établir le filtre adapté, le cas général exige de connaître la fonction d'autocorrélation du bruit, d'où l'étude du cas du bruit blanc.
> [!check]- Réponse
> **VRAI** (§4.1-4.2 du complément).

**100.** Dans le filtre adapté $h_{opt}(t)=\lambda s_1(t_1-t)$, le facteur $\lambda$ améliore le rapport signal à bruit.
> [!check]- Réponse
> **FAUX**. $\lambda$ ne modifie que le **gain** : il agit pareil sur le signal et le bruit, donc le RSB est inchangé (§4.2).
