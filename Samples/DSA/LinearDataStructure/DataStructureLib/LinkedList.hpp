#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP
#pragma once
#include "List.hpp"
#include "Sequence.hpp"
template <typename T>
class LinkedList : public List<T>
{   
    template <typename U>
    struct node{
        U data;
        node<U>* next;
        node(U data) : data(data), next(nullptr) {};
    };

    private:  
        node<T>* head;
        int length;
        bool reverseList(node<T>* current);

    public:
        LinkedList();
        ~LinkedList();
        int size();
        std::optional<T> get(int index);
        bool set(int index, T data);
        bool addFirst(T data);
        bool addLast(T data);
        bool deleteFirst();
        bool deleteLast();
        bool addAt(int index, T data);
        bool deleteAt(int index);
        void display();  
        bool reverse();
        bool contains(T data);
};
#include "LinkedList.inl"
#endif