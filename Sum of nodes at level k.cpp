/*Question:
Given a binary tree with N nodes and an integer K, the task is to find the sum of all the nodes 
present at the Kth level.
*/
#include <iostream>
#include<queue>
using namespace std;
struct node {        //Create self referential structure with 2 pointers for each node
    int data;        //data denotes the value present in a node
    struct node* left;
    struct node* right;
};
 
struct node* CreateNode(int data)//This function creates a subtree with left and right nodes for every node
{
    struct node* temp = new struct node;
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
};
 int sumatlevelk(struct node* root,int k)//This is a slight modification of BFS 
{ 
    if (root == NULL)//if tree is empty
        return 0;
    queue<struct node*> que;
    que.push(root);//Push the root inside the queue
    int level = 0;//This denotes the level that will be updated at every iteration
    int sum = 0;//Initialize the sum
    int f = 0;
    while (!que.empty()) {//Loop until queue is empty
        int size = que.size();
        for(int i=0;i<size;++i){
            struct node* ptr = que.front();//Record the node  at front
            que.pop();//Pop it to process the nodes in the next level
            if (level == k) {//If the level matches k
                f = 1;       
                sum += ptr->data;//Increment sum
            }
            else {
                if (ptr->left)//If left node exists
                    que.push(ptr->left);//Put it in queue as it acts as the root node for left subtree
                if (ptr->right)//If right node exists
                    que.push(ptr->right);//Push it in queue as it acts as root node for right subtree
            }
        }
        level++;//Increment level when the nodes of a particular level are processed
        if (f == 1)
            break;
    }
    return sum;
}
int main()
{
    struct node* root = new struct node;
    cout<<"Enter level at which you want to get the sum"<<'\n';
    int k;
    cin>>k;
    root = CreateNode(50);
    root->left = CreateNode(30);
    root->right = CreateNode(70);
    root->left->left = CreateNode(20);
    root->left->right = CreateNode(40);
    root->right->left = CreateNode(60);
    int ans = sumatlevelk(root, k);
    cout << ans;
 
    return 0;
}