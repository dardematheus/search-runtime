#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

const char *algorithm_menu =
    "Which algorithm do you want to test out?\n"
    "1 - Binary Search\n"
    "2 - Exponential Search\n"
    "3 - N Search\n";

const char *target_menu = 
    "Which number do you want to find?";

const char *size_menu =
    "\nWhich array size?\n"
    "1 - 10\n"
    "2 - 50\n"
    "3 - 100\n";

int binary_search(int target, int arr[], int left, int right){
    if(!left){
        left = 0;
    }
    if(!right){
        right = sizeof(arr) / sizeof(arr[left]) - 1;
    }

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
    return 0;
}

int exponential_search(int target){
    int arr[50] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
        21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
        31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
        41, 42, 43, 44, 45, 46, 47, 48, 49, 50
    };

    int left = 0;
    int index = 0;
    int right = sizeof(arr) / sizeof(arr[left]) - 1;

    while(target > arr[index]){
        if (index == 0){
            index++;
            left = index;
            index *= 2;
        }
        left = index;
        index *= 2;
    }
    right = index;
    return binary_search(target, arr, left, right);
}

int n_search(int target, int arr[]){
    int size = sizeof(arr) - 1;
    for(int i = 0; i < size; i++){
        if (arr[i] == target){
            return i;
        }
    }
    return 0;
}

int arr_allocation(int size){
    return 0;
}

void main(){
    int choice;
    int target;
    int arraysize;

    printf("%s", algorithm_menu);
    scanf("%d", &choice);

    printf("%s", target_menu);
    scanf("%d", &target);

    printf("%s", size_menu);
    scanf("%d", &arraysize);

    int pos = exponential_search(target);
    printf("Number %d found at position %d", target, pos);
}