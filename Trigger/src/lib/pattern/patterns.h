#pragma once

#include <iostream>
#include <stdlib.h>

namespace Trigger
{
    void patternHP_stars(int64_t rows = 5)
    {
        for (int i = 1; i <= rows; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                std::cout << "*";
            }
            std::cout << "\n";
        }
    }

    void patternHP_rows(int64_t rows = 5)
    {
        for (int i = 1; i <= rows; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                std::cout << j;
            }
            std::cout << "\n";
        }
    }

    void patternHP_alpha(int64_t rows = 5)
    {
        for (int i = 1; i <= rows; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                std::cout << (char)(64 + j);
            }
            std::cout << "\n";
        }
    }

    void patternIHP_stars(int64_t rows = 5)
    {
        for (int i = 1; i <= rows; ++i)
        {
            for (int j = rows; j >= i; --j)
            {
                std::cout << "*";
            }
            std::cout << "\n";
        }
    }

    void patternIHP_rows(int64_t rows = 5)
    {
        for (int i = rows; i >= 1; --i)
        {
            for (int j = 1; j <= i; ++j)
            {
                std::cout << j;
            }
            std::cout << "\n";
        }
    }

    void patternFP_stars(int64_t rows = 5)
    {
        for (int i = 1; i <= rows; ++i)
        {
            int space = rows - i;
            while (space > 0)
            {
                std::cout << " ";
                space--;
            }
            for (int j = 1; j <= (i * 2) - 1; j++)
            {
                std::cout << "*";
            }
            std::cout << "\n";
        }
    }

    // void patternFP_rows(int64_t rows = 5)
    // {
    //     int count = 0;
    //     for (int i = 1; i <= rows; ++i)
    //     {
    //         int space = rows - i, j;
    //         while (space > 0)
    //         {
    //             std::cout << " ";
    //             space--;
    //             ++count;
    //         }

    //         for (j = i; j <= (i * 2) - 1; j++)
    //         {
    //             std::cout << j;
    //         }

    //         for (int k = j - 1; k >= j; --k)
    //         {
    //             std::cout << k;
    //         }

    //         std::cout << "\n";
    //     }
    // }

    void patternIFP_stars(int64_t rows = 5)
    {
        for (int i = rows; i >= 1; --i)
        {
            int space = rows - i;
            while (space > 0)
            {
                std::cout << " ";
                --space;
            }
            for (int j = (2 * i) - 1; j >= 1; --j)
            {
                std::cout << "*";
            }
            std::cout << "\n";
        }
    }

    void pascalTriangle(int64_t rows = 5)
    {
    }

    void floydTriangle(int64_t rows = 5)
    {
        int ans = 1;
        for (int i = 1; i <= rows; ++i)
        {
            for (int j = 1; j <= i; j++)
            {
                std::cout << ans;
                ++ans;
            }
            std::cout << "\n";
        }
    }
}