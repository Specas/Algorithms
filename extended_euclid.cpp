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

using namespace std;

int x;
int y;
int d;

int extended_euclid(int a, int b)
{
	if(b==0)
	{
		x = 1;
		y=0;
		return a;
	}
	int dd = extended_euclid(b, a%b);
	int xx = x;
	int yy = y;
	
	d = dd;
	x = yy;
	y = xx - (a/b)*yy;
	return d;
	
	
		
}

int main()
{
	cout << "Two numbers: ";
	int a,b;
	cin >> a >> b;
	
	cout << endl;
	
	int ans = extended_euclid(a,b);
	
	cout << ans << endl;
	cout << x << " " << y << endl;
}
