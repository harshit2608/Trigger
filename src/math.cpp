#include "../include/Math.h"

namespace trigger
{
    int factorial(int num)
    {
        if (num <= 1)
        {
            return 1;
        }
        return factorial(num - 1) * num;
    }
}