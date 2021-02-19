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
        int64_t rev = 0, rem = 0, temp = num;
        if (num == 0)
        {
            return true;
        }

        while (num != 0)
        {
            rem = num % 10;
            rev = rev * 10 + rem;
            num = num / 10;
        }
        return (temp == rev);
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

    int64_t factorialtrailingzeros(int64_t num)
    {
        int64_t res = 0;
        for (int i = 5; i <= num; i *= 5)
        {
            res = res + num / i;
        }
        return res;
    }

    int64_t GCD(int64_t a, int64_t b)
    {
        if (b == 0)
        {
            return a;
        }
        return GCD(b, a % b);
    }
} // namespace Trigger