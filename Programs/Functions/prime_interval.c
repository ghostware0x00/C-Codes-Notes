#include<stdio.h>
int isPrime(int num){
    if(num <=0 || num == 1)
        return 0;
    for(int i=2; i<num; i++){
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}

void display(int l,int u){
    printf("Prime Numbers between %d and %d\n",l,u);
    for(int i=l; i<=u; i++){
        if(isPrime(i) == 1)
            printf("%d\n",i);
    }
}


void input(){
    int l, u;
    printf("Enter lower limit : ");
    scanf("%d",&l);
    printf("Enter upper limit : ");
    scanf("%d",&u);
    if(l > u){
        printf("lower limit cannot be greater than upper limit");
        return;
    }
    display(l,u);
}

int main(){
    input();
    return 0;
}