#include <iostream>
using namespace std;

int main()
{
	int n, m,d,f,g;
	cout << "Enter a matrix size:" << "\n";
	cout << "n = ";
	cin >> n;
	cout << "m = ";
	cin >> m;
	if (n % 2 == 0) d = n * 0.5;
	if (n % 2 == 1) d = (n+1)*0.5;
	int** a = new int*[n];
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}
	cout << "Enter a matrix:" << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << a[i][j];
				cout << " ";
			}
			cout << endl;
		}
		if (n % 2 == 0){
		for (int k = 0; k < d; k++) {
			for (int i = k; i < d; i++) {
				s = s + a[i][d - k - 1] + a[i][d + k];
			}
		}
		g = -1;
		for (int k = 0; k < d; k++) {
			if (d >= 3) {
				if (g > 0) {
					for (int i = d; i < n - 1 - g; i++) {
						s = s + a[i][k + i - d] + a[i][n - k - 1 - i + d];
					}
				}
				if (g <= 0) {
					for (int i = d; i < n - 1; i++) {
						s = s + a[i][k + i - d] + a[i][n - k - 1 - i + d];
					}
				}
			}
			if (d < 3) {
				for (int i = d; i < n - 1; i++) {
					s = s + a[i][k + i - d] + a[i][n - k - 1 - i + d];
				}
			}
			g = g + 1;

		}
		for (int i = n - 1; i < n; i++) {
			s = s + a[i][d - 1] + a[i][d];
		}
	}
		if (n % 2 == 1) {
			for (int k = 0; k < d - 1; k++) {
				for (int i = k; i < d - 1; i++) {
					s = s + a[i][d - 2 - i] + a[i][d + i];
				}
			}
			for (int i = 0; i < n; i++) {
				s = s + a[d - 1][i];
			}
			for (int i = 0; i < n; i++) {
				s = s + a[i][d - 1];
			}

			for (int k = 0; k < d - 1; k++) {
				for (int i = d; i < n - k; i++) {
					s = s + a[i][i - d + k] + a[i][n + d - i - 1 - k];
				}
			}
			s = s - a[d - 1][d - 1];
		}
		cout << "figure area=";
	cout << s;
	return 0;
}
