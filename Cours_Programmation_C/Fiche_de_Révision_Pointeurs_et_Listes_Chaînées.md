
# Fiche de Révision : Pointeurs et Listes Chaînées en C

Cette fiche synthétise les concepts clés pour manipuler la mémoire et les structures dynamiques.

## 1. Les Pointeurs : Concepts Fondamentaux
Les pointeurs sont des variables qui stockent l'**adresse mémoire** d'une autre variable plutôt que sa valeur [1].

*   **Déclaration** : `type* variable;` (ex: `int* p;`). Cela signifie que `p` contiendra l'adresse d'un entier [1].
*   **Opérateurs clés** :
    *   `&` (Adresse de) : Récupère l'adresse d'une variable [1].
    *   `*` (Déréférencement) : Accède au **contenu** de la case mémoire pointée [2].
*   **Initialisation** : Il est crucial d'initialiser les pointeurs, souvent à `NULL` si l'adresse n'est pas encore connue, pour éviter des comportements indéfinis [1].

### Exemple : Passage par adresse
Pour modifier une variable dans une fonction (comme échanger deux valeurs), il faut passer des pointeurs. Sinon, la fonction travaille sur une copie locale [3].

```c
void swap(int* a, int* b) {
    int temp = *a; // Lit la valeur à l'adresse a
    *a = *b;       // Écrit la valeur de b à l'adresse a
    *b = temp;     // Écrit temp à l'adresse b
}
// Appel dans le main : swap(&x, &y);
````

_Source :_

--------------------------------------------------------------------------------

2. Allocation Dynamique de Mémoire

Les listes chaînées nécessitent une allocation dans le **tas (heap)** car leur taille n'est pas connue à la compilation et elles doivent survivre à la fonction qui les crée,.

• **malloc** : Réserve une zone mémoire contiguë.

    ◦ Syntaxe : `type* p = malloc(nombre_octets);`

    ◦ Nécessite `#include <stdlib.h>`.

    ◦ Renvoie `NULL` en cas d'échec.

• **sizeof(type)** : Indispensable pour demander la taille exacte d'un type en octets (ex: `sizeof(int)`), car celle-ci dépend de l'architecture,.

• **free** : Libère la mémoire allouée. C'est obligatoire pour éviter les fuites de mémoire une fois l'utilisation terminée.

--------------------------------------------------------------------------------

3. Les Structures et Listes Chaînées

Une liste chaînée est constituée de structures récursives où chaque élément pointe vers le suivant.

Structure d'un Nœud

On utilise un pointeur vers le même type de structure à l'intérieur de la définition.

```
struct int_list_item_s {
    int value;                    // La donnée
    struct int_list_item_s* next; // Le lien vers le suivant
};
```

_Source :_

Manipulation (`->`)

Pour accéder aux membres d'une structure via un pointeur, on utilise l'opérateur flèche `->`.

• `p->value` est strictement équivalent à `(*p).value`.

**Exemple de chaînage :**

```
void append(struct int_list_item_s* item, struct int_list_item_s* other) {
    item->next = other; // Le champ 'next' pointe maintenant sur 'other'
}
```

_Source :_

--------------------------------------------------------------------------------

4. Pièges Fréquents

5. **Segmentation Fault (Segfault)** : Se produit souvent lors d'une tentative d'accès à une zone mémoire invalide, par exemple en déréférençant un pointeur `NULL`.

6. **Pointeur** **void*** : C'est un pointeur générique (renvoyé par `malloc`). On ne peut pas le déréférencer directement sans le convertir ("caster") car le compilateur ignore la taille de la donnée pointée.

7. **Arithmétique des pointeurs** :

    ◦ `p + i` décale l'adresse de `i * sizeof(type)` octets.

    ◦ C'est utile pour parcourir des tableaux (`*(p+i)` équivaut à `p[i]`), mais pour les listes chaînées, on se déplace en suivant le pointeur `next`.

--------------------------------------------------------------------------------

Analogie : La Chasse au Trésor

• **Tableau** : Une rangée de casiers contigus. Si vous connaissez l'adresse du premier, vous trouvez le 10ème par simple calcul (arithmétique).

• **Liste Chaînée** : Une chasse au trésor. Vous avez l'adresse du premier coffre. En l'ouvrant, vous trouvez un objet (la valeur) et un papier indiquant l'adresse du coffre suivant (`next`). Vous ne pouvez pas aller directement au dernier coffre sans ouvrir tous les précédents.