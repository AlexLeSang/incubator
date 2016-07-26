#include <memory>
#include <vector>
#include <gtest/gtest.h>
#include <vector>
#include <iterator>
#include <tuple>
#include <queue>
#include <iostream>

using namespace std;

struct Node {
    int x;
    int y;
    Node* parent;
    vector<Node> children;

    Node() : x(0), y(0), parent(nullptr) {}
    Node(int _x, int _y, Node* _parent) : x(_x), y(_y), parent(_parent) {}
};


bool BFS(const Node* root, int x, int y)
{
    if (root == nullptr) return false;
    if (root->x == x && root->y == y) return true;

    queue<tuple<const Node*, int>> Q;
    int level = 0;
    Q.emplace(root, level);
    ++level;

    bool has_x = false;
    bool has_y = false;

    int search_level = 0;
        
    while (!Q.empty()) {
        auto c = Q.front();
        Q.pop();

        cout << "(" << get<0>(c)->x << ',' << get<0>(c)->y << "): " << get<1>(c);
        
        cout << " search_level: " << search_level << endl;
        if (get<1>(c) != search_level) {
            has_x = false;
            has_y = false;
            search_level = get<1>(c);
        }

        auto l_has_x = get<0>(c)->x == x;
        //cout << "l_has_x: " << l_has_x << endl;
        //cout << "has_x: " << has_x << endl;
        has_x |= l_has_x;
        //cout << "has_x: " << has_x << endl;

        auto l_has_y = get<0>(c)->y == y;
        //cout << "l_has_y: " << l_has_y << endl;
        //cout << "has_y: " << has_y << endl;
        has_y |= l_has_y;
        //cout << "has_y: " << has_y << endl;
            
        if (has_x && has_y) return true;

                
        for (const Node& ch: get<0>(c)->children) {
            Q.emplace(&ch, get<1>(c) + 1);
        }
    }

    return false;
}


TEST(TestTree, DefaultConstructNode)
{
    Node empty;
    ASSERT_EQ(0, empty.x);
    ASSERT_EQ(0, empty.y);
    ASSERT_EQ(nullptr, empty.parent);
    ASSERT_TRUE(BFS(&empty, 0, 0));
    ASSERT_FALSE(BFS(&empty, 1, 1));
    ASSERT_FALSE(BFS(&empty, 0, 1));
    ASSERT_FALSE(BFS(&empty, 1, 0));
}

TEST(TestTree, ConstructNode)
{
    Node n(1, 2, (Node*)0xDEAFBEEF);
    ASSERT_EQ(1, n.x);
    ASSERT_EQ(2, n.y);
    ASSERT_EQ((Node*)0xDEAFBEEF, n.parent);
    ASSERT_TRUE(BFS(&n, 1, 2));
    ASSERT_FALSE(BFS(&n, 0, 2));
    ASSERT_FALSE(BFS(&n, 1, 0));
}


TEST(TestTree, CreateTree)
{
    Node r;
    Node ch1(1, 2, &r);
    Node ch2(3, 4, &r);
    
    Node ch11(11, 12, &ch1);
    Node ch12(13, 14, &ch1);
    ch1.children.push_back(ch11);
    ch1.children.push_back(ch12);

    Node ch21(21, 22, &ch2);
    Node ch22(23, 24, &ch2);
    ch2.children.push_back(ch21);
    ch2.children.push_back(ch22);

    r.children.push_back(ch1);
    r.children.push_back(ch2);

    ASSERT_EQ(2, r.children.size());
    ASSERT_EQ(1, r.children[0].x);
    ASSERT_EQ(2, r.children[0].y);

    ASSERT_EQ(3, r.children[1].x);
    ASSERT_EQ(4, r.children[1].y);
    
    ASSERT_EQ(11, r.children[0].children[0].x);
    ASSERT_EQ(12, r.children[0].children[0].y);

    ASSERT_EQ(13, r.children[0].children[1].x);
    ASSERT_EQ(14, r.children[0].children[1].y);
    

    ASSERT_EQ(21, r.children[1].children[0].x);
    ASSERT_EQ(22, r.children[1].children[0].y);

    ASSERT_EQ(23, r.children[1].children[1].x);
    ASSERT_EQ(24, r.children[1].children[1].y);

    ASSERT_TRUE(BFS(&r, 1, 4));
    ASSERT_TRUE(BFS(&r, 3, 2));
    
    ASSERT_TRUE(BFS(&r, 11, 24));
    ASSERT_TRUE(BFS(&r, 13, 22));
    
    ASSERT_TRUE(BFS(&r, 21, 24));
    ASSERT_TRUE(BFS(&r, 23, 22));
}
