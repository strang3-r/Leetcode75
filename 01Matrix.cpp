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
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       	queue<pair<int,int>> q;

       	vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), -1));

       	for(int i = 0; i < mat.size(); i++) {
       		for(int j = 0; j < mat[0].size(); j++) {
       			if(mat[i][j] == 0) {
       				q.push({i, j});
       				ans[i][j] = 0;
       			}
       		}
       	}

       	int m = mat.size();
       	int n = mat[0].size();

       	while(not q.empty()) {
       		int i = q.front().first;
       		int j = q.front().second;

       		if(checkvalid(i+1, j, m, n) and ans[i+1][j] == -1) {
       			q.push({i+1, j});
       			ans[i+1][j] = ans[i][j]+1;
       		}

       		if(checkvalid(i-1, j, m, n) and ans[i-1][j] == -1) {
       			q.push({i-1, j});	
       			ans[i-1][j] = ans[i][j]+1;
       		}

       		if(checkvalid(i, j+1, m, n) and ans[i][j+1] == -1) {
       			q.push({i, j+1});	
       			ans[i][j+1] = ans[i][j]+1;
			}

       		if(checkvalid(i, j-1, m, n) and ans[i][j-1] == -1) {
       			q.push({i, j-1});	
       			ans[i][j-1] = ans[i][j]+1;
       		}

       		q.pop();
       	}

       	return ans;

    }

    bool checkvalid(int i, int j, int m, int n) {
    	if(i < 0 or j < 0 or i >= m or j >= n) return false;

    	return true;
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
