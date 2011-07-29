#ifndef READ_POLY_H
#define READ_POLY_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "CheckPoints.h"

/** Read and parses the polygons (check points) of a given file
 * \param  The file to read the polygons from
 * \return The list of polygons read from the files
 */
CheckPoints* read_file(char* file);

/** Parse a buffer to a polygon
 * \param  The string to parse
 * \return The polygon of the string
 */
Poly* parse_poly(char* buffer);

/** Parse a buffer to a Vec (vertex/vector)
 * \param  The string to parse
 * \return The Vec of the string
 */
Vec* parse_vector(char* buffer);

#endif

