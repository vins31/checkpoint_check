#include "Poly.h"

Poly::Poly()
{

}

Poly::~Poly()
{

}

void Poly::addVertex(Vec* v)
{
    verts.push_back(v);
}

std::ostream& operator<< (std::ostream &os, Poly const &p)
{
    os << "Poly:" << std::endl;
    for ( size_t i = 0, size = p.verts.size(); i < size; ++i )
    {
        os << "[" << i << "] ";
        std::cout << *(p.verts[i]);
    }
    return os;
}
