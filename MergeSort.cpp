#include "MergeSort.h"


MergeSort::MergeSort(void)
{
}


MergeSort::~MergeSort(void)
{
}

int * MergeSort::mergeSort(int *a,int n)
{
	return mergeSort(a,n,0,n-1);
}

int * MergeSort::mergeSort(int *a,int n,int low,int high)
{
	if(low>=high)
		return a;
	int mid=(low+high)/2;
	mergeSort(a,n,low,mid);
	mergeSort(a,n,mid+1,high);
	merge(a,n,low,mid,high);//low:前一个头、mid:前一个尾、high:后一个尾
	return a;
}

void MergeSort::merge(int *a, int n,int low,int mid,int high)
{
	int i=low,j=mid+1, k=0;//i:前一个头、j:后一个头、k:作为tmp数组的下标指针
	int *tmp=new int[high-low+1];
	while(i<=mid && j<=high)
	{
		if(a[i]<=a[j])
			tmp[k++]=a[i++];
		else
			tmp[k++]=a[j++];
	}
	while(i<=mid)
		tmp[k++]=a[i++];
	while(j<=high)
		tmp[k++]=a[j++];
	for(int i=low,flag=0;i<=high;i++,flag++)
		a[i]=tmp[flag];
	delete []tmp;
}
