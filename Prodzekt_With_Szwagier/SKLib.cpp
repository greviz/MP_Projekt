#pragma once
#include "SKLib.h"

int fGetTenPercent(int size)
{
	return static_cast<int>(size / 10);
}
int *fCreateIntTable(int size)
{
	try
	{
		int *tab = new int[size];
		return tab;
	}
	catch (bad_alloc)
	{
		cout << "Nie udalo sie utworzyc tablicy!" << endl;
		getchar();
		exit(0);
	}
}
void fInitiateTextLook(fstream &file)
{
	file << endl;
	file << "Nazwa metody sortowania" << '\t' << '\t' << "Dlugosc tablicy" << '\t' << '\t' << "Rodzaj tablicy       " << '\t' << " Liczba porownan" << '\t' << " Liczba przestawien" << endl;
	file << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}