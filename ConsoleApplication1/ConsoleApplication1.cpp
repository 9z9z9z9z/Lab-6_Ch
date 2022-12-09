#include "Matrix.h"
#include "stdarg.h"
#include <iostream>


int sum(int n, ...)
{
	int result = 0;
	va_list factor;         //указатель va_list
	va_start(factor, n);    // устанавливаем указатель
	for (int i = 0; i < n; i++)
	{
		result += va_arg(factor, int);  // получаем значение текущего параметра типа int
	}
	va_end(factor); // завершаем обработку параметров
	return result;
}

void main(char* args) {
	int N = 10;
	Matrix m = Matrix(10, 1,2,3,4,5,6,7,8,9,10);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << m.matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	/*
	printf("%d, \n", sum(4, 1, 3, 4, 5));
	printf("%d, \n", sum(5, 1, 3, 4, 5, 6));*/
}
