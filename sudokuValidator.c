#include<stdio.h>
#include<stdbool.h>
#define N 9

/*
  checks the entire row and if the same number has been repeated then returns false
*/
bool checkRow(int arr[][N], int i, int j){
    for(int col=0; col<N; col++){
        if(col!=j && arr[i][col] == arr[i][j])
            return false;
    }
    return true;
}

/*
  checks the entire column and if the same number has been repeated then returns false
*/
bool checkColumn(int arr[][N], int i, int j){
    for(int row=0; row<N; row++){
        if(row!=i && arr[row][j] == arr[i][j]){
            return false;
        }
    }
    return true;
}
/*
  checks the current box of that particular entry and if the same number has been repeated then returns false
*/
bool checkBox(int arr[][N], int i, int j){
    int startX, startY, endX, endY;
    startX = (i/3)*3;
    startY = (j/3)*3;
    endX = ((i/3)*3)+2;
    endY = ((j/3)*3)+2;

    for(int row=startX; row<=endX; row++){
        for(int col=startY; col<=endY; col++){
            if(row!=i && col!=j && arr[row][col] == arr[i][j]){
                return false;
            }
        }
    }
    return true;
}
void checkSudoku(int arr[][N]){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(!checkRow(arr, i, j)){
                printf("Row %d doesn't contain all the digits 1-9", (i+1));
                printf("\nSudoku Matrix Verification FAILED");
                return;
            }
            if(!checkColumn(arr, i, j)){
                printf("Colmn %d doesn't contain all the digits 1-9", (j+1));
                printf("\nSudoku Matrix Verification FAILED");
                return;
            }
            if(!checkBox(arr, i, j)){
                printf("Failed for cube starting with row=%d,col=%d", (((i/3)*3)+1), (((j/3)*3)+1));
                printf("\nSudoku Matrix Verification FAILED");
                return;
            }
        }
    }
    printf("Sudoku Matrix Verification SUCCESS");
}
int main(){
    int arr[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    checkSudoku(arr);
}