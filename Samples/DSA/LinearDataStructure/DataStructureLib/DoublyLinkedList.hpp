#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP
#pragma once
#include "Sequence.hpp"
#include "List.hpp"
template <typename T>
class DoublyLinkedList : public List<T>
{
    template <typename U>
    struct node {
            int data;
            node<U>* prev;
            node<U>* next;
            node(U data) : data(data){}
    };

    private:
        node<T>* head;
        int length;

    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
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
};
#endif