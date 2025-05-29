#include <iostream>
#include <optional>

using namespace std;

void algochecker(bool returnValue)
{
    if (returnValue)
        cout << "Successfully" << "\n";
    else 
        cout << "Error" << "\n";
}

void sizePrinter(int size)
{
    cout << "Data Structure Size: " <<  size << "\n";
}

