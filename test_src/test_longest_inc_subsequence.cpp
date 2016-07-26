#include <gtest/gtest.h>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> longest_inc_subseq(const vector<int>& v) {
    if (!v.empty()) {
        auto current_seq = 0;
        auto prev_seq = 0;
        auto prev_seq_end = 0;
        for (auto i = 1; i < (int)v.size(); i++) {
            if (v[i - 1] < v[i]) {
                current_seq += 1;
                if (current_seq > prev_seq) {
                    prev_seq = current_seq;
                    prev_seq_end = i;
                }
            }
            else {
                current_seq = 0;
            }
        }

        auto sub_seq_begin = v.begin();
        advance(sub_seq_begin, prev_seq_end - prev_seq);
        auto sub_seq_end = v.begin();
        advance(sub_seq_end, prev_seq_end + 1);
        return vector<int>(sub_seq_begin, sub_seq_end);
    }
    return vector<int>();
}

// tests
TEST(TestLongestIncSubseq, GivenEmptyReturnsEmpty)
{
    vector<int> seq;
    auto res = longest_inc_subseq(seq);
    ASSERT_TRUE(res.empty());
}

TEST(TestLongestIncSubseq, GivenSingleItemReturnsSingleItem)
{
    vector<int> seq = {1};
    auto res = longest_inc_subseq(seq);

    vector<int> expected = {1};
    ASSERT_EQ(expected, res);
}

TEST(TestLongestIncSubseq, GivenTwoNonContiniousReturnsFirst)
{
    vector<int> seq = {2, 1};
    auto res = longest_inc_subseq(seq);

    vector<int> expected = {2};
    ASSERT_EQ(expected, res);
}

TEST(TestLongestIncSubseq, GivenTwoContiniousReturnsWhole)
{
    vector<int> seq = {1, 2};
    auto res = longest_inc_subseq(seq);

    vector<int> expected = {1, 2};
    ASSERT_EQ(expected, res);
}

TEST(TestLongestIncSubseq, GivenSmallLongSmallSequenceReturnsLong)
{
    vector<int> seq = {1000, 2000, 3000, 100, 200, 300, 400, 500, 1, 2, 3, 4};
    auto res = longest_inc_subseq(seq);

    vector<int> expected = {100, 200, 300, 400, 500};
    ASSERT_EQ(expected, res);
}

TEST(TestLongestIncSubseq, GivenSmallLongSmallSequenceReturnsLong1)
{
    vector<int> seq = {1, 2, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3};
    auto res = longest_inc_subseq(seq);

    vector<int> expected = {1, 2, 3, 4};
    ASSERT_EQ(expected, res);
}


