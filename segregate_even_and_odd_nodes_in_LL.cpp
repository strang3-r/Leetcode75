/*
GFG PROBLEM: Segregate even and odd nodes in a Linked List

Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list.
The order of appearance of numbers within each segregation should be same as that in the original list.

Example 1:

Input:
N = 7
Link List:
17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

Output: 8 2 4 6 17 15 9

Explanation: 8,2,4,6 are the even numbers
so they appear first and 17,15,9 are odd
numbers that appear later.
*/

// CODE:
//  { Driver Code Starts
// Initial template for C++

#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
// User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    Node *divide(int N, Node *head)
    {
        // code here
        Node *evenHead = NULL;
        Node *evenTail = NULL;
        Node *oddHead = NULL;
        Node *oddTail = NULL;

        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->data % 2 == 0)
            {
                if (evenHead == NULL)
                {
                    evenHead = temp;
                    evenTail = temp;
                }
                else
                {
                    evenTail->next = temp;
                    evenTail = temp;
                }
            }
            else
            {
                if (oddHead == NULL)
                {
                    oddHead = temp;
                    oddTail = temp;
                }
                else
                {
                    oddTail->next = temp;
                    oddTail = temp;
                }
            }
            temp = temp->next;
        }

        if (evenHead == NULL)
        {
            return oddHead;
        }
        if (oddHead == NULL)
        {
            return evenHead;
        }
        else
        {
            evenTail->next = oddHead;
            oddTail->next = NULL;
            return evenHead;
        }
    }
};

// { Driver Code Starts.

int main()
{
    // code
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans);
    }
    return 0;
}
// } Driver Code Ends
