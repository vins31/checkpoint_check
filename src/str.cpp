#include "checkpoint_check/str.h"



char* trim(char* s)
{
    char* s2 = s+strlen(s)-1; /* DANGEROUS whether strlen=0 !!!*/
    while (*s++ == ' ');
    s--;
    if (*s)
    {
        /* if the string contains only space => segfault ! */
        while (*s2 == ' ')
        {
            *s2 = '\0';
            s2--;
        }
    }
    return s;
}

char* strtok_r2(char *ptr, const char *sep, char **end)
{
    if (!ptr)
        /* we got NULL input so then we get our last position instead */
        ptr = *end;

    /* pass all letters that are including in the separator string */
    while (*ptr && strchr(sep, *ptr))
        ++ptr;

    if (*ptr) {
        /* so this is where the next piece of string starts */
        char *start = ptr;

        /* set the end pointer to the first byte after the start */
        *end = start + 1;

        /* scan through the string to find where it ends, it ends on a
           null byte or a character that exists in the separator string */
        while (**end && !strchr(sep, **end))
            ++*end;

        if (**end) {
            /* the end is not a null byte */
            **end = '\0';  /* zero terminate it! */
            ++*end;        /* advance last pointer to beyond the null byte */
        }

        return start; /* return the position where the string starts */
    }

    /* we ended up on a null byte, there are no more strings to find! */
    return NULL;
}


// needed a second strtok because there are two loops
char *strtok2(char *chaine_src, char *separateur)
{
	char* res = NULL;
	static char* src = NULL;
	static int j = 0;
	if (chaine_src!=NULL)
	{
		src = chaine_src;
		j = 0;
	}

	int l = strlen(src);
	while ((j<l) && (res==NULL))
	{
		res = strchr(separateur, src[j]);
		j++;
	}
	return &(src[0]) + j-1;

}
