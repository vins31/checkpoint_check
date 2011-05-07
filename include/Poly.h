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

        /** Access center (mean of the vertices)
         * \return The current value of center
         */
        Vec center() { return _center; }

        /** Access normal (cross product of 2 edges)
         * \return The current value of normal
         */
        Vec normal() { return _normal; }

        /** Access radius (distance between the center and a vertex)
         * \return The current value of radius
         */
        double radius() { return _radius; }
    protected:
    private:
        Vec _center; //!< Member variable "center"
        Vec _normal; //!< Member variable "normal"
        double _radius; //!< Member variable "radius"

        void calcCenter();

        void calcNormal();

        void calcRadius();
};

std::ostream& operator<< (std::ostream &os, Poly const &p);

#endif // POLY_H
