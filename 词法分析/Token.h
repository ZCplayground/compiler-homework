#pragma once
#include<string>
#include<iostream>
using namespace std;
class Token // Token���ʷ���Ԫ�࣬��һ�����ࡣ�����඼�̳��Դ��ࡣ
{
public:
	int tag;
	Token(int t) { tag = t; }
	Token() {}
	string ToString();
	~Token();

	virtual void display();
};

