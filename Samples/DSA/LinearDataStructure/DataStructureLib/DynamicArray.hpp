#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP
#pragma once
#include "Sequence.hpp"
template <typename T>
class DynamicArray : public Sequence<T>
{
    private:
        T* array;
        int length;
        int capacity;
        bool resize();
    public:
        DynamicArray();
        ~DynamicArray();
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
#include "DynamicArray.inl"
#endif