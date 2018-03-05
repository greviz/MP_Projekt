#pragma once
#include <iostream>
#include <fstream>
using namespace std;

/*
#Funkcja oblicza i zwraca 10% podanej liczby
#Param_IN: liczba
#Return: 10% podanej liczby
*/
int fGetTenPercent(int size);
/*
#Tworzy tablice o zadanym rozmiarze
#Param_IN: rozmiar tablicy
#Return: wskaznik na tablice
*/
int *fCreateIntTable(int size);
/*
#Funkcja inicjujaca tabelke do pliku
#Param_IN: uchwyt do pliku
*/
void fInitiateTextLook(fstream &file);