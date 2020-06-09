# Exercices

## Exercice 1

```c
struct date {
   unsigned char day : 5; // 0..31
   unsigned char month : 4; // 1..12
   unsigned short year_from_1973 : 7; // 1900..2027
};
```

00..99 --> 1900..2100 --> 16-bits

EPOCH (Timestamp UNIX) nombre de secondes écoulées depuis le
premier janvier 1970... 32-bits...

Comment optimiser le stockage ?

## Exercice 2

Écrire une structure pour décrire le registre `ADC12CTL2` du MSP430. Utiliser des types énumérés si nécessaire.

1. Datasheet...
2. Traduire la doc en une structure...
3. Créer des types énumérés si nécessaire...

19:13 -> Quelqu'un me présente sa solution...
