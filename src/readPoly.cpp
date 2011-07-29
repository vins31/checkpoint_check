#include <iostream>

#include "checkpoint_check/readPoly.h"
#include "checkpoint_check/str.h"

#define LIN_MAX 30000

CheckPoints* read_file(char* file)
{

	CheckPoints* cp = new CheckPoints;
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
        cp->add(parse_poly(line));
	}
	fclose(pfile);
	return cp;
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
    char* saveptr;
    double vecl[3];
    int i = 0;
    Vec* v = new Vec();
    /* We cannot use strtok else we would erase the static variable initialized
       by the call to strtok in parse_poly */
    //ccoord =  strtok2(trim(buffer), (char*)" ");
    ccoord =  strtok_r(trim(buffer), (char*)" ", &saveptr);
    while (ccoord!=NULL && i<3)
    {
        //std::cout << ccoord << std::endl;
        vecl[i] = atof(ccoord);
        ccoord =  strtok_r(NULL, (char*)" ", &saveptr);
        i++;
    }
    v->x = vecl[0];
    v->y = vecl[1];
    v->z = vecl[2];
    return v;
}
