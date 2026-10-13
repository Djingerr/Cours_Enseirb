---
tags: [PG220, java, POO, chapitre4]
module: PG220
chapitre: 4
slides: 26, 112-116
---

# Chapitre 4 (suite) — Classes imbriquées, packages et classes utilitaires

← [[Fiche_PG220_06_Exceptions|Exceptions]] · [[PG220_00_Sommaire|Sommaire]] · Suivant → [[Fiche_PG220_08_Threads|Threads]]

> [!abstract] Ce que tu dois retenir
> - 4 sortes de classes imbriquées : **interne** (liée à une instance), **statique** (indépendante), **locale** (dans une méthode), **anonyme** (sans nom, créée en une expression).
> - Une classe interne non statique se crée avec `outer.new Inner()`.
> - Les **packages** organisent le code, évitent les conflits de noms et contrôlent l'accès (visibilité par défaut).
> - `java.lang` est importé automatiquement (`String`, `Math`, `Integer`, `System`…).

> [!info] Note sur cette fiche
> Les slides annoncent « packages et organisation du code » et « quelques classes utilitaires » au chapitre 4 sans les détailler. Les sections 2 et 3 complètent donc le cours avec ce qui sert le plus en TP et en projet.

---

## 1. Les classes imbriquées (*nested classes*)

Ce sont des classes **définies à l'intérieur d'autres classes**. Elles servent à **regrouper** des classes logiquement liées et à **renforcer l'encapsulation** (une classe d'aide n'a pas à être visible de tout le projet).

| Type | Déclarée | `static` ? | Accès à la classe englobante | Création |
|---|---|:-:|---|---|
| **Interne** (*inner*) | dans la classe | non | **tous** les membres, même privés, de l'instance englobante | `outer.new Inner()` |
| **Statique** (*static nested*) | dans la classe | oui | seulement les membres **statiques** (sans instance) | `new Outer.Nested()` |
| **Locale** (*local*) | dans une méthode / un bloc | non | membres de la classe + variables locales *effectivement finales* | `new Local()` dans le bloc |
| **Anonyme** (*anonymous*) | dans une expression | non | idem locale | déclarée et instanciée d'un coup |

### 1.1 Classe interne

Chaque objet `InnerClass` est **attaché** à un objet `OuterClass` et peut lire ses membres, même privés.

```java
public class OuterClass {
    private String message = "Hello from OuterClass!";

    public class InnerClass {
        public void display() {
            System.out.println(message);      // accès au membre privé de l'objet englobant
        }
    }

    public static void main(String[] args) {
        OuterClass outer = new OuterClass();
        OuterClass.InnerClass inner = outer.new InnerClass();   // ⚠️ syntaxe particulière
        inner.display();                                        // Hello from OuterClass!
    }
}
```

> [!tip] Pourquoi `outer.new` ?
> Une classe interne a besoin d'un objet englobant auquel se rattacher (c'est de là que vient `message`). `outer.new InnerClass()` dit : « crée un `InnerClass` rattaché à **cet** `outer` ».

### 1.2 Classe imbriquée statique

Elle n'est rattachée à **aucun** objet englobant. Elle se comporte comme une classe normale rangée dans une autre.

```java
public class OuterClass {
    private static String message = "Hello from OuterClass!";

    public static class StaticNestedClass {
        public void display() {
            System.out.println(message);      // ✅ membre STATIQUE de la classe englobante
        }
    }

    public static void main(String[] args) {
        OuterClass.StaticNestedClass nested = new OuterClass.StaticNestedClass();  // pas besoin d'outer
        nested.display();
    }
}
```

Si `message` n'était pas `static`, `display()` ne pourrait pas y accéder directement : il n'y a pas d'objet `OuterClass` associé. Même logique que les méthodes statiques ([[Fiche_PG220_03_Static_Final_Relations#1. Les membres statiques|fiche 03]]).

### 1.3 Classe locale

Définie **dans un bloc** (méthode, constructeur), visible **uniquement** dans ce bloc.

```java
public class OuterClass {
    public void displayMessage() {
        class LocalClass {
            public void print() {
                System.out.println("Hello from LocalClass!");
            }
        }
        LocalClass local = new LocalClass();
        local.print();
    }
    // LocalClass n'existe pas ici
}
```

> [!note] Capture de variables
> Une classe locale (ou anonyme, ou une lambda) peut lire les variables locales de la méthode **seulement si elles sont effectivement finales** (jamais réaffectées après leur initialisation).

### 1.4 Classe anonyme

Une classe **sans nom**, **définie et instanciée en une seule expression**. Utilisée pour une implémentation « jetable » d'une interface ou d'une classe, avec **une seule instance**.

```java
interface Greeting { void sayHello(); }

public class OuterClass {
    public void greet() {
        Greeting greeting = new Greeting() {          // « un objet d'une classe sans nom qui implémente Greeting »
            @Override
            public void sayHello() {
                System.out.println("Hello from Anonymous Class!");
            }
        };                                            // ⚠️ point-virgule : c'est une instruction d'affectation
        greeting.sayHello();
    }
}
```

Tu l'as déjà croisée avec `Comparator` ([[Fiche_PG220_05_Interfaces_Abstraites_Tri|fiche 05, section Comparator]]) et tu la reverras avec `Runnable` ([[Fiche_PG220_08_Threads|fiche 08]]).

> [!tip] Classe anonyme → lambda
> Quand l'interface n'a **qu'une seule méthode abstraite** (interface fonctionnelle : `Greeting`, `Runnable`, `Comparator`…), une lambda remplace avantageusement la classe anonyme :
> ```java
> Greeting greeting = () -> System.out.println("Hello from a lambda!");
> ```

---

## 2. Packages et organisation du code

### Pourquoi des packages ?

- **Organiser** un grand projet en modules (modèle, interface graphique, réseau…).
- **Éviter les conflits de noms** : `java.util.Date` et `java.sql.Date` coexistent.
- **Contrôler l'accès** : la visibilité par défaut (sans modificateur) = « visible dans le package ».

### Déclarer

```java
package fr.bordeauxinp.pg220.banque;   // 1re instruction du fichier, une seule par fichier

public class Compte { ... }
```

- Convention : **minuscules**, nom de domaine **inversé** (`fr.bordeauxinp...`).
- Sans `package`, la classe est dans le **package par défaut** (acceptable pour un petit test, à éviter en projet).
- **L'arborescence des dossiers doit refléter le package** :

```text
projet/
└── src/
    └── fr/bordeauxinp/pg220/
        ├── banque/
        │   ├── Compte.java        → package fr.bordeauxinp.pg220.banque;
        │   └── Banque.java
        └── app/
            └── Main.java          → package fr.bordeauxinp.pg220.app;
```

### Importer

```java
package fr.bordeauxinp.pg220.app;

import fr.bordeauxinp.pg220.banque.Compte;   // une classe précise
import java.util.*;                          // toutes les classes de java.util (pas ses sous-packages !)
import static java.lang.Math.PI;             // import statique : on écrira PI au lieu de Math.PI

public class Main {
    public static void main(String[] args) {
        Compte c = new Compte();
        List<String> l = new ArrayList<>();
        java.sql.Date d = null;              // nom complet : pas besoin d'import
        System.out.println(PI);
    }
}
```

> [!note] Rien à importer pour `java.lang`
> `String`, `Math`, `Integer`, `System`, `Object`, `Thread`, les exceptions de base… sont dans `java.lang`, importé automatiquement.

### Compiler et exécuter un projet en packages

```bash
# Depuis projet/ : compiler toutes les sources vers le dossier out/
javac -d out $(find src -name "*.java")

# Exécuter : -cp indique où chercher les .class, puis le nom COMPLET de la classe
java -cp out fr.bordeauxinp.pg220.app.Main
```

---

## 3. Quelques classes utilitaires de la bibliothèque Java

### `String` : texte immuable

Un objet `String` **ne change jamais**. Les méthodes qui semblent le modifier renvoient une **nouvelle** chaîne.

```java
String s = "Bonjour";
s.toUpperCase();                 // ⚠️ ne modifie pas s !
s = s.toUpperCase();             // ✅ on récupère le résultat → "BONJOUR"
```

| Méthode | Exemple | Résultat |
|---|---|---|
| `length()` | `"Java".length()` | `4` |
| `charAt(i)` | `"Java".charAt(0)` | `'J'` |
| `substring(a, b)` | `"Bonjour".substring(0, 3)` | `"Bon"` (b exclu) |
| `indexOf(x)` | `"Bonjour".indexOf("jour")` | `3` (ou `-1` si absent) |
| `contains(x)` | `"Bonjour".contains("on")` | `true` |
| `equals` / `equalsIgnoreCase` | `"a".equalsIgnoreCase("A")` | `true` |
| `compareTo` | `"Adam".compareTo("Zoé")` | négatif |
| `split(regex)` | `"a,b,c".split(",")` | `["a","b","c"]` |
| `trim()` / `strip()` | `"  x ".strip()` | `"x"` |
| `isEmpty()` | `"".isEmpty()` | `true` |
| `String.valueOf(x)` | `String.valueOf(42)` | `"42"` |

> [!warning] Concaténer dans une boucle
> `s += ...` dans une boucle recrée une nouvelle `String` à chaque tour. Pour construire un texte morceau par morceau, utilise `StringBuilder` :
> ```java
> StringBuilder sb = new StringBuilder();
> for (int i = 0; i < 5; i++) {
>     sb.append(i).append(' ');
> }
> String resultat = sb.toString();   // "0 1 2 3 4 "
> ```

### `Math` : fonctions mathématiques (toutes statiques)

```java
Math.abs(-3);        // 3
Math.max(4, 9);      // 9
Math.pow(2, 10);     // 1024.0 (double)
Math.sqrt(16);       // 4.0
Math.round(2.6);     // 3
Math.random();       // double dans [0, 1[
Math.PI;             // 3.14159...
```

### Classes enveloppes (*wrappers*)

Chaque primitif a sa classe : `int` → `Integer`, `double` → `Double`, `char` → `Character`, `boolean` → `Boolean`… Elles servent à mettre des primitifs dans des collections et offrent des méthodes utiles.

```java
int n = Integer.parseInt("42");          // String → int (NumberFormatException si invalide)
double d = Double.parseDouble("3.14");
Integer.MAX_VALUE;                       // 2147483647
Integer.compare(3, 7);                   // négatif

List<Integer> l = new ArrayList<>();
l.add(5);                                // autoboxing   : int → Integer automatiquement
int x = l.get(0);                        // unboxing     : Integer → int automatiquement
```

> [!danger] Piège : `==` sur des `Integer`
> ```java
> Integer a = 127, b = 127;
> Integer c = 128, e = 128;
> System.out.println(a == b);       // true   (Java réutilise les petits Integer entre -128 et 127)
> System.out.println(c == e);       // false  (deux objets différents !)
> System.out.println(c.equals(e));  // true
> ```
> Même règle que pour `String` : **objets → `equals`**. Et attention, déballer un `Integer` qui vaut `null` lève une `NullPointerException`.

### `Arrays` : outils pour tableaux

```java
int[] t = {5, 2, 9};
System.out.println(t);                    // [I@1b6d3586  ← adresse, pas le contenu !
System.out.println(Arrays.toString(t));   // [5, 2, 9]
Arrays.sort(t);                           // [2, 5, 9]
Arrays.fill(t, 0);                        // [0, 0, 0]
int[] copie = Arrays.copyOf(t, 5);        // [0, 0, 0, 0, 0]
List<String> l = Arrays.asList("a", "b"); // tableau → liste (taille fixe)
```

### `Collections` : outils pour collections

```java
Collections.sort(liste);                  // ordre naturel (Comparable)
Collections.sort(liste, comparateur);     // ordre donné (Comparator)
Collections.reverse(liste);
Collections.max(liste);
Collections.shuffle(liste);
```

### `ArrayList` et `HashMap` : les deux collections du quotidien

```java
List<String> noms = new ArrayList<>();
noms.add("Coco"); noms.add("Lina");
noms.get(0);          // "Coco"
noms.size();          // 2
noms.contains("Tom"); // false

Map<String, Integer> notes = new HashMap<>();   // clé → valeur
notes.put("Coco", 16);
notes.put("Lina", 14);
notes.get("Coco");                    // 16
notes.getOrDefault("Tom", 0);         // 0
notes.containsKey("Lina");            // true
for (Map.Entry<String, Integer> en : notes.entrySet()) {
    System.out.println(en.getKey() + " → " + en.getValue());
}
```

### `Objects` : aide pour `equals`, `hashCode` et `null`

```java
Objects.equals(a, b);         // comme a.equals(b) mais sans NPE si a est null
Objects.hash(id, nom);        // pour écrire hashCode() facilement
Objects.requireNonNull(x);    // lève NullPointerException tout de suite si x est null
```

### `Scanner` : lire au clavier (pratique en TP)

```java
import java.util.Scanner;

Scanner sc = new Scanner(System.in);
System.out.print("Ton âge ? ");
int age = sc.nextInt();
sc.nextLine();                // consomme le retour à la ligne restant
System.out.print("Ton nom ? ");
String nom = sc.nextLine();
```

---

## 🔁 Teste-toi

> [!question]- Comment instancier la classe interne (non statique) `Inner` de `Outer` depuis l'extérieur ?
> `Outer o = new Outer(); Outer.Inner i = o.new Inner();`

> [!question]- Une classe imbriquée statique peut-elle lire un attribut d'instance privé de la classe englobante ?
> Pas directement : elle n'est liée à aucune instance. Elle peut en revanche lire les membres **statiques**, même privés, ou ceux d'une instance qu'on lui fournit explicitement.

> [!question]- Qu'est-ce qu'une classe anonyme ? Quand la remplacer par une lambda ?
> Une classe sans nom déclarée et instanciée en une expression. On peut la remplacer par une lambda quand elle implémente une interface à **une seule** méthode abstraite.

> [!question]- Quel package n'a jamais besoin d'être importé ?
> `java.lang`.

> [!question]- `import java.util.*;` importe-t-il `java.util.concurrent.atomic.AtomicInteger` ?
> **Non**, `*` n'importe pas les sous-packages.

> [!question]- `String s = "abc"; s.toUpperCase(); System.out.println(s);` affiche ?
> `abc` : les `String` sont immuables, le résultat de `toUpperCase()` a été perdu.

> [!question]- Comment afficher le contenu d'un tableau `int[] t` ?
> `System.out.println(Arrays.toString(t));` (afficher `t` directement donne une adresse du type `[I@...`).
