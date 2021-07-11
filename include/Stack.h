#pragma once

#include "Core.h"
#include "Algorithm.h"
#include "Utility.h"

namespace trigger
{
    template <typename T, size_t S>
    class StackArray
    {
    public:
        constexpr size_t Size() const { return m_Size + 1; }
        constexpr size_t Capacity() const { return S; }

        void Push(size_t val)
        {
            if (m_Size == (S - 1))
            {
                std::cout << "Stack OverFlow!";
                return;
            }
            m_Size++;
            m_Data[m_Size] = val;
        }

        T Pop()
        {
            if (m_Size == -1)
            {
                std::cout << "Stack UnderFlow!!";
                return 0;
            }
            size_t val = m_Data[m_Size];
            m_Data[m_Size] = 0;
            m_Size--;
            return val;
        }

        T ElementAt(size_t idx)
        {
            if (idx > m_Size + 1)
            {
                return 0;
            }
            return m_Data[idx];
        }

        T Peek()
        {
            return m_Data[m_Size];
        }

        bool IsEmpty()
        {
            return m_Size == -1;
        }

    private:
        /*operator to access the elements of stack and const to provide read only access*/
        T &operator[](size_t index) { return m_Data[index]; }
        const T &operator[](size_t index) const { return m_Data[index]; }

        /*Acces the data within the stack*/
        T *Data() { return m_Data; }
        const T *Data() const { return m_Data; }

    private:
        size_t m_Size = -1;
        T m_Data[S];
    };
}