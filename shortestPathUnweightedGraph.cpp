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





vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
	
	vector<int> ADJ[n+1];

	for(int i = 0; i < m; i++){
		int x, y;
		x = edges[i].first;
		y = edges[i].second;
		ADJ[x].push_back(y);
		ADJ[y].push_back(x);
	}


	vector<int> visited(n+1, -1);
	vector<int> parent(n+1, -1);

	visited[s] = 1;

	queue<int> Q;

	Q.push(s);

	while(Q.size() > 0) {
		int curNode = Q.front();
		Q.pop();

		for(int nextNode : ADJ[curNode]) {
			if(visited[nextNode] == -1) {
				visited[nextNode] = 1;
				Q.push(nextNode);
				parent[nextNode] = curNode;
			}
		}
	}

	vector<int> path;
	int currentNode = t;

	path.push_back(t);

	while(currentNode != s) {
		currentNode = parent[currentNode];
		path.push_back(currentNode);
	}

	// path.push_back(s);

	reverse(path.begin(), path.end());

	return path;

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