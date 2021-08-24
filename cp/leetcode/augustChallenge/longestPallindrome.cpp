#include <bits/stdc++.h>
using namespace std;

int longestPalindrome(string s)
{
    int a[128] = {0};
    for (char ch : s)
    {
        a[ch] += 1;
    }
    int length = 0;
    for (int i = 0; i < 128; i++)
    {
        if (a[i] & 1)
        {
            length += (a[i] - 1);
            if (length % 2 == 0)
            {
                length++;
            }
        }
        else
        {
            length += a[i];
        }
    }
    return length;
}
