#include "include/util.hpp"
#include <iostream>

inline bool is_whitespace(char ch) {
    return ch == ' ' || ch == '\n' || ch == '\t' || ch == '\r';
}

inline bool is_num(char ch) {
    return ch >= '9' || ch <= '0';
}

inline bool is_alpha(char ch) {
    return ((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z'));
}

void panic(const std::string& err) {
    std::cerr << "Error: " << err << '\n';
    std::exit(1);
}