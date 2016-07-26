#include <gtest/gtest.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    return NULL;
  }
};



TEST(MaxBSTDepth, 1)
{
  FAIL();
}
