#include<stdio.h>
void merge(int arr[], int p, int q, int r) {
    int i, j, k;
    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[q + 1 + j];

    i = 0;
    j = 0;
    k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
int main() {
    int data[] = { 12, 11, 13, 5, 6, 7 };
    int size = sizeof(data) / sizeof(data[0]);
    mergeSort(data, 0, size - 1);
    printf("Sorted array: \n");
    for (int i = 0; i < size; i++)
        printf("%d ", data[i]);
    return 0;
}