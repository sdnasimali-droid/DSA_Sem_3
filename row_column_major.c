#include<stdio.h>
void Row_Major(int B,int LR,int LC,int i,int j,int W,int N){
    int address;
    address=B+W*((i-LR)*N+(j-LC));
    printf("Address of element [%d][%d] in Row Major Order is: %d\n",i,j,address);
}
void Column_Major(int B,int LR,int LC,int i,int j,int W,int M){
    int address;
    address=B+W*((j-LC)*M+(i-LR));
    printf("Address of element [%d][%d] in Column Major Order is: %d\n",i,j,address);
}
int main(){
    int a[10][10],i,j,r,c,x,y,B,LR,LC,W;
    int choice;
    printf("Enter the number of rows and columns of the array(Maximum 10): ");
    scanf("%d %d",&r,&c);
    printf("Enter the elements of the array:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("Element [%d][%d]: ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter 1 for Row Major and 2 for Column Major: ");
    scanf("%d",&choice);
    printf("Enter the row and column number to calculate the address of the element: ");
    scanf("%d %d",&x,&y);
    printf("Enter the base address of the array: ");
    scanf("%d",&B);
    printf("Enter LR and LC Values:");
    scanf("%d %d",&LR,&LC);
    W=sizeof(int);
    switch(choice){
        case 1:
            Row_Major(B,LR,LC,x,y,W,c);
            break;
        case 2:
            Column_Major(B,LR,LC,x,y,W,r);
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}