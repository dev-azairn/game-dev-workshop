#include "array.hpp"


template <typename T>
inline Array<T>::Array(int capacity) : capacity(capacity), length(0), array(new T[capacity]) {}

template <typename T>
inline Array<T>::~Array()
{
    delete [] array;
}

template <typename T>
inline int Array<T>::size()
{
    return length;
}


template <typename T>
inline std::optional<T> Array<T>::get(int index)
{
    
}


template <typename T>
inline void Array<T>::set(int index, T data)
{

}
