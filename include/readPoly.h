#ifndef READ_POLY_H
#define READ_POLY_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "CheckPoints.h"


CheckPoints* read_file(char* file);

Poly* parse_poly(char* buffer);

Vec* parse_vector(char* buffer);

#endif

