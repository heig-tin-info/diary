#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void* b){
    return (*(int*)b - *(int*)a);
}

#define LEN(a) sizeof(a)/sizeof(*a)

int main() {
    int u[] = {6, 12, 44, 1, 3, 5, 22, 100, 8};
    // {adresse, nbr éléments, taille élément, }
    qsort(u,LEN(u), sizeof(*u), comp);

    for (int i = 0; i < LEN(u); i++) {
        printf("%d ", u[i]);
    }
    printf("\n");
}
