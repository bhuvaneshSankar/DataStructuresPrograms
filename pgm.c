#include<stdio.h>
int main(){
    int a1[100], a2[100], i=0, j=0;
    int a;
    char ch;
     while(1){
        scanf("%d", &a);
        if(ch=='\n'){
            break;
        }
        a1[i] = a;
        i++ ;
  } 
  for(j=0; j<i; j++){
      printf("%d ", a1[i]);
  }
}