#pragma once

#include <stdint.h>
#include <iostream>
#include <vector>

namespace Trigger
{
    bool checkKthbit(int64_t num, int64_t k)
    {
        if ((num >> (k - 1)) & 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int64_t countSetBits(int64_t num)
    {
        int64_t res = 0;
        while (num > 0)
        {
            num = num & (num - 1);
            res++;
        }
        return res;
    }

    bool powOfTwo(int64_t num)
    {
        if (num == 0)
        {
            return false;
        }
        else
        {
            return (num & (num - 1) == 0);
        }
    }


}