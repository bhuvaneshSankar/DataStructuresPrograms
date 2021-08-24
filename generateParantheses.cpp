#include <bits/stdc++.h>
#include <vector>

using namespace std;

void execute(vector<string> &paranthesesList, string currentParantheses, int leftLen, int rightLen, int maxLen)
{
    if (currentParantheses.length() == maxLen)
    {
        paranthesesList.push_back(currentParantheses);
        return;
    }
    if (leftLen == rightLen)
    {
        currentParantheses.push_back('(');
        --leftLen;
        execute(paranthesesList, currentParantheses, leftLen, rightLen, maxLen);
    }
    else if (leftLen < rightLen)
    {
        currentParantheses.push_back(')');
        --rightLen;
        execute(paranthesesList, currentParantheses, leftLen, rightLen, maxLen);
        //backtrack
        currentParantheses.pop_back();
        ++rightLen;
        if (leftLen > 0)
        {
            currentParantheses.push_back('(');
            --leftLen;
            execute(paranthesesList, currentParantheses, leftLen, rightLen, maxLen);
        }
    }
}
vector<string> AllParenthesis(int n)
{
    int leftLen = n, rightLen = n, maxLen = 2 * n;
    vector<string> paranthesesList;
    string currentParantheses = "";
    execute(paranthesesList, currentParantheses, leftLen, rightLen, maxLen);
    return paranthesesList;
}

int main()
{
    vector<string> vi = AllParenthesis(3);
    cout << "result\n";
    for (string s : vi)
    {
        cout << s << "\n";
    }
}
