# Préprocesseur

gcc -DDEBUG=1 foo.c

#define DEBUG 1

# Classes de stockage

auto (classe par défaut)
volatile (utilisé dans les interruptions, le compilateur ne fait pas d'hypothèses d'optimisation)
register (donne l'indication au compilateur d'utiliser un registre cpu pour cette variable)
static (limite la portée de la variable au fichier courant + rends la variable persistante)
const (empêche de modifier une variable)
extern (symbole est déclaré dans un autre fichier)

# Types abstraits et bibliothèques

```c
// foo.c

typedef struct foobar {
    int a;
    int b;
    int c;
} Foobar;

int foo(int a, int b) {
    return a + b;
}
```

```c
// foo.h
/**
 * Return the sum of the parameters.
 * @param a Number
 * @param b Number
 * @return sum of a and b
 */

typedef struct foobar Foobar;

int foo(int a, int b);
```

```c
// main.c
#include <math.h>

#if 0
extern int foo(int, int);
#else
#include "foo.h"
#endif

int main() {
    Foobar foobar; // Interdit car la taille n'est pas connue...
    Foobar *foobar; // Autorisé
    foobar + 1; // Interdit car la taille n'est pas connue (type incomplet)...

    printf("%d", sqrt(foo(1,2)));
}
```

```bash
gcc -c foo.c -o foo.o
gcc -c main.c -o main.o
gcc foo.o main.o -o a.out -lm # Assembler...
```

## Allocation dynamique

- calloc (initialise à zéro l'espace)
- malloc
- realloc (redimensionne l'espace alloué dynamiquement, et si nécessaire le copie ailleurs)
- free !!!

Jamais oublier de libérer l'espace mémoire utilisé pour éviter une fuite...

```c
int *u = malloc(sizeof(int) * 10);
int *v = &u[3];
*v = 42;

int *tmp = realloc(u, sizeof(int) * 1000));
assert(tmp != NULL);
#if 1 // Pour éviter un crash
v = &u[3];
#endif
u = tmp;

printf("%d", *v); // Peut avoir un très crash !


```

## Queues et piles

- push (push_back, append)
- pop
- shift // Enlève un élément au début
- unshift // Ajoute un élément au début

### Queue (FIFO)

- push
- shift // Pas efficace sur un tableau static ou dynamique

Autres noms :

- File d'attente
- Queues
- Deques (deques de cartes)

### Pile (stack) (LIFO)

- push
- pop

## Tableaux dynamiques

Facteur de croissance 2 (1.5)

Coût d'insertion "O(1) amorti"

## Type de donnée récursif

```c
typedef struct element {
    int value;
    struct element *next;
} Element;
```

- Liste chaînées (queues, queues prioritaires)
- Liste chaînées double
- Arbres binaires (Heap)
- Tries

## Fichiers binaires et les fichiers textes

// fp pour File Pointer
FILE *fp = fopen("file.c", "wb");

- fscanf
- fprintf
- fread
- fwrite
- fseek
- ftell
- fclose
- fgetc
- fputc

### Fichier texte

Du texte lisible... C'est à dire les caractères ASCII imprimables ou
les caractères UTF8 imprimables... On y trouvera pas \x0 \x2...

- CSV (Comma Separated Values) .csv
- JSON .json
- Markdown .md
- .c
- .h

### Fichier binaire

- Pas de texte ou peu de texte et toutes les valeurs sont admises...

- .o
- a.out
- .dat (souvant des fichiers binaires)
- .dll
- .exe


### Lecture écriture séquentielle

```bash
cat foo.csv | ./csv2binary > foo.dat
echo "Salut" | cowsay > tutu.txt
```
