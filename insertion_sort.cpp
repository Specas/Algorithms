#include <iostream>

using namespace std;

int * insertionSort(int arr[], int n)
{
	
	int tmp;
	int i;
	
	for(int j=1;j<n;j++)
	{
		tmp = arr[j];
		
		i = j-1;
		
		// We shift the elements accordingly
		while((i>=0)&&(arr[i]>tmp))
		{
			arr[i+1] = arr[i];
			--i;
		}
		
		arr[++i] = tmp;
		
	}
	
	return arr;
}
		
	
	



int main()
{
	
	int a[] = {6,8,9,12,0,4,3,5,1,7,6,23,6,4,2,8,9};
	
	int n = sizeof(a)/sizeof(a[0]);
	
	int *b;
	
	b = insertionSort(a,n);
	
	// display the sorted array
	
	for(int i=0;i<n;i++)
	{
		cout << b[i] << " ";
	}
	
	return 0;
}
	
