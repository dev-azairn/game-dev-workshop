// Sequence Interface
#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP
#pragma once
#include <optional>
#include <iostream>
template <typename T>
class Sequence
{
    public:
        virtual ~Sequence() {};
        virtual int size() = 0;
        virtual std::optional<T> get(int index) = 0;
        virtual bool set(int index, T data) = 0;
        virtual bool addFirst(T data) = 0;
        virtual bool addLast(T data) = 0;
        virtual bool deleteFirst() = 0;
        virtual bool deleteLast() = 0;
        virtual bool addAt(int index, T data) = 0;
        virtual bool deleteAt(int index) = 0;
        virtual void display() = 0;
};
#endif