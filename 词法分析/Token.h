#pragma once
#include<string>
#include<iostream>
using namespace std;
class Token // Token：词法单元类，是一个基类。其他类都继承自此类。
{
public:
	int tag;
	Token(int t) { tag = t; }
	Token() {}
	string ToString();
	~Token();

	virtual void display();
};

