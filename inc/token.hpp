#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <string>

namespace Lex
{

class Token
{

public:
	Token() = default;
	~Token() = default;

	std::string stringRepresentation() const { return ""; }
};

}

#endif // __TOKEN_H__