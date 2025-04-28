//vanunuraz@gmail.com
#include "squaremat.hpp"
#include "myModulo.hpp"
#include <iostream>
#include <stdexcept>
namespace matOper{
    Squaremat::Squaremat(int n): size(n){
        if(n <= 0){
            throw std::invalid_argument("Invalid size, must be positive");
        }
        data = new double*[size];//array of pointers
        for(int i = 0; i < size; i++){
            data[i] = new double[size];//every pointer points to an array of doubles
            for(int j = 0; j < size; j++){
                data[i][j] = 0.0;//initialize to zero
            }
        }
    }

    void Squaremat::copy(const Squaremat& other) {
        size = other.size;
        data = new double*[size];
        for (int i = 0; i < size; ++i) {
            data[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                data[i][j] = other.data[i][j];//deep copy of each element
            }
        }
    }

    Squaremat::Squaremat(const Squaremat& other){
        copy(other);
    }

    Squaremat& Squaremat::operator=(const Squaremat& other){
        if(this != &other){//avoid = to same object and pointer to same object
            //first delete the previous data
        for(int i = 0; i < size; i++){
            delete[] data[i];
        }
        delete[] data;
        //copy the datas
        copy(other);
        }
        return *this;//return the current object
    }

    Squaremat::~Squaremat(){
        for(int i = 0; i < size; i++){
            delete[] data[i];//delete each row
        }
        delete[] data;//delete the array of pointers
    }

    //implementation of operator overloading
    Squaremat Squaremat::operator+(const Squaremat& other) const{
        if(size!=other.size){
            throw std::invalid_argument("the two matrices must be the same size");
        }
        Squaremat res(size);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                res.data[i][j] = data[i][j]+other.data[i][j];
            }
        }
        return res;
    }

    Squaremat Squaremat::operator-(const Squaremat& other)const{
        if(size!=other.size){
            throw std::invalid_argument("the two matrices must be the same size");    
        }
        Squaremat res(size);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                res.data[i][j] = data[i][j]-other.data[i][j];
            }
        }
        return res;
    }

    Squaremat Squaremat::operator-() const{
        Squaremat res(size);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                res.data[i][j] = data[i][j]*(-1);//+*-=-,  -*-=+
            }
        }
        return res;
    }

    Squaremat Squaremat::operator*(const Squaremat& other) const{
        if(size!=other.size){
            throw std::invalid_argument("the two matrices must be the same size");
        }
        Squaremat res(size);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                res.data[i][j] = 0;
                for(int k = 0; k < size; k++){//mult the row of the first matrix by the column of the second matrix
                    res.data[i][j] += data[i][k]*other.data[k][j];
                }
            }
        }
        return res;
    }

    Squaremat Squaremat::operator*(double scalar) const{
        Squaremat res(size);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                res.data[i][j] = data[i][j]*scalar;
            }
        }
        return res;
    }

    Squaremat Squaremat::operator%(const Squaremat& other) const{
        if(size!=other.size){
            throw std::invalid_argument("the two matrices must be the same size");
        }
        Squaremat res(size);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                res.data[i][j] = data[i][j]*other.data[i][j];//mult every element of the first matrix by the  element of the second matrix at the same position
            }
        }
        return res;
    }

    Squaremat Squaremat::operator%(int num) const{
        Squaremat res(size);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                res.data[i][j] = myModulo(data[i][j], num);//modulo every element of the matrix by the number
            }
        }
        return res;
    }

    Squaremat Squaremat::operator/(double scalar) const{
        if(scalar == 0){
            throw std::invalid_argument("division by zero is not allowed");
        }
        Squaremat res(size);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                res.data[i][j] = data[i][j]/scalar;
            }
        }
        return res;
    }

    Squaremat Squaremat::operator^(int power) const{
        if (power < 0){
            throw std::invalid_argument("this operation is not valid for negative powers");
        }
        if (power == 0){
            //return the identity matrix
            Squaremat identity(size);
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < size; ++j){
                    if (i == j){
                        identity.data[i][j] = 1;
                    }
                    else{
                        identity.data[i][j] = 0;
                    }
                }
            }
            return identity;
        }
        Squaremat res(*this);//deep copy of the current matrix
        for (int i = 1; i < power; ++i) {
            res = res*(*this);
        }
    
        return res;
    }
    

    Squaremat Squaremat::operator++() const{
        Squaremat res(size);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                res.data[i][j] = data[i][j]+1;
            }
        }
        return res;
    }

    Squaremat Squaremat::operator++(int) const{
        Squaremat res(*this);
        Squaremat change(*this);
        ++(change);//use my prefix implementation
        return res;
    }

    Squaremat Squaremat::operator--() const{
        Squaremat res(size);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                res.data[i][j] = data[i][j]-1;
            }
        }
        return res;
    }
    Squaremat Squaremat::operator--(int) const{
        Squaremat res(*this);
        Squaremat change(*this);
        --(change);//use my prefix implementation
        return res;
    }

    Squaremat Squaremat::operator~() const{
        Squaremat res(size);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                res.data[i][j] = data[j][i];//transpose the matrix
            }
        }
        return res;
    }

    //same implementation for the operator[] for reading and writing
    const double* Squaremat::operator[] (int i) const{
        if(i < 0 || i >= size){
            throw std::out_of_range("index out of range");
        }
        return data[i];
    }

    double* Squaremat::operator[] (int i){
        if(i < 0 || i >= size){
            throw std::out_of_range("index out of range");
        }
        return data[i];
    }

    //helper funtion used in all the operators that compare the two matrices
    int Squaremat::sumMatrix() const{
        int sum = 0;
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                sum += data[i][j];
            }
        }
        return sum;
    }

    bool Squaremat::operator==(const Squaremat& other) const{
        return this->sumMatrix() == other.sumMatrix();
    }

    bool Squaremat::operator!=(const Squaremat& other) const{
        return this->sumMatrix() != other.sumMatrix();
    }

    bool Squaremat::operator<(const Squaremat& other) const{
        return this->sumMatrix() < other.sumMatrix();
    }

    bool Squaremat::operator>(const Squaremat& other) const{
        return this->sumMatrix() > other.sumMatrix();
    }

    bool Squaremat::operator<=(const Squaremat& other) const{
        return this->sumMatrix() <= other.sumMatrix();
    }

    bool Squaremat::operator>=(const Squaremat& other) const{
        return this->sumMatrix() >= other.sumMatrix();
    }

    double Squaremat::computeDet(const Squaremat& matrix){
        if(matrix.size == 1){
            return matrix[0][0];//use my operator[]
        }
        if(matrix.size == 2){
            return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
        }
        //size> 2
        double det = 0;
        for(int i = 0; i < matrix.size; i++){//det by col of the first row
            Squaremat minorMatrix(matrix.size - 1);//minor matrix delete the first row and the ith col
            for(int j = 1; j < matrix.size; j++){//start from the second row because compute det by the first row
                int col= 0;
                for(int k = 0; k < matrix.size; k++){//loop col
                    if(k != i){////skip the i col
                        minorMatrix[j-1][col] = matrix[j][k];//if k != i, add the element to the minor matrix
                        col++;
                    }
                }
            }
            //odd +, even -
            det+= (i % 2 == 0 ? 1 : -1)*matrix[0][i]*computeDet(minorMatrix);
        }
        return det;
    }

    double Squaremat::operator!() const{
        return computeDet(*this);
    }

    //change this with my implementation to +=, -=, *=, /=, %=
    Squaremat& Squaremat::operator+=(const Squaremat& other){
        *this = *this+other;
        return *this;
    }

    Squaremat& Squaremat::operator-=(const Squaremat& other){
        *this = *this-other;
        return *this;
    }

    Squaremat& Squaremat::operator*=(const Squaremat& other){
        *this = *this*other;
        return *this;
    }

    Squaremat& Squaremat::operator*=(double scalar){
        *this = *this*scalar;
        return *this;   
    }

    Squaremat& Squaremat::operator/=(double scalar){
        *this = *this/scalar;
        return *this;
    }

    Squaremat& Squaremat::operator%=(const Squaremat& other){
        *this = *this%other;
        return *this;
    }

    Squaremat& Squaremat::operator%=(int scalar){
        *this = *this%scalar;
        return *this;
    }

    //std is external library and ostream is used to print the matrix
    std::ostream& operator<<(std::ostream& os, const Squaremat& matrix){//os is the output stream
        for(int i = 0; i < matrix.size; i++){
            for(int j = 0; j < matrix.size; j++){
                os << matrix[i][j] << " ";
            }
            os << std::endl;// /n
        }
        return os;
    }    
    //now can use std::cout << matrix;

    //scalar*mat, out of the class
    Squaremat operator*(double scalar, const Squaremat& mat){
        return mat*scalar;//use my implementation for operator*
    }    
}    