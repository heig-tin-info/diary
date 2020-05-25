#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

typedef struct Element
{
    struct Element *next;
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

void queue_push(Queue *queue, char *str)
{
    Element *new = malloc(sizeof(Element)+(strlen(str)+1));
    new->next = NULL;
    assert(new != NULL);
    strcpy(new->word,str);

    if(queue->tail == NULL) {
        queue->head = queue->tail = new;
    } else {
        queue->tail->next = new;
        queue->tail = new;
    }
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
