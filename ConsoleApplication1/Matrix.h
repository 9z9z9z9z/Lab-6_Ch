#pragma once

#include <stdio.h>
#include <random>
#include <stdarg.h>

class Matrix {

public:
	int** matrix;

	Matrix(const int n) {
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
				matrix[i][j] = tmp;
				matrix[n - i - 1][n - j - 1] = tmp;
				tmp++;
			}
		}
	}

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
	

	Matrix(int n, ...) {
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
				matrix[i][j] = tmp;
				matrix[n - i - 1][n - j - 1] = tmp;
				tmp++;
			}
		}
	}
};
