#include<stdio.h>
#include<string.h>
#include<stdbool.h>

void rightShift(char str[], int i, int j, int n){
    printf(" %d right shift \n", i);
    printf("%s ", str);
    char temp = str[j];
    for(int k=j; k>i; k--){
        str[k] = str[k-1];
    }
    str[i] = temp;  
    printf("%s ", str);
}
void leftShift(char str[], int i, int j, int n){
    char temp = str[j];
    for(int k=j; k<i; k++){
        str[k] = str[k+1];
    }
    str[i] = temp;
}
bool notAdjacentCharacters(char str[], int n){
    for(int i=0; i<n-1; i++){
        if(str[i] == str[i+1]){
            return false;
        }
    }
    return true;
}
bool rearrangeUtil(char str[],  int n){
    int j, k;
 //   printf("fun ");
    for(int i=1; i<n; i++){
        printf("%d ", i);
        if(str[i]==str[i-1]){
            j=n-1;
            while(j>=i+1){
                if(str[j]!=str[i-1]){
                    rightShift(str, i, j, n);
                    break;
                }
                j--;
            }
            if(str[i]==str[i-1]){
                j=0;
                while(j<=i-1){
                    if(str[j]!=str[i-1]){
                        leftShift(str, i-1, j, n);
                        break;
                    }
                    j++;
                }
                if(str[i]==str[i-1]){
                    return false;
                }
            }
        }
        printf("%s ", str);
    }
    if(notAdjacentCharacters(str, n)==true){
        return true;
    
    }
    else{
        return false;
    }
}
int main(){
    char str[] = "honeymoonroom";
 //   char str[] = "geeksforgeeks";
 //   char str[] = "bbbabaaacd";
 //   char str[] = "bbbb";
  //  printf("s  ");
    
  //  printf("start ");
    int len = strlen(str);
  //  printf("%s ", str);
    if(rearrangeUtil(str, len)==true){
        printf("1 ");
    
    }
    else{
        printf("0 ");
    }
}