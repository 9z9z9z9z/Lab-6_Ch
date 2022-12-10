#include "Matrix.h"
#include "stdarg.h"
#include <iostream>


int main(char* args) {
	int N = 10;
	Matrix m = Matrix(N, true);
	Matrix m1 = m;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << m1.matrix[i][j] << "\t";
		}
		std::cout << std::endl << std::endl;
	}
	std::cout << std::endl << std::endl << std::endl;
	return 666;
}
