#include <bits/stdc++.h>
#include <vector>

#define ll long long
#define deb(a) cout << #a << " - " << a << "\n"
#define deb2(a, b) cout << #a << " - " << a << " " << #b << " - " << b << "\n";
#define nl "\n"

using namespace std;
int solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        int val;
        cin >> arr[i];
    }
    // if (n == 2)
    //     return n;
    vector<int> diff(n - 1);
    for (int i = 1; i < n; ++i)
    {
        int d = (arr[i] - arr[i - 1]);
        diff[i - 1] = d;
    }
    int max = -1;
    --n;
    for (int i = 0; i < n - 1; ++i)
    {
        int cnt = 1;
        while (i < n - 1 && diff[i] == diff[i + 1])
        {
            cnt++;
            ++i;
        }
        if (cnt > max)
        {
            max = cnt;
        }
    }
    return max + 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    int i = 1;
    while (t > 0)
    {
        --t;
        int res = solve();
        cout << "Case #" << (i) << ": " << res << "\n";
        ++i;
    }
}