#include <iostream>
#include <cstdio>

using namespace std;

void sieve(int n)
{
	int a[n+1];
	
	for(int i=0;i<=n;i++)
	{
		a[i] = 1;
	}
	
	for(int i=2;i<=n;i++)
	{
		if(a[i])
		{
			cout << i << " ";
			
			int j=2*i; // or i*i for efficiency
			
			while(j<=n)
			{
				a[j] = 0;
				j+=i;
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	
	sieve(n);
}
			
