#include <stdio.h>
#include <stdlib.h>


void pop(int *tab, int *elements, int value) // Valdebenito
{
    tab[--*elements] = value;
}

void push(int *tab, int *elements, int value)
{
    tab[*elements++] = value;
}

int shift(int *tab, int *elements) // Yersin
{
    if (*elements == 0) return 0;
    int value = tab[0];
    for(int i = 0; i < (*elements-1); i++){
        tab[i] = tab[i+1];
    }

    return value;
}

void unshift(int *tab, int *elements, int value) // Bélaire
{
      for(int i = *elements - 1; i < 0; i--){
        tab[i] = tab[i-1];
    }
    tab[0] = value;
}

int main(void) {
    int v[10];
    int elements = 0;
    int value_shift = 0;
    int value_unshift = 0;

    // Push 42
    push(v, &elements, 42);

    // Pop enlever un élément du tableau par la fin
    int value = v[--elements];

    // Shift
    value_shift = shift(v, &elements);

    // Unshift (ajoute un élément depuis le début du tableau)
    unshift(v, &elements, value_unshift);

}
