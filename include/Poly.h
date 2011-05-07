#ifndef POLY_H
#define POLY_H

#include <vector>
#include "Vec.h"

class Poly
{
    public:
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
        std::vector<Vec*> verts; //!< Member variable "*verts"
        Vec center; //!< Member variable "center"
        Vec normal; //!< Member variable "normal"
};

#endif // POLY_H
