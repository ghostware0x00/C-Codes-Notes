#include<stdio.h>
int main(){
    char i='A';// computer treats char as 1 byte integer so it stores 65 (ASCII value of 'A') in memory and therefore increment is possible
    while(i <= 'Z'){
        printf("%c\n",i);
        i++;
    }
    return 0;
}