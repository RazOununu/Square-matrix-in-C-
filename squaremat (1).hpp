//vanunuraz@gmail.com
#ifndef matrix_hpp
#define matrix_hpp
#include <iostream>
namespace matOper{
    class Squaremat{
    private:
        int size;//square matrix
        double** data;
        void copy(const Squaremat& other);//helper function to copy data
    public:
        Squaremat(int n);//constructor
        //rule of three
        Squaremat(const Squaremat& other);//copy constructor
        Squaremat& operator=(const Squaremat& other);//operator=
        ~Squaremat();//destructor

        int getSize() const{
            return size;
        }

        //Operator overloading
        //const on 2 object to not change the object and return a new object
        Squaremat operator+(const Squaremat& other) const;
        //2 - -->with argument and without
        Squaremat operator-(const Squaremat& other) const;
        Squaremat operator-() const;
        //2 * with different arguments
        Squaremat operator*(const Squaremat& other) const;
        Squaremat operator*(double scalar) const;
        //2 % with different arguments
        Squaremat operator%(const Squaremat& other) const;//multiply
        Squaremat operator%(int num) const;
        Squaremat operator/(double scalar) const;
        Squaremat operator^(int power) const;
        Squaremat operator++() const;//prefix
        Squaremat operator++(int) const;//postfix
        Squaremat operator--() const;//prefix
        Squaremat operator--(int) const;//postfix
        Squaremat operator~() const;
        //we asked to implement the operator[] for weriting and reading
        //return the row of the matrix
        const double* operator[] (int i) const;//just for reading(first const is pointer)
        double* operator[] (int i);//also for weriting
        int sumMatrix() const;
        bool operator==(const Squaremat& other) const;
        bool operator!=(const Squaremat& other) const;
        bool operator<(const Squaremat& other) const;
        bool operator>(const Squaremat& other) const;
        bool operator<=(const Squaremat& other) const;
        bool operator>=(const Squaremat& other) const;
        static double computeDet(const Squaremat& matrix);
        double operator!() const;

        //this operators make change in this object and its allows to threding
        Squaremat& operator+=(const Squaremat& other);
        Squaremat& operator-=(const Squaremat& other);
        Squaremat& operator*=(const Squaremat& other); //mult 2 matrices
        Squaremat& operator*=(double scalar);//mult by scalar
        Squaremat& operator/=(double scalar);
        Squaremat& operator%=(const Squaremat& other);//modulo 2 matrices
        Squaremat& operator%=(int scalar);//modulo by scalar  
        
        //this function belongs to the another implementation
        friend std::ostream& operator<<(std::ostream& os, const Squaremat& mat);
    };
    //scalar*mat, out of the class
    Squaremat operator*(double scalar, const Squaremat& mat);
}
#endif    