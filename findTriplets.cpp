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




vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
 	
 	   // Brute Force Approach

		/*vector<vector<int>> ans;

		sort(arr.begin(), arr.end());

 	   for(int i = 0; i < n-3; i++) {
	 	   	for(int j = i+1; j < n-2; j++) {
	 	   		for(int k = j+1; k < n-1; k++) {
	 	   			if(arr[j] == arr[j+1]) continue;
	 	   			if(arr[i] + arr[j] + arr[k] == k) {
	 	   				vector<int>temp;
	 	   				temp.push_back(arr[i]);
	 	   				temp.push_back(arr[j]);
	 	   				temp.push_back(arr[k]);
	 	   				ans.push_back(temp);
	 	   			}
	 	   		}
	 	   	}
 	   } 

 	return ans;*/


 	sort(arr.begin(), arr.end());

		vector<vector<int>> res;

		for(int i = 0; i < arr.size(); i++) {
			if(i == 0 or (i > 0 and arr[i] != arr[i - 1])) {
				int lo = i+1;
				int hi = arr.size()-1;
				int sum = K - arr[i];

				while(lo < hi) {
					if(arr[lo] + arr[hi] == sum) {
						vector<int> temp;
						temp.push_back(arr[i]);
						temp.push_back(arr[lo]);
						temp.push_back(arr[hi]);
						res.push_back(temp);

						while(lo < hi and arr[lo] == arr[lo+1]) lo++;
						while(lo < hi and arr[hi] == arr[hi-1]) hi--;

						lo++;
						hi--;

					}

					else if(arr[lo] + arr[hi] < sum) lo++;
					else hi--;
				}
			}
		}

		return res;
    
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