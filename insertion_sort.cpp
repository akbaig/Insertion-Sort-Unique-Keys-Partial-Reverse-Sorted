#include <iostream>
#include <stdio.h>
#include <stdlib.h> //for rand() srand() functions
#include <time.h>
#include <vector>
#include <bits/stdc++.h> //for reverse() function

using namespace std;

long int CurrentTimeInSec()
{
	time_t seconds; 
    seconds = time(NULL);
	return seconds; 
}
vector<int> ReverseSorted(int n)
{
	vector<int> V(n);
	int next_int = rand()%n;
	for(int j=0; j < n; j++)
	{
		int increment = rand()%n;
		V[j] = next_int+increment;
		next_int = V[j]; 
	}
	reverse(V.begin(), V.end()); 
	return V;
}
vector<int> PartiallyReverseSorted(int n)
{
	int n2 = (rand()%(n/2))+(n/4); //this makes the first 25 to 75% no. partially reverse sorted 
	vector<int> V(n2);
	V = ReverseSorted(n2);
	V.resize(n);
	for(int j=n2; j < n; j++)
	{
		V[j] = rand()%n; 
	}
	return V;
}
vector<int> FewUniqueKeys(int n)
{
	vector<int> V(n);
	int repeated_num = rand()%n;
	for(int i=0; i< n; i++)
	{	
		int r = rand()%n;
		if(r <= (n*0.75))
			V[i] = repeated_num;
		else
			V[i] = r;
	}
	return V;
}
int main()
{
	//printf("%ld", CurrentTimeInSec());
	srand(time(0));
	vector<int> A = FewUniqueKeys(40);
	for(int i=0; i < A.size(); i++)
	{
		cout << A[i] << " ";
	}
	return 0;
}
