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

void decode(int code_sipherstring[], char sipher_string[], int sipher_len)
{
	for (int i = 0; i < sipher_len; i++)
	{
		if (code_sipherstring[i] != '32')
		{
			sipher_string[i] = (char)code_sipherstring[i];
			printf(" %c", sipher_string[i]);
		}
		else {
			sipher_string[i] = ' ';
			printf(" %c", sipher_string[i]);

		}
	}
}




void attack(int code_string[], int code_sipherstring[], int string_len, int a, int b, int key_a[], int key_b[], int sipher_len,int *c)
{
	char str[256];
	int p = 0;
	int j = 0;
	int k=0;
	int counter = 0;
	for (int i = j; i < sipher_len; i = j)
	{
		while ((code_sipherstring[j] > 96 && code_sipherstring[j] < 123) || (code_sipherstring[j] > 64 && code_sipherstring[j] < 91))
		{
			j = j + 1;
			counter = counter + 1;

		}
		if (counter == string_len)
		{
			if (code_string[0] > code_string[1])
			{
				a = code_string[0] - code_string[1];
				b = code_sipherstring[i] - code_sipherstring[i + 1];
				while (b%a != 0)
					b = b + 26;
				a = b / a;
				b = code_sipherstring[i] - ((code_string[0] - 97)*a + 97);
				while (b < 0)
					b = b + 26;
				b = b % 26;

			}
			if (code_string[1] > code_string[0])
			{
				a = code_string[1] - code_string[0];
				b = code_sipherstring[i + 1] - code_sipherstring[i];
				while (b%a != 0)
					b = b + 26;
				a = b / a;
				b = code_sipherstring[i] - ((code_string[0] - 97)*a + 97);
				while (b < 0)
					b = b + 26;
				b = b % 26;
			}
			if (a % 2 == 1)
			{
		

				//printf("a=%d\n", *key_a);
				//printf("b=%d\n", *key_b);
				key_a[k] = a;
				key_b[k] = b;
				k = k + 1;
			}

		}
		counter = 0;
		j = j + 1;
	}
	*c = k;
}


void sipher(int code_sipherstring[], int sipher_len,  int key_a[],int key_b[],int c)
{
	for (int j = 0; j < c; j = j + 1)
	{
		int k = 26;
		while (k%key_a[j] != (key_a[j] - 1))
			k = k + 26;
		key_a[j] = (k + 1) / key_a[j];
		for (int i = 0; i < sipher_len; i++)

		{
			if (code_sipherstring[i] > 96)
			{
				code_sipherstring[i] = code_sipherstring[i] - 97;

				code_sipherstring[i] = (key_a[j] * (code_sipherstring[i] -key_b[j] + 26) % 26) + 97;
			}
			else
			{
				code_sipherstring[i] = code_sipherstring[i] - 65;
				code_sipherstring[i] = (key_a[j] * (code_sipherstring[i] - key_b[j] + 26) % 26) + 65;
			}
		}
	}
	//for (int i = 0; i < sipher_len; i++)
		//printf("%d", code_sipherstring[i]);
}



int main()
{
	char string[256], sipher_string[256];
	int code_string[256], code_sipherstring[256];
	int a = 1;
	int b = 0;
	int i;
	int c = 0;
	int key_a[256], key_b[256];
	printf("enter string: ");
	gets_s(string);
	int string_len = strlen(string);
	code(string, code_string);
	printf("sipherstring: ");
	gets_s(sipher_string);
	int sipher_len = strlen(sipher_string);

	code(sipher_string, code_sipherstring);
	attack(code_string, code_sipherstring, string_len, a, b, key_a,key_b, sipher_len,&c);
	sipher(code_sipherstring, sipher_len, key_a, key_b,c);
	decode(code_sipherstring, sipher_string, sipher_len);
	//printf("a=%d\n", key_a);
	//printf("b=%d\n", key_b);
	return 0;
}
