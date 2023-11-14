//﻿12. Дана строка символов. Группы символов, разделенные пробелами (одним или
//несколькими) и не содержащие пробелов внутри себя, будем называть словами.
//Преобразовать строку, удвоив в ней самое короткое слово.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CharWork.h"


typedef struct List {
    char c;
    struct List* next;
} List;


void push(List** head, char data) {
    List* tmp = (List*)malloc(sizeof(List));
    tmp->c = data;
    tmp->next = (*head);
    (*head) = tmp;
}
void printList(const List* head) {
    while (head) {
        printf("%c", head->c);
        head = head->next;
    }
}

void getFromArray(List** head, char* str) {
    for (int i = strlen(str) - 2; i >= 0; i--) {
        push(head, str[i]);
    }
}

void setMinWord(int& temp, int& min, int& pos, int& temp_pos) {
    if (temp != 0) {
        pos = min >= temp ? temp_pos : pos;
        min = min >= temp ? temp : min;
    }
    temp = 0;
}


void getMinLength(const List* head, int& min, int& pos) {
    int temp_min_word = 0;
    int i = 0;
    while (head) { // находим длину наименьшего слова
        switch (head->c) {
        case '\n':
        case '\0':
        case ' ':
            setMinWord(temp_min_word, min, pos, i); 
            break;
        default:
            temp_min_word++;
        }
        head = head->next;
        i++;
    }
    setMinWord(temp_min_word, min, pos, i);
}

char* getMinWord(const List* head, int pos, int min_length) {
    char* minimum = (char*) malloc(sizeof(char)*min_length);
    for (int i = 0; head; i++) {
        if (i >= pos-min_length && i < pos) {
            minimum[i - (pos - min_length)] = head->c;
        }
        else if (i >= pos) {
            break;
        }
        head = head->next;

    }
    minimum[min_length] = '\0';
    return minimum;
}


void insert(List* head, unsigned n, int val) {
    unsigned i = 0;
    List* tmp = NULL;
    //Находим нужный элемент. Если вышли за пределы списка, то выходим из цикла,
    //ошибка выбрасываться не будет, произойдёт вставка в конец
    while (i < n && head->next) {
        head = head->next;
        i++;
    }
    tmp = (List*)malloc(sizeof(List));
    tmp->c = val;
    //Если это не последний элемент, то next перекидываем на следующий узел
    if (head->next) {
        tmp->next = head->next;
        //иначе на NULL
    }
    else {
        tmp->next = NULL;
    }
    head->next = tmp;
}

void doubleMinWord(List* head, char* minimum, int min_length, int pos) {
    for (int i = 0; i < min_length; i++) {
        insert(head, pos - 1 + i, minimum[i]);
    }
}

int main() {
    List* head = NULL;
    int position = 0;
    int min_length = 707*707;
    int size = 100;
    char* str = (char*)calloc(size,sizeof(char));

    fgets(str, size, stdin);
    getFromArray(&head, str);
    getMinLength(head, min_length, position);
    char* min_word = getMinWord(head, position, min_length);
    printf("min_l: %d\n min_w: %s \n position: %d\n", min_length, min_word, position);

    doubleMinWord(head, min_word, min_length, position);
    
    printList(head); 
    

    
}
