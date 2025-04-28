vanunuraz@gmail.com
Overview:
This project implements a C++ class Squaremat, which represents a square matrix of real numbers.
It supports mathematical operations between matrices and scalars using operator overloading.
The code usage of STL containers like vector or stack and strictly follows good object-oriented design principles, including:
    1.Rule of Three(Destructor, Copy Constructor, Assignment Operator),
    2.Friend Functions where needed.
    3.Manual dynamic memory management.


Structure:
├── README.md               
├── Makefile                 
├── main.cpp                 
├── test.cpp                 
├── squaremat.hpp         #Declaration of the Squaremat class and its operators.
├── squaremat.cpp        
├── myModulo.hpp          #Helper function for floating-point modulo
├── doctest.h             #Basic local copy of doctest framework


Implematiom:
    1.Dynamic square matrices- the Squaremat class manages dynamic square matrices of real numbers (double type), using manual memory allocation without STL containers.

    2.Operator overloading- arithmetic operators, unary operators, element access using double indexing (matrix[i][j]), comparison operators, determinant calculation, assignment operators.

    3.Helper function- a dedicated helper function (myModulo) was created to handle floating-point modulo operations safely and correctly.

    4.Input validation- all operations validate inputs and throw appropriate exceptions (std::invalid_argument or std::out_of_range) on invalid conditions.

    5.Memory management- full dynamic memory management using new/delete[].Memory safety was verified using valgrind to ensure no memory leaks.
    
    6.Testing- comprehensive unit tests were written using the doctest framework. All functions and operator overloads were tested individually, including normal operations, edge cases, and exception throwing scenarios.


Using learned skills:
The Squaremat class fully implements the Rule of Three-
    1.Destructor (~Squaremat)— releases dynamically allocated memory.
    2.Copy Constructor (Squaremat(const Squaremat& other))— performs deep copy of matrix data.
    3.Assignment Operator (Squaremat& operator=(const Squaremat& other)) — handles self-assignment safely.
This ensures that copying and assignment work correctly without memory issues.

Using friend function- operator<<(std::ostream& os, const Squaremat& matrix).
The operator<< is declared as a friend because it needs access to the private data and size members of Squaremat.

Operator overloading was implemented to allow intuitive operations between matrices and scalars.
Each overloaded operator performs the corresponding mathematical action while maintaining input validation and memory safety.
While the project implemented operator, using my implemation in another operators.


Instructions:
The project uses a Makefile that includes targets for building and running the program, running unit tests, checking memory leaks with Valgrind, and cleaning up generated files.
The commands:
    1. make clean 
    2. make valgrind
    3. make Main
    4. make test


Written by:
Author: Raz Oununu
Date: April 2025

