#include "header.h"

mv1::Matrix::Matrix()
	: data_(nullptr), rows_(0), columns_(0) {}

mv1::Matrix::Matrix(std::size_t row, std::size_t col, int fill) {
	this->rows_ = row;
	this->columns_ = col;
	this->data_ = new int* [row];

	for (int i = 0; i < row; i++) {
		this->data_[i] = new int[col];
		for (int j = 0; j < col; j++) {
			this->data_[i][j] = fill;
		}
	}
}

mv1::Matrix::Matrix(const Matrix& rhs) {
	this->rows_ = rhs.rows_;
	this->columns_ = rhs.columns_;
	this->data_ = new int* [rows_];

	for (int i = 0; i < rows_; i++) {
		this->data_[i] = new int[columns_];
		for (int j = 0; j < columns_; j++) {
			this->data_[i][j] = rhs.data_[i][j];
		}
	}
}

mv1::Matrix& mv1::Matrix::operator=(const Matrix& rhs) {
	if (this != &rhs) {
		this->rows_ = rhs.rows_;
		this->columns_ = rhs.columns_;
		this->data_ = new int* [rows_];

		for (int i = 0; i < rows_; i++) {
			this->data_[i] = new int[columns_];
			for (int j = 0; j < columns_; j++) {
				this->data_[i][j] = rhs.data_[i][j];
			}
		}
	}
	return *this;
}

mv1::Matrix::~Matrix() {
	clear();
}