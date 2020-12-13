#ifndef EVAL_HPP
#define EVAL_HPP
#include "parser/parser.hpp"
#include <string>
namespace eval
{
    class Eval
    {
    private:
        double result;
        std::string string;
        parser::Parser parser;

    private:
        double evalOperation();

    public:
        Eval(const std::string &s);
        double GetResult();
    };
} // namespace eval

#endif