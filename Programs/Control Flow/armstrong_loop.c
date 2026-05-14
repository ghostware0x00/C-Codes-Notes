#include<stdio.h>
int main(){
    int count;
    printf("Armstrong Numbers between 1 and 1000\n<------------------------------------>\n");
    for(int range=1; range<=1000; range++){
        int copy = range;
        count=0;
        while(copy > 0){
            count++;
            copy = copy/10;
        }
        copy = range;
        int arms=0,rem,remSum=1;
        while(copy > 0){
            rem = copy%10;
            remSum = 1;
            for(int i=1; i<=count; i++)
                remSum = remSum * rem;
            arms = arms+remSum;
            copy = copy/10;
        }
        if(range == arms)
            printf("%d\n",range);
    }
    return 0;
}