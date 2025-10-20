# Chapitre 2 — Variables et types primitifs  
[[00_Sommaire]]

---

## Introduction

Les **variables** permettent de stocker et manipuler des données dans un programme.  
Chaque variable a un **nom**, un **type** et une **valeur**.  
Le **type** détermine la taille mémoire et les opérations possibles sur la variable.

---

## 1. Les types de base en C

### 1.1 Types entiers

| Type | Taille (approx.) | Exemple | Remarques |
|------|------------------|----------|------------|
| `char` | 1 octet | `'A'`, `97` | Peut être signé ou non |
| `short` | 2 octets | `-32768` à `32767` | Entier court |
| `int` | 4 octets | `42` | Type entier standard |
| `long` | ≥ 4 octets | `123456789L` | Grand entier |
| `long long` | 8 octets | `9223372036854775807LL` | Très grand entier |

Les modificateurs `signed` et `unsigned` précisent le signe :  
```c
unsigned int n = 10;
```

---

### 1.2 Types réels (flottants)

| Type | Taille | Précision approximative |
|-------|--------|--------------------------|
| `float` | 4 octets | ~6 à 7 chiffres |
| `double` | 8 octets | ~15 chiffres |
| `long double` | 10–16 octets | ~18 chiffres |

Exemple :  
```c
float x = 3.14f;
double y = 2.71828;
```

---

### 1.3 Type caractère et chaînes

Un **caractère** est stocké dans un `char` :
```c
char c = 'A';
```

Une **chaîne de caractères** est un **tableau de char** terminé par `\0` :
```c
char mot[] = "Bonjour";
```

⚠️ Le caractère `\0` indique la fin de la chaîne.

---

### 1.4 Type booléen

Depuis C99 :
```c
#include <stdbool.h>
bool actif = true;
```

Valeurs possibles :
- `true`
- `false`

---

## 2. Déclaration et initialisation

### 2.1 Déclaration simple

```c
int age;
float poids;
char lettre;
```

### 2.2 Initialisation

```c
int age = 25;
float pi = 3.14;
char c = 'Z';
```

Il est recommandé **d’initialiser toutes les variables** pour éviter des valeurs indéterminées.

---

## 3. Constantes

Une **constante** est une valeur qui ne change pas pendant l’exécution.

### 3.1 Constante littérale

```c
printf("%d", 42);
```

### 3.2 Constante nommée

Avec `#define` :
```c
#define PI 3.14159
```

Avec `const` :
```c
const float g = 9.81;
```

⚙️ `#define` est géré par le préprocesseur, tandis que `const` est interprété par le compilateur.

---

## 4. Conversion de types (cast)

Le **cast** permet de convertir explicitement un type en un autre :
```c
int a = 5, b = 2;
float r = (float)a / b;
```

Résultat : `2.5` (et non `2`).

---

## 5. Opérateurs

### 5.1 Arithmétiques

| Opérateur | Signification | Exemple |
|------------|----------------|----------|
| `+` | Addition | `a + b` |
| `-` | Soustraction | `a - b` |
| `*` | Multiplication | `a * b` |
| `/` | Division | `a / b` |
| `%` | Modulo (reste entier) | `a % b` |

### 5.2 Affectation combinée

| Opérateur | Équivalent à | Exemple |
|------------|---------------|----------|
| `+=` | `a = a + b` | `a += 2` |
| `-=` | `a = a - b` | `a -= 3` |
| `*=` | `a = a * b` | `a *= 5` |
| `/=` | `a = a / b` | `a /= 4` |

### 5.3 Incrémentation / décrémentation

```c
i++; // post-incrémentation
++i; // pré-incrémentation
```

Différence :
- `i++` : utilise la valeur avant d’ajouter 1  
- `++i` : ajoute 1 puis utilise la valeur

---

## 6. Entrées et sorties de base

### 6.1 Affichage (`printf`)

```c
int a = 10;
printf("Valeur : %d\n", a);
```

| Format | Type |
|---------|------|
| `%d` | int |
| `%f` | float/double |
| `%c` | char |
| `%s` | string |

### 6.2 Lecture (`scanf`)

```c
int age;
scanf("%d", &age);
```

⚠️ Toujours passer **l’adresse** de la variable (`&`).

---

## 7. Portée et durée de vie des variables

| Type de variable | Portée | Durée de vie |
|------------------|--------|---------------|
| Locale | Fonction ou bloc | Jusqu’à la fin du bloc |
| Globale | Programme entier | Toute la durée du programme |
| Statique (`static`) | Conserve sa valeur entre appels | Même après sortie du bloc |

---

## 8. Bonnes pratiques

- Donner des **noms explicites** (`compteur`, `somme`, `resultat`).  
- Toujours **initialiser** les variables.  
- Éviter les **variables globales**.  
- Utiliser `const` pour les valeurs fixes.  
- Vérifier les **types** lors des calculs mixtes (int vs float).

---

## Synthèse du chapitre

- Les **types primitifs** du C sont `int`, `char`, `float`, `double`, `bool`.  
- Une **variable** doit être **déclarée et initialisée** avant usage.  
- Les **opérateurs arithmétiques** et **logiques** permettent de manipuler ces variables.  
- Les **constantes** garantissent l’immuabilité d’une valeur.  
- Les conversions de types (cast) doivent être maîtrisées pour éviter les erreurs.

---

[[01_Introduction]] ← → [[03_Conditions_et_Boucles]]
