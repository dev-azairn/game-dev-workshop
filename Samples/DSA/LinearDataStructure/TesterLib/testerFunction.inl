#pragma once
#include "tester.hpp"

// For the template function, class or every structures, they cannot be implemented in separeated file directly.
// Using .inl with pragma (avoid the redefinition function)
using namespace std;
template <typename T>
void returnchecker(optional<T> returnValue)
{
    if(returnValue.has_value())
    {
        cout << "Value: ";
        cout << returnValue.value() << "\n";
    } 
    else 
    {
        cout << "No return value" << "\n";
    }
}