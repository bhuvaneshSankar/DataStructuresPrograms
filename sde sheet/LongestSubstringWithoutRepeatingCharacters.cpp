#include <bits/stdc++.h>
#include <map>
using namespace std;
int lengthOfLongestSubstring(string S)
{
    unordered_map<char, int> umap;
    if (S.length() == 1)
        return 1;
    int l = 0, r = 1;
    cout << "n = " << n;
    int len = 0;
    for (r = 1; r < n; ++r)
    {
        if (umap.find(S[r]) == umap.end())
        {
            umap[S[r]] = r;
        }
        else
        {
            if (umap[S[r]] >= l)
            {
                if (len < (r - l))
                    len = r - l;
                l = r;
            }
            umap[S[r]] = r;
        }
        // cout<<r<<" "<<len<<" "<<umap['a']<<"\n";
    }
    if (len < (r - l))
        len = r - l;
    return len;
}