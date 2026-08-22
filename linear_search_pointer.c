#include<stdio.h>
void linear(int a[], int n, int ele){
    int i,x=0;
    for(i=0;i<n;i++){
        if(*(a + i)==ele)
        {
            printf("Element found at position: %d\n",i+1);
            printf("Element found at index: %d\n",i);
            x=1;
            break; 

        }
               
    }
    if(x==0)
        printf("Element not found\n");
}
int main(){
    int a[10],i,n,ele,pos;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d",&ele);
    linear(a,n,ele);
}