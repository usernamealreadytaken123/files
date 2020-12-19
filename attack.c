#include <iostream>
#include <conio.h>
#include <cstring>
#include <stdlib.h>

using namespace std;




void code(char str[], int str1[])
{
	int i = 0, j = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		str1[i] = (int)str[i];
		j++;
	}
	cout << "Encrypted string: ";
	for (i = 0; i < j; i++)
	{
		cout << str1[i] << ' ';
	}
	cout << endl;

}
void cipher(int str1[], int str4[], int d, int f,int a,int b)
{
	int j = 0;
	int c = 0;
	for (int a = 1; a < 25; a = a + 2) 
		for (int b = 0; b < 5; b = b + 1){
			for (int i = 0; i < d ; i++)
			{
				for (int j = 0; j < f; j++)
				{
					if (str1[i] == (((a * (str4[j]-97) + b) % 26) + 97))
					{
						c++;
					}
				
				}

			}
		if (c == d) goto stop;
	}
stop:
	a = a;
}

		



int main()
{
	char str[256], str3[256], str5[256];
	int str1[256], c, str4[256], str6[256];
	int a = 1;
	int b = 0;
	cout << "enter string: ";
	cin.getline(str, 256);
	int d = strlen(str);
	code(str, str1);
	cout << "key=";
	cin.getline(str3, 256);
	int f = strlen(str3);
	code(str3, str4);
	cipher(str1, str4, d, f,a,b);
	cout << a;
	cout << b;
	return 0;
}
