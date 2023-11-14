//﻿12. Дана строка символов. Группы символов, разделенные пробелами (одним или
//несколькими) и не содержащие пробелов внутри себя, будем называть словами.
//Преобразовать строку, удвоив в ней самое короткое слово.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CharWork.h"


typedef struct Node {
    char c;
    struct Node* next;
} Node;


void push(Node** head, char data) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->c = data;
    tmp->next = (*head);
    (*head) = tmp;
}
void printList(const Node* head) {
    while (head) {
        printf("%c", head->c);
        head = head->next;
    }
}

int main() {
    char z = 0;
    Node* head = NULL;
    for (int i = 0; (z = getchar()) != '\n'; i++) {
        push(&head, z);
    }
    char* str = (char*)malloc(sizeof(head));
    z = 0;
    while (head) {
        str[z] = head->c;
        head = head->next;
        z++;
    }
    str[z] = '\0';
    for (int i = strlen(str); i >= 0; i--) {
        printf("%c", str[i]);
    }
    
    
}


//char* str;
//str = get_string_by_malloc(stdin); // сам массив символов
//int str_size = strlen(str); // размер массива
//int min_word = str_size + 1; // длина мин слова
//int min_word_pos = 0; // последний символ наикороткого слова
//// поиск длины мин слова
//findMinWord(str, strlen(str), min_word, min_word_pos);
//// обработка строки
//moveChar(str, strlen(str), min_word, min_word_pos);
//// вывод результата и некоторой статистики
//printf("%s\n", str);
//free(str); // освобождаем память



//printf("Minimum length: %d\n", min_word);
//printf("End position: %d\n", min_word_pos - 1);
//printf("Length of string: %d\n", (int)strlen(str));