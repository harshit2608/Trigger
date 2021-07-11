#include <gtest/gtest.h>
#include "../include/Array.h"

using namespace trigger;

class ArrayTest : public ::testing::Test
{
protected:
    void SetUp() override { start_time = time(nullptr); }
    void TearDown() override
    {
        const time_t end_time = time(nullptr);
        EXPECT_TRUE(end_time - start_time <= 5) << "The test took too long." << end_time - start_time;
    }

    time_t start_time;

    Array<unsigned int, 5> a1;
    Array<double, 10> a2;
    Array<Array<bool, 5>, 10> a3;
    Array<Array<int, 100>, 100> a4;
};

TEST_F(ArrayTest, ArrayTest_IsEmptyInitial_Test)
{
    EXPECT_EQ(a1.Size(), 5);
    EXPECT_EQ(a2.Size(), 10);
    EXPECT_EQ(a3.Size(), 10);
    EXPECT_EQ(a4.Size(), 100);
}

TEST_F(ArrayTest, ArrayTest_InsertingAndCheckingElementA1_Test)
{
    memset(a1.Data(), -1, a1.Size() * sizeof(unsigned int));
    for (int i = 0; i < a1.Size(); ++i)
    {
        EXPECT_EQ(a1[i], -1) << "Value at index : " << i << " is " << a1[i] << std::endl;
    }

    a1[3] = 100;
    EXPECT_EQ(a1[3], 100);

    for (int i = 0; i < a1.Size(); i++)
    {
        a1[i] = i * 2;
    }
    EXPECT_EQ(a1[0], 0);
    EXPECT_EQ(a1[2], 4);
    EXPECT_EQ(a1[4], 8);
    EXPECT_EQ(*(a1.Begin()), 0);
    int i = 0;
    for (auto &it : a1)
    {
        EXPECT_EQ(it, i * 2) << "Value at index : " << i << " is " << it << std::endl;
        i++;
    }

    i = 0;
    for (Array<unsigned int, 5>::Iterator it = a1.Begin(); it != a1.End(); it++)
    {
        unsigned int a = *it;
        EXPECT_EQ(a, i * 2) << "Value at index : " << i << " is " << a << std::endl;
        i++;
    }
    //a1.msort();
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
    for (int i = 0; i < a2.Size(); ++i)
    {
        EXPECT_EQ(a2[i], 0) << "Value at index : " << i << " is " << a2[i] << std::endl;
    }

    a2[0] = 14456;
    a2[1] = 15;
    a2[2] = 563;
    a2[3] = 64;
    a2[4] = 1;
    a2[5] = 0;
    a2[6] = 6865;
    a2[7] = 65;
    for (int i = 0; i < a2.Size(); ++i)
    {
        std::cout << "Value at index : " << i << " is " << a2[i] << std::endl;
    }

    //Bsort(a2, a2.Size());
    for (int i = 0; i < a2.Size(); ++i)
    {
        std::cout << "Value at index : " << i << " is " << a2[i] << std::endl;
    }
}

TEST_F(ArrayTest, ArrayTest_2D_ArrayInsertionAndCheckingElement_Test)
{
    for (int i = 0; i < a3.Size(); ++i)
    {
        for (int j = 0; j < a3[i].Size(); ++j)
        {
            a3[i][j] = true;
        }
    }

    for (int i = 0; i < a3.Size(); ++i)
    {
        for (int j = 0; j < a3[i].Size(); ++j)
        {
            EXPECT_EQ(a3[i][j], true) << "Value at index : [" << i << "][" << j << "] is " << a3[i][j] << std::endl;
        }
    }

    a3[4][5] = false;
    EXPECT_EQ(a3[4][5], false);
}

TEST_F(ArrayTest, ArrayTest_2D_ArrayInsertionAndCheckingElementA4_Test)
{
    for (int i = 0; i < a4.Size(); ++i)
    {
        for (int j = 0; j < a4[i].Size(); ++j)
        {
            a4[i][j] = i * 2;
        }
    }

    for (int i = 0; i < a4.Size(); ++i)
    {
        for (int j = 0; j < a4[i].Size(); ++j)
        {
            EXPECT_EQ(a4[i][j], i * 2) << "Value at index : [" << i << "][" << j << "] is " << a4[i][j] << std::endl;
        }
    }

    a4[1][1] = 9, a4[2][2] = 1, a4[3][4] = 5, a4[5][6] = 78;
    Swap(a4[1][1], a4[2][2]);
    Swap(a4[3][4], a4[5][6]);
    EXPECT_EQ(a4[1][1], 1);
    EXPECT_EQ(a4[2][2], 9);
    EXPECT_EQ(a4[3][4], 78);
    EXPECT_EQ(a4[5][6], 5);
}

// TEST_F(ArrayTest, ArrayTest_InsertingAndCheckingElementA2_Test)
// {
//     a2[trig] = 0;
//     a2[type] = 2;
//     EXPECT_EQ(a2[trig], 0);
//     EXPECT_EQ(a2[type], 2);

//     memset(a1.Data(), 0121, sizeof(a1));
// }
