/*Создать класс, определяющий одномерный массив и содержащий функцию, проверяющую, 
упорядочен ли этот одномерный массив по убыванию. 
Для заданной матрицы определить, сколько ее строк упорядочены по возрастанию. 
Создать класс-наследник, позволяющий определить, состоит ли массив только из простых чисел. 
Сколько столбцов данной матрицы A(i,j упорядочены по возрастанию?
*/

#include <iostream>
#include <vector>
#include <locale>
using namespace std;

class Array {
    vector<int> arr;
public:
    Array(vector<int> tmp) {
        arr = tmp;
    }
    bool checkByDecrease() {
        for (int i = 0; i < arr.capacity()-1; i++) {
            if (arr[i] < arr[i + 1]) {
                cout << "Массив не упорядочен по убыванию" << endl;
                return false;
            }
        }
        cout << "Массив упорядочен по убыванию" << endl;
        return true;
    }
    void printArr() {
        cout << "Вывод массива из класса Array размерностью: " << arr.capacity() << endl;
        for (int i = 0; i < arr.capacity(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    vector<int> getArray() {
        return arr;
    }
};

class Matrix : Array {
    int str;
    Array matrix[];
public:
    Matrix() { 
    }
    void print() {
        printf("%d", Array::checkByDecrease());
    }
};

void print(vector<int> A, int size) {
    cout << "Вывод массива из мейна размерностью " << size << endl;
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main()
{
    setlocale(0, "");
    int array_size = 0;

    cout << "Введите размер массива: ";
    cin >> array_size;

    vector<int> origArray(array_size);
    for (auto i = 0; i < array_size; i++)
        cin >> origArray[i];
    

    Array arr(origArray);
    arr.printArr();
    cout << arr.checkByDecrease();

    return 0;
}
