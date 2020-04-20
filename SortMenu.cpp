#include "SortMenu.h"
#include "ToolArray.h"
#include "BubbleSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "ShellSort.h"
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

string UTF8ToGB(const char* str)//因为使用getline会出现乱码，所以只能这个样子
{
	string result;
	WCHAR *strSrc;
	LPSTR szRes;

	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}


SortMenu::SortMenu(void)
{
}


SortMenu::~SortMenu(void)
{
}


void SortMenu::printBlock(int n)
{
	for(int i=0;i<n;i++) cout<<" ";
}

void SortMenu::printDot(int n)
{
	for(int i=0;i<n;i++) cout<<"·";
}

void SortMenu::printEndl(int n)
{
	for(int i=0;i<n;i++) cout<<endl;
}



void SortMenu::printMenu(string fname)
{
	ifstream fin(fname);
	string lineCnt;
	while(getline(fin,lineCnt))
	{
		string str;
		str= UTF8ToGB(lineCnt.c_str()).c_str();
		cout<<str<<endl;
	}
}

int SortMenu::getAnswer()
{
	int x;
	cin>>x;
	return x;
}

void SortMenu::remainTime(int t,string fname)
{
	system("cls");
	for(int i=t;i>=1;i--)
	{
		printMenu(fname);
		printEndl(7);
		cout<<"请于"<<i<<"秒后重新输入"<<endl;
		Sleep(1000);
		system("cls");
	}

}

void SortMenu::pleaseInput()
{
	printEndl(7);
	cout<<"请输入操作符并回车：";
}

int SortMenu::sortIsDone()
{
	printEndl(10);
	printBlock(20);
	cout<<"所有排序算法已经完成，请于 '排序完成'文件夹下查看排序结果"<<endl;
	printEndl(10);
	printBlock(20);
	cout<<"你是否需要展示排序后的文件：Y/N"<<endl;
	pleaseInput();
	char answer;
	while(1)
	{
		cin>>answer;
		if(answer=='y'||answer=='Y'||answer=='n'||answer=='N') break;
		system("cls");
		printEndl(10);
		printBlock(20);
		cout<<"输入错误，请重新输入：Y/N";
		pleaseInput();
	}

	if(answer=='y'||answer=='Y') return 1;
	else return 2;
	return 0;
}

void SortMenu::doAllSort()
{
	printEndl(10);
	printBlock(20);
	cout<<"请输入测试数据的个数：";
	int n;
	cin>>n;
	ToolArray ta;
	int * a=ta.getArray(n);
	ta.writeBackToFile("source.txt");

	int * aBubbleSort=ta.readFile("source.txt");
	BubbleSort bs;
	bs.bubbleSort(aBubbleSort,n);
	ta.writeBackToFile("排序完成\\BubbleSort.txt",aBubbleSort,n);

	int * aShellSort=ta.readFile("source.txt");
	ShellSort ss;
	ss.shellSort(aShellSort,n);
	ta.writeBackToFile("排序完成\\ShellSort.txt",aBubbleSort,n);

	int * aQuickSort=ta.readFile("source.txt");
	QuickSort qs;
	qs.quickSort(aQuickSort,n);
	ta.writeBackToFile("排序完成\\QuickSort.txt",aBubbleSort,n);

	int * aHeapSort=ta.readFile("source.txt");
	HeapSort hs;
	hs.heapSort(aHeapSort,n);
	ta.writeBackToFile("排序完成\\HeapSort.txt",aBubbleSort,n);

	int * aMergeSort=ta.readFile("source.txt");
	MergeSort ms;
	ms.mergeSort(aMergeSort,n);
	ta.writeBackToFile("排序完成\\MergeSort.txt",aBubbleSort,n);
	int flag=sortIsDone();
	system("cls");

	if(flag==1)
	{
		printMenu("菜单\\冒泡排序.txt");
		ta.output(aBubbleSort,n);
		printEndl(3);

		printMenu("菜单\\希尔排序.txt");
		ta.output(aShellSort,n);
		printEndl(3);

		printMenu("菜单\\快速排序.txt");
		ta.output(aQuickSort,n);
		printEndl(3);

		printMenu("菜单\\堆排序.txt");
		ta.output(aHeapSort,n);
		printEndl(3);

		printMenu("菜单\\归并排序.txt");
		ta.output(aMergeSort,n);
		printEndl(3);

		printBlock(20);
		cout<<"请按 0 回到主菜单"<<endl;
		int answer;
		while(1)
		{
			cin>>answer;
			if(answer==0) break;
			system("cls");
			printEndl(10);
			printBlock(20);
			cout<<"输入错误，请重新输入：请按 0 回到主菜单";
			pleaseInput();
		}
		return;
	}
	else return;
	
}

void SortMenu::helpBook()
{
	printMenu("菜单\\帮助手册.txt");
	printEndl(3);
	printBlock(20);
	cout<<"请按 0 回到主菜单"<<endl;
	int answer;
	while(1)
	{
		cin>>answer;
		if(answer==0) break;
		system("cls");
		printEndl(10);
		printBlock(20);
		cout<<"输入错误，请重新输入：请按 0 回到主菜单";
		pleaseInput();
	}
	return;
}

