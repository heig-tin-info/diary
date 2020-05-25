## Semaine 13

- [x] TE2 en présentiel ?
- [x] Rappels
  - [x] Classes de stockage
  - [x] Tableaux multi-niveaux et multi dimensionnels
  - [x] Type de données abtraites
- [ ] Listes chaînées

- [ ] Labo Test 16h35->18h05

## Type de données abstraits

- Cacher l'implémentation
  - `push(data, value);`
- S'abstraire de l'implémentation
- Modularité

```c
// main.c
#include "vector.h"

int main() {
    Vector vector;
    vector.count; // Error ! Type incomplet
    sizeof(vector); // Error ! Type n'a pas de taille

    push(vector, 42);
}
```

```c
// vector.h
typedef struct vector Vector;

void push(Vector vector, int value);
```

```c
// vector.c
struct vector {
    int capacity;
    int count;
    int *data;
} Vector;
```

## Tableau multi-niveaux et multi dimensionnels

### Tableau multi-niveau

```c
int foo[10] = {1,2,3,4,5,6,7,8,9,10};
int* bar[10] { foo, foo, foo };

bar[0][2] // *(*(bar + 0) + 2)
```

### Tableau multi-dimensionnels

```c
int foo[10][2] = { {0,1}, {2,3}, {4,5}, ... };
              // {0,1,2,3,4,5, ... };

foo[0][1]
```

## Classes de stockage

### `const`

```c
const double pi = 3.1415926535;

int foo(const int *p);
```

### `extern`

```c
extern void array_push(Data *data, int value);
```

### `volatile`

```c
volatile int i;

int main() {
    for(; i <10; i++);
}
```

### `auto`

- Stack
- Registre

```c
auto int i;
```

### `register`

On n'utilise plus ce mot clé...
