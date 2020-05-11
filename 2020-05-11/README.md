# Semaine 12

- [x] Quiz (HEIGINFO2A) --> 16h40
- [x] Correction Quiz

- [x] Classes de stockages
  - [x] static ***
  - [x] const ***
  - [x] extern **
  - [x] volatile *
  - [x] auto
  - [x] register
- [x] Type de données récursifs
  - [..] Listes chaînées
- [x] Informations concernant le labo test :
  - Utilisation du préprocesseur
  - Type de donnée abstrait
  - Structures
  - Création de bibliothèque (compilation séparée)
  - Pointeurs
  - Allocation dynamique

## Classes de stockage

### `auto` Classe de stockage automatique

```c
void foo() {
    // Variable locale
    // En général déclarée sur le stack
    // Variable automatique
    auto int toto;
}
```

### `static`

- Déclarer une variable local persistante
- Spécifier qu'un symbole n'est pas exportable
  - Ca permet d'éviter des collisions de symboles
```c
static int iterate() {
    static int i = 0;
    return i++;
}

int main() {
    assert(iterate() == 0);
    assert(iterate() == 1);
    assert(iterate() == 2);
    assert(iterate() == 3);
}
```

### `extern`

- Le symbol est déclaré dans un autre module

### `const`

- Le symbol est constant et ne peut pas être modifié.
- Ce n'est pas une constante au sens strict du terme.
- Utile à titre informatif.

```c
int main() {
    int a = 42;
    const int b = 12;

    int *p = &b; // <-- Warning : b ne sera plus constant...
    *p = 14; // Modifie b...

    // /!\ Mal parce que je jardine...
    *(&a + 1) = 41; // <-- Pas de warning... Donc dangereux...
}
```

Usage principal de const :

```c
int display_vector(const Vector *vector) {

}

void memcpy(void* dst, const void *src, size_t size);
```

### `register`

- La variable devrait être déclarée dans un registre processeur
- Le compilateur est malin et avec `auto` il choisi automatiquement de changer la classe de stockage du symbol en `register`

```c
register int i = 0;
for (i; i < 10; i++) {...}
```

### `volatile`

- Renseigne le compilateur que le symbol déclaré ne peut pas être optimisé
- Utile pour programmation système ou microcontrôleurs

```c
volatile int gpio; // Ce symbol ne peut pas être optimisé ! Il peut changer n'importe quand par quelque chose d'externe.

int main() {
    gpio ^= 0x01;
    gpio ^= 0x01;
    for(int i = 0; i < 10; i++) {
        gpio++;
        gpio--;
    }
}
```
