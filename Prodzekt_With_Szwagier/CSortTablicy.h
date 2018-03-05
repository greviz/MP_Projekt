#pragma once
#include <iostream>

using namespace std;

class CSortTablicy
{
private:
	string sSortName;
	unsigned long int iSwapsCount, iComparesCount;
public:
	string fGetSortName();
	int fGetSwapsCount();
	int fGetComparesCount();
	void fBubbleSort(int , int*);
	void fCocktailSort(int *, int);
	void fHeapSort(int *, int);
	void fCountingSort(int *, int *, int);
	void fBucketSort(int, int*);
	void fQuickSortLemuto(int, int, int*, int);

};