#include<stdio.h>
int main(){
    int a;
    printf("Enter a number : ");
    scanf("%d",&a);
    int rev=0;
    while(a > 0){
        rev = (rev*10) + (a%10);
        a = a/10;
    }
    printf("Reverse Number = %d\n",rev);
    return 0;
}