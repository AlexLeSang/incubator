#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <iterator>

typedef std::size_t Size;

template<typename Key, typename T, Size MAX>
class static_map
{
public:
    typedef std::vector<Key> Keys;
private:
    Size m_size;
    Keys m_keys;
public:
    static_map():
        m_size(0)
    {}

    // Capacity
    Size size() const
    {
        return m_size;
    }

    Size max_size() const
    {
        return MAX;
    }

    bool empty() const
    {
        return 0 == m_size;
    }

    T& operator[](const Key& k)
    {
        typename Keys::iterator it = std::find(std::begin(m_keys), std::end(m_keys), k);
        if (std::end(m_keys) == it)
        {
            // Operator doesn't exist
            m_keys.push_back(k);
        }
        else
        {
            // TODO
        }
        ++m_size;
    }
};

TEST(MapTest, CreateEmptyMap)
{
    const std::size_t map_size = 10;
    static_map<int, int, map_size> map;
    ASSERT_EQ(map_size, map.max_size());
    ASSERT_EQ(0, map.size());
    ASSERT_TRUE(map.empty());
}

TEST(MapTest, AddElementToMap)
{
    const std::size_t map_size = 10;
    static_map<int, int, map_size> map;
    ASSERT_TRUE(map.empty());
    map[1] = 2;
    ASSERT_FALSE(map.empty());
}
