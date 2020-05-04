#include <stdio.h>

// somme : 1/2 +1/4 + 1/8

#if 0
int _(int n) {
    if (!n) return 0;
    return n + _(n / 2);
}
#endif

/*
_(10)
    printf("10") ...
    _(5)
        _(2)
            _(1)
                _(0)
                0
            printf("1")
            1
        printf("2")
        3
    printf("5")
    8
printf("10");
18
*/

#if 0
int _(int n) {
    if (!n) return 0;
    printf("%d\n", n);
    int result = n + _(n / 2);
    return result;
}

int main() {
    int n = 10;
    printf("%f\n", (double)_(n) / n);
}

#endif

struct Data {
    int values[1024];
    int count;
};

int _(int n, struct Data *data) {
    if (!n) return 0;
    data->values[data->count++] = n;
    int result = n + _(n / 2, data);
    //data->values[data->count++] = n;
    return result;
}

int main() {
    struct Data data = {0};
    _(10, &data);
    for (int i = 0; i < data.count; i++)
        printf("%d ", data.values[i]);
}
