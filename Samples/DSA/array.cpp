#include <iostream>

int arr[5][5];

int main(void)
{   
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << "Address of row " << i << ", col " << j << ": " << &arr[i][j] << "\n";
        }
    }
    return (0);
}