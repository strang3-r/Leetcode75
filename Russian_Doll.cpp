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

// Bruteforce Approach

/*int helper(vector<int> &height, vector<int> &width, int n, int &maxHeight, int &maxWidth) {
	int maxEnvelopes = 0;

	// Recursively try to find all way to russian doll envelope inside it
	for(int i = 0; i < n; i++) {
		if(height[i] < maxHeight and width[i] < maxWidth) {
			maxEnvelopes = max(maxEnvelopes, 1 + helper(height, width, n, height[i], width[i]));
		}

	} 

	return maxEnvelopes;
}


int findMaxEnvelopes(vector<int> &height, vector<int> &width, int n) {
    // Write your code here.

	// Maximum height and width of envelopes that can be placed
	int maxHeight = INT_MAX;
	int maxWidth = INT_MAX;

	// recursively find maximum number of envelopes that can russian doll

	return helper(height, width, n, maxHeight, maxWidth);

}*/



// DP Approach


/*int findMaxEnvelopes(vector<int>&height, vector<int>&width, int n){

    vector<vector<int>> envelopes(n, bector<int>(2));

    for(int i = 0; i < n; i++){

       envelopes[i][0] = height[i];
       envelopes[i][1] = width[i];

    }

    sort(envelopes.begin(),envelopes.end(), [](vector<int> &v1, vector<int> &v2) -> bool {
    	if(v1[0] < v2[0] or (v1[0] == v2[0] and v1[1] > v2[1])) {
    		return true;
    	}
    	return false;
    });

    vector<int> maxEnvelopes(n);

    int res = 0;

    for(int i = 1; i < n; i++){
    	maxEnvelopes[i] = 1;
         for(int j = i-1; j >= 0; j--){

             if(envelopes[i][1] > envelopes[j][1]){

             	maxEnvelopes[i] = max(maxEnvelopes[i], maxEnvelopes[j]+1);

            }

            result = max(result, maxEnvelopes[i]);

        }
    }

    return result;

}*/



// Approach 3 Dynamic Programming and Binary Search

/*
    Time Complexity     :   O(N * log(N))
    Space Complexity    :   O(N)

    Where 'N' is the number of envelopes.
*/


int longestIncreasingSubsequence(vector<int> &arr, int n) {

    // Here tail[i] will be last element of incresing sequence of length 'i'.
    vector<int> tail(n);
    
    tail[0] = arr[0];
    int length = 1;
    
    for(int i = 1; i < n; i++) {
    
        // Binary search to find position in 'tail' array.
        int j = lower_bound(tail.begin(), tail.begin() + length, arr[i]) - tail.begin();
        
        if(j == length) {
            tail[length++] = arr[i];
        }
        else {
            tail[j] = arr[i];
        }
    }

    return length;
}

int findMaxEnvelopes(vector<int> &height, vector<int> &width, int n) {
    
    // Store height and width of each envelop in matrix 'envelopes'.
    vector<vector<int>> envelopes(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        envelopes[i][0] = height[i];
        envelopes[i][1] = width[i];
    }

    // Sort matrix 'envelopes' in increasing order of their height and if height are equal then arrange in decreasing order of width.
    sort(envelopes.begin(), envelopes.end(), [](vector<int> &v1, vector<int> &v2)->bool{
        if(v1[0] < v2[0] or (v1[0] == v2[0] and v1[1] > v2[1])) {
            return true;
        }
        return false;
    });

    // Copy second column of matrix 'envelopes' after sorting.
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        arr[i] = envelopes[i][1];
    }

    return longestIncreasingSubsequence(arr, n);
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