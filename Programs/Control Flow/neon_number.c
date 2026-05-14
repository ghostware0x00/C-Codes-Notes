#include<stdio.h>
int main(){
    int a;
    printf("Enter the number : ");
    scanf("%d",&a);
    int sq = a*a;
    int sum=0;
    while(sq > 0){
        sum = sum + (sq%10);
        sq = sq/10;
    }
    if(a == sum)
        printf("Neon Number");
    else
        printf("Not Neon Number");
    return 0;
}