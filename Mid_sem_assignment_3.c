#include <stdio.h>
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
        if (L[i] >= R[j]) {
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
void bubbleSort(int arr[], int Size){
    for(int i=0; i<Size-1; i++){
        for(int j=0; j<Size-i-1; j++){
            if(arr[j] < arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int size){
    for(int i=1; i<size; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && key<arr[j]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int mid_find(int arr[], int low, int high, int target){
    int mid = low + (high-low)/2;
    if(target == arr[mid]){
        bubbleSort(arr, mid);
        mergeSort(arr, mid+1, high);
        return mid;
    }
    else{
        arr[mid] = target;
        insertionSort(arr, high+1);
        return mid;
    }
}


int main(){
    int arr[] = {2,4,6,8,10,12,14,16,18};
    int Size = sizeof(arr)/sizeof(*arr);
    int target ;
    printf("Enter the target element: ");
    scanf("%d", &target);
    int mid = mid_find(arr, 0, Size-1, target);

    printf("Middle Index : %d", mid);
    printf("\n");
    for(int i=0; i<Size; i++){
        printf("%d ", arr[i]);
    }
}