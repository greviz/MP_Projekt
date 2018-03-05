#pragma once

#include "SKFunToSort.h"

using namespace std;

void heapify(int *tab, int size, int i, unsigned long int &comps,unsigned long int &swaps)
{
	int largest = i;
	int l = (2 * i) + 1;
	int r = (2 * i) + 2;
	if (l < size && tab[l] > tab[largest])
	{
		comps ++;
		largest = l;
	}
	if (r < size && tab[r] > tab[largest])
	{
		comps ++;
		largest = r;
	}
	if (largest != i)
	{
		comps++;
		swaps++;
		swap(tab[i], tab[largest]);
		heapify(tab, size, largest,comps,swaps);
	}
}

int find_max(int *tab, int size,unsigned long int &counts)
{
	int temp = 0, k = 0;
	for (int i = 0; i < size; i++)
	{
		temp = tab[i];
		if (temp>k)
		{
			counts++;
			k = temp;
		}
	}
	return k;
}

int partition(int pierwsza, int druga, int *tab,unsigned long int &compareCount,unsigned long int &swapCount)
{
	int x = tab[pierwsza];
	int i = pierwsza;
	for (int j = pierwsza + 1; j <= druga; j++) {
		if (tab[j] <= x) {
			compareCount++;
			i = i + 1;
			swap(tab[i], tab[j]);
			swapCount++;
		}
	}
	swap(tab[i], tab[pierwsza]);
	swapCount++;
	return i;
}