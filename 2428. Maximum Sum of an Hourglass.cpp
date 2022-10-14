#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSum(vector<vector<int>> &grid)
    {
        // vector<pair<int>> pos = {{0,0},{0,1},{0,2},{1,1},{2,0},{2,1},{2,2}};
        int sum = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (i + 2 < grid.size() && j + 2 < grid[0].size())
                {
                    int temp = grid[i][j] + grid[i][j + 1] + grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
                    sum = max(sum, temp);
                }
            }
        }
        return sum;
    }
};
int main()
{
    Solution b;
    vector<vector<int>> grid = {{6, 2, 1, 3}, {4, 2, 1, 5}, {9, 2, 8, 7}, {4, 1, 2, 9}};
    cout << b.maxSum(grid) << endl;
    return 0;
}