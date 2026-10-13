---
tags: [PG220, java, POO, exercices, QCM]
module: PG220
---

# PG220 — QCM d'entraînement

← [[PG220_00_Sommaire|Sommaire]] · Fiche express → [[Fiche_PG220_99_Aide_Memoire|Aide-mémoire]]

> [!info] Mode d'emploi
> - Le QCM compte pour **70 %** de la note : ces questions visent les pièges typiques (vocabulaire, « ça compile ? », « qu'affiche ce code ? »).
> - Les chapitres sont **volontairement mélangés** : ça force à reconnaître la notion en jeu, comme le jour de l'examen.
> - **Réponds d'abord, ouvre ensuite.** Note tes erreurs et relis la fiche indiquée.
> - Sauf mention « plusieurs réponses », une seule réponse est correcte.
> - Tous les codes ont été compilés et exécutés pour vérifier les réponses.

---

## Série 1 — Les fondamentaux

### Q1 · Compilation · [[Fiche_PG220_01_Intro_POO_Java|ch.1]]
Que produit la commande `javac Hello.java` ?

- A) Un exécutable natif pour le processeur
- B) Un fichier `Hello.class` contenant du bytecode
- C) Un fichier `Hello.jar`
- D) Rien, elle exécute directement le programme

> [!success]- Réponse
> **B.** `javac` compile vers du **bytecode**, exécuté ensuite par la JVM (`java Hello`).

### Q2 · Constructeurs · [[Fiche_PG220_02_Classes_Objets|ch.2]]
```java
public class Point {
    private int x, y;
    public Point(int x, int y) { this.x = x; this.y = y; }
}
// ailleurs :
Point p = new Point();
```
- A) Compile, `p` vaut (0, 0)
- B) Erreur de compilation
- C) Compile, mais `NullPointerException` à l'exécution
- D) Compile, `p` vaut `null`

> [!success]- Réponse
> **B.** Le constructeur par défaut n'est généré que si la classe n'a **aucun** constructeur. Ici il y en a un, donc `Point()` n'existe pas.

### Q3 · Valeurs par défaut · [[Fiche_PG220_02_Classes_Objets|ch.2]]
```java
class T { int a; boolean b; String s; }
T t = new T();
System.out.println(t.a + " " + t.b + " " + t.s);
```
- A) `0 false null`
- B) `0 false ""`
- C) Erreur de compilation : attributs non initialisés
- D) `null null null`

> [!success]- Réponse
> **A.** Les **attributs** reçoivent une valeur par défaut (`0`, `false`, `null`). Seules les **variables locales** doivent être initialisées avant usage.

### Q4 · Passage de paramètres · [[Fiche_PG220_02_Classes_Objets|ch.2]]
```java
static void echange(int a, int b) { int tmp = a; a = b; b = tmp; }

int x = 1, y = 2;
echange(x, y);
System.out.println(x + " " + y);
```
- A) `2 1`
- B) `1 2`
- C) Erreur de compilation
- D) `1 1`

> [!success]- Réponse
> **B.** Java passe **par valeur** : `a` et `b` sont des copies. Échanger les copies ne change rien pour l'appelant.

### Q5 · Vérifiées ou non · [[Fiche_PG220_06_Exceptions|ch.4]] — *plusieurs réponses*
Lesquelles sont des exceptions **vérifiées** (*checked*) ?

- A) `IOException`
- B) `NullPointerException`
- C) `FileNotFoundException`
- D) `ArithmeticException`
- E) `SQLException`

> [!success]- Réponse
> **A, C, E.** B et D héritent de `RuntimeException` → non vérifiées.

### Q6 · Interfaces · [[Fiche_PG220_05_Interfaces_Abstraites_Tri|ch.3]] — *plusieurs réponses*
Quelles affirmations sont vraies ?

- A) Une classe peut implémenter plusieurs interfaces
- B) Une interface peut être instanciée avec `new`
- C) Une interface peut étendre une classe
- D) Les méthodes abstraites d'une interface sont implicitement `public`
- E) Depuis Java 8, une interface peut contenir des méthodes `default` avec un corps

> [!success]- Réponse
> **A, D, E.** Une interface ne s'instancie pas (B) et ne peut étendre que d'autres interfaces (C).

### Q7 · Threads · [[Fiche_PG220_08_Threads|ch.5]]
Quelle méthode faut-il appeler pour que le code de `run()` s'exécute dans un **nouveau** thread ?

- A) `t.run()`
- B) `t.start()`
- C) `t.execute()`
- D) `t.join()`

> [!success]- Réponse
> **B.** `run()` appelé directement s'exécute dans le thread courant, sans parallélisme.

### Q8 · `final` · [[Fiche_PG220_03_Static_Final_Relations|ch.2]]
```java
final int[] t = {1, 2, 3};
t[0] = 9;          // ligne 1
t = new int[5];    // ligne 2
```
- A) Les deux lignes compilent
- B) Seule la ligne 1 compile
- C) Seule la ligne 2 compile
- D) Aucune ne compile

> [!success]- Réponse
> **B.** `final` bloque la **référence** (ligne 2 interdite), pas le **contenu** du tableau (ligne 1 permise).

### Q9 · Vocabulaire · [[Fiche_PG220_04_Heritage_Polymorphisme|ch.3]]
Deux méthodes de **même nom** et de **mêmes paramètres**, l'une dans une classe mère, l'autre dans une classe fille. C'est :

- A) une surcharge, résolue à la compilation
- B) une surcharge, résolue à l'exécution
- C) une redéfinition, résolue à la compilation
- D) une redéfinition, résolue à l'exécution

> [!success]- Réponse
> **D.** Redéfinition (*override*) = polymorphisme **dynamique**.

### Q10 · Relations UML · [[Fiche_PG220_03_Static_Final_Relations|ch.2]]
Une `Maison` crée ses `Piece` dans son constructeur ; si la maison disparaît, ses pièces aussi. Quelle relation ?

- A) Agrégation (losange vide)
- B) Composition (losange plein)
- C) Héritage
- D) Réalisation

> [!success]- Réponse
> **B.** La partie ne peut pas exister sans le tout : **composition**.

---

## Série 2 — Ça compile ?

Pour chaque extrait : **compile** ou **ne compile pas** ? Si ça compile, y a-t-il un problème à l'exécution ?

### Q11 · [[Fiche_PG220_05_Interfaces_Abstraites_Tri|ch.3]]
```java
interface Animal { void eat(); }
class Bear implements Animal {
    void eat() { System.out.println("miam"); }
}
```

> [!success]- Réponse
> **Ne compile pas.** `eat()` est implicitement `public` dans l'interface ; l'implémenter sans `public` réduit la visibilité. (C'est l'erreur de la slide 77.)

### Q12 · [[Fiche_PG220_04_Heritage_Polymorphisme|ch.3]]
```java
class Parent { Parent(String nom) { } }
class Enfant extends Parent {
    Enfant() { System.out.println("coucou"); }
}
```

> [!success]- Réponse
> **Ne compile pas.** Java insère `super()` en première ligne, mais `Parent()` sans argument n'existe pas. Il faut écrire `super("...")`.

### Q13 · [[Fiche_PG220_06_Exceptions|ch.4]]
```java
try {
    int n = Integer.parseInt("abc");
} catch (Exception e) {
    System.out.println("erreur");
} catch (NumberFormatException e) {
    System.out.println("pas un nombre");
}
```

> [!success]- Réponse
> **Ne compile pas.** `NumberFormatException` est déjà attrapée par `catch (Exception e)` : le second bloc est inatteignable. Ordre correct : du plus spécifique au plus général.

### Q14 · [[Fiche_PG220_04_Heritage_Polymorphisme|ch.3]]
```java
class A { public void f() { } }
class B extends A { protected void f() { } }
```

> [!success]- Réponse
> **Ne compile pas.** Une redéfinition ne peut pas **réduire** la visibilité (`public` → `protected`).

### Q15 · [[Fiche_PG220_04_Heritage_Polymorphisme|ch.3]]
```java
Employee e = new Manager("Ana", 3000, null, "ventes");
System.out.println(e.getDepartment());   // getDepartment() n'existe que dans Manager
```

> [!success]- Réponse
> **Ne compile pas.** Le compilateur ne regarde que le **type statique** `Employee`. Il faut `((Manager) e).getDepartment()`, idéalement après un `instanceof`.

### Q16 · [[Fiche_PG220_05_Interfaces_Abstraites_Tri|ch.3]]
```java
abstract class Shape { abstract double area(); }
class Square extends Shape { double c = 2; double area() { return c * c; } }

Shape s1 = new Square();   // ligne 1
Shape s2 = new Shape();    // ligne 2
```

> [!success]- Réponse
> Ligne 1 : **compile** (type statique abstrait, objet concret). Ligne 2 : **ne compile pas** (classe abstraite non instanciable).

### Q17 · [[Fiche_PG220_02_Classes_Objets|ch.2]]
```java
int[] t = new int[3];
System.out.println(t[3]);
```

> [!success]- Réponse
> **Compile**, mais lève `ArrayIndexOutOfBoundsException` à l'exécution (indices valides : 0 à 2).

### Q18 · [[Fiche_PG220_02_Classes_Objets|ch.2]]
```java
void calcul() {
    int total;
    total++;
}
```

> [!success]- Réponse
> **Ne compile pas.** `total` est une variable **locale** non initialisée : `variable total might not have been initialized`.

### Q19 · [[Fiche_PG220_04_Heritage_Polymorphisme|ch.3]]
```java
class Calc {
    int  somme(int a, int b) { return a + b; }
    long somme(int a, int b) { return a + b; }
}
```

> [!success]- Réponse
> **Ne compile pas.** Même signature (nom + types des paramètres). Le type de retour seul ne suffit pas à surcharger.

### Q20 · [[Fiche_PG220_06_Exceptions|ch.4]]
```java
class Lecteur { void lire() throws IOException { } }
class LecteurReseau extends Lecteur {
    @Override void lire() throws Exception { }
}
```

> [!success]- Réponse
> **Ne compile pas.** Une redéfinition ne peut pas lancer une **superclasse** des exceptions vérifiées du parent. `IOException`, une sous-classe, aucune exception ou une non vérifiée seraient acceptées.

### Q21 · [[Fiche_PG220_03_Static_Final_Relations|ch.2]]
```java
public class Compteur {
    private int valeur;
    public static void reset() { valeur = 0; }
}
```

> [!success]- Réponse
> **Ne compile pas.** Une méthode `static` n'a pas de `this` : `non-static variable valeur cannot be referenced from a static context`.

### Q22 · [[Fiche_PG220_08_Threads|ch.5]]
```java
public void attendre() {
    Thread.sleep(500);
}
```

> [!success]- Réponse
> **Ne compile pas.** `sleep` lève `InterruptedException`, une exception **vérifiée** : il faut un `try/catch` ou `throws InterruptedException`.

---

## Série 3 — Qu'affiche ce code ?

### Q23 · [[Fiche_PG220_03_Static_Final_Relations|ch.2]]
```java
class C {
    static int n = 0;
    int id;
    C() { n++; id = n; }
}

C a = new C(); C b = new C(); C c = new C();
System.out.println(a.id + " " + C.n);
```

> [!success]- Réponse
> `1 3`. `n` est **partagé** (3 après trois constructions), `id` est propre à chaque objet (`a` a été créé en premier).

### Q24 · [[Fiche_PG220_04_Heritage_Polymorphisme|ch.3]]
```java
class A {
    String nom() { return "A"; }
    void affiche() { System.out.println(nom()); }
}
class B extends A {
    String nom() { return "B"; }
}

A x = new B();
x.affiche();
```

> [!success]- Réponse
> `B`. `affiche()` est héritée de `A`, mais l'appel `nom()` à l'intérieur utilise la **liaison dynamique** : l'objet réel est un `B`, donc `B.nom()`.

### Q25 · [[Fiche_PG220_04_Heritage_Polymorphisme|ch.3]] — le piège surcharge/redéfinition
```java
class A { }
class B extends A { }

static void f(A a) { System.out.println("fA"); }
static void f(B b) { System.out.println("fB"); }

A x = new B();
f(x);
```

> [!success]- Réponse
> `fA`. La **surcharge** est résolue **à la compilation**, d'après le **type statique** de l'argument (`A`). La liaison dynamique ne concerne que la **redéfinition** (l'objet sur lequel on appelle la méthode), pas le choix entre surcharges.

### Q26 · [[Fiche_PG220_04_Heritage_Polymorphisme|ch.3]]
```java
class P { P() { System.out.print("P "); } }
class E extends P {
    E()      { System.out.print("E1 "); }
    E(int x) { this(); System.out.print("E2 "); }
}

new E(5);
```

> [!success]- Réponse
> `P E1 E2 `. `E(int)` appelle `this()` → `E()` commence par le `super()` implicite → `P()` s'affiche d'abord, puis `E1`, puis on revient finir `E(int)` avec `E2`.

### Q27 · [[Fiche_PG220_06_Exceptions|ch.4]]
```java
try {
    System.out.print("1 ");
    int x = 5 / 0;
    System.out.print("2 ");
} catch (ArithmeticException e) {
    System.out.print("3 ");
} finally {
    System.out.print("4 ");
}
System.out.print("5");
```

> [!success]- Réponse
> `1 3 4 5`. L'exception saute le reste du `try` (pas de `2`), le `catch` s'exécute, puis `finally`, puis le programme continue.

### Q28 · [[Fiche_PG220_06_Exceptions|ch.4]]
```java
static void g() {
    try {
        throw new RuntimeException("X");
    } finally {
        System.out.print("F ");
    }
}

try {
    g();
    System.out.print("A ");
} catch (RuntimeException e) {
    System.out.print(e.getMessage() + " ");
}
System.out.print("FIN");
```

> [!success]- Réponse
> `F X FIN`. `g()` n'attrape pas l'exception mais exécute son `finally` avant de la laisser **remonter**. L'appelant l'attrape (on saute `A `), puis continue.

### Q29 · [[Fiche_PG220_05_Interfaces_Abstraites_Tri|ch.3]]
```java
String a = "java";
String b = new String("java");
String c = b;
System.out.println((a == b) + " " + a.equals(b) + " " + (b == c));
```

> [!success]- Réponse
> `false true true`. `a` et `b` sont deux objets distincts de même contenu ; `b` et `c` sont la même référence.

### Q30 · [[Fiche_PG220_02_Classes_Objets|ch.2]]
```java
int[] t = {1, 2, 3};
int[] u = t;
u[0] = 9;
System.out.println(t[0]);
```

> [!success]- Réponse
> `9`. `u = t` copie la **référence** : un seul tableau, deux noms.

### Q31 · [[Fiche_PG220_05_Interfaces_Abstraites_Tri|ch.3]]
```java
List<String> l = new ArrayList<>(List.of("poire", "kiwi", "banane"));
l.sort((x, y) -> x.length() - y.length());
System.out.println(l);
```

> [!success]- Réponse
> `[kiwi, poire, banane]`. Le comparateur trie par longueur croissante (4, 5, 6).

### Q32 · [[Fiche_PG220_05_Interfaces_Abstraites_Tri|ch.3]]
```java
class P { int x; P(int x) { this.x = x; } }   // equals/hashCode NON redéfinis

Set<P> s = new HashSet<>();
s.add(new P(1));
s.add(new P(1));
System.out.println(s.size());
```

> [!success]- Réponse
> `2`. Sans redéfinition, `equals` hérité d'`Object` compare les **références** : deux `new` = deux objets différents. Pour que ce soit `1`, il faut redéfinir `equals` **et** `hashCode`.

### Q33 · [[Fiche_PG220_08_Threads|ch.5]]
```java
Thread t = new Thread(() -> System.out.print("T "));
t.start();
t.join();
System.out.print("M");
```

> [!success]- Réponse
> `T M`, **toujours**. `join()` oblige `main` à attendre la fin de `t` avant d'afficher `M`. Sans le `join`, l'ordre serait imprévisible.

### Q34 · [[Fiche_PG220_04_Heritage_Polymorphisme|ch.3]]
```java
Employee e = null;
System.out.println(e instanceof Employee);
```

> [!success]- Réponse
> `false`. `null instanceof X` vaut toujours `false`, sans exception.

---

## 📊 Bilan

| Score | Que faire |
|---|---|
| 30–34 | Relis juste l'[[Fiche_PG220_99_Aide_Memoire\|aide-mémoire]] la veille |
| 22–29 | Reprends les fiches des questions ratées, section « Teste-toi » comprise |
| < 22 | Relis les fiches dans l'ordre du [[PG220_00_Sommaire\|sommaire]], puis refais ce QCM dans quelques jours |
