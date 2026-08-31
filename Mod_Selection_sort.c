#include <stdio.h>
void modifiedSelectionSort(int arr[], int start, int end) {
    while (start < end) {
        int min_idx = start;
        int max_idx = start;
        for (int i = start; i <= end; i++) {
            if (arr[i] < arr[min_idx]) {
                min_idx = i;
            }
            if (arr[i] > arr[max_idx]) {
                max_idx = i;
            }
        }
        int temp1 = arr[start];
        arr[start] = arr[min_idx];
        arr[min_idx] = temp1;
        if (max_idx == start) {
            max_idx = min_idx;
        }
        int temp2 = arr[end];
        arr[end] = arr[max_idx];
        arr[max_idx] = temp2;
        start++;
        end--;
    }
}

int main() {
    int data[] = {6, 4, 7, 8, 1, 9, 5};
    int size = sizeof(data) / sizeof(data[0]);
    modifiedSelectionSort(data, 0, size - 1);
    printf("\nSorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    return 0;
}