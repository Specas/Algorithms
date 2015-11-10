#include <iostream>


using namespace std;

// undirected graph

int main()
{
	int m,n;
	int i,j;
	int v;
	int k,kk;
	int top = 0;
	
	cout << "Enter the number of vertices" << endl;
	cin >> n;
	
	cout << "Enter the number of edges" << endl;
	cin >> m;

	
	int cost[n+1][n+1];
	int visited[n+1];
	int visit[n+1];
	int sta[n+1];
	
	for(k=0;k<=n;k++)
	{
		for(kk=0;kk<=n;kk++)
		{
			cost[k][kk] = 0;
		}
	}
	
	for(k=0;k<=n;k++)
	{
		visited[k] = 0;
		visit[k] = 0;
	}
	
	cout << "Enter the edges " << endl;
	
	// Adjacency array
	
	for(k=1;k<=m;k++)
	{
		cin >> i >> j;
		cost[i][j] = 1;
		cost[j][i] = 1;

	}
	
	cout << "Enter the initial vertex " << endl;
	cin >> v;
	
	cout << "Order of visited vertices: " << endl;
	
	cout << v << " ";
	visited[v] = 1;
	
	k=1;
	
	while(k<n)
	{
		for(j=n;j>=1;j--)
		{
			if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
			{
				visit[j] = 1;
				sta[top] = j;
				top++;
			}
		}
		

		v = sta[--top];
		cout << v << " ";
		k++;
		visit[v] = 0;
		visited[v] = 1;
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
