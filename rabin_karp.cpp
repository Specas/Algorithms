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

void rabinKarp(string pat, string txt, int q, int d)
{
	int m = pat.length();
	int n = txt.length();
	
	int p = 0;
	int t = 0;
	int h = 1;
	int i,j;
	
	for(int i=0;i<m-1;i++)
	{
		h = (h*d)%q; // This is used later to compute the next string number in constant time
	}
	
	// initial preprocess
	for(int i=0;i<m;i++)
	{
		p = (d*p + pat[i])%q;
		t = (d*t + txt[i])%q;
	}
	
	for(i=0;i<=n-m;i++)
	{
		if(p==t)
		{
			// Need to check if it is a spurious hit
			for(j=0;j<m;j++)
			{
				if(txt[i+j]!=pat[j])
				{
					break;
				}
			}
			
			if(j==m)
			{
				cout << "Pattern found at index: "<< i << endl;
			}
		}
		
		if(i<n-m)
		{
			t = (d*(t-txt[i]*h)+txt[i+m])%q; // calculating the next sequence in constant time
			if(t<0)
			{
				t = t+q;
			}
		}
	}
}
					
			
			

int main()
{
	string t,p;
	cout << "Enter the main string: ";
	cin >> t;
	cout << endl;
	
	cout << "Enter the pattern: ";
	cin >> p;
	cout << endl;
	
	rabinKarp(p, t, 101, 256);
	
}
