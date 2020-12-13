#include "token/token.hpp"
#include "parser/parser.hpp"
#include <vector>
#include <string>

namespace parser
{
    Parser::Parser(const std::string &s) : rawString(s)
    {
        cursor = &rawString[0];
    }

    Parser::Parser(const Parser &other) : rawString(other.rawString)
    {
        cursor = &rawString[0];
    }

    void Parser::Parse()
    {
        while (getNextToken())
        {
            tokens.push_back(currentToken);
        }
    }

    bool Parser::getNextToken()
    {
        //Check if the first character in the string is a number
        if (*cursor >= '0' && *cursor <= '9')
        {
            currentToken = Token(parseNumber(), TokenType::NUMBER);
        }
        else if (*cursor == '+' || *cursor == '-' || *cursor == '*' || *cursor == '/')
        {
            currentToken = Token(parseOperation(), TokenType::OPERATION);
        }
        else if (*cursor >= 'a' && *cursor <= 'z')
        {
            currentToken = Token(parseVariable(), TokenType::VARIABLE);
        }
        else if (*cursor == 0)
        {
            return false;
        }
        else
        {
            throw "Right now there is only number + number implementation.";
            return false;
        }
        return true;
    }
    std::string Parser::parseNumber()
    {
        std::string number = "";
        while (*cursor >= '0' && *cursor <= '9')
        {
            number += *cursor;
            cursor++;
        }

        return number;
    }

    std::string Parser::parseOperation()
    {
        std::string op;
        switch (*cursor)
        {
        case '+':
            op = "+";
            break;
        case '-':
            op = "-";
            break;
        case '*':
            op = "*";
            break;
        case '/':
            op = "/";
            break;
        default:
            op = "None";
            break;
        }
        cursor++;
        return op;
    }
    std::string Parser::parseVariable()
    {
        std::string var = "";
        while (*cursor <= 'z' && *cursor >= 'a')
        {
            var += *cursor;
            cursor++;
        }
        return var;
    }

    std::vector<Token> Parser::GetTokens() const
    {
        return tokens;
    }

} // namespace parser