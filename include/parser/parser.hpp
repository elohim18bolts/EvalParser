#ifndef PARSER_HPP
#define PARSER_HPP
#include <vector>
#include "token/token.hpp"
namespace Parser
{
    class Parser
    {
    private:
        /** Store the generated tokens
         * 
         * */
        std::vector<Token> tokens;
        /** Currnet token to be proccesed
         * */
        Token currentToken;
        /** Pointer to the next token
        */
        char *cursor;
        std::string rawString;

    private:
        bool getNextToken();
        void eat(TokenType);
        std::string parseNumber();
        std::string parseOperation();
        std::string parseVariable();

    public:
        Parser(const std::string &);
        std::vector<Token> GetTokens() const;
        void Parse();
    };
} // namespace Parser

#endif