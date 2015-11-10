#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>
#include <list>
#include <limits.h>

using namespace std;

int graph[10000][10000];


// Utility function to find the vertex with minimum distance value, from the set of vertices not included in the shortest path tree
int minDistance(int dist[], bool sptSet[], int v)
{
	int min = INT_MAX, min_index;
	
	for(int i=0;i<v;i++)
	{
		if(sptSet[i] == false && dist[i] <= min)
		{
			min = dist[i];
			min_index = i;
		}
	}
	return min_index;
}

// Utility funciton to print the array
void printSolution(int dist[], int v)
{
	cout << "Vertex		Distance from source" << endl;
	for(int i=0;i<v;i++)
	{
		cout << i << "\t" << dist[i] << endl;
	}
}

void dijkstra(int src, int v)
{
	int dist[v];
	
	bool sptSet[v];
	
	for(int i=0;i<v;i++)
	{
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}
	
	dist[src] = 0;
	
	// shortest path
	for(int i=0;i<v-1;i++)
	{
		int u = minDistance(dist, sptSet, v);
		sptSet[u] = true;
		
		for(int j = 0;j<v;j++)
		{
			if(graph[u][j] && dist[u]!=INT_MAX && dist[u]+graph[u][j]<dist[j])
			{
				dist[j] = dist[u] + graph[u][j];
			}
		}
	}
	
	printSolution(dist, v);
}

int main()
{
	int v, e, s;
	cout << "Vertex: ";
	cin >> v;
	cout << endl;
	
	cout << "Edges: ";
	cin >> e;
	cout << endl;
	
	for(int i=0;i<1000;i++)
	{
		for(int j=0;j<1000;j++)
		{
			graph[i][j] = 0;
		}
	}
	
	
	for(int i=0;i<e;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		graph[a][b] = c;
	}
	
	cout << "Starting vertex";
	cin >> s;
	cout << endl;
	
	dijkstra(s, v);
	
	return 0;
}
		



























