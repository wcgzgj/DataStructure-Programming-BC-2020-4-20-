#include "ShellSort.h"
#include "ToolArray.h"
#include <iostream>



ShellSort::ShellSort(void)
{
}


ShellSort::~ShellSort(void)
{
}

int * ShellSort::shellSort(int *a,int n)
{
	ToolArray ta;
	for(int step=n/2;step>=1;step=step/2)
	{
		
		for(int i=step;i<n;i++)
		{
			for(int j=i-step;j>=0;j=j-step)
			{
				if(a[j]>a[j+step])
					ta.swap(a[j],a[j+step]);
			}
		}
	}
	return a;
}
