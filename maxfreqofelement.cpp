#include <bits/stdc++.h> //in this we have created a map to store the freq..and created a minheap and output the elemnts having more freq
using namespace std;

typedef pair<int, int> pi;

void PrintTopKfrequentNums(vector<int> &arr, int k)
{

        //created a map becoz numbers  r repeating ... map stores the the freq of a particular number

    /*  input: (10->no. of ele
         2 2 2 1 1 1 3 3  4            
           2->key)
    Map will store the input like this ...with which it will be easier to store freq
    
     no.     freq
     1   ->   3
     2   ->   3
     3   ->   2
     4   ->   1
                                                                        
      */

    unordered_map<int, int> mp;
    for (auto e : arr)
    {
        mp[e]++;
    }

    priority_queue<pi, vector<pi>, greater<pi>> minh;
    for (auto e : mp) //iterating the map from 1st to last
    {
        minh.push(make_pair(e.second, e.first)); // pair becoz we r pushing both freq and no.

        if (minh.size() > k)
            minh.pop();
    }

    while (!minh.empty())
    {
        cout << minh.top().second << " "; //printing the no. with highest freq
        minh.pop();
    }
    cout << endl;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    PrintTopKfrequentNums(arr, k);
    return 0;
}