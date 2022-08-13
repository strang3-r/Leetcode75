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





/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:


	  ListNode* sortList(ListNode* head) {
        if(head == NULL || head ->next == NULL)
            return head;
        
        
        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        
        //middle of linked list
        while(fast !=  NULL && fast -> next != NULL){
            temp = slow;
            slow = slow->next;          
            fast = fast ->next ->next;  
            
        }   
        temp -> next = NULL;            
        
        ListNode* l1 = sortList(head);  //2   
        ListNode* l2 = sortList(slow);  //1 
        
        return mergeTwoLists(l1, l2);         
            
    }

    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
  		ListNode* fh = nullptr;
  		ListNode* ft = nullptr;

  		while(head1 != nullptr and head2 != nullptr) {

  			if(fh == nullptr and ft == nullptr) {

	  			if(head1 -> val > head2 -> val) {
	  				fh = head2;
	  				ft = head2;
	  				head2 = head2 -> next;
	  			}
	  			
	  			else {
	  				fh = head1;
	  				ft = head1;
	  				head1 = head1 -> next;
	  			}

  			}

  			if(head1 and head2) {
  				
	  			if(head1 -> val < head2 -> val) {
	  				ft -> next = head1;
	  				ft = ft -> next;
	  				head1 = head1 -> next;
	  			}

	  			else {
	  				ft -> next = head2;
	  				ft = ft -> next;
	  				head2 = head2 -> next;
	  			}
  			}

  		}

  		if(head1 != nullptr) ft -> next = head1;
  		if(head2 != nullptr) ft -> next = head2;

  		return fh;

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