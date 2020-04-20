#pragma once
class MergeSort
{
public:
	MergeSort(void);
	~MergeSort(void);
	int * mergeSort(int *a,int n);
private:
	int * mergeSort(int *a,int n,int low,int high);
	void merge(int *a,int n,int low,int mid,int high);

};

