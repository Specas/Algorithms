#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>
#include <list> 

using namespace std;

class Graph
{
	int v;
	list <int> *adj;
	void dfsutil(int v, bool visited[]);
	
	public:
	
	Graph(int v);
	void addEdge(int v, int w);
	void dfs(int v);
};

Graph::Graph(int v)
{
	this->v = v;
	adj = new list<int>[v];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::dfsutil(int v, bool visited[])
{
	// Mark the current node as visited and print it
	visited[v] = true;
	cout << v << " ";
	
	// Recursion fo all vertices adjacent to this one
	list <int> :: iterator i;
	for(i=adj[v].begin(); i!=adj[v].end(); ++i)
	{
		if(!visited[*i])
		{
			dfsutil(*i, visited);
		}
	}
}

// dfs traversal

void Graph::dfs(int v)
{
	bool *visited = new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[i] = false;
	}
	
	dfsutil(v, visited);
}

int main()
{
	
	int v,s,e;
	
	cout << "Vertex: ";
	cin >> v;
	cout << endl;
	
	cout << "Edges: ";
	cin >> e;
	cout << endl;
	
	Graph g(v);
	
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin >> a >> b;
		
		g.addEdge(a,b);
	}
	
	cout << "Start node: ";
	cin >> s;
	cout << endl;
	g.dfs(s);
}




























