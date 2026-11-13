# Questions que j'ai pu poser à l'IA
*IA utilisée : Claude*

## **<u>Prompt :</u>** *est ce que le petit 2 du travail demandé est bien le 3.1.2.2.1 ?*

**<u>Réponse IA</u>** : *Oui, mais ce n'est qu'une petite partie. **3.1.2.2.1** est bien la bonne section pour la **fréquence porteuse** de la réponse Mode S. Comme tu l'as trouvée, j'en déduis que tu as compris que le squitter est une **réponse downlink** : c'est juste.*

*Par contre, 3.1.2.2.1 ne couvre qu'un seul paramètre. Le point 2 du travail demande de repérer **toutes** les exigences de couche physique et de les classer en trois catégories. Pour avancer :*

***a) Contraintes sur l'émetteur.** Tu es dans la bonne section, mais ne t'arrête pas à .1. Regarde tout le bloc **3.1.2.2** jusqu'au début de 3.1.2.3. Liste chaque sous-section avec le paramètre qu'elle fixe. Il y en a plusieurs : fréquence, spectre, modulation, impulsions, intervalles, amplitudes… Une sous-section renvoie aussi à un **tableau** et une autre à une **figure**. Note leurs numéros, tu en auras besoin pour la fiche.*

***b) Contraintes de format.** Elles ne sont pas dans 3.1.2.2. Cherche la section qui suit directement. Elle définit comment les bits sont codés et numérotés, quels champs contient une trame, et comment la parité est calculée. Pour le DF17 en particulier, une autre sous-section plus loin dans 3.1.2 parle du format de l'extended squitter. À toi de la trouver.*

***c) Éléments laissés au récepteur.** C'est la catégorie la plus délicate. Tu verras une section 3.1.2.10 qui parle de « receiver » et de sensibilité. Avant de la ranger ici, demande-toi **de quel récepteur elle parle** et sur quelle fréquence il reçoit. Est-ce le récepteur de ta station sol ADS-B ?*

*Envoie-moi ta liste pour (a), sous la forme numéro de section → paramètre. Je te dirai ce qui manque ou ce qui est mal rangé.*

## **<u>Prompt :</u>** *ca veut dire que un bit est échangé toute les 56 microsecondes à 112 microsecondes ,*

<u>Réponse IA :</u>  *Non. Les nombres 56 et 112 ne sont pas des durées. Décompose la phrase mot à mot :*

> *« Either **56 or 112** | **one-microsecond** | **bit intervals** shall be assigned to each **transmission**. »*

- *bit intervals : des intervalles de bit, c'est-à-dire des cases de temps, une par bit ;*
- *one-microsecond : la durée de **chaque** case ;*
- *56 or 112 : le **nombre** de cases ;*
- *each transmission : une transmission, c'est une trame entière.*

*Autrement dit, une trame contient 56 ou 112 bits, et chaque bit occupe une case d'une microseconde.*

*Un ruban découpé en cases est une bonne image : chaque case fait 1 µs et contient un bit, et le ruban compte 56 ou 112 cases. La phrase 3.1.2.3.1.2 te dit d'ailleurs la même chose (« 56 or 112 data bits »). Pour savoir laquelle des deux longueurs correspond au DF17, regarde le cahier des charges du sujet (section 5).*

*Avec ça, réponds :*

1. *$T_b$ = ? (avec l'unité)*
2. *$D_b = 1/T_b$ = ? Est-ce cohérent avec 3.1.2.2.4 ?*
3. *Combien de temps dure le **bloc de données** d'une trame DF17 ? Pour l'instant, sans compter le préambule.*

## **<u>Prompt :</u>** donc Db = 10⁶bits/s

<u>Réponse IA :</u> *Oui, $D_b = 10^6$ bit/s, soit **1 Mbit/s**. C'est bien cohérent avec **3.1.2.2.4**, qui écrit « 1 megabit per second data rate ». Tu as maintenant deux sections qui se recoupent : note les deux références dans ta fiche.*

*Encore deux questions et on peut écrire les formes d'onde :*

1. *Durée du bloc de données d'une trame DF17 (112 bits) = ?*
2. *Dans 3.1.2.2.5.1.2, troisième phrase : quelle est la durée d'une impulsion ? Exprime-la en fraction de $T_b$, par exemple « $T_b/\ldots$ ».*