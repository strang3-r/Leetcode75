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


int findDuplicate(vector<int> &arr, int n){
	// Write your code here.

	// Approach 1

	/*sort(arr.begin(), arr.end());

	for(int i = 0; i < arr.size(); i++){
		if(arr[i] == arr[i+1])
			return arr[i]; 
	}

	return -1;*/


	// Approach 2 

	/*for(int i = 0; i < arr.size(); i++){
		int idx = abs(arr[i]) - 1;
		if(arr[idx] < 0) {
			return idx + 1;
		}
		else {
			arr[idx] = -1*arr[idx];
		}
	}	

	return -1;*/


	// Hare and Tortoise method

	int tortoise = arr[0];
	int hare = arr[0];

	do {
		// hare pointer move twice as tortoise

		tortoise = arr[tortoise];
		hare = arr[arr[hare]];


	}
	// find the intersection pt of two runners.
	while(tortoise != hare);
		// to find the entrance to the cycle torrtoise begins from start of array
	tortoise = arr[0];
	while(tortoise != hare) {
		// This time both runner move with same speed

		tortoise = arr[tortoise];
		hare = arr[hare];

	} 
	// return the entrance to the cycle
	return hare;

}



int main(int argc, char const *argv[]) {

	file_i_o();

	clock_t start, end;
    start = clock();

	

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
    	cin >> arr[i];
    }

    cout << findDuplicate(arr, n) << endl;



	end = clock();
	
	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cerr<<"\nTime : "<<fixed<<time_taken<<setprecision(5)<<" s \n";
    cerr<<"\n"<< "Coded By : S!r Black-D3vil" <<"\n";

	return 0;
}
