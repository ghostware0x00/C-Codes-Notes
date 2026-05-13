#include<stdio.h>
int main(){
    int a,b;
    printf("Enter 2 numbers : \n");
    scanf("%d",&a);
    scanf("%d",&b);
    int sum = a + b;
    printf("%d + %d = %d",a,b,sum);
    return 0;
}