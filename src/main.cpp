#include <iostream>
#include <list>
#include <vector>
#include <string.h>

#include "checkpoint_check/Vec.h"
#include "checkpoint_check/readPoly.h"
#include "checkpoint_check/Racer.h"

using namespace std;

int main()
{
    Vec v(0.5,0.5,3);
//    cout << v+v << std::endl;
//    char s[30];
//    strcpy(s, "8 1 2");
//    Vec* v2 = parse_vector(s);
//    cout << *v2 << std::endl;
//
//    char s2[300];
//    strcpy(s2, "0 1 2 ; 4 5 6 ; 7 8 9");
//    Poly* p = parse_poly(s2);
//    cout << *p  << std::endl;

    CheckPoints* cp = read_file((char*)"cp1.txt");
//    cout << *cp  << std::endl;

//    cout << cp->in_poly_area(v, 0) << endl;

    Racer racer("Vins", "f-16", 2, cp);
    cout << "check: " << racer.check(0.3, 0.3, -100, 20) << endl;
    cout << "check: " << racer.check(0.3, 0.3, -0.2, 20) << endl;
    cout << "check: " << racer.check(0.3, 0.3, 0.2, 20) << endl;
    cout << "check: " << racer.check(0.5, 0.5, 5, 20) << endl;
    cout << "check: " << racer.check(0.5, 0.5, 9.5, 20) << endl;
    cout << "check: " << racer.check(0.5, 0.5, 10.5, 20) << endl;
    cout << "check: " << racer.check(0.5, 0.5, 19.5, 20) << endl;
    cout << "check: " << racer.check(0.5, 0.5, 20.5, 20) << endl;
    cout << "check: " << racer.check(0.5, 0.5, 29.5, 20) << endl;
    cout << "check: " << racer.check(0.5, 0.5, 30.5, 30) << endl;

    cout << "check11: " << racer.check(0.3, 0.3, -0.2, 20) << endl;
    cout << "check: " << racer.check(0.3, 0.3, 0.2, 20) << endl;
    cout << "check: " << racer.check(0.5, 0.5, 5, 20) << endl;
    cout << "check: " << racer.check(10.5, 10.5, 9.5, 20) << endl;
    cout << "checkE: " << racer.check(10.5, 10.5, 10.5, 20) << endl;
    cout << "check: " << racer.check(0.5, 0.5, 9.5, 20) << endl;
    cout << "check1: " << racer.check(0.5, 0.5, 10.5, 20) << endl;
    cout << "check: " << racer.check(0.5, 0.5, 19.5, 20) << endl;
    cout << "check: " << racer.check(0.5, 0.5, 20.5, 20) << endl;
    cout << "check: " << racer.check(0.5, 0.5, 29.5, 20) << endl;
    cout << "check: " << racer.check(0.5, 0.5, 30.5, 20) << endl;

    cout << racer << endl;

    return 0;
}
