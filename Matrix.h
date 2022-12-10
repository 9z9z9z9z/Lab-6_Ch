#pragma once

#include <array>
#include <iostream>
#include <stdio.h>
#include <random>
#include <stdarg.h>

class Matrix {

public:
	int* line;
	int size;

	Matrix(int n, bool flag);
	Matrix(const int n, ...);
	Matrix(Matrix& base, bool flag);

	~Matrix();

	void print();

	Matrix& operator=(const Matrix& source);
};

Matrix::Matrix(int n, bool flag) {
	this->size = n;
	this->line = new int[size];
	for (int i = 0; i < size; i++) {
		line[i] = rand();
	}
}

Matrix::Matrix(const int n, ...) {
	size = n;
	line = new int[size];
	va_list tmp_par;
	va_start(tmp_par, n);
	for (int i = 0; i < n; i++) {
		line[i] = va_arg(tmp_par, int);
	}
	va_end(tmp_par);
}

Matrix::Matrix(Matrix& base, bool flag) {
	this->size = base.size;
	this->line = base.line;
}

Matrix::~Matrix() { delete[] line; }

void Matrix::print() {
	double** tmp_matrix = new double* [this->size];
	for (int i = 0; i < size; i++) {
		tmp_matrix[i] = new double[this->size];
	}
	int tmp;
	for (int i = 0; i < this->size; i++) {
		tmp = 0;
		for (int j = i; j < this->size; j++) {
			tmp_matrix[i][j] = line[tmp];
			tmp_matrix[this->size - i - 1][this->size - j - 1] = line[tmp];
			tmp++;
		}
	}
	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < this->size; j++) {
			std::cout << tmp_matrix[i][j] << "\t";
		}
		std::cout << std::endl << std::endl;
	}
}

Matrix& Matrix::operator=(const Matrix& source) {
	delete[] line;
	this->size = source.size;
	this->line = new int[size];
	for (int i = 0; i < size; i++) {
		line[i] = source.line[i];
	}
	return *this;
}
