#include<stdio.h>
int main(){
    char character;
    printf("Enter the character : ");
    scanf(" %c",&character);
    // the gap prevents leading spaces
    // so lets say we take 25 as input in number so in buffer 2, 5 and "\n" 
    // since we are taking int so 25 will be take and "\n" will be left behind in buffer
    // %c tells c to take any character
    // so if we do scanf("%c") with so space, c will take the "\n" present in the buffer since %c tells it to take any character
    // to prevent this we do scanf(" %c") to eliminate leading spaces
    printf("ascii value of %c = %d",character,character);
    return 0;
}