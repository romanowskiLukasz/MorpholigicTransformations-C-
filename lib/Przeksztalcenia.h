#pragma once
#include "Bitmapa.h"
#include<vector>
#include"libErrors.h"

/*
glowna klasa przeksztalcenie reprezentujaca poszczegolne dzialania
*/
class Przeksztalcenie
{
public:
    virtual void przeksztalc(Bitmapa&) = 0;
};

/*
klasa ZlozeniePrzeksztalcen - do wyboru wykonywanych czynnosciw okreslonej kolejnosci
*/
class ZlozeniePrzeksztalcen :public Przeksztalcenie
{
	std::vector<Przeksztalcenie*> array;
public:

	void dodajPrzeksztalcenie(Przeksztalcenie* p);

	void przeksztalc(Bitmapa& bitmap);
};

/*
klasa dziedziczaca po klasie Przeksztalcenie, 
zamiana kolorow bitmapy
*/
class Inwersja : public Przeksztalcenie
{
public:
	void przeksztalc(Bitmapa& Bitmap);
};

/*
klasa dziedziczaca po klasie Przeksztalcenie, 
erozja - piksele berzegowe - zamiana z czarnych na bia³e
*/
class Erozja : public Przeksztalcenie
{
public:
	void przeksztalc(Bitmapa& Bitmap);
};

/*
klasa dziedziczaca po klasie Przeksztalcenie,
dylatacja - biali sasiedzi pikseli brzegowych (czarnych) na czarne
*/
class Dylatacja : public Przeksztalcenie
{
	void przeksztalc(Bitmapa& Bitmap);
};

/*
klasa dziedziczaca po klasie Przeksztalcenie,
zerowanie calego obrazu na bialy - zero
*/
class Zerowanie : public Przeksztalcenie
{
	void przeksztalc(Bitmapa& Bitmap);
};

/*
klasa dziedziczaca po klasie Przeksztalcenie,
usrednienie - jesli piksel ma wiecej niz 2 sasiadow w danym kolorze, 
innym niz jego, to zmienia swoj kolor na ten sasiadow
*/
class Usrednianie : public Przeksztalcenie
{
	void przeksztalc(Bitmapa& Bitmap);
};

/*
szablon klasy z metoda do sprawdzania typu argumentu 
*/
template<typename type>
void poprawnoscArg(type& arg)
{
	try
	{
		if (typeid(arg) != typeid(BitmapaExt))
			throw BadTypeException::BadTypeException();
	}
	catch (BadTypeException & e)
	{
		std::cout << "error: " << e.what();
		exit(-2);
	}
}