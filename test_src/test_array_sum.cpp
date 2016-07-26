#include <gtest/gtest.h>
#include <numeric>
#include <vector>

using namespace std;

class NumArray {
public:
    explicit NumArray(vector<int> &nums)
      : m_part_sums(nums.size()) {
      partial_sum(nums.begin(), nums.end(), m_part_sums.begin());
    }

    int sumRange(int i, int j) {
      if (i > j) return 0;
      return m_part_sums[j] - m_part_sums[i - 1];
    }

private:
  vector<int> m_part_sums;
};


TEST(TestSumNumbers, Test1)
{
  vector<int> nums = {-2, 0, 3, -5, 2, -1};
  NumArray numArr(nums);
  ASSERT_EQ(1, numArr.sumRange(0, 2));
  ASSERT_EQ(-1, numArr.sumRange(2, 5));
  ASSERT_EQ(-3, numArr.sumRange(0, 5));
}



int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
