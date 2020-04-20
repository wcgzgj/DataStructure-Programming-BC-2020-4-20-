#pragma once
class HeapSort
{
public:
	HeapSort(void);
	~HeapSort(void);
	int * heapSort(int *a,int n);

private:
	void heapShift(int *a,int n,int k);
};

