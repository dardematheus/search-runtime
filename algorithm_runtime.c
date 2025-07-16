#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

const char *algorithm_menu =
    "Which algorithm do you want to test out?\n"
    "1 - Binary Search\n"
    "2 - Exponential Search\n"
    "3 - N Search\n";

int* bubble_sort(int arr[], int size){
    int aux;
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1 - i; j++){
            if(arr[j] > arr[j + 1]){
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
            }
        }
    }
    return arr;
}


int binary_search(int target, int arr[], int left, int right){
    bool found = false;
    int index = right / 2;

    while(!found){
        if(arr[index] > target){
            right = index;
            index = floor(right / 2);
        }
        if(arr[index] < target){
            left = index;
            index = floor((right + left) / 2);
        }
        if(arr[index] == target){
            found = true;
            return index;
        }
    }
    return -1;
}

int exponential_search(int target, int arr[], int size){
    int left = 0;
    int index = 1;
    int right = size;

    if (arr[0] == target){
        return 0;
    }

    while(index < size && target > arr[index]){
        left = index;
        index *= 2;
    }

    right = index;
    return binary_search(target, arr, left, right);
}

int n_search(int target, int arr[], int size){
    for(int i = 0; i < size; i++){
        if (arr[i] == target){
            return i;
        }
    }
    return -1;
}

int* arr_allocation(int size){
    int *arr = malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        arr[i] = rand() % size;
    }
    return arr;
}

void main(){
    int choice, target, arraysize;
    clock_t start_time, end_time;
    double cpu_time_used;

    printf("%s", algorithm_menu);
    scanf("%d", &choice);

    printf("Which number do you want to find?\n");
    scanf("%d", &target);

    printf("Which size do you want the array to be?\n");
    scanf("%d", &arraysize);
    
    int *arr = arr_allocation(arraysize);
    int *sorted = bubble_sort(arr, arraysize);

    switch(choice){
        case 1:
            start_time = clock();
            int pos = binary_search(target, sorted, 0, arraysize - 1);
            end_time = clock();
            cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
            printf("Number %d found in position %d\n", target, pos);
            printf("\nAlgorithm Execution time: %f seconds\n", cpu_time_used);
            break;
        case 2:
            start_time = clock();
            pos = exponential_search(target, sorted, arraysize);
            end_time = clock();
            cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
            printf("Number %d found in position %d\n", target, pos);
            printf("\nAlgorithm Execution time: %.10f seconds\n", cpu_time_used);
            break;
        case 3:
            start_time = clock();
            pos = n_search(target, sorted, arraysize);
            end_time = clock();
            cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
            printf("Number %d found in position %d\n", target, pos);
            printf("\nAlgorithm Execution time: %f seconds\n", cpu_time_used);
            break;
    }
    free(arr);
}