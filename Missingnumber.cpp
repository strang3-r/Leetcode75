#include <iostream>
using namespace std;

int findMissingNo (int arr[], int len){
   int temp;  
   temp  = ((len+1)*(len+2))/2;  
   for (int i = 0; i<len; i++)    
      temp -= arr[i];  
   return temp;
}

int main() {
   int n;   
   cin>>n;    
   int arr[n-1];    
   for(int i=0; i<n; i++){    
      cin>>arr[i];  
   } 
   int missingNo = findMissingNo(arr,5); 
   cout<<"Missing Number is: "<<missingNo;
   return 0;
}
