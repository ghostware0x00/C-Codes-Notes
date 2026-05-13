#include<stdio.h>
int main(){
    int num,i,count=0;
    printf("Enter the range : ");
    scanf("%d",&num);
    printf("Prime Numbers between 1 to %d\n",num);
    for(int a=2; a<=num; a++){
        int number = a;
        count=0;
        for(i=2; i<number; i++){
            if(number%i == 0){
                count++;
                break;
            }
        }
        if(count == 0)
            printf("%d\n",number);
    }
    return 0;
}