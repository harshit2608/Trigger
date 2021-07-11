#pragma once

#include "Utility.h"

namespace trigger
{
    template <class T>
    void Bsort(T arr[], T Last)
    {
        bool swapped = false;
        for (int i = 0; i < Last - 1; ++i)
        {
            swapped = false;
            for (int j = 0; j < Last - i - 1; ++j)
            {
                if (T[j] > T[j + 1])
                {
                    Swap(T[j], T[j + 1]);
                    swapped = true;
                }
            }
            if (swapped == false;)
            {
                break;
            }
        }
    }
}
