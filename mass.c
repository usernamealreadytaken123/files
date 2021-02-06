//на вход подается целочисленный массив ненулевых элементов. Программа выводит самую длинную знакопеременную последовательность
#include <stdio.h>


int main()
{
	int arr[256];
	int i,k,n;
	int b = 1;
	int e = 0;
	int j = 1;
	printf("enter the size of the array:");
scanf("%d", &n);
	for (i = 0; i < n; i=i+1)
	{
		printf("arr[%d] = ", i);
scanf("%d", &arr[i]);
	}
		for (i = 0; i < n; i=i+1)
		{
			while(j+i<n)
			{
			if (arr[j+i] * arr[j+i - 1] < 0)
				b = b+1;
			else break;
			j=j+1;
		}
			if (b > e) {
				e = b;
				k = i;
			}
			b = 1;
			j = 1;
		
	}
		for (i = k; i < e+k; i=i+1)
		{
				printf("%d",arr[i]);
				printf(" ");
		}
	return 0;
}
