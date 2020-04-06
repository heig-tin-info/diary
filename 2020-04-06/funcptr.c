#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void cat(size_t amount) {
    for (size_t i = 0; i < amount; i++)
        printf("🐱");
}

void rabbit(size_t amount) {
    for (size_t i = 0; i < amount; i++)
        printf("🐰");
}

int main(void) {
    srand(time(NULL));

    void (*animals[])(size_t) = {rabbit, cat};

    do {
        animals[rand() % 2](rand() % 10);
    } while(getchar());
}