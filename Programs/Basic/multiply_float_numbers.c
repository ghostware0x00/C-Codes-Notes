#include<stdio.h>
int main(){
    float a,b;
    printf("Enter values of a and b : \n");
    scanf("%f",&a);
    scanf("%f",&b);
    float mul = a*b;
    printf("%fx%f = %f",a,b,mul);
    return 0;
}