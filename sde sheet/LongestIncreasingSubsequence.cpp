#include <bits/stdc++.h>
#include <vector>
using namespace std;
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxVal = 1;
    for (int j = 1; j < n; ++j)
    {
        for (int i = 0; i < j; ++i)
        {
            if ((nums[j] > nums[i]) && (dp[i] + 1 > dp[j]))
            {
                dp[j] = dp[i] + 1;
            }
        }
        maxVal = dp[j] > maxVal ? dp[j] : maxVal;
    }
    return maxVal;
}