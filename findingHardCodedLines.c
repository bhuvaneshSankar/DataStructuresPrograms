#include<stdio.h>
#include<stdbool.h>

bool isNumber(char ch){
    if(ch>='0' && ch<='9')
        return true;
    else
        return false;
}
bool isString(char ch){
    if(ch=='"' || ch=='\'')
        return true;
    else    
        return false;
}

bool isOperator(char ch){
    if(ch=='+' || ch=='-' || ch=='/' || ch=='%' || ch=='<' || ch=='>' || ch=='=')
        return true;
    else
        return false;
}

bool isHexNumber(char* data, int i){
    if(data[i]=='0' && data[i+1]=='x')
        return true;
    else
        return false;
}
bool containsHardCodedConstant(char* data){
    for(int i=0; data[i]!='\0' && data[i]!='\n'; i++){
        if(isOperator(data[i])){
            while(data[i]!='\0' && data[i]!='\n' && i<100 && isOperator(data[i])){
                i++;
            }
            if(isString(data[i]))  return true;
            if(isNumber(data[i]) && data[i]>'1')  return true;
            if(isNumber(data[i]) && ( data[i]=='1' || data[i]=='0') && isNumber(data[i+1]))  return true;
            if(isHexNumber(data, i))  return true;
        }
    }
    return false;
}

void detectHardCodedConstants(char* fileName){
    FILE *filePointer = fopen(fileName, "r");
    if(filePointer == NULL){
        printf("Cannot open the file.");
        return;
    }
    char data[100];
    int lineNum=1;
    while(fgets(data, 100, filePointer)!=NULL){
        if(containsHardCodedConstant(data)){
            printf("%d %s", lineNum, data);
        }
        lineNum++;
    }
    fclose(filePointer);
}

int main(){
   char fileName[100];
   printf("Enter the file name\n");
   scanf("%s", fileName);
   detectHardCodedConstants(fileName); 
}