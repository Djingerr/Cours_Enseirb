# Chapitre 1 — Introduction au langage C  
[[00_Sommaire]]

---

## Introduction

Le **langage C** est l’un des langages de programmation les plus influents et durables.  
Créé au début des années 1970 par **Dennis Ritchie** dans les laboratoires Bell, il a servi à écrire le système d’exploitation **UNIX**, et reste aujourd’hui la base de nombreux langages modernes tels que C++, Java, Go ou Rust.

Le C est un langage :
- **impératif** : les instructions sont exécutées dans un ordre précis ;
- **structuré** : il favorise la clarté et la modularité du code ;
- **compilé** : il est transformé en code machine avant exécution.

---

## Objectifs du cours

À la fin de ce cours, tu sauras :
- comprendre et écrire des programmes en C ;
- manipuler les variables, tableaux, pointeurs et structures ;
- interagir avec des fichiers et la mémoire ;
- structurer un projet en plusieurs fichiers et le compiler.

---

## 1. Structure minimale d’un programme C

### 1.1 Exemple simple

```c
#include <stdio.h>

int main(void) {
    printf("Bonjour, monde !\n");
    return 0;
}
```

### 1.2 Décomposition

| Élément | Rôle |
|----------|------|
| `#include <stdio.h>` | Inclusion de la bibliothèque standard d’E/S |
| `int main(void)` | Fonction principale, point d’entrée du programme |
| `printf()` | Fonction d’affichage sur la sortie standard |
| `return 0;` | Indique que le programme s’est terminé avec succès |

---

## 2. Compilation et exécution

### 2.1 Étapes principales

1. **Édition du code source** : fichier `.c`  
2. **Compilation** : transformation en code objet `.o`  
3. **Édition de liens** : création de l’exécutable final  
4. **Exécution** : le programme s’exécute sur le processeur.

### 2.2 Exemple avec GCC

```bash
gcc programme.c -o programme
./programme
```

---

## 3. Les bibliothèques standard

Le C fournit de nombreuses **bibliothèques** pour des tâches courantes :
- `stdio.h` : entrées/sorties (`printf`, `scanf`)  
- `stdlib.h` : utilitaires généraux (`malloc`, `free`, `rand`)  
- `string.h` : manipulation de chaînes (`strlen`, `strcpy`)  
- `math.h` : fonctions mathématiques (`sqrt`, `pow`)

---

## 4. Avantages et inconvénients du langage C

### 4.1 Avantages
- Très **rapide et efficace** (proche du matériel).  
- **Portable** sur toutes les plateformes.  
- Langage de référence pour l’**apprentissage des bases** de la programmation.

### 4.2 Inconvénients
- Peu de **vérifications automatiques** (risque d’erreurs mémoire).  
- Pas de gestion native des chaînes ou des exceptions.  
- Programmation bas-niveau nécessitant rigueur et prudence.

---

## 5. Exemple d’analyse d’un programme

```c
#include <stdio.h>

int carre(int x) {
    return x * x;
}

int main() {
    int n = 4;
    printf("Le carré de %d est %d\n", n, carre(n));
    return 0;
}
```

📘 **Explication :**
- La fonction `carre()` calcule une valeur.  
- `main()` appelle cette fonction et affiche le résultat.  
- Le code est **structuré et modulaire** : chaque fonction a un rôle précis.

---

## Synthèse du chapitre

- Le **langage C** est compilé, structuré et bas-niveau.  
- Tout programme commence par la fonction `main()`.  
- Le code est organisé en **instructions séquentielles**, souvent groupées en **fonctions**.  
- La compilation se fait avec un outil comme **GCC** ou **Clang**.  
- Le C est la base de nombreux langages modernes et reste incontournable dans le développement système.

---

[[00_Sommaire]] ← → [[02_Variables_et_Types]]
