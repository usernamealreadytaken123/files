//Программа выделяет память под двумерный массив, заполняет его случайными целыми числами,затем считает площадь фигуры, выводит ее и освобождает память, выделенную под матрицу
#include <ctime>       
#include <cstdlib>     
#include <iomanip>      
#include <iostream>    
using namespace std;

#define R_MAX 100       
#define R_MIN 1         

int ** memory(int rows, int columns);
void free_memory(int ** array,int cols,int rows);
void random(int ** array, int rows, int columns);
void area(int ** array, int rows, int cols);
void print_array(int ** array, int rows, int columns);

int main(void) {
int n, m;
printf("Input array size:");
printf("rows = ");
scanf("%d", n);
printf("columns = ");
scanf("%d", m);
if (n < 1 || m < 1) return 1;

int ** a = memory(n, m);

random(a, n, m);
print_array(a, n, m);
area(a, n, m);
free_memory(a,n,m);
return 0;
}


int ** memory(int rows, int cols) {
	int ** tmp = new int *[rows];
	for (int i = 0; i < rows; i=i+1)
		tmp[i] = new int[cols] ;
	return tmp;
}


void free_memory(int ** array,int rows,int cols) {
	for (int i=0;i<rows;i=i+1)
	delete[] array[i];
	delete[] array;
}


void random(int ** array, int rows, int cols) {
	srand(time(NULL));
	int max_rnd = R_MAX - R_MIN + 1;
	for (int i = 0; i < rows; i=i+1)
		for (int k = 0; k < cols; k=k+1)
			array[i][k] = R_MIN + rand() % max_rnd;
}



void print_array(int ** array, int rows, int cols) {
	for (int i = 0; i < rows; i=i+1) {
		for (int k = 0; k < cols; k=k+1)
			printf("%2d ", array[i][k]);
		printf("\n");
	}
	printf("\n");
}

void area(int ** array, int rows, int cols)
{
	int  s = 0;
	int d, g;
	if (rows % 2 == 0) d = rows * 0.5;
	if (rows % 2 == 1) d = (rows + 1)*0.5;

	if (rows % 2 == 0) {
		for (int k = 0; k < d; k=k+1) {
			for (int i = k; i < d; i=i+1) {
				s = s + array[i][d - k - 1] + array[i][d + k];
			}
		}
		g = -1;
		for (int k = 0; k < d; k=k+1) {
			if (d >= 3) {
				if (g > 0) {
					for (int i = d; i < rows - 1 - g; i=i+1) {
						s = s + array[i][k + i - d] + array[i][rows - k - 1 - i + d];
					}
				}
				if (g <= 0) {
					for (int i = d; i < rows - 1; i=i+1) {
						s = s + array[i][k + i - d] + array[i][rows - k - 1 - i + d];
					}
				}
			}
			if (d < 3) {
				for (int i = d; i < rows - 1; i=i+1) {
					s = s + array[i][k + i - d] + array[i][rows - k - 1 - i + d];
				}
			}
			g = g + 1;

		}
		for (int i = rows - 1; i < rows; i=i+1) {
			s = s + array[i][d - 1] + array[i][d];
		}
	}
	if (rows % 2 == 1) {
		for (int k = 0; k < d - 1; k=k+1) {
			for (int i = k; i < d - 1; i=i+1) {
				s = s + array[i][d - 2 - i] + array[i][d + i];
			}
		}
		for (int i = 0; i < rows; i=i+1) {
			s = s + array[d - 1][i];
		}
		for (int i = 0; i < rows; i=i+1) {
			s = s + array[i][d - 1];
		}

		for (int k = 0; k < d - 1; k=k+1) {
			for (int i = d; i < rows - k; i=i+1) {
				s = s + array[i][i - d + k] + array[i][rows + d - i - 1 - k];
			}
		}
		s = s - array[d - 1][d - 1];
		printf("figure area=");
		printf("%d", s);
	}
	printf("figure area=");
	printf("%d", s);

}
