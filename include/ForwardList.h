#pragma once
#include <iostream>
namespace trigger
{
    struct Node
    {
        size_t data;
        Node *next;
    };

    template <typename T>
    class ForwardList
    {
    public:
        size_t Size() const { return m_Size; }
        Node *PushFront(size_t val)
        {
            Node *temp = new Node();
            temp->data = val;
            temp->next = head;
            head = temp;
            m_Size++;
            return head; // head;
        }

        Node *PushBack(size_t val)
        {
            Node *temp = new Node();
            temp->data = val;
            temp->next = nullptr;
            if (head == nullptr)
            {
                m_Size++;
                return temp;
            }

            Node *curr = head;
            while (curr->next != nullptr)
            {
                curr = curr->next;
            }

            curr->next = temp;
            m_Size++;
            return head;
        }

        void PushAt(Node *head, size_t val, size_t pos)
        {
            m_Size++;
        }

        void PopFront(Node *head)
        {
            m_Size--;
        }

        void PopBack(Node *head)
        {
            m_Size--;
        }

        void PopAt(Node *head, size_t pos)
        {
            m_Size--;
        }

        void PrintFL()
        {
            while (head && head->next)
            {
                std::cout << "[" << head->data << "] ->";
                head = head->next;
            }

            if (head)
            {
                std::cout << head->data << std::endl;
            }
            else
            {
                std::cout << "Empty LinkedList" << std::endl;
            }
        }

    private:
        Node *head = nullptr;
        size_t m_Size = 0;
    };

    template <typename T>
    class CircularForwardList
    {
    };
}