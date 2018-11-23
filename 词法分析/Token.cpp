#include "Token.h"

string Token::ToString()
{
	string ret = "";
	ret += to_string(tag);
	return ret;
}


Token::~Token()
{
	
}

void Token::display()
{
	cout << "token :" << tag;
	cout << endl;

}
