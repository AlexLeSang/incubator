#include <gtest/gtest.h>
#include <tokenizer.hpp>

using namespace std;


TEST(TokenizerTest, GivenEmptyStringReturnsEmptyTokens)
{
    string s;
    auto t = tokenizer::tokenize(s);
    ASSERT_TRUE(t.empty());
}

TEST(TokenizerTest, GivenOneWordReturnsOneWord)
{
    string input = "word";
    auto result = tokenizer::tokenize(input);
    ASSERT_EQ(1, result.size());
    ASSERT_EQ(input, *result.begin());
}

TEST(TokenizerTest, GivenTwoWordsReturnsTwoElements)
{
    string first_word = "first";
    string second_word = "second";
    auto input = first_word + ' ' + second_word;
    auto result = tokenizer::tokenize(input);
    
    ASSERT_EQ(2, result.size());
    ASSERT_EQ(first_word, result.front());
    result.pop_front();
    ASSERT_EQ(second_word, result.front());
}

TEST(TokenizerTest, GivenTwoWordsMultipleSpacesReturnsTwoElements)
{
    string first_word = "first";
    string second_word = "second";
    auto input = first_word + ' ' + ' ' + second_word;
    auto result = tokenizer::tokenize(input);
    
    ASSERT_EQ(2, result.size());
    ASSERT_EQ(first_word, result.front());
    result.pop_front();
    ASSERT_EQ(second_word, result.front());
}

TEST(TokenizerTest, GivenThreeWordsReturnsThreeElements)
{
    string first_word = "first";
    string second_word = "second";
    string third_word = "third";
    auto input = first_word + ' ' + second_word + ' ' + third_word;
    auto result = tokenizer::tokenize(input);
    
    ASSERT_EQ(3, result.size());
    ASSERT_EQ(first_word, result.front());
    result.pop_front();
    ASSERT_EQ(second_word, result.front());
    result.pop_front();
    ASSERT_EQ(third_word, result.front());
}

TEST(TokenizerTest, GivenManyTokensReturnsAll)
{
    auto input = "t1 t2 t3 t4 t5 t6 t7 t8 t9 t10 t11";
    auto result = tokenizer::tokenize(input);
    
    ASSERT_EQ(11, result.size());
}

// int main(int argc, char **argv) {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
