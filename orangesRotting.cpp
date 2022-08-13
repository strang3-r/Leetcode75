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
    int orangesRotting(vector<vector<int>>& grid) {
     	if(grid.empty()) return 0;

     	int m = grid.size(), n = grid[0].size(), days = 0, tot = 0, cnt = 0;

     	queue<pair<int, int>> rotten;

     	for(int i = 0; i < m; i++) {
     		for(int j = 0; j < n; j++) {
     			if(grid[i][j] != 0) tot++;
     			if(grid[i][j] == 2) rotten.push({i, j});
     		}
     	}   

     	int dx[4] = {0, 0, 1, -1};
     	int dy[4] = {1, -1, 0, 0};

     	while(not rotten.empty()) {
     		int k = rotten.size();

     		cnt += k;

     		while(k--) {
     			int x = rotten.front().first;
     			int y = rotten.front().second;
     			rotten.pop();

     			for(int i = 0; i < 4; i++) {
     				int nx = x + dx[i];
     				int ny = y + dy[i];
     				if(nx < 0 or ny < 0 or nx >= m or ny >= n or grid[nx][ny] != 1) continue;
     				grid[nx][ny] = 2;
     				rotten.push({nx, ny});
     			}

     		}

     		if(not rotten.empty()) days++;
     	}

     	return tot == cnt ? days : -1;
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