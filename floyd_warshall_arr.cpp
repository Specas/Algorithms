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


int main()
{
	
	int v,e;
	
	cout << "Vertices: ";
	cin >> v;
	cout << endl;
	
	cout << "Edges: ";
	cin >> e;
	cout << endl;
	
	int w[v][v];
	
	// initializing
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			w[i][j] = 9999;
			if(i==j)
			{
				w[i][j] = 0;
			}
		}
	}
	
	
	for(int i=0;i<e;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		
		w[a][b] = c;
	}
	
	int dist[v][v];
	
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			dist[i][j] = w[i][j];
		}
	}
	
	for(int k=0;k<v;k++)
	{
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<v;j++)
			{
				if(dist[i][k]+dist[k][j]<dist[i][j])
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	
	
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			if(dist[i][j]==9999)
			{
				cout << "INF ";
			}
			else
			{
				cout << dist[i][j] << " ";
			}
		}
		cout << endl;
	}
}
	

	
	
	
	
	
	
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
