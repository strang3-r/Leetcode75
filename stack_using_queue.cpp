//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
        }
        cout<<endl;
    }
}

void QueueStack :: push(int x)
{
       q2.push(x);
       while(!q1.empty()) {
           int curr = q1.front();
           q1.pop();
           q2.push(curr);
       }
       swap(q1, q2);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
      if(q1.empty()) {
          return -1;
      }
      int ans = q1.front();
      q1.pop();
      return ans;
}
