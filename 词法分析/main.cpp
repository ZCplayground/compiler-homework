#include<iostream>
#include<string>
#include<unordered_map>
#include<fstream>
#include"Token.h"    // �ʷ���Ԫ����
#include"Word.h"     // ���ϴʷ���Ԫ
#include"Operator.h" // �����
#include"Num.h"      // ����
#include"Real.h"     // ������
#include"Separator.h"// �ָ���


using namespace std;

unordered_map<string, int> words;
unordered_map<string, int>::iterator iter;

void reserve(Word w) // ����һ�� keyword ����ϣ��
{
	pair<string, int>p = pair<string, int>(w.lexeme, w.tag);
	words.insert(p);
}

char peek = ' '; // ��ǰ���ǵ��ַ�
int i = 0;       // ����ָ��
char buffer[4096]; // ������

int line = 1; // ��������кţ�������

void readch() // ��ȡ����������һ���ַ�
{
	peek = buffer[i];
	i++;
}

bool readch(char c) // ��ȡ����������һ���ַ��������ڲ���c����true�����򷵻�false
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
	switch (peek) // 1.��ʶ�𸴺ϴʷ���Ԫ Word ������� Operator ��ָ��� Separator
	{
		// �ܹ�ʶ��ĸ��ϴʷ���Ԫ���������Ҫ��������
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

	if (isdigit(peek))// 2.ʶ������
	{
		int v = 0;
		do {
			v = 10 * v + (peek - '0');
			readch();
		} while (isdigit(peek));
		if (peek != '.') // ���û��ʶ��С���㣬��������
			return new Num(v); 
		double x = v;
		double d = 10;
		for (;;) {
			readch();
			if (!isdigit(peek))break;
			x = x + ((peek - '0') / d);
			d = d * 10;
		}
		return new Real(x); // ���򷵻�С��
	}

	if (isalpha(peek)) { // 3.ʶ��keyword��identifier
		string s = "";
		do {
			s += peek;
			readch();
		} while (isalnum(peek));
		
		iter = words.find(s);
		if (iter == words.end()) { // ��û���ڹ�ϣ���в鵽���Ͳ���keyword������identifier
			return new Word(s, Tag::ID, "idnet");
		}
		else { // �����ڹ�ϣ���в鵽������keyword
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
	f.read(buffer, length); // �����ļ�ȫ������

	// ���ϴʷ���Ԫ
	Word my_and = Word("&&", Tag::LOGICAL_AND), my_or = Word("||", Tag::LOGICAL_OR),
		eq = Word("==", Tag::EQ), ne = Word("!=", Tag::NE),
		le = Word("<=", Tag::LE), ge = Word(">=", Tag::GE),

	// ��ʶ��Ĺؼ��� keyword �б����£�
	
	True = Word("true", Tag::TRUE),
	False = Word("false", Tag::FALSE),
	my_if = Word("if", Tag::IF),
	my_else = Word("else", Tag::ELSE),
	my_while = Word("while", Tag::WHILE),
	my_do = Word("do", Tag::DO),
	my_break = Word("break", Tag::BREAK);


	// ����ؼ��ֵ� hashtable
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

