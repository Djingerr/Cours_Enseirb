# 🧠 Fiche de révision — Programmation en C

---

## ⚙️ Mémoire et pointeurs

- Un **pointeur** stocke **l’adresse** d’une variable : `int *p = &a;`
- `*p` accède à la **valeur pointée**, `p` contient **l’adresse**.
- Toujours **initialiser les pointeurs** :  
  ```c
  int *p = NULL;
  ```
- Ne jamais faire `free()` deux fois sur le même pointeur.
- Après `free(p);` → faire `p = NULL;`
- `malloc` et `calloc` renvoient `NULL` si échec → **vérifier avant usage.**
- La **durée de vie** des variables locales prend fin à la sortie du bloc.
- Les tableaux sont **passés par adresse** (modifiables par les fonctions).

---

## 🧩 Tableaux et chaînes

- Un **tableau** n’a pas de taille connue par la fonction → toujours **passer la taille** en paramètre.
- Les **indices** vont de `0` à `n-1`.  
  ⚠️ Accès hors limites = comportement **indéfini**.
- Les **chaînes de caractères** doivent se terminer par `\0`.
- `strcpy()` est dangereux → préférer `strncpy()`.
- Comparer des chaînes avec `strcmp(a, b)` et **non** avec `==`.

---

## 📦 Structures et typedef

- Une structure **regroupe des champs** :  
  ```c
  typedef struct {
      int x, y;
  } Point;
  ```
- Utiliser `typedef` pour simplifier les noms (`Point` au lieu de `struct Point`).
- L’accès via pointeur utilise `->` (pas `.`).
- Toujours **initialiser les champs** avant usage.
- Une structure passée par valeur est **copiée** (préférer passage par adresse pour efficacité).

---

## ⚠️ Erreurs classiques à éviter

| Type d’erreur | Exemple | Symptôme |
|----------------|----------|-----------|
| Variable non initialisée | `int x; printf("%d", x);` | Valeur aléatoire |
| Mauvais format `printf` | `printf("%f", x)` alors que `x` est un `int` | Résultat incohérent |
| Oubli `&` dans `scanf` | `scanf("%d", a);` | Crash immédiat |
| Oubli de `free()` | Après `malloc()` | Fuite mémoire |
| Double `free()` | `free(p); free(p);` | Segmentation fault |
| Chaîne non terminée | `char s[3] = {'O','K'};` | Comportement indéfini |
| Fonction sans prototype | Appel avant déclaration | “implicit declaration” warning |

---

## 🔁 Conditions et boucles

- Toujours **vérifier la condition** avant une boucle `while`.
- `do...while` → exécute **au moins une fois**.
- `break` sort de la boucle, `continue` saute à l’itération suivante.
- ⚠️ Ne pas oublier de **modifier la variable de boucle** → sinon boucle infinie.
- `switch` doit toujours avoir un `default:` pour les cas imprévus.

---

## 🧮 Fonctions et portée

- Les variables **locales** ne vivent que dans la fonction.  
- Les **globales** doivent être limitées au strict nécessaire.
- `static` dans une fonction → conserve la valeur entre appels.
- Toujours déclarer les **prototypes** avant utilisation.

---

## 📁 Fichiers (I/O)

- `FILE *f = fopen("fichier.txt", "r");` → toujours **vérifier le retour**.
- `fclose(f);` obligatoire à la fin.
- Utiliser `fgets()` plutôt que `scanf("%s")` pour les chaînes avec espaces.
- En binaire : `fwrite()` et `fread()` sur des structures ou tableaux.
- Oublier `fclose()` peut entraîner **perte de données**.

---

## ⚡ Compilation et projet

- Étapes : **préprocesseur → compilation → édition de liens**.
- Toujours compiler avec `-Wall -Wextra` → détecte la majorité des erreurs.
- Liens courants :
  ```bash
  gcc main.c module.c -o prog
  ```
- **Headers (`.h`)** : ne contiennent que les **prototypes** et **déclarations globales**.
- **Makefile** : automatise la compilation, ne recompile que le nécessaire.

---

## 🧠 Mémento rapide

- `%d` → `int`  
- `%f` → `float`/`double`  
- `%c` → `char`  
- `%s` → `string`  
- `%p` → adresse (`void*`)

---

## 💡 Rappels essentiels

- Le C **ne vérifie pas les limites mémoire** → prudence.
- Les pointeurs et les chaînes sont les **sources d’erreurs les plus fréquentes**.
- Toujours **tester les retours** de `malloc`, `fopen`, `scanf`, etc.
- Une **bonne discipline mémoire** est le secret d’un programme C stable.

---

[[00_Sommaire]]
