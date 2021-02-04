#include <iostream>
using namespace std;

int main()
{
	int a[256];
	int i,k,n;
	int b = 1;
	int d = 0;
	int j = 1;
	printf("enter the size of the array:");
	cin >> n;
	for (i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
	cin>>a[i];
	}
		for (i = 0; i < n; i++)
		{
			while(j+i<n)
			{
			if (a[j+i] * a[j+i - 1] < 0)
				b = b++;
			else break;
			j++;
		}
			if (b > d) {
				d = b;
				k = i;
			}
			b = 1;
			j = 1;
		
	}
		for (i = k; i < d+k; i++)
			cout << a[i]<<" ";
	return 0;
}
