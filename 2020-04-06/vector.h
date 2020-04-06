#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include <stdbool.h>

typedef struct Vector {
    double *data;
    size_t elements;
    size_t capacity;
} Vector;

bool vector_init(Vector *vector);
bool vector_free(Vector *vector);

bool vector_push(Vector *vector, double c);
bool vector_pop(Vector *vector, double *c);

#endif // VECTOR_H
