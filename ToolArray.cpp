#include "ToolArray.h"
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

ToolArray::ToolArray(void)
{
	n=0;
}


ToolArray::~ToolArray(void)
{
}



int * ToolArray::getArray(int n)
{
	this->n=n;
	a=getRandomData();
	return a;
}

int * ToolArray::getRandomData()
{
	int *a=new int[n];
	srand((int)time(0));
	for(int i=0;i<n;i++)
		a[i]=rand()%n+1;//生成的随机数值为1-n;
	return a;
}

void ToolArray::writeBackToFile(char fname[])
{
	ofstream fout(fname);
	int lineCount=0;
	if(!fout.is_open())
	{
		cout<<"文件打开错误！"<<endl;
		fout.close();
		exit(0);
	}
	int flag=0;
	while(flag<n)
	{
		fout<<a[flag]<<" ";
		flag++;
		lineCount++;
		if(lineCount==10)//每10个数换行
		{
			fout<<"\n";
			lineCount=0;
		}
	}
}

void ToolArray::writeBackToFile(char fname[],int *b,int n)
{
	ofstream fout(fname);
	int lineCount=0;
	if(!fout.is_open())
	{
		cout<<"文件打开错误！"<<endl;
		fout.close();
		exit(0);
	}
	int flag=0;
	while(flag<n)
	{
		fout<<b[flag]<<" ";
		flag++;
		lineCount++;
		if(lineCount==10)//每10个数换行
		{
			fout<<"\n";
			lineCount=0;
		}
	}
}

int * ToolArray::readFile(char fname[])
{
	int *a=new int[n];
	ifstream fin(fname);
	int flag=0;
	if(!fin.is_open())
	{
		cout<<"文件打开错误"<<endl;
		fin.close();
		exit(0);
	}
	while(!fin.eof())//当文件不为空
	{
		fin>>a[flag];
		flag++;
	}
	fin.close();
	return a;
}


int ToolArray::getN()
{
	return n;
}

void ToolArray::output()
{
	int flag=0;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
		flag++;
		if(flag==10)
		{
			cout<<endl;
			flag=0;
		}
	}
	cout<<endl;
}

void ToolArray::output(int *a,int n)
{
	int flag=0;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
		flag++;
		if(flag==10)
		{
			cout<<endl;
			flag=0;
		}
	}
	cout<<endl;
}

void ToolArray::swap(int &x,int &y)
{
	int tmp=x;
	x=y;
	y=tmp;
}

