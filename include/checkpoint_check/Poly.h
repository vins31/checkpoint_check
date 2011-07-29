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

        /** Add a vertex in the polygon
         * \param The vertex to add
         */
        void addVertex(Vec* v);

        /** Access center (mean of the vertices)
         * \return The current value of center
         */
        Vec center() { if (_center == Vec(0,0,0)) {calcCenter();} return _center; }

        /** Access normal (cross product of 2 edges)
         * \return The current value of normal
         */
        Vec normal() { if (_normal == Vec(0,0,0)) {calcNormal();} return _normal; }

        /** Access radius (distance between the center and a vertex)
         * \return The current value of radius
         */
        double radius() { if (_radius == 0) {calcRadius();} return _radius; }

        /** Access radius^2 (distance between the center and a vertex)
         * \return The current value of radius
         */
        double radius2() { if (_radius2 == 0) {calcRadius2();} return _radius2; }

    protected:
    private:
        Vec _center; //!< Member variable "center"
        Vec _normal; //!< Member variable "normal"
        double _radius; //!< Member variable "radius"
        double _radius2; //!< Member variable "radius2" = _radius * _radius

        /** Calculate the center of the polygon
         */
        void calcCenter();

        /** Calculate the normal of the polygon
         */
        void calcNormal();

        /** Calculate the radius of the polygon
         */
        void calcRadius();

        /** Calculate the radius^2 of the polygon
         */
        void calcRadius2();
};

std::ostream& operator<< (std::ostream &os, Poly &p);

#endif // POLY_H
