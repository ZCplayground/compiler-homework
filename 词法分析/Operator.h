#pragma once
#include "Token.h"
class Operator : // �������
	public Token
{
public:
	string content = ""; // contentָ�����������
	Operator(string c, int t) { content = c; tag = t; }
	Operator(string c) { content = c; }
	Operator() {};
	~Operator() {};

	virtual void display();
};

