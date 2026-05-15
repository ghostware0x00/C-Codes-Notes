#include<stdio.h>

int ret_power(int num, int pow){
    if(pow == 1)
        return num;
    else
        return num*ret_power(num, pow-1);
}

int main(){
    int num,power;
    printf("Enter the number : ");
    scanf("%d",&num);
    printf("Enter the power : ");
    scanf("%d",&power);
    printf("Result = %d",ret_power(num, power));
    return 0;
}