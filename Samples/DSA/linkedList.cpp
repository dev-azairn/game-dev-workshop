#include <iostream>
#include "list.cpp"

template <typename T>
struct node {
    T data;
    node* next;

    node(T data) : data(data), next(nullptr) {};
};

template <typename T>
class LinkedList : public List<T> 
{
    private:
        node<T>* head;
        int length;

    public:
        LinkedList() 
        {
            head = nullptr;
            length = 0;
        }

        virtual ~LinkedList() 
        {
            node<T>* current = head;
            while (current != nullptr) 
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

        T get(int index)
        {
            if(index < 0 || index >= length) throw std::runtime_error("Invalid index!");

            int i = 0;
            node<T>* current = head;
            while(head != nullptr && i < index)
            {
                current = current->next;
                i++;
            }
            return current->data;
        }

        void set(int index, T data)
        {
            if(index < 0 || index >= length) throw std::runtime_error("Invalid index!");
            

            int i = 0;
            node<T>* current = head;
            while(head != nullptr && i < index)
            {
                current = current->next;
                i++;
            }
            current->data = data;
        }

        bool addFirst(T data) 
        {
            node<T>* new_node = new node<T>(data);
            new_node->next = head;
            head = new_node;
            length++;
            return true;
        }

        bool addAt(int position, T data)
        {
            node<T>* new_node = new node<T>(data);
            if(new_node == nullptr) return false;
            if(head == nullptr) 
            {
                head = new_node;
                return true;
            } 

            node<T>* current = head;
            int i = 0;
            while(current->next != nullptr && i < position - 1)
            { 
                current = current->next; 
                i++;
            }

            if(current->next == nullptr) 
            {
                current->next = new_node;
                return true;
            }

            new_node->next = current->next;
            current->next = new_node;
            length++;
            return true;

        }

        bool addLast(T data) 
        {
            node<T>* new_node = new node<T>(data);
            if (head == nullptr) 
            {
                head = new_node;
                return true;
            }
            node<T>* current = head;
            while (current->next != nullptr) 
            {
                current = current->next;
            }
            current->next = new_node;
            length++;
            return true;
        }

        bool contains(T data) 
        {
            node<T>* current = head;
            while (current != nullptr) 
            {
                if (current->data == data)
                    return true;
                current = current->next;
            }
            return false;
        }

        bool deleteFirst()
        {
            if(head == nullptr) return false;
            node<T>* temp = head;
            head = head->next;
            delete temp;
            length--;
            return true;
        }

        bool deleteAt(int position) 
        {
            if(head == nullptr) return false;
            
            if(head->next == nullptr) 
            {
                delete head;
                head = nullptr;
                return true;
            }

            node<T>* current = head;
            int i = 0;
            while(current->next->next != nullptr && i < position - 1){
                current = current->next;
                i++;
            }

            if(current->next->next == nullptr) 
            {
                delete current->next;
                current->next = nullptr;
                return true;
            }
            
            node<T>* temp = current->next;
            current->next = temp->next;
            delete temp;
            length--;
            return true;
        }

        bool deleteLast()
        {

            if(head == nullptr) return false;
            
            if(head->next == nullptr) 
            {
                delete head;
                head = nullptr;
                return true;
            }

            node<T>* current = head;

            while(current->next->next != nullptr)
            {
                current = current->next;
            }

            node<T>* temp = current->next;
            current->next = nullptr;
            delete temp;
            length--;
            return true;
        }

        void display() 
        {
            node<T>* current = head;
            while (current != nullptr) 
            {
                std::cout << current->data << " ";
                current = current->next;
            }
            
            std::cout << "\n";
        }
};

// Tester
/*

int main() 
{
    std::cout << "Welcome to Singly Linked List Tester!" << "\n";
    List<int>* list = new LinkedList<int>();
    list->addFirst(10);
    list->addFirst(20);
    list->addLast(30);
    list->addAt(2, 40);
    list->deleteAt(1);
    list->deleteFirst();
    list->deleteLast();
    list->addFirst(50);
    list->addFirst(60);
    list->addFirst(70);
    list->set(2, 10);
    list->set(3, 20);
    list->display();
    std::cout << list->get(0) << "\n";
    std::cout << list->get(3) << "\n";
    delete list;
    return 0;
}
*/