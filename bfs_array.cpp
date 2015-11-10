#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
	int v, e;
	cout << "Vertices: ";
	cin >> v;
	cout << endl;
	cout << "Edges: ";
	cin >> e;
	cout << endl;
	
	int arr[v+1][v+1];
	
	for(int i=0;i<=v;i++)
	{
		for(int j=0;j<=v;j++)
		{
			arr[i][j] = 0;
			
		}
	}
	
	for(int i=0;i<e;i++)
	{
		// Weighted (directed or undirected). C is the weight of each edge
		int a, b;
		cin >> a >> b;
		
		arr[a][b] = 1;
		//~ arr[b][a] = 1;
	}
	
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	
	int visited[v+1];
	int dist[v+1];
	
	for(int i=0;i<=v;i++)
	{
		visited[i] = 0;
		dist[i] = INT_MAX;
	}
	
	int q[v];
	for(int i=0;i<v;i++)
	{
		q[i] = 0;
	}
	
	int top = 0;
	int bot = 0;
	
	int st;
	
	cout << "Start vertex: ";
	cin >> st;
	cout << endl;
	
	visited[st] = 1;
	// push to queue
	q[top] = st;
	top++;
	cout << st << " ";
	
	dist[st] = 0;
	
	while(top!=bot)
	{
		// pop from queue
		int k = q[bot];
		bot++;
		
		for(int i=1;i<=v;i++)
		{
			if(visited[i]==0 && arr[k][i]!=0)
			{
				visited[i] = 1;
				cout << i << " ";
				
				dist[i] = dist[k]+arr[k][i];
				
				q[top] = i;
				top++;
			}
		}
		
	}
	cout << endl;
	
	for(int i=1;i<=v;i++)
	{
		cout << dist[i] << " ";
	}
}
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

		
	
