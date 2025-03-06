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
        };
        Node* head;
        Node* curr;
        Node* tail;

        Node* GetPtr(size_t index)
        {
            size_t count = 0;
            curr = head;

            while(curr != nullptr && count < index)
            {
                curr = curr->next;
                count++;
            }
            return curr;
        }

        public:
        size_t count;
        LinkedList();
        ~LinkedList();
        void AddToBack(T value);
        void AddToFront(T value);
        void LoopList(void (*lambda)(T&));
        void Reset();
        void Next();
        bool End();
        T Get(size_t index);
        bool SwapV(size_t first, size_t second);
        void Remove(size_t index);
        void Insert(size_t index, T value);
    };
}

#include "data_impl.h"
#include "data_constructors.h"

#endif