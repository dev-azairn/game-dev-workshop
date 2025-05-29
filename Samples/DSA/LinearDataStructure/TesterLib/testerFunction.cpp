#include "tester.hpp"
#include "include/Array.hpp"
#include "include/DynamicArray.hpp"
#include "include/LinkedList.hpp"
#include "include/DoublyLinkedList.hpp"


using namespace std;
void arrayTester()
{
    cout << "======= Array Tester =======" << "\n"; 
    // Instantiation
    Array<int>* array = new Array<int>(10);
    
    // Test Add first
    algochecker(array->addFirst(10));
    algochecker(array->addFirst(20));
    algochecker(array->addLast(30));
    algochecker(array->addLast(40));
    algochecker(array->addAt(2,50));
    algochecker(array->addAt(3,60));
    algochecker(array->deleteFirst());
    algochecker(array->deleteLast());
    algochecker(array->deleteAt(2));
    algochecker(array->set(2,100));
    returnchecker(array->get(0));
    // Error here
    returnchecker(array->get(10));
    algochecker(array->addAt(10,60));
    algochecker(array->set(10, 100));
    // Display array
    sizePrinter(array->size());
    array->display();
    delete array;
}

void dynamicArrayTester()
{
    cout << "======= Dynamic Array Tester =======" << "\n"; 
    // Instantiation
    DynamicArray<int>* array = new DynamicArray<int>();

    // Test Add First
    algochecker(array->addFirst(10));
    algochecker(array->addFirst(20));
    algochecker(array->addLast(30));
    algochecker(array->addLast(40));
    algochecker(array->addAt(2,50));
    algochecker(array->addAt(3,60));
    algochecker(array->deleteFirst());
    algochecker(array->deleteLast());
    algochecker(array->deleteAt(2));
    algochecker(array->set(2,100));
    returnchecker(array->get(0));
    // Error here
    returnchecker(array->get(10));
    algochecker(array->addAt(10,60));
    algochecker(array->set(10, 100));
    // Display array
    sizePrinter(array->size());
    array->display();
    delete array;
}

void singlyLinkedListTester()
{
    cout << "======= Singly Linked List Tester =======" << "\n";

    // Instantiation
    LinkedList<int>* list = new LinkedList<int>();

    // Test Add First
    algochecker(list->addFirst(10));
    algochecker(list->addFirst(20));
    algochecker(list->addLast(30));
    algochecker(list->addLast(40));
    algochecker(list->addAt(2,50));
    algochecker(list->addAt(3,60));
    algochecker(list->deleteFirst());
    algochecker(list->deleteLast());
    algochecker(list->deleteAt(2));
    algochecker(list->set(2,100));
    returnchecker(list->get(0));
    // Error here
    returnchecker(list->get(10));
    algochecker(list->addAt(10,60));
    algochecker(list->set(10, 100));
    // Display array
    sizePrinter(list->size());
    list->display();

    // Reverse Checking
    algochecker(list->reverse());
    list->display();
    delete list;
}

void doublyLinkedListTester()
{

}

void circularLinkedListTester()
{

}

void staticStackTester()
{

}

void staticQueueTester()
{

}

void dynamicStackTester()
{
    
}

void dynamicQueueTester()
{

}
