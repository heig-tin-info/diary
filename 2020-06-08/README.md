# Semaine 16 (4 périodes, lundi + mardi)

  - [x] Quiz 28 (1/2)
  - [x] Quiz 29 (2/2)
  - [ ] Unions
  - [ ] Champs de bits + Aliasing

  - [ ] Résumé du semestre
  - [ ] Anciens TE


# Static

```c
int foo() {
    static int i = 0;
    return i++;
}

assert(foo() == 0);
assert(foo() == 1);
assert(foo() == 2);
```

# Unions

```c
union toto {
    int a;
    float b;
} Toto;

Toto u;

u.a = 123;
u.b = 12.1; // écrase la valeur 123
```

```c
typedef struct article {
   char *title;
   double price;
   union {
      int pages;
      float duration;
   };
} Article;

Article book;
book.title = "The little prince";
book.pages = 324;
book.price = 5.40;

Article movie;
movie.title = "The Matrix";
movie.duration = 131.2;
movie.price = 23.5;
```

```c
union {
    int32_t a;
    int8_t b;
} foo;

printf("%d\n", sizeof(foo));
```

```c
union {
    int8_t i8[4];
    int16_t i16[2];
    int32_t i32;
} bar;

bar.i32 = 1243482812;
#if 0
int8_t b0 = 1243482812 & 0xff;
int8_t b1 = (1243482812 >> 8) & 0xff;
int8_t b2 = (1243482812 >> 16) & 0xff;
int8_t b3 = (1243482812 >> 24) & 0xff;
#else
int8_t b0 = bar.i8[0];
int8_t b1 = bar.i8[1];
int8_t b2 = bar.i8[2];
int8_t b3 = bar.i8[3];
#endif
```

```c
char m[2][2] = { {0, 1}, {2, 3} };

00 01 02 03
```

```c
union {
    int m[8][8];
    int v[64];
} data;

for (int i = 0; i < 8; i++)
   for (int j = 0; j < 8 ; j++)
      data.m[i][j] = rand();

for (int i = 0; i < sizeof(data.v)/sizeof(data.v[0]); i++)
    data.v[i] = rand();
```


## Alignement mémoire

   1   2    3     4   5     6    7
+----+----+----+----+----+----+----+----+----+----+
| a  |    b    |         c         |    |    |    |
+----+----+----+----+----+----+----+----+----+----+

+----+----+----+----+----+----+----+----+----+----+
| a  | -- |    b    |         c         |    |    |
+----+----+----+----+----+----+----+----+----+----+
|                   |                   |


#pragma pack(1)
typedef struct foo {
   int8_t a;
   int16_t b;
   int32_t c;
} Foo;
#pragma pop

+----+----+----+----+----+----+----+----+----+----+
|         c         |    b    |  a |
+----+----+----+----+----+----+----+----+----+----+
|                   |                   |

typedef struct bar {
   int32_t c;
   int16_t b;
   int8_t a;

} Bar;



fwrite(foo, sizeof(foo), 1, fp);

fwrite(foo.a, sizeof(int8_t), 1, fp);
fwrite(foo.b, sizeof(int16_t), 1, fp);
fwrite(foo.c, sizeof(int32_t), 1, fp);

sizeof(Foo);

## Champs de bits

typedef struct ucsctl2 {
    short flln : 10;
    short _reserved : 2;
    short flld : 3;
    short _reserved1 : 1;
} Ucsctl2;

Ucsctl2 ucsctl2 = { .flld = 2, .flln = 12 };

## Enum

```c
#if 0
#define FOO 0
#define BAR 1
#define BAZ 2
#else
// Commence à zéro
// On a aussi la possibilité de forcer la valeur avec le signe =
// enum sont stoqués sur 4 bytes (sur une machine 32-bits)
enum FOOBAR {
    FOO, BAR, BAZ, QUX = 32, OTHER
};
#endif

enum FOOBAR foobar;
foobar = BAR;
printf("%d", foobar); // Affiche 1
int a = BAR; // Autorisé mais pas très utile...
```
