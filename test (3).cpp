//vanunuraz@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "squaremat.hpp"
#include <stdexcept>
#include "doctest.h"
using namespace matOper;
TEST_CASE("Squaremat: initialization at construction"){
    Squaremat mat(3);
    CHECK(mat.getSize() == 3);//check getSize()
    //valid initialization
    CHECK_NOTHROW(Squaremat(3));
    CHECK_THROWS_AS(Squaremat(-1), std::invalid_argument);
}

TEST_CASE("Squaremat: Operator[] for reading and writing"){
    Squaremat mat(3);
    mat[0][0] = 1.0;
    mat[1][1] = 2.0;
    mat[2][2] = 3.0;
    CHECK(mat[0][0] == 1.0);
    CHECK(mat[1][1] == 2.0);
    CHECK(mat[2][2] == 3.0);
    CHECK_THROWS_AS(mat[3][0], std::out_of_range);//invalid index
}

TEST_CASE("Squaremat: operator+"){
    Squaremat mat1(2);
    mat1[0][0] = 1; mat1[0][1] = 2; mat1[1][0] = 3; mat1[1][1] = 4;
    Squaremat mat2(2);
    mat2[0][0] = 5; mat2[0][1] = 6; mat2[1][0] = 7; mat2[1][1] = 8;
    Squaremat res = mat1+mat2;
    CHECK(res[0][0] == 6);
    CHECK(res[0][1] == 8);
    CHECK(res[1][0] == 10);
    CHECK(res[1][1] == 12);
}

TEST_CASE("Squaremat: operator-"){
    Squaremat mat1(2);
    mat1[0][0] = 5; mat1[0][1] = 6;
    mat1[1][0] = 7; mat1[1][1] = 8;
    Squaremat mat2(2);
    mat2[0][0] = 1; mat2[0][1] = 2;
    mat2[1][0] = 3; mat2[1][1] = 4;
    Squaremat res = mat1-mat2;
    CHECK(res[0][0] == 4);
    CHECK(res[0][1] == 4);
    CHECK(res[1][0] == 4);
    CHECK(res[1][1] == 4);
}

TEST_CASE("Squaremat: operator- unary"){
    Squaremat mat(2);
    mat[0][0] = 1; mat[0][1] = -2;
    mat[1][0] = 3; mat[1][1] = -4;
    Squaremat res= -mat;
    CHECK(res[0][0] == -1);
    CHECK(res[0][1] == 2);
    CHECK(res[1][0] == -3);
    CHECK(res[1][1] == 4);
}

TEST_CASE("Squaremat: operator*"){
    Squaremat mat1(2);
    mat1[0][0] = 1; mat1[0][1] = 2;
    mat1[1][0] = 3; mat1[1][1] = 4;
    Squaremat mat2(2);
    mat2[0][0] = 2; mat2[0][1] = 0;
    mat2[1][0] = 1; mat2[1][1] = 2;
    Squaremat res = mat1*mat2;
    CHECK(res[0][0] == 4);
    CHECK(res[0][1] == 4);
    CHECK(res[1][0] == 10);
    CHECK(res[1][1] == 8);
}

TEST_CASE("Squaremat: operator* with scalar"){
    Squaremat mat(2);
    mat[0][0] = 1; mat[0][1] = 2;
    mat[1][0] = 3; mat[1][1] = 4;
    //mat*scalar
    Squaremat res1 = mat*2.0;
    CHECK(res1[0][0] == 2);
    CHECK(res1[0][1] == 4);
    CHECK(res1[1][0] == 6);
    CHECK(res1[1][1] == 8);
    //scalar*mat
    Squaremat res2 = 2.0*mat;
    CHECK(res2[0][0] == 2);
    CHECK(res2[0][1] == 4);
    CHECK(res2[1][0] == 6);
    CHECK(res2[1][1] == 8);
}

TEST_CASE("Squaremat: operator%"){
    Squaremat mat(2);
    mat[0][0] = 5; mat[0][1] = 6;
    mat[1][0] = 7; mat[1][1] = 8;
    Squaremat res = mat%3;
    CHECK(res[0][0] == 2);
    CHECK(res[0][1] == 0);
    CHECK(res[1][0] == 1);
    CHECK(res[1][1] == 2);
}

TEST_CASE("Squaremat: operator% with another matrix"){
    Squaremat mat1(2);
    mat1[0][0] = 5; mat1[0][1] = 6;
    mat1[1][0] = 7; mat1[1][1] = 8;
    Squaremat mat2(2);
    mat2[0][0] = 2; mat2[0][1] = 3;
    mat2[1][0] = 4; mat2[1][1] = 5;
    Squaremat res = mat1%mat2;
    CHECK(res[0][0] == 10);
    CHECK(res[0][1] == 18);
    CHECK(res[1][0] == 28);
    CHECK(res[1][1] == 40);
}

TEST_CASE("Squaremat: operator/"){
    Squaremat mat(2);
    mat[0][0] = 4; mat[0][1] = 8;
    mat[1][0] = 12; mat[1][1] = 16;
    Squaremat res = mat/4.0;
    CHECK(res[0][0] == 1);
    CHECK(res[0][1] == 2);
    CHECK(res[1][0] == 3);
    CHECK(res[1][1] == 4);
    //division by zero
    CHECK_THROWS_AS(mat/0.0, std::invalid_argument);
}

TEST_CASE("Squaremat: operator^"){
    Squaremat mat(2);
    mat[0][0] = 1; mat[0][1] = 2;
    mat[1][0] = 3; mat[1][1] = 4;
    Squaremat res = mat^2;
    CHECK(res[0][0] == 7);
    CHECK(res[0][1] == 10);
    CHECK(res[1][0] == 15);
    CHECK(res[1][1] == 22);
}

TEST_CASE("Squaremat: perfix operaors"){
    Squaremat mat(2);
    mat[0][0] = 1; mat[0][1] = 2;
    mat[1][0] = 3; mat[1][1] = 4;
    Squaremat res = ++mat;
    CHECK(res[0][0] == 2);
    CHECK(res[0][1] == 3);
    CHECK(res[1][0] == 4);
    CHECK(res[1][1] == 5);
    
    Squaremat res2 = --mat;
    CHECK(res2[0][0] == 0);
    CHECK(res2[0][1] == 1);
    CHECK(res2[1][0] == 2);
    CHECK(res2[1][1] == 3);
}

TEST_CASE("Squaremat: postfix operators"){
    Squaremat mat(2);
    mat[0][0] = 1; mat[0][1] = 2;
    mat[1][0] = 3; mat[1][1] = 4;
    Squaremat res = mat++;
    CHECK(res[0][0] == 1);
    CHECK(res[0][1] == 2);
    CHECK(res[1][0] == 3);
    CHECK(res[1][1] == 4);
    res = mat--;
    CHECK(res[0][0] == 1);
    CHECK(res[0][1] == 2);
    CHECK(res[1][0] == 3);
    CHECK(res[1][1] == 4);
}

TEST_CASE("Squaremat: operator~"){
    Squaremat mat(2);
    mat[0][0] = 1; mat[0][1] = 2;
    mat[1][0] = 3; mat[1][1] = 4;
    Squaremat result = ~mat;
    CHECK(result[0][0] == 1);
    CHECK(result[0][1] == 3);
    CHECK(result[1][0] == 2);
    CHECK(result[1][1] == 4);
}

TEST_CASE("Squaremat: operator!"){
    Squaremat mat(2);
    mat[0][0] = 1; mat[0][1] = 2;
    mat[1][0] = 3; mat[1][1] = 4;
    CHECK(!mat== -2);
}

TEST_CASE("Squaremat: Comparison operators") {
    Squaremat mat1(2), mat2(2);
    mat1[0][0] = 1; mat1[0][1] = 2;
    mat1[1][0] = 3; mat1[1][1] = 4;
    mat2[0][0] = 5; mat2[0][1] = 6;
    mat2[1][0] = 7; mat2[1][1] = 8;
    CHECK(mat1 != mat2);//if this ok, also operator== is ok
    CHECK(mat1 < mat2);
    CHECK_FALSE(mat1 > mat2);
    CHECK(mat2 > mat1);
    CHECK(mat1 <= mat2);
    CHECK_FALSE(mat1 >= mat2);
    CHECK(mat2 >= mat1);
}

TEST_CASE("Squaremat: Operators that change the object"){
    Squaremat mat1(2);
    mat1[0][0] = 1; mat1[0][1] = 2;
    mat1[1][0] = 3; mat1[1][1] = 4;
    Squaremat mat2(2);
    mat2[0][0] = 5; mat2[0][1] = 6;
    mat2[1][0] = 7; mat2[1][1] = 8;

    mat1+=mat2;
    CHECK(mat1[0][0] == 6);
    CHECK(mat1[0][1] == 8);
    CHECK(mat1[1][0] == 10);
    CHECK(mat1[1][1] == 12);

    mat1-=mat2;
    CHECK(mat1[0][0] == 1);
    CHECK(mat1[0][1] == 2);
    CHECK(mat1[1][0] == 3);
    CHECK(mat1[1][1] == 4);

    mat1*=mat2;
    CHECK(mat1[0][0] == 19);
    CHECK(mat1[0][1] == 22);
    CHECK(mat1[1][0] == 43);
    CHECK(mat1[1][1] == 50);

    //mult by scalar    
    mat1*=2.0;
    CHECK(mat1[0][0] == 38);
    CHECK(mat1[0][1] == 44);
    CHECK(mat1[1][0] == 86);
    CHECK(mat1[1][1] == 100);

    mat1/=2.0;
    CHECK(mat1[0][0] == 19);
    CHECK(mat1[0][1] == 22);
    CHECK(mat1[1][0] == 43);
    CHECK(mat1[1][1] == 50);

    //modulo
    mat1%=3;
    CHECK(mat1[0][0] == 1);
    CHECK(mat1[0][1] == 1);
    CHECK(mat1[1][0] == 1);
    CHECK(mat1[1][1] == 2);

    //% for mult each cell
    mat1%=mat2;
    CHECK(mat1[0][0] == 5);
    CHECK(mat1[0][1] == 6);
    CHECK(mat1[1][0] == 7);
    CHECK(mat1[1][1] == 16);
}
