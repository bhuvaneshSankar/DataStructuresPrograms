#include <bits/stdc++.h>
#include <vector>

#define ll long long
#define deb(a) cout << #a << " - " << a << "\n"
#define deb2(a, b) cout << #a << " - " << a << " " << #b << " - " << b << "\n";
#define nl "\n"

using namespace std;
/**
 * impossible : 
 * c greater than a or b
 * if a == len && b == len && c < len
 */
void consLeft(int n, vector<int> &v, int ch, int fill, int pos)
{
    //<=ch is the available building size
    // fill is the number of builings to fill to be able to see from left
    // pos is the index of building upto which i should fill from 0
    // cout << nl << "cons left " << ch << " " << fill << " " << pos << "\n";
    int l = 0, r = pos;
    int vacant = pos;
    if (fill == vacant)
    {
        for (int i = 0; i < pos; ++i)
        {
            v[i] = ch - 1;
        }
    }

    else if (fill < vacant)
    {
        for (int i = 0; i < fill; ++i)
        {
            v[i] = ch - 1;
        }
        for (int i = fill; i < pos; ++i)
        {
            v[i] = ch - 2;
        }
    }
}
bool consRight(int n, vector<int> &v, int ch, int fill, int pos)
{
    int vacant = n - pos;
    // cout << nl << "cons right " << ch << " " << fill << " " << pos << " " << vacant << nl;
    if (fill > vacant)
    {
        return false;
    }
    if (fill == 0 && vacant > 0)
    {
        return false;
    }
    if (fill == vacant)
    {
        for (int i = pos; i < n; ++i)
        {
            v[i] = ch - 1;
        }
    }
    else if (fill < vacant)
    {
        for (int i = n - 1, j = 0; i >= pos; --i, ++j)
        {
            if (j < fill)
            {
                v[i] = ch - 1;
            }
            else
            {
                v[i] = ch - 2;
            }
        }
    }
    return true;
}
void util(int n, int a, int b, int c)
{
    int ld = a - c;
    int rd = b - c;
    vector<int> v(n);

    int leftChoice, leftFill, leftPos, leftVacant;
    leftChoice = n - 1;
    leftFill = ld;
    leftPos = ld; //not inc
    leftVacant = ld;
    int rightChoice, rightFill, rightPos, rightVacant;
    rightChoice = n - 1;
    rightFill = rd;
    rightPos = ld + c; //inc
    rightVacant = n - rightPos;
    if (rightFill > rightVacant)
    {
        //impossible
    }
    int offset = 0;
    if (rightFill == 0 && rightVacant > 0)
    {
        while (rightVacant > 0)
        {
            offset += 1;
            // leftChoice = n - 1;
            // leftFill = ld;
            // leftPos = ld + offset; //not inc
            // leftVacant = ld + offset;
            rightChoice = n - 1;
            rightFill = rd;

            rightPos = ld + c + offset; //inc
            rightVacant = n - rightPos;
        }
    }
    consLeft(n, v, n, ld, ld + offset);
    bool res = consRight(n, v, n, rd, ld + c + offset);
    if (!res)
    {
        cout << "IMPOSSIBLE\n";
    }

    else
    {
        for (int i = ld + offset; i < (ld + c + offset); ++i)
        {
            v[i] = n;
        }
        for (int val : v)
        {
            cout << val << " ";
        }
        cout << "\n";
    }
}
void solve(int tc)
{
    int n, a, b, c;
    cin >> n;
    cin >> a;
    cin >> b;
    cin >> c;
    vector<int> ans(n);
    cout << "Case #" << tc << ": ";
    if (c > a || c > b)
    {
        cout << "IMPOSSIBLE\n";
    }
    else if (a == n && b == n && c < n)
    {
        cout << "IMPOSSIBLE\n";
    }
    else if (a == b && a == c && a < n)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        util(n, a, b, c);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    int tc = 1;
    while (t > 0)
    {
        --t;
        solve(tc);
        tc++;
    }
}
