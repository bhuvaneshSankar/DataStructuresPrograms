#include <bits/stdc++.h>
#include <vector>
#include <queue>

using namespace std;
int iteration = 0;

//dfs
int solve(vector<vector<int>> &maze, vector<vector<int>> &visited, int &lenX, int &lenY, int x, int y, int minDistance, int &globalMinDistance)
{
    ++iteration;
    if (x < 0 || y < 0 || x == lenX || y == lenY || visited[x][y] == 1 || maze[x][y] == 0)
    {
        return 0;
    }
    if (maze[x][y] == 9)
    {
        if (minDistance < globalMinDistance)
        {
            globalMinDistance = minDistance;
        }
        return 1;
    }
    visited[x][y] = 1;
    solve(maze, visited, lenX, lenY, x, y + 1, minDistance + 1, globalMinDistance);
    solve(maze, visited, lenX, lenY, x + 1, y, minDistance + 1, globalMinDistance);
    solve(maze, visited, lenX, lenY, x, y - 1, minDistance + 1, globalMinDistance);
    solve(maze, visited, lenX, lenY, x - 1, y, minDistance + 1, globalMinDistance);
    visited[x][y] = 0;
}

int getMin(int a, int b, int c, int d)
{
    if (a == -1)
    {
        a = INT_MAX;
    }
    if (b == -1)
    {
        b = INT_MAX;
    }
    if (c == -1)
    {
        c = INT_MAX;
    }
    if (d == -1)
    {
        d = INT_MAX;
    }
    int minVal = a;
    if (a < b && a < c && a < d)
    {
        minVal = a;
    }
    else if (b < c && b < d)
    {
        minVal = b;
    }
    else if (c < d)
    {
        minVal = c;
    }
    else
    {
        minVal = d;
    }
    if (minVal == INT_MAX)
    {
        minVal = -1;
    }
    return minVal;
}

//dp
int solvee(vector<vector<int>> &maze, vector<vector<int>> &visited, int &lenX, int &lenY, int x, int y, int minDistance, int &globalMinDistance, vector<vector<int>> &dp)
{
    ++iteration;
    if (minDistance >= globalMinDistance || x < 0 || y < 0 || x == lenX || y == lenY || visited[x][y] == 1 || maze[x][y] == 0)
    {
        return -1;
    }
    if (maze[x][y] == 9)
    {
        if (minDistance < globalMinDistance)
        {
            globalMinDistance = minDistance;
        }
        return 1;
    }
    visited[x][y] = 1;
    if (dp[x][y] != -1)
    {
        visited[x][y] = 0;
        return dp[x][y] + 1;
    }
    int l1 = solvee(maze, visited, lenX, lenY, x, y + 1, minDistance + 1, globalMinDistance, dp);
    int l2 = solvee(maze, visited, lenX, lenY, x + 1, y, minDistance + 1, globalMinDistance, dp);
    int l3 = solvee(maze, visited, lenX, lenY, x, y - 1, minDistance + 1, globalMinDistance, dp);
    int l4 = solvee(maze, visited, lenX, lenY, x - 1, y, minDistance + 1, globalMinDistance, dp);
    int d = getMin(l1, l2, l3, l4);
    cout << l1 << " " << l2 << " " << l3 << " " << l4 << " " << d << "\n";
    dp[x][y] = d;
    visited[x][y] = 0;
    if (d == -1)
    {
        return d;
    }
    return (d + 1);
}

//bfs - efficient approach O(mn)
int bfs(vector<vector<int>> &maze, int lenX, int lenY, int startX, int startY)
{
    vector<vector<int>> visited(lenX, vector<int>(lenY, 0));
    bool found = false;
    queue<pair<int, int>> qu;
    qu.push({startX, startY});
    visited[startX][startY] = 1;
    int distance = 0;
    while (!qu.empty() && !found)
    {
        ++distance;
        int len = qu.size();
        for (int i = 0; i < len && !found; ++i)
        {
            pair<int, int> currentTile = qu.front();
            qu.pop();
            int x = currentTile.first;
            int y = currentTile.second;
            int posX[] = {0, 1, 0, -1};
            int posY[] = {1, 0, -1, 0};
            for (int j = 0; j < 4; ++j)
            {
                int currX = x + posX[j];
                int currY = y + posY[j];
                if (currX < 0 || currY < 0 || currX == lenX || currY == lenY || visited[currX][currY] || maze[currX][currY] == 0)
                {
                    continue;
                }
                if (maze[currX][currY] == 9)
                {
                    found = true;
                    break;
                }
                else
                {
                    qu.push({currX, currY});
                    visited[currX][currY] = 1;
                }
            }
        }
    }
    return found ? distance : -1;
}

int main()
{
    vector<vector<int>> maze{
        {1, 1, 0, 0, 0},
        {1, 1, 1, 0, 0},
        {1, 1, 1, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 1, 9, 0}};
    // vector<vector<int>> maze{
    //     {1, 1, 1, 1},
    //     {0, 1, 1, 1},
    //     {0, 1, 0, 1},
    //     {0, 1, 9, 1}};
    int m = maze.size();
    int n = maze[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int globalMinDistance = INT_MAX;
    // solve(maze, visited, m, n, 0, 0, 0, globalMinDistance);
    // solvee(maze, visited, m, n, 0, 0, 0, globalMinDistance, dp);
    // cout << "maze \n";
    // for (int i = 0; i < m; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "result " << dp[0][0] << "\n";
    // cout << "globalmindist " << globalMinDistance << "\n";
    // cout << "iteration " << iteration;
    int bfsDist = bfs(maze, m, n, 0, 0);
    cout << "bfs " << bfsDist << "\n";
}