#include<stdio.h>
void delete(int a[], int n, int pos){
    int i;
    for(i=pos;i<n-1;i++)
    {
        a[i]=a[i+1];
    }
    n--;
    printf("Array after deletion: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}
int main(){
    int a[10],i,n,pos;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the position of the element to be deleted: ");
    scanf("%d",&pos);
    delete(a,n,pos);
}