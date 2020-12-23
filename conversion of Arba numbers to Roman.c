#include <iostream>
using namespace std;
int main()
{
	int  i, b, c, d , e , f , g , j ;
	int a;
	printf("enter the number:");
	scanf("%d", &a);
	b = a / 1000;
	c = a % 1000;
	d = a % 500;
	e = a % 100;
	f = a % 50;
	g = a % 10;
	j = a % 5;
	printf( "roman number: ");
	for (int i = 0; i <= b - 1; i++) {
		printf( "M");
	}
	if (c >= 900) {
		printf( "CM");
	}
	if (c >= 400 && c < 500)
		printf("CD");
	if (c>=500 && c<900)
	{
	
			printf( "D");
	}
	if (d < 400)

	{
		if (d >= 100 && e < 90)
			for (int i = 0; i < (d / 100); i++)
			{
				printf( "C");
			}
		if (d >= 100 && e >= 90)
		{
			for (int i = 0; i < (d / 100); i++)
			{
				printf ("C");
			}
		 printf("XC");
		}
	}
if (d<100 && e >= 90)
	printf("XC");
	if (e<90 && e>=50)
	{
			printf("L");
		}
	
	if (e < 50 && e >= 40) {
		printf("XL");
	}

	if (f<40 && f>=10 )
		for (int i = 0; i < (f/10) ; i++) {
			printf("X");
		}
	
	if (g == 9 ) {
		printf ("IX");
	}
	if (g < 9 && g >= 5) {

			printf("V");
		}
	
	if (g == 4) {
		printf("IV");
	}

	if (j <4 )
		for (int i = 0; i < j ; i++) {
			printf("I");
		}
	

	return 0;
}

