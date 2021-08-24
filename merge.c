#include<stdio.h>

void merge(int arr[], int n, int l, int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int a1[n1];
    int a2[n2];
    for(int i=0; i<n1; i++){
        a1[i] = arr[l+i];
    }
    for(int i=0; i<n2; i++){
        a2[i] = arr[m+1+i];
    }
    
    int i=0, j=0, k=l;
    while(i<n1 && j<n2){
        if(a1[i]<=a2[j]){
            arr[k] = a1[i];
            i++;
            k++;
        }
        else{
            arr[k] = a2[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k] = a1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = a2[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int n, int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(arr, n, l, m);
        mergeSort(arr, n, m+1, r);
        merge(arr, n, l, m, r);
    }
}
void printArr(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[] = {8,1,7,10,6,12,3,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, n, 0, n);
    printArr(arr, n);
}