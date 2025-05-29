#pragma once
#include "DynamicArray.hpp"

template <typename T>
inline DynamicArray<T>::DynamicArray() : length(0), capacity(1), array(new T[1]){}


template <typename T>
inline DynamicArray<T>::~DynamicArray()
{
    delete[] array;
}

template <typename T>
inline bool DynamicArray<T>::resize()
{
    capacity+=capacity;
    T* temp_array = new T[capacity];
    if(temp_array == nullptr) return false; 
    for (int i = 0; i < length; i++)
    {
        temp_array[i] = array[i];
    }
    delete[] array;
    array = temp_array;
    return true;
}

template <typename T>
inline int DynamicArray<T>::size()
{
     return length;
}

template <typename T>
inline std::optional<T> DynamicArray<T>::get(int index)
{
    if(index >= length || index < 0) 
        return std::nullopt;
    return array[index];
}

template <typename T>
bool DynamicArray<T>::set(int index, T data)
{
    if(index >= length || index < 0) 
        return false;
    array[index] = data;
    return true;
}

template <typename T>
bool DynamicArray<T>::addFirst(T data)
{   
    if(array == nullptr) DynamicArray();
    if(length + 1 > capacity) 
        if(!resize()) 
            return false;
    T* temp_array = new T[capacity];
    if(temp_array == nullptr) 
        return false;
    length++;
    temp_array[0] = data;
    for(int i = 1; i < length; i++)
    {
        temp_array[i] = array[i - 1];
    }
    delete [] array;
    array = temp_array;
    return true;
}

template <typename T>
bool DynamicArray<T>::deleteFirst()
{
    if(length <= 0 || array == nullptr) return false;
    length--;
    for(int i = 0; i < length; i++)
    {
        array[i] = array[i+1];
    }
    return true;
}

template <typename T>
bool DynamicArray<T>::addLast(T data)
{   
    if(array == nullptr) DynamicArray();
    if(length + 1 > capacity) if(!resize()) return false;
    array[length] = data;
    length++;
    return true;
}

template <typename T>
bool DynamicArray<T>::deleteLast()
{
    if (length <= 0 || array == nullptr) return false;
    length--;
    return true;
}

template <typename T>
bool DynamicArray<T>::addAt(int index, T data)
{
    if (index >= length + 1) return false;
    if (length + 1 > capacity) if (!resize()) return false;
    length++;
    for (int i = length - 1;  i > index; i--)
    {
        array[i] = array[i - 1];
    }
    array[index] = data;
    return true;
}

template <typename T>
bool DynamicArray<T>::deleteAt(int index)
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
void DynamicArray<T>::display()
{
    for (int i = 0; i < length; i++)
    {
        std::cout << array[i];
        if(i != length - 1)
            std::cout << ", ";
    }
    std::cout << "\n";
}
