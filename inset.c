#include<stdio.h>
void insert(int a[], int n, int pos, int ele){
    int i;
    for(i=n;i>pos;i--){
        a[i]=a[i-1];
    }
    a[pos]=ele;
    n++;
    printf("Array after insertion: ");
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    int a[10],i,n,pos,ele;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the position where you want to insert the element: ");
    scanf("%d",&pos);
    printf("Enter the element to be inserted: ");
    scanf("%d",&ele);
    insert(a,n,pos,ele);
}
