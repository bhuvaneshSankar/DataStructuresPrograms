#include<stdio.h>
int* cellComplete(int cells[], int days) {
    int flag[8], i, day;
    for(day=0; day<days; day++){
    for(i=0; i<8; i++){
        if(i==0){
            if(cells[i+1]==1){
                flag[i] = 1;
            }
            else
                flag[i]=0;
        }
        else if(i==7){
            if(cells[6]==1)
                flag[i]=1;
            else
                flag[i]=0;
        }
        else{
            if(cells[i-1]==cells[i+1])
                flag[i]=0;
            else
                flag[i]=1;
        }
    }
    for(i=0; i<8; i++)
        cells[i]=flag[i];
    }
}
void main(){
    int arr[8] = {1,0,0,0,0,1,0,0};
    cellComplete(arr, 3);
    int i;
    for(i=0; i<8; i++)
        printf("%d ", arr[i]);
}