#pragma once

#include <iostream>

using namespace std;
/*
#Funkcja do kopcowania
#Param_IN: tablica,rozmiar, zmienna , zmienna zaw. ilosc porownan, zmienna zaw. ilosc zamian

*/
void heapify(int *, int, int, unsigned long int &, unsigned long int &);
/*
#Funkcja znajduje najwieksza wartosc w tablicy
#Param_IN: tablica, rozmiar tablicy, zmienna zaw. ilosc porownan
#Return max wartosc w tablicy
*/
int find_max(int *, int, unsigned long int &);
/*
*Funkcja dzielaca tablice (potrzeba do quicksorta)
*@param_in: pierwsze (wybrane) miejsce w tablicy, drugie (wybrane) miejsce w tablicy, tablica, zmienna zaw. ilosc porownan, zmienna zaw. ilosc zamian
*/
int partition(int, int, int *,unsigned long int &,unsigned long int &);