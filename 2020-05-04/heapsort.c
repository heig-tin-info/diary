
/*
enfant de gauche  2 * k + 1
enfant de droite  2 * k + 2

int a[] = {4,71,42,8,99,16,83,51,15,66,50};

00  01  02  03  04  05  06  07  08  09  10
04  71  42  08  99  16  83  51  15  66  50

            04
             |
         ----+----
       /           \
      71           42
     --            --
   /    \        /    \
  8     99      16    83
 / \    / \
51 15  66  50

heapify --> Les enfants sont toujours plus petit que les parents


00  01  02  03  04 | 05  06  07  08  09  10
04  71  42  08  99 | 16  83  51  15  66  50


            04
             |
         ----+----
       /           \
      71           42
     --            --
   /    \        /    \
  8     99      16    83
 / \    / \
51 15  66  50


            99
             |
         ----+----
       /           \
      71           83
     --            --
   /    \        /    \
  51    66      16    42
 / \    / \
08 15  04  50


50 71 83 51 66 16 42 08 15 04 99
-----------------------------
04 71 50 51 66 16 42 08 15 83 99
--------------------------
15 66 50 51 04 16 42 08 71 83 99
-----------------------
08 51 50 15 04 16 42 66 71 83 99
--------------------
42 15 50 08 04 16 51 66 71 83 99
-----------------


            42
             |
         ----+----
       /           \
      15           50
     --            --
   /    \        /
  08    04      16
*/

#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;
    if (largest == i) return;

    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
}

void heapSort(int arr[], int n)
{
    // Only traverse nodes with childrens (half of the tree)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);


    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n) {
    for (int i=0; i<n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program
int main() {
    int arr[20];
    int n = sizeof(arr)/sizeof(*arr);

    for (int i = 0; i < n; i++) arr[i] = rand() % 50;
    heapSort(arr, n);

    printArray(arr, n);
}
