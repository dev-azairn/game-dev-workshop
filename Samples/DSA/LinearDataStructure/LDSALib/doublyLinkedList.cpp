#include "list.hpp"

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
                return std::nullopt;
            }
            int i = 0;
            node<T>* current = head;
            while (i < index)
            {
                current = current->next;
                i++;
            }
            return current->data;
        }

        void set(int index, T data)
        {
            if (index < 0 || index >= length) return ();
            if (index < 0 || index >= length) 
            {
                return std::nullopt;
            }
            int i = 0;
            node<T>* current = head;
            while (i < index)
            {   
                current = current->next
                i++;
            } 
            current->data = data;
        }
        
        bool reverse()
        {

        }

        bool contains()
        {

        }

        bool addFirst(T data)
        {
        
            node<T>* new_node = new node<T>(data);
            if (new_node == nullptr) 
            {
                std:: cout << "Cannot allocate for new node." << "\n";
                return false;
            }
            if (head == nullptr) 
            {
                head = new_node;
                return true;
            }
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
        }

        bool addLast(T data)
        {
            node<T>* new_node = new node<T>(data);
            if (new_node == nullptr) 
            {
                std:: cout << "Cannot allocate for new node." << "\n";
                return false;
            }
            if (head = nullptr) head = new_node;
            
            
            
        }
        bool deleteFirst()
        {

        }

        bool deleteLast()
        {

        }

        bool addAt(int index, T data)
        {

        }

        bool deleteAt(int index)
        {

        }

        void display()
        {

        }

};
