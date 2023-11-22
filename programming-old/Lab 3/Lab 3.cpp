#include <iostream>
#include <ctime>
using namespace std;
class Matrix {
private: int array[10]; int size;
public:
    void moveElements(int k) { 
        for (int j = 0; j < 3 * k; j++) {
            int first = array[0];
            for (int i = 0; i < size - 1; i++) {
                array[i] = array[i + 1];
            }  
            array[size - 1] = first;
        }
    } 
    void print() {
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
    }
    Matrix(int arr[10][10], int m_size, int m_row, int multiplier) {
        for (int j = 0; j < m_size; j++) {
            array[j] = arr[m_row][j];
        }
        size = m_size;
        moveElements(multiplier);
        print();
    }

};
void input(int arr[10][10], int *row, int *column) {
    cout << "Size of matrix: ";
    cin >> *row;
    cin >> *column;
    int random = 1;
    srand(time(0));
    for (int i = 0; i < *row; i++)
        for (int j = 0; j < *column; j++) {
            if (random == 1) {
                arr[i][j] = (rand()%100);
            }
            else {
                cin >> arr[i][j];
            }
        }
}
int main()
{
    int array[10][10];
    int n = 0, m = 0, k = 0;
    input(array, &n, &m);
    for (int i = 0; i < n; i++, putchar('\n')) {
        for (int j = 0; j < m; j++) {
            cout << array[i][j] << " ";
        }
    }
    cout << "Multiplier: 3*";
    cin >> k;
    cout << "Result" << endl;
    for (int i = 0; i < n; i++, putchar('\n')) {
        Matrix work(array, m, i, k);
    }
    
    

}

