#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct node {
    char word[50];
    struct node* next;
    struct node* prev;
} Node;

void insert(Node** head, char* word) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->word, word);
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*head == NULL) {
        *head = new_node;
    }
    else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }
}

void doubleMinWord(Node* head) {
    Node* current = head;
    Node* minNode = head;
    int minLength = strlen(head->word);

    while (current != NULL) {
        int length = strlen(current->word);
        if (length < minLength) {
            minLength = length;
            minNode = current;
        }
        current = current->next;
    }

    char* doubledWord = (char*)malloc(sizeof(char) * (minLength * 2 + 1));
    strcpy(doubledWord, minNode->word);
    strcat(doubledWord, minNode->word);
    strcpy(minNode->word, doubledWord);
    free(doubledWord);
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%s ", current->word);
        current = current->next;
    }
    printf("\n");
}

int main() {
    setlocale(0, "");
    char input[100];
    printf("Введите строку: ");
    fgets(input, sizeof(input), stdin);

    Node* head = NULL;
    char* word = strtok(input, " \n");
    while (word != NULL) {
        insert(&head, word);
        word = strtok(NULL, " \n");
    }

    printf("Исходная строка: ");
    printList(head);

    doubleMinWord(head);

    printf("Результат: ");
    printList(head);

    return 0;
}