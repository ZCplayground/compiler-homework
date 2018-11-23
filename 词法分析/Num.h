#pragma once
#include "Token.h"
#include "Tag.h"
class Num : // ÕûÊıÀà
	public Token
{
public:
	int value;

	Num(int v) { value = v; tag = Tag::NUM;}
	string ToString();
	Num() {};
	~Num();

	virtual void display();
};

