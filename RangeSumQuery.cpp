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







class NumArray {
public:

	int n;
	vector<int> seg;


	int build(const vector<int> &nums, int left, int right, int node){
		int middle;
		int leftSum, rightSum;

		if(left == right) return seg[node] = nums[left];

		middle = (left + right) / 2;

		leftSum = build(nums, left, middle, 2*node+1);
		rightSum = build(nums, middle+1, right, 2*node+2);

		return seg[node] = leftSum + rightSum;
	}



	int sumRange(int left, int right, int ss, int se, int node) {
	int leftSum;
	int rightSum;

	int middle;

	if(right < ss or left > se) return 0;
	if(left <= ss and se <= right) return seg[node];

	middle = (ss+se)/2;

	leftSum = sumRange(left, right, ss, middle, 2*node+1);
	rightSum = sumRange(left, right, middle+1, se, 2*node+2);

	return leftSum+rightSum;
}


int update(int index, int newVal, int ss, int se, int node) {
	int leftSum;
	int rightSum;
	int middle;

	if(index < ss or index > se) return seg[node];
	if(ss == se) return seg[node] = newVal;

	middle = (ss+se)/2;

	leftSum = update(index, newVal, ss, middle, 2*node+1);
	rightSum = update(index, newVal, middle+1, se, 2*node+2);

	return seg[node] = leftSum+rightSum;
}



    NumArray(vector<int>& nums) {
   		n = nums.size();
   		seg.resize(4*n);
   		build(nums, 0, n-1, 0);     
    }
    
    void update(int index, int val) {
        update(index, val, 0, n-1, 0);
    }
    
    int sumRange(int left, int right) {
        return sumRange(left, right, 0, n-1, 0); 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */






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