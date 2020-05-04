# Semaine 11

- [x] Quiz
- [x] Correction Quiz
- [x] Tableaux dynamiques, complexité amortie
- [x] Rappel complexité des algorithmes
- [x] Recursivité
- [x] qsort de stdlib
- [x] Pause -> 16h40
- [x] Quick Sort
- [x] Heap Sort
- [x] Static

# Tableaux dynamiques

```c
typedef struct Vector {
    int *data;
    size_t capacity;
    size_t count;
};
```

```text
id       00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20
capacity 01 04 04 04 08 08 08 08 08 08 08 16 16 16 16 16 16
cost     01 02 01 04 01 01 01 08 01 01 01 01 01 01 01 16 01 ...

1 + 2 + 4 + 8 + 16 + 32 + n
n + n/2 + n/4 + n/8 ... + 4 + 2 + 1
n (1 + 1/2 + 1/4 + 1/8 ...)
       -------------------
n (1 + 1)
┌───────────────────┬─────────┬─────────┐
│                   │         │         │
│                   │         │   n/4   │
│                   │         │         │
│                   |         │         │
│         n         │   n/2   ├────┬────┘
│                   │         │n/16│    ┆
│                   │         │    │    ┆
│                   │         ├────┘    ┆
│                   │         │         ┆
└───────────────────┴─────────┘┄┄┄┄┄┄┄┄┄┘
```

O(n) pire des cas
O(1) amorti...

# Complexité des algorithmes

O(n^2) time   (le temps d'execution)
O(n)   space  (l'espace mémoire requis)

Un algorithme pour connaître le jour de la semaine du premier janvier d'une année donnée :

```c
char *tab[10000] {
    "lundi",
    "mardi",
    ...
}

tab[1936] // O(1) time  O(n) space
```



# Récursivité

--> Un algorithme récursif est souvent moins performant qu'un algorithme itératif.
--> Un algorithme récursif est souvent plus facile à comprendre qu'un algorithme itératif.

# Quick Sort

- On choisit un Pivot
- On partitionne le tableau de façon que tous les éléments plus petit que le tableau sont à gauche et les éléments plus grand sont à droite
- On répète récursivement cet algorithme sur les tronçons de gauche et de droite.

On obtient quelque chose comme :

    n + (2 * n/2) + (2 * n/ 4) + (2 * n/8)

Qui peut être écrit comme :

    2 * (n + n/ 2 + n/4 + n/8 ... + 1)

Et qui se résume à :

    O(n * log(n))

Meilleure temps O(n log n) time
Temps moyen     O(n log n) time
Pire temps      O(n^2) time

qsort (stdlib.h) implémenté de façon itérative
que le pivot est choisi de manière intelligente

On peut voir dans le code source de [glibc](https://github.com/bminor/glibc) l'implémentation itérative de `qsort`. On y voit que le choix du pivot est plus subtile que simplement choisir le premier, le dernier ou l'élément milieu. 

# Heap Sort

- Un tableau linéraire est considéré comme un arbre binaire
- Les enfants sont accessibles avec la propriété 2k + 1 et 2k + 2

Le concept est le suivant :

1. Le tableau est transformé en un `heap`, qui respecte la propriété que tous les enfants sont plus petits que leurs parents.
2. Le premier élément est permuté avec le dernier élément du tableau
3. La taille du tableau est réduite de 1.

La fonction `heapify` est récursive.

Meilleure temps O(n log n) time
Temps moyen     O(n log n) time
Pire temps      O(n log n) time

# Static

Le mot clé static à deux utilités :

1. Rendre une variable locale persistante.
2. Empêcher un symbole (fonction ou variable) d'être utilisé dans un autre fichier.

```c
static int foo() {
    static int i = 2;
    return i++;
}

int main() {
    assert(2 == foo())
    assert(3 == foo())
    assert(4 == foo())
}
```

