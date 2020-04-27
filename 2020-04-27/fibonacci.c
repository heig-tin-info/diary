#include <stdio.h>

long long count = 0;

int f(int n) {
  count++;
  if (n <= 2) {
    return 1;
  }
  int out = f(n - 1) + f(n - 2);
  return out;
}

int main() { f(46);
printf("%lld\n", count);
}
