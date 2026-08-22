#include<stdio.h>
void traverse(int a[], int n){
    printf("Traversing the array:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(a + i));
    }
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
    traverse(a,n);
}