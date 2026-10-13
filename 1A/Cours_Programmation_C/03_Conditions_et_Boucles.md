# Chapitre 3 — Conditions et boucles  
[[00_Sommaire]]

---

## Introduction

Les **structures de contrôle** permettent de modifier l’ordre d’exécution des instructions dans un programme.  
Elles sont essentielles pour **prendre des décisions** (conditions) et **répéter des actions** (boucles).

---

## 1. Les conditions

### 1.1 L’instruction `if`

```c
if (condition) {
    // instructions si condition vraie
}
```

Exemple :
```c
int age = 18;
if (age >= 18) {
    printf("Majeur\n");
}
```

### 1.2 `if ... else`

```c
if (age >= 18) {
    printf("Majeur\n");
} else {
    printf("Mineur\n");
}
```

### 1.3 `if ... else if ... else`

```c
if (note >= 16) {
    printf("Très bien\n");
} else if (note >= 10) {
    printf("Moyen\n");
} else {
    printf("Insuffisant\n");
}
```

---

## 2. Opérateurs relationnels et logiques

### 2.1 Opérateurs relationnels

| Opérateur | Signification |
|------------|----------------|
| `==` | Égal à |
| `!=` | Différent de |
| `<` | Inférieur à |
| `>` | Supérieur à |
| `<=` | Inférieur ou égal à |
| `>=` | Supérieur ou égal à |

### 2.2 Opérateurs logiques

| Opérateur | Signification | Exemple |
|------------|----------------|----------|
| `&&` | ET logique | `a > 0 && b > 0` |
| `||` | OU logique | `a == 0 || b == 0` |
| `!` | NON logique | `!a` |

---

## 3. Le `switch`

Le `switch` simplifie les tests multiples sur une même variable.

```c
int choix = 2;
switch (choix) {
    case 1:
        printf("Option 1\n");
        break;
    case 2:
        printf("Option 2\n");
        break;
    default:
        printf("Option inconnue\n");
}
```

💡 Toujours mettre `break;` pour éviter d’exécuter les autres cas.

---

## 4. Les boucles

### 4.1 La boucle `while`

```c
int i = 0;
while (i < 5) {
    printf("%d\n", i);
    i++;
}
```

➡️ Exécute le bloc **tant que la condition est vraie**.

---

### 4.2 La boucle `do ... while`

```c
int i = 0;
do {
    printf("%d\n", i);
    i++;
} while (i < 5);
```

➡️ La boucle est exécutée **au moins une fois**, même si la condition est fausse au départ.

---

### 4.3 La boucle `for`

```c
for (int i = 0; i < 5; i++) {
    printf("%d\n", i);
}
```

Structure générale :
```c
for (initialisation; condition; incrément) {
    // instructions
}
```

---

### 4.4 Boucles imbriquées

```c
for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
        printf("%d,%d\n", i, j);
    }
}
```

💡 Permet de parcourir des tableaux à plusieurs dimensions.

---

## 5. Interruption de boucle

### 5.1 `break`

Met fin immédiatement à la boucle.

```c
for (int i = 0; i < 10; i++) {
    if (i == 5) break;
    printf("%d\n", i);
}
```

### 5.2 `continue`

Passe à l’itération suivante sans exécuter la suite du bloc.

```c
for (int i = 0; i < 10; i++) {
    if (i % 2 == 0) continue;
    printf("%d\n", i); // affiche seulement les impairs
}
```

---

## 6. Exemples pratiques

### 6.1 Calcul de la somme des entiers

```c
int somme = 0;
for (int i = 1; i <= 10; i++) {
    somme += i;
}
printf("Somme = %d\n", somme);
```

### 6.2 Boucle infinie

```c
while (1) {
    // traitement en continu
}
```

⚠️ Une boucle infinie doit comporter une **condition de sortie** (souvent via `break`).

---

## 7. Instructions composées

Plusieurs instructions peuvent être regroupées dans un bloc `{ ... }`.  
Cela est utile pour les conditions ou boucles contenant plusieurs lignes.

Exemple :
```c
if (x > 0) {
    printf("Positif\n");
    printf("Fin du test\n");
}
```

---

## Synthèse du chapitre

- Les **conditions** (`if`, `else`, `switch`) permettent de **prendre des décisions**.  
- Les **boucles** (`while`, `for`, `do...while`) permettent de **répéter des actions**.  
- Les instructions **`break`** et **`continue`** contrôlent la boucle.  
- Les **blocs `{}`** regroupent plusieurs instructions.  
- Bien utiliser les conditions évite des erreurs logiques ou des boucles infinies.

---

[[02_Variables_et_Types]] ← → [[04_Fonctions]]
