#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <list>
#include <limits.h>
#include <queue>
#include <stack>
#include <vector> 
#include <stdlib.h>

using namespace std;




int modexp(int a, int b, int n)
{
	long long int ans = 1;
	
	while(b>0)
	{
		if(b%2==1)
		{
			ans = (ans*a)%n;
		}
		b = b >> 1;
		a = (a*a)%n;
	}
	return ans;
}

	
	

int main()
{
	//computer a^b(mod n)
	
	cout << "Enter a,b,n: ";
	long long int a, b, n;
	cin >> a >> b >> n;
	cout << endl;
	
	long long int ans = modexp(a,b,n);
	
	cout << ans;
	
}
