#include<stdio.h>
#include<math.h>

void quadratic_calc(int b,int a,int c){
    int x1=0, x2=0;
    if(a == 0){
        printf("a cannot be zero\n");
        return;
    }
    x1 = (-b + sqrt((b*b)-(4*a*c)))/2*a;
    x2 = (-b - sqrt((b*b)-(4*a*c)))/2*a;
    printf("x = %d and x = %d",x1,x2);
}

void input(){
    int a,b,c;
    printf("Enter the value of b : ");
    scanf("%d",&b);
    printf("Enter the value of a : ");
    scanf("%d",&a);
    printf("Enter the value of c : ");
    scanf("%d",&c);
    quadratic_calc(b,a,c);
}
int main(){
    input();
    return 0;
}