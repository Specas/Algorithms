// This program contains functions to implement selection sort

#include <iostream>
using namespace std;

void selection_sort(int *arr, int size)
{
	
	int len = size;
	int minVal = 0;
	int minPos = 0;
	
	for( int i = 0; i<len; i++)
	{
		 minVal = arr[i];
		 minPos = i;

		 for(int j = i+1; j<len; j++)
		 {
			 if (arr[j] < minVal)
			 {
				 minVal = arr[j];
				 minPos = j;
			 }
		 }

		 swap(arr[i], arr[minPos]);

	 }

 }
 
 int main()
 {
	 using namespace std;
	 
	 int a[] = {1,7,6,10,2,9,32,4,5,19};
	 int size = sizeof(a)/sizeof(a[0]);
	 int *p = a;
	 selection_sort(p, size);

	 for(int i = 0;i<size;i++)
	 {
		 cout << a[i] << " ";
	 }
	 return 0;
 }
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
 
