#pragma once
#include <iostream>

namespace trigger
{
    template <typename T, size_t S>
    class Array
    {
    public:
        /*Returns size*/
        constexpr size_t Size() const { return S; }

        /*operator to access the elements of array and const to provide read only access*/
        T &operator[](size_t index) { return m_Data[index]; }
        const T &operator[](size_t index) const { return m_Data[index]; }

        /*Acces the data within the array*/
        T *Data() { return m_Data; }
        const T *Data() const { return m_Data; }

        //TODO:
        /**
         * fill -  fill the array with a particular number
         * clear -  clear the array
         * indexof - returns the index of the input element
        */
    private:
        T m_Data[S];
    };
}
