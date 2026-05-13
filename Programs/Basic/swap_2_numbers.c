#include<stdio.h>
int main(){
    int a,b;
    printf("Enter 2 numbers : \n");
    scanf("%d",&a);
    scanf("%d",&b);
    printf("a = %d\tb = %d\n",a,b);
    int swap = 0;
    swap = a;
    a = b;
    b = swap;
    printf("a = %d\tb = %d\n",a,b);
    return 0;
}