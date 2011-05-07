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
    strcpy(s, "0 1 2");
    Vec* v2 = parse_vector(s);
    cout << *v2;

    return 0;
}
