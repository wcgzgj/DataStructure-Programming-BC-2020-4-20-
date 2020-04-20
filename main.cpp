#include <iostream>
#include <Windows.h>
#include "ToolArray.h"
#include "BubbleSort.h"
#include "ShellSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "SortMenu.h"
using namespace std;

int main()
{
	SortMenu sm;

	int flag=1;
	while(flag)
	{
		system("cls");
		sm.printMenu("�˵�\\���˵�.txt");
		sm.pleaseInput();
		int answer=sm.getAnswer(); 
		
		switch (answer)
		{
		case 1:
			while (1)
			{
				system("cls");
				sm.printMenu("�˵�\\������Ϣ.txt");
				int infoFlag;
				sm.pleaseInput();
				cin>>infoFlag;
				if(infoFlag==0) break;
			}
			break;
		case 2:
			system("cls");
			sm.doAllSort();
			break;

		case 3:
			system("cls");
			sm.helpBook();
			break;

		case 4:
			system("cls");
			sm.printMenu("�˵�\\�ټ�.txt");
			Sleep(1000);
			return 0;
		default:
			system("cls");
			sm.printMenu("�˵�\\�������.txt");
			sm.remainTime(3,"�˵�\\�������.txt");
			break;
		}
	}

	system("pause");
	return 0;
}


