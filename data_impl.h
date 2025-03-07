#include <iostream>
#include <stdexcept>
#include "data.h"

using namespace xx;

template<typename T>
void LinkedList<T>::AddToBack(T value)
{
    count++;
    if(head == nullptr)
    {
        head = new Node(value, nullptr);
        curr = head;
        tail = head;
        return;
    }

    tail->next = new Node(value, nullptr);
    tail = tail->next;
}

template<typename T>
void LinkedList<T>::AddToFront(T value)
{
    if(head == nullptr && tail == nullptr)
    {
        AddToBack(value);
        return;
    }
    head = new Node(value, head);
    curr = head;
    count++;
}

template<typename T>
void LinkedList<T>::LoopList(void (*lambda)(T&))
{
    while(curr != nullptr)
    {
        lambda(curr->value);
        curr = curr->next;
    }
    curr = head;
}

template<typename T>
void LinkedList<T>::Reset()
{
    curr = head;
}

template<typename T>
void LinkedList<T>::Next()
{
    curr = curr->next;
}

template<typename T>
bool LinkedList<T>::End()
{
    return curr == nullptr;
}

template<typename T>
size_t LinkedList<T>::Length() const
{
    return this->count;
}

template<typename T>
T LinkedList<T>::Get(size_t index)
{
    Node* value = GetPtr(index);
    Reset();
    if(value == nullptr)
        throw std::invalid_argument("Index out of bounds!");
    return value->value;
}

template<typename T>
bool LinkedList<T>::SwapValues(size_t first, size_t second)
{
    if(first < 0 || first >= second || second >= count) return false;

    Node* firstPtr = GetPtr(first);
    Node* secondPtr = GetPtr(second);
    Reset();

    if(firstPtr == nullptr || secondPtr == nullptr) return false;
    
    T tempVal = firstPtr->value;
    firstPtr->value = secondPtr->value;
    secondPtr->value = tempVal;

    return true;
}

template<typename T>
void LinkedList<T>::Remove(size_t index)
{
    if(index >= count || count == 0) return;

    Node* deletedNode = GetPtr(index);

    if(index == 0) 
    {
        head = head->next;
        delete deletedNode;
        count--;
        return;
    }

    Node* prevPtr = GetPtr(index - 1);
    prevPtr->next = deletedNode->next;
    
    if(index == count - 1)
    {
        tail = prevPtr;
    }

    delete deletedNode;
    count--;
    Reset();
}

template<typename T>
void LinkedList<T>::Insert(size_t index, T value)
{
    if(index < 0 || index > count)
    {
        return;
    }
    if(index == 0)
    {
        AddToFront(value);
        return;
    }
    else if (index == count)
    {
        AddToBack(value);
        return;
    }

    Node* prevPtr = GetPtr(index - 1);
    Node* pushedPtr = GetPtr(index);

    prevPtr->next = new Node(value, pushedPtr);
    Reset();
}

template<typename T>
bool LinkedList<T>::SwapNodes(size_t first, size_t second)
{
    if (first == second || first < 0 || second < 0 || first >= count || second >= count)
        return false;

    if (first > second) std::swap(first, second); 

    Node* r1 = (first == 0) ? nullptr : GetPtr(first - 1);
    Node* s1 = GetPtr(first);
    Node* r2 = GetPtr(second - 1);
    Node* s2 = GetPtr(second);

    if (!s1 || !s2) return false;

    if (first == 0) {
        head = s2;
    } else {
        r1->next = s2;
    }

    if (second - first == 1) {
        s1->next = s2->next;
        s2->next = s1;
    }
    else {
        Node* temp = s2->next;
        s2->next = s1->next;
        s1->next = temp;
        r2->next = s1;
    }

    if (s1->next == nullptr) tail = s1;
    else if (s2->next == nullptr) tail = s2;

    return true;
}


template<typename T>
void LinkedList<T>::BubleSort()
{
    if (head == nullptr || head->next == nullptr) return;

    bool flag = true;
    while(flag)
    {
        Reset();
        flag = false;

        for(size_t i = 0; i < this->count - 1; i++)
        {
            if(curr->value > curr->next->value)
            {
                P_SwapValues(curr, curr->next);
                flag = true;
            }
            Next();
        }
        Reset();
    }
}

template<typename T>
void LinkedList<T>::SelectionSort()
{
    for(size_t i = 0; i < this->count - 1; i++)
    {
        Node* minNode = GetPtr(i);
        curr = GetPtr(i+1);
        for(size_t j = i + 1; j < this->count; j++)
        {
            if(minNode->value > curr->value)
            {
                minNode = curr;
            }
            Next();
        }
        Node* temp = GetPtr(i);
        if(minNode != temp)
        {
            P_SwapValues(minNode, temp);
        }
        Reset();
    }
}