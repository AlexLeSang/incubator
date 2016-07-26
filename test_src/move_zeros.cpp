#include <gtest/gtest.h>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      uint j = 0;
      for (uint i = 0; i < nums.size(); ++i)
        if (nums[i] != 0) nums[j++] = nums[i];

      for (; j < nums.size(); ++j) nums[j] = 0;
    }
};


TEST(MoveZeros, GivenEmptyArr)
{
  const vector<int> expected;
  vector<int> input;
  
  Solution s;
  s.moveZeroes(input);
  ASSERT_EQ(expected, input);
}


TEST(MoveZeros, Given1)
{
  vector<int> input{0, 1, 0, 3, 12};
  const vector<int> expected{1, 3, 12, 0, 0};

  Solution s;
  s.moveZeroes(input);
  ASSERT_EQ(expected, input);
}
