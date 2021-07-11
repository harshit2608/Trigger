#include <gtest/gtest.h>
#include "../include/Vector.h"

using namespace trigger;

class VectorTest : public ::testing::Test
{
protected:
    void SetUp() override { start_time = time(nullptr); }
    void TearDown() override
    {
        const time_t end_time = time(nullptr);
        EXPECT_TRUE(end_time - start_time <= 5) << "The test took too long." << end_time - start_time;
    }

    time_t start_time;

    Vector<unsigned int> v1;
    Vector<double> v2;
    Vector<Vector<bool>> v3;
    //Vector<int> v4(10);
};

TEST_F(VectorTest, VectorTest_IsEmptyInitial_Test)
{
    EXPECT_EQ(v1.Size(), 0);
    EXPECT_EQ(v2.Size(), 0);
    EXPECT_EQ(v3.Size(), 0);
}

TEST_F(VectorTest, VectorTest_InsertingAndCheckingElementv1_Test)
{

    for (int i = 0; i < 5; ++i)
    {
        v1.PushBack(-1);
    }
    for (int i = 0; i < v1.Size(); ++i)
    {
        EXPECT_EQ(v1[i], -1) << "Value at index : " << i << " is " << v1[i] << std::endl;
    }

    v1[3] = 100;
    EXPECT_EQ(v1[3], 100);

    for (int i = 0; i < v1.Size(); i++)
    {
        v1[i] = i * 2;
    }
    EXPECT_EQ(v1[0], 0);
    EXPECT_EQ(v1[2], 4);
    EXPECT_EQ(v1[4], 8);
    EXPECT_EQ(*(v1.Begin()), 0);
    int i = 0;
    for (auto &it : v1)
    {
        EXPECT_EQ(it, i * 2) << "Value at index : " << i << " is " << it << std::endl;
        i++;
    }

    i = 0;
    for (Vector<unsigned int>::Iterator it = v1.Begin(); it != v1.End(); it++)
    {
        unsigned int a = *it;
        EXPECT_EQ(a, i * 2) << "Value at index : " << i << " is " << a << std::endl;
        i++;
    }
    Swap(v1[0], v1[4]);
    EXPECT_EQ(*(v1.Begin()), 8);
    EXPECT_EQ(v1[4], 0);
}

// TEST_F(VectorTest, VectorTest_InsertingAndCheckingElementv2_Test)
// {
//     for (int i = 0; i < 5; i++)
//     {
//         v2[i] = i * 2;
//     }
//     EXPECT_EQ(v2[0], 0);
//     EXPECT_EQ(v2[5], 10);
//     EXPECT_EQ(v2[4], 8);
//     v2[3] = 100.265;
//     EXPECT_EQ(v2[3], 100.265);

//     memset(v2.Data(), 0, v2.Size() * sizeof(double));
//     for (int i = 0; i < v1.Size(); ++i)
//     {
//         EXPECT_EQ(v2[i], 0) << "Value at index : " << i << " is " << v2[i] << std::endl;
//     }
//     v2.PopBack();
//     EXPECT_EQ(v2.Size(), 4);
// }

// TEST_F(VectorTest, VectorTest_2D_VectorInsertionAndCheckingElement_Test)
// {
//     for (int i = 0; i < 6; ++i)
//     {
//         Vector<bool> v3temp;
//         for (int j = 0; j < 10; ++j)
//         {
//             v3temp.PushBack(true);
//         }
//         v3.PushBack(v3temp);
//     }

//     for (int i = 0; i < v3.Size(); ++i)
//     {
//         for (int j = 0; j < v3[i].Size(); ++j)
//         {
//             EXPECT_EQ(v3[i][j], true) << "Value at index : [" << i << "][" << j << "] is " << v3[i][j] << std::endl;
//         }
//     }

//     v3[4][5] = false;
//     EXPECT_EQ(v3[4][5], false);
// }

// TEST_F(VectorTest, VectorTest_InsertingAndCheckingElementv2_Test)
// {
//     v2[trig] = 0;
//     v2[type] = 2;
//     EXPECT_EQ(v2[trig], 0);
//     EXPECT_EQ(v2[type], 2);

//     memset(v1.Data(), 0121, sizeof(v1));
// }
