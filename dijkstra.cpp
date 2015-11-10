#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>
#include <list>
#include <limits.h>

using namespace std;

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
int printSolution(int dist[], int n, int v)
{
	cout << "Vertex		Distance from source" << endl;
	for(int i=0;i<v;i++)
	{
		cout << i << "\t" << dist[i] << endl;
	}
}

void dijkstra(int graph[v][v], int src)
{
	



























