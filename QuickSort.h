#pragma once
class QuickSort
{
public:
	QuickSort(void);
	~QuickSort(void);
	int * quickSort(int *a,int n);
private:
	int * quickSort(int *a,int n,int left,int right);
	int Div(int *a,int n,int left,int right);
};

