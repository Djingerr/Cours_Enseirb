# Chapitre 6 — Pointeurs et gestion mémoire  
[[00_Sommaire]]

---

## Introduction

Les **pointeurs** sont l’un des concepts les plus puissants du langage C.  
Ils permettent de **manipuler directement les adresses mémoire** et de gérer des structures dynamiques.  
Bien utilisés, ils rendent le code flexible et performant ; mal utilisés, ils peuvent causer des erreurs graves.

---

## 1. Notion d’adresse mémoire

Chaque variable est stockée dans une **adresse mémoire**.  
On peut obtenir cette adresse avec l’opérateur `&`.

```c
int a = 5;
printf("Adresse de a : %p\n", &a);
```

L’opérateur `%p` affiche une adresse mémoire.

---

## 2. Déclaration d’un pointeur

```c
int a = 5;
int *p;     // déclaration d’un pointeur vers int
p = &a;     // p contient l’adresse de a
```

### Accès à la valeur pointée

```c
printf("Valeur pointée : %d\n", *p);
```

💡 `*p` signifie “la valeur à l’adresse contenue dans p”.

---

## 3. Exemple complet

```c
int a = 10;
int *ptr = &a;

printf("a = %d\n", a);
printf("*ptr = %d\n", *ptr);

*ptr = 20; // modifie la valeur de a
printf("a = %d\n", a);
```

Résultat :
```
a = 10
*ptr = 10
a = 20
```

---

## 4. Pointeurs et tableaux

Le nom d’un tableau **est déjà un pointeur** vers son premier élément.

```c
int t[3] = {10, 20, 30};
int *p = t;

printf("%d", *(p + 1)); // affiche 20
```

`*(p + i)` équivaut à `t[i]`.

---

## 5. Pointeurs et fonctions

### 5.1 Passage par adresse

```c
void doubler(int *x) {
    *x = *x * 2;
}

int main() {
    int a = 3;
    doubler(&a);
    printf("%d", a); // affiche 6
}
```

💡 Les pointeurs permettent à une fonction de **modifier une variable externe**.

---

## 6. Pointeurs et chaînes

```c
char *message = "Bonjour";
printf("%s", message);
```

Ici, `message` pointe vers le premier caractère de la chaîne.

---

## 7. Allocation dynamique

Pour réserver de la mémoire pendant l’exécution, on utilise les fonctions de `<stdlib.h>` :

| Fonction | Rôle |
|-----------|------|
| `malloc()` | Alloue une zone mémoire brute |
| `calloc()` | Alloue et initialise à zéro |
| `realloc()` | Redimensionne une zone mémoire |
| `free()` | Libère la mémoire allouée |

### Exemple :

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *tab;
    tab = malloc(5 * sizeof(int));

    if (tab == NULL) {
        printf("Erreur d’allocation\n");
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        tab[i] = i * 10;
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", tab[i]);
    }

    free(tab);
    return 0;
}
```

---

## 8. Pointeurs nuls et sécurité

### 8.1 Le pointeur `NULL`

```c
int *p = NULL;
```

Avant d’utiliser un pointeur, **toujours vérifier s’il est nul** :

```c
if (p != NULL) {
    printf("%d", *p);
}
```

### 8.2 Erreurs classiques

| Erreur | Exemple | Conséquence |
|--------|----------|-------------|
| Pointeur non initialisé | `int *p; *p = 5;` | Segmentation fault |
| Oubli de `free()` | Allocation non libérée | Fuite mémoire |
| Double `free()` | Libération répétée | Crash du programme |

---

## 9. Pointeurs de pointeurs

Un **pointeur de pointeur** contient l’adresse d’un autre pointeur.

```c
int a = 5;
int *p = &a;
int **pp = &p;

printf("%d", **pp); // affiche 5
```

---

## 10. Pointeurs et fonctions avancées

### Exemple : création dynamique de tableau

```c
int *creerTableau(int n) {
    int *tab = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) tab[i] = i;
    return tab;
}

int main() {
    int *t = creerTableau(5);
    for (int i = 0; i < 5; i++) printf("%d ", t[i]);
    free(t);
}
```

---

## Synthèse du chapitre

- Un **pointeur** contient une **adresse mémoire**.  
- L’opérateur `*` permet d’accéder à la **valeur pointée**.  
- Les pointeurs servent au **passage par adresse**, aux **tableaux** et à la **mémoire dynamique**.  
- Toujours **initialiser**, **vérifier** et **libérer** les pointeurs.  
- La mauvaise gestion de la mémoire est une **source majeure de bugs**.

---

[[05_Tableaux_et_Chaines]] ← → [[07_Structures_Typedef_Enums]]
