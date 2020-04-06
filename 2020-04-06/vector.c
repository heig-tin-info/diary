#include <stdlib.h>
#include <stdbool.h>

#include <stdio.h>
#include "vector.h"

#define GROWTH_FACTOR (2)

bool vector_init(Vector *vector) {
    vector->capacity = 1;
    vector->data = malloc(vector->capacity * sizeof(*vector->data));
    vector->elements = 0;
    return vector->data != NULL;
}

bool vector_free(Vector *vector) {
    if (vector->data != NULL) {
        free(vector->data);
        vector->data = NULL;
        vector->elements = 0;
        vector->capacity = 0;
        return true;
    }
    return false;
}

bool vector_push(Vector *vector, double c) {
    #ifdef DEBUG
    fprintf(stderr, "push(%f)\n", c);
    #endif
    if (vector->data == NULL)
        return false;

    if (vector->elements + 1 >= vector->capacity) {
        vector->data = realloc(vector->data, vector->capacity *= GROWTH_FACTOR);
        if (vector->data == NULL)
            return false;
    }

    vector->data[vector->elements++] = c;
    return true;
}

bool vector_pop(Vector *vector, double *c) {
    if (vector->data == NULL)
        return false;

    if (vector->elements < 1)
        return false;

    *c = vector->data[--vector->elements];
    #ifdef DEBUG
    fprintf(stderr, "pop(%f)\n", *c);
    #endif
    return true;
}
