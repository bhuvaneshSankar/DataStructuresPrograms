#include <bits/stdc++.h>
#include <vector>
using namespace std;
string longestPalindrome(string s)
{
    int len = s.length();
    vector<vector<int>> dp(len, vector<int>(len, 0));
    int max = INT_MIN;
    int maxX = 0, maxY = 0;
    for (int i = 0; i < len; ++i)
    {
        int p = 0, q = i;
        for (int j = i; j < len; ++j)
        {
            if (p == q)
            {
                dp[p][q] = 1;
            }
            else if (s[p] == s[q])
            {
                if ((dp[p + 1][q - 1] > 0) || (p + 1 == q))
                {
                    dp[p][q] = dp[p + 1][q - 1] + 2;
                }
            }
            if (dp[p][q] > max)
            {
                max = dp[p][q];
                maxX = p;
                maxY = q;
            }
            ++p;
            ++q;
        }
    }
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < len; ++j)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    int palLength = maxY - maxX + 1;
    vector<char> palList(palLength);
    int i = maxX, j = maxY;
    cout << palLength << " " << i << " " << j << "\n";
    int x = 0, y = palLength - 1;
    while (i <= j)
    {
        palList[x] = s[i];
        palList[y] = s[j];
        ++i;
        --j;
        ++x;
        --y;
    }
    string pal(palList.begin(), palList.end());
    return pal;
}
int main()
{
    string s = "cbbd";
    string pal = longestPalindrome(s);
    cout << "result " << pal << "\n";
}