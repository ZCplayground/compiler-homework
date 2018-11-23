#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>
#include"Token.h"    // 词法单元基类
#include"Word.h"     // 复合词法单元
#include"Operator.h" // 运算符
#include"Num.h"      // 整数
#include"Real.h"     // 浮点数
#include"Separator.h"// 分隔符


using namespace std;

unordered_map<string, int> words;
unordered_map<string, int>::iterator iter;

void reserve(Word w) // 保存一个 keyword 到哈希表
{
	pair<string, int>p = pair<string, int>(w.lexeme, w.tag);
	words.insert(p);
}

char peek = ' '; // 当前考虑的字符
int i = 0;       // 输入指针
char buffer[4096]; // 缓冲区

int line = 1; // 用于输出行号，调错用

void readch() // 读取缓冲区的下一个字符
{
	peek = buffer[i];
	i++;
}

bool readch(char c) // 读取缓冲区的下一个字符，若等于参数c返回true，否则返回false
{
	readch();
	if (peek != c) { 
		return false;
	}
	peek = ' ';
	return true;
}

Token * scan()
{
	for (;; readch())
	{
		if (peek == ' ' || peek == '\t') continue;
		else if (peek == '\n') line = line + 1;
		else break;
	}
	switch (peek) // 1.先识别复合词法单元 Word 或运算符 Operator 或分隔符 Separator
	{
		// 能够识别的复合词法单元和运算符都要列在这里
	case'&': 
		if (readch('&')) return new Word("&&", Tag::LOGICAL_AND); else return new Operator("&", Tag::AND); 
	case'|':
		if (readch('|')) return new Word("||", Tag::LOGICAL_OR); else return new Operator("|", Tag::OR); 
	case'=':
		if (readch('='))return new Word("==", Tag::EQ); else return new Operator("=", Tag::ASSIGN);
	case'!':
		if (readch('='))return new Word("!=", Tag::NE); else return new Operator("!", Tag::NON); 
	case '<':
		if (readch('='))return new Word("<=", Tag::LE); else return new Operator("<", Tag::LESS);
	case '>':
		if (readch('='))return new Word("<=", Tag::GE); else return new Operator(">", Tag::GREATER);
	case '(':
		readch(); return new Separator("(");
	case ')':
		readch(); return new Separator(")");
	case '{':
		readch(); return new Separator("{");
	case '}':
		readch(); return new Separator("}");
	case '+':
		readch(); return new Operator("+", Tag::ADD);
	case '-':
		readch(); return new Operator("-", Tag::SUB);
	case '*':
		readch(); return new Operator("*", Tag::MUL);
	case '/':
		readch(); return new Operator("/", Tag::DIV);

	default:
		break;
	}

	if (isdigit(peek))// 2.识别数字
	{
		int v = 0;
		do {
			v = 10 * v + (peek - '0');
			readch();
		} while (isdigit(peek));
		if (peek != '.') // 如果没有识别到小数点，返回整数
			return new Num(v); 
		double x = v;
		double d = 10;
		for (;;) {
			readch();
			if (!isdigit(peek))break;
			x = x + ((peek - '0') / d);
			d = d * 10;
		}
		return new Real(x); // 否则返回小数
	}

	if (isalpha(peek)) { // 3.识别keyword或identifier
		string s = "";
		do {
			s += peek;
			readch();
		} while (isalnum(peek));
		
		iter = words.find(s);
		if (iter == words.end()) { // 若没有在哈希表中查到，就不是keyword，而是identifier
			return new Word(s, Tag::ID, "idnet");
		}
		else { // 若能在哈希表中查到，就是keyword
			return new Word(iter->first, iter->second, "keyword"); 
		}
	}
	Token * tok = new Token(peek); peek = ' ';
	return tok;
}

int main()
{
	ifstream f;
	f.open("input.txt", ios::in);
	f.seekg(0, f.end);
	int length = f.tellg();
	f.seekg(0, f.beg);
	printf("input length : %d\n", length);
	f.read(buffer, length); // 读入文件全部内容

	// 复合词法单元
	Word my_and = Word("&&", Tag::LOGICAL_AND), my_or = Word("||", Tag::LOGICAL_OR),
		eq = Word("==", Tag::EQ), ne = Word("!=", Tag::NE),
		le = Word("<=", Tag::LE), ge = Word(">=", Tag::GE),

	// 能识别的关键字 keyword 列表如下：
	
	True = Word("true", Tag::TRUE),
	False = Word("false", Tag::FALSE),
	my_if = Word("if", Tag::IF),
	my_else = Word("else", Tag::ELSE),
	my_while = Word("while", Tag::WHILE),
	my_do = Word("do", Tag::DO),
	my_break = Word("break", Tag::BREAK);


	// 保存关键字到 hashtable
	reserve(True);
	reserve(False);
	reserve(my_if);
	reserve(my_else);
	reserve(my_while);
	reserve(my_do);
	reserve(my_break);

	for (int y = 0; y < 13; y++)
	{
		Token * t = scan();
		t->display();
	}
}

