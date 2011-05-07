#include "CheckPoints.h"

CheckPoints::CheckPoints()
{
    //ctor
}

void CheckPoints::add(Poly* p)
{
    polys.push_back(p);
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
