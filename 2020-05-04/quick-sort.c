
#include <stdio.h>
/*
04  71  42  08  99  16  83  51  15  66 [50]
04  08  16  15  42 [50] 51  99  66  83  71 <-- void partition(int a[], int low, int high, int pivot)

04  08  16  15 [42]
04  08  16  15 [42]
                        51  99  66  83 [71]
                        51  66 [71] 99  83
04  08  16 [15]
04  08 [15] 16
                        51 [66]
                        51 [66]
                                    99 [83]
                                   [83] 99
04 [08]
04 [08]
*/

#include <stdio.h>
#define LEN(a) (sizeof(a)/sizeof(*a))

#define DEBUG

#ifdef DEBUG
#define RED "\033[0;31m"
#define RESET "\033[0m"
int display(int a[], int low, int high, int pivot) {
    for(int i = 0; i < low; i++)
        printf("    ");
    for(int i = low; i <= high; i++) {
        if (i == pivot)
            printf(RED "[%02d]" RESET, a[i]);
        else
            printf(" %02d ", a[i]);
    }
    printf("\n");
}
#endif

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition (int a[], int low, int high, int pivot)
{
    int i = low;
    for (int j = low; j < high; j++)
        if (a[j] < a[pivot])
            swap(&a[i++], &a[j]);
    swap(&a[i], &a[pivot]);
    return i;
}

void quicksort(int *a, int low, int high)
{
    if (low >= high) return;
    #ifdef DEBUG
    display(a, low, high, (high-low)/2 + low);
    #endif
    int pivot = partition(a, low, high, (high-low)/2 + low);
    #ifdef DEBUG
    display(a, low, high, pivot);
    #endif
    quicksort(a, low, pivot - 1);
    quicksort(a, pivot + 1, high);
}

int main() {
    //int a[] = {4, 71, 42, 8, 99, 16, 83, 51, 15, 66, 50};
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    quicksort(a, 0, LEN(a) - 1);
}
