#pragma once

#include <array>
#include <stdio.h>
#include <random>
#include <stdarg.h>

class Matrix {

public:
	int** matrix;
	int size;
	// EEMMMIIILLLL!!!
	/*Matrix(const int n) {
		matrix = new int* [n];
		for (int i = 0; i < n; i++) {
			matrix[i] = new int[n];
			for (int j = 0; j < n; j++) {
				matrix[i][j] = 0;
			}
		}
		int tmp = 0;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < n; j++) {
				matrix[i][j] = tmp;
				tmp++;
			}
			tmp = 0 + n - i;
		}
	}*/
	Matrix(const int n, bool flag);
	Matrix(const int n, ...);
	Matrix(Matrix& base, bool flag);

	~Matrix();

	Matrix& operator=(const Matrix& source);
};

Matrix::Matrix(const int n, bool flag) {
	this->size = n;
	matrix = new int* [n];
	int* base = new int[n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
		base[i] = std::rand();
		for (int j = 0; j < n; j++) {
			matrix[i][j] = 0;
		}
	}
	int tmp;
	for (int i = 0; i < n; i++) {
		tmp = 0;
		for (int j = i; j < n; j++) {
			matrix[i][j] = base[tmp];
			matrix[n - i - 1][n - j - 1] = base[tmp];
			tmp++;
		}
	}
	delete[] base;
}

Matrix::Matrix(int n, ...) {
	this->size = n;
	int* params = new int[n];
	va_list tmp_par;
	va_start(tmp_par, n);
	for (int i = 0; i < n; i++) {
		params[i] = va_arg(tmp_par, int);
	}
	va_end(tmp_par);
	matrix = new int* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new int[n];
		for (int j = 0; j < n; j++) {
			matrix[i][j] = 0;
		}
	}
	int tmp;
	for (int i = 0; i < n; i++) {
		tmp = 0;
		for (int j = i; j < n; j++) {
			matrix[i][j] = params[tmp];
			matrix[n - i - 1][n - j - 1] = params[tmp];
			tmp++;
		}
	}
	delete[] params;
}

Matrix::Matrix(Matrix& base, bool flag) {
	this->size = base.size;
	this->matrix = base.matrix;
}

Matrix::~Matrix() { 
	for (int i = 0; i < size; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

Matrix& Matrix::operator=(const Matrix& source) {
	for (int i = 0; i < size; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	this->size = source.size;
	this->matrix = new int* [size];
	for (int i = 0; i < size; i++) {
		matrix[i] = new int[size];
		for (int j = 0; j < size; j++) {
			this->matrix[i][j] = source.matrix[i][j];
		}
	}
	return *this;
}
