#include <gtest/gtest.h>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string reverseString(string s) {
    if (s.empty()) return string();
    if (s.length() == 1) return s;
    return string(s.rbegin(), s.rend());
  }
};

// Here go tests
TEST(Problem, GivenEmptyStringReturnsEmptyString)
{
  Solution s;
  ASSERT_EQ(string(), s.reverseString(string()));
}

TEST(Problem, GivenOneCharStringReturnsSameString)
{
  Solution s;
  string input = "a";
  string expected = "a";
  ASSERT_EQ(expected, s.reverseString(input));
}

TEST(Problem, GivenTwoCharStringReturnsReversed)
{
  Solution s;
  string input = "ab";
  string expected = "ba";
  ASSERT_EQ(expected, s.reverseString(input));
}

TEST(Problem, GivenLongStringReturnsReversed)
{
  Solution s;
  string input = "abcdefgh";
  string expected = "hgfedcba";
  ASSERT_EQ(expected, s.reverseString(input));
}
