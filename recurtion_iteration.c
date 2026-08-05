#include<stdio.h>
int Rec(int n){
    if(n==0||n==1){
        return 1;
    }
    int x;
    x=n*Rec(n-1);
    return x;
}
int Iter(int n){
    int x=1;
    for(int i=1;i<=n;i++){
        x*=i;
    }
    return x;
}
int main(){
    int a;
    printf("Which Number Factorial you want to Calculate:");
    scanf("%d",&a);
    printf("Factorial=%d",Rec(a));
    printf("Factorial=%d",Iter(a));

}