#ifndef STR_H
#define STR_H


#include <string.h>

/** Remove leading and trailing whitespaces
 * \param the string to clean
 * \return a new string without leading and trailing whitespaces
 */
char* trim(char* s);

/** An other strtok() which works a bit differently
 */
char *strtok2(char *chaine_src, char *separateur);

/** Portable implementation of strtok_r()
*/
char* strtok_r2(char *ptr, const char *sep, char **end);
#endif
