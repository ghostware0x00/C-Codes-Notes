//Check Whether a Number Can Be Express as Sum of Two Prime Numbers
#include<stdio.h>
int isPrime(int num){
    if(num <=0 || num == 1)
        return 0;
    for(int i=2; i<num; i++){
        if(num%i == 0){
            return 0;
        }
    }
    return num;
}

void check_prime_combo(int number){
    printf("Prime Combinations are :\n");
    for(int i=2; i<number-1; i++){
        if(isPrime(i)!=0 && isPrime(number-i)!=0)
            printf("%d + %d\n",i,number-i);
    }
}

void input(){
    int number;
    printf("Enter the number : ");
    scanf("%d",&number);
    check_prime_combo(number);
}

int main(){
    input();
    return 0;
}