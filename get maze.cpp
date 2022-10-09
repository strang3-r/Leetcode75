
//use eulers tree to understand
//    sc=starting col
//    sr=starting row
//    dc =destination col
//    dr =destination row
// v & h= vertical and horizontal

#include <iostream>
#include <vector>
using namespace std;

vector<string> getpath(int sr, int sc, int dr, int dc)
{
    if (sr == dr && sc == dc) //base case
    {
        vector<string> base;
        base.push_back("");
        return base;
    }
    vector<string> ans;
    if (sc + 1 <= dc) // condition to not go outside the maze
    {
        vector<string> hpath = getpath(sr, sc + 1, dr, dc); //moving in horizontsl means rigth side
        for (string s : hpath)
        {
            ans.push_back("h" + s);
        }
    }
    if (sr + 1 <= dr) // condition to not go outside the maze
    {
        vector<string> vpath = getpath(sr + 1, sc, dr, dc); //moving in vertical direction means downwards
        for (string s : vpath)
        {
            ans.push_back("v" + s);
        }
    }
    return ans;
}
void display(vector<string> &a) //display the output
{

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i];
        cout << " ";
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> answer = getpath(0, 0, n - 1, m - 1);
    display(answer);
}