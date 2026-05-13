#include<stdio.h>
int main(){
    int fah,cel=0;
    printf("Enter fahrenheit : ");
    scanf("%d",&fah);
    cel = (5 * (fah - 32))/9;
    printf("fahrenheit = %d\tcelcius = %d\n",fah,cel);
    return 0;
}