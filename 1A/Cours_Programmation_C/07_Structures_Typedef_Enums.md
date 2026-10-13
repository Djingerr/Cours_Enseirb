# Chapitre 7 — Structures, typedef et énumérations  
[[00_Sommaire]]

---

## Introduction

Le C permet de définir **ses propres types de données** pour regrouper des informations hétérogènes.  
Les **structures**, **énumérations** et **typedef** sont des outils essentiels pour rendre le code plus clair et modulaire.

---

## 1. Les structures (`struct`)

Une **structure** regroupe plusieurs variables (appelées **champs**) sous un même nom.

### Exemple simple

```c
struct Point {
    int x;
    int y;
};
```

### Déclaration et utilisation

```c
struct Point p1;
p1.x = 10;
p1.y = 20;
printf("x = %d, y = %d\n", p1.x, p1.y);
```

---

### Initialisation

```c
struct Point p2 = {5, 8};
```

### Accès via pointeur

```c
struct Point *p = &p2;
printf("%d", p->x); // équivalent à (*p).x
```

💡 L’opérateur `->` est utilisé pour accéder aux champs via un pointeur.

---

## 2. Structures imbriquées

Une structure peut contenir une autre structure.

```c
struct Adresse {
    char ville[30];
    int code_postal;
};

struct Personne {
    char nom[30];
    int age;
    struct Adresse adr;
};
```

### Utilisation

```c
struct Personne p = {"Alice", 25, {"Paris", 75000}};
printf("%s habite à %s (%d)\n", p.nom, p.adr.ville, p.adr.code_postal);
```

---

## 3. Tableaux de structures

```c
struct Etudiant {
    char nom[20];
    int note;
};

struct Etudiant classe[3] = {
    {"Jean", 12},
    {"Marie", 15},
    {"Luc", 9}
};

for (int i = 0; i < 3; i++) {
    printf("%s : %d\n", classe[i].nom, classe[i].note);
}
```

---

## 4. Passage de structures à des fonctions

### Par valeur

```c
void afficher(struct Point p) {
    printf("(%d, %d)\n", p.x, p.y);
}
```

### Par adresse

```c
void deplacer(struct Point *p) {
    p->x += 1;
    p->y += 1;
}
```

---

## 5. Le mot-clé `typedef`

Le mot-clé **`typedef`** permet de créer un **alias de type** plus lisible.

```c
typedef struct Point {
    int x;
    int y;
} Point;

Point p = {3, 4};
```

💡 On peut désormais écrire `Point` au lieu de `struct Point`.

---

## 6. Énumérations (`enum`)

Une **énumération** permet de définir un ensemble de valeurs symboliques entières.

### Exemple

```c
enum Jour {Lundi, Mardi, Mercredi, Jeudi, Vendredi, Samedi, Dimanche};
enum Jour j = Mardi;
```

Par défaut, `Lundi = 0`, `Mardi = 1`, etc.

### Personnalisation

```c
enum Mois {Janvier = 1, Fevrier, Mars, Avril};
```

### Utilisation

```c
enum Jour j = Vendredi;
if (j == Vendredi) printf("Bon week-end !");
```

---

## 7. Unions (`union`)

Une **union** partage la même zone mémoire entre plusieurs champs.  
Elle permet d’économiser de la mémoire quand une seule valeur est utilisée à la fois.

### Exemple

```c
union Nombre {
    int entier;
    float reel;
};

union Nombre n;
n.entier = 5;
printf("%d\n", n.entier);
n.reel = 3.14; // écrase la valeur précédente
```

💡 Les unions sont souvent utilisées dans les protocoles ou les structures matérielles.

---

## 8. Structures, typedef et enums combinés

```c
typedef enum {HOMME, FEMME} Sexe;

typedef struct {
    char nom[30];
    int age;
    Sexe sexe;
} Personne;

int main() {
    Personne p = {"Alice", 28, FEMME};
    printf("%s a %d ans\n", p.nom, p.age);
}
```

---

## Synthèse du chapitre

- Les **structures** regroupent plusieurs champs sous un même type.  
- Les **typedef** rendent le code plus clair et concis.  
- Les **énumérations** remplacent les valeurs numériques par des symboles.  
- Les **unions** partagent une même zone mémoire.  
- Ces outils permettent de créer des **types personnalisés** pour structurer les programmes.

---

[[06_Pointeurs_et_Memoire]] ← → [[08_Fichiers_IO]]
