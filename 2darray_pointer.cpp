#include <iostream>

using namespace std;
int n,m;
void display(int **);

void display(int **a)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	cout << "Enter the number of rows and columns :" << endl;
	cin >> n >> m;
	
	cout << "Enter the elements of the 2d array :" << endl;
	
	int arr[n][m];
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin >> arr[i][j];
		}
	}
	
	//~ Passing as pointer 
	
	int *p[n];
	
	for (int i=0;i<n;i++)
	{
		p[i] = arr[i];
	}
	
	display(p);
	
	return 0;
}
