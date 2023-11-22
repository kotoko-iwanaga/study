﻿#define _CRT_SECURE_NO_WARNINGS

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "LinkedList.h"

void menu();

int main()
{
    setlocale(0, "");
    menu();
    printf("Нажмите на любую кнопку, чтобы выйти");
    _getch();
}

const char* FuncNames[14] = {
    "1) Начать работу со списком",
    "2) Сделать список пустым",
    "3) Проверка на пустоту",
    "4) Установить указатель на начало списка",
    "5) Проверка на нахождение указателя в конце списка", //5
    "6) Сдвинуть указатель на след. элемент",
    "7) Вывести значение элемента за указателем",
    "8) Удалить элемент за указателем",
    "9) Взять элемент за указателем",
    "0) Изменить значение за указателем", //10
    "a) Добавить новый элемент за указателем",
    "b) Вывести список на экран",
    "c) Удалить список",
    "d) Завершить работу программы" //14
};

void menu() {
    bool on = true;
    char choice = 0;
    List* node = NULL;
    while (on == true) {
        for (int i = 0; i < 14; i++) {
            printf("%s\n", FuncNames[i]);
        }
        choice = _getch();
        switch (choice) {
        case '1':
            createList(&node);
            break;
        case '2':
            node = clearList(node);
            break;
        case '3':
            checkClean();
            break;
        case '4':
            goToFirst();
            break;
        case '5':
            checkEnd();
            break;
        case '6':
            goToNext();
            break;
        case '7':
            getNext();
            break;
        case '8':
            deleteNext();
            break;
        case '9':
            getNextElement();
            break;
        case '0':
            changeNextElement();
            break;
        case 'A':
        case 'a':
            addNextElement();
            break;
        case 'B':
        case 'b':
            printList(node);
            break;
        case 'C':
        case 'c':
            deleteList(&node);
            break;
        case 'D':
        case 'd':
            on = false;
            break;
        default:
            printf("Повторите ввод\n");
        }
        putchar('\n');
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
