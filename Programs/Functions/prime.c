#include<stdio.h>
void isPrime(int num){
    int count=0;
    for(int i=2; i<num; i++){
        if(num%i == 0){
            count++;
            break;
        }
    }
    if(count == 0)
        printf("Prime Number");
    else
        printf("Not Prime Number");
}
int main(){
    int a;
    printf("Enter the number : ");
    scanf("%d",&a);
    isPrime(a);
    return 0;
}