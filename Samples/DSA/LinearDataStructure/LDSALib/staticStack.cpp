#include "sequence.hpp"
#include "linkedList.cpp"

template <typename T>
class Stack : public LinkedList<T>
{
    int capacity;
    public: 
        Stack(int c) : LinkedList<T>(), capacity(c) {};
       
        bool push(T data)
        {   
            if (this->size() == capacity)
            { 
                std::cout << "Stack overflow";
                return false;
            }

            return this->addLast(data);
        }

        T pop()
        {
            if (this->size() <= 0) throw std::runtime_error("No element left!");
            T x = this->get(0);
            if(!this->deleteFirst()) throw std::runtime_error("Error");
            return x;
        }

};
