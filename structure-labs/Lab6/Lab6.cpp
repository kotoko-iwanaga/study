#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale>

void mergeElements(int[], int, int, int);
void mergeSorting(int[], int, int);


int main() {
    setlocale(0, "");
    FILE* inputFile, * outputFile;
    inputFile = fopen("input.txt", "r");
    outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        fprintf(stderr, "Open file error\n");
        exit(0);
    }

    int n;
    fscanf(inputFile, "%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        fscanf(inputFile, "%d", &arr[i]);
    }

    mergeSorting(arr, 0, n - 1);

    fprintf(outputFile, "%d ",n);
    for (int i = 0; i < n; i++) {
        fprintf(outputFile, "%d ", arr[i]);
    }

    free(arr);
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}


void mergeElements(int arr[], int index1, int index2, int index3) {
    int i, j, k;
    int n1 = index2 - index1 + 1;
    int n2 = index3 - index2;

    int* first = (int*)malloc(n1 * sizeof(int));
    int* second = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        first[i] = arr[index1 + i];
    for (j = 0; j < n2; j++)
        second[j] = arr[index2 + 1 + j];

    i = 0;
    j = 0;
    k = index1;

    while (i < n1 && j < n2) {
        if (first[i] <= second[j]) {
            arr[k] = first[i];
            i++;
        }
        else {
            arr[k] = second[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = first[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = second[j];
        j++;
        k++;
    }

    free(first);
    free(second);
}

void mergeSorting(int arr[], int index1, int index2) {
    if (index1 < index2) {
        int m = index1 + (index2 - index1) / 2;

        mergeSorting(arr, index1, m);
        mergeSorting(arr, m + 1, index2);

        mergeElements(arr, index1, m, index2);

        printf("Merge result: ");
        for (int i = index1; i <= index2; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}