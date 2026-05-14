#include<stdio.h>
int main(){
    int a,b,result=0;
    char operation;
    printf("Enter number1 : ");
    scanf("%d",&a);
    printf("Enter number2 : ");
    scanf("%d",&b);
    printf("Enter the operation to perform(+, -, *, /, MODULUS) : ");
    scanf(" %c",&operation);
    if(operation == '+')
        result = a+b;
    else if(operation == '-')
        result = a-b;
    else if(operation == '*')
        result = a*b;
    else if(operation == '/'){
        if(b == 0){
            printf("Denominator cannot be 0");
            return 0;
        }
        result = a/b;
    }
    else if(operation == '%')
        result = a%b;
    else{
        printf("invalid operation cannot be performed");
        return 0;
    }
    printf("%d %c %d = %d",a,operation,b,result);
    return 0;
}