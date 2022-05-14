#ifndef __LEXER_H__
#define __LEXER_H__

#include <vector>
#include "token.hpp"
// #include <string>

namespace Lex
{

class Lexer
{
	std::string trans_unit;
	int chr_index = 0;
	char get_next_char();
public:
	Lexer() = default;
	~Lexer() = default;

	void setTranslationUnit(const std::string& translationUnit);
	Token lexNextToken();
	bool eof();
};
}

#endif // __LEXER_H__