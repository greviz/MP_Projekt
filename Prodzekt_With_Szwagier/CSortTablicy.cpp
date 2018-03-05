#pragma once
#include "SKFunToSort.h"
#include "CSortTablicy.h"
#include <string>
#include <iostream>


string CSortTablicy::fGetSortName()
{
	return sSortName;
}

int CSortTablicy::fGetSwapsCount()
{
	return iSwapsCount;
}

int CSortTablicy::fGetComparesCount()
{
	return iComparesCount;
}

void CSortTablicy::fBubbleSort(int rozmiar, int *tab)
{
	sSortName = "Sortowanie babelkowe";
	iSwapsCount = 0;
	iComparesCount = 0;
	int kontrolMonoton;
	do {
		kontrolMonoton = iSwapsCount;
		for (int i = 1; i < rozmiar; i++) {
			iComparesCount++;
			if (tab[i - 1] > tab[i]) {
				swap(tab[i - 1], tab[i]);
				iSwapsCount++;
			}
		}
	} while (kontrolMonoton != iSwapsCount);
}

void CSortTablicy::fCocktailSort(int *tab, int size)
{
	sSortName = "Sortowanie koktajlowe";
	iSwapsCount = 0;
	iComparesCount = 0;

	int bottom_index = 0;
	int top_index = size - 1;
	bool isSwapped = true; // flaga operujaca petla
	while (isSwapped)
	{
		isSwapped = false;
		for (int i = bottom_index; i < top_index; i++)
		{
			if (tab[i] > tab[i + 1])
			{
				iSwapsCount++;
				swap(tab[i], tab[i + 1]);
				isSwapped = true;
			}
			iComparesCount++;
		}
		top_index--; // ostatni element jest na swoim miejscu, konczymy przed nim
		if (!isSwapped) // jezeli zadna wartosci nie zostala zamieniona oznacza to ze tablica jest posortowana
		{
			break;
		}
		isSwapped = false;
		for (int i = top_index; i > bottom_index; i--)
		{
			if (tab[i] < tab[i - 1])
			{
				iSwapsCount++;
				swap(tab[i], tab[i - 1]);
				isSwapped = true;
			}
			iComparesCount++;
		}
		bottom_index++; // pierwszy element jest na swoim miejscu zaczynamy od kolejnego
	}
}

void CSortTablicy::fHeapSort(int *tab, int heap_size)
{
	sSortName = "Sortowanie przez kopcowanie";
	iComparesCount = 0;
	iSwapsCount = 0;

	for (int i = (heap_size / 2) - 1; i >= 0; i--)
	{
		heapify(tab, heap_size, i, iComparesCount, iSwapsCount);
	}
	for (int i = heap_size - 1; i >= 0; i--)
	{
		swap(tab[0], tab[i]);
		iSwapsCount++;
		heapify(tab, i, 0, iComparesCount, iSwapsCount);
	}
}

void CSortTablicy::fCountingSort(int *tab, int *tab2, int size)
{
	sSortName = "Sortowanie przez zliczanie";
	iSwapsCount = 0;
	iComparesCount = 0;

	int *c = nullptr;
	int temp = 0, k;
	k = find_max(tab, size, iComparesCount) + 1;

	c = new int[k];
	for (int i = 0; i < k; i++) // wyzerowanie tablicy z wystapieniami
	{
		c[i] = 0;
	}
	for (int j = 0; j < size; j++) // uzupelnienie tablicy z wystapieniami ich iloscia
	{
		c[tab[j]]++;
	}
	for (int i = 1; i < k; i++)
	{
		c[i] += c[i - 1];
	}
	for (int j = size - 1; j >= 0; j--) // wpisanie w nowa tablice wartosci od najmniejszej do najwiekszej
	{
		iSwapsCount++;
		tab2[c[tab[j]] - 1] = tab[j];
		c[tab[j]]--;
	}
}

void CSortTablicy::fBucketSort(int rozmiar, int *tab)
{
	sSortName = "Sortowanie kubelkowe";
	iSwapsCount = 0;
	iComparesCount = 0;
	int m = tab[0];
	for (int i = 1; i < rozmiar; i++) 
	{
		if (tab[i] > m)
		{
			m = tab[i];
			iComparesCount++;
		}
	}
	m++;
	int *buckets = new int[m];
	for (int i = 0; i < m; ++i)
		buckets[i] = 0;
	for (int i = 0; i < rozmiar; ++i)
		buckets[tab[i]]++;
	for (int i = 0, j = 0; j < m; ++j){
		for (int k = buckets[j]; k > 0; --k)
		{
			tab[i] = j;
			iSwapsCount++;
			i++;
		}
	}
}

void CSortTablicy::fQuickSortLemuto(int pierwsza, int druga, int *tab, int rozmiar) 
{
	sSortName = "Sortowanie szybkie ver. Lemuto";
	iComparesCount = 0;
	iSwapsCount = 0;
	
	int i = 0;
	while (pierwsza < druga || i > 0) {
		if (pierwsza < druga) {
			int q = partition(pierwsza, druga, tab,iComparesCount,iSwapsCount);
			tab[druga] = -tab[druga];
			druga = q - 1;
			i++;
		}
		else {
			druga = pierwsza = druga + 2;
			while (druga < rozmiar) {
				if (tab[druga] < 0) {
					tab[druga] = -tab[druga];
					break;
				}
				else
					druga++;
				iComparesCount++;
			}
			i--;
		}
		iComparesCount++;
	}
}
