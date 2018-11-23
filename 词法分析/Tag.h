#pragma once

class Tag
{
public:
	Tag();
	~Tag();

	// 需要有内部编码值的词法单元都要把属性值列在这里

	static const int
		LOGICAL_AND = 256, BASIC = 257, BREAK = 258, DO = 259, ELSE = 260,
		EQ = 261, FALSE = 262, GE = 263, ID = 264, IF = 265,
		INDEX = 266, LE = 267, MINUS = 268, NE = 269, NUM = 270,
		LOGICAL_OR = 271, REAL = 272, TEMP = 273, TRUE = 274, WHILE = 275,
		INT = 276, CHAR = 277, BOOL = 278, FLOAT = 279,
		AND = 280, OR = 281,

		ASSIGN = 282, NON = 283, LESS = 284, GREATER = 285,
		ADD = 286, SUB = 287, MUL = 288, DIV = 289;
};

