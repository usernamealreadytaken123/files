#include <stdio.h>
#include <string.h>
#include <stdlib.h>



void code(char string[], int code_string[])

{
	int i = 0, j = 0;
	for (i = 0; string[i] != '\0'; i=i+1)
	{
		code_string[i] = (int)string[i];
		j=j+1;
	}
	printf ("Encrypted string: ");
	for (i = 0; i < j; i=i+1)
	{
		printf(" %d", code_string[i]);
	}
	printf(" \n");

}
void cipher( int code_string[], int code_sipherstring[], int string_len,int a,int b, int* key_a, int* key_b)
{
	int j = 0;
	int counter = 0;
	for (int a = 1; a < 26; a = a + 2) 
		for (int b = 0; b < 25; b = b + 1){
			for (int i = 0; i <= string_len ; i=i+1)
			{
					if (code_sipherstring[i] == (((a * (code_string[i]-97) + b) % 26) + 97))
					{
						counter = counter +1;
				
					}
					if (counter == string_len)
					{
				
						*key_a = a;
						*key_b = b;
						goto stop;
					}
				}
			counter = 0;
			}
	

stop:
	a=a;
	

}

		




int main()
{
	char string[256], sipher_string[256];
	int code_string[256], c, code_sipherstring[256];
	int a=1;
	int b=0;
	int key_a, key_b;
	printf ("enter string: ");
	gets(string);
	int string_len = strlen(string);
	code(string, code_string);
	printf ("key=");
	gets(sipher_string);
	int sipher_len = strlen(sipher_string);
	if (sipher_len != string_len) 
		goto error;
	
	code(sipher_string, code_sipherstring);
	cipher(code_string, code_sipherstring, string_len,a,b,&key_a,&key_b);
	if (key_a<0)
		goto error;
	printf("a=%d\n", key_a);
	printf("b=%d\n", key_b);
	goto exit;
error:
	
		printf("error");
		exit:
	return 0;
}
