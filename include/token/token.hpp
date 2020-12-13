#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

namespace Parser
{

    enum class TokenType
    {
        NONE,
        OPERATION,
        NUMBER,
        VARIABLE
    };
    enum class TokenValue
    {
        NONE,
        NUMBER,
        PLUS,
        MINUS,
        MULT,
        DIVIDE
    };

    class Token
    {
    private:
        /**
         * It represents the type of the token passed in the constructor
         * Type are: NULL, NUMBER, OPERATION, VARIABLE
         */
        TokenType type;
        /**
         * It represents the value type of the constructor parameter
         * It can be NONE, which is used invalid token types.
         * The other values are: NUMBER, PLUS, MINUS, MULT, DIVIDE
         * */
        TokenValue valueType;
        /**
         * This variable will store a numeric value in case that the 
         * constructor recieves a number type token
         */
        double value;

        /**
         * This variable contains the variable name in case of a type 
         * variable is passed to the constructor
         * */
        std::string variableName;

    public:
        Token(const std::string &token, TokenType type);
        Token(const Token &) = default;
        Token(Token &&) = delete;
        Token &operator=(const Token &) = default;
        Token &operator=(Token &&) = default;
        Token() = default;

    public:
        std::string GetToken() const;
        TokenType GetType();
    };
} // namespace Parser

#endif
