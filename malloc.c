

#include <stdlib.h>
#include <stdio.h>

int *array = NULL;
int main() {
    array = calloc(5LL*1024*1024*1024, 1);

    fgetc(stdin);
    free(array);
}


