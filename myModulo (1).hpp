//vanunuraz@gmail.com
//% valid for int and the matrix double, so here i will implement modulo for double
#ifndef myModulo_hpp
#define myModulo_hpp
#include <stdexcept>
//inline is used to suggest to the compiler to inline the function and avoid function call more than once
inline double myModulo(double a, int b){
    if(b == 0){
        throw std::invalid_argument("division by zero is not allowed");
    }
    int c = static_cast<int>(a/b);
    return a - c*b;//included the res after .
}
#endif