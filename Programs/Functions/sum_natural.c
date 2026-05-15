#include<stdio.h>
int sum_natural(int num){
    if(num == 0)
        return 0;
    else
        return num+sum_natural(num-1);
}
int main(){
    int a;
    printf("Enter the natural number you want to calculate sum of : ");
    scanf("%d",&a);
    printf("%d",sum_natural(a));
    return 0;
}