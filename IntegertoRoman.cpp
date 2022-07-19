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


class Solution {
public:
    string intToRoman(int num) {
  		string roman = "";

  		while(num >= 1000){
  			roman = roman + "M";
  			num -= 1000;
  		}      

  		if(num >= 900){
  			roman = roman + "CM";
  			num -= 900;
  		}

  		while(num >= 500){
  			roman = roman + "D";
  			num -= 500;
  		}

  		if(num >= 400){
  			roman = roman + "CD";
  			num -= 400;
  		}

  		while(num >= 100){
  			roman = roman + "C";
  			num -= 100;
  		}

  		if(num >= 90){
  			roman = roman + "XC";
  			num -= 90;
  		}

  		while(num >= 50){
  			roman = roman + "L";
  			num -= 50;
  		}

  		if(num >= 40){
  			roman = roman + "XL";
  			num -= 40;
  		}

  		while(num >= 10){
  			roman = roman + "X";
  			num -= 10;
  		}

  		if(num == 9){
  			roman = roman + "IX";
  			num -= 9;
  		}

  		while(num >= 5){
  			roman = roman + "V";
  			num -= 5;
  		}

  		if(num == 4){
  			roman = roman + "IV";
  			num -= 4;
  		}

  		while(num >= 1){
  			roman = roman + "I";
  			num -= 1;
  		}
	    return roman;
    }

};



int main(int argc, char const *argv[])
{

	file_i_o();

	clock_t start, end;
    start = clock();

	
	int num;
	cin >> num;

	Solution s;

	string str = s.intToRoman(num);

	cout << str << endl;

	end = clock();
	
	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cerr<<"\nTime : "<<fixed<<time_taken<<setprecision(5)<<" s \n";
    cerr<<"\n"<< "Coded By S!r Black-D3vil" <<"\n";

	return 0;
}