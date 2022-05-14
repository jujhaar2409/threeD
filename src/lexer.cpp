#include "lexer.hpp"
#include "token.hpp"
#include <vector>

namespace Lex {
    bool is_type(std::string inp) {
        return (inp == "int" || inp == "char*" || inp == "const");
    }

    bool is_whitespace(char chr) {
        return (chr == ' ' || chr == '\n' || chr == '\t');
    }

    char Lexer::get_next_char() { return trans_unit.at(++chr_index); }

    void Lexer::setTranslationUnit(const std::string &translationUnit) {
        trans_unit = translationUnit;
    }

    Token Lexer::lexNextToken() {
//	get_next_char();
//	return Token("hi", IDENT);
        types_enum tok_type;
        std::string tok_val;
        char curr_char = trans_unit[chr_index];

        // ignoring multiple whitespace
        while (is_whitespace(curr_char)) curr_char = get_next_char();

        if (curr_char == '/') {
            curr_char = get_next_char();
            if (curr_char == '/') {
                while (curr_char != '\n') curr_char = get_next_char();
                chr_index++;
                return lexNextToken();
            }
        }

        if (isalpha(curr_char)) {
            // get the whole token
            std::string id_str;
            do {
                id_str += curr_char;
                curr_char = get_next_char();
            } while (isalnum(curr_char) || curr_char == '*');

            if (id_str == "return") { // ret
                tok_type = RET;
                tok_val = id_str;
            } else if (is_type(id_str)) { // type
                if (id_str == "const") {
                    tok_type = CONST;
                } else {
                    tok_type = TYPE;
                }
                tok_val = id_str;
            } else { // identifier
                tok_type = IDENT;
                tok_val = id_str;
            }
        } else if (isdigit(curr_char) || curr_char == '.') {
            std::string num_str;
            do {
                num_str += curr_char;
                curr_char = get_next_char();
            } while (isdigit(curr_char) || curr_char == '.');

            if (num_str.find('.') == std::string::npos) {
                tok_type = INT_LITERAL;
                tok_val = num_str;
            }

        } else if (curr_char == '"') {
            tok_type = STRING_LITERAL;
            std::string id_str;
            id_str += curr_char;
            do {
                curr_char = get_next_char();
                id_str += curr_char;
            } while (curr_char != '"');
            curr_char = get_next_char();
            tok_val = id_str;
        } else {
            if (curr_char == '(') {
                tok_type = OPARA;
            } else if (curr_char == ')') {
                tok_type = CPARA;
            } else if (curr_char == '{') {
                tok_type = OBRACE;
            } else if (curr_char == '}') {
                tok_type = CBRACE;
            } else if (curr_char == ';') {
                tok_type = SEMICOLON;
            } else if (curr_char == '=') {
                tok_type = OP_EQ;
            } else if (curr_char == ',') {
                tok_type = OP_COMMA;
            }
            tok_val = "";
            tok_val += curr_char;
            chr_index++;
        }

        return Token(tok_val, tok_type);
    }

    bool Lexer::eof() { return (trans_unit[chr_index] == '\0'); }
}
