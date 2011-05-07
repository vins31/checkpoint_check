#include <iostream>
#include <list>
#include <vector>
#include <string.h>

#include "Vec.h"
#include "readPoly.h"

using namespace std;

int main()
{
    Vec v(1,2,3);
    cout << v+v;
    char s[30];
    strcpy(s, "8 1 2");
    Vec* v2 = parse_vector(s);
    cout << *v2 << std::endl;

    char s2[300];
    strcpy(s2, "0 1 2 ; 4 5 6 ; 7 8 9");
    Poly* p = parse_poly(s2);
    cout << *p  << std::endl;

    CheckPoints* cp = read_file((char*)"cp1.txt");
    cout << *cp  << std::endl;

    return 0;
}
