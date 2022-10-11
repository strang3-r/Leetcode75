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




/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

/*
bool isOverlap(int  &minS, int &maxE, vector<int> &intervals) {
	if(minS > intervals[1] or maxE < intervals[0]) {
		return false;
	}
	return true;
}



vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals) {
    // Write your code here.

	int n = intervals.size();

	vector<vector<int>> res;
	vector<bool> vis(n, false);

	for(int i = 0; i < n; i++) {
		if(vis[i]) {
			continue;
		}
		
		vis[i] = true;

		int minS = intervals[i][0];
		int maxE = intervals[i][1];

		while(true) {
			int cnt = 0;

			for(int j = 0; j < n; j++) {
				if(not vis[j] and isOverlap(minS, maxE, intervals[j])) {
					vis[j] = true;
					minS = min(minS, intervals[j][0]);
					maxE = max(maxE, intervals[j][1]);
					cnt++;
				}

			}

			if(cnt == 0) break;


		}

		vector<int> interval = {minS, maxE};
		res.push_back(interval);

	}

	sort(res.begin(), res.end());

	return res;

}*/


// Optimized Approach


vector<vector<int> > mergeIntervals(vector<vector<int>> &intervals) {
	int n = intervals.size();

	sort(intervals.begin(),intervals.end());

	vector<vector<int> > res;

	for(int i = 0; i < n; i++) {
		int curS = intervals[i][0];
		int curE = intervals[i][1];

		if(res.size() == 0 or curS > res[res.size()-1][1])
			res.push_back(intervals[i]);
		else 
			res[res.size() - 1][1] = max(res[res.size() - 1][1], curE);
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