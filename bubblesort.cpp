/* Here we just comapre the next element with the previous element and then do the same.....
n-i-1 becoz for each i the element will be sorted*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j + 1] < a[j])
            {
                swapped = true;
                swap(a[j + 1], a[j]);
            }
        }
        if (!swapped)
        {
            break;
        }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}