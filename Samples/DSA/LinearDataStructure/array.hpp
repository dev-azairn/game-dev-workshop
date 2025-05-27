#include "list.hpp"

template <typename T>
class Array : public List<T>
{
    private:
        T* array;
        int length;
        int capacity;
    public:
        Array(int capacity) : capacity(capacity), length(0), array(new array[capacity]) {}
        
        ~Array()
        {
            delete array;
        }

        
};