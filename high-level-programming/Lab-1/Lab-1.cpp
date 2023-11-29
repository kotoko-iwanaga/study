// Lab-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale>
using namespace std;

class Array {
    int size;
    int* newArray = 0;
public:
    Array(int sizeArr, int *origArray) {
        size = sizeArr;
        newArray = new int(size);
        for (int i = 0; i < size; i++)
            newArray[i] = origArray[i];
    }
    bool checkByDecrease() {
        for (int i = 0; i < (size-1); i++) {
            if (newArray[i] < newArray[i + 1]) { 
                return false;
            }
        }
        return true;
    }
    void printArray() {
        for (int i = 0; i < size; i++)
            cout << newArray[i];
    }
    int *getArray() {
        return newArray;
    }
};

int* inputToArray(int size) {
    int* array = new int(size);
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }
    return array;
}

int main()
{
    setlocale(0, "");
    int sizeArr = 0;

    cout << "Введите размер массива: ";
    cin >> sizeArr;

    int* origArray = new int(sizeArr);
    origArray = inputToArray(sizeArr);

    Array arr{ sizeArr, origArray[5]};
    arr.printArray();
    int* test = 0;
    memcpy(test, arr.getArray(), sizeArr);
    //cout << arr.checkByDecrease();

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
