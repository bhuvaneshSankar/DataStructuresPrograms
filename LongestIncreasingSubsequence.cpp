#include <bits/stdc++.h>
#include <vector>
using namespace std;
int iter = 0;
/*
void solve(int n, vector<int> v, vector<int> &currV, vector<int> &maxV, int currPos)
{
    if (currPos == n)
    {
        if (currV.size() > maxV.size())
        {
            maxV = currV;
        }
    }
    else
    {
        if (currV.empty() || v[currPos] > currV[currV.size() - 1])
        {
            currV.push_back(v[currPos]);
            solve(n, v, currV, maxV, currPos + 1);
            currV.pop_back();
            solve(n, v, currV, maxV, currPos + 1);
        }
        else
        {
            solve(n, v, currV, maxV, currPos + 1);
        }
    }
}
*/
void solve(int n, vector<int> v, int currPos, int prevInc, int &globalMax, int currMax, vector<int> &dp)
{
    ++iter;
    if (currPos == n)
    {
        if (currMax > globalMax)
        {
            globalMax = currMax;
        }
    }
    else
    {
        if (prevInc == -1 || v[currPos] > v[prevInc])
        {
            solve(n, v, currPos + 1, currPos, globalMax, currMax + 1);
            solve(n, v, currPos + 1, prevInc, globalMax, currMax);
        }
        else
        {
            solve(n, v, currPos + 1, prevInc, globalMax, currMax);
        }
    }
}

int main()
{
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    //vector<int> arr = {3, 10, 2, 1, 20};
    //   vector<int> arr = {50, 3, 10, 7, 40, 80};
    //vector<int> arr = {3, 2};
    //vector<int> arr = {10, 22, 9, 33, 21, 50};
    vector<int> currV;
    vector<int> maxV(0);
    int n = arr.size();
    //   solve(n, arr, currV, maxV, 0);
    int globalMax = -1;
    solve(n, arr, 0, -1, globalMax, 0);
    cout << globalMax << "  " << iter;
    // for (int i : maxV)
    // {
    //     cout << i << " ";
    // }
}