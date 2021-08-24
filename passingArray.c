#include<stdio.h>

int n;
int* getArray(){        //int array so returning int pointer
    n=10;
    static int arr[10] = {1,2,3,4,5,6,7,8,9,10};        // arr is local variable so it automatically gets disappeared after this function block. so if declared as static then it gets global scope
    return arr;
}
void solveUtil(){
    int* startPtr = getArray();
    for(int i=0; i<n; i++)
        printf("%d ", *(startPtr+i));
}
int main(){
    solveUtil();    
}