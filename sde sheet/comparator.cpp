#include <bits/stdc++.h>
#include <vector>
#include <map>
using namespace std;

void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}
struct mapComp
{
    bool operator()(const int a, const int b)
    {

        return a > b;
    }
};
void printMap(map<int, int, mapComp> mp)
{
    for (pair<int, int> pr : mp)
    {
        cout << pr.first << " " << pr.second << " \n";
    }
    cout << "\n\n-----\n\n";
}
/**
 * return true is a should come before b
 * According to the condition here b comes before a
 */
bool comp(const int a, const int b)
{
    return a > b;
}
int main()
{
    // vector<int> v = {45, 12, 74, 10, 36, 55};
    // printVector(v);
    // sort(v.begin(), v.end(), comp);
    // printVector(v);
    map<int, int, mapComp> mp;
    mp.insert({2, 5});
    mp.insert({1, 3});
    mp.insert({5, 10});
    mp.insert({4, 6});
    printMap(mp);
}