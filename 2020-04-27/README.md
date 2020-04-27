# Cours S10

- [x] Quiz (10 min) HEIGINFO2A -> 16h47
- [x] Correction du quiz
- [x] Algorithmes
- [x] Complexité des algorithmes
- [x] Recursivité

## Structures

```c
typdef struct foo {
    int a;
    int b;
} Foo;

Foo toto;
struct foo {
    int a;
    int b;
} *tata;
```

## Flexible member array

```c
struct { int a; char b[] } *i = malloc(1000);
i->b[100];
```

```c
struct {
   int16_t u[2];  2*2 = 4
   int32_t v[2];  4*2 = 8
   int8_t w[8];   1*8 = 8
   char z[];
} *p = malloc(100);

p->z[8] = 42;
```

## Complexité des algorithmes

```c
int pair_sum_sequence(int n) {
   int sum = 0;
   for (int i = 0; i < n; i++) {
      sum += i + (i + 1);
   }
   return sum;
}
```

O(n)

### Exemple 2

```c
int min = INT_MAX;
int max = INT_MIN;

for (int i = 0; i < N; i++) {
   if (x[i] < min) min = x[i];
   if (x[i] > max) max = x[i];
}
```

O(n)

### Exemple 3

```c
for (int i = 0; i < LEN; i++) {
   if (x[i] < min) min = x[i];
}

for (int i = 0; i < LEN; i++) {
   if (x[i] > max) max = x[i];
}
```

O(n)

### Exemple 4

```c
for (int i = 0; i < N; i++) {
   for (int j = 0; j < N; j++) {
      printf("%d, %d\n"), a, b);
   }
}
```

O(n^2)

### Exemple 5


```c
for (int i = 0; i < A; i++) {
   for (int j = 0; j < B; j++) {
      printf("%d, %d\n"), a, b);
   }
}
```

O(A * B)

### Exemple 6 (récursivité)

```c
int sum(int n) {
  if (n <= 1) {
     return n;
  }
  return n + sum(n-1);
}
```


sum(4) --> 4 + 6 --> return 10
   sum(3) --> return 6
      sum(2) --> return 3
         sum(1) --> return 1
            return 1

O(n)

### Exemple 7

```c
int f(int n) {
   if (n <= 2) {
      return 1;
   }
   return f(n - 1) + f(n - 2);
}
```

O(n!)

### Exemple 8

```c
int main() {
    int n = 100;

    int t1 = 1, t2 = 1;
    for (int i = 1; i <= n; ++i) {
        printf("%d, ", t1);
        int nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }

    return 0;
}
```

O(n)

## Tri à bulle

```c
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   for (int i = 0; i < n-1; i++)
       for (int j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
```

## Log n

1 3  10  25  651  45557 51224  51329
     ^         ^
O(log n) <---
O(n)




O(n^2)

n=10

10 * 10
10 * 9
10 * 8
...




1 1 2 3 5 8 ...

O(n!)


n
1  1
2  1
3  2 + 1 = 3
4  3 + 1 + 1 = 5
5  5 + 3 + 1 = 9
6  9 + 5 + 1 = 15
7  15 + 9 + 1 = 25
8  25 + 15 + 1 = 41



A : O(n)          80%
B : O(log n)
C : O(n^2)        20%
D : O(n!)
E : J'ai rien compris

O(2*n)



01 02 03 04 05 06 07 08 09 10
Recherche log n
Insertion n
00 01 02 03 04 05 06 07 08 09 10

n log n
