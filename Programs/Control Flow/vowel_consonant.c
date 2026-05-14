#include<stdio.h>
#include<ctype.h>
int main(){
    char character;
    printf("Enter a character : ");
    scanf(" %c",&character);
    char c = tolower(character);
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        printf("Vowel");
    else
        printf("Consonant");
    return 0;
}