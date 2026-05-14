#include<stdio.h>
int main(){
    int a=0, b=1, c=0, n;
    printf("Enter the range : ");
    scanf("%d",&n);
    if(!(n<=0)){
        if(n == 1)
            printf("0\n");
        else if(n == 2)
            printf("0\t1\n");
        else{
            printf("0\t1\t");
            for(int i=1; i<=n-2; i++){
                c = a+b;
                printf("%d\t",c);
                a = b;
                b = c;
            }
        }
    }
    else
        printf("Invalid range value");
    printf("\n");
    return 0;
}