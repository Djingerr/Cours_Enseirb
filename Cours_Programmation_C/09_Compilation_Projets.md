# Chapitre 9 — Compilation et gestion de projets  
[[00_Sommaire]]

---

## Introduction

Un projet en langage C peut contenir plusieurs fichiers sources et bibliothèques.  
La **compilation** transforme le code source en un **exécutable**.  
Comprendre les étapes et les outils de compilation est essentiel pour structurer correctement un programme.

---

## 1. Étapes de la compilation

### 1.1 Schéma général

1. **Préprocessing** → inclusion des fichiers (`#include`) et macros (`#define`).
2. **Compilation** → transformation du code en **fichier objet (.o)**.
3. **Édition de liens (linking)** → assemblage des fichiers objets pour créer l’exécutable.

### 1.2 Exemple de commande GCC

```bash
gcc main.c -o programme
```

### 1.3 Compilation séparée

```bash
gcc -c calcul.c   # crée calcul.o
gcc -c main.c     # crée main.o
gcc main.o calcul.o -o programme
```

💡 Cette méthode accélère la recompilation et améliore la modularité.

---

## 2. Organisation d’un projet

### Structure typique

```
/projet
│
├── src/        → fichiers sources (.c)
├── include/    → fichiers d’en-tête (.h)
├── bin/        → exécutables
└── Makefile    → automatisation de la compilation
```

### Exemple de fichiers

- `main.c` : contient `main()`  
- `calcul.c` : contient les fonctions du module calcul  
- `calcul.h` : prototypes de fonctions

```c
// calcul.h
int addition(int a, int b);
```

```c
// calcul.c
#include "calcul.h"
int addition(int a, int b) {
    return a + b;
}
```

```c
// main.c
#include <stdio.h>
#include "calcul.h"

int main() {
    printf("%d", addition(2, 3));
    return 0;
}
```

---

## 3. Le Makefile

Le **Makefile** automatise la compilation.

### Exemple simple

```makefile
programme: main.o calcul.o
	gcc main.o calcul.o -o programme

main.o: main.c calcul.h
	gcc -c main.c

calcul.o: calcul.c calcul.h
	gcc -c calcul.c

clean:
	rm -f *.o programme
```

### Utilisation

```bash
make        # compile le projet
make clean  # supprime les fichiers temporaires
```

💡 `make` ne recompile que les fichiers modifiés → gain de temps.

---

## 4. Inclusion de bibliothèques

### 4.1 Bibliothèques standard

Incluses avec le compilateur :
```c
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
```

Compilation :
```bash
gcc main.c -lm   # pour la bibliothèque mathématique
```

### 4.2 Bibliothèques externes

```bash
gcc main.c -o prog -L/usr/lib -lmylib -I/usr/include/mylib
```

- `-L` : chemin vers les bibliothèques
- `-I` : chemin vers les fichiers d’en-tête
- `-l` : nom de la bibliothèque à lier

---

## 5. Compilation conditionnelle

Permet d’inclure du code selon une condition.

```c
#ifdef DEBUG
printf("Mode debug activé\n");
#endif
```

Compilation avec une option :
```bash
gcc -DDEBUG main.c -o prog
```

---

## 6. Erreurs de compilation et d’édition de liens

| Type d’erreur | Exemple | Cause |
|----------------|----------|--------|
| Syntaxe | `missing ;` | Erreur de grammaire |
| Non-déclarée | `undeclared variable` | Variable inconnue |
| Liaison | `undefined reference` | Fonction non trouvée à l’édition de liens |
| Type | `incompatible pointer type` | Mauvais type de paramètre |

💡 Toujours lire attentivement les messages d’erreur du compilateur.

---

## 7. Options utiles de GCC

| Option | Description |
|---------|--------------|
| `-Wall` | Active tous les avertissements |
| `-Wextra` | Active des vérifications supplémentaires |
| `-g` | Ajoute les informations de débogage |
| `-O2` | Optimisation du code |
| `-E` | Exécute seulement le préprocesseur |
| `-S` | Génère le code assembleur |
| `-c` | Compile sans lier |

---

## 8. Débogage

### 8.1 Avec GDB

```bash
gcc -g main.c -o prog
gdb prog
```

Commandes utiles :
```
run
break main
next
print variable
continue
quit
```

### 8.2 Avec `printf`

Méthode simple et universelle : afficher des valeurs intermédiaires.

---

## 9. Compilation sur plusieurs fichiers

### Exemple

```
gcc -Iinclude src/main.c src/calcul.c -o bin/prog
```

💡 L’option `-I` précise où chercher les fichiers d’en-tête.

---

## Synthèse du chapitre

- La **compilation** se déroule en plusieurs étapes : préprocessing, compilation, liaison.  
- Le **Makefile** automatise la construction du projet.  
- Il est important de **structurer** le code en fichiers `.c` et `.h`.  
- Les **options GCC** permettent d’activer les avertissements et les optimisations.  
- Le **débogage** aide à corriger les erreurs de logique et de syntaxe.

---

[[08_Fichiers_IO]] ← → [[10_Synthese_Glossaire]]
