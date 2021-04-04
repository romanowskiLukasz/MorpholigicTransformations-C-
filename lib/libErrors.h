#pragma once

#include <iostream>
#include <exception>
#include<typeinfo>



	class BadSizeException : public std::runtime_error
	{
	public:
		BadSizeException() : std::runtime_error("rozmiar tablicy musi byc wiekszy od zera") {};
		BadSizeException(std::string msg) : std::runtime_error(msg) {};
	};

	class BadTypeException : public std::logic_error
	{
	public:
		BadTypeException() : std::logic_error("podano bledy typ obiektu w argumencie funkcji") {};
		BadTypeException(std::string msg) : std::logic_error(msg) {};
	};

	
