#pragma once
#include "Operator.h"
class Separator : // �ָ�����
	public Operator
{
public:
	Separator(string s) { content = s; /*tag = t; */}
	virtual void display();
	Separator();
	~Separator();
};

