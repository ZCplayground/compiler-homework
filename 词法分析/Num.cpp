#include "Num.h"

string Num::ToString()
{
	string ret = "";
	ret += value;
	return ret;
}

Num::~Num()
{
}

void Num::display()
{
	cout << "integer: " << value;
	cout << endl;
}
