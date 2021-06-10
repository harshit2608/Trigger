#pragma once
#include <iostream>
#include "algorithm.h"

namespace trigger
{
    template <class Array>
    class Functions
    {
    public:
    private:
    };

    template <typename Array>
    class ArrayIterator
    {
    public:
        using ValueType = typename Array::ValueType;
        using PointerType = ValueType *;
        using ReferenceType = ValueType &;

    public:
        ArrayIterator(PointerType ptr)
            : m_Ptr(ptr) {}

        ArrayIterator operator++()
        {
            m_Ptr++;
            return *this;
        }

        ArrayIterator operator++(int)
        {
            ArrayIterator iterator = *this;
            ++(*this);
            return iterator;
        }

        ArrayIterator operator--()
        {
            m_Ptr--;
            return *this;
        }

        ArrayIterator operator--(int)
        {
            ArrayIterator iterator = *this;
            --(*this);
            return iterator;
        }

        ReferenceType operator[](size_t index) { return *(m_Ptr + index); }
        PointerType operator->() { return m_Ptr; }
        ReferenceType operator*() { return *m_Ptr; }

        bool operator==(const ArrayIterator &other) const noexcept
        {
            return m_Ptr == other.m_Ptr;
        }

        // bool operator==(const ArrayIterator &one, const ArrayIterator &two) const
        // {
        //     return (one.m_Ptr == two.m_Ptr);
        // }

        bool operator!=(const ArrayIterator &other) const
        {
            return !(*this == other);
        }

    private:
        PointerType m_Ptr;
    };

    template <typename T, size_t S>
    class Array
    {
    public:
        using ValueType = T;
        using Iterator = ArrayIterator<Array<T, S>>;

    public:
        /*Returns size*/
        constexpr size_t
        Size() const
        {
            return S;
        }

        /*operator to access the elements of array and const to provide read only access*/
        T &operator[](size_t index) { return m_Data[index]; }
        const T &operator[](size_t index) const { return m_Data[index]; }

        /*Acces the data within the array*/
        T *Data() { return m_Data; }
        const T *Data() const { return m_Data; }

        /*Interator to the begining index of Array*/
        Iterator Begin() { return Iterator(m_Data); }
        /*Iterator to the end element +1 index of Array*/
        Iterator End() { return Iterator(m_Data + S); }

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
