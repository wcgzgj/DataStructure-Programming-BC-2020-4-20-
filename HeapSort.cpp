#include "HeapSort.h"
#include "ToolArray.h"
#include <iostream>

HeapSort::HeapSort(void)
{
}


HeapSort::~HeapSort(void)
{
}

int * HeapSort::heapSort(int *a,int n)
{
	ToolArray ta;
	for(int i=n/2-1;i>=0;i--)//这里是为了将数组变成堆<---建堆的时候要从下往上的操作<-----但后面进行堆调整的时候，
	{//因为已经建堆成功，所以可以从上往下的操作
		heapShift(a,n,i);//a是数组，n是要调整的堆的元素个数，i是堆头
	}
	for(int i=n-1;i>0;i--)
	{
		ta.swap(a[0],a[i]);//每次将新的大根堆的堆头放到当前堆组成的数组最后，最后从后往前，由大到小，形成从前往后，由小到大的数组
		heapShift(a,i,0);
	}
	ta.output(a,n);
	return a;
}

void HeapSort::heapShift(int *a,int n,int k)
{
	ToolArray ta;
	while(2*k+1<n)//保证k是分支节点
	{
		int ch=2*k+1;
		if(ch+1<n && a[ch+1]>a[ch])
			ch=ch+1;//为了构成大根堆，要挑分支节点左右两边数值更大的节点
		if(a[k]>a[ch])
			return;
		ta.swap(a[k],a[ch]);
		k=ch;
	}
}
