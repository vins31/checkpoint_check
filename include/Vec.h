#ifndef VEC_H
#define VEC_H


class Vec
{
    public:
        double x;
        double y;
        double z;

        /** Default constructor, initialize all the components to 0 */
        Vec();

        /** 2D constructor (z=0)
         * \param x initialize x
         * \param y initialize y
         */
        Vec(double const &x, double const &y);

        /** 3D constructor
         * \param x initialize x
         * \param y initialize y
         * \param z initialize z
         */
        Vec(double const &x, double const &y, double const &z);

        /** Construct a vector from too vertices
         * \param start start vertex
         * \param end end vertex
         * \return end-start
         */
        void vect2vect(Vec const &start, Vec const &end);

        /** Copy a vector
         * \return a new vector with the same components
         */
        Vec copy();

        /** Calculate the square of the norm of the vector
         * \return the square of the norm of the vector
         */
        double norm2();

        /** Calculate the norm of the vector
         * \return the norm of the vector
         */
        double norm();

        /** Divide the components by the norm of the vector
         * \return the normalized vector
         */
        void normalize();

        /** Negate the components of the vector
         * \return the negated vector
         */
        void negate();

        /** Multiply all the components by the scalar lambda
         * \param lambda the scalar
         */
        void scalarProd(double const &lambda);

        /** Return a new vector with all its components multiplied by the scalar lambda
         * \param lambda the scalar
         * \ return the scalared vector
         */
        Vec scalarProduct(double const &lambda);

        /** Calculate the dot product between this and v
         * \param v the vector with which calculating the dot product
         * \return the value of the dot product
         */
        double dotProduct(Vec const &v);

        /** Calculate the cross product between this and v
         * \param v the vector with which calculating the cross product
         * \return the value of the cross product
         */
        Vec crossProduct(Vec v);

        /** Return the component by component addition
         * return the new vector
         */
        Vec operator+(Vec const &v);

        /** Return the component by component substraction
         * return the new vector
         */
        Vec operator-(Vec const &v);

        /** Component by component addition
         * return the new vector
         */
        Vec &operator+=(Vec const &v);

        /** Component by component addition
         * return the new vector
         */
        Vec &operator-=(Vec const &v);

        /** Test the equality between two vectors
         * return the equality test
         */
        bool operator==(Vec const &v);

        /** Assign the value of the current vector with the values of an other vector
         * return the assigned vector
         */
        Vec &operator=(Vec const &v);



    private:
        double _norm; //!< norm of the vector
        double _norm2; //!< norm^2 of the vector
};

#endif // VEC_H
