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

string UTF8ToGB(const char* str)//��Ϊʹ��getline��������룬����ֻ���������
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
	for(int i=0;i<n;i++) cout<<"��";
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
		cout<<"����"<<i<<"�����������"<<endl;
		Sleep(1000);
		system("cls");
	}

}

void SortMenu::pleaseInput()
{
	printEndl(7);
	cout<<"��������������س���";
}

int SortMenu::sortIsDone()
{
	printEndl(10);
	printBlock(20);
	cout<<"���������㷨�Ѿ���ɣ����� '�������'�ļ����²鿴������"<<endl;
	printEndl(10);
	printBlock(20);
	cout<<"���Ƿ���Ҫչʾ�������ļ���Y/N"<<endl;
	pleaseInput();
	char answer;
	while(1)
	{
		cin>>answer;
		if(answer=='y'||answer=='Y'||answer=='n'||answer=='N') break;
		system("cls");
		printEndl(10);
		printBlock(20);
		cout<<"����������������룺Y/N";
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
	cout<<"������������ݵĸ�����";
	int n;
	cin>>n;
	ToolArray ta;
	int * a=ta.getArray(n);
	ta.writeBackToFile("source.txt");

	int * aBubbleSort=ta.readFile("source.txt");
	BubbleSort bs;
	bs.bubbleSort(aBubbleSort,n);
	ta.writeBackToFile("�������\\BubbleSort.txt",aBubbleSort,n);

	int * aShellSort=ta.readFile("source.txt");
	ShellSort ss;
	ss.shellSort(aShellSort,n);
	ta.writeBackToFile("�������\\ShellSort.txt",aBubbleSort,n);

	int * aQuickSort=ta.readFile("source.txt");
	QuickSort qs;
	qs.quickSort(aQuickSort,n);
	ta.writeBackToFile("�������\\QuickSort.txt",aBubbleSort,n);

	int * aHeapSort=ta.readFile("source.txt");
	HeapSort hs;
	hs.heapSort(aHeapSort,n);
	ta.writeBackToFile("�������\\HeapSort.txt",aBubbleSort,n);

	int * aMergeSort=ta.readFile("source.txt");
	MergeSort ms;
	ms.mergeSort(aMergeSort,n);
	ta.writeBackToFile("�������\\MergeSort.txt",aBubbleSort,n);
	int flag=sortIsDone();
	system("cls");

	if(flag==1)
	{
		printMenu("�˵�\\ð������.txt");
		ta.output(aBubbleSort,n);
		printEndl(3);

		printMenu("�˵�\\ϣ������.txt");
		ta.output(aShellSort,n);
		printEndl(3);

		printMenu("�˵�\\��������.txt");
		ta.output(aQuickSort,n);
		printEndl(3);

		printMenu("�˵�\\������.txt");
		ta.output(aHeapSort,n);
		printEndl(3);

		printMenu("�˵�\\�鲢����.txt");
		ta.output(aMergeSort,n);
		printEndl(3);

		printBlock(20);
		cout<<"�밴 0 �ص����˵�"<<endl;
		int answer;
		while(1)
		{
			cin>>answer;
			if(answer==0) break;
			system("cls");
			printEndl(10);
			printBlock(20);
			cout<<"����������������룺�밴 0 �ص����˵�";
			pleaseInput();
		}
		return;
	}
	else return;
	
}

void SortMenu::helpBook()
{
	printMenu("�˵�\\�����ֲ�.txt");
	printEndl(3);
	printBlock(20);
	cout<<"�밴 0 �ص����˵�"<<endl;
	int answer;
	while(1)
	{
		cin>>answer;
		if(answer==0) break;
		system("cls");
		printEndl(10);
		printBlock(20);
		cout<<"����������������룺�밴 0 �ص����˵�";
		pleaseInput();
	}
	return;
}

