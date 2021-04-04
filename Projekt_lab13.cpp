// Projekt_lab13.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
// Romanowski Łukasz 12i, Konduracka Karolina 12i

#include <iostream>
#include <typeinfo>
#include"lib/Bitmapa.h"
#include"lib/Przeksztalcenia.h"



int main()
{

	BitmapaExt aa(5, 5);
	aa(1, 1) = aa(2, 1) = aa(3, 1) = aa(2, 2) = aa(1, 3) = aa(2, 3) = aa(3, 3) = true;
	std::cout << aa << "\n"; Usrednianie u;
	Dylatacja d;
	ZlozeniePrzeksztalcen z; z.dodajPrzeksztalcenie(&u); z.dodajPrzeksztalcenie(&d); 
	z.przeksztalc(aa);
	std::cout << aa << "\n";
	
	return 0;
}
