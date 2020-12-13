#include "token/token.hpp"
#include <string>
#include <sstream>
namespace Parser
{
    Token::Token(const std::string &token, TokenType type) : type(type)
    {
        if (type == TokenType::NUMBER)
        {
            value = std::stod(token);
        }
        else if (type == TokenType::VARIABLE)
        {
            valueType = TokenValue::NONE;
            variableName = token;
        }
        else if (type == TokenType::OPERATION)
        {
            char t = token[0];
            switch (t)
            {
            case '+':
                valueType = TokenValue::PLUS;
                break;
            case '-':
                valueType = TokenValue::MINUS;
                break;
            case '*':
                valueType = TokenValue::MULT;
                break;
            case '/':
                valueType = TokenValue::DIVIDE;
                break;
            default:
                valueType = TokenValue::NONE;
                break;
            }
        }
        else
        {
            throw "Token with None type has no value or significance.";
        }
    }

    std::string Token::GetToken() const
    {
        std::string t = "";
        std::ostringstream stringStream;
        switch (type)
        {
        case TokenType::NUMBER:
            stringStream << "{ type: Number, valueType: Number, value: " << value << " }";
            t = stringStream.str();
            break;
        case TokenType::OPERATION:
            t = "{ type: Operation, ";
            switch (valueType)
            {
            case TokenValue::PLUS:
                t += "valueType: Plus, value: None }";
                break;
            case TokenValue::MINUS:
                t += "valueType: Minus, value: None }";
                break;
            case TokenValue::DIVIDE:
                t += "valueType: Division, value: None }";
            case TokenValue::MULT:
                t += "valueType: Multiplication, value: None }";
                break;
            default:
                break;
            }
            break;
        case TokenType::VARIABLE:
            t = "{ type: Variable, valueType: None, value: None }";
            break;
        default:
            t = "Token not recognized.";
            break;
        }

        return t;
    }

    TokenType Token::GetType()
    {
        return type;
    }
} // namespace Parser