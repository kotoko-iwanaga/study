#include <iostream>
using namespace std;


void idb2215(int& x) {
	x++;
	cout << x << endl;
}
void idb2214(int* x) {
	(*x)++;
	cout << *x << endl;
}
void idb2216(int x) {
	x++;
	cout << x << endl;
}

void main(void) {
	setlocale(0, "");
	char c[9] = "Артемий ";
	char b[9];
	strcpy_s(b, c);
	cout << c << b << endl;
	int polina = 28;
	idb2216(polina);
	idb2214(&polina);
	idb2215(polina);
}