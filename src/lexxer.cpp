#include "include/lexxer.hpp"
#include "include/util.hpp"

// Shorthand for tokens with no value
#define ETOKEN(type) Token{std::monostate{}, type}

std::vector<Token> lex(std::string_view src) {
    size_t pos = 0;
    std::vector<Token> tokens;

    while (pos < src.length()) {
        char cur_byte = src[pos];

        if (is_whitespace(cur_byte)) {
            pos++;
            continue;
        }

        if (is_num(cur_byte)) {
            tokens.push_back(lex_num(&pos, src));
            continue;
        }

        if (cur_byte == '\'' || cur_byte == '"') {
            tokens.push_back(lex_str(&pos, src));
            continue;
        }

        if (cur_byte == '(') {
            tokens.push_back(ETOKEN(TokenType::LParen));
            pos++;
            continue;
        }

        if (cur_byte == ')') {
            tokens.push_back(ETOKEN(TokenType::RParen));
            pos++;
            continue;
        }

        if (is_alpha(cur_byte)) {
            tokens.push_back(lex_word(&pos, src));
            continue;
        }

        // Finally if we encounter some unknown random character we should either throw
        // or panic or log the error idk what we want to do yet so just panic for now
        panic("Unkown character");
    }
}

// TODO: Implement these 
Token lex_num(size_t *pos, std::string_view src);

Token lex_str(size_t *pos, std::string_view src);

Token lex_op(size_t *pos, std::string_view src);

Token lex_word(size_t *pos, std::string_view src);