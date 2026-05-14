#include<stdio.h>
int main(){
    int number,power,result=1;
    printf("Enter the number : ");
    scanf("%d",&number);
    printf("Enter the power : ");
    scanf("%d",&power);
    for(int i=1; i<=power; i++){
        result = result * number;
    }
    printf("%d",result);
}