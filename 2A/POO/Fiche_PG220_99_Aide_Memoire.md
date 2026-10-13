---
tags: [PG220, java, POO, aide-memoire]
module: PG220
---

# PG220 — Aide-mémoire (révision express)

← [[PG220_00_Sommaire|Sommaire]] · [[Exercices_PG220_QCM|QCM]]

> [!tip] À relire la veille du QCM
> Tout ce qui est ici est détaillé dans les fiches. Si une ligne te semble floue, suis le lien.

---

## Les mots-clés en une ligne

| Mot-clé | Effet | Fiche |
|---|---|---|
| `new` | crée un objet sur le tas, appelle le constructeur, renvoie la référence | [[Fiche_PG220_02_Classes_Objets\|02]] |
| `this` | l'objet courant ; `this(...)` = autre constructeur de la même classe (1re ligne) | [[Fiche_PG220_02_Classes_Objets\|02]] |
| `static` | appartient à la classe, partagé, pas de `this` | [[Fiche_PG220_03_Static_Final_Relations\|03]] |
| `final` | classe non héritable / méthode non redéfinissable / variable affectée une fois | [[Fiche_PG220_03_Static_Final_Relations\|03]] |
| `extends` | hérite d'**une** classe (ou interface → interfaces) | [[Fiche_PG220_04_Heritage_Polymorphisme\|04]] |
| `super` | `super(...)` = constructeur parent (1re ligne) ; `super.m()` = version parente | [[Fiche_PG220_04_Heritage_Polymorphisme\|04]] |
| `@Override` | fait vérifier la redéfinition par le compilateur | [[Fiche_PG220_04_Heritage_Polymorphisme\|04]] |
| `instanceof` | teste le type dynamique ; `null instanceof X` → `false` | [[Fiche_PG220_04_Heritage_Polymorphisme\|04]] |
| `abstract` | classe non instanciable / méthode sans corps | [[Fiche_PG220_05_Interfaces_Abstraites_Tri\|05]] |
| `implements` | réalise **une ou plusieurs** interfaces | [[Fiche_PG220_05_Interfaces_Abstraites_Tri\|05]] |
| `default` | méthode d'interface avec corps (Java 8+) | [[Fiche_PG220_05_Interfaces_Abstraites_Tri\|05]] |
| `try/catch/finally` | tenter / traiter / toujours exécuter | [[Fiche_PG220_06_Exceptions\|06]] |
| `throw` | **lance** une exception (corps) | [[Fiche_PG220_06_Exceptions\|06]] |
| `throws` | **déclare** des exceptions (signature) | [[Fiche_PG220_06_Exceptions\|06]] |
| `synchronized` | un seul thread à la fois sur le verrou de l'objet | [[Fiche_PG220_08_Threads\|08]] |

## Visibilité

| | classe | package | sous-classe | partout |
|---|:-:|:-:|:-:|:-:|
| `private` | ✅ | | | |
| *(défaut)* | ✅ | ✅ | | |
| `protected` | ✅ | ✅ | ✅ | |
| `public` | ✅ | ✅ | ✅ | ✅ |

UML : `-` private, `~` package, `#` protected, `+` public.

## Surcharge vs redéfinition

| | Surcharge | Redéfinition |
|---|---|---|
| Paramètres | **différents** | **identiques** |
| Retour | libre (mais ne suffit pas à distinguer) | identique ou sous-type |
| Visibilité | libre | pas plus restrictive |
| Résolution | **compilation**, sur le type **statique** des arguments | **exécution**, sur le type **dynamique** de l'objet |
| Polymorphisme | statique | dynamique |

## Type statique / dynamique

```java
Employee e = new Manager();   // statique = Employee, dynamique = Manager
e.toString();                 // compile (existe dans Employee), exécute Manager.toString()
e.getDepartment();            // ❌ ne compile pas
((Manager) e).getDepartment() // ✅ (ClassCastException si e n'est pas un Manager)
```

## Classe / abstraite / interface

| | Interface | Abstraite | Classe |
|---|:-:|:-:|:-:|
| Méthodes abstraites | ✅ | ✅ | ❌ |
| Méthodes avec corps | `default`/`static` | ✅ | ✅ |
| Attributs | constantes seulement | ✅ | ✅ |
| Constructeur | ❌ | ✅ | ✅ |
| `new` | ❌ | ❌ | ✅ |
| Combien par classe | plusieurs | une | une |

## Comparable / Comparator

| | `Comparable<T>` | `Comparator<T>` |
|---|---|---|
| Méthode | `compareTo(T o)` | `compare(T a, T b)` |
| Nombre d'ordres | 1 (naturel) | illimité |
| Où | dans la classe | à l'extérieur (anonyme, lambda) |

Signe du résultat : **négatif** = avant, **0** = équivalent, **positif** = après. Utiliser `Integer.compare`, pas `a - b`.

`==` → même objet · `equals` → même valeur (+ redéfinir `hashCode`) · `compareTo` → ordre.

## Exceptions

```text
Throwable
├── Error                      (ne pas attraper)
└── Exception                  ← VÉRIFIÉES : try/catch ou throws obligatoire
    ├── IOException, SQLException, ...
    └── RuntimeException       ← NON VÉRIFIÉES
        └── NullPointerException, ArithmeticException, ArrayIndexOutOfBounds..., IllegalArgument..., NumberFormat...
```

- `catch` du plus **spécifique** au plus **général**.
- `finally` s'exécute toujours (même après `return`).
- Redéfinition : mêmes exceptions vérifiées, des sous-classes, ou aucune. Jamais plus, jamais plus large.
- Exception perso : `extends Exception` (vérifiée) ou `extends RuntimeException` (non vérifiée).

## Threads

| Action | Code |
|---|---|
| Créer (recommandé) | `new Thread(runnable)` ou `new Thread(() -> ...)` |
| Lancer | `t.start()` (jamais `t.run()`) |
| Pause du thread **courant** | `Thread.sleep(ms)` (InterruptedException) |
| Attendre la fin de `t` | `t.join()` (InterruptedException) |
| Demander l'arrêt | `t.interrupt()` (drapeau, pas un arrêt forcé) |
| Priorités | 1 (MIN), 5 (NORM), 10 (MAX) — indicatives |
| Compteur partagé sûr | `synchronized` ou `AtomicInteger.incrementAndGet()` |

États : New → Runnable ⇄ Running → Terminated, avec Non-Runnable (bloqué) entre Running et Runnable.

Interblocage = verrous pris dans des ordres différents → toujours le **même ordre**.

---

## 🪤 Les 15 pièges à connaître

1. Écrire un constructeur avec paramètres **supprime** le constructeur par défaut.
2. Un constructeur n'a **aucun** type de retour : `public void Date()` est une méthode.
3. Variables **locales** non initialisées → erreur de compilation ; attributs → 0/false/null.
4. Java passe **toujours par valeur** (pour un objet : la référence est copiée).
5. `x = x;` dans un constructeur n'initialise pas l'attribut : il faut `this.x = x;`.
6. `new Point[5]` crée **un** tableau de 5 `null`, aucun `Point`.
7. Méthode `static` → pas de `this`, pas d'accès direct aux attributs d'instance.
8. `final` sur une référence n'empêche pas de modifier l'objet.
9. `super(...)` / `this(...)` : **première ligne**. Si absent, `super()` implicite (erreur si le parent n'a pas de constructeur sans argument).
10. Redéfinir en **réduisant** la visibilité est interdit (y compris implémenter une méthode d'interface sans `public`).
11. La surcharge est choisie sur le type **statique** ; la redéfinition sur le type **dynamique**.
12. `==` sur des objets (`String`, `Integer`…) compare des références → utiliser `equals`.
13. `equals` redéfini sans `hashCode` → `HashSet`/`HashMap` incohérents.
14. `t.run()` n'est pas `t.start()` : pas de nouveau thread.
15. `count++` n'est pas atomique entre threads.

---

## ⚠️ Erreurs et imprécisions repérées dans les slides

| Slide | Ce qui est écrit | Ce qu'il faut retenir | Fiche |
|---|---|---|---|
| 17 | `d.day = 30; // no assignment` | Ne **compile pas** (`day` est `private`) | [[Fiche_PG220_02_Classes_Objets\|02]] |
| 41 | `new int[2][]` puis `tableau[2] = ...` | `ArrayIndexOutOfBoundsException` : il faut `new int[3][]` | [[Fiche_PG220_02_Classes_Objets\|02]] |
| 60 | « une méthode **surchargée** ne peut pas… » | Il s'agit d'une méthode **redéfinie** | [[Fiche_PG220_04_Heritage_Polymorphisme\|04]] |
| 65 | `for (Employee e : emps) e.toString()` sur 100 cases dont 3 remplies | `NullPointerException` dès la 4e case | [[Fiche_PG220_04_Heritage_Polymorphisme\|04]] |
| 67 | `a instanceof Date → false` | Vrai ici car `Animal` est une interface ; avec une classe sans lien, **erreur de compilation** | [[Fiche_PG220_04_Heritage_Polymorphisme\|04]] |
| 77 | `void eat()` sans `public` dans `Bear` | Ne **compile pas** : il faut `public void eat()` | [[Fiche_PG220_05_Interfaces_Abstraites_Tri\|05]] |
| 128-129 | `ForeverRunnable` + `interrupt()` | Le thread **ne s'arrête jamais** : le `catch` avale l'interruption | [[Fiche_PG220_08_Threads\|08]] |
| 133 | `synchronized(this){value++;} return value;` | La lecture pour le `return` est hors verrou → valeur renvoyée pas fiable | [[Fiche_PG220_08_Threads\|08]] |
