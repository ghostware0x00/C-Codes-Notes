#include<stdio.h>
int main(){
    int a;
    printf("Enter the number : ");
    scanf("%d",&a);
    int copy=a,count=0;
    while(copy > 0){
        count++;
        copy = copy/10;
    }
    int arms=0,rem=0,remSum;
    copy = a;
    while(copy > 0){
        rem = copy%10;
        remSum=1;
        for(int i=1; i<=count; i++)
            remSum = remSum * rem;
        arms = arms + remSum;
        copy = copy/10;
    }
    if(a == arms)
        printf("Armstrong Number");
    else
        printf("Not Armstrong Number");
    return 0;
}