#include<stdio.h>
#include<math.h>
int main(){
    float p_amt, rate, time, ci=0;
    printf("Enter principal : ");
    scanf("%f",&p_amt);
    printf("Enter rate percent : ");
    scanf("%f",&rate);
    printf("Enter time : ");
    scanf("%f",&time);
    ci = (p_amt * pow((1 + (rate/100)),time))-p_amt;
    printf("compound interest = %f",ci);
    return 0;
}