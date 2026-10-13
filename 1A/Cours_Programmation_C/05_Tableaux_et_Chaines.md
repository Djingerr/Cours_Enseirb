# Chapitre 5 — Tableaux et chaînes de caractères  
[[00_Sommaire]]

---

## Introduction

Les **tableaux** permettent de stocker plusieurs valeurs du **même type** sous un seul nom.  
Les **chaînes de caractères** sont des tableaux particuliers de `char` terminés par le caractère nul `\0`.

---

## 1. Déclaration et utilisation des tableaux

### 1.1 Déclaration simple

```c
int notes[5];
```

Crée un tableau de 5 entiers (indexés de 0 à 4).

### 1.2 Initialisation

```c
int notes[5] = {12, 15, 14, 9, 17};
```

ou

```c
int notes[] = {12, 15, 14, 9, 17}; // taille déduite automatiquement
```

### 1.3 Accès aux éléments

```c
printf("%d", notes[2]); // affiche 14
notes[0] = 10; // modifie le premier élément
```

⚠️ En C, aucun contrôle des bornes : accéder à `notes[10]` est **dangereux**.

---

## 2. Parcours d’un tableau

```c
int notes[5] = {12, 15, 14, 9, 17};

for (int i = 0; i < 5; i++) {
    printf("Note %d = %d\n", i, notes[i]);
}
```

---

## 3. Tableaux multidimensionnels

### 3.1 Exemple

```c
int matrice[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

### 3.2 Accès

```c
printf("%d", matrice[1][2]); // affiche 6
```

### 3.3 Parcours

```c
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
        printf("%d ", matrice[i][j]);
    }
    printf("\n");
}
```

---

## 4. Chaînes de caractères

### 4.1 Définition

Une **chaîne** est un tableau de caractères terminé par `\0`.

```c
char mot[] = "Bonjour";
```

ou

```c
char mot[8] = {'B', 'o', 'n', 'j', 'o', 'u', 'r', '\0'};
```

### 4.2 Lecture et affichage

```c
char nom[20];
printf("Votre nom : ");
scanf("%s", nom);
printf("Bonjour %s !", nom);
```

⚠️ `scanf("%s", nom)` lit jusqu’au premier espace → utiliser `fgets()` pour une ligne complète.

---

## 5. Fonctions de la bibliothèque `<string.h>`

| Fonction            | Description            | Exemple                |
| ------------------- | ---------------------- | ---------------------- |
| `strlen(s)`         | Longueur de la chaîne  | `strlen("abc") == 3`   |
| `strcpy(dest, src)` | Copie une chaîne       | `strcpy(b, a)`         |
| `strcat(dest, src)` | Concatène deux chaînes | `strcat(a, b)`         |
| `strcmp(a, b)`      | Compare deux chaînes   | `strcmp("a", "b") < 0` |

### Exemple complet

```c
#include <stdio.h>
#include <string.h>

int main() {
    char a[20] = "Bonjour";
    char b[20] = " le monde";
    strcat(a, b);
    printf("%s", a);
    return 0;
}
```

---

## 6. Tableaux et fonctions

### 6.1 Passage d’un tableau à une fonction

```c
void afficher(int t[], int taille) {
    for (int i = 0; i < taille; i++) {
        printf("%d ", t[i]);
    }
}

int main() {
    int valeurs[3] = {1, 2, 3};
    afficher(valeurs, 3);
}
```

⚙️ Le tableau est passé **par adresse** (le contenu peut être modifié).

### 6.2 Exemple avec chaînes

```c
void afficherTexte(char s[]) {
    printf("%s", s);
}

int main() {
    char phrase[] = "Salut !";
    afficherTexte(phrase);
}
```

---

## 7. Limites et précautions

- Les **indices** doivent rester dans les bornes du tableau.  
- Les chaînes doivent toujours être **terminées par `\0`**.  
- Utiliser `strncpy` au lieu de `strcpy` pour éviter les débordements.  
- Pour les tableaux dynamiques, utiliser **malloc** (voir chapitre suivant).

---

## Synthèse du chapitre

- Les **tableaux** stockent plusieurs valeurs du même type.  
- Les **chaînes de caractères** sont des tableaux de `char` terminés par `\0`.  
- Les fonctions de `<string.h>` facilitent la manipulation des chaînes.  
- Un tableau est toujours passé **par adresse** à une fonction.  
- Attention aux **dépassements de mémoire**.

---

[[04_Fonctions]] ← → [[06_Pointeurs_et_Memoire]]
