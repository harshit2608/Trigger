#pragma once

#include "Core.h"
#include "Algorithm.h"
#include "Utility.h"
#include "Iterator.h"
//TODO:
/**
 * 1. Implement the insertion of values using []
 * 2. Option to specify the size during creation
*/
namespace trigger
{
    template <class Vector>
    class VectorIterator //: public Iterator<Vector>
    {
    public:
        using ValueType = typename Vector::ValueType;
        using PointerType = ValueType *;
        using ReferenceType = ValueType &;

    public:
        VectorIterator(PointerType ptr)
            : m_Ptr(ptr) {}

        VectorIterator operator++()
        {
            m_Ptr++;
            return *this;
        }

        VectorIterator operator++(int)
        {
            VectorIterator iterator = *this;
            ++(*this);
            return iterator;
        }

        VectorIterator operator--()
        {
            m_Ptr--;
            return *this;
        }

        VectorIterator operator--(int)
        {
            VectorIterator iterator = *this;
            --(*this);
            return iterator;
        }

        ReferenceType operator[](size_t index) { return *(m_Ptr + index); }
        PointerType operator->() { return m_Ptr; }
        ReferenceType operator*() { return *m_Ptr; }

        bool operator==(const VectorIterator &other) const
        {
            return m_Ptr == other.m_Ptr;
        }

        bool operator!=(const VectorIterator &other) const
        {
            return !(*this == other);
        }

    private:
        PointerType m_Ptr;
    };

    template <class Vector>
    class VectorConstIterator
    {
    public:
        using ValueType = typename Vector::ValueType;
        using CPointerType = const ValueType *;
        using CReferenceType = const ValueType &;

    public:
    private:
        CPointerType m_Ptr;
    };

    template <typename T>
    class Vector
    {
    public:
        using ValueType = T;
        using Iterator = VectorIterator<Vector<T>>;
        using CIterator = VectorConstIterator<Vector<T>>;

    public:
        Vector() { ReAllocate(2); }
        Vector(int val) : m_Size(val)
        {
            T *m_Data = new T[val];
            memset(m_Data, 0, sizeof(m_Data));
            ReAllocate(val);
        }

        ~Vector()
        {
            Clear();
            ::operator delete(m_Data, m_Capacity * sizeof(T));
        }

        /*Returns the size of vector*/
        size_t Size() const { return m_Size; }
        /*Returns the size of the storage space currently allocated to the vector expressed as number of elements*/
        size_t Capacity() const { return m_Capacity; }
        /* Resizes the vector so that it contains ‘n’ elements.*/
        size_t Resize(const size_t val) const { ReAllocate(val); }

        /*operator to access the elements of vector and const to provide read only access*/
        T &operator[](size_t index) { return m_Data[index]; }
        const T &operator[](size_t index) const { return m_Data[index]; }

        /*Acces the data within the vector*/
        T *Data() { return m_Data; }
        const T *Data() const { return m_Data; }

        void PushBack(const T &value)
        {
            if (m_Size >= m_Capacity)
            {
                ReAllocate(m_Capacity + m_Capacity / 2);
            }

            m_Data[m_Size] = std::move(value);
            m_Size++;
        }

        template <typename... Args>
        T &EmplaceBack(Args &&...args)
        {
            if (m_Size >= m_Capacity)
            {
                ReAllocate(m_Capacity + m_Capacity / 2);
            }

            m_Data[m_Size] = T(std::forward<Args>(args)...);
            return m_Data[m_Size++];
        }

        /*Removes the last element from the vector*/
        void PopBack()
        {
            if (m_Size > 0)
            {
                m_Data[m_Size].~T();
            }
        }

        /*Clear the whole vector*/
        void Clear()
        {
            for (size_t i = 0; i < m_Size; ++i)
            {
                m_Data[i].~T();
            }
        }

        // void Swap()

        Iterator Begin() const { return m_Data; }
        Iterator begin() const { return m_Data; }
        Iterator End() const { return m_Data + m_Size; }
        Iterator end() const { return m_Data + m_Size; }

    private:
        void ReAllocate(size_t newCapacity)
        {
            T *newBlock = (T *)::operator new(newCapacity * sizeof(T));

            if (newCapacity < m_Size)
            {
                m_Size = newCapacity;
            }

            for (size_t i = 0; i < m_Size; ++i)
            {
                newBlock[i] = std::move(m_Data[i]);
            }

            for (size_t i = 0; i < m_Size; ++i)
            {
                m_Data[m_Size].~T();
            }

            ::operator delete(m_Data, m_Capacity * sizeof(T));
            m_Data = newBlock;
            m_Capacity = newCapacity;
        }

    private:
        T *m_Data = nullptr;
        size_t m_Size = 0;
        size_t m_Capacity = 0;
    };
}