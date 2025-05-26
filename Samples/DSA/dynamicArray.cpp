#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>

template <class T>
class DynamicArray {
    private:
        T* array;
        int length;
        int capacity;

    public:
        DynamicArray(){
            length = 0;
            capacity = 1;
            array = new T[capacity];
        }

        ~DynamicArray()
        {
            delete[] array;
        }
        
        bool resize()
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

        bool addFirst(T data)
        {   
            if(array == nullptr) DynamicArray();
            if(length + 1 > capacity) if(!resize()) return false;
            T* temp_array = new T[capacity];
            if(temp_array == nullptr) return false;
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

        bool deleteFirst(T data)
        {
            if(length <= 0) return false;
            return true;
        }

        bool addLast(T data)
        {   
            if(array == nullptr) DynamicArray();
            if(length + 1 > capacity) if(!resize()) return false;
            array[length] = data;
            length++;
            return true;
        }

        void display_array()
        {
            for (int i = 0; i < length; i++)
            {
                std::cout << array[i];
                if(i != length - 1)
                    std::cout << ", ";
            }
            std::cout << "\n";
        }
        

};  

int main(){
    DynamicArray<int>* arr = new DynamicArray<int>(); 
    arr->addLast(10);
    arr->addLast(20);
    arr->addLast(30);
    arr->addLast(40);
    arr->addLast(50);
    arr->addFirst(0);
    arr->display_array();

    //report memory leak
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG); 
    _CrtDumpMemoryLeaks();
    return 0;
}