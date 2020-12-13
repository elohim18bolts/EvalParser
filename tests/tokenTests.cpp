#include <gtest/gtest.h>
#include "token/token.hpp"
#include "parser/parser.hpp"
#include "eval/eval.hpp"
#include <string>
#include <vector>
TEST(parserTests, tokenTest)
{
    parser::Token t("+", parser::TokenType::OPERATION);
    parser::Token t2("785", parser::TokenType::NUMBER);
    parser::Token t3("myvariable", parser::TokenType::VARIABLE);
    EXPECT_EQ("{ type: Operation, valueType: Plus, value: None }", t.GetToken());
    EXPECT_EQ("{ type: Number, valueType: Number, value: 785 }", t2.GetToken());
    EXPECT_EQ("{ type: Variable, valueType: None, value: None }", t3.GetToken());
}

TEST(perserTest, parserTokensTests)
{
    parser::Parser sum("var-534+45");
    sum.Parse();
    EXPECT_EQ(5, sum.GetTokens().size());
    EXPECT_EQ("{ type: Variable, valueType: None, value: None }", sum.GetTokens()[0].GetToken());
    EXPECT_EQ("{ type: Operation, valueType: Minus, value: None }", sum.GetTokens()[1].GetToken());
    EXPECT_EQ("{ type: Number, valueType: Number, value: 534 }", sum.GetTokens()[2].GetToken());
    EXPECT_EQ("{ type: Operation, valueType: Plus, value: None }", sum.GetTokens()[3].GetToken());
    EXPECT_EQ("{ type: Number, valueType: Number, value: 45 }", sum.GetTokens()[4].GetToken());
}

TEST(evalTests, sumTest)
{
    eval::Eval sum("6+3");
    eval::Eval mult("10*23");
    eval::Eval div("34/12");
    eval::Eval minus("0-34");
    EXPECT_EQ(9, sum.GetResult());
    EXPECT_EQ(230, mult.GetResult());
    EXPECT_EQ(-34, minus.GetResult());
    EXPECT_EQ(34.0 / 12, div.GetResult());
}