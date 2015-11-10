#include <iostream>

using namespace std;

void countingSort(int *a, int n)
{
	
	int c[11] = {0}; // considerting that the max value of an element is only 10
	int b[n];
	
	for(int i=0;i<n;i++)
	{
		c[a[i]]++;
	}
	

	
	//now to make c[i] contain the number of elements <=i
	for(int i=1;i<=10;i++)
	{
		c[i] = c[i]+c[i-1];
	}
	
	for(int i=0;i<11;i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;
	
	for(int i=n-1;i>=0;i--)
	{
		cout << i << " " << a[i] << " "<< c[a[i]] << " " << endl;
		b[c[a[i]]] = a[i];
		c[a[i]]--;
	}
	
	for(int i=0;i<n;i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	
	
}



int main()
{
	int a[] = {2,3,1,4,2,6,7,5,6,6,4,3,3,8,9};
	int n = sizeof(a)/sizeof(a[0]);

	
	countingSort(a,n);

}
