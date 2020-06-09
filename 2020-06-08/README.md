# Semaine 16 (4 périodes, lundi + mardi)

  - [ ] Quiz (1/2)
  - [ ] Quiz (2/2)
  - [ ] Unions
  - [ ] Champs de bits + Aliasing
  - [ ] Résumé du semestre
  - [ ] Anciens TE
  - [ ] Cours de mardi en présentiel (voté à l'unanimité) ?

# Static

```c
int foo() {
    static int i = 0;
    return i++;
}

assert(foo() == 0);
assert(foo() == 1);
assert(foo() == 2);
```
