#include <bits/stdc++.h>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int max = 0;
    int i = 0, j = 1;
    int n = nums.size();
    for (; j < n; ++j)
    {
        if (nums[i] == 1 && nums[j] == 0)
        {
            max = max > (j - i) ? max : (j - i);
            i = j;
        }
        else if (nums[i] == 0 && nums[j] == 1)
        {
            i = j;
        }
    }
    if (nums[i] == 1)
        max = max > (n - i) ? max : (n - i);
    return max;
}