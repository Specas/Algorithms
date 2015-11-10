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

// doesnt work

using namespace std;

int modexp(long long int a, long long int b, long long int n)
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
	cout << "Enter the number to be checked for prime: ";
	long long int num;
	cin >> num;
	cout << endl;
	
	long long int k = modexp(2, num-1, num);
	long long int kk = k%num;
	if(k!=kk)
	{
		cout << "Definitely composite" << endl;
	}
	else
	{
		cout << "Hopefully prime" << endl;
	}
}
