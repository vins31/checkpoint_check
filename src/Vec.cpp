#include "math.h"
#include "Vec.h"


Vec::Vec()
{
    x     = 0;
    y     = 0;
    z     = 0;
    _norm  = -1;
    _norm2 = -1;

}

Vec::Vec(double const &x, double const &y, double const &z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    _norm  = -1;
    _norm2 = -1;
}

Vec::Vec(double const &x, double const &y)
{
    Vec(x,y,0);
}

void Vec::vect2vect(Vec const &start, Vec const &end)
{
    x = end.x - start.x;
    y = end.y - start.y;
    z = end.z - start.z;
}

void Vec::zero()
{
    this->Vec();
}

Vec Vec::copy()
{
    Vec* v = new Vec(x,y,z);
    return *v;
}

double Vec::norm2()
{
    if (_norm2 == -1)
    {
        _norm2 = x*x + y*y + z*z;
    }
    return _norm2;
}

double Vec::norm()
{
    if (_norm == -1)
    {
        _norm = sqrt(_norm2);
    }
    return _norm;
}

void Vec::normalize()
{
    x /= this->norm();
    y /= this->norm();
    z /= this->norm();
}

void Vec::negate()
{
    x = -x;
    y = -y;
    z = -z;
}

void Vec::scalarProd(double const &lambda)
{
    x *= lambda;
    y *= lambda;
    z *= lambda;
}

Vec Vec::scalarProduct(double const &lambda)
{
    return *(new Vec(x * lambda, y * lambda, z * lambda));
}

double Vec::dotProduct(Vec const &v)
{
    return x*v.x + y*v.y + z*v.z;
}

Vec Vec::crossProduct(Vec v)
{
    return *(new Vec(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x));
}

Vec Vec::operator+(Vec const &v)
{
    return *(new Vec(x+v.x, y+v.y, z+v.z));
}

Vec Vec::operator-(Vec const &v)
{
    return *(new Vec(x-v.x, y-v.y, z-v.z));
}

Vec& Vec::operator+=(Vec const &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vec& Vec::operator-=(Vec const &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return *this;
}

Vec& Vec::operator*=(int lambda)
{
    x *= lambda;
    y *= lambda;
    z *= lambda;
    return *this;
}

Vec& Vec::operator/=(int lambda)
{
    x /= lambda;
    y /= lambda;
    z /= lambda;
    return *this;
}

bool Vec::operator==(Vec const &v)
{
    return (x==v.x)&&(y==v.y)&&(z==v.z);
}

Vec& Vec::operator=(Vec const &v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return *this;
}

std::ostream& operator<< (std::ostream &os, Vec const &v)
{
    std::cout << "Vec: x=" << v.x << ", y=" << v.y << ", z=" << v.z << std::endl;
    return os;
}
