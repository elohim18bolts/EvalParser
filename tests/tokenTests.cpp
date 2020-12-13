#include <gtest/gtest.h>
#include "token/token.hpp"
#include "parser/parser.hpp"
#include <string>
#include <vector>
TEST(parserTests, tokenTest)
{
    Parser::Token t("+", Parser::TokenType::OPERATION);
    Parser::Token t2("785", Parser::TokenType::NUMBER);
    Parser::Token t3("myvariable", Parser::TokenType::VARIABLE);
    EXPECT_EQ("{ type: Operation, valueType: Plus, value: None }", t.GetToken());
    EXPECT_EQ("{ type: Number, valueType: Number, value: 785 }", t2.GetToken());
    EXPECT_EQ("{ type: Variable, valueType: None, value: None }", t3.GetToken());
}

TEST(perserTest, parserTokensTests)
{
    Parser::Parser sum("var-534+45");
    sum.Parse();
    EXPECT_EQ(5, sum.GetTokens().size());
    EXPECT_EQ("{ type: Variable, valueType: None, value: None }", sum.GetTokens()[0].GetToken());
    EXPECT_EQ("{ type: Operation, valueType: Minus, value: None }", sum.GetTokens()[1].GetToken());
    EXPECT_EQ("{ type: Number, valueType: Number, value: 534 }", sum.GetTokens()[2].GetToken());
    EXPECT_EQ("{ type: Operation, valueType: Plus, value: None }", sum.GetTokens()[3].GetToken());
    EXPECT_EQ("{ type: Number, valueType: Number, value: 45 }", sum.GetTokens()[4].GetToken());
}