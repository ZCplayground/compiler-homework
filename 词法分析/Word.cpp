#include "Word.h"


Word::~Word()
{
}

void Word::display()
{
	if (catagory == "")
		cout << "<" << tag << ", " << lexeme << ">";
	else
		cout << catagory << ": " << "<" << tag << ", " << lexeme << ">";
	cout << endl;
}
