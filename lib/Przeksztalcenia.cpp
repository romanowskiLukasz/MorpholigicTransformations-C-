#pragma once
#include"Przeksztalcenia.h"

//klasa ZlozeniePrzeksztalcen

void ZlozeniePrzeksztalcen::dodajPrzeksztalcenie(Przeksztalcenie* p)
{
	this->array.push_back(p);
}

void ZlozeniePrzeksztalcen::przeksztalc(Bitmapa& bitmap)
{
	for (int i = 0; i < array.size(); i++)
	{
		array[i]->przeksztalc(bitmap);
	}
}

//inwersja
void Inwersja::przeksztalc(Bitmapa& Bitmap)
{
	poprawnoscArg(Bitmap);

	BitmapaExt bitmap = static_cast<BitmapaExt&>(Bitmap);

	for (int i = 0; i < bitmap.Lenght; i++)
	{
		for (int j = 0; j < bitmap.Width; j++)
		{
			if (bitmap.bitmap[i][j] == true) bitmap.bitmap[i][j] = false;
			else bitmap.bitmap[i][j] = true;
		}
	}
}


// Erozja 
void Erozja::przeksztalc(Bitmapa& Bitmap)
{
	poprawnoscArg(Bitmap);

	std::vector<int> pixelsToChange;
	BitmapaExt bitmap = static_cast<BitmapaExt&>(Bitmap);

	for (int i = 0; i < bitmap.Lenght; i++)
	{
		for (int j = 0; j < bitmap.Width; j++)
		{
			if (j > 0 && i > 0 && i < bitmap.Lenght - 1 && j < bitmap.Width - 1) // elementy niebrzegowe
			{
				if (bitmap.bitmap[i][j] == 1 && (bitmap.bitmap[i - 1][j] == 0 || bitmap.bitmap[i][j - 1] == 0 || bitmap.bitmap[i + 1][j] == 0 || bitmap.bitmap[i][j + 1] == 0))
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
				}
			}
			else if (i == 0 && j == 0) //prawy gorny rog
			{
				if (bitmap.bitmap[i][j] == 1 && (bitmap.bitmap[i + 1][j] == 0 || bitmap.bitmap[i][j + 1] == 0))
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
				}
			}

			else if (i == 0 && j == bitmap.Width - 1) //lewy gorny rog
			{
				if (bitmap.bitmap[i][j] == 1 && (bitmap.bitmap[i + 1][j] == 0 || bitmap.bitmap[i][j - 1] == 0))
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
				}
			}

			else if (i == bitmap.Lenght - 1 && j == bitmap.Width - 1) //prawy dolny rog
			{
				if (bitmap.bitmap[i][j] == 1 && (bitmap.bitmap[i - 1][j] == 0 || bitmap.bitmap[i][j - 1] == 0))
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
				}
			}

			else if (i == 0 && j == bitmap.Width - 1) //lewy dolny rog
			{
				if (bitmap.bitmap[i][j] == 1 && (bitmap.bitmap[i + 1][j] == 0 || bitmap.bitmap[i][j - 1] == 0))
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
				}
			}

			else if (i != 0 && i != bitmap.Lenght - 1 && j == 0) //prawy bok (bez rogow)
			{
				if (bitmap.bitmap[i][j] == 1 && (bitmap.bitmap[i + 1][j] == 0 || bitmap.bitmap[i][j + 1] == 1 || bitmap.bitmap[i - 1][j] == 0))
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
				}
			}

			else if (i == 0 && j != bitmap.Width - 1 && j != 0) // gorny bok (bez rogow)
			{
				if (bitmap.bitmap[i][j] == 1 && (bitmap.bitmap[i][j - 1] == 0 || bitmap.bitmap[i][j + 1] == 0 || bitmap.bitmap[i + 1][j] == 0))
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
				}
			}

			else if (i != 0 && i != bitmap.Lenght - 1 && j == bitmap.Width - 1) //lewy bok (bez rogow)
			{
				if (bitmap.bitmap[i][j] == 1 && (bitmap.bitmap[i][j - 1] == 0 || bitmap.bitmap[i + 1][j] == 0 || bitmap.bitmap[i - 1][j] == 0))
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
				}
			}

			else if (i == bitmap.Lenght - 1 && j != 0 && j != bitmap.Lenght - 1) //dolny bok(bez rogow)
			{
				if (bitmap.bitmap[i][j] == 1 && (bitmap.bitmap[i][j - 1] == 0 || bitmap.bitmap[i][j + 1] == 0 || bitmap.bitmap[i - 1][j] == 0))
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
				}
			}


		}

	}
	int m = 0, n = 0;
	while (!pixelsToChange.empty())
	{
		m = pixelsToChange.back();
		pixelsToChange.pop_back();
		n = pixelsToChange.back();
		pixelsToChange.pop_back();
		bitmap.bitmap[n][m] = 0;
	}

}

//Dylatacja

void Dylatacja::przeksztalc(Bitmapa& Bitmap)
{
	poprawnoscArg(Bitmap);

	std::vector<int> pixelsToChange;
	BitmapaExt bitmap = static_cast<BitmapaExt&>(Bitmap);

	for (int i = 0; i < bitmap.Lenght; i++)
	{
		for (int j = 0; j < bitmap.Width; j++)
		{
			if (j > 0 && i > 0 && i < bitmap.Lenght - 1 && j < bitmap.Width - 1) // elementy niebrzegowe
			{
				if (bitmap.bitmap[i][j] == 0 && (bitmap.bitmap[i - 1][j] == 1 || bitmap.bitmap[i][j - 1] == 1 || bitmap.bitmap[i + 1][j] == 1 || bitmap.bitmap[i][j + 1] == 1))
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
				}
			}
			else if (i == 0 && j == 0) //prawy gorny rog
			{
				if (bitmap.bitmap[i][j] == 0 && (bitmap.bitmap[i + 1][j] == 1 || bitmap.bitmap[i][j + 1] == 1))
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
				}
			}

			else if (i == 0 && j == bitmap.Width - 1) //lewy gorny rog
			{
				if (bitmap.bitmap[i][j] == 0 && (bitmap.bitmap[i + 1][j] == 1 || bitmap.bitmap[i][j - 1] == 1))
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
				}
			}

			else if (i == bitmap.Lenght - 1 && j == bitmap.Width - 1) //prawy dolny rog
			{
				if (bitmap.bitmap[i][j] == 0 && (bitmap.bitmap[i - 1][j] == 1 || bitmap.bitmap[i][j - 1] == 1))
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
				}
			}

			else if (i == 0 && j == bitmap.Width - 1) //lewy dolny rog
			{
				if (bitmap.bitmap[i][j] == 0 && (bitmap.bitmap[i + 1][j] == 1 || bitmap.bitmap[i][j - 1] == 1))
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
				}
			}

			else if (i != 0 && i != bitmap.Lenght - 1 && j == 0) //prawy bok (bez rogow)
			{
				if (bitmap.bitmap[i][j] == 0 && (bitmap.bitmap[i + 1][j] == 1 || bitmap.bitmap[i][j + 1] == 1 || bitmap.bitmap[i - 1][j] == 1))
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
				}
			}

			else if (i == 0 && j != bitmap.Width - 1 && j != 0) // gorny bok (bez rogow)
			{
				if (bitmap.bitmap[i][j] == 0 && (bitmap.bitmap[i][j - 1] == 1 || bitmap.bitmap[i][j + 1] == 1 || bitmap.bitmap[i + 1][j] == 1))
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
				}
			}

			else if (i != 0 && i != bitmap.Lenght - 1 && j == bitmap.Width - 1) //lewy bok (bez rogow)
			{
				if (bitmap.bitmap[i][j] == 0 && (bitmap.bitmap[i][j - 1] == 1 || bitmap.bitmap[i + 1][j] == 1 || bitmap.bitmap[i - 1][j] == 1))
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
				}
			}

			else if (i == bitmap.Lenght - 1 && j != 0 && j != bitmap.Lenght - 1) //dolny bok(bez rogow)
			{
				if (bitmap.bitmap[i][j] == 0 && (bitmap.bitmap[i][j - 1] == 1 || bitmap.bitmap[i][j + 1] == 1 || bitmap.bitmap[i - 1][j] == 1))
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
				}
			}


		}

	}
	int m = 0, n = 0;
	while (!pixelsToChange.empty())
	{
		m = pixelsToChange.back();
		pixelsToChange.pop_back();
		n = pixelsToChange.back();
		pixelsToChange.pop_back();
		bitmap.bitmap[n][m] = 1;
	}

}

//Zerowanie

void Zerowanie::przeksztalc(Bitmapa& Bitmap)
{
	poprawnoscArg(Bitmap);

	BitmapaExt bitmap = static_cast<BitmapaExt&>(Bitmap);
	for (int i = 0; i < bitmap.Lenght; i++)
	{
		for (int j = 0; j < bitmap.Width; j++)
			bitmap.bitmap[i][j] = 0;
	}
}

//Usrednianie

void Usrednianie::przeksztalc(Bitmapa& Bitmap)
{
	poprawnoscArg(Bitmap);

	std::vector<int> pixelsToChange;
	BitmapaExt bitmap = static_cast<BitmapaExt&>(Bitmap);

	for (int i = 0; i < bitmap.Lenght; i++)
	{
		for (int j = 0; j < bitmap.Width; j++)
		{
			if (j > 0 && i > 0 && i < bitmap.Lenght - 1 && j < bitmap.Width - 1) // elementy niebrzegowe
			{
				int ilSasiadow = 0, kolor = 0;
				if (bitmap.bitmap[i][j] == 0) //zliczamy ilosc sasiadow innego koloru jezeli pixel jest bialy
				{
					if (bitmap.bitmap[i - 1][j] == 1)
						ilSasiadow += 1;
					if (bitmap.bitmap[i + 1][j] == 1)
						ilSasiadow += 1;
					if (bitmap.bitmap[i][j - 1] == 1)
						ilSasiadow += 1;
					if (bitmap.bitmap[i][j + 1] == 1)
						ilSasiadow += 1;

					kolor = 1;
				}
				else //zliczamy ilosc sasiadow innego koloru jezeli pixel jest czarny
				{
					if (bitmap.bitmap[i - 1][j] == 0)
						ilSasiadow += 1;
					if (bitmap.bitmap[i + 1][j] == 0)
						ilSasiadow += 1;
					if (bitmap.bitmap[i][j - 1] == 0)
						ilSasiadow += 1;
					if (bitmap.bitmap[i][j + 1] == 0)
						ilSasiadow += 1;

					kolor = 0;
				}

				if (ilSasiadow > 2) //jezeli ma wiecej niz 2 sasiadow innego koloru to zapisujemy go do zmiany
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
					pixelsToChange.push_back(kolor);
				}
			}

			//tu nie sprawdzamy rogow poniewaz maja tylko dwoch sasiadow

			else if (i != 0 && i != bitmap.Lenght - 1 && j == 0) //prawy bok (bez rogow)
			{
				int ilSasiadow = 0, kolor = 0;
				if (bitmap.bitmap[i][j] == 0) //zliczamy ilosc sasiadow innego koloru jezeli pixel jest bialy
				{
					if (bitmap.bitmap[i + 1][j] == 1)
						ilSasiadow += 1;
					if (bitmap.bitmap[i - 1][j] == 1)
						ilSasiadow += 1;
					if (bitmap.bitmap[i][j - 1] == 1)
						ilSasiadow += 1;

					kolor = 1;
				}
				else //zliczamy ilosc sasiadow innego koloru jezeli pixel jest czarny
				{
					if (bitmap.bitmap[i + 1][j] == 0)
						ilSasiadow += 1;
					if (bitmap.bitmap[i][j - 1] == 0)
						ilSasiadow += 1;
					if (bitmap.bitmap[i - 1][j] == 0)
						ilSasiadow += 1;

					kolor = 0;
				}

				if (ilSasiadow > 2) //jezeli ma wiecej niz 2 sasiadow innego koloru to zapisujemy go do zmiany
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
					pixelsToChange.push_back(kolor);
				}
			}

			else if (i == 0 && j != bitmap.Width - 1 && j != 0) // gorny bok (bez rogow)
			{
				int ilSasiadow = 0, kolor = 0;
				if (bitmap.bitmap[i][j] == 0) //zliczamy ilosc sasiadow innego koloru jezeli pixel jest bialy
				{
					if (bitmap.bitmap[i + 1][j] == 1)
						ilSasiadow += 1;
					if (bitmap.bitmap[i][j - 1] == 1)
						ilSasiadow += 1;
					if (bitmap.bitmap[i][j + 1] == 1)
						ilSasiadow += 1;

					kolor = 1;
				}
				else //zliczamy ilosc sasiadow innego koloru jezeli pixel jest czarny
				{
					if (bitmap.bitmap[i + 1][j] == 0)
						ilSasiadow += 1;
					if (bitmap.bitmap[i][j - 1] == 0)
						ilSasiadow += 1;
					if (bitmap.bitmap[i][j + 1] == 0)
						ilSasiadow += 1;

					kolor = 0;
				}

				if (ilSasiadow > 2) //jezeli ma wiecej niz 2 sasiadow innego koloru to zapisujemy go do zmiany
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
					pixelsToChange.push_back(kolor);
				}
			}

			else if (i != 0 && i != bitmap.Lenght - 1 && j == bitmap.Width - 1) //lewy bok (bez rogow)
			{
				int ilSasiadow = 0, kolor = 0;
				if (bitmap.bitmap[i][j] == 0) //zliczamy ilosc sasiadow innego koloru jezeli pixel jest bialy
				{
					if (bitmap.bitmap[i + 1][j] == 1)
						ilSasiadow += 1;
					if (bitmap.bitmap[i - 1][j] == 1)
						ilSasiadow += 1;
					if (bitmap.bitmap[i][j + 1] == 1)
						ilSasiadow += 1;

					kolor = 1;
				}
				else //zliczamy ilosc sasiadow innego koloru jezeli pixel jest czarny
				{
					if (bitmap.bitmap[i + 1][j] == 0)
						ilSasiadow += 1;
					if (bitmap.bitmap[i - 1][j] == 0)
						ilSasiadow += 1;
					if (bitmap.bitmap[i][j + 1] == 0)
						ilSasiadow += 1;

					kolor = 0;
				}

				if (ilSasiadow > 2) //jezeli ma wiecej niz 2 sasiadow innego koloru to zapisujemy go do zmiany
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
					pixelsToChange.push_back(kolor);
				}
			}

			else if (i == bitmap.Lenght - 1 && j != 0 && j != bitmap.Lenght - 1) //dolny bok(bez rogow)
			{
				int ilSasiadow = 0, kolor = 0;
				if (bitmap.bitmap[i][j] == 0) //zliczamy ilosc sasiadow innego koloru jezeli pixel jest bialy
				{
					if (bitmap.bitmap[i][j - 1] == 1)
						ilSasiadow += 1;
					if (bitmap.bitmap[i - 1][j] == 1)
						ilSasiadow += 1;
					if (bitmap.bitmap[i][j + 1] == 1)
						ilSasiadow += 1;

					kolor = 1;
				}
				else //zliczamy ilosc sasiadow innego koloru jezeli pixel jest czarny
				{
					if (bitmap.bitmap[i][j - 1] == 0)
						ilSasiadow += 1;
					if (bitmap.bitmap[i - 1][j] == 0)
						ilSasiadow += 1;
					if (bitmap.bitmap[i][j + 1] == 0)
						ilSasiadow += 1;

					kolor = 0;
				}

				if (ilSasiadow > 2) //jezeli ma wiecej niz 2 sasiadow innego koloru to zapisujemy go do zmiany
				{
					pixelsToChange.push_back(i);
					pixelsToChange.push_back(j);
					pixelsToChange.push_back(kolor);
				}
			}


		}


	}
	int m = 0, n = 0, kolor = 0;
	while (!pixelsToChange.empty())
	{
		kolor = pixelsToChange.back();
		pixelsToChange.pop_back();
		m = pixelsToChange.back();
		pixelsToChange.pop_back();
		n = pixelsToChange.back();
		pixelsToChange.pop_back();
		bitmap.bitmap[n][m] = kolor;
	}
}






