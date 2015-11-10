#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>
#include <list> 
#include <limits.h>

using namespace std;

struct Edge
{
	int src, dest, weight;
};

struct Graph
{
	int v,e;
	
	struct Edge* edge;
};

// creates a graph with v vertices and e edges
struct Graph* createGraph(int v, int e)
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->v = v;
	graph->e = e;
	
	graph->edge = (struct Edge*) malloc(graph->e*sizeof(struct Edge));
	
	return graph;
}

// function to print the solution

void printArr(int dist[], int n)
{
	cout << "Vertex		Distance from source" << endl;
	for(int i=0;i<n;i++)
	{
		cout << i << "\t" << dist[i] << endl;
	}
}


void bellmanFord(struct Graph* graph, int src)
{
	int v = graph->v;
	int e = graph->e;
	int dist[v];
	
	// distances as inifinity initially
	for(int i=0;i<v;i++)
	{
		dist[i] = INT_MAX;
	}
	
	dist[src] = 0;
	
	// relax all edges v-1 times
	for(int i=1;i<=v-1;i++)
	{
		for(int j=0;j<e;j++)
		{
			int u = graph->edge[j].src;
			int v = graph->edge[j].dest;
			int weight = graph->edge[j].weight;
			if(dist[u] != INT_MAX && dist[u]+weight<dist[v])
			{
				dist[v] = dist[u] + weight;
			}
		}
	}
	
	// Check for negative weight cycles
	
	for(int i=0;i<e;i++)
	{
		int u = graph->edge[i].src;
		int v = graph->edge[i].dest;
		int weight = graph->edge[i].weight;
		if(dist[u] != INT_MAX && dist[u]+weight<dist[v])
		{
			cout << "Graph contains a negative weight cycle" << endl;
		}
	}
	
	printArr(dist, v);
	
	return;
}


int main()
{
	int v,e,s;
	
	cout << "Vertex: ";
	cin >> v;
	cout << endl;
	
	cout << "Edges: ";
	cin >> e;
	cout << endl;
	
	struct Graph* graph = createGraph(v, e);
	
	for(int i=0;i<e;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		
		graph->edge[i].src = a;
		graph->edge[i].dest = b;
		graph->edge[i].weight = c;
	}
	
	cout << "Source vertex: ";
	cin >> s;
	cout << endl;
	
	bellmanFord(graph, s);
	
	return 0;
}
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


	
