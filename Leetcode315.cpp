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

	// Merge Sort


	void merge(vector<pair<int, int>> &arr, vector<int>&count, int l, int mid, int r) {
		vector<pair<int, int>> temp(r-l+1);

		int i = l, j = mid+1, k = 0;

		while(i <= mid and j <= r) {
			if(arr[i].first <= arr[j].first)
				temp[k++] = arr[j++];
			else {
				count[arr[i].second] += r-j+1;
				temp[k++] = arr[i++];
			}
		}

		while(i <= mid) {
				temp[k++] = arr[i++];
		}
		while(j <= r) {
			temp[k++] = arr[j++];
		}

		for(int x = l; x <= r; x++) {
			arr[x] = temp[x-l];
		}
	}



	void merge_sort(vector<pair<int, int>> &arr, vector<int> &count, int l, int r) {
		if(l >= r) {
			return;
		}

		int mid = (l+r)/2;
		merge_sort(arr, count, l, mid);
		merge_sort(arr, count, mid+1, r);
		merge(arr, count, l, mid, r);

	}



    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++){
        	arr[i] = {nums[i], i};
        }
        vector<int> count(n, 0);
        merge_sort(arr, count, 0, n-1);

        return count;
    }
};





int main(int argc, char const *argv[]) {

	file_i_o();

	clock_t start, end;
    start = clock();

	
    /*int n;
    cin >> n;

    vector<int> nums;

    for(int i = 0; i < n; i++){
    	cin >> nums[i];
    }

    Solution ans;

    vector<int> result;

    for(int i = 0; i < n; i++){
    	result[i] = ans.countSmaller(nums);
    }

    for(int i = 0; i < n; i++){
    	cout << result[i] << endl;
    }*/


	end = clock();
	
	double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
    cerr<<"\nTime : "<<fixed<<time_taken<<setprecision(5)<<" s \n";
    cerr<<"\n"<< "Coded By : S!r Black-D3vil" <<"\n";

	return 0;
}