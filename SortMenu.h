#pragma once
#include <string>
class SortMenu
{
public:
	SortMenu(void);
	~SortMenu(void);

	void printBlock(int n);
	void printDot(int n);
	void printEndl(int n);
	void printMenu(std::string fname);
	int getAnswer();
	void remainTime(int t,std::string fname);
	void pleaseInput();
	int sortIsDone();
	void doAllSort();
	void helpBook();
};

