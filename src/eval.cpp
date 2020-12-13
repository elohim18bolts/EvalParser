#include "eval/eval.hpp"
#include "parser/parser.hpp"
#include "token/token.hpp"
#include <vector>
#include <iostream>
namespace eval
{

    Eval::Eval(const std::string &s) : string(s)
    {
        parser = parser::Parser(s);
        parser.Parse();
    }

    double Eval::evalOperation()
    {

        std::vector<parser::Token> tokens = parser.GetTokens();
        double a, b;
        double result;
        if (tokens[0].HasValue() && tokens[2].HasValue())
        {
            a = tokens[0].GetValue();
            b = tokens[2].GetValue();
        }
        switch (tokens[1].GetValueType())
        {
        case parser::TokenValue::PLUS:
            result = a + b;
            break;
        case parser::TokenValue::MINUS:
            result = a - b;
            break;
        case parser::TokenValue::MULT:
            result = a * b;
            break;
        case parser::TokenValue::DIVIDE:
            result = a / b;
            break;
        default:
            throw "Error in evaluating. No recognized operation passed in the string.";
        }
        return result;
    }

    double Eval::GetResult()
    {
        return evalOperation();
    }

} // namespace eval