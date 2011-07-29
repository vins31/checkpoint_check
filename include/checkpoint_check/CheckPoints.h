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

        /** Return the number of polygons
         * \return the number of polygons (polys.size())
         */
        int nbPolys() { return (int)polys.size();}

        /** Add a polygon in the list of polygons
         * \param p the polygon to add
         */
        void add(Poly* p);

        /** Tells if the point pt has its projection on the polygon number k
            inside the polygon k (to know if the point pt will go trough the
                                   polygon k)
         * \param pt the point to test
         * \param k  the number of the polygon to consider
         * \return true is the projection of pt over the polygon number k is
            inside this polygon, false else
         */
        bool in_poly_area(Vec pt, int k);

        /** Tells if the point pt is near the polygon
            WARNING: requires a CONVEX polygon
         * \param pt the point to test
         * \param k  then polygon to test if the point is near from
         * \return true if the norm2(pt-polys[k].center) < 2*radius2,
                   false else
         */
        bool in_area(Vec pt, int k);

        /** Tells on which side of the polygon we are
         * \param pt the point to test
         * \param k  the polygon to consider
         * \return 1 if we are on the side of the normal
                   0 if we are stuck to the polygon (should never occur)
                  -1 if we are on the opposite side of the normal
         */
        int side(Vec pt, int k);

    protected:
    private:


};

std::ostream& operator<< (std::ostream &os, CheckPoints const &cp);

/** Tells if you have an acute or obtuse angle
 * \param v1 the first vector which defines the sector of the angle
 * \param v2 the second vector
 * \param normal the normal to give an orientation to the space
 * \return -1 if the angle is obtuse
            1 if the angle is acute
 */
double angleSign(Vec v1, Vec v2, Vec normal);

#endif // CHECKPOINTS_H
