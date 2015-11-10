#include <iostream>
#include <algorithm>

using namespace std;

// returns the max value that can be put in a knapstack of capacity max_weight
int knapStack(int max_weight, int weights[], int values[], int n)
{
	int i, j;
	int k[n+1][max_weight+1];
	
	
	// build the table bottom up
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=max_weight;j++)
		{
			if(i==0||j==0)
			{
				k[i][j] = 0;
			}
			else if(weights[i-1]<=j)
			{
				k[i][j] = max(values[i-1] + k[i-1][j-weights[i-1]], k[i-1][j]);
			}
			else
			{
				k[i][j] = k[i-1][j];
			}
		}
		
		
	}
	return k[n][max_weight];
}

int main()
{
	int values[] = {1,2,3,4,5};
	int weights[] = {1,2,3,4,5};
	int max_weight = 13;
	int n = sizeof(values)/sizeof(values[0]);
	cout << knapStack(max_weight, weights, values, n);
	return 0;
}
	
	
	
	
	
	
	
	
	
