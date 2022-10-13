#include<bits/stdc++.h>
using namespace std;

int main()
{	
	int t;
	cin>>t;

	while(t--)
	{

	int n;
	cin>>n;

	int digit_sum=0;
	while(n > 0)
	{
		int last_digit=n%10;
		digit_sum += last_digit;
		n=n / 10;
	}
/* Use can use also the folowing while loop
	while👎
	{
		digit_sum+=n%10;
		n=n/10;
	}

*/
	cout<<digit_sum<<endl;
}
	return 0;
}
