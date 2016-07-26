#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      if (nums1.size() > nums2.size()) return intersection(nums2, nums1);

      sort(nums1.begin(), nums1.end());
      sort(nums2.begin(), nums2.end());
      nums1.erase(unique(nums1.begin(), nums1.end()), nums1.end());
      nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());

      vector<int> inter;
      auto it = nums2.cbegin();
      for (const auto& num: nums1) {
        it = lower_bound(it, nums2.cend(), num);
        if (it != nums2.cend() && *it == num) {
          inter.emplace_back(*it++);
        }
      }
      inter.erase(unique(inter.begin(), inter.end()), inter.end());
      return inter;
    }
};

TEST(Intersection, 1)
{
  Solution s;
  vector<int> i_nums1{1, 2, 2, 1};
  vector<int> i_nums2{2, 2};
  const vector<int> expected{2};
  ASSERT_EQ(expected, s.intersection(i_nums1, i_nums2));
}

TEST(Intersection, 2)
{
  Solution s;
  vector<int> i_nums1{2, 1};
  vector<int> i_nums2{1, 2};
  const vector<int> expected{1, 2};
  ASSERT_EQ(expected, s.intersection(i_nums1, i_nums2));
}
