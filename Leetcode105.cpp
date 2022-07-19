#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ff                 first
#define ss                 second
#define endl               "\n"
#define ll                 long long
#define ld                 long double
#define loop(a, b, c)      for(ll (a) = (b); (a)<=(c); (a)++)
#define looprev(a, b, c)   for(ll (a) = (b); (a)>=(c); (a)--)
#define pb                 push_back
#define mp                 make_pair
#define pii                pair<ll, ll>
#define vi                 vector<ll>
#define mii                map<ll, ll>
#define pqb                priority_queue<ll>
#define pqs                priority_queue<int, vi, greater<ll> >
#define setbits(x)         __builtin_popcountll(x)
#define zrobits(x)         __builtin_ctzll(x)
#define mod                1000000007
#define inf                1e18
#define ps(x, y)           fixed<<setprecision(y)<<x
#define mk(arr,n,type)     type *arr = new type[n];
#define w(t)               int x; cin>>x; while(x--)
// mt19937                    rng(chrono::steady_clock::now,time_since_epoch(),count());
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

    
void file_i_o(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	/* #ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif */
}




  // Definition for a binary tree node.
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:


	TreeNode* buildT(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> inMap){
		if(preStart > preEnd or inStart > inEnd) return NULL;
		TreeNode* root = new TreeNode(preorder[preStart]);

		int inRoot = inMap[root->val];
		int numLeft = inRoot - inStart;

		root->left = buildT(preorder, preStart+1, preStart+numLeft, inorder, inStart, inRoot-1, inMap);
		root->right = buildT(preorder, preStart+numLeft+1, preEnd, inorder, inRoot+1, inEnd, inMap);

		return root;
	}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
     	map<int, int> inMap;

     	for(int i = 0; i < inorder.size(); i++){
     		inMap[inorder[i]] = i;
     	}   

     	TreeNode* root = buildT(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);

     	return root;
    }

};



int main(int argc, char const *argv[])
{

	file_i_o();

	clock_t start, end;
    start = clock();

	w(t){

	/* Write Code Here */
	

	}

	end = clock();
	
	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cerr<<"\nTime : "<<fixed<<time_taken<<setprecision(5)<<" s \n";
    cerr<<"\n" << "Coded By S!r Black-D3vil" <<"\n";

	return 0;
}