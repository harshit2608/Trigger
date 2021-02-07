#pragma once

#include <stdint.h>

namespace Trigger
{
    int64_t numofdigits(int64_t num)
    {
        int64_t count = 0;
        while (num != 0)
        {
            num /= 10;
            count++;
        }
        return count;
    }

    bool isprime(int64_t num)
    {
        return true;
    }

    bool ispalindrome(int64_t num)
    {
        return true;
    }

    int64_t factorial(int64_t num)
    {
        int64_t fact = 1;
        if (num == 0)
        {
            return 1;
        }
        else if (num > 170)
        {
            return 0;
        }
        else
        {
            while (num != 1)
            {
                fact = fact * num;
                num--;
            }
            return fact;
        }
    }
} // namespace Trigger