#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "vector.h"

/**
 * 1. Écrire des fonctions prenant deux doubles en paramètres
 * et retournant :
 *
 * - Somme (add)
 * - Produit (mul)
 * - Division (divise)
 * - Différence (sub)
 */

double add(double a, double b)
{
    return(a+b);
}

double mul (double a, double b)
{
    return(a*b);
}

double sub(double a, double b)
{
    return (a-b);
}

double divise(double a, double b)
{
    return a/b;
}

/**
 * 2. Définir un tableau global `operators` de 256 pointeurs
 * de fonctions initialisés à NULL
 */

double (*operators[256])(double, double) = {0};

int main() {
    /**
     * 3. Dans la fonction main, initialiser les positions du
     * tableau des 4 opérateurs de base à leur fonction
     * correspondante.
     */
    operators['+'] = add;
    operators['*'] = mul;
    operators['-'] = sub;
    operators['/'] = divise;

    /**
     * 4. Parcourir la chaîne et lire chaque opération
     */
    const char* calculus = "347+*";
    Vector vector;
    vector_init(&vector);

    char c;
    while((c = *calculus++) != '\0')
    {
        if (isdigit(c))
        {
            vector_push(&vector, (double)(c - '0'));
        } 
        else if (operators[c] != NULL)
        {
            double a, b;
            vector_pop(&vector, &a);
            vector_pop(&vector, &b);
            double result = operators[c](a, b);
            vector_push(&vector, result);
        }
    }

    double result;
    vector_pop(&vector, &result);
    printf("%.1lf\n", result);

    vector_free(&vector);

    return 0;
}