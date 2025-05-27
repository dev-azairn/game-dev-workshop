#ifndef LIST_HPP
#define LIST_HPP

#include "sequence.hpp"

    template <typename T>
    class List : Sequence<T>
    {
        virtual bool reverse();
        virtual bool contains();
    };

#endif