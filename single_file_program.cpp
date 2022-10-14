#include<bits/stdc++.h>
  using namespace std;
   
  int main()
  {
   int tc, n , m, k;
   scanf("%d",&tc);
   while(tc--) {
   scanf("%d %d %d",&n,&m,&k);
   int ar[n+1] = {0};
   int sum = 0,ans = 0 ;
   for(int i = 0; i < n; i++) scanf("%d",&ar[i]);
   for(int i = 0, j = 0; i < n*m; i++) {
   j = i + 1;
   sum = 0;
   if(ar[i%n] <= k){
   ans++;
   sum = ar[i%n] + ar[j%n];
   
  while(j < n*m and sum <= k) {
   ans++;j++;
   sum += ar[j%n];
   }
   }
   }
   cout << ans << endl;
   }
   return 0;
  }