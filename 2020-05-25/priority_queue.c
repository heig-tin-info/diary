#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

typedef struct Element
{
    struct Element *next;
    int priority;
    char word[];
}Element;

typedef struct Queue
{
    Element *head;
    Element *tail;
}Queue;

void queue_init(Queue *queue) {
    queue->head = queue->tail = NULL;
}

static Element *new(char *str, int priority) {
    Element *el = calloc(sizeof(Element) + strlen(str) + 1, 1);
    assert(el != NULL);
    el->priority = priority;
    strcpy(el->word, str);
    return el;
}

void queue_push(Queue *queue, char *str, int priority)
{
    Element *el = new(str, priority);
    Element **walk = &queue->head;
    while((*walk) != NULL && (*walk)->priority > el->priority)
        walk = &(*walk)->next;
    el->next = *walk;
    *walk = el;
}

void queue_shift(Queue *queue, char *str, size_t size) {
    assert(queue->head != NULL);
    Element *current = queue->head;
    if (str != NULL)
        strncpy(str, current->word, size);

    queue->head = current->next;
    free(current);
}

void queue_iterate(Queue *queue, void (*cb)(char *word)) {
    Element *walk = queue->head;
    while(walk != NULL) {
        cb(walk->word);
        walk = walk->next;
    }
}

void display(char *str) {
    printf("%s->", str);
}

int main()
{
    Queue queue;
    queue_init(&queue);

    queue_push(&queue, "toto");
    queue_push(&queue, "tata");
    queue_push(&queue, "titi");
    queue_push(&queue, "tutu");

    char buffer[100];
    queue_shift(&queue, buffer, sizeof(buffer)/sizeof(*buffer));
    printf("élément enlevé: %s\n", buffer);
    queue_iterate(&queue, display);
}
