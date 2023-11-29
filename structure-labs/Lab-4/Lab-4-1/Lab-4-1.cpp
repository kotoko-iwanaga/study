#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale>

struct List {
    int data;
    struct List* next;
};

struct List* head = NULL;
struct List* current = NULL;

//Функция для создания пустого списка
struct List* createLinkedList() {
    return NULL;
}

// Функция для создания нового узла
struct List* createList(int data) {
    struct List* newList = (struct List*)malloc(sizeof(struct List));
    if (newList == NULL) {
        printf("Ошибка: не удалось выделить память для нового узла\n");
        exit(1);
    }

    newList->data = data;
    newList->next = NULL;
    return newList;
}

// Функция для добавления нового элемента в конец списка
void addList(int data) {
    struct List* newList = createList(data);

    if (head == NULL) {
        head = newList;
        current = newList;
    }
    else {
        current->next = newList;
        current = newList;
    }

    printf("Элемент успешно добавлен\n");
}

// Функция для удаления элемента за рабочим указателем
void deleteList() {
    if (current == NULL) {
        printf("Ошибка: список пуст\n");
        return;
    }

    struct List* temp = current->next;
    if (temp == NULL) {
        printf("Ошибка: нет элемента за рабочим указателем\n");
        return;
    }

    current->next = temp->next;
    free(temp);

    printf("Элемент успешно удален\n");
}

// Функция для вывода значения элемента за рабочим указателем
void printCurrentValue() {
    if (current == NULL) {
        printf("Ошибка: список пуст\n");
        return;
    }

    struct List* temp = current->next;
    if (temp == NULL) {
        printf("Ошибка: нет элемента за рабочим указателем\n");
        return;
    }

    printf("Значение элемента за рабочим указателем: %d\n", temp->data);
}

// Функция для изменения значения элемента за рабочим указателем
void modifyCurrentValue() {
    if (current == NULL) {
        printf("Ошибка: список пуст\n");
        return;
    }

    struct List* temp = current->next;
    if (temp == NULL) {
        printf("Ошибка: нет элемента за рабочим указателем\n");
        return;
    }

    int newValue;
    printf("Введите новое значение элемента: ");
    scanf("%d", &newValue);

    temp->data = newValue;
    printf("Значение элемента успешно изменено\n");
}

// Функция для перемещения рабочего указателя на следующий элемент
void moveNext() {
    if (current == NULL) {
        printf("Ошибка: список пуст\n");
        return;
    }

    current = current->next;
    if (current == NULL) {
        printf("Ошибка: рабочий указатель уже находится в конце списка\n");
    }
    printf("Рабочий указатель успешно перемещен на следующий элемент\n");
}

// Функция для проверки списка на пустоту
void checkEmpty() {
    if (head == NULL) {
        printf("Список пуст\n");
    }
    else {
        printf("Список не пуст\n");
    }
}

// Функция для установки рабочего указателя в начало списка
void resetCurrent() {
    current = head;
    if (current == NULL) {
        printf("Ошибка: список пуст\n");
    }
    else {
        printf("Рабочий указатель успешно установлен в начало списка\n");
    }
}

// Функция для очистки списка
void clearList() {
    struct List* temp;

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    current = NULL;

    printf("Список успешно очищен\n");
}

// Функция для печати списка
void printList() {
    if (head == NULL) {
        printf("Список пуст\n");
        return;
    }

    struct List* temp = head;

    printf("Элементы списка: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    setlocale(0, "");
    char choice;
    int value;

    while (1) {
        printf("Меню:\n");
        printf("1) Начать работу со списками\n");
        printf("2) Сделать список пустым\n");
        printf("3) Проверка списка на пустоту\n");
        printf("4) Установить рабочий указатель в начало списка\n");
        printf("5) Проверка находится ли рабочий указатель в конце списка\n");
        printf("6) Сдвинуть рабочий указатель на следующий элемент\n");
        printf("7) Вывести значение элемента за рабочим указателем\n");
        printf("8) Удалить элемент за рабочим указателем\n");
        printf("9) Взять элемент за рабочим указателем\n");
        printf("0) Изменить значение элемента за рабочим указателем\n");
        printf("a) Добавить элемент за рабочий указатель\n");
        printf("b) Распечатать список\n");
        printf("c) Закончить работу со списком\n");
        printf("d) Закончить работу программы\n");
        choice = _getch();

        switch (choice) {
        case '1':
            head = createLinkedList();
            if (head == NULL) {
                printf("Список успешно создан и пуст\n");
            }
            break;
        case '2':
            clearList();
            break;
        case '3':
            checkEmpty();
            break;
        case '4':
            resetCurrent();
            break;
        case '5':
            if (current == NULL) {
                printf("Ошибка: список пуст\n");
            }
            else if (current->next == NULL) {
                printf("Рабочий указатель находится в конце списка\n");
            }
            else {
                printf("Рабочий указатель не находится в конце списка\n");
            }
            break;
        case '6':
            moveNext();
            break;
        case '7':
            printCurrentValue();
            break;
        case '8':
            deleteList();
            break;
        case '9':
            if (current == NULL) {
                printf("Ошибка: список пуст\n");
            }
            else if (current->next == NULL) {
                printf("Ошибка: нет элемента за рабочим указателем\n");
            }
            else {
                printf("Элемент за рабочим указателем: %d\n", current->next->data);
            }
            break;
        case '0':
            modifyCurrentValue();
            break;
        case 'a':
            printf("Введите значение элемента: ");
            scanf("%d", &value);
            addList(value);
            break;
        case 'b':
            printList();
            break;
        case 'c':
            current = NULL;
            printf("Работа со списком завершена\n");
            clearList();
            break;
        case 'd':
            printf("Работа программы завершена\n");
            exit(0);
            break;
        default:
            printf("Неверный выбор. Попробуйте еще раз\n");
        }
    }

    return 0;
}