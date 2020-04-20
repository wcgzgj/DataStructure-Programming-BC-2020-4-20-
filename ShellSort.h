#pragma once
class ShellSort
{
public:
	ShellSort(void);
	~ShellSort(void);
	int * shellSort(int *a,int n);
private:
	void swap(int &x,int &y);
};

