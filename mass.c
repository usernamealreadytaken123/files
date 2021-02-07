//на вход подается целочисленный массив ненулевых элементов. Программа выводит самую длинную знакопеременную последовательность
#include <stdio.h>


int main()
{
	int arr[256];
	int i, first_element_of_sequence, arr_size;
	int counter = 1;
	int sequence_len = 0;
	int j = 1;
	printf("enter the size of the array:");
scanf("%d", &arr_size);
	for (i = 0; i < arr_size; i=i+1)
	{
		printf("arr[%d] = ", i);
scanf("%d", &arr[i]);
	}
		for (i = 0; i < arr_size; i=i+1)
		{
			while(j+i<arr_size)
			{
			if (arr[j+i] * arr[j+i - 1] < 0)
				counter = counter+1;
			else break;
			j=j+1;
		}
			if (counter > sequence_len) {
				sequence_len = counter;
				first_element_of_sequence = i;
			}
			counter = 1;
			j = 1;
		
	}
		for (i = first_element_of_sequence; i < sequence_len+first_element_of_sequence; i=i+1)
		{
				printf("%d",arr[i]);
				printf(" ");
		}
	return 0;
}
