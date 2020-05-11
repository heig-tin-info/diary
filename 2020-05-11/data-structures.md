# Type de données

- push
- pop
- shift
- unshift

Tableau Dynamique
    - Pile (Pile de cartes, deque)
      - push
      - pop
    - Queue
      - push
      - shift

==============  =========  ===========  =============
                Tableau
                Statique   Dynamique    Liste chaînée
==============  =========  ===========  =============
Indexing i[1]   O(1)       O(1)         O(n)
Push/Pop        n/a        O(1) amorti  O(1)
Unshift/Shift   n/a        O(n)         O(1)
Insert/Delete   n/a        O(n)         O(1)
Search          O(n)       O(n)         O(n)
Sort            O(n log n) O(n log n)   O(n log n)
==============  =========  ===========  =============

# Listes chaînées

```c
typedef struct Element {
    int value;
    struct Element *next;
} Element;

typedef struct LinkedList {
    struct Element *first;
    struct Element *last;
} LinkedList;


first       [8]->[15]->[16]
  -----------^
last--------------------^

void push(LinkedList *list, int value) {
    Element *new = malloc(sizeof(Element));
    new->value = value;
    list->last = list->last->next = new;
}

int shift(LinkedList *list) {
    int value = list->first->value;
    Element *p = list->first;
    list->first = list->first->next;
    free(p);
    return value;
}

int pop(LinkedList *list) {
    int value = list->last->value;

    Element *el = list->first;
    Element *parent = list->first;
    while(el->next != NULL) {
        parent = el;
        el = el->next;
    }
    parent->next = NULL;
    list->last = parent;
    free(el);
    return value;
}

int main() {
    Element a = {.value=1, .next=NULL};
    Element b = {.value=2, .next=NULL};
    Element c = {.value=3, .next=NULL};
    a.next = &b; // Lie les deux éléments
    b.next = &c;
    c.next = &a;

    Element z = {.value=0, .next=NULL};
    c.next = &z;
    z.next = &a;

    Element *p = &a;
    for (int i = 0; i < 10; i++) {
        printf("%d\n", p->value);
        p = p->next;
    }
}
```


