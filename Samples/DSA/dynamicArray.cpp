#include <iostream>
#include "list.cpp"
#include <stdexcept>


template <typename T>
class DynamicArray : public List<T>{
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

        int size()
        {
            return length;
        }

        T get(int index)
        {
            if(index >= length || index < 0) throw std::runtime_error("Bad index access");
            return array[index];
        }

        void set(int index, T data)
        {
            if(index >= length || index < 0) throw std::runtime_error("Bad index access");
            array[index] = data;
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

        bool deleteFirst()
        {
            if(length <= 0 || array == nullptr) return false;
            length--;
            for(int i = 0; i < length; i++)
            {
                array[i] = array[i+1];
            }
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

        bool deleteLast()
        {
            if (length <= 0 || array == nullptr) return false;
            length--;
            return true;
        }

        bool addAt(int index, T data)
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
        
        bool deleteAt(int index)
        {
            if(length <= 0 || array == nullptr) return false;
            for(int i = index + 1; i < length; i++)
            {
                array[i - 1] = array[i];
            }
            length--;
            return true;
        }

        void display()
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
    List<int>* arr = new DynamicArray<int>(); 

    arr->addLast(10);
    arr->addLast(20);
    arr->addLast(30);
    arr->addLast(40);
    arr->addLast(50);
    arr->addFirst(0);
    arr->deleteLast();
    arr->deleteFirst();
    arr->addAt(2, 60);
    arr->deleteAt(2);
    arr->set(0, 50);
    arr->display();
    std::cout << arr->get(0) << "\n";
    std::cout << arr->size() << "\n";
    // bad index access -> std::cout << arr->get(4);

    //Using Destructor automatically.
    delete arr;
    return 0;
}