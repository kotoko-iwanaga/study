#pragma once
typedef struct List {
    char c;
    struct List* next;
} List;

void push(List**, char);
int pop(List**);
void printList(const List*);
void insert(List*, unsigned, int);
List* getNth(List*, int);
int deleteNth(List**, int);



void push(List** head, char data) {
    List* tmp = (List*)malloc(sizeof(List));
    tmp->c = data;
    tmp->next = (*head);
    (*head) = tmp;
}

int pop(List** head) { // �������� ������� ��������
    List* prev = NULL;
    int val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->c;
    (*head) = (*head)->next;
    free(prev);
    return val;
}

void printList(const List* head) {
    while (head) {
        printf("%c", head->c);
        head = head->next;
    }
}

void insert(List* head, unsigned n, int val) {
    unsigned i = 0;
    List* tmp = NULL;
    //������� ������ �������. ���� ����� �� ������� ������, �� ������� �� �����,
    //������ ������������� �� �����, ��������� ������� � �����
    while (i < n && head->next) {
        head = head->next;
        i++;
    }
    tmp = (List*)malloc(sizeof(List));
    tmp->c = val;
    //���� ��� �� ��������� �������, �� next ������������ �� ��������� ����
    if (head->next) {
        tmp->next = head->next;
        //����� �� NULL
    }
    else {
        tmp->next = NULL;
    }
    head->next = tmp;
}

List* getNth(List* head, int n) {
    int counter = 0;
    while (counter < n && head) {
        head = head->next;
        counter++;
    }
    return head;
}

int deleteNth(List** head, int n) {
    if (n == 0) {
        return pop(head);
    }
    else {
        List* prev = getNth(*head, n - 1);
        List* elm = prev->next;
        int val = elm->c;

        prev->next = elm->next;
        free(elm);
        return val;
    }
}


void deleteList(List** head) {
    List* prev = NULL;
    while ((*head)->next) {
        prev = (*head);
        (*head) = (*head)->next;
        free(prev);
    }
    free(*head);
}


