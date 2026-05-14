#include<stdio.h>
int main(){
    int a,b,hcf,lcm;
    printf("Enter number1 : ");
    scanf("%d",&a);
    printf("Enter number2 : ");
    scanf("%d",&b);
    for(int i=1; i<=a; i++){
        if(a%i == 0 && b%i == 0)
            hcf=i;
    }
    lcm = (a*b)/hcf;
    printf("LCM of %d and %d = %d",a,b,lcm);
    return 0;
}