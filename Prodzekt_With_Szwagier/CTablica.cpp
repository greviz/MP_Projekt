#pragma once
#include "CTablica.h"


void CTablica::fAddValuesManually(int *tab, int manuals)
{
	cout << "Wprowadz je: " << endl;
	for (int i = 0; i < manuals; i++)
	{
		cin >> tab[i];
	}
}

void CTablica::fAddRandomValues(int *tab, int manuals, int size)
{
	int from, to;
	random_device rd;
	mt19937 mt(rd());

	cout << "Podaj zakres losowanych liczb[od-do]: " << endl;

	cin >> from;
	cin >> to;

	uniform_int_distribution<int>dist(from, to);
	for (int i = manuals; i < size; i++)
	{
		tab[i] = dist(rd);
	}
}

void CTablica::fChoicePart(int *arr, int iTableSize)
{
	char cChoice;
	cout << "Czy chcesz sam wprowadzic wartosci do tablicy?[Y/N]" << endl;
	cin >> cChoice;
	if (cChoice == 'y' || cChoice == 'Y')
	{
		int iManualValues;
		cout << "Ile wartosci chcesz wprowadzic sam? ";
		cin >> iManualValues;
		if (iManualValues > iTableSize)
		{
			cout << "Nie mozesz podac wiecej wartosci niz tablica ma miesjc!" << endl;
			exit(0);
		}
		else if (iManualValues == iTableSize)
			fAddValuesManually(arr, iManualValues);
		else
		{
			fAddValuesManually(arr, iManualValues);
			fAddRandomValues(arr, iManualValues, iTableSize);
		}
	}
	else if (cChoice == 'n' || cChoice == 'N')
	{
		fAddRandomValues(arr, 0, iTableSize);
	}
	cout << "Sortowanie tych liczb odbedzie sie w 4 przypadkach:" << endl << "1. Wartosci w tablicy beda losowo ulozone" << endl << "2. Wartosci w tablicy beda juz posortowane" << endl;
	cout << "3. Wartosci w tablicy beda posortowane malejaco" << endl << "4. 10% wartosci w tablicy bedzie na zlej pozycji" << endl; cout << endl;
}

void CTablica::fCopyTables(int *original, int *copy, int *copy2, int *copy3, int size)
{
	int iTenPercent, iEnd;
	for (int i = 0; i < size; i++)
	{
		copy[i] = original[i];
	}

	fHeapSort(copy, size); // posortowanie wartosci dla 2giego przypadku tablicy heap bo jest stosunkowo szybki

	for (int i = 0; i < size; i++)
	{
		copy2[i] = -original[i];
	}
	fHeapSort(copy2, size); // posortowanie malejaco liczb w tablicy poprzez zamiane na ujemne

	for (int i = 0; i < size; i++) // odwrocenie wartosci do normalnej postaci
	{
		copy2[i] = -copy2[i];
	}


	for (int i = 0; i < size; i++) // w tym przypadku tylko 10% ma byc nie posortowane - kopiuje tablice ktora jest juz posortowana
	{
		copy3[i] = copy[i];
	}
	iTenPercent = fGetTenPercent(size); // obliczenie ile liczb trzeba zamienic aby 10% bylo nie posortowane
	iEnd = size - 1; // zamieniam poczatek tablicy z koncem
	for (int i = 0; i <iTenPercent; i++) // liczbe z poczatku wrzucam co 2 miejsca od tylu
	{
		swap(copy3[i], copy3[iEnd]);
		iEnd -= 2;
	}

}

void CTablica::fSortPart(int* iFirstCase, int iTableSize, fstream &fDataOutput)
{
	int iChoice;
	int *iSecondCase, *iThirdCase, *iFourthCase;

	iSecondCase = iThirdCase = iFourthCase = nullptr;

	iSecondCase = fCreateIntTable(iTableSize); // utworzenie tablic i rozmiarach tablicy 1szej
	iThirdCase = fCreateIntTable(iTableSize);
	iFourthCase = fCreateIntTable(iTableSize);

	fCopyTables(iFirstCase, iSecondCase, iThirdCase, iFourthCase, iTableSize);
	cout << "Jakie sortowanie chcesz zastosowac?" << endl << "1. Sortowanie babelkowe" << endl << "2. Sortowanie koktajlowe" << endl << "3. Sortowanie kubelkowe" << endl;
	cout << "4. Sortowanie przez zliczanie" << endl << "5. Sortowanie szybkie" << endl << "6. Sortowanie przez kopcowanie" << endl;

	cin >> iChoice;

	switch (iChoice)
	{
	case 1:
	{
			  fBubbleSort(iTableSize, iFirstCase);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Uzupelnona losowo" << '\t' << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fBubbleSort(iTableSize, iSecondCase);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Posortowana rosnaco" << '\t' << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fBubbleSort(iTableSize, iThirdCase);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Posortowana malejaco" << '\t' << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fBubbleSort(iTableSize, iFourthCase);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Czesciowo posortowana(10% zle)" << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;
			  fDataOutput << endl;
			  break;
	}
	case 2:
	{
			  fCocktailSort(iFirstCase, iTableSize);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Uzupelnona losowo" << '\t' << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fCocktailSort(iSecondCase, iTableSize);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Posortowana rosnaco" << '\t' << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fCocktailSort(iThirdCase, iTableSize);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Posortowana malejaco" << '\t' << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fCocktailSort(iFourthCase, iTableSize);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Czesciowo posortowana(10% zle)" << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fDataOutput << endl;
			  break;
	}
	case 3:
	{
			  fBucketSort(iTableSize, iFirstCase);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Uzupelnona losowo" << '\t' << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fBucketSort(iTableSize, iSecondCase);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Posortowana rosnaco" << '\t' << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fBucketSort(iTableSize, iThirdCase);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Posortowana malejaco" << '\t' << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fBucketSort(iTableSize, iFourthCase);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Czesciowo posortowana(10% zle)" << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fDataOutput << endl;
			  break;
	}
	case 4:
	{
			  int *iCountingTable = nullptr;
			  iCountingTable = fCreateIntTable(iTableSize);

			  fCountingSort(iFirstCase, iCountingTable, iTableSize);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Uzupelnona losowo" << '\t' << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fCountingSort(iSecondCase, iCountingTable, iTableSize);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Posortowana rosnaco" << '\t' << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fCountingSort(iThirdCase, iCountingTable, iTableSize);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Posortowana malejaco" << '\t' << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fCountingSort(iFourthCase, iCountingTable, iTableSize);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Czesciowo posortowana(10% zle)" << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fDataOutput << endl;
			  break;
	}
	case 5:
	{
			  fQuickSortLemuto(0, iTableSize - 1, iFirstCase, iTableSize);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Uzupelnona losowo" << '\t' << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fQuickSortLemuto(0, iTableSize - 1, iSecondCase, iTableSize);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Posortowana rosnaco" << '\t' << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fQuickSortLemuto(0, iTableSize - 1, iThirdCase, iTableSize);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Posortowana malejaco" << '\t' << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fQuickSortLemuto(0, iTableSize - 1, iFourthCase, iTableSize);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Czesciowo posortowana(10% zle)" << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fDataOutput << endl;
			  break;
	}
	case 6:
	{
			  fHeapSort(iFirstCase, iTableSize);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Uzupelnona losowo" << '\t' << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fHeapSort(iSecondCase, iTableSize);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Posortowana rosnaco" << '\t' << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fHeapSort(iThirdCase, iTableSize);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Posortowana malejaco" << '\t' << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fHeapSort(iFourthCase, iTableSize);
			  fDataOutput << fGetSortName() << '\t' << '\t' << iTableSize << '\t' << '\t' << "Czesciowo posortowana(10% zle)" << '\t' << '\t' << fGetComparesCount() << '\t' << '\t' << '\t' << fGetSwapsCount() << endl;

			  fDataOutput << endl;
			  break;
	}

	default:
		cout << "Zly wybor!" << endl;
		exit(0);
		break;
	}
}
