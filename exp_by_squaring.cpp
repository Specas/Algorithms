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

long long int ebs(long long int a, long long int b)
{
	if(b<0)
	{
		return ebs(1/a, -b);
	}
	else if(b==0)
	{
		return 1;
	}
	else if(b==1)
	{
		return a;
	}
	else if(b%2==0)
	{
		return ebs(a*a, b/2);
	}
	else
	{
		return a*ebs(a*a, (b-1)/2);
	}
}

int main()
{
	
	cout << "Enter the two numbers: " << endl;
	
	long long int a,b;
	
	cin >> a >> b;
	
	cout << ebs(a,b);
}
