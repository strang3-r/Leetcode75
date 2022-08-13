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

unordered_map<int, vector<int>> m;
int MOD = 1e9+7;

public:

	int helper(int n, int i, char prev, vector<vector<long long>> &dp) {
		if(i > n) return 0;

		if(i == n) {
			switch(prev) {
				case 'a' :
					return 1;
				case 'e' :
					return 2;
				case 'i' :
					return 4;
				case 'o' :
					return 2;
				case 'u' :
					return 1;
				default :
					return 5;
			}
		}

		int idx = prev - 'a';

		if(dp[i][idx] != -1) {
			return dp[i][idx];
		}

		long long ans = 0;
		for(auto next : m[prev]) {
			ans += helper(n, i+1, next, dp) %MOD;
		}

		return dp[i][idx] = ans%MOD;

	}

    int countVowelPermutation(int n) {
        m['c'] = {'a', 'e', 'i', 'o', 'u'};
        m['a'] = {'e'};
        m['e'] = {'a', 'i'};
        m['i'] = {'a', 'e', 'o', 'u'};
        m['o'] = {'i', 'u'};
        m['u'] = {'a'};

        vector<vector<long long>> dp(vector<vector<long long>>(n+2, vector<long long>(27, -1)));

        return helper(n, 1, 'c', dp);
    }
};





int main(int argc, char const *argv[]) {

	file_i_o();

	clock_t start, end;
    start = clock();


    int n;
    cin >> n;

    Solution result;

    cout << result.countVowelPermutation(n) << endl;



	end = clock();
	
	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cerr<<"\nTime : "<<fixed<<time_taken<<setprecision(5)<<" s \n";
    cerr<<"\n"<< "Coded By : S!r Black-D3vil" <<"\n";

	return 0;
}