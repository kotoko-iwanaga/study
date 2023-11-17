#pragma once
typedef struct List {
	int value;
	struct List* next;
} List;



void createList(List**);
List* clearList(List*);
bool checkClean();
void goToFirst();
bool checkEnd();
void goToNext();
void getNext();
void deleteNext();
void getNextElement();
void changeNextElement();
void addNextElement();
void printList(List*);
void deleteList();

void createList(List** node) {
	size_t size = 10;
	int* arr = (int*)calloc(size, sizeof(int));
	printf("Введите 10 чисел, разделяя их пробелами: ");
	for (auto i = size; i > 0; i--)
		scanf("%d", &arr[i-1]);
	for (auto i = 0; i < size; i++) {
		List* tmp = (List*)malloc(sizeof(List));
		tmp->value = arr[i];
		tmp->next = *node;
		*node = tmp;
	}
	printf("Список успешно создан\n");

}

List* clearList(List * node) {
	node = NULL;
	return node;
}

bool checkClean() {
	return 1;
}

void goToFirst() {

}

bool checkEnd() {
	return 1;
}

void goToNext() {

}

void getNext() {

}

void deleteNext() {

}

void getNextElement() {

}

void changeNextElement() {

}

void addNextElement() {

}

void printList(List* node) {
	printf("\nСписок: ");
	while (node) {
		printf("%d ", node->value);
		node = node->next;
	}
	putchar('\n');
}

void deleteList() {

}
