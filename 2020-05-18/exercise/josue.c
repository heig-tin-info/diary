#include <stdio.h>
#include <stdlib.h>

typedef struct Animal{
    char *breed;
    char *name;
    int age;
    struct Animal *next;
    struct Animal *prev;
}Animal;

typdef struct Zoo{
    Animal *first;
    Animal *last;
}Zoo;

void push(Zoo *zoo, char *breed, char *name, int age){
    Animal *new = malloc(sizeof(Animal));

    zoo->last->next = new;
    new->prev = zoo->last;
    zoo->last = new;
    new->last = NULL;

    new->name = name;
    new->age = age;
}

void shift(Zoo *zoo){
    Animal *rmv = zoo->first;

    zoo->first = zoo->first->next;
    zoo->first = NULL;
    free(rmv);
}

void print_zoo(Zoo *zoo){
    Animal *current = zoo->first;
    do{
        printf(("Breed: %s\n"), current->breed);
        printf(("Name: %s\n"), current->name);
        printf(("Age: %d\n") current->age);
        printf("\n");
    }while(current->next != NULL);
}

int main(){
    Zoo zoo;
    zoo->first = NULL;
    zoo->last = NULL;

    push(&zoo, "Cheetah", "Speedy", 4);
    push(&zoo, "Elefant", "Jumbo", 4);
    push(&zoo, "Bear", "Balou", 4);
}
