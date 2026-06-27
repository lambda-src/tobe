#pragma once

#include <variant>
#include <string_view>
#include <optional>
#include <vector>

// An identifier for each "piece" of the source code
enum class TokenType {
    Number,
    Float,
    Bool,
    String,
    Ident,
    Keyword,
    Op,
    LParen,
    RParen,
};

// For any value tokens we need to know what value it's currently holding
using TokenValue = std::variant<std::monostate, bool, int, float, std::string_view>;

struct Token {
    TokenValue val;
    TokenType type;
};

// Lex the src code and return a dyn arr of tokens
std::vector<Token> lex(std::string_view src);

Token lex_num(size_t *pos, std::string_view src);

Token lex_str(size_t *pos, std::string_view src);

Token lex_op(size_t *pos, std::string_view src);

// Since we're lexxing this byte by byte things like true, if, my_variable all
// have the exact same structure despite being identifiers, keywords, and bools 
// so if we encounter an alphanumeric char then parse it accordingly
Token lex_word(size_t *pos, std::string_view src);