#include <iostream>
#include <vector>
using namespace std;

void printfloodfill(int[][] maze, int row, int col, string psf, bool visited[][])
{
    //base case
    if ((row < 0) || (col < 0) || row >= n || col >= m || maze[row][col] == 1 || visited[row][col] == true)
    {
        return;
    }
    if (row == size() && col ==)
    {
        cout << psf << endl;
        return;
    }

    visited[row][col] = true;
    printfloodfill(maze, row - 1, col, psf + "T", visited);
    printfloodfill(maze, row, col - 1, psf + "L", visited);
    printfloodfill(maze, row + 1, col, psf + "D", visited);
    printfloodfill(maze, row, col + 1, psf + "R", visited);
    visited[row][col] = false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)

        {
            cin >> arr[i][j];
        }
    }

    bool visited[n][m];
    printfloodfill(arr, 0, 0, "", visited);
}
