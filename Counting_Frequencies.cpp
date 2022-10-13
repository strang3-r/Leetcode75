// C++ program to count frequencies of
// integers in array using Hashmap

#include <bits/stdc++.h>
using namespace std;

 

void frequencyNumber(int arr[],int size)
{

    // Creating a HashMap containing integer as a key and occurrences as a value:

   unordered_map<int,int>freqMap;
 

  for (int i=0;i<size;i++) {

    freqMap[arr[i]]++;

  }
 

  // Printing the freqMap

  for (auto it : freqMap) {

    cout<<it.first<<" "<<it.second<<endl;

  }
}
 

int main()
{

  int arr[] = {10, 20, 20, 10, 10, 20, 5, 20};

  int size = sizeof(arr)/sizeof(arr[0]);

  frequencyNumber(arr,size);
  
  return 0;
}
