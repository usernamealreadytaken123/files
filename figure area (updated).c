#include <ctime>       
#include <cstdlib>     
#include <iomanip>      
#include <iostream>    
using namespace std;

#define R_MAX 100       
#define R_MIN 1         

int ** memory(int rows, int columns);
void free_memory(int ** array);
void random(int ** array, int rows, int columns);
void area(int ** array, int rows, int cols);
void print_array(int ** array, int rows, int columns);

int main(void) {

	int n, m;           
	printf( "Input array size:") ;    
	printf ( "rows = ");     
	scanf("%d", n);
	printf("columns = ");  
	scanf("%d", m);
	if (n < 1 || m < 1) return 1;

	int ** a = memory(n, m);       

	random(a, n, m);            
	print_array(a, n, m);       
     area(a, n, m);
	free_memory(a);             
	return 0;                  
}
 
 
int ** memory(int rows, int cols) {
	int ** tmp = new int *[rows];
	tmp[0] = new int[rows*cols];
	for (int i = 1; i < rows; ++i)
		tmp[i] = tmp[i - 1] + cols;
	return tmp;
}


void free_memory(int ** array) {
	delete[] array[0];
	delete[] array;
}


void random(int ** array, int rows, int cols) {
	srand(time(NULL));
	int max_rnd = R_MAX - R_MIN + 1;
	for (int i = 0; i < rows; i++)
		for (int k = 0; k < cols; k++)
			array[i][k] = R_MIN + rand() % max_rnd;
}



void print_array(int ** array, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int k = 0; k < cols; k++)
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
		for (int k = 0; k < d; k++) {
			for (int i = k; i < d; i++) {
				s = s + array[i][d - k - 1] + array[i][d + k];
			}
		}
		g = -1;
		for (int k = 0; k < d; k++) {
			if (d >= 3) {
				if (g > 0) {
					for (int i = d; i < rows - 1 - g; i++) {
						s = s + array[i][k + i - d] + array[i][rows - k - 1 - i + d];
					}
				}
				if (g <= 0) {
					for (int i = d; i < rows - 1; i++) {
						s = s + array[i][k + i - d] + array[i][rows - k - 1 - i + d];
					}
				}
			}
			if (d < 3) {
				for (int i = d; i < rows - 1; i++) {
					s = s + array[i][k + i - d] + array[i][rows - k - 1 - i + d];
				}
			}
			g = g + 1;

		}
		for (int i = rows - 1; i < rows; i++) {
			s = s + array[i][d - 1] + array[i][d];
		}
	}
	if (rows % 2 == 1) {
		for (int k = 0; k < d - 1; k++) {
			for (int i = k; i < d - 1; i++) {
				s = s + array[i][d - 2 - i] + array[i][d + i];
			}
		}
		for (int i = 0; i < rows; i++) {
			s = s + array[d - 1][i];
		}
		for (int i = 0; i < rows; i++) {
			s = s + array[i][d - 1];
		}

		for (int k = 0; k < d - 1; k++) {
			for (int i = d; i < rows - k; i++) {
				s = s + array[i][i - d + k] + array[i][rows + d - i - 1 - k];
			}
		}
		s = s - array[d - 1][d - 1];
		cout << "figure area=";
		cout << s;
	}
	printf("figure area=") ;
	printf ("%d", s);

}