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

    protected:
    private:

};

std::ostream& operator<< (std::ostream &os, CheckPoints const &cp);

#endif // CHECKPOINTS_H
