#include <gtest/gtest.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class Solution {
public:
  string reverseVowels(string s) {
    int i = 0, j = s.size() - 1;
    bool Isvowel[300];
    memset(Isvowel, 0, 300);
    Isvowel['A'] = true;
    Isvowel['E'] = true;
    Isvowel['I'] = true;
    Isvowel['O'] = true;
    Isvowel['U'] = true;
    Isvowel['a'] = true;
    Isvowel['e'] = true;
    Isvowel['i'] = true;
    Isvowel['o'] = true;
    Isvowel['u'] = true;
    while (i < j)
      {
        while (!Isvowel[s[i]] && i < j) i++;
        while (!Isvowel[s[j]] && i < j) j--;
        if (i < j)
          swap(s[i++],s[j--]);
      }
    return s;
  }
};

TEST(ReverseVowels, GivenEmptyStringReturnsEmpty)
{
  Solution s;
  string expected;
  string input;
  ASSERT_EQ(expected, s.reverseVowels(input));
}

TEST(ReverseVowels, GivenOneCharStringReturnsSameString)
{
  Solution s;
  string expected = "a";
  string input = "a";
  ASSERT_EQ(expected, s.reverseVowels(input));
}

TEST(ReverseVowels, GivenStringVnReturnsSameString)
{
  Solution s;
  string expected = "ab";
  string input = "ab";
  ASSERT_EQ(expected, s.reverseVowels(input));
}

TEST(ReverseVowels, GivenStringnVReturnsSameString)
{
  Solution s;
  string expected = "ba";
  string input = "ba";
  ASSERT_EQ(expected, s.reverseVowels(input));
}

TEST(ReverseVowels, GivenStringVVReturnsReversedString)
{
  Solution s;
  string expected = "ai";
  string input = "ia";
  ASSERT_EQ(expected, s.reverseVowels(input));
}

TEST(ReverseVowels, GivenStringVnVReturnsReversedString)
{
  Solution s;
  string expected = "abi";
  string input = "iba";
  ASSERT_EQ(expected, s.reverseVowels(input));
}

TEST(ReverseVowels, GivenHelloReturnsHolle)
{
  Solution s;
  string expected = "holle";
  string input = "hello";
  ASSERT_EQ(expected, s.reverseVowels(input));
}

TEST(ReverseVowels, GivenAAA)
{
  Solution s;
  string expected = "Aa";
  string input = "aA";
  ASSERT_EQ(expected, s.reverseVowels(input));
}
