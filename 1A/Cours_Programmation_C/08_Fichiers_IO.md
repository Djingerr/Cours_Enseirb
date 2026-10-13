# Chapitre 8 — Fichiers et entrées/sorties (I/O)  
[[00_Sommaire]]

---

## Introduction

La gestion des **fichiers** est essentielle pour sauvegarder et lire des données.  
Le langage C permet de manipuler des fichiers via la **bibliothèque standard `<stdio.h>`** en utilisant des **flux** (`FILE*`).

---

## 1. Types de fichiers

- **Fichiers texte** : contiennent des caractères lisibles (`.txt`, `.csv`, etc.).  
- **Fichiers binaires** : contiennent des données brutes (`.dat`, `.bin`, etc.).

---

## 2. Ouverture d’un fichier

```c
FILE *f = fopen("donnees.txt", "r");
```

### Modes d’ouverture

| Mode | Description |
|------|--------------|
| `"r"` | Lecture (le fichier doit exister) |
| `"w"` | Écriture (écrase le contenu existant) |
| `"a"` | Ajout à la fin |
| `"r+"` | Lecture/écriture (fichier existant) |
| `"w+"` | Lecture/écriture (efface le fichier) |
| `"a+"` | Lecture/ajout |

💡 Toujours **vérifier si le fichier s’est ouvert correctement**.

```c
if (f == NULL) {
    printf("Erreur d'ouverture\n");
    return 1;
}
```

---

## 3. Lecture et écriture dans un fichier texte

### 3.1 Écriture (`fprintf`)

```c
FILE *f = fopen("resultat.txt", "w");
if (f != NULL) {
    fprintf(f, "Valeur = %d\n", 42);
    fclose(f);
}
```

### 3.2 Lecture (`fscanf`)

```c
FILE *f = fopen("resultat.txt", "r");
int val;
if (f != NULL) {
    fscanf(f, "Valeur = %d", &val);
    printf("Lu : %d\n", val);
    fclose(f);
}
```

### 3.3 Lecture ligne par ligne (`fgets`)

```c
char ligne[100];
FILE *f = fopen("texte.txt", "r");
while (fgets(ligne, 100, f) != NULL) {
    printf("%s", ligne);
}
fclose(f);
```

---

## 4. Lecture et écriture dans un fichier binaire

### 4.1 Écriture (`fwrite`)

```c
int tab[3] = {10, 20, 30};
FILE *f = fopen("data.bin", "wb");
fwrite(tab, sizeof(int), 3, f);
fclose(f);
```

### 4.2 Lecture (`fread`)

```c
int tab[3];
FILE *f = fopen("data.bin", "rb");
fread(tab, sizeof(int), 3, f);
for (int i = 0; i < 3; i++) printf("%d ", tab[i]);
fclose(f);
```

---

## 5. Fonctions de manipulation de fichiers

| Fonction | Description |
|-----------|--------------|
| `fopen()` | Ouvre un fichier |
| `fclose()` | Ferme le fichier |
| `fgetc()` | Lit un caractère |
| `fputc()` | Écrit un caractère |
| `fgets()` | Lit une ligne |
| `fputs()` | Écrit une ligne |
| `fscanf()` | Lecture formatée |
| `fprintf()` | Écriture formatée |
| `fseek()` | Positionne le curseur |
| `ftell()` | Donne la position courante |
| `rewind()` | Replace le curseur au début |

---

## 6. Exemple complet

```c
#include <stdio.h>

int main() {
    FILE *f = fopen("notes.txt", "w");
    if (f == NULL) {
        printf("Erreur d’ouverture\n");
        return 1;
    }

    int notes[3] = {12, 15, 18};
    for (int i = 0; i < 3; i++) {
        fprintf(f, "Note %d = %d\n", i + 1, notes[i]);
    }
    fclose(f);

    f = fopen("notes.txt", "r");
    char ligne[50];
    while (fgets(ligne, 50, f) != NULL) {
        printf("%s", ligne);
    }
    fclose(f);

    return 0;
}
```

---

## 7. Erreurs et précautions

- Toujours **fermer** les fichiers (`fclose`).  
- Vérifier les **valeurs de retour** des fonctions (`NULL`, `EOF`).  
- Ne pas oublier d’utiliser les bons **modes d’ouverture**.  
- Utiliser des **tailles de buffer suffisantes** pour les chaînes.  

---

## 8. Exemple avec structure

```c
#include <stdio.h>

typedef struct {
    char nom[20];
    int age;
} Personne;

int main() {
    FILE *f = fopen("personnes.bin", "wb");
    Personne p = {"Alice", 25};
    fwrite(&p, sizeof(Personne), 1, f);
    fclose(f);

    f = fopen("personnes.bin", "rb");
    Personne q;
    fread(&q, sizeof(Personne), 1, f);
    printf("%s a %d ans\n", q.nom, q.age);
    fclose(f);

    return 0;
}
```

---

## Synthèse du chapitre

- Les fichiers sont manipulés via des **pointeurs de type `FILE*`**.  
- On utilise `fopen`, `fclose`, `fprintf`, `fscanf`, `fread`, `fwrite`.  
- Toujours **vérifier l’ouverture** du fichier et le **fermer** après utilisation.  
- Le C gère aussi bien les **fichiers texte** que **binaires**.  
- Les structures peuvent être **écrites et lues directement** dans un fichier binaire.

---

[[07_Structures_Typedef_Enums]] ← → [[09_Compilation_Projets]]
