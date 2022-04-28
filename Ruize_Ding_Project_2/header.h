#pragma once

#include <string>		// std::string
#include <cstddef>		// std::size_t
#include <ostream>		// std::ostream

namespace mv1 {
	// Matrix implemented with the C-style array, using a double and dynamic memory allocation
	class Matrix {
	public:
		// Constructs an empty matrix (Default Constructor)
		Matrix();	

		// Constructs and initialises a matrix (parameterized constructor)
		Matrix(std::size_t row, std::size_t col, int fill = 0);

		// Copy constructor
		Matrix(const Matrix& rhs);

		// Copy assignment
		Matrix& operator=(const Matrix& rhs);

		// Destructs matrix (destructor)
		~Matrix();

		// Element mutator (setter)
		int& at(std::size_t row, std::size_t col);
		// Element accessor (getter)
		int at(std::size_t row, std::size_t col) const;

		void clear();										// Delete contents
		bool empty() const;									// 'true' if matrix contains no elements

		std::size_t rows() const;							// Returns the number of rows
		std::size_t columns() const;						// Returns the number of columns

		// Compound assignment
		Matrix& operator +=(const Matrix& rhs);				// Matrix addition
		Matrix& operator -=(const Matrix& rhs);				// Matrix subtraction
		Matrix& operator *=(const int rhs);					// Scalar multiplication

		friend Matrix make_identity(std::size_t n);

		friend Matrix operator+(Matrix lhs, const Matrix& rhs);
		friend Matrix operator-(Matrix lhs, const Matrix& rhs);

		friend Matrix operator*(Matrix lhs, const int rhs);
		friend Matrix operator*(const int lhs, Matrix rhs);
		friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);

		friend std::ostream& operator<<(std::ostream& stream, const Matrix& rhs);
		friend std::string csv(const Matrix& mat);

		friend Matrix transpose(const Matrix& mat);

		void reallocate(std::size_t rows, std::size_t cols, int fill = 0);
	private:
		std::size_t rows_;
		std::size_t columns_;
		int** data_;
	};
	// Returns an n-by-n identity matrix
	Matrix make_identity(std::size_t n);

	Matrix operator+(Matrix lhs, const Matrix& rhs);			// Matrix addition
	Matrix operator-(Matrix lhs, const Matrix& rhs);			// Matrix subtraction
	Matrix operator*(Matrix lhs, const int rhs);				// Scalar multiplication	
	Matrix operator*(const int lhs, Matrix rhs);				// Scalar multiplication
	Matrix operator*(const Matrix& lhs, const Matrix& rhs);		// Matrix multiplication

	/* Note about matrix multiplication:
	- The simple implementation used here is cubic in time O(n^3),
	which means it is infeasible for solving large problems
	- Returns an empty matrix if either ‘lhs ‘ or ‘rhs ‘ is empty ,
	or if the inner dimensions are not equal (i.e., the number of
	columns in ‘lhs ‘ does not equal the number of rows in ‘rhs ‘) */

	// Comparison operator overloads
	bool operator ==(const Matrix& lhs, const Matrix& rhs);
	bool operator !=(const Matrix& lhs, const Matrix& rhs);

	// Stream insertion operator overload
	std::ostream& operator<<(std::ostream& os, const Matrix& rhs);

	// Returns matrix values in comma separated value (CSV) format
	std::string csv(const Matrix& mat);

	// Returns transpose of the matrix
	Matrix transpose(const Matrix& mat);

} // namespace mv1