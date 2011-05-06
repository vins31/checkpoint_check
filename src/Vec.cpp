#include "Vec.h"

Vec::Vec()
{
    x     = 0;
    y     = 0;
    z     = 0;
    norm  = -1;
    norm2 = -1;

}

Vec::Vec(double const &x, double const &y, double const &z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vec::Vec(double const &x, double const &y)
{
    Vec(x,y,0);
}

Vec::vect2vect(Vec const &start, Vec const &end)
{
    x = end.x - start.x;
    y = end.y - start.y;
    z = end.z - start.z;
}

Vec::copy()
{
    return new Vec(x,y,z);
}

Vec::norm2()
{
    if (norm2 == -1)
    {
        norm2 = x*x + y*y + z*z;
    }
    return norm2;
}

Vec::norm()
{
    if (norm == -1)
    {
        norm = sqrt(norm2);
    }
    return norm;
}

Vec::normalize()
{
    x /= this->norm();
    y /= this->norm();
    z /= this->norm();
}

Vec::negate()
{
    x = -x;
    y = -y;
    z = -z;
}

Vec::scalarProd(double const &lambda)
{
    x *= lambda;
    y *= lambda;
    z *= lambda;
}

Vec::scalarProduct(double const &lambda)
{
    return new Vec(x * lambda, y * lambda, z * lambda);
}

Vec::dotProduct(Vec const &v)
{
    return x*v.x + y*v.y + z*v.z;
}

Vec::crossProduct(Vec v)
{
    return new Vec(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
}

