# Chapitre 4 — Fonctions  
[[00_Sommaire]]

---

## Introduction

Les **fonctions** permettent de diviser un programme en **blocs logiques réutilisables**.  
Elles améliorent la lisibilité, la maintenance et la modularité du code.

---

## 1. Définition et appel de fonction

### 1.1 Exemple simple

```c
#include <stdio.h>

void bonjour() {
    printf("Bonjour !\n");
}

int main() {
    bonjour();
    return 0;
}
```

### 1.2 Structure d’une fonction

```c
type_retour nom_fonction(paramètres) {
    // corps de la fonction
}
```

- **type_retour** : type de la valeur renvoyée (ou `void` si aucune).  
- **nom_fonction** : identifiant unique.  
- **paramètres** : variables locales reçues par la fonction.

---

## 2. Passage de paramètres

### 2.1 Passage par valeur

Les arguments sont **copiés** dans les paramètres.

```c
void incrementer(int n) {
    n++;
}

int main() {
    int a = 5;
    incrementer(a);
    printf("%d", a); // affiche 5
}
```

### 2.2 Passage par adresse

Permet de modifier la variable originale.

```c
void incrementer(int *n) {
    (*n)++;
}

int main() {
    int a = 5;
    incrementer(&a);
    printf("%d", a); // affiche 6
}
```

💡 On utilise `&` pour envoyer l’adresse, et `*` pour accéder à la valeur.

---

## 3. Retour d’une valeur

```c
int carre(int x) {
    return x * x;
}
```

```c
int main() {
    int r = carre(5);
    printf("Résultat : %d\n", r);
}
```

---

## 4. Prototypes de fonctions

Les **prototypes** annoncent la fonction avant son utilisation.

```c
int carre(int x); // prototype

int main() {
    printf("%d", carre(4));
}

int carre(int x) {
    return x * x;
}
```

💡 Le prototype évite les erreurs de compilation lors de l’appel.

---

## 5. Portée des variables

| Type | Localisation | Accessibilité |
|-------|---------------|---------------|
| Locale | À l’intérieur d’une fonction | Seulement dans cette fonction |
| Globale | En dehors de toute fonction | Accessible partout |
| Statique | Persiste entre appels | Visible uniquement dans le fichier |

### Exemple :

```c
int g = 0; // globale

void f() {
    int local = 0;
    static int compteur = 0;
    g++;
    compteur++;
    printf("%d %d %d\n", g, local, compteur);
}
```

Chaque appel de `f()` incrémente `compteur`, mais la variable `local` est réinitialisée.

---

## 6. Fonctions récursives

Une **fonction récursive** s’appelle elle-même.

### Exemple : factorielle

```c
int fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}
```

### Exemple : Fibonacci

```c
int fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}
```

⚠️ Toujours définir une **condition d’arrêt** pour éviter les boucles infinies.

---

## 7. Fonction avec plusieurs paramètres

```c
float moyenne(float a, float b, float c) {
    return (a + b + c) / 3;
}
```

---

## 8. Fonctions dans plusieurs fichiers

### 8.1 Déclaration dans un header (`.h`)

```c
// calcul.h
int carre(int x);
```

### 8.2 Définition dans un fichier source (`.c`)

```c
// calcul.c
int carre(int x) { return x * x; }
```

### 8.3 Utilisation

```c
#include "calcul.h"
#include <stdio.h>

int main() {
    printf("%d", carre(4));
}
```

💡 Cela permet de **structurer le code** et d’éviter les redéfinitions.

---

## Synthèse du chapitre

- Une **fonction** regroupe un ensemble d’instructions exécutables à la demande.  
- Les **paramètres** peuvent être passés **par valeur** ou **par adresse**.  
- Une fonction peut **retourner une valeur**.  
- Les **prototypes** assurent la cohérence du code.  
- La **récursivité** permet des solutions élégantes mais doit être maîtrisée.  
- La **portée** et la **durée de vie** des variables influencent le comportement du programme.

---

[[03_Conditions_et_Boucles]] ← → [[05_Tableaux_et_Chaines]]
