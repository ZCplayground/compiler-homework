#pragma once
#include "Token.h"
#include "Tag.h"
#include <vector>
class Word : /* �����࣬���ڴ�� 1.���ϴʷ���Ԫ������ &&��
								����2. �ؼ��֣�Ӣ�ģ�keyword
								����3. ��ʶ����Ӣ�ģ�ident*/
	public Token
{
public:
	string lexeme = "";   // ���أ�����˵���Ǵ���Ǹ���Ӧ�Ĵ�
	string catagory = ""; // ���������Ǹ��ϴʷ���Ԫ�Ͳ������Tag��ʶ��
						  // �����Ҫô��ident��Ҫô��keyword

	Word(string s, int t) { lexeme = s; tag = t;  } // ���ϴʷ���Ԫ��������캯��
	Word(string s, int t, string c) { tag = t; lexeme = s; catagory = c; } // keyword��ident��������캯��˵��catagory
	string ToString() { return lexeme; }

	Word() {};
	~Word();

	virtual void display();
};

