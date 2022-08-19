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
    int calculate(string s) {
  		int len = s.length();
  		if(len == 0) return 0;
  		int curNum = 0, lastNum = 0, result = 0;
  		char sign = '+';
  		for(int i = 0; i < len; i++) {
  			char curChar = s[i];
  			if(isdigit(curChar)) {
  				curNum = (curNum*10) + (curChar - '0');
  			}
  			if(not isdigit(curChar) and not iswspace(curChar) or i == len - 1) {
  				if(sign == '+' or sign == '-') {
  					result += lastNum;
  					lastNum = (sign == '+') ? curNum : -curNum;
  				}
  				else if(sign == '*'){
  					lastNum = lastNum * curNum;
  				}
  				else if(sign == '/') {
  					lastNum = lastNum / curNum;
  				}

  				sign = curChar;
  				curNum = 0;
   			}
  		}      

  		result += lastNum;
  		cerr << result << endl;
  		return result;
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