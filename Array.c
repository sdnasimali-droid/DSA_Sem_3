#include<stdio.h>
int main(){
    int n,x,i,j,r,c,y,z;
    int a[10];
    int b[10][10];
    //For 1-D Array 
    printf("Enter 1-D Array Element Number:");
    scanf("%d",&n);
    printf("Enter 1-D Array Elements:\n");
    for(i=0;i<n;i++){
        printf("'%d' Element is: ",(i+1));
        scanf("%d",&a[i]);
    }
    printf("Enter the 1-D Array Position to Access:");
    scanf("%d",&x);
    for(i=0;i<=n;i++){
        if(i==x){
            printf("The '%d' no Element is %d\n",x,a[i-1]);
        }
    }
    printf("1-D Array Elements:\n");
    for(i=0;i<n;i++){
        printf("'%d' Element is %d \n",(i+1),a[i]);
    }
    //For 2-D Array
    printf("Enter 2-D Array Row & Column No:");
    scanf("%d %d", &r,&c);
    printf("Enter 2-D Array Elements:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("Element [%d][%d]:", (i+1), (j+1));
            scanf("%d",&b[i][j]);
        }
    }
    printf("Enter the 2-D Array Row & Column Position to Access:");
    scanf("%d %d",&y,&z);
    printf("The '%d' Row & '%d' Column Element is %d\n",y,z,b[y-1][z-1]);
    printf("2-D Array Elements:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("Element [%d][%d]: %d\n", (i+1), (j+1),b[i][j]);
        }
    }
}