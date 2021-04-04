#pragma once
#include "Bitmapa.h"

unsigned BitmapaExt::length() const
{
	return Lenght;
}

unsigned BitmapaExt::width() const
{
	return Width;
}

bool& BitmapaExt::operator() (unsigned x, unsigned y)
{
	return bitmap[x][y];
}

bool BitmapaExt::operator() (unsigned x, unsigned y) const
{
	return bitmap[x][y];
}

BitmapaExt::BitmapaExt(unsigned lenght, unsigned width)
{
	try
	{
		if (lenght == 0 || width == 0)
		{
			throw BadSizeException::BadSizeException();
		}
		this->Lenght = lenght;
		this->Width = width;
	}
	catch (BadSizeException& e)
	{
		std::cout << "error: " << e.what();
		exit(-1);
	}

	try
	{
		this->bitmap = new bool* [lenght];
	}
	catch (std::bad_alloc)
	{
		exit(0);
	}
	for (int i = 0; i < lenght; i++)
	{
		try
		{
			this->bitmap[i] = new bool[width];
		}
		catch (std::bad_alloc)
		{
			exit(0);
		}
	}

	// zerowanie stworzonej bitmapy (bialy kolor)
	for (int i = 0; i < lenght; i++)
	{
		for (int j = 0; j < width; j++)
			this->bitmap[i][j] = 0;
	}

}


std::ostream& operator<< (std::ostream& os, const BitmapaExt& Bitmap)
{

	for (int i = 0; i < Bitmap.Lenght; i++)
	{
		for (int j = 0; j < Bitmap.Width; j++)
		{
			os << Bitmap.bitmap[i][j] << " ";
		}
		os << std::endl;
	}

	return os;
}