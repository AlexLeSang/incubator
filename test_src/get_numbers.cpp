#include <gtest/gtest.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <locale>
#include <limits>

using namespace std;

vector<int> get_digits(int n)
{
    stack<int> st;
    while (n > 0)
    {
        st.push(n % 10);
        n = n/10;
    }
    vector<int> result;
    while (!st.empty()) {result.push_back(st.top()); st.pop();}
    return result;
}

bool operator ==(const vector<int>& a, const vector<int>& b)
{
    return equal(a.begin(), a.end(), b.begin());
}

TEST(GetDigits, 1)
{
    vector<int> expected = {1};
    ASSERT_EQ(expected, get_digits(1));

    vector<int> expected_1 = {1, 2};
    ASSERT_EQ(expected_1, get_digits(12));

    vector<int> expected_2 = {1, 0, 2};
    ASSERT_EQ(expected_2, get_digits(102));
}
