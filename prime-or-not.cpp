#include <iostream>  

using namespace std;  

int main()  

{  

  int n, i, m=0, flag=0;  

  cout << "Enter the Number to check Prime: ";  

  cin >> n;  

  m=n/2;  

  for(i = 2; i <= m; i++)  

  {  

      if(n % i == 0)  

      {  

          cout<<"Number is not Prime."<<endl;  

          flag=1;  

          break;  

      }  

  }  

  if (flag==0)  

      cout << "Number is Prime."<<endl;  

  return 0;  

}  


// Efficient approach based on Sieve of Eratosthenes to check for multiple numbers if they are prime or not
vector<bool> sieve;
void prime(int n){
    sieve.resize(n+1,true);
    sieve[0]=sieve[1]=false;
    for(int i=2;(long long)i*i<=n;++i){
        if(sieve[i])
            for(int j=i*i;j<=n;j+=i)
                sieve[j]=false;
    }
}

int main{
  cout<<"Enter total numbers you wanted to check for prime: ";
  int t;
  cin>>t;

  // Initialise the sieve upto the maximum number
  prime(100005);
  while(t--){
    int n;
    cin>>n;
    if(sieve[n]==true)
      cout<<"Number "<<n<<" is prime\n";
    else
      cout<<"Number "<<n<<" is not prime\n";
  }

  return 0;
}