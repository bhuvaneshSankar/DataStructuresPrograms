#include <bits/stdc++.h>
#include <vector>

#define ll long long
#define deb(a) cout << #a << " - " << a << "\n"
#define deb2(a, b) cout << #a << " - " << a << " " << #b << " - " << b << "\n";
#define nl "\n"

using namespace std;
// int solve()
// {
//     unordered_map<string, float> um;
//     int n;
//     for (int i = 0; i < n; ++i)
//     {
//         um.insert({products[i], productPrices[i]});
//     }
//     int count = 0;
//     for (int i = 0; i < n; ++i)
//     {
//         string product = productSold[i];
//         float price = soldPrice[i];
//         float actualPrice = um[product];
//         if (price != actualPrice)
//         {
//             count++;
//         }
//     }
//     return count;
// }
// void solve(vector<int> arr)
// {
//     sort(arr.begin(), arr.end());
//     int i = 0, j = arr.size() - 1;
//     while (i < j)
//     {
//         int temp = arr[i];
//         arr[i] = arr[j];
//         arr[j] = temp;
//         i++;
//         j--;
//     }
//     return arr;
// }
// int countPairs(vector<int> nums, int k)
// {
//     set<int> st;
//     for (int val : nums)
//     {
//         st.insert(val);
//     }
//     int count = 0;
//     //a+k=b ... b-k=a
//     for (int val : st)
//     {
//         int diff = val - k;
//         if (diff == 0)
//             count++;
//         else
//         {
//             auto it = st.find(diff);
//             if (it != st.end())
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }
int main()
{
    // vector<int> arr = {5, 2, 7, 8, -2, 25, 25};
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    sort(arr.begin(), arr.end());
    int i = 0, j = arr.size() - 1;
    for (int val : arr)
    {
        cout << val << " ";
    }
    cout << "\n";
    int n = arr.size();
    vector<int> res(arr.size());
    int p = 0, q = arr.size() - 1;
    for (int i = 0; i < n; ++i)
    {
        res[i] = arr[q];
        --q;
        ++i;
        res[i] = arr[p];
        ++p;
    }
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << res[i] << " ";
    }
    // for (int val : arr)
    // {
    //     cout << val << " ";
    // }
}