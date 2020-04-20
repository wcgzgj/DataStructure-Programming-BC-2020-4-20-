#include "QuickSort.h"
#include "ToolArray.h"
#include <iostream>
using namespace std;


QuickSort::QuickSort(void)
{
}


QuickSort::~QuickSort(void)
{
}

int * QuickSort::quickSort(int *a,int n)
{
	return quickSort(a,n,0,n-1);
}

int * QuickSort::quickSort(int *a,int n,int left,int right)
{
	if(left>=right)
		return a;
	int mid=Div(a,n,left,right);
	quickSort(a,n,left,mid-1);
	quickSort(a,n,mid+1,right);
}

int QuickSort::Div(int *a,int n,int left,int right)
{
	int tmp=a[left];//把一开始的a[left]作为中间数，先要把a[left]位置让出来
	a[left]=NULL;//便于理解
	int i=left,j=right;
	while(i<j)
	{
		while(i<j && a[j]>=tmp)//在tmp左边，比tmp大的都不管
			j--;
		if(i<j)//鲁棒性
		{
			a[i]=a[j];
			i++;
			a[j]=NULL;//便于理解
		}

		while(i<j && a[i]<=tmp)//等于tmp的放左边还是右边都可以，所以最好的选择是不动它
			i++;
		if(i<j)
		{
			a[j]=a[i];
			j--;
			a[i]=NULL;
		}
	}
	a[i]=tmp;
	return i;
}
