#include <gtest/gtest.h>

class Solution {
public:
  bool canWinNim(int n) {
    return n % 4;
  }
};

TEST(NimGame, 1)
{
  Solution s;
  ASSERT_TRUE(s.canWinNim(1));
}

TEST(NimGame, 2)
{
  Solution s;
  ASSERT_TRUE(s.canWinNim(2));
}

TEST(NimGame, 3)
{
  Solution s;
  ASSERT_TRUE(s.canWinNim(3));
}

TEST(NimGame, 4)
{
  Solution s;
  ASSERT_FALSE(s.canWinNim(4));
}

TEST(NimGame, 5)
{
  Solution s;
  ASSERT_TRUE(s.canWinNim(5));
}

TEST(NimGame, 6)
{
  Solution s;
  ASSERT_TRUE(s.canWinNim(6));
}

TEST(NimGame, 7)
{
  Solution s;
  ASSERT_TRUE(s.canWinNim(7));
}

TEST(NimGame, 8)
{
  Solution s;
  ASSERT_FALSE(s.canWinNim(8));
}

TEST(NimGame, 9)
{
  Solution s;
  ASSERT_TRUE(s.canWinNim(9));
}
