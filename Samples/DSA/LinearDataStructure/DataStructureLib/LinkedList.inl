#pragma once
#include "LinkedList.hpp"

template <typename T>
inline bool LinkedList<T>::reverseList(node<T>* current)
{   
    // Recursion for change the head
    if (current == nullptr) return false;
    if (current->next == nullptr)
    {
        head = current;
        return true;
    }

    // Callback changing next
    if(reverseList(current->next))
    {
        node<T>* temp = current->next;
        temp->next = current;
        current->next = nullptr;
    }
    return true;
}
template <typename T>
inline LinkedList<T>::LinkedList() 
{
    head = nullptr;
    length = 0;
}

template <typename T>
inline LinkedList<T>::~LinkedList() 
{
    node<T>* current = head;
    while (current != nullptr) 
    {
        node<T>* temp = current;
        current = current->next;
        delete temp;
    }
}

template <typename T>
inline bool LinkedList<T>::reverse()
{
    if (head == nullptr) 
        return false;
    node<T>* current = head;
    bool result = reverseList(current);
    if(!result) delete current;
    return result;
}

template <typename T>
inline int LinkedList<T>::size()
{
    return length;
}

template <typename T>
inline std::optional<T> LinkedList<T>::get(int index)
{
    if(index < 0 || index >= length) return std::nullopt;
    int i = 0;
    node<T>* current = head;
    while(head != nullptr && i < index)
    {
        current = current->next;
        i++;
    }
    return current->data;
}

template <typename T>
inline bool LinkedList<T>::set(int index, T data)
{
    if(index < 0 || index >= length) return false;
    

    int i = 0;
    node<T>* current = head;
    while(head != nullptr && i < index)
    {
        current = current->next;
        i++;
    }
    current->data = data;
    return true;
}

template <typename T>
inline bool LinkedList<T>::addFirst(T data) 
{
    node<T>* new_node = new node<T>(data);
    new_node->next = head;
    head = new_node;
    length++;
    return true;
}

template <typename T>
inline bool LinkedList<T>::addAt(int position, T data)
{
    if (position < 0 || position > this->length) return false;

    node<T>* new_node = new node<T>(data);
    if(new_node == nullptr) return false;
    if(head == nullptr) 
    {
        head = new_node;
        return true;
    } 

    node<T>* current = head;
    int i = 0;
    while(current->next != nullptr && i < position - 1)
    { 
        current = current->next; 
        i++;
    }

    if(current->next == nullptr) 
    {
        current->next = new_node;
        return true;
    }

    new_node->next = current->next;
    current->next = new_node;
    length++;
    return true;

}

template <typename T>
inline bool LinkedList<T>::addLast(T data) 
{
    node<T>* new_node = new node<T>(data);
    if (head == nullptr) 
    {
        head = new_node;
        return true;
    }
    node<T>* current = head;
    while (current->next != nullptr) 
    {
        current = current->next;
    }
    current->next = new_node;
    length++;
    return true;
}

template <typename T>
inline bool LinkedList<T>::contains(T data) 
{
    node<T>* current = head;
    while (current != nullptr) 
    {
        if (current->data == data)
            return true;
        current = current->next;
    }
    return false;
}

template <typename T>
inline bool LinkedList<T>::deleteFirst()
{
    if(head == nullptr) return false;
    node<T>* temp = head;
    head = head->next;
    delete temp;
    length--;
    return true;
}

template <typename T>
inline bool LinkedList<T>::deleteAt(int position) 
{
    if(head == nullptr) return false;
    
    if(head->next == nullptr) 
    {
        delete head;
        head = nullptr;
        return true;
    }

    node<T>* current = head;
    int i = 0;
    while(current->next->next != nullptr && i < position - 1){
        current = current->next;
        i++;
    }

    if(current->next->next == nullptr) 
    {
        delete current->next;
        current->next = nullptr;
        return true;
    }
    
    node<T>* temp = current->next;
    current->next = temp->next;
    delete temp;
    length--;
    return true;
}

template <typename T>
inline bool LinkedList<T>::deleteLast()
{

    if(head == nullptr) return false;
    
    if(head->next == nullptr) 
    {
        delete head;
        head = nullptr;
        return true;
    }

    node<T>* current = head;

    while(current->next->next != nullptr)
    {
        current = current->next;
    }

    node<T>* temp = current->next;
    current->next = nullptr;
    delete temp;
    length--;
    return true;
}

template <typename T>
inline void LinkedList<T>::display() 
{
    node<T>* current = head;
    while (current != nullptr) 
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    
    std::cout << "\n";
}
