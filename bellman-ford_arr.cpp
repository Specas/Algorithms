#include <iostream>
#include <cstdio>

using namespace std;


void relax(int d[], int pi[], int u, int v, int w)
{
	if(d[v]>(d[u]+w))
	{
		d[v] = d[u] + w;
		pi[v] = u;
	}
}


int main()
{
	int v,e;
	cout << "Vertices: ";
	cin >> v;
	cout << endl;
	cout << "Edges: ";
	cin >> e;
	cout << endl;
	
	int a[v+1][v+1];
	
	for(int i=0;i<=v;i++)
	{
		for(int j=0;j<=v;j++)
		{
			a[i][j] = 0;
		}
	}
			         
	
	for(int i=0;i<e;i++)
	{
		int aa,bb,cc;
		cin >> aa >> bb >> cc;
		
		a[aa][bb] = cc;
	}
	

	
	int d[v+1];
	int pi[v+1];
	
	for(int i=0;i<=v;i++)
	{
		d[i] = 100000; // infinity
		pi[i] = -1; // NIL
	}
	
	int s;
	cout << "Start vertex: ";
	cin >> s;
	cout << endl;
	
	
	d[s] = 0; // distance of starting vertex from the starting vertex
	
	
	
	
	// algorithm starts ----------------------------------------------
	
	for(int i=0;i<(v-1);i++)
	{
		for(int j=1;j<=v;j++)
		{
			for(int k=1;k<=v;k++)
			{
				if(a[j][k]!=(0))
				{
					relax(d, pi, j, k, a[j][k]);
				}
			}
		}
	}
	
	int negative_cycles = 0;
	
	for(int j=1;j<=v;j++)
	{
		for(int k=1;k<=v;k++)
		{
			if(a[j][k]!=(0))
			{
				if(d[k]>(d[j]+a[j][k]))
				{
					negative_cycles = 1;
				}
			}
		}
	}
	
	cout << negative_cycles << endl;
	
	
	for(int i=1;i<=v;i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;
	
	for(int i=1;i<=v;i++)
	{
		cout << pi[i] << " ";
	}
	
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	
	
	
	
	
	

