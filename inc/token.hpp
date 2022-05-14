#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <string>

namespace Lex
{
enum types_enum {TYPE, IDENT, OPARA, CPARA, OBRACE, CBRACE,
                RET, INT_LITERAL, SEMICOLON, OP_EQ, OP_COMMA,
                CONST, STRING_LITERAL};

class Token
{
	std::vector<std::string> types_str {"TYPE", "IDENT", "OPARA", "CPARA", "OBRACE", "CBRACE",
                                        "RET", "INT_LITERAL", "SEMICOLON", "OP_EQ", "OP_COMMA",
                                        "CONST", "STRING_LITERAL"};
	std::string tok_val;
	types_enum tok_type;

public:
	// Token() = default;
	~Token() = default;

	Token(std::string val, types_enum type) 
	{
		tok_type = type;
		tok_val = val;
	}

	std::string stringRepresentation() const 
	{ 
		return types_str[tok_type] + " " + tok_val; 
	}

	std::string getTypeStr() const 
	{
		return types_str[tok_type];
	}
	types_enum getType() const 
	{
		return tok_type;
	}
	void setType(types_enum type) 
	{
		tok_type = type;
	}
	std::string getVal() const 
	{
		return tok_val;
	}
};

}

#endif // __TOKEN_H__