#include<stdio.h>
int main(){
    int l,b,p=0,a=0;
    printf("Enter length : ");
    scanf("%d",&l);
    printf("Enter breadth : ");
    scanf("%d",&b);
    a = l*b;
    p = 2*(l+b);
    printf("Area of Rectangle = %d\n",a);
    printf("Perimeter of Rectangle = %d\n",p);
    return 0;
}