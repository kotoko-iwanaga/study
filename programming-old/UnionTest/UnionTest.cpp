// UnionTest.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

struct {
	unsigned int a : 1;
	unsigned int b : 4;
} otchislenie;

void ShowMSG(string msg, int x, int y = 0) {
	cout << msg << endl;
	printf("x: %d y: %d\n", x, y);
}
void ShowMSG(char msg, int x = 0, int y = 0) {
	cout << msg << endl;
	printf("x: %d y: %d\n", x, y);
}
void ShowMSG(string msg, int &x, int y = 0) {
	cout << msg << endl;
	printf("x: %d y: %d\n", x, y);
}


union Artemii {
	char a;
	int b;
	//string p;
	long long int c;
} ;



int main()
{
	setlocale(0, "");
	ShowMSG("Расформируем 15 группу\n");
	ShowMSG("Разделим 14 группу", 15, 10);
	cout << sizeof(otchislenie) << endl;
	cout << sizeof(Artemii) << endl;
	otchislenie.a = 0;
	otchislenie.b = 3;
	for (int i = 0; i < 1024; i++) {
		otchislenie.a = i;
		otchislenie.b = i;
		cout << otchislenie.a << " | " << otchislenie.b << endl;
		if (otchislenie.b = 0) {
			break;
		}
	}
	/*Artemii.a = '\0';
	Artemii.b = 128;
	Artemii.p = "Сосед мой любимый";
	Artemii.c = 65838348;

	cout << sizeof(Artemii) << endl;*/
	


}

//#include <iostream>
//
//class Base {
//public:
//	Base() {
//		std::cout << "Constructor" << std::endl;
//	}
//	~Base() {
//		std::cout << "Destructor" << std::endl;
//	}
//};
//
//void foo() {
//	Base static obj;
//} // строка 15
//
//int main() {
//	foo();
//	std::cout << "End of main()" << std::endl;
//	return 0;
//}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
