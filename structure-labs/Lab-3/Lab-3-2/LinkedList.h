#pragma once

typedef struct _Node {
    void* symbol;
    struct _Node* next;
    struct _Node* prev;
} Node; 


typedef struct _DblLinkedList {
    size_t size;
    Node* head;
    Node* tail;
} DblLinkedList;


DblLinkedList* createDblLinkedList() {
    DblLinkedList* tmp = (DblLinkedList*)malloc(sizeof(DblLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;

    return tmp;
}


void deleteDblLinkedList(DblLinkedList** list) {
    Node* tmp = (*list)->head;
    Node* next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
}


void pushFront(DblLinkedList* list, void* data) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(1);
    }
    tmp->symbol = data;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;

    if (list->tail == NULL) {
        list->tail = tmp;
    }
    list->size++;
}

void pushBack(DblLinkedList* list, void* symbol) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    if (tmp == NULL) {
        exit(3);
    }
    tmp->symbol = symbol;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;

    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
}

void* popFront(DblLinkedList* list) {
    Node* prev;
    void* tmp;
    if (list->head == NULL) {
        exit(2);
    }

    prev = list->head;
    list->head = list->head->next;
    if (list->head) {
        list->head->prev = NULL;
    }
    if (prev == list->tail) {
        list->tail = NULL;
    }
    tmp = prev->symbol;
    free(prev);

    list->size--;
    return tmp;
}


Node* getNth(DblLinkedList* list, size_t index) {
    Node* tmp = list->head;
    size_t i = 0;

    while (tmp && i < index) {
        tmp = tmp->next;
        i++;
    }

    return tmp;
}



void insert(DblLinkedList* list, size_t index, void* symbol) {
    Node* elm = NULL;
    Node* ins = NULL;
    elm = getNth(list, index);
    if (elm == NULL) {
        exit(5);
    }
    ins = (Node*)malloc(sizeof(Node));
    ins->symbol = symbol;
    ins->prev = elm;
    ins->next = elm->next;
    if (elm->next) {
        elm->next->prev = ins;
    }
    elm->next = ins;

    if (!elm->prev) {
        list->head = elm;
    }
    if (!elm->next) {
        list->tail = elm;
    }

    list->size++;
}

void* deleteNth(DblLinkedList* list, size_t index) {
    Node* elm = NULL;
    void* tmp = NULL;
    elm = getNth(list, index);
    if (elm == NULL) {
        exit(5);
    }
    if (elm->prev) {
        elm->prev->next = elm->next;
    }
    if (elm->next) {
        elm->next->prev = elm->prev;
    }
    tmp = elm->symbol;

    if (!elm->prev) {
        list->head = elm->next;
    }
    if (!elm->next) {
        list->tail = elm->prev;
    }

    free(elm);

    list->size--;

    return tmp;
}



void printLinkedList(DblLinkedList* list, void (*fun)(void*)) {
    Node* tmp = list->head;
    while (tmp) {
        fun(tmp->symbol);
        tmp = tmp->next;
    }
    printf("\n");
}


DblLinkedList* fromArray(void* arr, size_t n, size_t size) {
    DblLinkedList* tmp = NULL;
    size_t i = 0;
    if (arr == NULL) {
        exit(7);
    }

    tmp = createDblLinkedList();
    while (i < n) {
        pushBack(tmp, ((char*)arr + i * size));
        i++;
    }

    return tmp;
}