#include <gtest/gtest.h>
#include <queue>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    if (NULL == root) return NULL;
    std::queue<TreeNode* > q;
    q.push(root);

    while (!q.empty()) {
      TreeNode* i = q.front(); q.pop();
      if ((NULL != i->left) && (NULL != i->right)) std::swap(i->left, i->right);
      if (NULL != i->left) q.push(i->left);
      if (NULL != i->right) q.push(i->right);
    }
    return root;
  }
};

bool operator==(const TreeNode& a, const TreeNode& b)
{
  return (a.val == b.val) && (a.left == b.left) && (a.right == b.right);
}

TEST(ReverseBST, GivenNullReturnsNull)
{
  Solution s;
  TreeNode* root = NULL;
  TreeNode* expected = NULL;
  ASSERT_EQ(expected, s.invertTree(root));
}

TEST(ReverseBST, GivenOneNodeReturnsOneNode)
{
  Solution s;
  TreeNode root(10);
  TreeNode expected(10);
  ASSERT_TRUE(expected == *s.invertTree(&root));
}

TEST(ReverseBST, BFS)
{
  TreeNode n4(4);
  TreeNode n2(2);
  TreeNode n7(7);
  TreeNode n1(1);
  TreeNode n3(3);
  TreeNode n6(6);
  TreeNode n9(9);

  n2.left = &n1;
  n2.right = &n3;

  n7.left = &n6;
  n7.right = &n9;

  n4.left = &n2;
  n4.right = &n7;

  Solution s;
  s.invertTree(&n4);
}
