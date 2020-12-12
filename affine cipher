#include <iostream>
#include <conio.h>
#include <cstring>
#include <stdlib.h>

using namespace std;


void decode(char str5[], int str1[], int str6[], int d)
{
	for (int i = 0; i < d; i++)
	{
		if (str1[i] != '32')
		{
			str5[i] = (char)str1[i];
			cout << str5[i];
		}
		else {
			str5[i] = ' ';
			cout << str5[i];

		}
	}
}
void code(char str[], int str1[])
{
	int i = 0, j = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		str1[i] = (int)str[i];
		j++;
	}
	cout << "Шифрованная строка: ";
	for (i = 0; i < j; i++)
	{
		cout << str1[i] << ' ';
	}
	cout << endl;

}

void cipher(int str1[] ,int str2[], int d, int a, int b)
{
	int j = 0;
	for (int i = 0; i < d; i++)
	{
		str1[i] = ((a * str1[i] + b) % 26)+52;
			
}
	for (int i = 0; i < d; i++)
		cout << str1[i] << " ";
}

int main()
{
	char str[256], str5[256];
	int str1[256], str2[256],str6[256], a, b, c;
	cout << "enter string: ";
	cin.getline(str, 256);
	cout << "key=";
	cin>> a;
	cin >> b;
	int d = strlen(str);
	code(str,str1);
	cipher(str1, str2, d, a,b);
	decode(str5, str1, str6, d);
	return 0;
}
