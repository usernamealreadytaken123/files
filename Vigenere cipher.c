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
	cout << "Encrypted string: ";
	for (i = 0; i < j; i++)
	{
		cout << str1[i] << ' ';
	}
	cout << endl;

}
void cipher(int str1[], int str4[],int d, int f)
{
	int j = 0;
	for (int i = 0; i < d; i++)
	{
		if (str1[i] != 32)
		{
			if (str1[i] + str4[j] > 219)
			{
				if (j + 1 < f)
				{
					str1[i] = str1[i] + str4[j] - 123;
					j++;
				}
				else
				{
					str1[i] = str1[i] + str4[j] - 123;
					j = 0;
				}
			}
			else
			{
				if (j + 1 < f)
				{
					str1[i] = str1[i] + str4[j] - 97;
					j++;
				}
				else
				{
					str1[i] = str1[i] + str4[j] - 97;
					j = 0;
				}
			}
		}
		else str1[i] = 32;
	}
	for (int i = 0; i < d; i++)
		cout << str1[i] << " ";
}
			
int main()
{
	char str[256],str3[256],str5[256];
	int str1[256], c, str4[256],str6[256];
	cout << "enter string: ";
	cin.getline(str, 256);
	int d = strlen(str);
	code(str, str1);
	cout << "key=";
	cin.getline(str3, 256);
	int f = strlen(str3);
	code(str3, str4);
	cipher(str1, str4,d,f);
	decode(str5,str1,str6,d);
	return 0;
}