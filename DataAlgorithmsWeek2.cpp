// DataAlgorithmsWeek2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void Swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void SelectionSort(int* a, int size)
{
    int smallest;
    for (int n = 0; n < size; n++)
    {
        smallest = n;
        for (int i = n + 1; i < size; i++)
        {
            if (a[i] < a[smallest])
            {
                smallest = i;
            }
        }
        Swap(&a[n], &a[smallest]);
    }
}

int main()
{
    int data[] = { 4,5,6,1,3,9,4,8,2,7 };

    int arraySize = sizeof(data) / sizeof(int);

    SelectionSort(data, arraySize);

    for (int i = 0; i < arraySize; i++)
    {
        std::cout << data[i] << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
