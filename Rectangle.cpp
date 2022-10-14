/*Divide the stick in 4 parts codeforces "Pasha and Stick" problem.
Note
There is only one way to divide the stick in the first sample {1, 1, 2, 2}.

Four ways to divide the stick in the second sample are {1, 1, 9, 9}, {2, 2, 8, 8}, {3, 3, 7, 7} and {4, 4, 6, 6}. Note that {5, 5, 5, 5} doesn't work.




EXAMPLE:-
INPUT 1:
6

OUTPUT 1:
1   //divide like(1, 1, 2, 2)

INPUT 2:
20

OUTPUT:
4   //divide like {1, 1, 9, 9}, {2, 2, 8, 8}, {3, 3, 7, 7}, {4, 4, 6, 6}


stick = l+l+b+b
stick = 2(l+b)
stick/2 = l+b

*/



//SOLUTION 1:
#include <bits/stdc++.h>
using namespace std;

int main()
{
	long int n;
	cin>>n;

	if(n%2==1) // here by default is 1. Not needed to write ==1
	{
		cout<<0;
	}
	n=n/2;

	if(n%2==1) // here by default is 1. Not needed to write ==1
	{
		cout<<n/2;
	}
	else
	{
		cout<<n/2-1;
	}




	return 0;
}


/* 
//SOLUTION 2:

#include <stdio.h>

int main(){
	int i, n, p, k;
	long t;
	
	scanf("%ld", &t);
	if(t%2 !=0){
		printf("0\n");
	}
	else{
		if(t%4==0){
			printf("%ld\n", (t/4)-1);
		}
		else printf("%ld\n", t/4);
	}
	
	return 0;
}
*/
