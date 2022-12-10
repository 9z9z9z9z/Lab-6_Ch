#include "Matrix.h"
#include "stdarg.h"
#include <iostream>


int main(char* args) {
	int N = 10;
	Matrix m = Matrix(N, 1,2,3,4,5,6,7,8,9,20);
	Matrix m1 = m;
	m1.print();
	std::cout << std::endl << std::endl << std::endl;
	return 666;
}
