#include "header.h"

// Element mutator
int& mv1::Matrix::at(std::size_t row, std::size_t col) { return data_[row][col]; }
// Element accessor
int mv1::Matrix::at(std::size_t row, std::size_t col) const { return data_[row][col];}

void mv1::Matrix::clear() {										// Delete contents
	for (int i = 0; i < rows_; i++) {
		delete[] data_[i];
	}
	delete[] data_;
}

bool mv1::Matrix::empty() const {								// 'true' if matrix contains no elements
	if (rows_ == 0 && columns_ == 0) return true;
	else return false;
}

std::size_t mv1::Matrix::rows() const { return rows_; }			// Returns the number of rows
std::size_t mv1::Matrix::columns() const { return columns_; }	// Returns the number of columns

void mv1::Matrix::reallocate(std::size_t rows, std::size_t cols, int fill) {
	clear();
	this->rows_ = rows;
	this->columns_ = cols;
	this->data_ = new int* [rows];
	for (int i = 0; i < rows; i++) {
		this->data_[i] = new int[cols];
		for (int j = 0; j < cols; j++) {
			this->data_[i][j] = fill;
		}
	}
}