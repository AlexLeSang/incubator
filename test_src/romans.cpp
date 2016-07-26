#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <locale>
#include <limits>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        // for (auto& ch: s) {
        //     ch = tolower(ch);
        // }
        replaceAll(s, "IV", "IIII");
        replaceAll(s, "IX", "VIIII");
        replaceAll(s, "XL", "XXXX");
        replaceAll(s, "XC", "LXXXX");
        replaceAll(s, "CD", "CCCC");
        replaceAll(s, "CM", "DCCCC");
        // vector<int> transformed(s.length());
        // for (auto& c: s) {
        //     transformed.push_back(GetValue(c));
        // }
        return accumulate(s.begin(), s.end(), 0, [](const int b, const char a){return GetValue(a) + b;});
    }

private:
    static void replaceAll(std::string& str, const std::string& from, const std::string& to)
    {
        if(from.empty())
            return;
        size_t start_pos = 0;
        while((start_pos = str.find(from, start_pos)) != std::string::npos) {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length();
        }
    }

    static int GetValue(const char ch)
    {
        if ('I' == ch) return 1;
        if ('V' == ch) return 5;
        if ('X' == ch) return 10;
        if ('L' == ch) return 50;
        if ('C' == ch) return 100;
        if ('D' == ch) return 500;
        if ('M' == ch) return 1000;
        return numeric_limits<int>::min();
    }

};

TEST(Roman, test)
{
  Solution s;
  ASSERT_EQ(1, s.romanToInt("i"));
  ASSERT_EQ(2, s.romanToInt("ii"));
  ASSERT_EQ(3, s.romanToInt("iii"));
  ASSERT_EQ(4, s.romanToInt("iv"));
  ASSERT_EQ(9, s.romanToInt("ix"));
  ASSERT_EQ(40, s.romanToInt("xl"));
  ASSERT_EQ(90, s.romanToInt("xc"));
  ASSERT_EQ(400, s.romanToInt("cd"));
  ASSERT_EQ(900, s.romanToInt("cm"));
}
