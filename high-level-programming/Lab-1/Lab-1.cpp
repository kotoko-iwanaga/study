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
    Array() {}
    Array(int size) {
        arr.resize(size);
    }
    void setArray() {
        for (int i = 0; i < arr.capacity(); i++)
            cin >> arr[i];
    }
    vector<int> getArray() {
        return arr;
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
        for (int i = 0; i < arr.capacity(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Matrix : Array {
    vector<Array> matrix;

    bool isPrime(int number) {
        for (int i = 2; i <= number / 2; ++i)
            if (number % i == 0)
                return false;
        return true;
    }
    bool checkRowIncrease(int row) {
        for (int j = 0; j < matrix[row].getArray().capacity() - 1; j++) {
            if (matrix[row].getArray()[j] >= matrix[row].getArray()[j + 1]) {
                return false;
            }
        }
        return true;
    }
    bool checkColumnIncrease(int column) {
        for (int i = 0; i < matrix.capacity() - 1; i++) {
            if (matrix[i].getArray()[column] >= matrix[i + 1].getArray()[column]) {
                return false;
            }
        }
        return true;
    }
public:
    Matrix(vector<Array> tmp) {
        matrix = tmp;
    }
    bool isSimple(int row) {
        for (int i = 0; i < matrix[row].getArray().capacity(); i++) {
            if (isPrime(matrix[row].getArray()[i]) == false) {
                return false;
            }
        }
        return true;
    }
    int columnsByIncrease() {
        int result = 0;
        for (int j = 0; j < matrix[0].getArray().capacity(); j++) {
            if (checkColumnIncrease(j) == true) {
                result++;
            }
        }
        return result;
    }
    int rowsByIncrease() {
        int result = 0;
        for (int i = 0; i < matrix.capacity(); i++) {
            if (checkRowIncrease(i) == true) {
                result++;
            }
        }
        return result;
    }

    void printMatrix() {
        for (int i = 0; i < matrix.capacity(); i++)
            matrix[i].printArr();
    }
};

int main()
{
    setlocale(0, "");
    int rows = 0, columns = 0; // строки и столбцы;

    cout << "Введите размеры матрицы: ";
    cin >> rows >> columns;
    cout << "Введите элементы массива" << endl;
    vector<Array> origArray(rows, Array(columns));

    for (int i = 0; i < rows; i++)
        origArray[i].setArray();

    Matrix matrix(origArray);
    cout << "Вот ваша матрица" << endl;
    matrix.printMatrix();
    cout << "Сколько строк возрастает по порядку: " << matrix.rowsByIncrease() << endl;
    cout << "Сколько столбцов возрастает по порядку: " << matrix.columnsByIncrease() << endl;
    cout << "Первая строка с простыми числами? " << matrix.isSimple(1) << endl;

}
