
// /!\ Généralement on met ça dans un fichier d'en-tête
extern double add(double a, double b);

// /!\ On n'exporte jamais les variables globales, c'est caca !
extern int i; // La déclaration de i est faite dans un autre module

int main() {
    i++;
    return add(23,i);
}
