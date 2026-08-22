#include<stdio.h>
int main(){
    int a=10,b=20;
    int *p1,*p2;
    p1=&a;
    p2=&b;
    printf("Value of a=%d\n",*p1);
    printf("Value of b=%d\n",*p2);
    printf("Address of a=%p\n",&a);
    printf("Address of b=%p\n",&b);
    printf("Address of a=%p\n",p1);
    printf("Address of b=%p\n",p2);
    printf("Address of p1=%p\n",&p1);
    printf("Address of p2=%p\n",&p2);
    printf("Value of p1=%p\n",p1);
    printf("Value of p2=%p\n",p2);

    return 0;

}