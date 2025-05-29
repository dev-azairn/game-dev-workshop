#ifndef LIST_HPP
#define LIST_HPP
#pragma once
#include "Sequence.hpp"

    template <typename T>
    class List : Sequence<T>
    {
        virtual bool reverse() = 0; 
        virtual bool contains(T data) = 0;
    };
#endif