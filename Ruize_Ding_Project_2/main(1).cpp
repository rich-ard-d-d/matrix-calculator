#include <iostream>
#include "header.h"

int main() {
	std::cout << "Print a 3x3 matrix filled with 1: " << std::endl;
	mv1::Matrix m0(3, 3, 1);
	std::cout << m0 << std::endl;
	m0.at(0, 0) = 1;
	m0.at(0, 1) = 9;
	m0.at(0, 2) = 7;

	m0.at(1, 0) = 5;
	m0.at(1, 1) = 2;
	m0.at(1, 2) = 6;

	m0.at(2, 0) = 1;
	m0.at(2, 1) = 4;
	m0.at(2, 2) = 8;
	
	std::cout << "Modifying the matrix to have unique values: " << std::endl;
	std::cout << m0 << std::endl;

	std::cout << "Printing out matrix in .csv format: " << std::endl;
	std::cout << csv(m0) << std::endl;

	std::cout << "Checking if the matrix is empty: " << m0.empty() << std::endl;
	std::cout << "Matrix row count: " << m0.rows() << std::endl;
	std::cout << "Matrix column count: " << m0.columns() << std::endl;
	std::cout << std::endl;

	std::cout << "Identity Matrix Size 4: " << std::endl;
	std::cout << mv1::make_identity(4) << std::endl;

	std::cout << "The following matrix will get transposed: " << std::endl;
	mv1::Matrix transpose_Matrix(4, 2, 0);
	std::cout << transpose_Matrix << std::endl;

	std::cout << "Transposed Matrix: " << std::endl;
	std::cout << mv1::transpose(transpose_Matrix);
	std::cout << std::endl;

	mv1::Matrix m1(3, 3, 9);
	mv1::Matrix m2(3, 3, 7);

	std::cout << "Matrix 1: " << std::endl;
	std::cout << m1 << std::endl;
	std::cout << "Matrix 2: " << std::endl;
	std::cout << m2 << std::endl;
	std::cout << "Matrix Addition: " << std::endl;
	std::cout << "Matrix 1 + Matrix 2: " << std::endl << m1 + m2 << std::endl;
	m1 += m2;
	std::cout << "Matrix 1 += Matrix 2: " << std::endl << m1 << std::endl;
	std::cout << "The + and += operators are identical." << std::endl;
	std::cout << std::endl;

	m1.reallocate(3, 3, 9);
	m2.reallocate(3, 3, 7);
	
	std::cout << "Matrix Subtraction: " << std::endl;
	std::cout << "Matrix 1 - Matrix 2: " << std::endl << m1 - m2 << std::endl;
	m1 -= m2;
	std::cout << "Matrix 1 -= Matrix 2: " << std::endl << m1 << std::endl;
	std::cout << "The - and -= operators are identical." << std::endl;
	std::cout << std::endl;

	m1.reallocate(3, 3, 9);
	m2.reallocate(3, 3, 7);
	
	std::cout << "Matrix Multiplication: " << std::endl;
	std::cout << "Matrix 1 * Matrix 2: " << std::endl << m2 * m1 << std::endl;
	std::cout << std::endl;

	std::cout << "Scalar Multiplication: " << std::endl;
	std::cout << "Matrix 1 * 6: " << std::endl << m1 * 6 << std::endl;
	m1 *= 6;
	std::cout << "Matrix 1 *= 6: " << std::endl << m1 << std::endl;
	std::cout << "The * and *= operators are identical." << std::endl;
	std::cout << std::endl;
	std::cout << "9 * Matrix 2: " << std::endl << 9 * m2 << std::endl;
	std::cout << std::endl;

	std::cout << "Matrix 1 == Matrix 2: " << (m1 == m2) << std::endl;
	std::cout << "Matrix 1 != Matrix 2: " << (m1 != m2) << std::endl;
	std::cout << std::endl;

	int rows_, columns_, fill;
	std::cout << "The following allows the user to generate a matrix with a specified fill." << std::endl;
	std::cout << "Enter number of rows: ";
	std::cin >> rows_;
	std::cout << "Enter the number of columns: ";
	std::cin >> columns_;
	std::cout << "Enter the fill of the matrix: ";
	std::cin >> fill;
	mv1::Matrix user_Matrix(rows_, columns_, fill);
	std::cout << user_Matrix << std::endl;

	std::cout << "The following allows the user to generate an identity matrix of pre-specified size." << std::endl;
	std::cin >> rows_;
	std::cout << mv1::make_identity(rows_);
}