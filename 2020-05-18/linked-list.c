#include <stdlib.h>

// Liste doublement chaînée

typedef struct Person {
    char firstname[32];
    char lastname[64];
    int age;
    char phone[20];
} Person;

typedef struct Element {
    Person person;
    struct Element * next;
    struct Element * prev;
} Element;

typedef struct List {
    Element * first;
    Element * last;
} List;

// O(1) time
void list_push(List* list, Person person) {
    Element *new = (Element*)malloc(sizeof(Element));

    list->last->next = new;
    new->next = NULL;
    new->prev = list->last;
    list->last = new;

    new->person = person;
}

list_shift(List *list, Person *person) {
    *person = list->first->person;
    list->first = list->first->next;
    free(list->first->prev);
    list->first->prev = NULL;
}

void list_delete(List* list, Element* el) {
    el->prev->next = el->next;
    el->next = el->prev;
    free(el);
}

