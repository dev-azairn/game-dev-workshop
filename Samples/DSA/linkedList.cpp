#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;

    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
    }

    bool insertAtTheBeginning(T data) {
        Node<T>* new_node = new Node<T>(data);
        new_node->next = head;
        head = new_node;
        return true;
    }

    bool insertAtPosition(int position, T data){
        Node<T>* new_node = new Node<T>(data);
        if(new_node == nullptr) return false;
        if(head == nullptr) {
            head = new_node;
            return true;
        } 

        Node<T>* current = head;
        int i = 0;
        while(current->next != nullptr && i < position - 1){ current = current->next; i++;}
        if(current->next == nullptr) {
            current->next = new_node;
            return true;
        }

        new_node->next = current->next;
        current->next = new_node;

        return true;

    }

    bool insertAtTheEnd(T data) {
        Node<T>* new_node = new Node<T>(data);
        if (head == nullptr) {
            head = new_node;
            return true;
        }
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
        return true;
    }

    bool contains(T data) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == data)
                return true;
            current = current->next;
        }
        return false;
    }

    bool removeAtTheBeginning(){
        if(head == nullptr) return false;
        Node<T>* temp = head;
        head = head->next;
        
        delete temp;
        return true;
    }

    bool removeAtPosition(int position) {
        if(head == nullptr) return false;
        
        if(head->next == nullptr) {
            delete head;
            head = nullptr;
            return true;
        }

        Node<T>* current = head;
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
        
        Node<T>* temp = current->next;
        current->next = temp->next;
        delete temp;
        return true;
    }

    bool removeAtTheEnd(){

        if(head == nullptr) return false;
        
        if(head->next == nullptr) {
            delete head;
            head = nullptr;
            return true;
        }

        Node<T>* current = head;

        while(current->next->next != nullptr){
            current = current->next;
        }

        Node<T>* temp = current->next;
        current->next = nullptr;
        delete temp;
        return true;
    }

    void displayList() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        
        std::cout << "\n";
    }
};

int main() {
    std::cout << "Welcome to Singly Linked List Tester!" << "\n";
    LinkedList<int>* list = new LinkedList<int>();
    int input;
    do {
        int data;
        int position;
        std::cout << "========================" <<"\n";
        std::cout << "Choose Mode: " << "\n";
        std::cout << "1. InsertAtTheBeginning" << "\n";
        std::cout << "2. InsertAtPosition" << "\n";
        std::cout << "3. InsertAtTheEnd" << "\n";
        std::cout << "4. DeleteAtTheBeginning" << "\n";
        std::cout << "5. DeleteAtPostition" << "\n";
        std::cout << "6. DeleteAtTheEnd" << "\n";
        std::cout << "7. DisplayList" << "\n";
        std::cout << "8. DeleteList and Exit" << "\n";
        std::cout << "========================" <<"\n";
        std::cout << "Input the mode: ";
        std::cin >> input;
        switch (input)
        {
        case 1:
            std::cout << "Data: ";
            std::cin >> data;
            if(list->insertAtTheBeginning(data))
                std::cout << "Success" << "\n";
            else
                std::cout << "Not Success" << "\n";
            break;
        case 2:
            std::cout << "Data: ";
            std::cin >> data;
            
            std::cout << "Position: ";
            std::cin >> position;
            if(list->insertAtPosition(position, data))
                std::cout << "Success" << "\n";
            else
                std::cout << "Not Success" << "\n";
            break;
        case 3:
            std::cout << "Data: ";
            std::cin >> data;
            if(list->insertAtTheEnd(data))
                std::cout << "Success" << "\n";
            else
                std::cout << "Not Success" << "\n";
            break;
        case 4:
            if(list->removeAtTheBeginning())
                std::cout << "Success" << "\n";
            else
                std::cout << "Not Success" << "\n";
            break;
        case 5:
            std::cout << "Position: ";
            std::cin >> position;
            if(list->removeAtPosition(position))
                std::cout << "Success" << "\n";
            else
                std::cout << "Not Success" << "\n";
            break;
        case 6:
            if(list->removeAtTheEnd())
                std::cout << "Success" << "\n";
            else
                std::cout << "Not Success" << "\n";
            break;
        case 7:
            list->displayList();
            break;
        case 8:
            delete list;
        default:
            break;
        }
    
    } while (input != 8);
    return 0;
}