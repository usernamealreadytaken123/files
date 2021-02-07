#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void code(char string[], int code_string[])

{
	int i = 0, j = 0;
	for (i = 0; string[i] != '\0'; i = i + 1)
	{
		code_string[i] = (int)string[i];
		j = j + 1;
	}
	printf("Encrypted string: ");
	for (i = 0; i < j; i = i + 1)
	{
		printf(" %d", code_string[i]);
	}
	printf(" \n");
}
//
void cipher(int code_string[], int code_sipherstring[], int string_len, int a, int b, int* key_a, int* key_b, int sipher_len)
{
	int j = 0;
	int k=0;
	int counter = 0;
	for (int i = 0; i <= string_len; i = i + 1)
	{
		
		 for (int j = 0; j <= string_len; j = j + 1)

			 if (((code_string[j] > 96 && code_string[j ] < 123 && code_sipherstring[j+i] > 96 && code_sipherstring[j+i]) || (code_string[j] > 64 && code_string[j] < 91 && code_sipherstring[j+i] > 64 && code_sipherstring[j+i] < 91)) && (j + i<=sipher_len))
			{
				counter = counter + 1;
			}
		if (counter == string_len)
		{
			if ((code_string[i] > 90 && code_string[i] < 97) || (code_string[i] > 123) || (code_string[i] > 90 && code_string[i] < 97 && code_sipherstring[i] > 90 && code_sipherstring[i] < 97))
				if (code_string[0] > code_string[1])
				{
					a = code_string[0] - code_string[1];
					b = code_sipherstring[0] - code_sipherstring[1];
					while (b%a != 0)
						b = b + 26;
					a = b / a;
					b = code_sipherstring[0] - (code_string[0] - 97)*a + 97;
					while (b < 0)
						b = b + 26;
					b = b % 26;

				}
			if (code_string[1] > code_string[0])
			{
				a = code_string[1] - code_string[0];
				b = code_sipherstring[1] - code_sipherstring[0];
				while (b%a != 0)
					b = b + 26;
				a = b / a;
				b = code_sipherstring[0] - ((code_string[0] - 97)*a + 97);
				while (b < 0)
					b = b + 26;
				b = b % 26;
			}
			if (a / 2 == 1) 
			{
				*key_a = a;
				*key_b = b;
			}
		}
		counter = 0;
	}
}





int main()
{
	char string[256], sipher_string[256];
	int code_string[256], c, code_sipherstring[256];
	int a = 1;
	int b = 0;
	int key_a, key_b;
	printf("enter string: ");
	gets_s(string);
	int string_len = strlen(string);
	code(string, code_string);
	printf("sipherstring: ");
	gets_s(sipher_string);
	int sipher_len = strlen(sipher_string);

	code(sipher_string, code_sipherstring);
	cipher(code_string, code_sipherstring, string_len, a, b, &key_a, &key_b, sipher_len);
	printf("a=%d\n", key_a);
	printf("b=%d\n", key_b);
	return 0;
}
