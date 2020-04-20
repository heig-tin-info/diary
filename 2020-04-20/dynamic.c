
void *malloc(size_t size);
void memcpy(void *dst, void *str, size_t size);

void * my_realloc(void* p, size_t size) {
    void *q = malloc(size);
    memcpy(q, p, size);
    free(p);
    return q;
}

int main() {
  char *foo = malloc(10);
  char a[10];
  char b[10];
  memcpy((char *)b, (char *)a, 10);

  {
    char *tmp = realloc(foo, 20);
    if (tmp == NULL)
      fprintf(stderr, "pas bien");
    else
      foo = tmp;
  }

  char *toto = foo;
  free(toto);
}
