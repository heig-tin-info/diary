# Semaine 6

- [x] Quiz HEIGINFO2A (14h57 --> 15h10)
  - [x] Correction du quiz
- [x] LiveShare (installation)
- [x] Allocation dynamique
  - [x] Démonstration malloc
  - [x] Tableaux dynamiques (interactif)
- [x] Compilation séparée
- [.] Préprocesseur

# Note de cours

13 minutes pour le quiz c'est trop long. 20% de la classe,
est parvenu à tenir le délai initial (< 8 minutes).

```c
int array[2][2];

**array == *(*(array + 0) + 0) == *(array[0] + 0) == array[0][0]
```

```c
#define V int
#define K (int argc, char*argv[])
#define U main

V U K {
    printf("hello, world!");
}
```

```c
printf("4, 8");
```

## Installation de LiveShare

1. Lancer Visual code.
2. CTRL + MAJ + X (Extensions)
3. Chercher Live Share
4. Cliquer sur intaller
5. Cliquer sur reload
6. Cliquer sur ce [lien](https://prod.liveshare.vsengsaas.visualstudio.com/join?B39313CE8DA765ACF84DF36B13B83B8F7155)
7. Loguer vous avec GitHub
8. Suivez les instructions

## Compilation d'un fichier

1. Preprocessing (toutes les directives avec # et les commentaires)
2. Compilation (conversion C en langage machine)
3. Assemblage (link, conversion object en exécutable)
