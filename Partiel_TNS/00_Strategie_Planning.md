---
tags: [partiel, TNS, filtres-numeriques, processus, signaux, strategie]
prof: E. Grivel
date-partiel: J+4 (à partir du 13/11/2026)
---

# Partiel Filtres numériques & Estimation : stratégie de révision

> [!info] Ce qu'on sait du partiel
> - Surtout du **Vrai/Faux sur le cours**.
> - **Beaucoup de 1A** (Processus & signaux aléatoires + Signaux continus, même prof : Grivel) et **un peu de 2A** (filtres numériques).
> - Les anciens sujets de Grivel (dans `1A/Signaux_Processus/Cours_TD_Processus_Signaux.pdf`, p. 69 et suivantes) reviennent **toujours** sur les mêmes points : gaussienne + intervalle à 95,4 %, autocorrélation d'un MA, stationnarité de $A\sin(2\pi f_0 t+\phi)$, estimateurs biaisé/non biaisé, MV de la moyenne, $F_{ij}$ en Markov, Karhunen-Loève. **Ce sont tes priorités absolues.**

## Contenu du dossier

| Fichier | Rôle | Quand |
|---|---|---|
| [[01_Fiche_Signaux_Continus]] | Fiche 1A signaux déterministes | J-3 |
| [[02_Fiche_Processus_Aleatoires]] | Fiche 1A processus/estimation/Markov (**le cœur**) | J-4 |
| [[03_Fiche_Filtres_Numeriques]] | Fiche 2A (poly prof + tes notes de cours + TD) | J-2 |
| [[04_VF_Signaux_Continus]] | 45 V/F corrigés | J-3, puis J-1 |
| [[05_VF_Processus]] | 70 V/F corrigés | J-4, puis J-2, J-1 |
| [[06_VF_Filtres_Numeriques]] | 60 V/F corrigés | J-2, puis J-1 |
| [[07_Exercices_Types]] | Exos style examen + TD 2A 1.1 à 1.5, corrigés | J-3, J-2 |
| [[08_Examen_Blanc]] | 40 V/F inédits + 2 exos, chronométré | J-1 |
| [[09_QCM_VF_Cours]] | 100 V/F calqués sur les phrases des polys (format probable du partiel) | J-2 et J-1 |

Répartition du temps : **65 % 1A / 35 % 2A**, alignée sur le poids annoncé.

---

## Planning sur 4 jours

### J-4 (aujourd'hui) : processus aléatoires (≈ 3 h)
1. **Blurting (15 min)** : sur une feuille blanche, sans rien regarder, écris tout ce que tu sais sur stationnarité, autocorrélation, BBGC, Markov. C'est ta photo de départ.
2. Lis [[02_Fiche_Processus_Aleatoires]] **stylo en main** : refais chaque mini-démo (MA, AR(1), $A\sin(\cdot+\phi)$).
3. [[05_VF_Processus]], **1er passage à l'aveugle** : réponds V/F *et* écris une justification d'une ligne **avant** d'ouvrir la réponse.
4. Reporte chaque erreur dans le **carnet d'erreurs** (en bas de ce fichier).

### J-3 : signaux continus + exos 1A (≈ 3 h 30)
1. Relis le carnet d'erreurs de J-4 (5 min). C'est la 1re répétition espacée.
2. [[01_Fiche_Signaux_Continus]] puis [[04_VF_Signaux_Continus]] à l'aveugle.
3. [[07_Exercices_Types]], partie 1A : **fais-les sans corrigé**, chrono, puis corrige. Les calculs de $R_{yy}(\tau)$ d'un MA tombent à **chaque** examen.

### J-2 : filtres numériques 2A (≈ 3 h 30)
1. 2e passage sur les V/F **ratés** de J-4 seulement (répétition espacée).
2. [[03_Fiche_Filtres_Numeriques]] puis [[06_VF_Filtres_Numeriques]].
3. [[07_Exercices_Types]], partie 2A (TD 1.1 à 1.5, les seuls vraiment traités en TD).
4. **Interleaving** : finis par 15 V/F mélangés tirés des 3 fichiers.

### J-1 : examen blanc et consolidation (≈ 3 h, pas plus)
1. [[08_Examen_Blanc]] **en conditions réelles** : 1 h 30, sans fiche ni calculatrice.
2. Correction, puis mise à jour du carnet d'erreurs.
3. **Feynman** sur tes 5 erreurs les plus graves : explique chaque notion à voix haute comme à un élève de terminale. Là où tu bloques, c'est un trou : retourne à la fiche.
4. Relis toutes les sections « Pièges » des 3 fiches.
5. **Dors.** La consolidation mémoire se fait pendant le sommeil : une nuit blanche fait perdre plus qu'elle ne rapporte.

### Jour J (20 min max)
Seulement les encadrés « Pièges » et ton carnet d'erreurs. Rien de nouveau.

---

## Les techniques à appliquer

| Technique | Comment | Pourquoi ça marche |
|---|---|---|
| **Rappel actif** | Toujours répondre *avant* de regarder (les réponses sont repliées : `> [!check]-`) | Se tester ancre bien mieux que relire |
| **Répétition espacée** | Revoir les erreurs à J+1, J+2, J+3 | Contre la courbe de l'oubli |
| **Blurting** | Page blanche → tout écrire → comparer à la fiche | Montre ce que tu sais *vraiment* |
| **Interleaving** | Mélanger 1A/2A dans une même session | Le partiel mélange les chapitres |
| **Feynman** | Expliquer simplement à voix haute | Révèle les zones floues |
| **Carnet d'erreurs** | Noter *pourquoi* tu t'es trompé, pas juste la bonne réponse | Tu ne refais pas deux fois la même erreur |
| **Pomodoro 50/10** | 50 min concentré, 10 min pause, téléphone dans une autre pièce | Garde la concentration |

---

## Méthode spéciale Vrai/Faux (le format du partiel)

Le prof teste surtout **les conditions et le sens des implications**. Pour chaque affirmation :

1. **Repère les mots-pièges** : *toujours, nécessairement, quel que soit, si et seulement si, implique, équivalent, uniquement*. Une seule exception suffit à rendre l'affirmation fausse.
2. **Vérifie le sens de l'implication** : « indépendant ⇒ décorrélé » est VRAI, « décorrélé ⇒ indépendant » est FAUX (sauf cas gaussien).
3. **Vérifie les hypothèses cachées** : stationnaire ? ergodique ? signal réel ou complexe ? filtre causal ? bruit centré ? chaîne irréductible ? apériodique ?
4. **Cherche un contre-exemple type** (à connaître par cœur) :
   - $A\sin(2\pi f_0 t)$ : moyenne nulle mais **pas** SSL ;
   - marche aléatoire : variance qui croît, donc **pas** stationnaire ;
   - filtre récursif qui est quand même RIF (simplification pôle-zéro, TD 1.6) ;
   - zero-padding : grille plus fine, mais **pas** de meilleure résolution.
5. **Vérifie les conventions du prof** : types I à IV de phase linéaire (sa table, pas celle d'Internet), $R(\tau)=E[X(t+\tau)X^*(t)]$, matrice stochastique $P$ (lignes de somme 1) vs matrice de transition $M=P^T$.
6. Si c'est un calcul : refais-le vite (ordre de grandeur, cas particulier $\tau=0$, $n=0$, $f=0$).

> [!tip] Si le barème pénalise les mauvaises réponses
> Ne réponds au hasard que si tu peux éliminer l'option la moins plausible. Demande en début d'épreuve si les fausses réponses retirent des points.

---

## Checklist « je sais faire » (à cocher la veille)

- [ ] Densité gaussienne de $N(m,\sigma^2)$ + intervalle à 95,4 % de $Y=aX+b$
- [ ] Moyenne et $R_{yy}(\tau)$ d'un MA avec bruit **non centré** ($\mu\neq 0$)
- [ ] $R_{xx}(\tau)$ d'un AR(1) + relation récursive
- [ ] Stationnarité de $A\sin(2\pi f_0t)$ et de $A\sin(2\pi f_0t+\phi)$
- [ ] Les 2 estimateurs de l'autocorrélation, leur biais, `xcorr(x,'biased'/'unbiased')`
- [ ] MV de la moyenne d'observations gaussiennes iid (démo)
- [ ] Moindres carrés $\hat\theta=(H^TH)^{-1}H^TY$ (démo + cas de biais)
- [ ] Karhunen-Loève : principe, erreur = somme des $\lambda$ écartées, applications
- [ ] Markov : $\pi=\pi P$, irréductible/apériodique, démo $F_{ij}=p_{ij}+\sum_{k\neq j}p_{ik}F_{kj}$
- [ ] Propriétés TF (retard, modulation, échelle, signal réel ⇒ hermitien)
- [ ] Wiener-Khintchine, Parseval, Shannon
- [ ] Fréquences observées par une TFD / FFT (TD 1.2), effet du zero-padding
- [ ] RIF/RII, causalité, stabilité, pôles/zéros → allure de $|H(f)|$
- [ ] Phase linéaire : conditions, 4 types, retard $(N-1)/2$
- [ ] Bilinéaire : stabilité conservée + distorsion (warping) + pré-distorsion
- [ ] Butterworth / Tchebychev I-II / Cauer / Bessel : qui ondule où

---

## Carnet d'erreurs (à remplir)

| # | Fichier / question | Ma réponse | Bonne réponse | **Pourquoi je me suis trompé** | Revu J+1 | J+2 |
|---|---|---|---|---|---|---|
| 1 | | | | | ☐ | ☐ |
| 2 | | | | | ☐ | ☐ |
| 3 | | | | | ☐ | ☐ |
| 4 | | | | | ☐ | ☐ |
| 5 | | | | | ☐ | ☐ |
