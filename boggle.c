#include<stdio.h>
#include<string.h>
#include<stdbool.h>
void copyArr(int a1[], int a2[], int n){
int i;
for(i=0; i<n; i++){
a1[i] = a2[i];
}
}
void printArr(int arr[], int len){
    int i;
    for(i=0; i<len; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void printcharArr(char arr[][7], int r, int c){
    int i, j;
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}
void findWords(char dictionary[][100], int len, int hash[255]){

int copy[255]={0};
int i, j;
copyArr(copy, hash, 255);
//	printcharArr(boggle, n, m);
//	printArr(hash, 255);
bool isPrinted = false;
for(i=0; i<len; i++){
char* str = dictionary[i];
bool flag = true;
for(j=0; j<strlen(str); j++){
if(copy[str[j]] == 0){
flag=false;
break;
}
else{
copy[str[j]]--;
}
}
if(flag==false){
copyArr(copy, hash, 255);
}
else{
isPrinted = true;
printf("%s ", str);
copyArr(hash, copy, 255);
}
}
if(isPrinted==false){
printf("-1");
}
}
int main(){
    int i, j,t, x;
    scanf("%d", &t);
    while(t>0){
--t;
scanf("%d", &x);
char dictionary[x][100];
for(i=0; i<x; i++){
   scanf("%s", dictionary[i]);
}
int n , m;
scanf("%d %d", &n, &m);
char boggle[n][m];
for(i=0; i<n; i++){
    for(j=0; j<m; j++){
        scanf("%c", &boggle[i][j]);
    }
}
int hash[255] = {0};
for(i=0; i<n; i++){
    for(j=0; j<m; j++){
        hash[boggle[i][j]]++;
    }
}
findWords(dictionary, x, hash);
printf("\n");
    }
}

