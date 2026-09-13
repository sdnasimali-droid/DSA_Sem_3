#include<stdio.h>
int partition(int arr[],int low,int high){
    int pivot = arr[high];
    int i = (low - 1);
    for(int j = low;j <high;j++){
        if(arr[j] <= pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}
void quickSort(int arr[],int low,int high){
    if(low < high){
        int pi = partition(arr,low,high);
        quickSort(arr,low,pi - 1);
        quickSort(arr,pi + 1,high);
    }
}void bubbleSort( int array[], int size){
    for (int step=0;step<size;step++){
        for (int i=0;i<size-step-1;i++){
            if (array[i] > array[i+1]){
                int temp= array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
        printf("\nInternal array: \n");
        for (int i = 0; i < size; i++) {
            printf("%d  ", array[i]);
        }
        
        quickSort(array,0,size-1);
        break;
    }
}
int main(){
    int data[]={4,7,1,9,8,5.2,3};
    int size = sizeof(data)/sizeof(data[0]);
    bubbleSort(data,size);
    printf("\nSorted array :\n");
    for(int i=0;i<size;i++){
        printf("%d  ",data[i]);
    }
    return 0;
}