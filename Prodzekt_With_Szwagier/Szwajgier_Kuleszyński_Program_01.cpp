#pragma once
#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <windows.h>

#include "SKLib.h"
#include "SKFunToSort.h"
#include "CSortTablicy.h"
#include "CTablica.h"

using namespace std;

int main()
{
	fstream fDataOutput;
	CTablica a;
	int iTableSize;
	int *iFirstCase = nullptr;

	cout << "--==/Witaj w programie sortujacym!\==--" << endl;
	Sleep(1000);
	cout << "Podaj dlugosc tablicy: ";
	cin >> iTableSize;

	iFirstCase = fCreateIntTable(iTableSize);

	a.fChoicePart(iFirstCase, iTableSize);

	fDataOutput.open("out.txt", ios::out | ios::app);

	fInitiateTextLook(fDataOutput);

	a.fSortPart(iFirstCase, iTableSize, fDataOutput);

	cout << "Program pomyslnie zakonczyl dzialanie!" << endl;

	system("pause");
	return 0;
}