#include "Poly.h"

Poly::Poly()
{
    center = Vec();
    normal = Vec();
}

Poly::~Poly()
{

}

void Poly::addVertex(Vec* v)
{
    verts.push_back(v);
}

void Poly::calcCenter()
{
    center.zero();
    for ( size_t i = 0, size = verts.size(); i < size; ++i )
    {
        center += verts[i];
    }
    center /= verts.size();
}

std::ostream& operator<< (std::ostream &os, Poly const &p)
{
    os << "Poly:" << std::endl;
    for ( size_t i = 0, size = p.verts.size(); i < size; ++i )
    {
        os << "     [" << i << "] ";
        std::cout << *(p.verts[i]);
    }
    return os;
}
