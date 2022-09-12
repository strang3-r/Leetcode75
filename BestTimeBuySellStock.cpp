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




class Solution {
public:
	int findMaxProfit(int i, int canBuy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp) {
		if(k == 0) return 0;
		if(i == prices.size()) return 0;

		int maxProfit = 0;

		if(dp[i][canBuy][k] != -1) return dp[i][canBuy][k];

		if(canBuy) {
			int buy = -prices[i] + findMaxProfit(i+1, 0, k, prices, dp);
			int notBuy = 0 + findMaxProfit(i+1, 1, k, prices, dp);
			maxProfit = max(buy, notBuy);
		}
		else {
			int sell = prices[i] + findMaxProfit(i+1, 1, k-1, prices, dp);
			int notSell = 0 + findMaxProfit(i+1, 0, k, prices, dp);
			maxProfit = max(sell, notSell);
		}

		return maxProfit;
	}

    int maxProfit(int k, vector<int>& prices) {
    	vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
    	return findMaxProfit(0, 1, k, prices, dp);
    }
};



class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
		int n = prices.size();
		int tt = k;

		vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

		for(int i = n-1; i >= 0; i--) {
			for(int canBuy = 0; canBuy <= 1; canBuy++) {
				for(int k = 1; k <= tt; k++) {
					int maxProfit = 0;
					if(canBuy) {
						int buy = -prices[i] + dp[i+1][0][k];
						int notBuy = 0 + dp[i+1][1][k];
						maxProfit = max(buy, notBuy);
					}
					else {
						int sell = prices[i] + dp[i+1][1][k-1];
						int notSell = 0 + dp[i+1][0][k];
						maxProfit = max(sell, notSell);
					} 
					dp[i][canBuy][k] = maxProfit;
				}
			}
		}  

		return dp[0][1][tt];  
    }
};




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
