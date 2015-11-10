#include <iostream>

using namespace std;

int hcf(int, int);

int hcf(int a, int b)
{
	if(a%b==0)
	{
		return b;
	}
	
	else
	{
		return hcf(b, (a%b));
	}
}

int main()
{
	int t;
	cin >> t;
	
	while(t--)
	{
		int n;
		cin >> n;
		
		int a[n];
		
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
		}
		
		// The required result is the hcf of all the numbers
		
		// variable to store the current hcf
		int h = a[0];;
		
		for(int i=1;i<n;i++)
		{
			h = hcf(h, a[i]);
			
		}
		
		cout << h << endl;
	}
	return 0;
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		

