#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;
// struct cmmp
// {
//     bool operator()(pair<const int, string> a, pair<const int, string> b) const
//     {
//         if (a.first < b.first)
//         {
//             return true;
//         }
//         else if (a.first > b.first)
//         {
//             return false;
//         }
//         else
//         {
//             return a.second < b.second;
//         }
//     }
// };

struct cmmp
{
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

bool custom_cmp(pair<int, string> a, pair<int, string> b)
{
    if (a.first < b.first)
    {
        return true;
    }
    else if (a.first > b.first)
    {
        return false;
    }
    else
    {
        return a.second < b.second;
    }
}
int main()
{
    vector<int> v{10, 14, 17, 34, 89};
    vector<int>::iterator itr1 = lower_bound(v.begin(), v.end(), 91);
    //   cout << *itr1 << " " << itr1 - v.begin();

    map<int, int> mp;
    mp.insert({1, 3});
    int a = 4, b = 10;
    mp.insert({a, b});
    mp.insert(pair<int, int>(3, 5));
    mp[2] = 10;

    for (map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr)
    {
        //       cout << itr->first << " " << itr->second << "\n";
    }

    string str = "good evening folks its a pleasant evening goodies here folks hope you all are good goodies";
    unordered_map<string, int> freqStringUMap;
    string word;
    stringstream sstream(str);
    while (sstream >> word)
    {
        ++freqStringUMap[word];
    }
    multimap<int, string, cmmp> freqCountToWordsMap;
    //    unordered_map<string, int>::iterator itr1;
    for (unordered_map<string, int>::iterator itr1 = freqStringUMap.begin(); itr1 != freqStringUMap.end(); ++itr1)
    {
        freqCountToWordsMap.insert({itr1->second, itr1->first});
    }
    // for (multimap<int, string>::iterator itr1 = freqCountToWordsMap.begin(); itr1 != freqCountToWordsMap.end(); ++itr1)
    // {
    //     cout << itr1->first << " " << itr1->second << "\n";
    // }
    vector<pair<int, string>> vr;
    for (pair<int, string> pr : freqCountToWordsMap)
    {
        vr.push_back(pr);
    }
    sort(vr.begin(), vr.end(), custom_cmp);
    // for (pair<int, string> pr : vr)
    // {
    //     cout << pr.first << " " << pr.second << "\n";
    // }

    set<int, greater<int>> s{6, 1, 47, 52, 32, 14, 1, 52};
    for (int val : s)
    {
        cout << val << " ";
    }
    cout << "\n";
    unordered_set<int> us{6, 1, 47, 52, 32, 14, 47, 1};
    for (int val : us)
    {
        cout << val << " ";
    }
}