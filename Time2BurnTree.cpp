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
#define ump                unordered_map<ll, ll>
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





/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

class customPair {
	public :
		bool foundStart;
		int maxPath;

		customPair(int foundStart, int maxPath) {
			this->foundStart = foundStart;
			this->maxPath = maxPath;
		}
};

int ans = -1;

customPair helper(BinaryTreeNode<int>* root, int start) {
	customPair result = customPair(false, -1);

	if(root == NULL) {
		result.foundStart = false;
		result.maxPath = 0;

		return result;
	}

	customPair leftCall = helper(root -> left, start);
	customPair rightCall = helper(root -> right, start);

	if(root -> data == start) {
		ans = max(leftCall.maxPath, rightCall.maxPath);
		result.foundStart = true;
		result.maxPath = 1;
		return result;
	}

	if(leftCall.foundStart or rightCall.foundStart) {
		ans = max(ans, leftCall.maxPath+rightCall.maxPath);

		if(leftCall.foundStart){
			result.foundStart = true;
			result.maxPath = leftCall.maxPath + 1;
			return result;
		}

		result.foundStart = true;

		result.maxPath  = rightCall.maxPath + 1;

		return result;
	}

	result.foundStart = false;
	result.maxPath = max(leftCall.maxPath, rightCall.maxPath) + 1;

	return result;
}


int timeToBurnTree(BinaryTreeNode<int>* root, int start) {
    // Write your code here

	ans = -1;

	helper(root, start);

	return ans;
    
}





int main(int argc, char const *argv[]) {

	file_i_o();

	clock_t start, end;
    start = clock();

	w(t){

	/*  Write Code Here  */

	}

	end = clock();
	
	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cerr<<"\nTime : "<<fixed<<time_taken<<setprecision(5)<<" s \n";
    cerr<<"\n"<< "Coded By : S!r Black-D3vil" <<"\n";

	return 0;
}