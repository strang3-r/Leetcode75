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


/*vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	

	int n = arr.size();
	int m = queries.size();

	vector<int> result(m, -1);

 	for(int i=0; i < m; i++) {

 		for(int j=0; j < n; j++) {
 			if(arr[j] <= queries[i][1]) {
 				result[i] = max(result[i], arr[j]^queries[i][0]);
 			}
 		}

 	}   

 	return result;
    
}*/



// Optimized Solution

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries) {

// Number of Queries
	int m = queries.size();

	vector<int> result(m, -1);

	// Sort Arr in Non-decreasing order

	sort(arr.begin(), arr.end());

	// Finding answer of each queries

	for(int i = 0; i < m; i++) {
	
		// If answer to rhis query is -1
		if(queries[i][1] < arr[0]) {
			continue;
		}

		int left = 0;
		int right = upper_bound(arr.begin(), arr.end(), queries[i][1]) - arr.begin();
		int ans = 0;
		int cur = 0;

		for(int j = 30; j >= 0; j--) {
			// if jth bit is set in queries[i][0] (i.e 'Xi')
			if(queries[i][0] & (1 << j)) {
				if(not arr[left] & (1 << j)) {
					ans = ans | (1 << j);
					right = lower_bound(arr.begin() + left, arr.end() + right, cur + (1 << j)) - arr.begin();
				}
				else {
					cur = cur | (1 << j);
				}
			}

			else {
				// if jth bit is not set in queries[i][0] (i.e 'Xi')

				if(arr[right - 1] & (1 << j)) {
					ans = ans | (1 << j);
					cur = cur | (1 << j);
					left = lower_bound(arr.begin() + left, arr.end() + right, cur) - arr.begin();
				}
			}
		}

		result[i] = ans;
	}

	return result;

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