#ifndef ARRAY_HPP
#define ARRAY_HPP
#pragma once
#include "Sequence.hpp" 
template <typename T>
class Array : public Sequence<T>
{
    private:
        T* array;
        int length;
        int capacity;
    public:
        Array(int capacity);
        ~Array();
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
#include "Array.inl"
#endif
