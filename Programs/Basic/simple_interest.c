#include<stdio.h>
int main(){
    float p_amt, rate, time, si=0;
    printf("Enter principal : ");
    scanf("%f",&p_amt);
    printf("Enter rate percent : ");
    scanf("%f",&rate);
    printf("Enter time : ");
    scanf("%f",&time);
    si = (p_amt * rate * time)/100;
    printf("Simple Interest = %f",si);
    return 0;
}