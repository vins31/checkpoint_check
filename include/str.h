#ifndef STR_H
#define STR_H


#include <string.h>

/** Remove leading and trailing whitespaces
 * \param the string to clean
 * \return a new string without leading and trailing whitespaces
 */
char* trim(char* s);

/** An other strtok()
 */
char *strtok2(char *chaine_src, char *separateur);
#endif
