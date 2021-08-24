#include<iostream>
#include<string.h>
using namespace std;

int getCount(char s1[], char s2[], int l1, int l2, int pos1, int pos2){
    if(pos1 < 0){
        return l2;
    }
    if(pos1==0 && pos2==0){
        if(s1[pos1] == s2[pos2]){
            return 0;
        }
        else{
            return 1;
        }
    }
    if(l1 == l2){
        if(s1[pos1] == s2[pos2]){
            return getCount(s1, s2, l1-1, l2-1, pos1-1, pos2-1);
        }
        else{
            return 1+getCount(s1, s2, l1-1, l2-1, pos1-1, pos2-1);
        }
    }
    else{
        if(s1[pos1] == s2[pos2]){
            return getCount(s1, s2, l1-1, l2-1, pos1-1, pos2-1);
        }
        else{
        //    return 1 + getCount(s1, s2, l1, l2-1, pos1, pos2-1);
            s2[pos2] = s1[pos1];
            return 1 + getCount(s1, s2, l1, l2, pos1, pos2);
        //    int val1 = 1 + getCount(s1, s2, l1, l2-1, pos1, pos2-1);
        //    s2[pos2] = s1[pos1];
        //    int val2 = 1 + getCount(s1, s2, l1, l2, pos1, pos2);
        //    cout<<l1<<"  "<<l2<<"  "<<val1<<"  "<<val2<<endl;
        //    return val1<val2 ? val1:val2;
        }
    }
}
int main(){
 //   char s1[100] = "gesek";
 //   char s2[100] = "geek";
    char s1[100] = "lrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmcoq";
    char s2[100] = "hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcaceh";
    int l1 = strlen(s1), l2 = strlen(s2);
    int no;
    if(l2>l1)
        no = getCount(s1, s2, l1, l2, l1-1, l2-1);
    else
        no = getCount(s2, s1, l2, l1, l2-1, l1-1);
    cout<<"final = "<<no<<endl;
}

/*
84 87
lrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmcoq 
hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcaceh
 */