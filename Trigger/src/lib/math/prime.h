#pragma once

#include <stdint.h>
#include <iostream>
#include <vector>

/////////////////////////////////////////////////////////////////////
/////// PRIME METHODS ///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

namespace Trigger
{
    bool isprime(int64_t num)
    {
        if (num == 1)
        {
            return false;
        }
        if (num == 2 || num == 3)
        {
            return true;
        }
        if (num % 2 == 0 || num % 3 == 0)
        {
            return false;
        }
        for (int i = 5; i * i <= num; i = i + 6)
        {
            if (num % i == 0 || num % (i + 2) == 0)
            {
                return false;
            }
        }
        return true;
    }

    void primefactors(int64_t num)
    {
        if (num <= 1)
        {
            return;
        }

        while (num % 2 == 0)
        {
            std::cout << 2 << " ";
            num /= 2;
        }

        while (num % 3 == 0)
        {
            std::cout << 3 << " ";
            num /= 3;
        }

        for (int i = 5; i * i <= num; i = i + 6)
        {
            while (num % i == 0)
            {
                std::cout << i << " ";
                num = num / i;
            }
            while (num % (i + 2) == 0)
            {
                std::cout << (i + 2) << " ";
                num = num / (i + 2);
            }
        }
        if (num > 1)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    void getPrimes(int64_t num)
    {
        std::vector<bool> prime(num + 1, true);
        for (int i = 2; i <= num; i++)
        {
            if (prime[i])
            {
                std::cout << i << " ";
                for (int j = i * i; j <= num; j = j + i)
                {
                    prime[j] = false;
                }
            }
        }
    }

    void getComposites(int64_t num)
    {
        std::vector<bool> composite(num + 1, true);
        for (int i = 1; i * i <= num; i++)
        {
            if (composite[i])
            {
                for (int j = i * i; j <= num; j = j + i)
                {
                    composite[j] = false;
                }
            }
        }

        for (int i = 1; i <= num; i++)
        {
            if (!composite[i])
            {
                std::cout << i << " ";
            }
        }
    }
}