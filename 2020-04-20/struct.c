
/* Sucre syntaxique
 *
 * foo->bar
 * (*foo).bar
 */

struct Foobar {
    int a;
    int b;
};

struct Foobar foo;
struct Foobar bar;

typedef struct Foobar Miam;

//#define uint unsigned int <-- Pas bien
typedef unsigned int uint;

void f(uint uint) {
}

Miam foofoo;
Miam barbar;

typedef struct {
    int a;
    int b;
} FooFooBar;

