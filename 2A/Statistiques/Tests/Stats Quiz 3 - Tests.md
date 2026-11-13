---
tags: [stats, quiz, tests]
---
# Quiz 3 — Tests d'hypothèses (≈ 30 min)

Chapitre : [[Stats 07 - Tests d'hypothèses]] · Retour : [[00 - Stats Sommaire]]

> [!info] Règles
> Sur 15. **≥ 12** → [[Stats TD3 - Tests (corrigé)|TD3]].

1. Que signifie $T_n=1$ ?
2. Définir l'erreur de type I, le niveau, la puissance.
3. Pourquoi fixe-t-on le niveau plutôt que de minimiser les deux erreurs ?
4. Écrire la définition du ratio de vraisemblances.
5. $\ln R_n=-3\bar X_n+5$. Forme de la région de rejet ?
6. $\mathcal N(\mu,1)$, $n=25$, $H_0:\mu=0$ vs $H_1:\mu=0{,}5$, $\alpha=5\%$. Seuil sur $\bar X_n$ ?
7. Puissance de ce test ?
8. Pour un test bilatère $\mathcal N(0,1)$ à 5 %, quel seuil sur $|Z|$ ?
9. $H_0:\mu\le\mu_0$ composite : où calcule-t-on le seuil et pourquoi ?
10. Bernoulli, $\theta_0<\theta_1$ : le RV est fonction croissante de quoi ?
11. Exponentielle, $\theta_0<\theta_1$ : on rejette $H_0$ quand $\sum X_k$ est grand ou petit ?
12. Gaussien $\mu,\sigma^2$ inconnus, test $\mu=\mu_0$ : quelle statistique, quelle loi sous $H_0$ ?
13. Que devient la puissance quand $n\to\infty$ pour une alternative fixe ? Pour $\theta_1=\theta_0+\Delta/\sqrt n$ ?
14. Puissance d'un test « rejet si $|Z|>q$ » quand $Z\sim\mathcal N(\delta,1)$ ?
15. RADAR : quelle quantité de traitement du signal apparaît dans le RV ?

---
> [!success]- Correction
> 1. On rejette $H_0$ (on décide $H_1$).
> 2. Type I : rejeter $H_0$ alors qu'elle est vraie, $P_\theta(T_n=1)$, $\theta\in\Theta_0$ ; niveau $=\sup_{\Theta_0}$ ; puissance $P_\theta(T_n=1)$, $\theta\in\Theta_1$.
> 3. Compromis : baisser l'une augmente l'autre ; par convention on contrôle la fausse alarme.
> 4. $R_n=\sup_{\Theta_1}\prod f_\theta(X_k)/\sup_{\Theta_0}\prod f_\theta(X_k)$, rejet si $R_n>\epsilon$.
> 5. Décroissant ⇒ rejet si $\bar X_n<\epsilon'$.
> 6. $\epsilon=0+\frac15\cdot1{,}645=0{,}329$.
> 7. $1-\Phi(1{,}645-5\cdot0{,}5)=1-\Phi(-0{,}855)=\Phi(0{,}855)\approx0{,}80$.
> 8. 1,96.
> 9. À la frontière $\mu_0$ : $P_\mu(\text{rejet})$ est croissante en $\mu$, son sup sur $\Theta_0$ est en $\mu_0$.
> 10. De $S=\sum X_k$ (ou $\bar X_n$).
> 11. Petit ($R_n$ décroissant en $S$).
> 12. $\sqrt n(\bar X_n-\mu_0)/s_n\sim t(n-1)$, rejet si $|\cdot|>t_{n-1,1-\alpha/2}$.
> 13. → 1 (test consistant) ; → une limite $<1$ (ex. $1-\Phi(q-\Delta/s)$).
> 14. $1-\Phi(q-\delta)+\Phi(-q-\delta)$.
> 15. La corrélation $\langle s,y\rangle$ = filtre adapté ; puissance fonction du SNR.
