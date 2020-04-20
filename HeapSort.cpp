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
	for(int i=n/2-1;i>=0;i--)//������Ϊ�˽������ɶ�<---���ѵ�ʱ��Ҫ�������ϵĲ���<-----��������жѵ�����ʱ��
	{//��Ϊ�Ѿ����ѳɹ������Կ��Դ������µĲ���
		heapShift(a,n,i);//a�����飬n��Ҫ�����Ķѵ�Ԫ�ظ�����i�Ƕ�ͷ
	}
	for(int i=n-1;i>0;i--)
	{
		ta.swap(a[0],a[i]);//ÿ�ν��µĴ���ѵĶ�ͷ�ŵ���ǰ����ɵ�����������Ӻ���ǰ���ɴ�С���γɴ�ǰ������С���������
		heapShift(a,i,0);
	}
	ta.output(a,n);
	return a;
}

void HeapSort::heapShift(int *a,int n,int k)
{
	ToolArray ta;
	while(2*k+1<n)//��֤k�Ƿ�֧�ڵ�
	{
		int ch=2*k+1;
		if(ch+1<n && a[ch+1]>a[ch])
			ch=ch+1;//Ϊ�˹��ɴ���ѣ�Ҫ����֧�ڵ�����������ֵ����Ľڵ�
		if(a[k]>a[ch])
			return;
		ta.swap(a[k],a[ch]);
		k=ch;
	}
}
