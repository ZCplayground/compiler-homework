#include "Real.h"



string Real::ToString()
{
	string ret = to_string(value);
	return ret;
}

Real::~Real()
{
}

void Real::display()
{
	cout << "floting point: " << value;
	cout << endl;
}
