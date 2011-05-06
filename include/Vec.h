#ifndef VEC_H
#define VEC_H


class Vec
{
    public:
        double x;
        double y;
        double z;

        /** Default constructor */
        Vec();

        Vec(double const &x, double const &y);

        Vec(double const &x, double const &y, double const &z);

        /** Construct a vector from too vertices */
        void vect2vect(Vec const &start, Vec const &end);

        Vec copy();

        double norm2();

        double norm();

        void normalize();

        void negate();

        void scalarProd(double const &lambda);

        Vec scalarProduct(double const &lambda);

        /** Calculate the dot product between this and v
         * \param v the vector with which calculating the dot product
         * \return The value of the dot product
         */
        Vec dotProduct(Vec const &v);


        Vec crossProduct(Vec v);

        Vec operator+(Vec const &v);

        Vec operator-(Vec const &v);

        void operator+=(Vec const &v);

        void operator-=(Vec const &v);

        bool operator==(Vec const &v);

        Vec operator=(Vec const &v);



    protected:

    private:
        double norm; //!< norm of the vector
        double norm2; //!< norm^2 of the vector
};

#endif // VEC_H
