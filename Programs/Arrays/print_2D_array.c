#include<stdio.h>

void display(int row, int column, int arr[row][column]){// in modern c row = args1 col = args2 array[row][col] = args3 (this is the signature)
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
}

void input(int row, int column, int arr[row][column]){
    printf("Enter the elements of array : \n");
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            printf("arr[%d][%d] : ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
}

int main(){
    int r,c;
    printf("Enter rows : ");
    scanf("%d",&r);
    printf("Enter columns : ");
    scanf("%d",&c);
    int arr[r][c];
    input(r, c, arr);
    display(r, c, arr);
    return 0;
}