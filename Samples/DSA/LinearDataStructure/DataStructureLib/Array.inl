#pragma once
#include "Array.hpp"

template <typename T>
inline Array<T>::Array(int capacity) : capacity(capacity), length(0), array(new T[capacity]){}

template <typename T>
inline Array<T>::~Array()
{
    delete[] array;
}

template <typename T>
inline int Array<T>::size()
{
    return this->length;
}

template <typename T>
inline std::optional<T> Array<T>::get(int index)
{
    if (index < 0 || index >= this->length)
        return std::nullopt;
    return this->array[index];
}

template <typename T>
inline bool Array<T>::set(int index, T data)
{
    if (index < 0 || index >= this->length)
        return false;

    this->array[index] = data;
    return true;
}

template <typename T>
inline bool Array<T>::addFirst(T data)
{
    if (this->length + 1 >= this->capacity)
        return false;
    
    T* tempArray = new T[this->capacity];
    if (tempArray == nullptr) 
        return false;

    this->length++;
    tempArray[0] = data;
    for (int i = 1; i < this->length; i++)
    {
        tempArray[i] = this->array[i - 1];
    }

    delete[] this->array;
    this->array = tempArray;
    return true;
}

template <typename T>
inline bool Array<T>::addLast(T data)
{
    if (this->length + 1 >= this->capacity)
        return false;

    this->array[this->length] = data;
    this->length++;
    return true;    
}

template <typename T>
inline bool Array<T>::deleteFirst()
{
    if (this->length + 1 >= this->capacity)
        return false;

    length--;
    for(int i = 0; i < length; i++)
    {
        array[i] = array[i+1];
    }
    return true; 
}

template <typename T>
inline bool Array<T>::deleteLast()
{
    if (this->length + 1 >= this->capacity)
        return false;
    length--;
    return true;
}

template <typename T>
inline bool Array<T>::addAt(int index, T data)
{
    if (this->length + 1 >= this->capacity) return false;
    if (this->length + 1 < index) return false;
    this->length++;
    for (int i = length - 1;  i > index; i--)
    {
        array[i] = array[i - 1];
    }
    array[index] = data;
    return true;  
}

template <typename T>
inline bool Array<T>::deleteAt(int index)
{
    if(length <= 0 || array == nullptr) return false;
    for(int i = index + 1; i < length; i++)
    {
        array[i - 1] = array[i];
    }
    length--;
    return true;   
}

template <typename T>
inline void Array<T>::display()
{
    for (int i = 0; i < length; i++)
    {
        std::cout << array[i];
        if(i != length - 1)
        std::cout << ", ";
    }
    std::cout << "\n";
}