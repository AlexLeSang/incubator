#include <gtest/gtest.h>
// #include <memorization.hpHost// TEST(TestMinimumStepToOne, InvalidNumber)
// {
//     ASSERT_EQ(-1, Memorization::get_minimal_steps(-1));
//     ASSERT_EQ(-1, Memorization::get_minimal_steps(0));
//     ASSERT_EQ(-1, Memorization::get_minimal_steps(-10));
// }

// TEST(TestMinimumStepToOne, Case1)
// {
//     ASSERT_EQ(0, Memorization::get_minimal_steps(1));
// }

// TEST(TestMinimumStepToOne, Case4)
// {
//     ASSERT_EQ(2, Memorization::get_minimal_steps(4));
// }

// TEST(TestMinimumStepToOne, Case10)
// {
//     ASSERT_EQ(3, Memorization::get_minimal_steps(10));
// }

#include <iteration.hpp>

TEST(TestMinimumStepToOne, InvalidNumber)
{

    ASSERT_EQ(-1, Iteration::get_minimal_steps(0));
    ASSERT_EQ(-1, Iteration::get_minimal_steps(-10));
}

TEST(TestMinimumStepToOne, Case1)
{
    ASSERT_EQ(0, Iteration::get_minimal_steps(1));
}

TEST(TestMinimumStepToOne, Case4)
{
    ASSERT_EQ(2, Iteration::get_minimal_steps(4));
}

TEST(TestMinimumStepToOne, Case10)
{
    ASSERT_EQ(3, Iteration::get_minimal_steps(10));
}

TEST(TestMinimumStepToOne, Case1e12)
{
    ASSERT_EQ(18, Iteration::get_minimal_steps(1e5));
}

// int main(int argc, char **argv) {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
