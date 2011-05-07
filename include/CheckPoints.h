#ifndef CHECKPOINTS_H
#define CHECKPOINTS_H

#include <vector>

#include "Poly.h"

class CheckPoints
{
    public:
        std::vector<Poly*> polys;

        /** Default constructor */
        CheckPoints();

        void add(Poly* p);

        bool in_poly_area(Vec pt, int k);

    protected:
    private:

};

std::ostream& operator<< (std::ostream &os, CheckPoints const &cp);

double angleSign(Vec v1, Vec v2, Vec normal);

#endif // CHECKPOINTS_H
