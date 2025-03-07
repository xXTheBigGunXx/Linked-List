#ifndef DATA_H
#define DATA_H

#include <stddef.h>
#include <cstddef>

namespace xx
{
    template<typename T>
    class LinkedList
    {
        private:
        struct Node
        {
            T value;
            Node* next;

            Node();
            Node(T v, Node* n);
            ~Node();
            bool operator < (const Node* right) const;
            bool operator > (const Node* right) const;
        };
        Node* head;
        Node* curr;
        Node* tail;

        size_t count;

        Node* GetPtr(size_t index)
        {
            if(index < 0 || index >= count)
                return nullptr;
            size_t count = 0;
            curr = head;

            while(curr != nullptr && count < index)
            {
                curr = curr->next;
                count++;
            }
            return curr;
        }

        void P_SwapValues(Node*& first, Node*& second) const
        {
            T tempVal = first->value;
            first->value = second->value;
            second->value = tempVal;
        }

        public:
        LinkedList();
        ~LinkedList();
        void AddToBack(T value);
        void AddToFront(T value);
        void LoopList(void (*lambda)(T&));
        void Reset();
        void Next();
        bool End();
        size_t Length() const;
        T Get(size_t index);
        bool SwapValues(size_t first, size_t second);
        bool SwapNodes(size_t first, size_t second);
        void Remove(size_t index);
        void Insert(size_t index, T value);
        void BubleSort();
        void SelectionSort();
    };
}

#include "data_impl.h"
#include "data_constructors.h"

#endif