#include <gtest/gtest.h>
#include "../include/array.h"

using namespace trigger;

class ArrayTest : public ::testing::Test
{
protected:
    void SetUp() override { start_time_ = time(nullptr); }
    void TearDown() override
    {
        const time_t end_time = time(nullptr);
        EXPECT_TRUE(end_time - start_time_ <= 5) << "The test took too long.";
    }

    time_t start_time_;

    Array<unsigned int, 5> a1;
    Array<double, 10> a2;
};

TEST_F(ArrayTest, ArrayTest_IsEmptyInitial_Test)
{
    EXPECT_EQ(a1.Size(), 5);
    EXPECT_EQ(a2.Size(), 10);
}

TEST_F(ArrayTest, ArrayTest_InsertingAndCheckingElementA1_Test)
{
    memset(a1.Data(), -1, a1.Size() * sizeof(unsigned int));
    for (int i = 0; i < a1.Size(); ++i)
    {
        EXPECT_EQ(a1[i], -1) << "Value at index : " << i << " is " << a1[i] << std::endl;
    }

    for (int i = 0; i < a1.Size(); i++)
    {
        a1[i] = i * 2;
    }
    EXPECT_EQ(a1[0], 0);
    EXPECT_EQ(a1[2], 4);
    EXPECT_EQ(a1[4], 8);
    a1[3] = 100;
    EXPECT_EQ(a1[3], 100);
}

TEST_F(ArrayTest, ArrayTest_InsertingAndCheckingElementA2_Test)
{
    for (int i = 0; i < a2.Size(); i++)
    {
        a2[i] = i * 2;
    }
    EXPECT_EQ(a2[0], 0);
    EXPECT_EQ(a2[5], 10);
    EXPECT_EQ(a2[4], 8);
    a2[3] = 100.265;
    EXPECT_EQ(a2[3], 100.265);

    memset(a2.Data(), 0, a2.Size() * sizeof(double));
    for (int i = 0; i < a1.Size(); ++i)
    {
        EXPECT_EQ(a2[i], 0) << "Value at index : " << i << " is " << a2[i] << std::endl;
    }
}

// TEST_F(ArrayTest, ArrayTest_InsertingAndCheckingElementA2_Test)
// {
//     a2[trig] = 0;
//     a2[type] = 2;
//     EXPECT_EQ(a2[trig], 0);
//     EXPECT_EQ(a2[type], 2);

//     memset(a1.Data(), 0121, sizeof(a1));
// }
