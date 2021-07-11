#include <gtest/gtest.h>
#include "../include/Stack.h"

using namespace trigger;

class StackArrayTest : public ::testing::Test
{
protected:
    void SetUp() override { start_time = time(nullptr); }
    void TearDown() override
    {
        const time_t end_time = time(nullptr);
        EXPECT_TRUE(end_time - start_time <= 5) << "The test took too long." << end_time - start_time;
    }

    time_t start_time;

    StackArray<unsigned int, 10> s1;
    StackArray<double, 15> s2;
    //StackArray<int> v4(10);
};

TEST_F(StackArrayTest, StackArrayTest_IsEmptyInitial_Test)
{
    EXPECT_EQ(s1.Size(), 0);
    EXPECT_EQ(s2.Size(), 0);
}

TEST_F(StackArrayTest, StackArrayTest_InsertingAndCheckingElements1_Test)
{
    EXPECT_EQ(s1.IsEmpty(), true);
    for (int i = 0; i < s1.Capacity(); ++i)
    {
        s1.Push(100);
    }
    for (int i = 0; i < s1.Size(); ++i)
    {
        EXPECT_EQ(s1.ElementAt(i), 100) << "Value at index : " << i << " is " << s1.ElementAt(i) << std::endl;
    }

    s1.Pop();
    EXPECT_EQ(s1.Size(), 9);
    EXPECT_EQ(s1.Capacity(), 10);

    while (s1.Size() >= 5)
    {
        s1.Pop();
    }
    EXPECT_EQ(s1.Size(), 4);
    EXPECT_EQ(s1.Capacity(), 10);
    EXPECT_EQ(s1.Peek(), 100);
    EXPECT_EQ(s1.IsEmpty(), false);
    EXPECT_EQ(s1.ElementAt(6), 0);
}

// TEST_F(StackArrayTest, StackArrayTest_InsertingAndCheckingElements2_Test)
// {
//     for (int i = 0; i < 5; i++)
//     {
//         s2[i] = i * 2;
//     }
//     EXPECT_EQ(s2[0], 0);
//     EXPECT_EQ(s2[5], 10);
//     EXPECT_EQ(s2[4], 8);
//     s2[3] = 100.265;
//     EXPECT_EQ(s2[3], 100.265);

//     memset(s2.Data(), 0, s2.Size() * sizeof(double));
//     for (int i = 0; i < s1.Size(); ++i)
//     {
//         EXPECT_EQ(s2[i], 0) << "Value at index : " << i << " is " << s2[i] << std::endl;
//     }
//     s2.PopBack();
//     EXPECT_EQ(s2.Size(), 4);
// }
