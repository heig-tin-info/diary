#include <stdio.h>
#include <stdlib.h>

void foo(char * a) {
    for (int i = 0; i < 10; i++) {
        a[i] = i + 'a';
    }
    a[10] = '\0';
}

enum Toto {
    TOTO_INT
};

typedef enum Type {
    TYPE_INT, // 0
    TYPE_CHAR, // 1
    TYPE_DOUBLE // 2
} Type;

void bar() {
    Type a = TYPE_DOUBLE;
}

void my_memset_dummy(void *c, int value, size_t size, Type type) {
    for (int i = 0; i < size; i++) {
        switch(type) {
            case TYPE_INT:
                ((int*)c)[i] = value;
                break;
            case TYPE_CHAR:
                ((char*)c)[i] = value;
                break;
            default:
                exit(EXIT_FAILURE);
        }
    }
}

void my_memset_int(int *c, int value, size_t size) {
    for (int i = 0; i < size; i++) {
        c[i] = value;
    }
}

void my_memset(void *c, char value, size_t size) {
    for (int i = 0; i < size; i++) {
        ((char*)c)[i] = value;
    }
}

#define MODE 1
int main() {
    #if MODE == 0 // Allocation dynamique initialisée à zéro
    char *str = NULL;
    str = calloc(11, sizeof(str[0]));
    #elif MODE == 1 // Allocation dynamique initialiée à zéro
    char *str = NULL;
    const size_t size = 11 * sizeof(str[0]);
    str = malloc(size);
    memset(str, 0, size);
    #else // Allocation statique, à la compilation
    char str[11] = {0};
    #endif

    foo(str);
}
