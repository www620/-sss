#ifndef _rd_h_

#include<iostream>
#include<ctime>
#include<cstdio>
#include<cstdlib>

#define _rd_h_

using namespace std;

void rd(int* array, int len)
{
	if(array == NULL)
		return;
	
	int n, m;
	
	for(n = len - 1; n >= 0; n--)
	{
		srand(time(NULL) + rand());
		m = rand() % (n + 1);
		swap(array[n], array[m]);
	}
	
	/*
	for(n = 0;	n < len;	n++)
	{
		cout << array[n] << " ";
	}
	*/
}

#endif
