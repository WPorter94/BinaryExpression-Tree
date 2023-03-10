//Copyright 2021
#ifndef SYNTAX_ERROR_H_
#define SYNTAX_ERROR_H_
#include <stdexcept>

class Syntax_Error : public std::invalid_argument {
public:
    explicit Syntax_Error(const std::string& msg = std::string()) :
        std::invalid_argument(msg) {}
};
#endif
