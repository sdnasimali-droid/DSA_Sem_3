#include<stdio.h>
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
    }
}
void insertionSort(int array[],int size){
    for(int step=1;step<size;step++){
        int key= array[step];
        int j=step-1;
        while(j>=0 && key<array[j]){
            array[j+1]=array[j];
            --j;
        }
        array[j+1]= key;
        }
    }
    void sort(int arr[], int p, int q, int r) {
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
int main() {
    int merge[16]; // Adjust size as needed
    int data[] = {4,7,1,9,8,5,2,3};
    int array[]={6, 4, 7, 8, 1, 9, 5};
    int size = sizeof(data) / sizeof(data[0]);
    int n=sizeof(array)/sizeof(array[0]);
    selectionSort(data, size);
    insertionSort(array,n);
    printf("\n1st Sorted array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d  ", data[i]);
    }
    printf("\n2nd Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d  ", array[i]);
    }
     for (int i = 0; i < size; i++) {
        merge[i]=data[i];
     }
     for (int i = 0; i < n; i++) {
        merge[size+i]=array[i];
     }
     printf("\nMerged array: \n");
     for (int i = 0; i < size+n; i++) {
        printf("%d  ", merge[i]);
     }
     int mid=(size+n)/2;
     sort(merge, 0, mid, size+n);
    printf("\nMerged Sorted array: \n");
    for (int i = 0; i < size+n; i++) {
        printf("%d  ", merge[i]);
    }

    printf("\n");
    return 0;
}