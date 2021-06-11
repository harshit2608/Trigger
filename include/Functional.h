#pragma once

namespace trigger
{
    /*rvalue reference (&&)*/
    template <class _Tc>
    _Tc &&_MOVE_(_Tc &&args)
    {
    }

    template <class _Tc>
    _Tc _FILL_()
    {
    }
}

#include <vector>