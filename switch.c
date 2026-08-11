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
void linear(int a[], int n, int ele){
    int i,x=0;
    for(i=0;i<n;i++){
        if(a[i]==ele)
        {
            x=1;
        }
        break;        
    }
    if(x==0)
        printf("Element not found\n");
}
int binary_search(int a[], int ele, int low, int high){
    int mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(a[mid]==ele)
            return mid;
        else if(a[mid]<ele)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}
int binary_search1(int a[], int ele, int low, int high){
    int mid;
    if(high>=low){
        mid=low+(high-low)/2;
        if(a[mid]==ele)
            return mid;
            if(a[mid]<ele)
                return binary_search1(a,ele,mid+1,high);
            else
                return binary_search1(a,ele,low,mid-1);
    }
    return -1;

}
int main(){
    int choice;
    printf("Enter your choice (1-6): ");
    scanf("%d",&choice);
     int a[10],i,n,ele,pos;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    switch(choice){
        case 1:
            // code for insert.
            printf("Enter the position where you want to insert the element: ");
    scanf("%d",&pos);
    printf("Enter the element to be inserted: ");
    scanf("%d",&ele);
    insert(a,n,pos,ele);
            break;
        case 2:
            // code for delete.
            printf("Enter the position of the element to be deleted: ");
    scanf("%d",&pos);
    delete(a,n,pos);
            break;
        case 3:
            //code for linear search.
             printf("Enter the element to be searched: ");
    scanf("%d",&ele);
    linear(a,n,ele);
            break;
        case 4:
            // code for binary search(iterative).
             printf("Enter the element to be searched: ");
    scanf("%d",&ele);
    pos=binary_search(a,ele,0,n-1);
    if(pos==-1)
        printf("Element not found\n");
    else
        printf("Element found at position: %d\n",pos);
            break;
        case 5:
            // code for binary search(recursive).
            printf("Enter the element to be searched: ");
    scanf("%d",&ele);
    pos=binary_search1(a,ele,0,n-1);
    if(pos==-1)
        printf("Element not found\n");
    else
        printf("Element found at position: %d\n",pos);
            break;
        case 6:
            // code for displaying the array.
            printf("Array elements are: ");
            for(i=0;i<n;i++)
            {
                printf("%d ",a[i]);
            }
            printf("\n");
        default:
            printf("Invalid choice\n");
    }
    return 0;
}