#include <iostream>
#include <stdexcept>
#include "data.h"

using namespace xx;

template<typename T>
void LinkedList<T>::AddToBack(T value)
{
    count++;
    if(head == nullptr && tail == nullptr)
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
    Node* newHead = new Node(value, head);
    head = newHead;
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
T LinkedList<T>::Get(size_t index)
{
    if(index < 0 || index>= count)
    {
        throw std::invalid_argument("Incorrect index!");
    }

    size_t count = 0;
    Node* temp = head;

    while(temp != nullptr && count != index)
    {
        temp = temp->next;
        count++;
    }

    if(temp == nullptr)
    {
        throw std::invalid_argument("Incorrect index!");
    }
    return temp->value;
}

template<typename T>
bool LinkedList<T>::SwapV(size_t first, size_t second)
{
    if(first < 0 || first >= second)
    {
        return false;
    }

    Node* firstPtr;

    size_t count = 0;
    while(curr != nullptr && count < second)
    {
        if(first == count)
        {
            firstPtr = curr;
        }
        curr = curr->next;
        count++;
    } 

    if(curr == nullptr)
    {
        Reset();
        return false;
    }

    T tempVal = firstPtr->value;
    firstPtr->value = curr->value;
    curr->value = tempVal;

    Reset();
    return true;
}

template<typename T>
void LinkedList<T>::Remove(size_t index)
{
    if(index < 0 || index >= count)
    {
        return;
    }

    if(index == 0 || count == 1)
    {
        Node* tempPtr = head;
        head = head->next;
        curr = head;
        count--;
        delete tempPtr;
        return;
    }
    Node* prevRemoveNodes = head;
    for(size_t i = 0; i < index - 1; i++)
    {
        prevRemoveNodes = prevRemoveNodes->next;
    }
    prevRemoveNodes->next = prevRemoveNodes->next->next;
}

template<typename T>
void LinkedList<T>::Insert(size_t index, T value)
{
    curr = GetPtr(index);
    if(curr == nullptr)
        return;

    if(head == curr)
    {
        Node* temp = new Node(value, head);
        head = temp;
        curr = head;
        return;
    }
    Node* temp = new Node(value, curr);
    curr = temp;
    curr = head;
}