
#include "readPoly.h"
#include "str.h"

#define LIN_MAX 30000

void read_text(char* file)
{

	/* Lecture du texte */
	FILE * pfile;
	char line[LIN_MAX + 1];
	pfile = fopen(file, "r");
	if (pfile==NULL)
	{
	    perror("Impossible to read the text.\n");
        exit (EXIT_FAILURE);
	}
	while(fgets(line, LIN_MAX + 1, pfile) != NULL)
	{
        line[LIN_MAX] = '\0';
	}
	fclose(pfile);
}

Poly* parse_poly(char* buffer)
{
    char* cvec;
    Poly* poly = new Poly();
    cvec =  strtok(buffer, ";");
    while (cvec!=NULL)
    {
        poly->addVertex(parse_vector(cvec));
        cvec =  strtok(NULL, ";");
    }
    return poly;
}

Vec* parse_vector(char* buffer)
{
    char* ccoord;
    double vecl[3];
    int i = 0;
    Vec* v = new Vec();
    ccoord =  strtok2(buffer, (char*)" ");
    while (ccoord!=NULL && i<3)
    {
        vecl[i] = atof(ccoord);
        ccoord =  strtok2(NULL, (char*)" ");
        i++;
    }
    v->x = vecl[0];
    v->y = vecl[1];
    v->z = vecl[2];
    return v;
}
