#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
    int *tab;
    int elements;
    int capacity;
} Vector;

int pop(Vector *v)
{
    if (v->elements == 0) return 0;
    return v->tab[--v->elements];
}

void push(Vector *v, int value)
{
    v->tab[v->elements++] = value;
    if(v->elements == v->capacity)
    {
        v->tab = realloc(v->tab, v->capacity *= 2);
        if(v->tab == NULL) {
            exit(EXIT_FAILURE);
        }
    }
}

int shift(Vector *v)
{
    if (v->elements == 0) return 0;
    int value = v->tab[0];
    for(int i = 0; i < ((v->elements)-1); i++){
        v->tab[i] = v->tab[i+1];
    }

    return value;
}

void unshift(Vector *v, int value)
{
    for(int i = v->elements - 1; i < 0; i--){
        v->tab[i] = v->tab[i-1];
    }
    v->tab[0] = value;
}

Vector init()
{
    int initial_capacity = 1;
    Vector vector = {
        .capacity = initial_capacity,
        .tab = malloc(sizeof(int) * initial_capacity)
    };
    return vector;
}

void free_(Vector *vector)
{
    if (vector->tab != NULL)
        free(vector->tab);
}

int main(void) {
    Vector vector = init();

    // Push 42
    for (int i = 0; i < 11; i++)
        push(&vector, 42);

    // Pop enlever un élément du tableau par la fin
    int value = pop(&vector);

    // Shift
    int value_shift = shift(&vector);

    // Unshift (ajoute un élément depuis le début du tableau)
    int value_unshift;
    unshift(&vector, value_unshift);

}
