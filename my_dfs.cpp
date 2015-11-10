#include <iostream>

using namespace std;

int main()
{
	int n,m;
	int v;
	
	cout << "Enter the number of nodes " << endl;
	cin >> n;
	
	cout << "Enter the number of edges " << endl;
	cin >> m;
	
	int cost[n+1][n+1];
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			cost[i][j] = 0;
		}
	}
	
	for(int k=0;k<m;k++)
	{
		int a,b;
		cin >> a >> b;
		cost[a][b] = 1;
		cost[b][a] = 1;
	}
	

	
	int st[n];
	int visited[n+1];
	
	// Initialize to zero
	for(int i=0;i<=n;i++)
	{
		if(i==n)
		{
			visited[i] = 0;
		}
		else
		{
			st[i] = 0;
			visited[i] = 0;
		}
	}
	
	cout << "Enter the inital node " << endl;
	cin >> v;
	
	int top = 0;
	
	st[top] = v;
	top ++;
	
	visited[v] = 1;

	// Non empty stack
	while(top>0) 
	{
		v = st[--top];
		cout << v << " ";
		
			for(int i=1;i<=n;i++)
			{
				if(cost[v][i]==1 && visited[i]==0)
				{
					st[top] = i;
					top++;
					visited[i] = 1;
				}
			}
		
	}
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
