
#include <stdio.h>

int sum(int n, int level) {
  for (int i = 0; i < level; i++) printf(" ");
  printf("sum(%d)\n", n);

  if (n <= 1) {
     for (int i = 0; i < level; i++) printf(" ");
     printf("return %d\n", n);
     return n;
  }
  int output = n + sum(n-1, level + 1);

  for (int i = 0; i < level; i++) printf(" ");
  printf("return %d\n", output);
}


int main() {
    int u = sum(4, 0);

    printf("%d\n", u);
}
