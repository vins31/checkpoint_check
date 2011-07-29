#include "checkpoint_check/CheckPoints.h"
#include <time.h>

CheckPoints::CheckPoints()
{
    //ctor
}

void CheckPoints::add(Poly* p)
{
    polys.push_back(p);
}

// REQUIRES A CONVEX POLYGON !!!!
bool CheckPoints::in_poly_area(Vec pt, int k)
{
    int i;
    if (k<0 or k>= (int)polys.size())
    {
        std::cerr << "Invalid integer k" << k << "in in_poly_area" << std::endl;
        return false;
    }
    int nb_verts = (int)polys[k]->verts.size();
    if (nb_verts < 3)
    {
        std::cerr << "Invalid polygon k" << k << "in in_poly_area" << std::endl;
        return false;
    }
	std::vector<Vec> vects;
	for (i = 0; i < nb_verts; ++i )
	{
	    Vec vect;
		vect.vect2vect(pt, *((polys[k]->verts)[i]));
		vects.push_back(vect);
	}

	double si = angleSign(vects[0], vects[1], polys[k]->normal());
	for (i=0 ; i<nb_verts ; i++)
	{
        double si2 = angleSign(vects[i], vects[(i+1)%(nb_verts)], polys[k]->normal());
		if (si2+si == 0)
			return false;
	}
	return true; // si and all the si2 are the same, some can be nil
}

bool CheckPoints::in_area(Vec pt, int k)
{
    Vec v;
    v.vect2vect(polys[k]->center(), pt);
    return (v.norm2() < 2*polys[k]->radius2());
}

int CheckPoints::side(Vec pt, int k)
{
    Vec v;
    v.vect2vect(polys[k]->center(), pt);
    double dotp = polys[k]->normal().dotProduct(v);
    if (dotp>0)
    {
        return 1;
    }
    else if(dotp == 0)
    {
        return 0;
    }
    else
    {
        return -1;
    }

}

std::ostream& operator<< (std::ostream &os, CheckPoints const &cp)
{
    os << "CheckPoints:" << std::endl;
    for ( size_t i = 0, size = cp.polys.size(); i < size; ++i )
    {
        os << "  [" << i << "] ";
        std::cout << *(cp.polys[i]) << std::endl;
    }
    return os;
}

double angleSign(Vec v1, Vec v2, Vec normal)
{
    double sign = normal.dotProduct(v1.crossProduct(v2));
    if (sign < 0)
        return -1;
    return 1;
}
