#include<stdio.h>
typedef struct complexNumber{
    int real;
    int imaginary;
}complex;
int main(){
    complex a,b,sum;
    printf("Enter complex number 1\n");
    printf("Enter the real part : ");
    scanf("%d",&a.real);
    printf("Enter the imaginary part : ");
    scanf("%d",&a.imaginary);
    printf("Enter complex number 2\n");
    printf("Enter the real part : ");
    scanf("%d",&b.real);
    printf("Enter the imaginary part : ");
    scanf("%d",&b.imaginary);
    sum.real = a.real + b.real;
    sum.imaginary = a.imaginary + b.imaginary;
    printf("(%d+%di) + (%d+%di) = %d+%di",a.real,a.imaginary,b.real,b.imaginary,sum.real,sum.imaginary);
    return 0;
}