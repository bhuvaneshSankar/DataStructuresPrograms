#include <bits/stdc++.h>
#include <vector>
using namespace std;
bool isOdd(int n)
{
    return n % 2 != 0;
}
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    int low = 0;
    int high = n1;
    double ans = 0.0;
    while (low < high)
    {
        int mid = (high + low) / 2;

        int l1, l2, r1, r2;
        l1 = mid;
        r1 = l1 + 1;
        l2 = (n1 + n2) - (l1 + 1) - 1;
        r2 = l2 + 1;
        cout << "lh low " << low << " high " << high << " mid " << mid << " l1 " << l1 << " l2 " << l2 << " r1 " << r1 << " r2 " << r2 << "\n";
        if (l1 >= 0)
            l1 = nums1[l1];
        else
            l1 = INT_MIN;
        if (l2 >= 0)
            l2 = nums2[l2];
        else
            l2 = INT_MIN;
        if (r1 < n1)
            r1 = nums1[r1];
        else
            r1 = INT_MAX;
        if (r2 < n2)
            r2 = nums2[r2];
        else
            r2 = INT_MAX;
        cout << "val l1 " << l1 << " l2 " << l2 << " r1 " << r1 << "  r2 " << r2 << "\n";
        if (l1 <= r2 && l2 <= r1)
        {
            if (isOdd(n1 + n2))
            {
                ans = min(r1, r2);
            }
            else
            {
                ans = (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            return ans;
        }
        else if (l1 > r2)
        {
            high = mid - 1;
        }
        else
        {
            low = mid;
        }
    }
    return ans;
}

int main()
{
    vector<int> v1 = {1, 3};
    vector<int> v2 = {2};
    // vector<int> v1 = {1, 2};
    // vector<int> v2 = {3, 4};
    // vector<int> v1 = {};
    // vector<int> v2 = {1};
    // vector<int> v1 = {2};
    // vector<int> v2 = {};

    double ans = findMedianSortedArrays(v1, v2);
    cout << "ans " << ans << "\n";
}