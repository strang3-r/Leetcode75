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
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        
        vector<vector<int>>ans;
        if(matrix.size()<1)return ans;
        vector<vector<int>>pacific(matrix.size(),vector<int>(matrix[0].size(),0));
        vector<vector<int>>atlantic(matrix.size(),vector<int>(matrix[0].size(),0));
        
        for(int col=0;col<matrix[0].size();col++)
        {
            fnc(matrix,0,col,INT_MIN,pacific);
            fnc(matrix,matrix.size()-1,col,INT_MIN,atlantic);
            
        }
        
        for(int row = 0;row<matrix.size();row++)
        {
             fnc(matrix,row,0,INT_MIN,pacific);
            fnc(matrix,row,matrix[0].size()-1,INT_MIN,atlantic);
        }
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(pacific[i][j]==1 && atlantic[i][j]==1)
                {
                    vector<int>v(2);
                    v[0]=i;
                    v[1]=j;
                    ans.push_back(v);
                }
            }
        }
        
        
        
        return ans;
    }
    
    void fnc(vector<vector<int>>& matrix,int i, int j,int prev,vector<vector<int>>& ocean)
    {
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size())
            return;
        if(ocean[i][j]==1)
            return;
        if(matrix[i][j]<prev)
            return;
        
        ocean[i][j]=1;
        
        fnc(matrix,i+1,j,matrix[i][j],ocean); 
        fnc(matrix,i-1,j,matrix[i][j],ocean);
        fnc(matrix,i,j+1,matrix[i][j],ocean);
        fnc(matrix,i,j-1,matrix[i][j],ocean);    
        
        
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