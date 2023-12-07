﻿// FreadTest.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <stdio.h>
#include <io.h>
int main()
{
    std::cout << "Hello World!\n";
    FILE* file = nullptr;

    file = fopen("1.dat", "wb");
    const int data[] = { 1,2,3,4,5 };
    fwrite(data, sizeof(int), 3, file);
    fclose(file);

    file = fopen("1.dat", "rb");
    int readData[100] = {0};
    fread(readData, sizeof(int), 3, file);
    for (int i = 0; i < 3; i++) {
        std::cout << readData[i];
    }
    fclose(file);
    
    file = fopen("1.dat", "rb");
    fseek(file, 0* sizeof(int), SEEK_CUR);
    int num;
    fread(&num, sizeof(int), 1, file);
    std::cout << num << std::endl;
    fclose(file);

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