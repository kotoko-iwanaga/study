#include <iostream>
using namespace std;

int& Artemii(int& Dima) {
	Dima = 180;
	return Dima;
}


int main(void) {
	setlocale(0, "");
	int Dima = 54;
	int* Dimas = &Dima;
	int& dima = Dima;
	cout << Dima <<" ссылка " << &dima << " ссылка без доллара " << dima << " указатель " << *Dimas << " без звездочки " << Dimas << endl;
	cout << sizeof(Dimas) << " Ссылку: " << sizeof(&dima) << " Число " << sizeof(Dima) << endl;

	int mass[5] = { 10,99,30,40,50 }; 
	int& adr = mass[0];
	int* address = mass;
	cout << *(address+1) << endl;
	cout <<  *( &adr +1) << endl;
	//adr = mass[1];
	cout << adr << endl;
	for (int i= 0; i<5; i++)
		cout << mass[i] << " ";
	putchar('\n');
	int Pidor = Artemii(Dima);
	cout << Pidor << endl << Dima;
}