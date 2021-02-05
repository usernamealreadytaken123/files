//Пр//программа выделяет память под двумерный массив, заполняет его случайными целыми числами,затем считает площадь фигуры, выводит ее и освобождает память, выделенную под матрицу          
#include <stdlib.h>     
#include <iomanip>      
#include <stdio.h>    
using namespace std;

#define R_MAX 100       
#define R_MIN 1         

int ** memory(int rows, int columns);
void free_memory(int ** array, int cols, int rows);
void random(int ** array, int rows, int columns);
void area(int ** array, int rows, int cols);
void print_array(int ** array, int rows, int columns);

int main(void) {
	int n, m;
	printf("Input array size:");
	printf("rows = ");
	scanf("%d", &n);
	printf("columns = ");
	scanf("%d", &m);
	if (n < 1 || m < 1) return 1;

	int ** a = memory(n, m);

	random(a, n, m);
	print_array(a, n, m);
	area(a, n, m);
	free_memory(a, n, m);
	return 0;
}


int ** memory(int rows, int cols) {
	int ** tmp = new int *[rows];
	for (int i = 0; i < rows; i = i + 1)
		tmp[i] = new int[cols];
	return tmp;
}


void free_memory(int ** array, int rows, int cols) {
	for (int i = 0; i < rows; i = i + 1)
		delete[] array[i];
	delete[] array;
}


void random(int ** array, int rows, int cols) {
	srand(time(NULL));
	int max_rnd = R_MAX - R_MIN + 1;
	for (int i = 0; i < rows; i = i + 1)
		for (int k = 0; k < cols; k = k + 1)
			array[i][k] = R_MIN + rand() % max_rnd;
}



void print_array(int ** array, int rows, int cols) {
	for (int i = 0; i < rows; i = i + 1) {
		for (int k = 0; k < cols; k = k + 1)
			printf("%2d ", array[i][k]);
		printf("\n");
	}
	printf("\n");
}

void area(int ** array, int rows, int cols)
{
	int  figure_area = 0;
	int middle, g;
	if (rows % 2 == 0) middle = rows * 0.5;
	if (rows % 2 == 1) middle = (rows + 1)*0.5;

	if (rows % 2 == 0) {
		for (int k = 0; k < middle; k = k + 1) {
			for (int i = k; i < middle; i = i + 1) {
				figure_area = figure_area + array[i][middle - k - 1] + array[i][middle + k];
			}
		}
		g = -1;
		for (int k = 0; k < middle; k = k + 1) {
			if (middle >= 3) {
				if (g > 0) {
					for (int i = middle; i < rows - 1 - g; i = i + 1) {
						figure_area = figure_area + array[i][k + i - middle] + array[i][rows - k - 1 - i + middle];
					}
				}
				if (g <= 0) {
					for (int i = middle; i < rows - 1; i = i + 1) {
						figure_area = figure_area + array[i][k + i - middle] + array[i][rows - k - 1 - i + middle];
					}
				}
			}
			if (middle < 3) {
				for (int i = middle; i < rows - 1; i = i + 1) {
					figure_area = figure_area + array[i][k + i - middle] + array[i][rows - k - 1 - i + middle];
				}
			}
			g = g + 1;

		}
		for (int i = rows - 1; i < rows; i = i + 1) {
			figure_area = figure_area + array[i][middle - 1] + array[i][middle];
		}
	}
	if (rows % 2 == 1) {
		for (int k = 0; k < middle - 1; k = k + 1) {
			for (int i = k; i < middle - 1; i = i + 1) {
				figure_area = figure_area + array[i][middle - 2 - i] + array[i][middle + i];
			}
		}
		for (int i = 0; i < rows; i = i + 1) {
			figure_area = figure_area + array[middle - 1][i];
		}
		for (int i = 0; i < rows; i = i + 1) {
			figure_area = figure_area + array[i][middle - 1];
		}

		for (int k = 0; k < middle - 1; k = k + 1) {
			for (int i = middle; i < rows - k; i = i + 1) {
				figure_area = figure_area + array[i][i - middle + k] + array[i][rows + middle - i - 1 - k];
			}
		}
		figure_area = figure_area - array[middle - 1][middle - 1];
	
	}
	printf("figure area=");
	printf("%d", figure_area);

}
