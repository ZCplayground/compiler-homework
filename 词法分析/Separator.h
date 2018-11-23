#pragma once
#include "Operator.h"
class Separator : // ·Ö¸ô·ûÀà
	public Operator
{
public:
	Separator(string s) { content = s; /*tag = t; */}
	virtual void display();
	Separator();
	~Separator();
};

