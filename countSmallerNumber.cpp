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

// Brute Force Approach

/*vector<int>countNumber(int n, vector<int> &arr) {
    // Write your code here.

	vector<int> count(n, 0);

	for(int i = 0; i < n; i++) {
		for(int j = i+1; j < n; j++) {
			if(arr[j] < arr[i])
				count[i]++;
		}
	}

	return count;

}*/


//  Optimize Approach
//  Merge Sort



void merge(vector<vector<int>> &arr1, int si, int ei, int si1, int ei1, vector<int> &ans) {
	int temp = 0;
	int i = si;
	int j = si1;

	int ctr = 0;

	vector<vector<int>>temp1(ei1-si + 5);

	while(i <= ei and j <= ei1) {
		if(arr1[i][0] > arr1[j][0]) {
			temp1[ctr++] =  arr1[j];
			j++;
			temp++;
		}
		else {
			ans[arr1[i][1]] += temp;

			temp1[ctr++] = arr1[i];
			i++;
 		}
	}

	while(i <= ei) {
		ans[arr1[i][1]] += temp;
		temp1[ctr++] =  arr1[i++];
	}

	while(j <= ei1) {
		temp1[ctr++] = arr1[j++];
	}

	for(int i = 0l; i < ctr; i++) {
		arr1[i + si] = temp1[i];
	}
}



void merge_s(vector<vector<int>> &arr1, int l, int r, vector<int> &ans) {
	if(l >= r) {
		return;
	}

	int mid = l + (r-l)/2;

	merge_s(arr1, l, mid, ans);
	merge_s(arr1, mid+1, r, ans);
	merge(arr1, l, mid, mid + 1, r, ans);
}




vector<int>countNumber(int n, vector<int> &arr) {
    // Write your code here.

	vector<vector<int>>arr1(n);

	for(int i = 0; i < n; i++) {
		arr1[i] = {arr[i], i};
	}

	vector<int> ans(n);

	merge_s(arr1, 0, n-1, ans);

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