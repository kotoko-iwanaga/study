/*12. Дана строка символов. Группы символов, разделенные пробелами (одним или
несколькими) и не содержащие пробелов внутри себя, будем называть словами.
Преобразовать строку, удвоив в ней самое короткое слово.*/

#include <stdio.h>
#include <string.h>

void setMinWord(int& temp, int& min, int& pos, int& temp_pos) {
    if (temp != 0) {
        pos = min >= temp ? temp_pos : pos;
        min = min >= temp ? temp : min;
    }
    temp = 0;
}

void findMinWord(char string[], int length, int& min, int& pos) {
    int temp_min_word = 0;
    for (int i = 0; i <= length; i++) { // находим длину наименьшего слова
        switch (string[i]) {
        case '\n':
            string[i] = '\0';
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

int main() {
    const int str_size = 100; // размер массива
    char str[str_size] = { 0 }; // сам массив символов
    int min_word = str_size + 1; // длина мин слова
    int min_word_pos = 0; // последний символ наикороткого слова
    // ввод в массив
    fgets(str,str_size,stdin);
    // поиск длины мин слова
    findMinWord(str, strlen(str), min_word, min_word_pos);
    // обработка строки
    moveChar(str, strlen(str), min_word, min_word_pos);
    // вывод результата
    printf("%s\n", str);

}



/*printf("Minimum length: %d\n", min_word);
    printf("End position: %d\n", min_word_pos - 1);
    printf("Length of string: %d\n", (int)strlen(str));*/