#include<stdio.h>
int main(){
    int a,b,c;
    printf("Enter number1 : ");
    scanf("%d",&a);
    printf("Enter number2 : ");
    scanf("%d",&b);
    printf("Enter number3 : ");
    scanf("%d",&c);
    if(a!=b && b!=c && a!=c){    
        if(a > b && a > c)
            printf("%d is the largest number",a);
        else if(b > a && b > c)
            printf("%d is the largest number",b);
        else
            printf("%d is the largest number",c);
    }
    else
        printf("values of a b c cannot be equal");
    return 0;
}