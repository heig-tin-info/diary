#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
// sugus   abcba abba

// Divide and Conquer

/*
char str[] = "sugus";
              "ugu"
               "g"

str[0] == str[n - 1];
str[1] == str[n - 2]; // <---

*/

#if 0
// O(n) time, O(n) space
bool pal(char s[], int size) {
    return size <= 0 || ((s[0] == s[size-1]) && pal(&s[1], size - 2));
}
#else
// O(n) time, O(1) space
bool pal(char s[], int size) {
    for(int i = 0 ; i < (size/2); i++)
    {
        if(!(s[i] == s[size - i - 1]) )
            return false;
    }
    return true;
}
#endif


int main()
{
    char str[] = "sugus";
    int size = strlen(str);

    if(pal(str, size))
        printf("%s est un palindrome !\n",str);
    else
        printf("%s n'est pas un palindrome !\n",str);
}

