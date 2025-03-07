#include "data.h"

using namespace xx;

template<typename T>
LinkedList<T>::Node::Node(): value(T()), next(nullptr) {}

template<typename T>
LinkedList<T>::Node::Node(T v, Node* n): value(v), next(n) {}

template<typename T>
LinkedList<T>::Node::~Node() {}

template<typename T>
bool LinkedList<T>::Node::operator<(const Node* right) const
{
    return this->value < right->value;
}

template<typename T>
bool LinkedList<T>::Node::operator>(const Node* right) const
{
    return this->value > right->value;
}

template<typename T>
LinkedList<T>::LinkedList(): head{nullptr}, curr{nullptr}, tail{nullptr} { count = 0;};

template<typename T>
LinkedList<T>::~LinkedList()
{
    curr = head;

    while(curr != nullptr)
    {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = nullptr;
};