#include<stdio.h>
void access(int a[], int n){
    int x;
    printf("Accessing elements of the array:\n");
    printf("Enter the index of the element to be accessed: ");
    scanf("%d",&x);
    printf("Element at index %d is: %d\n", x, *(a + x));
    printf("\n");
}
int main(){
    int a[10];
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    access(a,n);
    return 0;
}