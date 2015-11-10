#include <iostream>

using namespace std;



void merge(int arr[], int, int, int);
void mergeSort(int arr[], int, int);

void merge( int arr[], int p, int q, int r, int n)
{
	

	int i,j,k,c[n];
	
	i = p;
	k = p;
	j = q+1;
	
	while((i<=q)&&(j<=r))
	{
		if(arr[i]<arr[j])
		{
			c[k] = arr[i];
			k++;
			i++;
		}
		else
		{
			c[k] = arr[j];
			k++;
			j++;
		}
	}
	
	while(i<=q)
	{
		c[k] = arr[i];
		k++;
		i++;
	}
	
	while(j<=r)
	{
		c[k] = arr[j];
		k++;
		j++;
	}

	
	for(int i=p;i<k;i++)
	{
		arr[i] = c[i];
	}
	
}

void mergeSort(int arr[], int p, int r, int n)
{

	if(p<r)
	{
		int q = (p+r)/2;
		mergeSort(arr, p, q, n);
		mergeSort(arr, q+1, r, n);
		merge(arr, p, q, r, n);
	}
}

int main()
{
	
	int a[] = {5,6,3,2,1,8,7,5,4,3,2,8,9,8};
	int n = sizeof(a)/sizeof(a[0]);
	mergeSort(a, 0, 13, n);
	
	for(int i=0;i<14;i++)
	{
		cout << a[i] << " ";
	}
}
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

