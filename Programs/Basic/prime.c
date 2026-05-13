#include<stdio.h>
int main(){
    int num;
    int count=0;
    printf("Enter the number : ");
    scanf("%d",&num);
    if(num == 1 || num <= 0){
        printf("Not Prime Number");
        return 0;
    }
    for(int i=2; i<num; i++){
        if(num%i == 0){
            count++;
            break;
        }
    }
    if(count != 0)
        printf("Not Prime Number");
    else
        printf("Prime number");
    return 0;
}