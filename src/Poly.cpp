#include "Poly.h"

Poly::Poly()
{
    _center = Vec();
    _normal = Vec();
    _radius = 0;
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
    _center.zero();
    for ( size_t i = 0, size = verts.size(); i < size; ++i )
    {
        _center += *(verts[i]);
    }
    _center /= verts.size();
}

void Poly::calcNormal()
{
    _normal.zero();
    if (verts.size() > 2)
    {
        Vec v1;
        Vec v2;
        v1.vect2vect(*(verts[0]), *(verts[1]));
        v2.vect2vect(*(verts[0]), *(verts[2]));
        _normal = v1.crossProduct(v2);
    }
}

void Poly::calcRadius()
{
    if (verts.size() > 0)
    {
        Vec v;
        v.vect2vect(center(),*(verts[0]));
        _radius = v.norm();
    }
}


std::ostream& operator<< (std::ostream &os, Poly &p)
{
    os << "Poly   center: " << p.center() << " ; normal: " << p.normal() << "radius: " << p.radius() << std::endl;
    for ( size_t i = 0, size = p.verts.size(); i < size; ++i )
    {
        os << "     [" << i << "] ";
        std::cout << *(p.verts[i])  << std::endl ;
    }
    return os;
}
