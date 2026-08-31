#include <stdio.h>
void selectionSort(int array[], int size) {
    for (int step = 0; step < size - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < size; i++) {
            if (array[i] < array[min_idx]) {
                min_idx = i;
            }
        }
        int temp = array[min_idx];
        array[min_idx] = array[step];
        array[step] = temp;
        
        printf("\ninternal array: \n");
        for (int i = 0; i < size; i++) {
            printf("%d  ", array[i]);
        }
    }
}
int main() {
    int data[] = {6, 4, 7, 8, 1, 9, 5};
    int size = sizeof(data) / sizeof(data[0]);
    selectionSort(data, size);
    printf("\nSorted array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d  ", data[i]);
    }
}