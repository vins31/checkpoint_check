#include "str.h"



char* trim(char* s)
{
    char* s2 = s+strlen(s)-1; /* ATTENTION SI strlen=0 !!!*/
    while (*s++ == ' ');
    s--;
    if (*s)
    {
        /* si la chaine contient que des expaces on déborde */
        while (*s2 == ' ')
        {
            *s2 = '\0';
            s2--;
        }
    }
    return s;
}


