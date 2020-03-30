#include <stdio.h>

void version(FILE* fp, double version, char* author) {
    fprintf(fp, "Version %.1f copyright(c) HEIG-VD %s", version, author);
}
