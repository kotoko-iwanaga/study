// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;

void calloc_test() {
    int* wtf = 0;
    int size = 0;
    cout << "Vvedite: ";
    cin >> size;
    wtf = (int*)calloc(sizeof(int), size);

    for (int i = 0; i < size; i++) {
        wtf[i] = i + 3;
    }
    for (int i = 0; i < size; i++)
        cout << wtf[i] << endl;
    std::cout << "Hello World!\n";

    int* wtf2 = (int*)calloc(sizeof(int), size);
    memcpy(wtf2, wtf, size * sizeof(int));

    for (int i = 0; i < size; i++)
        cout << wtf[i] << endl;
    for (int i = 0; i < size; i++)
        cout << wtf2[i] << endl;
}

vector<int> arrayCPPTest() {
    int size = 0;
    cout << "vvedi: ";
    cin >> size;
    vector<int> A(size);
    for (int i = 0; i < size; i++)
        cin >> A[i];
    for (int i = 0; i < size; i++)
        cout << A[i] << endl;
    return A;
}

int main()
{
    setlocale(0, "");
    vector<int> B = arrayCPPTest();
    cout << "Вывод скопированного вектора B длиной: " << B.capacity() << endl;
    for (auto i = 0; i<4; i++)
        cout << B[i] << endl;
    
    vector<int> C = B;
    for (auto i = 0; i < 4; i++)
        C[i] *= 2;
    cout << "Вывод модифицированного цикла C длиной: " << C.capacity() << endl;
    for (auto i = 0; i < 4; i++)
        cout << C[i] << endl;
    cout << "Вывод оригинального вектора B длиной: " << B.capacity() << endl;
    for (auto i = 0; i < 4; i++)
        cout << B[i] << endl;
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
