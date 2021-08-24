#include<iostream>
using namespace std;
    int query(int arr[], int start, int end) {
        int sum = 0;
        int curr = 1;
        for (int i = start - 1; i <= end - 1; i++, curr++) {
            sum = curr % 2 != 0 ? sum + (arr[i] * curr) : sum - (arr[i] * curr);
        }
        return sum;
    }
    int main() {
        int t;
        cin >> t;
        for (int p = 0; p < t; p++) {
            int n, k;
            cin>>n;
            cin>>k;
            int arr[n];
            for (int i = 0; i < n; i++) {
                cin>>arr[i];
            }
            int globalSum = 0;
            for (int i = 0; i < k; i++) {
                char type;
                int q1, q2;
                cin>>type;
                cin>>q1>>q2;
                if (type == 'Q') {
                    globalSum += query(arr, q1, q2);
                } else {
                    arr[q1 - 1] = q2;
                }
            }
            cout<<"Case #"<<(p + 1)<<": "<<globalSum<<"\n";
        }
    }
