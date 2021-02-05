#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>


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
	printf(" \n");

}
void cipher( int str1[], int str4[], int d, int f,int a,int b, int* e, int* g, int* h )
{
	int j = 0;
	int c = 0;
	for (int a = 1; a < 26; a = a + 2) 
		for (int b = 0; b < 25; b = b + 1){
			for (int i = 0; i <= d ; i=i+1)
			{
					if (str4[i] == (((a * (str1[i]-97) + b) % 26) + 97))
					{
						c=c+1;
				
					}
					if (c == d)
					{
				
						*e = a;
						*g = b;
						goto stop;
					}
				}
			c = 0;
			}
	

stop:
	a=a;
	

}

		




int main()
{
	char str[256], str3[256], str5[256];
	int str1[256], c, str4[256], str6[256];
	int a=1;
	int b=0;
	int e, g;
	int h;
	printf ("enter string: ");
	gets(str);
	int d = strlen(str);
	code(str, str1);
	printf ("key=");
	gets(str3);
	int f = strlen(str3);
	if (f != d) 
		goto error;
	
	code(str3, str4);
	cipher(str1, str4, d, f,a,b,&e,&g,&h);
	if (e<0)
		goto error;
	printf("a=%d\n", e);
	printf("b=%d\n", g);
	goto exit;
error:
	
		printf("error");
		exit:
	return 0;
}
