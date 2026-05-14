#include<stdio.h>
int main(){
    int natural;
    printf("Enter natural number : ");
    scanf("%d",&natural);
    printf("Factors of %d :\n<-------------->\n",natural);
    for(int i=1; i<=natural; i++){
        if(natural%i == 0)
            printf("%d\n",i);
    }   
    printf("\n");
    return 0;
}