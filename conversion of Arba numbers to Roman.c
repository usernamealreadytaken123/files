#include <iostream>
using namespace std;
int main()
{
	int i = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, j = 0;
	int a;
	cout << "enter the number:" << endl;
	cin >> a;
	for (int i = a; i >= 1000; i = i - 1000) {
		b++;
	}
	for (int i = a - b * 1000; i >= 500; i = i - 500) {
		c++;
	}
	for (int i = a - b * 1000 - c * 500; i >= 100; i = i - 100) {
		d++;
	}
	for (int i = a - b * 1000 - c * 500 - d * 100; i >= 50; i = i - 50) {
		e++;
	}
	for (int i = a - b * 1000 - c * 500 - d * 100 - e * 50; i >= 10; i = i - 10) {
		f++;
	}
	for (int i = a - b * 1000 - c * 500 - d * 100 - e * 50 - f * 10; i >= V; i = i - 5) {
		g++;
	}
	for (int i = a - b * 1000 - c * 500 - d * 100 - e * 50 - f * 10 - g * 5; i >= 1; i--) {
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
