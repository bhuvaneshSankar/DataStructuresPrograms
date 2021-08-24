/*
The stock span problem is a financial problem where we have a series of n daily price quotes for a stock and we need to calculate the span of stock’s price for all n days. 
The span Si of the stock’s price on a given day i is defined as the maximum number of consecutive days just before the given day, for which the price of the stock on the current day is less than or equal to its price on the given day.
For example, if an array of 7 days prices is given as {100, 80, 60, 70, 60, 75, 85}, then the span values for corresponding 7 days are {1, 1, 1, 2, 1, 4, 6}.

Example 1:

Input: 
N = 7, price[] = [100 80 60 70 60 75 85]
Output:
1 1 1 2 1 4 6
Explanation:
Traversing the given input span for 100 
will be 1, 80 is smaller than 100 so the 
span is 1, 60 is smaller than 80 so the 
span is 1, 70 is greater than 60 so the 
span is 2 and so on. Hence the output will 
be 1 1 1 2 1 4 6.
Example 2:

Input: 
N = 6, price[] = [10 4 5 90 120 80]
Output:
1 1 2 4 5 1
Explanation:
Traversing the given input span for 10 
will be 1, 4 is smaller than 10 so the 
span will be 1, 5 is greater than 4 so 
the span will be 2 and so on. Hence, the 
output will be 1 1 2 4 5 1.
User Task:
The task is to complete the function calculateSpan() which takes two parameters, an array price[] denoting the price of stocks, and an integer N denoting the size of the array and number of days. This function finds the span of stock's price for all N days and returns an array of length N denoting the span for the i-th day.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 105
1 ≤ C[i] ≤ 105

Approach 
1. naive approach - two for loops - O(n^2)
2. Stack based approach - O(n)
   * Previous element of the current index is the top of the stack(starts from i=1)
   * if the price of the current day is lesser than the price of the previous day then result[i] = 1 coz its price is lesser
   * if the price of the current day is greater than or equal to the price of the previous day then the logic starts
     =>traverse the stack until the stack is empty or price of current day is lesser than price[stackTop], so you wud get a 
       index where the chain breaks and thus cud calculate the number of days bw them
   * push the current index into the stack - mandatory for all conditions
   TC - All the indices will be pushed into the stack one time and at worst case if the given price array is in increasing order
   then all the indices will be poped out one time from the stack
      So O(2N) => O(N)
*/
#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;
vector<int> calculateSpan(int price[], int n)
{
    // Your code here
    stack<int> stockSpan;
    vector<int> result(n);
    stockSpan.push(0);
    result[0] = 1;
    for (int i = 1; i < n; ++i)
    {
        if (price[i] < price[stockSpan.top()])
        {
            result[i] = 1;
        }
        else
        {
            int prevStackTop;
            while (!stockSpan.empty() && price[i] >= price[stockSpan.top()])
            {
                prevStackTop = stockSpan.top();
                stockSpan.pop();
            }
            if (stockSpan.empty())
            {
                stockSpan.push(prevStackTop);
                result[i] = i + 1;
            }
            else
            {
                result[i] = i - stockSpan.top();
            }
        }
        stockSpan.push(i);
    }
    return result;
}
int main()
{
    int price[] = {2, 6, 8, 5};
    int n = 4;
    vector<int> vi = calculateSpan(price, n);
    for (int i : vi)
    {
        cout << i << " ";
    }
}