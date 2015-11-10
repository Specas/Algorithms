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

int getMid(int s, int e)
{
	return s + (e-s)/2;
}

int rmqUtil(int *st, int ss, int se, int qs, int qe, int index)
{
	 if (qs <= ss && qe >= se)
        return st[index];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return -INT_MAX;
 
    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return max(rmqUtil(st, ss, mid, qs, qe, 2*index+1),
                  rmqUtil(st, mid+1, se, qs, qe, 2*index+2));
}

int rmq(int *st, int n, int qs, int qe)
{
	 // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        cout << "invalid " << endl;
        return -1;
    }
 
    return rmqUtil(st, 0, n-1, qs, qe, 0);
}


int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the minimum of two values in this node
    int mid = getMid(ss, se);
    st[si] =  max(constructSTUtil(arr, ss, mid, st, si*2+1),
                     constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}
 
/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
int *constructST(int arr[], int n)
{
    // Allocate memory for segment tree
 
    //Height of segment tree
    int x = (int)(ceil(log2(n))); 
 
    // Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1; 
 
    int *st = new int[max_size]; 
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}


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
	
	cout << rmq(st, n, 0, 2) << endl;
}




























