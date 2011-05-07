#ifndef POLY_H
#define POLY_H

#include <iostream>
#include <vector>
#include "Vec.h"

class Poly
{
    public:

        std::vector<Vec*> verts; //!< Member variable "*verts"

        /** Default constructor */
        Poly();
        /** Default destructor */
        ~Poly();
        /** Access center
         * \return The current value of center
         */

        void addVertex(Vec* v);

        //Vec Getcenter() { return center; }
        /** Access normal
         * \return The current value of normal
         */
        //Vec Getnormal() { return normal; }
    protected:
    private:
        Vec center; //!< Member variable "center"
        Vec normal; //!< Member variable "normal"
};

std::ostream& operator<< (std::ostream &os, Poly const &p);

#endif // POLY_H
