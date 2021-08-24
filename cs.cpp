#include <iostream>
using namespace std;

void countSort(char arr[])
{
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<len<<endl;
    char sortedArr[len];
    int range = 255;
    int countArr[range] = {0};
    for(int i=0; i<len; i++){
        countArr[arr[i]]++;
    }
    for(int i=1; i<range; i++){
        countArr[i] += countArr[i-1];
    }
    for(int i=len-1; i>=0; i--){
        char val = arr[i];
        int pos = countArr[val]-1;
        sortedArr[pos] = val;
        countArr[val]--;
    }
    cout<<sortedArr<<endl;
}
int main() {
	// your code goes here
	char arr[] = "geeksforgeeks";
	countSort(arr);
	cout<<arr;
	return 0;
}
