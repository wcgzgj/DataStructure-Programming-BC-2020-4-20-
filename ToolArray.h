#pragma once
class ToolArray
{
private:
	int *a;
	int n;
public:
	ToolArray(void);
	~ToolArray(void);
	int * getArray(int n);
	void writeBackToFile(char fname[]);
	void writeBackToFile(char fname[],int *a,int n);
	int * readFile(char fname[]);
	int getN();
	void output();
	void output(int *a,int n);
	void swap(int &x,int &y);
private:
	int *getRandomData();
};

