#include <iostream>
using namespace std;
int bin_search(int arr[],int n, int s){
    int mid=n/2;
    int temp[mid];
    if (arr[mid]==s){
        cout<<"Element found at position "<<mid+1;
    }
    else if(mid<n/2){
        for(int i=0; i<mid+1; i++){
            temp[i]==arr[i]
        }
    }
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>s;
    bin_search(arr,n,s);
}
