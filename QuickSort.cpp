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
	int tmp=a[left];//��һ��ʼ��a[left]��Ϊ�м�������Ҫ��a[left]λ���ó���
	a[left]=NULL;//�������
	int i=left,j=right;
	while(i<j)
	{
		while(i<j && a[j]>=tmp)//��tmp��ߣ���tmp��Ķ�����
			j--;
		if(i<j)//³����
		{
			a[i]=a[j];
			i++;
			a[j]=NULL;//�������
		}

		while(i<j && a[i]<=tmp)//����tmp�ķ���߻����ұ߶����ԣ�������õ�ѡ���ǲ�����
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
