#ifndef LLIST_H
#define LLIST_H

#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
struct Node
{
    T value;
    Node<T>* next;
    Node(): value{-1}, next{nullptr} {};
    Node(T value, Node<T>* next): value{value}, next{next} {};

    bool operator ==(Node<T>* const & rhs)
    {
        return this->value == rhs->value;
    }

    bool operator !=(Node<T>* const & rhs)
    {
        return !(this->value == rhs->value)
    }

    template<T>
    friend std::ostream& operator << (std::ostream& os, const Node<T>*& node)
    {
        os << node->value << '\n';
        return os;
    }
};

template<typename T>
class LList
{
public:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* curr;
    LList();
    ~LList();
    void AddToFront(int value);
    bool ResetPointer();
    void CopyVector(std::vector<int>& kec);
    void Print();
    Node<T>* Prev(Node<T>* head, T value);
    void Swap(Node<T>* head, Node<T>* r1, Node<T>* r2);
    void Insert(Node<T>* d, T value);
    void DeleteNode(Node<T>* prevDel);
};

template<typename T>
LList<T>::LList(): head{nullptr}, tail{nullptr}, curr{nullptr} {};

template<typename T>
LList<T>::~LList()
{
    Node<T>* temp = head;

    while(temp != nullptr)
    {
        Node<T>* t = temp->next;
        delete temp;
        temp = t;
    }
    head = nullptr;
}

template<typename T>
void LList<T>::AddToFront(int value)
{
    if(tail == nullptr)
    {
        tail = new Node<T>(value, nullptr);
        head = tail;
        return;
    }

    tail->next = new Node<T>(value, nullptr);
    tail = tail->next;
}

template<typename T>
bool LList<T>::ResetPointer()
{
    if(head != nullptr)
    {
        this->curr = this->head;
        return true;
    }
    return false;
}

template<typename T>
void LList<T>::CopyVector(std::vector<int>& vec)
{
    std::for_each(vec.begin(), vec.end(), [this](int i) -> void{
        this->AddToFront(i);
    });
}

template<typename T>
void LList<T>::Print()
{
    Node<T>* tempPtr = this->head;

    while(tempPtr != nullptr)
    {
        std::cout << tempPtr->value << '\n';
        tempPtr = tempPtr->next;
    }
}

template<typename T>
Node<T>* LList<T>::Prev(Node<T>* head, T value)
{
    Node<T>* valueNode = head;

    while(valueNode->next != nullptr && valueNode->next->value != value)
    {
        valueNode = valueNode->next;
    }
    return valueNode;
}

template<typename T>
void LList<T>::Swap(Node<T>* head, Node<T>* r1, Node<T>* r2)
{
    if(r1 == nullptr || r2 == nullptr)
    {
        return;
    }

    Node<T>* s1 = r1->next;
    Node<T>* s2 = r2->next;

    if(s2 == nullptr)
    {
        return;
    }

    r1->next = s2;
    r2->next = s1;
    Node<T>* temp = s2->next;
    s2->next = s1->next;
    s1->next = temp;
}

template<typename T>
void LList<T>::Insert(Node<T>* d, T value)
{
    if(d == nullptr)
    {
        return;
    }

    Node<T>* newNode = new Node<T>(value, d->next);
    d->next = newNode;
}

template<typename T>
void LList<T>::DeleteNode(Node<T>* prevDel)
{
    if(head == nullptr || prevDel == nullptr)
    {
        return;
    }

    if(&this->head == &prevDel)
    {
        Node<T>* temp = this->head;
        this->head = this->head->next;
        delete head;
    }

    Node<T>* temp = this->head;

    while(temp->next != nullptr && temp->next != prevDel)
    {
        temp = temp->next;
    }

    if(temp->next == nullptr)
    {
        return;
    }

    temp->next = temp->next->next;
}

#endif;