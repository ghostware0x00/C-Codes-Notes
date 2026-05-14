#include<stdio.h>
int main(){
    int n,fac=1;
    printf("Enter the number to find factorial of : ");
    scanf("%d",&n);
    if(n < 0){
        printf("Number cannot be negative");
        return 0;
    }
    for(int i=1; i<=n; i++){
        fac = fac*i;
    }
    printf("Factorial of %d = %d",n,fac);
    return 0;
}