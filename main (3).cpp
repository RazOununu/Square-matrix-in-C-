//vanunuraz@gmail.com
#include "squaremat.hpp"
#include "myModulo.hpp"
#include <iostream>
using namespace matOper;
int main() {
    //mat1
    Squaremat mat1(3);
    mat1[0][0] = 1.0; mat1[0][1] = 2.0; mat1[0][2] = 3.0; mat1[1][0] = 4.0; mat1[1][1] = 5.0; mat1[1][2] = 6.0; mat1[2][0] = 7.0;
    mat1[2][1] = 8.0; mat1[2][2] = 9.0;
    std::cout<<"Matrix 1:\n"<<mat1<<std::endl;
    //mat2
    Squaremat mat2(3);
    mat2[0][0] = 1; mat2[0][1] = 4; mat2[0][2] = 7; mat2[1][0] = 2; mat2[1][1] = 5; mat2[1][2] = 8; mat2[2][0] = 3;
    mat2[2][1] = 6; mat2[2][2] = 9;
    std::cout<<"Matrix 2:\n"<< mat2<<std::endl;

    //operators between two matrices
    //operator+
    Squaremat sum = mat1+mat2;
    std::cout<<"Matrix sum:\n"<<sum<<std::endl;
    //operator-
    Squaremat rest = mat1-mat2;
    std::cout<<"Matrix rest:\n"<<rest<<std::endl;
    //operator*
    Squaremat mult = mat1* mat2;
    std::cout<<"Matrix mult:\n"<<rest<<std::endl;
    //operator%
    Squaremat mult_each_cell = mat1%mat2;
    std::cout<<"Matrix mult_each_cell:\n"<<mult_each_cell<<std::endl;
    //compare operators
    //operator==
    bool isEqual = (mat1== mat2);
    std::cout << "Matrixs mat1&mat2 return "<<(isEqual?"True":"False")<<"for the operator="<<std::endl;
    //operator!=
    bool isNotEqual = (mat1!=mat2);
    std::cout << "Matrixs mat1&mat2 return "<<(isNotEqual?"True":"False")<<"for the operator!="<<std::endl;
    //operator<
    bool isLess = (mat1<mat2);
    std::cout << "Matrixs mat1&mat2 return "<<(isLess?"True":"False")<<"for the operator<"<<std::endl;
    //operator>
    bool isGreater = (mat1>mat2);
    std::cout << "Matrixs mat1&mat2 return "<<(isGreater?"True":"False")<<"for the operator>"<<std::endl;
    //operator<=
    bool isLessOrEqual = (mat1<=mat2);
    std::cout << "Matrixs mat1&mat2 return "<<(isLessOrEqual?"True":"False")<<"for the operator<="<<std::endl;
    bool isGreaterOrEqual = (mat1>=mat2);
    std::cout << "Matrixs mat1&mat2 return "<<(isGreaterOrEqual?"True":"False")<<"for the operator>="<<std::endl;

    //operators between matrix and scalar
    //operator*
    Squaremat mult_by_scalar = mat1*5.5;
    std::cout<<"Matrix mult_by_scalar:\n"<<mult_by_scalar<<std::endl;
    Squaremat mult_by_matrix = 5.5*mat1;
    std::cout<<"Matrix mult_by_matrix:\n"<<mult_by_matrix<<std::endl;
    //operator% with int
    Squaremat modulo_by_integer_scalar = mat1%2;
    std::cout<<"Matrix modulo_by_integer_scalar:\n"<<modulo_by_integer_scalar<<std::endl;
    //operator/
    Squaremat divide_by_scalar = mat1/2.1;
    std::cout<<"Matrix divide_by_scalar:\n"<<divide_by_scalar<<std::endl;

    //operators on matrix 1
    //operator-
    Squaremat negativ = -mat1;
    std::cout << "Matrix negativ:\n"<<negativ<<std::endl;
    //operator^
    Squaremat power = mat1^2;
    std::cout << "Matrix power:\n"<<power<<std::endl;
    //operator~
    matOper::Squaremat trans = ~mat1;
    std::cout << "Matrix trans:\n"<<power<<std::endl;
    //operator[]
    //read
    std::cout<<"Matrix 1, row 0, column 1: "<< mat1[0][1]<<std::endl;
    //write     
    mat1[0][1] =10;
    std::cout <<"Matrix 1 after writing 10 in row 0, column 1:\n" << mat1<<std::endl;
    //operator!
    double det = !mat1;
    std::cout << "Matrix det:\n" << det<<std::endl;
    //operator++ and operator--
    //prefix
    Squaremat per_increment = ++mat1;
    std::cout << "Matrix per_increment:\n" << per_increment<<std::endl;
    Squaremat per_decrement = --mat2;
    std::cout << "Matrix per_decrement:\n" << per_decrement<<std::endl;
    //postfix
    Squaremat post_increment = mat1++;
    std::cout << "Matrix post_increment:\n" << post_increment<<std::endl;
    Squaremat post_decrement = mat2--;
    std::cout << "Matrix post_decrement:\n" << post_decrement<<std::endl;

    //operators that change the matrix 1
    mat1+=mat2;
    std::cout<<"Matrix mat1+=mat2:\n"<< mat1<<std::endl;

    mat1-=mat2;
    std::cout<<"Matrix mat1-=mat2:\n"<< mat1<<std::endl;

    mat1*=mat2;
    std::cout<<"Matrix mat1*=mat2:\n"<< mat1<<std::endl;

    mat1*=2.0;
    std::cout<<"Matrix mat1*=2.0:\n"<< mat1<<std::endl;

    mat1/=2.0;
    std::cout<<"Matrix mat1/=2.0:\n"<< mat1<<std::endl;

    mat1%=2;
    std::cout<<"Matrix mat1%=2:\n"<< mat1<<std::endl;

    return 0;
}