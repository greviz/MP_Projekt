#pragma once
#include <iostream>
#include<exception>

using namespace std;

class eWrongSize : public exception
{
	const char* what() const throw()
	{
		return "Invalid table size!";
	}
};
