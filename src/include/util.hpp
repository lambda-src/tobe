#pragma once

#include <string>

// Print a error message and exit
void panic(const std::string& err);

inline bool is_whitespace(char ch);

inline bool is_num(char ch);

inline bool is_alpha(char ch);