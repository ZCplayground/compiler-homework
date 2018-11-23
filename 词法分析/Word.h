#pragma once
#include "Token.h"
#include "Tag.h"
#include <vector>
class Word : /* 单词类，用于存放 1.复合词法单元，例如 &&，
								或者2. 关键字，英文：keyword
								或者3. 标识符，英文：ident*/
	public Token
{
public:
	string lexeme = "";   // 词素，简单来说就是存放那个对应的串
	string catagory = ""; // 类别。如果不是复合词法单元就不填，而用Tag标识。
						  // 否则就要么是ident，要么是keyword

	Word(string s, int t) { lexeme = s; tag = t;  } // 复合词法单元用这个构造函数
	Word(string s, int t, string c) { tag = t; lexeme = s; catagory = c; } // keyword和ident用这个构造函数说明catagory
	string ToString() { return lexeme; }

	Word() {};
	~Word();

	virtual void display();
};

