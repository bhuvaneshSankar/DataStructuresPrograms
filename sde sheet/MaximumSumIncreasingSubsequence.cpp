#include <bits/stdc++.h>
#include <vector>
using namespace std;

int maxSumIS(int arr[], int n)
{
    // Your code goes here
    int maxSum = arr[0];
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i)
    {
        dp[i] = arr[i];
    }
    for (int j = 1; j < n; ++j)
    {
        for (int i = 0; i < j; ++i)
        {
            if ((arr[j] > arr[i]) && (dp[i] + arr[j] > dp[j]))
            {
                dp[j] = dp[i] + arr[j];
            }
        }
        maxSum = dp[j] > maxSum ? dp[j] : maxSum;
    }
    return maxSum;
}