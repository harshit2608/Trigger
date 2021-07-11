#include <gtest/gtest.h>
#include "../include/ForwardList.h"

using namespace trigger;

class ForwardListTest : public ::testing::Test
{
protected:
    void SetUp() override { start_time = time(nullptr); }
    void TearDown() override
    {
        const time_t end_time = time(nullptr);
        EXPECT_TRUE(end_time - start_time <= 5) << "The test took too long." << end_time - start_time;
    }

    time_t start_time;

    ForwardList<unsigned int> a1;
};

TEST_F(ForwardListTest, ForwardListTest_IsEmptyInitial_Test)
{
    EXPECT_EQ(a1.Size(), 0);
    a1.PushFront(1);
    a1.PushFront(2);
    a1.PushFront(30);
    a1.PushFront(40.0);
    EXPECT_EQ(a1.Size(), 4);
    a1.PrintFL();
    a1.PushFront(19);
    a1.PushBack(45);
    a1.PrintFL();
}

TEST_F(ForwardListTest, ForwardListTest_InsertingAndCheckingElementA1_Test)
{
    // memset(a1.Data(), -1, a1.Size() * sizeof(unsigned int));
    // for (int i = 0; i < a1.Size(); ++i)
    // {
    //     EXPECT_EQ(a1[i], -1) << "Value at index : " << i << " is " << a1[i] << std::endl;
    // }

    // a1[3] = 100;
    // EXPECT_EQ(a1[3], 100);

    // for (int i = 0; i < a1.Size(); i++)
    // {
    //     a1[i] = i * 2;
    // }
    // EXPECT_EQ(a1[0], 0);
    // EXPECT_EQ(a1[2], 4);
    // EXPECT_EQ(a1[4], 8);
    // EXPECT_EQ(*(a1.Begin()), 0);
    // int i = 0;
    // for (auto &it : a1)
    // {
    //     EXPECT_EQ(it, i * 2) << "Value at index : " << i << " is " << it << std::endl;
    //     i++;
    // }

    // i = 0;
    // for (ForwardList<unsigned int, 5>::Iterator it = a1.Begin(); it != a1.End(); it++)
    // {
    //     unsigned int a = *it;
    //     EXPECT_EQ(a, i * 2) << "Value at index : " << i << " is " << a << std::endl;
    //     i++;
    // }
}