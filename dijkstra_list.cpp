#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <string>
#include <list>
#include <limits.h> 
#include <queue>
#include <stack>
#include <vector>

using namespace std;

void init(bool visited[], int dist[], vector< pair<int, int> > graph[], int n)
{
	for(int i=1;i<=n;i++)
	{
		visited[i] = false;
		graph[i].clear();
		dist[i] = INT_MAX;
	}
}

// Comparator to sort edges. The shortest edge is removed first from the priority queue
class prioritize
{
	public:
		bool operator()(pair<int, int>&p1, pair<int, int>&p2)
		{
			return p1.second>p2.second;
		}
};

void dijkstra(bool visited[], int dist[], vector< pair<int, int> >graph[], int n, int s)
{
	
	// Using priority queue
	priority_queue< pair<int, int> , vector< pair<int, int> >, prioritize> pq; // Datatype, container comparator
	dist[s] = 0;
	
	pq.push(make_pair(s, 0));
	while(!pq.empty())
	{
		pair <int, int> curr = pq.top();
		pq.pop();
		
		// This node will now be of the highest priority
		int cv = curr.first;
		int cw = curr.second;
		
		visited[cv] = true; // future instances of this node with higher weight would be ignored
		
		vector< pair<int, int> >:: iterator i;
		
		for(i = graph[cv].begin(); i!=graph[cv].end(); i++) // iterating through vertices of the current vertex
		{
			
			if(!visited[(*i).first]) //  node not visited before
			{
				
				
				int nv = (*i).first;
				int nw = (*i).second;
				
				if(cw+nw<dist[nv])
				{
					// new distance is shorter
					dist[nv] = cw+nw;
					pq.push(make_pair(nv, dist[nv])); //  adding to priority queue
				}
			}
		}
	}
		
		
}
	
		

int main()
{
	int n,m,s;
	cout << "Vertices: ";
	cin >> n;
	cout << endl;
	
	cout << "Edges: ";
	cin >> m;
	cout << endl;
	
	bool visited[n+1];
	int dist[n+1];
	vector< pair<int,int> >graph[n+1];
	
	init(visited, dist, graph, n);
	
	// inputting data
	// source vertex, destination vertex, weight
	
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		
		graph[a].push_back(make_pair(b, c));
	}
	
	cout << "Starting vertex: ";
	cin >> s;
	cout << endl;
	
	dijkstra(visited, dist, graph, n,s);
	
	// Printing
	
	for(int i=1;i<=n;i++)
	{
		if(dist[i]!=INT_MAX)
		{
			cout << dist[i] << endl;
		}
		else
		{
			cout << "Unreachable" << endl;
		}
	}
	
	
}

		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		


	
	
	

	
	
