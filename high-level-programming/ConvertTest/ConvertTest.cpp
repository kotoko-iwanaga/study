// ConvertTest.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void cinTest();
void roundTest();

int main()
{
    roundTest();
    //cinTest();
}

void roundTest() {
    double a = 0;
    double b = 0;
    cin >> a;
    cout << "A is " << a << endl;
    cout << "ABS A is " << abs(a) << endl;
    b = floor(abs(a));
    cout << "B is " << b << endl;
    if (abs(a) - floor(abs(a)) == 0) {
        cout << "Happy-happy-happy" << endl;
    }
    else {
        cout << "sosi" << endl;
     }
    cout << a <<endl;
}


void cinTest() {
    double a = 0;
    int b;
    std::cin >> a;
    b = (int)a;
    std::cout << "Double: " << a << std::endl;
    std::cout << "Int: " << b << std::endl;
    cout << "Please input elements of an 1D array" << endl;
    //vector<int> Artemiy((int)a); // Best variant
    //int* Artemiy = (int*)malloc(sizeof(int)*(int)a); //Normal
    //int* Artemiy = (int*) calloc(sizeof(int),(int)a); //Normal
    int* Artemiy = new int[(int)a]; // Works like a shit
    for (int i = 0; i < (int)a; i++) {
        cin >> Artemiy[i];
        if (cin.fail()) {
            cout << "Type error" << endl;
            i--;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        /*if (cin.fail()) {
            cout << "Error with Artemiy" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            i--;
        }*/
    }
    cout << "Array 1D:" << endl;
    for (int i = 0; i < (int)a; i++, putchar('\n')) {
        cout << Artemiy[i] << " ";
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
