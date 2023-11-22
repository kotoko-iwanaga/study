// ClassTest.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define randx(x) x + 1

#if OOPS:
    #error oopS
#endif


#include <iostream>

using namespace std;

class Human{
public:
    int level_of_Human;
    int gay_level;
    float pi_dor_counter;
private:
    static int n;
public:
    void huilan() {
        cout << "L: " << level_of_Human << endl;
        cout << "G: " << gay_level << endl;
        cout << "B: " << pi_dor_counter << endl;
        cout << "T: 1000%\n\n";
    }
    Human(int xyi, int pizda, float zalupa);
    void staticwork(int x) {
        n = x;
    }
    void staticshow() {
        cout << n << endl;
    }

    Human operator / (int a) {
        Human temp(level_of_Human, gay_level, pi_dor_counter);
        temp.level_of_Human /= a;
        temp.gay_level /= a;
        temp.pi_dor_counter *=a;
        return temp;
    }
    Human operator + () {
        Human Artemii(level_of_Human, gay_level, pi_dor_counter);
        Artemii.level_of_Human += Artemii.level_of_Human;
        Artemii.gay_level += Artemii.gay_level;
        Artemii.pi_dor_counter += Artemii.pi_dor_counter;
        return Artemii;
    }
    Human operator - (int a) {
        Human temp((a - this->level_of_Human), (a - this->gay_level), (a - this->pi_dor_counter));
        return temp;
    }

    void operator ~ () {
        printf("%d", 2);
    }
    void operator >> (double d) {
        printf("%f", d);
    }
    //fiend Human operator - (int a, const Human& c1);
};

Human::Human(int xyi, int pizda, float zalupa) : level_of_Human(xyi), gay_level(pizda), pi_dor_counter(zalupa) {}

int Human::n = 4;

int* foo(int* n) {
    ++(*n);
    return n;
}





int main()
{
    int nu = 4;
    *foo(&nu) *= 3;
    *foo(&nu) *= 3;
    cout << nu << endl;

    Human Artemii1(999900, 0, 0);
    Artemii1.staticshow();
    Human Di(1, 999, 999);
    Di.staticshow();
    //Artemii1 + 4; 
    putchar('\n');
    char c[] = "hjahaskbdasikcabniakjsdniasfhkasnduasunisadnsudknasudnaslkdasdnsaklsadsaldkaslddasksadl";
    std::cout << sizeof(c) << "|" << sizeof(*c) << "|" << sizeof(&c) << endl;
    cout << ~0 << endl;
    cout << randx(3);
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
