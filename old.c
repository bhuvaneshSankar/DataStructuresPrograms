#include<stdio.h>
    int max=-1;
    void findMax(int arr[], int n, int pos, int val){
        if(pos>=n){
            if(val>max){
                max=val;
            }
            return;
        }
        
        findMax(arr, n, pos+2, val+arr[pos]);
        findMax(arr, n, pos+3, val+arr[pos]);
        
    }
    void main(){
    //    int arr[] = {5,3,11,20};
    //    int arr[] = {10, 20, 15, 1, 9, 12, 5};
        int i;
    //    int n = sizeof(arr)/sizeof(int);
        int n;
        scanf("%d", &n);
        int arr[n];
        for(i=0; i<n; i++){
            scanf("%d", &arr[i]);
        }
        for(i=0; i<n; i++){
            if(i==n-1 || i==n-2){
                if(arr[i]<=max)
                    break;
            }
            if(i==n-3){
                if(arr[i]+arr[i+2]<=max)
                    break;
            }
            
            findMax(arr, n, i, 0);
        }
        printf("%d", max);
    }
 //77 96 27 92 48 87 97 56 5 54 47 32 98 71 43 23 61 86 44 27 33 93 54 99 80 95 83 59 82 28 70 12 84 93 61 69 42 74 44 17 80 43 6 
// 1 43 25 45 84 72 71 8 63 19 34 67 66 31 74 32 33 80 44 1 50 58 79 83 28 80 27 2 59 94 48 24 58 92 12 17 27 63 61 92 4 2 72 27 7 
// 8 64 57 19 89 74 92 99 59 61 51 51 5 60 44 47 47 10 71 19 20 30 23 26 

 