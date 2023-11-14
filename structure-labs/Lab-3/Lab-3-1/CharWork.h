#pragma once
void setMinWord(int& temp, int& min, int& pos, int& temp_pos) {
    if (temp != 0) {
        pos = min >= temp ? temp_pos : pos;
        min = min >= temp ? temp : min;
    }
    temp = 0;
}

void getString(char string[]) {
    char character = '\0';
    for (int i = 0; (character = getchar()) != '\n'; i++)  // считывание строки
        string[i] = character;
}

void findMinWord(char string[], int length, int& min, int& pos) {
    int temp_min_word = 0;
    for (int i = 0; i <= length; i++) { // находим длину наименьшего слова
        switch (string[i]) {
        case '\0':
        case ' ':
            setMinWord(temp_min_word, min, pos, i);
            break;
        default:
            temp_min_word++;
        }
    }
}

void moveChar(char string[], int length, int& min, int& pos) {
    for (int i = length + min; i > pos - 1; i--) {
        string[i] = string[i - min];
    }
}

void handle_error(char* string) {
    if (string == NULL) {
        printf("Error");
        exit(1);
    }
}
char* get_string_by_malloc(FILE* stream) {
    char* string = NULL;
    int i = 0;
    string = (char*)malloc(sizeof(char));
    handle_error(string);

    char c = 0;
    while ((c = getc(stream)) != '\n') {
        if (c == EOF)
            break;
        char* tmp = NULL;
        tmp = (char*)malloc((strlen(string) + 1) * sizeof(char)); // создаем массив на +1 ячейку больше
        handle_error(string);

        strcpy(tmp, string); // копируем темп в стринг
        free(string);
        string = (char*)malloc((strlen(string) + 1) * sizeof(char)); // увеличиваем массив на 1
        handle_error(string);

        strcpy(string, tmp); // даем временные данные в исходный массив
        string[i] = c;
        i++;
        free(tmp);
    }
    string[i] = '\0';
    return string;
}