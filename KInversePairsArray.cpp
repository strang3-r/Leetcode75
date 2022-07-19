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


//Top Down Method

// class Solution {
// public:

// 	int dp[1001][1001] = {};

//     int kInversePairs(int n, int k) {
//         if(k <= 0) return k == 0;
//         if(dp[n][k] == 0){
//         	dp[n][k] = 1;
//         	for(auto i = 0; i < n; i++){
//         		dp[n][k] = (dp[n][k] + kInversePairs(n-1, k-i))%mod;
//         	}
//         }

//         return dp[n][k] - 1;
//     }
// };


// Bottom Up Method


class Solution {
public:

	int dp[1001][1001] = {};

	int kInversePairs(int n, int k) {
		int dp[1001][1001] = {1};
		for(int N = 1; N <= n; N++){
			for(int K = 0; K <= k; K++){
				for(int i = 0; i <= min(,K N-1); i++){
					dp[N][k] = (dp[N][K] + dp[N-1][K-i])%mod;
				}
			}
		}

		return dp[n][k];
	}

};




int main(int argc, char const *argv[])
{

	file_i_o();

	clock_t start, end;
    start = clock();

	w(t){

	/*  Write Code Here  */

	}

	end = clock();
	
	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cerr<<"\nTime : "<<fixed<<time_taken<<setprecision(5)<<" s \n";
    cerr<<"\n"<<"Coded By S!r Black-D3vil" <<"\n";

	return 0;
}