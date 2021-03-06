#pragma once
#include<iostream>
#include "libErrors.h"

/*
Głowna klasa reprezentujaca, abstrakcyjna - baza do dziedziczenia
*/
class Bitmapa
{
public:
    virtual unsigned length() const = 0;
    virtual unsigned width() const = 0;
    virtual bool& operator() (unsigned x, unsigned y) = 0;
    virtual bool operator() (unsigned x, unsigned y) const = 0;
    virtual ~Bitmapa() {}
};

/*
Klasa dziedzicząca po klasie Bitmapa
do określania szerokości i długości bitmapy, przysloniecie fun wirtualnych
z konstruktorem - przyjmuje powyzsze dane i tworzy biala (0) bitmape
*/
class BitmapaExt : public Bitmapa
{
public:
	bool** bitmap;
	unsigned Lenght, Width;
	friend std::ostream& operator<< (std::ostream& os, const BitmapaExt& Bitmap);

	unsigned length() const;

	unsigned width() const;

	bool& operator() (unsigned x, unsigned y);

	bool operator() (unsigned x, unsigned y) const;

	BitmapaExt(unsigned lenght, unsigned width);

};