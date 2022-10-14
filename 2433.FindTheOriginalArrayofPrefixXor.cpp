#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> findArray(vector<int> &A)
    {
        for (int i = A.size() - 1; i > 0; --i)
            A[i] ^= A[i - 1];
        return A;
    }
};

int main()
{
    Solution b;
    vector<int> arr = {5, 2, 0, 3, 1};
    auto ans = b.findArray(arr);
    for (int x : ans)
        cout << x << endl;
    return 0;
}