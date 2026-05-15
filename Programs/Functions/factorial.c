#include<stdio.h>

int factorial(int num){
    if(num == 0 || num == 1)
        return 1;
    else
        return num * factorial(num - 1);
}

int main(){
    int n;
    printf("Enter the number to find factorial of : ");
    scanf("%d",&n);
    if(n < 0)
        printf("Factorial value cannot be negative\n");
    else
        printf("Factorial of %d = %d",n,factorial(n));
    return 0;
}