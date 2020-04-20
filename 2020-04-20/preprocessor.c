
/*
#  Conversion en chaîne de caractère
## Concaténation
*/

#define TOTO "hello"
#define TATA "world"

#define H Hello
#define W World

#define TOSTR(A) #A
#define CONCAT(A, B) TOSTR(A) ## TOSTR(B)

#define ADDITION(A, B) (A + B)

int add(int a, int b) { return a + b; }
double fadd(double a, double b) { return a + b; }

int main() {
    int u = ADDITION(5, 6) * 2;
    double v = ADDITION(3.14, 6.26) * 1.2;
}
