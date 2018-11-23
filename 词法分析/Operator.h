#pragma once
#include "Token.h"
class Operator : // 运算符类
	public Token
{
public:
	string content = ""; // content指运算符的内容
	Operator(string c, int t) { content = c; tag = t; }
	Operator(string c) { content = c; }
	Operator() {};
	~Operator() {};

	virtual void display();
};

