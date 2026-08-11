#include<stdio.h>
int binary_search(int a[], int ele, int low, int high){
    int mid;
    if(high>=low){
        mid=low+(high-low)/2;
        if(a[mid]==ele)
            return mid;
            if(a[mid]<ele)
                return binary_search(a,ele,mid+1,high);
            else
                return binary_search(a,ele,low,mid-1);
    }
    return -1;

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
    pos=binary_search(a,ele,0,n-1);
    if(pos==-1)
        printf("Element not found\n");
    else
        printf("Element found at position: %d\n",pos);
}