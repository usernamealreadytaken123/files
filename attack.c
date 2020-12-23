#include <iostream>
#include <conio.h>
#include <cstring>
#include <stdlib.h>

using namespace std;




void code(char str[], int str1[])
{
	int i = 0, j = 0;
	for (i = 0; str[i] != '\0'; i=i+1)
	{
		str1[i] = (int)str[i];
		j=j+1;
	}
	printf ("Encrypted string: ");
	for (i = 0; i < j; i=i+1)
	{
		printf(" %d",  str1[i]);
	}
	cout << endl;

}
void cipher(int str1[], int str4[], int d, int f,int a,int b)
{
	int j = 0;
	int c = 0;
	for (int a = 1; a < 26; a = a + 2) 
		for (int b = 0; b < 26; b = b + 1){
			for (int i = 0; i <= d ; i=i+1)
			{
					if (str4[i] == (((a * (str1[i]-97) + b) % 26) + 97))
					{
						c=c+1;
				
					}
					if (c == d)
					{
						printf("a=%d\n", a);
						printf("a=%d\n", b);;
						goto stop;
					}
				}
			c = 0;
			}
		
	
stop:
	a = a;
	
}

		



int main()
{
	char str[256], str3[256], str5[256];
	int str1[256], c, str4[256], str6[256];
	int a=1;
	int b=0;
	printf ("enter string: ");
	cin.getline(str, 256);
	int d = strlen(str);
	code(str, str1);
	printf ("key=");
	cin.getline(str3, 256);
	int f = strlen(str3);
	code(str3, str4);
	cipher(str1, str4, d, f,a,b);
	return 0;
}
