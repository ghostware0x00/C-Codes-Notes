#include<stdio.h>
int main(){
    int n;
    printf("Enter the range of natural numbers to perform summation on : ");
    scanf("%d",&n);
    int sum = (n * (n+1))/2;
    printf("Sum of natural numbers till %d = %d",n,sum);
    return 0;
}