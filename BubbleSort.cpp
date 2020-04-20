#include "BubbleSort.h"
#include "ToolArray.h"
#include <iostream>
using namespace std;

BubbleSort::BubbleSort(void)
{
}


BubbleSort::~BubbleSort(void)
{
}

void BubbleSort::bubbleSort(int *a,int n)
{
	ToolArray ta;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<n-1;j++)
		{
			if(a[j]>a[j+1]) ta.swap(a[j],a[j+1]);
		}
	}
}


