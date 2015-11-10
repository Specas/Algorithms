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
	int v; // Number of vertices
	list <int> *adj; // Pointer to array containing the adjacency list
	
	public:
	
	Graph(int V); // constructor
	void addEdge(int v, int w);
	void bfs(int s);
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

void Graph::bfs(int s)
{
	// Mark all the vertices as not visited
	bool *visited = new bool[v];
	for(int i=0;i<v;i++)
	{
		visited[i] = false;
	}
	
	// create a queue for bfs
	list<int> queue;
	
	visited[s] = true;
	queue.push_back(s);
	
	// 'i' will be used to get all the adjacency vertices of a vertex
	list<int>:: iterator i;
	
	while(!queue.empty())
	{
		// Dequeue a vertex and print it
		s = queue.front();
		cout << s << " ";
		queue.pop_front();
		
		// get all adjacent vertices of the dequeued vertex s
		// If an adjacent has not been visited, then mark it as visited and enqueue it
		
		for(i = adj[s].begin(); i!=adj[s].end(); ++i)
		{
			if(!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
}


int main()
{
	
	cout << "Vertex: " << endl;
	int v;
	cin >> v;
	
	cout << "Edges: " << endl;
	int e;
	cin >> e;
	
	
	Graph g(v);
	
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin >> a >> b;
		
		g.addEdge(a,b);
	}
	
	cout << "Start: " << endl;
	int start;
	cin >> start;
	
	g.bfs(start);
	
	return 0;
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
