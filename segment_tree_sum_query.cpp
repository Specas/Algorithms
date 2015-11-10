#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstring>
#include <list>
#include <limits.h>
#include <queue>
#include <stack>
#include <vector>
#include <stdlib.h> 

using namespace std;

// Get middle index from corner indices
int getMid(int s, int e)
{
	return s + (e-s)/2;
}


// Get sum of values in a range ( recursive function )
// st - pointer to the segment tree
// si - pointer to current node. Initially it is 0
// ss and se - Starting and ending indices of the segment represented by the current node
// qs and qe - Starting and ending indices of the query range
int getSumUtil(int *st, int ss, int se, int qs, int qe, int si)
{
	// If the segment of the current node is a part of the given range, return the sum of the segment
	if(qs<=ss && qe>=se)
	{
		return st[si];
	} 
	
	// If the segment of the current node lies outside the given range
	if(se<qs || ss > qe)
	{
		return 0;
	}
	
	// If a part of the range overlaps with the given range
	int mid = getMid(ss, se);
	return getSumUtil(st, ss, mid, qs, qe, 2*si+1) + getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
}


// a recursive funciton to update the nodes which have the given index in their range.
// i - index of the element to be update
// diff - value to be added to the nodes
void updateValueUtil(int *st, int ss, int se, int i, int diff, int si)
{
	// base case
	if(i<ss || i>se)
	{
		return;
	}
	
	st[si] = st[i] + diff;
	if(se!=ss)
	{
		int mid = getMid(ss, se);
		updateValueUtil(st, ss, mid, i, diff, 2*si+1);
		updateValueUtil(st, mid+1, se, i, diff, 2*si+2);
	}
}


// Function to update value in the input array and the segment tree
// it uses the updateValueUtil function
void updateValue(int arr[], int *st, int n, int i, int new_val)
{
	// erroneous input index
	if(i<0 || i>n-1)
	{
		cout << "invalid" << endl;
		return;
	}
	
	// difference between old and new values
	int diff = new_val - arr[i];
	
	// update value in the array
	updateValueUtil(st, 0, n-1, i, diff, 0);
}


// return sum from qs to qe
// it uses the getSumUtil function
int getSum(int *st, int n, int qs, int qe)
{
	// erroneous input
	if(qs<0 || qe>n-1 || qs>qe)
	{
		cout << "invalid" << endl;
		return -1;
	}
	
	return getSumUtil(st, 0, n-1, qs, qe, 0);
}

// recursive function that constructs the segment tree for array[ss...se]
// si is the current index of node
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
	// If there is one element in the array, store it in the current node of the segment tree and return
	if(ss==se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}
	
	// If there are more than one elements, recur for left and right subtrees and store the sum of the values in this node
	int mid = getMid(ss, se);
	st[si] = constructSTUtil(arr, ss, mid, st, 2*si+1) + constructSTUtil(arr, mid+1, se, st, si*2+2);
	return st[si];
}

// Function to construct the segment tree from the given array

int *constructST(int arr[], int n)
{
	// height
	int x = (int)(ceil(log2(n)));
	
	// max size
	int max_size = 2*(int)pow(2, x) - 1;
	
	// allocate memory
	int *st = new int[max_size];
	
	constructSTUtil(arr, 0, n-1, st, 0);
	
	return st;
}


// driver main program

int main()
{
	int n;
	cin >> n;
	
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	
	int *st = constructST(arr, n);
	
	cout << getSum(st, n, 0, 3) << endl;	
	cout << getSum(st, n, 1, 2) << endl;	
	cout << getSum(st, n, 1, 5) << endl;	
	
	updateValue(arr, st, n, 1, 5);
	
	cout << getSum(st, n, 1, 5) << endl;
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
