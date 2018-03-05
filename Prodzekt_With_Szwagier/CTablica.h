#pragma once
#include <iostream>
#include <random>
#include <string>
#include <fstream>

#include "CSortTablicy.h"
#include "SKLib.h"

class CTablica : public CSortTablicy
{
private:

public:
	void fAddValuesManually(int *, int);
	void fAddRandomValues(int *, int, int);
	void fChoicePart(int *arr, int iTableSize);
	void fCopyTables(int *original, int *copy, int *copy2, int *copy3, int size);
	void fSortPart(int *firstTable, int size, fstream &dataFile);

};