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
