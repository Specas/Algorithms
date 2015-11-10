#include <iostream>
#include <vector>

using namespace std;
	

void sieve(int n, int m)
{
	//~ This function employs the Sieve of Eratosthenes algorithm to find all the prime numbers betweeen 1 and n
	
	//~ The limit is from 1 to n
	
	//~ array to store all the numbers
	int num1[n];
	
	//~ Filling the num array
	for(int i=0;i<n;i++)
	{
		num1[i] = i+1;
	}
	
	//~ 1 is not a prime number. If a number is not prime, we set that value to -1
	num1[0] = -1;
	
	for(int i=2;i<=(n/2);i++)
	{
		int mult = 2;
		while( (i*mult)<=n)
		{
			//~ If we find any multiples, that number is not prime. Hence we assign it to -1
			
			num1[(i*mult)-1] = -1;
			
			mult+=1;
		}
	}
	
	
	
	
	
	int num2[n];
	
	//~ Filling the num array
	for(int i=0;i<m;i++)
	{
		num2[i] = i+1;
	}
	
	//~ 1 is not a prime number. If a number is not prime, we set that value to -1
	num2[0] = -1;
	
	for(int i=2;i<=(m/2);i++)
	{
		int mult = 2;
		while( (i*mult)<=m)
		{
			//~ If we find any multiples, that number is not prime. Hence we assign it to -1
			
			num2[(i*mult)-1] = -1;
			
			mult+=1;
		}
	}
	
	
	
	
	
		
	//~ We create a vector with all the non negative numbers which are the prime numbers
	
	int *p1;
	p1 = num1;
	vector <int> low(p1, p1+sizeof(num1)/sizeof(num1[0]));
	int size1 = low.size();
	
	int *p2;
	p2 = num2;
	vector <int> high(p2, p2+sizeof(num2)/sizeof(num2[0]));
	int size2 = high.size();
	
	//~ vector to store the prime numbers
	vector <int> prime;
	
	for(int i=size1;i<size2;i++)
	{
		if(high[i]!=-1)
		{
			prime.push_back(high[i]);
		}
	}
	
	int psize = prime.size();
	cout << size1 << endl << size2 << endl << psize;
	for(int i=0;i<psize;i++)
	{
		cout << prime[i] << " ";
	}
		
	
	
}
	

int main()
{
	//~ This program calls the sieve function to find the prime numbers between two limits
	
	int a,b;
	//~ Input for the two limits 
	cin >> a >> b;
	
	sieve(a,b);

	
	
	return 0;
}
	
