#pragma once

namespace trigger
{
    template <class _Tc>
    class Iterator
    {
    public:
        using ValueType = typename _Tc::ValueType;
        using PointerType = ValueType *;
        using ReferenceType = ValueType &;

    public:
        Iterator(PointerType ptr)
            : m_Ptr(ptr) {}

        Iterator operator++()
        {
            m_Ptr++;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator iterator = *this;
            ++(*this);
            return iterator;
        }

        Iterator operator--()
        {
            m_Ptr--;
            return *this;
        }

        Iterator operator--(int)
        {
            Iterator iterator = *this;
            --(*this);
            return iterator;
        }

        ReferenceType operator[](size_t index) { return *(m_Ptr + index); }
        PointerType operator->() { return m_Ptr; }
        ReferenceType operator*() { return *m_Ptr; }

        bool operator==(const Iterator &other) const
        {
            return m_Ptr == other.m_Ptr;
        }

        bool operator!=(const Iterator &other) const
        {
            return !(*this == other);
        }

    private:
        PointerType m_Ptr;
    };
}