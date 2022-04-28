#include "header.h"

mv1::Matrix& mv1::Matrix::operator +=(const Matrix& rhs) {			// Matrix addition
	if (this->rows() != rhs.rows() || this->columns() != rhs.columns()) { return *this; }
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < columns_; j++) {
			this->data_[i][j] += rhs.data_[i][j];
		}
	}
	return *this;
}

mv1::Matrix& mv1::Matrix::operator -=(const Matrix& rhs) {			// Matrix subtraction
	if (this->rows() != rhs.rows() || this->columns() != rhs.columns()) { return *this; }
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < columns_; j++) {
			this->data_[i][j] -= rhs.data_[i][j];
		}
	}
	return *this;
}

mv1::Matrix& mv1::Matrix::operator *=(const int rhs) {				// Scalar multiplication
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < columns_; j++) {
			this->data_[i][j] *= rhs;
		}
	}
	return *this;
}

// Returns an n-by-n identity matrix
mv1::Matrix mv1::make_identity(std::size_t n) {
	Matrix result(n, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) { result.data_[i][j] = 1; }
			else { result.data_[i][j] = 0; }
		}
	}
	return result;
}

mv1::Matrix mv1::operator+(Matrix lhs, const Matrix& rhs) {			// Matrix addition
	if (lhs.rows() != rhs.rows() || lhs.columns() != rhs.columns()) { return lhs; }
	Matrix result(rhs.rows_, rhs.columns_);
	for (int i = 0; i < rhs.rows_; i++) {
		for (int j = 0; j < rhs.columns_; j++) {
			result.data_[i][j] = lhs.data_[i][j] + rhs.data_[i][j];
		}
	}
	return result;
}

mv1::Matrix mv1::operator-(Matrix lhs, const Matrix& rhs) {			// Matrix subtraction
	if (lhs.rows() != rhs.rows() || lhs.columns() != rhs.columns()) { return lhs; }
	Matrix result(rhs.rows_, rhs.columns_);
	for (int i = 0; i < rhs.rows_; i++) {
		for (int j = 0; j < rhs.columns_; j++) {
			result.data_[i][j] = lhs.data_[i][j] - rhs.data_[i][j];
		}
	}
	return result;
}

mv1::Matrix mv1::operator*(Matrix lhs, const int rhs) {				// Scalar multiplication	
	Matrix result(lhs.rows_, lhs.columns_);
	for (int i = 0; i < lhs.rows_; i++) {
		for (int j = 0; j < lhs.columns_; j++) {
			result.data_[i][j] = lhs.data_[i][j] * rhs;
		}
	}
	return result;
}

mv1::Matrix mv1::operator*(const int lhs, Matrix rhs) {				// Scalar multiplication
	Matrix result(rhs.rows_, rhs.columns_);
	for (int i = 0; i < rhs.rows_; i++) {
		for (int j = 0; j < rhs.columns_; j++) {
			result.data_[i][j] = lhs * rhs.data_[i][j];
		}
	}
	return result;
}

mv1::Matrix mv1::operator*(const Matrix& lhs, const Matrix& rhs) {	// Matrix multiplication
	if (lhs.columns() != rhs.rows()) { return Matrix(lhs.rows(), lhs.columns(), 0); }
	Matrix result(rhs.rows_, rhs.columns_);
	for (int i = 0; i < rhs.rows_; i++) {
		for (int j = 0; j < rhs.columns_; j++) {
			for (int k = 0; k < rhs.rows(); k++) {
				result.at(i, j) = result.at(i, j) + (lhs.at(i, k) * rhs.at(k, j)); 
			}
		}
	}
	return result;
}

bool mv1::operator==(const Matrix& lhs, const Matrix& rhs) { 
	if (lhs.rows() != rhs.rows() || lhs.columns() != rhs.columns()) { return false; }
	for (int i = 0; i < lhs.rows(); i++) {
		for (int j = 0; j < lhs.columns(); j++){
			if (lhs.at(i, j) == rhs.at(i, j)) { return true; }
		}
	}
	return false;
}
bool mv1::operator!=(const Matrix& lhs, const Matrix& rhs) {
	if (lhs.rows() != rhs.rows() || lhs.columns() != rhs.columns()) { return true; }
	for (int i = 0; i < lhs.rows(); i++) {
		for (int j = 0; j < lhs.columns(); j++){
			if (lhs.at(i, j) != rhs.at(i, j)) { return true; }
		}
	}
	return false;
}

std::ostream& mv1::operator<<(std::ostream& os, const Matrix& rhs) {
	for (int i = 0; i < rhs.rows_; i++) {
		for (int j = 0; j < rhs.columns_; j++) {
			os << rhs.data_[i][j] << " ";
		}
		os << std::endl;
	}
	return os;
}

// Returns matrix values in comma separated value (CSV) format
std::string mv1::csv(const Matrix& mat) {
	std::string output = "";
	for (int i = 0; i < mat.rows(); i++) {
		for (int j = 0; j < mat.columns(); j++) {
			output += std::to_string(mat.at(i, j)) + ",";
		}
		output += "\n";
	}
	return output;
}

mv1::Matrix mv1::transpose(const Matrix& mat) {
	Matrix result(mat.columns(), mat.rows());
	for (int i = 0; i < result.rows(); i++) {
		for (int j = 0; j < result.columns(); j++)
			result.at(i, j) = mat.at(j, i);
	}
	return result;
}