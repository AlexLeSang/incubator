#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <locale>
#include <limits>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;
        int r = a;
        if (a > 0 && b > 0) while (b--) ++r;
        else if (a > 0 && b < 0) while (b++) --r;
        else if (a < 0 && b > 0) while (b--) ++r;
        else /*if (a < 0 && b < 0)*/ while (b++) --r;
        return r;
    }
};

TEST(PlusMinus, test)
{
  Solution s;
  ASSERT_EQ(3, s.getSum(1, 2));
  ASSERT_EQ(-1, s.getSum(1, -2));
  ASSERT_EQ(1, s.getSum(-1, 2));
  ASSERT_EQ(-3, s.getSum(-1, -2));
  ASSERT_EQ(-1, s.getSum(2147483647, -2147483648));
}
