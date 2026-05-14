#include<stdio.h>
int main(){
    int a;
    printf("Enter a number : ");
    scanf("%d",&a);
    if(a == 0)
        printf("zero");
    else if(a < 0)
        printf("negative");
    else
        printf("positive");
    return 0;
}