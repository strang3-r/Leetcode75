#include <bits/stdc++.h>
#define I INT_MAX
#define V 8
using namespace std;

void prime_mst(int cost[][V], int n)
{
    int u, v, i, j, k, min = I;
    vector<int> near;
    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (cost[i][j] < min)
            {
                u = i;
                v = j;
            }
        }
    }


}

int main()
{

    int cost[V][V]{
        {I, I, I, I, I, I, I, I},
        {I, I, 25, I, I, I, 5, I},
        {I, 25, I, 12, I, I, I, 10},
        {I, I, 12, I, 8, I, I, I},
        {I, I, I, 8, I, 16, I, 14},
        {I, I, I, I, 16, I, 20, 18},
        {I, 5, I, I, I, 20, I, I},
        {I, I, 10, I, 14, 18, I, I},
    };

    int n = sizeof(cost[0]) / sizeof(cost[0][0]) - 1;

    prime_mst(cost, n);
    return 0;
}