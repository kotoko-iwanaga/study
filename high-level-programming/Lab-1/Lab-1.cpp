/*Создать класс, определяющий одномерный массив и содержащий функцию, проверяющую, 
упорядочен ли этот одномерный массив по убыванию. 
Для заданной матрицы определить, сколько ее строк упорядочены по возрастанию. 
Создать класс-наследник, позволяющий определить, состоит ли массив только из простых чисел. 
Сколько столбцов данной матрицы A(i,j) упорядочены по возрастанию?
*/

#include <iostream>
#include <vector>
#include <locale>

using namespace std;

class Array {
protected:
    vector<int> arr;
    bool checkByDecrease() {
        for (int i = 0; i < arr.capacity() - 1; i++) {
            if (arr[i] < arr[i + 1]) {
                return false;
            }
        }
        return true;
    }
public:
    Array(int size) {
        arr.resize(size);
    }
    void setArray(int size) {
        arr.resize(size);
        int i = 0;
        while (i < arr.capacity()) {
            cin >> arr[i];
            if (cin.fail())
            {
                printf("Ошибка ввода элемента, повторите ввод\n");
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            i++;
        }
    }
    vector<int> getArray() {
        return arr;
    }
    bool getCheckByDecrease() {
        return checkByDecrease();
    }
    void printArr() {
        for (int i = 0; i < arr.capacity(); i++) {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
};

class Matrix : public Array {
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
    bool isSimple() {
        for (int i = 0; i < getArray().capacity(); i++) {
            if (isPrime(getArray()[i]) == false) {
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
public:
    Matrix(vector<Array> tmp):Array(1){
        matrix = tmp;
    }
    bool getSimple() {
        return isSimple();
    }

    int getColumnsByIncrease() {
        return columnsByIncrease();
    }

    int getRowsByIncrease() {
        return rowsByIncrease();
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
    if (rows <= 0 or columns <= 0) {
        printf("Произошла ошибка ввода размерности матрицы");
        exit(1);
    }
    cout << "Введите элементы массива" << endl;
    vector<Array> origArray(rows, Array(columns));

    for (int i = 0; i < rows; i++) 
        origArray[i].setArray(columns);

    Matrix matrix(origArray);
    cout << "Вот ваша матрица" << endl;
    matrix.printMatrix();
    cout << "Сколько строк возрастает по порядку: " << matrix.getRowsByIncrease() << endl;
    cout << "Сколько столбцов возрастает по порядку: " << matrix.getColumnsByIncrease() << endl;
    cout << "Введите размер массива класса Array" << endl;
    int arrSize;
    cin >> arrSize;
    if (arrSize <= 0) {
        printf("Произошла ошибка ввода размерности массива");
        exit(1);
    }
    cout << "Введите элементы массива" << endl;
    matrix.setArray(arrSize);
    matrix.printArr();
    cout << "Простая: " << matrix.getSimple() << endl;
    cout << "Упорядочен по убыванию: " << matrix.getCheckByDecrease() << endl;
    
}
