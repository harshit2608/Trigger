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

} // namespace Trigger