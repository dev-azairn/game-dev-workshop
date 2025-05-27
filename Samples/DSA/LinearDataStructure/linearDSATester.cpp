// =================== DO NOT MODIFY THIS FILE =========================
#include "LDSALib/linearDSA.hpp"

void arrayTester();
void dynamicArrayTester();
void singlyLinkedListTester();
void doublyLinkedListTester();
void staticStackTester();
void dynamicStackTester();
void staticQueueTester();
void dynamicQueueTester();

int main()
{
    arrayTester();
    dynamicArrayTester();
    singlyLinkedListTester();
    doublyLinkedListTester();
    staticStackTester();
    dynamicStackTester();
    staticQueueTester();
    dynamicQueueTester();

}

void arrayTester()
{
    Array<int>* array = new Array<int>(10);
}

void doublyLinkedListTester()
{
    DoublyLinkedList<int>* list = new DoublyLinkedList<int>(); 

    delete list;
}