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
	bool able(string s,string t){
	    if(s.length()!=t.length())
	        return false;
	    int c=0;
	    for(int i=0;i<s.length();i++)
	        c+=(s[i]!=t[i]);
	    return c==1;
	}
	void bfs(vector<vector<int>> &g,vector<int> parent[],int n,int sr,int ds){
		vector <int> dist(n,1005);
		queue <int> q;
		q.push(sr);
		parent[sr]={-1};
		dist[sr]=0;
		while(!q.empty()){
		    int x=q.front();
		    q.pop();
		    for(int u:g[x]){
		        if(dist[u]>dist[x]+1){
		            dist[u]=dist[x]+1;
		            q.push(u);
		            parent[u].clear();
		            parent[u].push_back(x);
		        }
		        else if(dist[u]==dist[x]+1)
		            parent[u].push_back(x);
		    }
		}
	}
	void shortestPaths(vector<vector<int>> &Paths, vector<int> &path, vector<int> parent[],int node){
	    if(node==-1){
	        Paths.push_back(path);
	        return ;
	    }
	    for(auto u:parent[node]){
	        path.push_back(u);
	        shortestPaths(Paths,path,parent,u);
	        path.pop_back();
	    }
	}
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size(),sr=-1,ds=-1;
        vector<vector<string>> ANS;
        for(int i=0;i<n;i++){
            if(wordList[i]==beginWord)
                sr=i;
            if(wordList[i]==endWord)
                ds=i;
        }
        if(ds==-1)
            return ANS;
        if(sr==-1){
            wordList.emplace(wordList.begin(),beginWord);
            sr=0;
            ds++;
            n++;
        }
        vector <vector<int>> g(n,vector<int>()),Paths;
        vector <int> parent[n],path;
        for(int i=0;i<n-1;i++)
            for(int j=i+1;j<n;j++)
                if(able(wordList[i],wordList[j])){
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
        bfs(g,parent,n,sr,ds); 
        shortestPaths(Paths,path,parent,ds);
        for(auto u:Paths){
            vector <string> now;
            for(int i=0;i<u.size()-1;i++)
                now.push_back(wordList[u[i]]);
            reverse(now.begin(),now.end());
            now.push_back(wordList[ds]);
            ANS.push_back(now);
        }
        return ANS;
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