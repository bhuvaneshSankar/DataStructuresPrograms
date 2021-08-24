#include<stdio.h>
#include<string.h>

void swapChar(char str[], int i, int j){
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}
void reverseIndividualWords(char str[], int len){
    int i=0,j=0, start;
  //  printf("%d ", len);
    for(;i<len; i++){
    //    printf("%d ", i);
        start = i;
        while(i<len && str[i]!=' ' && str[i]!='\0'){
            i++;
        }
        j=i-1;
        printf("\n%d  %d\n", start, j);
        while(start<j){
            swapChar(str, start, j);
            start++;
            j--;
        }
        printf("%s \n", str);
    }
    printf("\n%s ", str);
}
void reverseString(char str[], int len){
    int i=0, j=len-1;
    while(i<j){
        swapChar(str, i, j);
        i++;
        j--;
    }
    printf("%s ", str);
    reverseIndividualWords(str, len);
  //  printf("%s ", str);
}
int main(){
    char str[] = "I love programming";
    int len = strlen(str);
    reverseString(str, len);
}