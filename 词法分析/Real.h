#pragma once
#include "Token.h"
#include "Tag.h"
class Real : // ��������
	public Token
{
public:

	double value;

	Real(double v) { value = v; tag = Tag::REAL; }
	string ToString();
	Real() {};
	~Real();

	virtual void display();
};

