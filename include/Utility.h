#pragma once

#include "Core.h"

namespace trigger
{
    /*rvalue reference (&&)*/
    template <class Tc>
    Tc &&Move(Tc &&args)
    {
    }

    template <class Tc>
    Tc _FILL_()
    {
    }

    template <class Tc>
    void Swap(Tc &Left, Tc &Right)
    {
        Tc Tmp = (Left);
        Left = (Right);
        Right = (Tmp);
    }
}