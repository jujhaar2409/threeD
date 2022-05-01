#ifndef __LEXER_H__
#define __LEXER_H__

#include <vector>
#include "token.hpp"

namespace Lex
{

class Lexer
{
public:
	Lexer() = default;
	~Lexer() = default;

	void setTranslationUnit(const std::string& translationUnit) {}
	Token lexNextToken() { return Token(); }
	bool eof() const { return true; }
};

}


#endif // __LEXER_H__