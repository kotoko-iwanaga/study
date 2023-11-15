//﻿12. Дана строка символов. Группы символов, разделенные пробелами (одним или
//несколькими) и не содержащие пробелов внутри себя, будем называть словами.
//Преобразовать строку, удвоив в ней самое короткое слово.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

void getFromArray(List**, char*);
void setMinWord(int&, int&, int&, int&);
void getMinLength(const List*, int&, int&);
char* getMinWord(const List*, int, int);
void doubleMinWord(List*, char*, int, int);


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
    printf("min_l: %d\nmin_w: %s\nposition: %d\n", min_length, min_word, position);

    doubleMinWord(head, min_word, min_length, position);
    printList(head); 

    deleteList(&head);
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
    char* minimum = (char*)malloc(sizeof(char) * min_length);
    for (int i = 0; head; i++) {
        if (i >= pos - min_length && i < pos) {
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

void doubleMinWord(List* head, char* minimum, int min_length, int pos) {
    for (int i = 0; i < min_length; i++) {
        insert(head, pos - 1 + i, minimum[i]);
    }
}