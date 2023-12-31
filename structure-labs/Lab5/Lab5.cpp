﻿#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void swap_elements(int*, int*);
void println_array(const int[], size_t);
void println_array_with_pointers(const int[], size_t, const int* const, const int* const);
int* copy_array(const int[], size_t);
bool isSorted(int[], size_t);
int* bubbleSort(const int[], const size_t);
int* shakerSort(const int[], size_t);
int partititate_array(int[], size_t, size_t, size_t);
void input(const int[], const int);


void main() {
    int len = 0;
    printf("Please write size of an array: ");
    scanf("%d", &len);
    int* arr = (int*) calloc(sizeof(int), len);
    bool active = true;

    input(arr, len);
    do {
        printf("Choose your type of sort\n");
        printf("1) bubble sorting\n");
        printf("2) shaker sorting\n");
        printf("3) input\n");
        printf("4) exit\n");
        char choice = _getch();
        switch (choice) {
        case '1':
            printf("This is bubble sorting\n");
            bubbleSort(arr, len);
            break;
        case '2':
            printf("This is shaker sorting\n");
            shakerSort(arr, len);
            break;
        case '3':
            input(arr, len);
            break;
        case '4':
            active = false;
            break;
        default:
            printf("Wrong selection. Try again\n");

        }
    } while (active == true);
}

void input(const int arr[], const int len) {
    printf("Please write elements of array\n");
    for(int i = 0; i < len; i++)
        scanf("%d", &arr[i]);
}

void swap_elements(int* first, int* second) {
    int tmp = *first;
    *first = *second;
    *second = tmp;
}

void println_array(const int arr[], size_t len) {
    for (int i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void println_array_with_pointers(const int arr[],
    size_t len,
    const int* const p1,
    const int* const p2) {
    for (int i = 0; i < len; i++) {
        if (&arr[i] == p1 || &arr[i] == p2)
            printf("[%d]\t", arr[i]);
        else
            printf("%d\t", arr[i]);
    }
    printf("\n");
}

int* copy_array(const int src_arr[], size_t len) {
    int* copiedArray = (int*)calloc(sizeof(int), len);
    memcpy(copiedArray, src_arr, sizeof(int) * len);
    return copiedArray;
}

bool isSorted(int arr[], size_t len) {
    bool isSorted = true;
    for (int i = 0; i < len - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            isSorted = false;
            break;
        }
    }
    return isSorted;
}

int* bubbleSort(const int src_arr[], const size_t len) {
    int* arr = copy_array(src_arr, len);
    println_array(arr, len);

    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            println_array_with_pointers(arr, len, &arr[j], &arr[j + 1]);
            if (arr[j] > arr[j + 1]) {
                swap_elements(&arr[j], &arr[j + 1]);
            }
        }
    }

    println_array(arr, len);

    return arr;
}

int* shakerSort(const int src_arr[], size_t len) {
    int* arr = copy_array(src_arr, len);
    println_array(arr, len);

    for (int i = 0; i < len / 2; i++) {
        bool is_swapped = false;
        for (int j = i; j < len - i - 1; j++) {
            println_array_with_pointers(arr, len, &arr[j], &arr[j + 1]);
            if (arr[j] > arr[j + 1]) {
                swap_elements(&arr[j], &arr[j + 1]);
                is_swapped = true;
            }
        }

        for (int j = len - i - 2; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                swap_elements(&arr[j], &arr[j - 1]);
                is_swapped = true;
            }
            println_array_with_pointers(arr, len, &arr[j], &arr[j - 1]);
        }

        if (!is_swapped)
            break;
    }

    println_array(arr, len);
    return arr;
}

int partititate_array(int arr[], size_t len, size_t low, size_t high) {
    size_t pivot_index = high;
    int pivot_value = arr[pivot_index];

    size_t new_pivot_index = low;
    for (int i = low; i <= high; i++) {
        println_array_with_pointers(arr, len, &arr[low], &arr[i]);
        if (arr[i] < pivot_value) {
            swap_elements(&arr[low], &arr[i]);
            new_pivot_index++;
        }
    } 
    println_array_with_pointers(arr, len, &arr[new_pivot_index], &arr[high]);
    swap_elements(&arr[new_pivot_index], &arr[high]);
    return new_pivot_index;
}
