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

void computeLPSArray(string pat, int m, int *lps)
{
	int len = 0;// length of previous longest prefix suffix
	int i;
	
	lps[0] = 0;
	i=1;
	
	while(i<m)
	{
		if(pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len = lps[len-1];
				//dont increment i here
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void kmp(string pat, string txt)
{
	int m = pat.length();
	int n = txt.length();
	
	int *lps = (int *)malloc(sizeof(int)*m);
	
	computeLPSArray(pat, m, lps);
	
	int i = 0; // index for target
	int j = 0; // index for pattern
	
	while(i<n)
	{
		if(pat[j] == txt[i])
		{
			i++;
			j++;
		}
		
		if(j==m)
		{
			cout << "Found pattern at index " << i-j << endl;
			j = lps[j-1];
		}
		
		//mismatch after j matches
		else if(i<n && pat[j]!=txt[i])
		{
			if(j!=0)
			{
				j = lps[j-1];
			}
			else
			{
				i = i+1;
			}
		}
	}
	free(lps);
}
	
	
	
	
	
	
	

int main()
{
	string p,t;
	cout << "Enter the main string: ";
	cin >> t;
	cout << endl;
	
	cout << "Enter the pattern to be matched: ";
	cin >> p;
	cout << endl;
	
	
	kmp(p,t);
	return 0;
		
	
}
