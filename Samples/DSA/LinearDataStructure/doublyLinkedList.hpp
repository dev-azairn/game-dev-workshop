#include "linkedList.hpp"

template <typename T>
struct node
{
    int data;
    node* prev;
    node* next;

    node(T data) : data(data), prev(nullptr), next(nullptr) {}
};

template <typename T>
class DoublyLinkedList : public List<T>
{
    private:
        node<T>* head;
        node<T>* tail;
        int length;


    public:
        DoublyLinkedList()
        {
            head = new node<T>();
            length = 0;
        }

        ~DoublyLinkedList() 
        {
            node<T>* current = head;
            while (current->next != nullptr)
            {
                node<T>* temp = current;
                current = current->next;
                delete temp;
            }     
        }


        int size()
        {
            return length;
        }

        std::optional<T> get(int index)
        {
            if (index < 0 || index >= length) 
            {
                
            }
            int i = 0;
            node<T>* current;
            if(index < length/2)
                current = head;
            else
                current = tail;
            
        }

};
