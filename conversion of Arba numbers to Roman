#include <iostream>
using namespace std;
int main()
{
	int I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000, i = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, j = 0;
	int a;
	cout << "enter the number:" << endl;
	cin >> a;
	for (int i = a; i >= M; i = i - M) {
		b++;
	}
	for (int i = a - b * M; i >= D; i = i - D) {
		c++;
	}
	for (int i = a - b * M - c * D; i >= C; i = i - C) {
		d++;
	}
	for (int i = a - b * M - c * D - d * C; i >= L; i = i - L) {
		e++;
	}
	for (int i = a - b * M - c * D - d * C - e * L; i >= X; i = i - X) {
		f++;
	}
	for (int i = a - b * M - c * D - d * C - e * L - f * X; i >= V; i = i - V) {
		g++;
	}
	for (int i = a - b * M - c * D - d * C - e * L - f * X - g * V; i >= I; i--) {
		j++;
	}
	cout << "roman number: ";
	for (int i = 0; i <= b - 1; i++) {
		cout << "M";
	}
	if (c == 1 && d == 4) {
		cout << "CM";
	}
	else {
		for (int i = 0; i <= c - 1; i++) {
			cout << "D";
		}
	}
	if (c == 1 && d == 4) {
		d = 0;
	}
	else if (d == 4) {
		cout << "CD";
	}
	else {
		for (int i = 0; i <= d - 1; i++) {
			cout << "C";
		}
	}
	if (e == 1 && f == 4) {
		cout << "XC";
	}
	else {
		for (int i = 0; i <= e - 1; i++) {
			cout << "L";
		}
	}
	if (e == 1 && f == 4) {
		f = 0;
	}
	else if (f == 4) {
		cout << "XL";
	}
	else {
		for (int i = 0; i <= f - 1; i++) {
			cout << "X";
		}
	}
	if (g == 1 && j == 4) {
		cout << "IX";
	}
	else {
		for (int i = 0; i <= g - 1; i++) {
			cout << "V";
		}
	}
	if (g == 1 && j == 4) {
		j = 0;
	}
	else if (j == 4) {
		cout << "IV";
	}
	else {
		for (int i = 0; i <= j - 1; i++) {
			cout << "I";
		}
	}

	return 0;
}
