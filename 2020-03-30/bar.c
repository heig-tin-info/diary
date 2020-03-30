#include <stdio.h>
#include "foo.h"
#include "version.h"

#define TOTO 23

int main() {
    printf("%d\n", TOTO + foo(10));
    version(stdout, 2.1, "Yves Chevallier");
    #include "pp.h" // A NE JAMAIS FAIRE
}
