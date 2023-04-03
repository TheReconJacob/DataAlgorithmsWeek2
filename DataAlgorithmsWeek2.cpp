// DataAlgorithmsWeek2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>

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

void BubbleSort(int* a, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                Swap(&a[j], &a[j + 1]);
            }
        }
    }
}

void EnhancedBubbleSort(int* a, int size)
{
    bool sorted = false;
    int lastUnsorted = size - 1;
    while(!sorted)
    {
        sorted = true;
        for(int j = 0; j < lastUnsorted; j++)
        {
            if (a[j] > a[j + 1])
            {
                Swap(&a[j], &a[j + 1]);
                sorted = false;
            }
        }
        lastUnsorted--;
    }
}

int SequentialSearch(int* a, int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (a[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int BinarySearch(int* a, int size, int key)
{
    int middle = 0;
    int lower = 0;
    int upper = size - 1;

    while (lower <= upper)
    {
        middle = (lower + upper) / 2;

        if (key < a[middle])
        {
            upper = middle - 1;
        }
        else if (key > a[middle])
        {
            lower = middle + 1;
        }
        else
        {
            return middle;
        }
    }

    return -1;
}


int main()
{
    srand(time(0));
    
    int bigData[20000];

    int arraySize = sizeof(bigData) / sizeof(int);
    
    for (int i = 0; i < arraySize; i++) {
        bigData[i] = rand() % 101;
    }

    EnhancedBubbleSort(bigData, arraySize);

    int indexOfFive = BinarySearch(bigData, arraySize, 5);

    std::cout << "Index of 5: " << indexOfFive << std::endl;

    //Index result will be -1 if one of the sort functions isn't used because the Binary Search
    //can't search unordered arrays.

    //Sequential search is faster when you take into acccount the fact that the array has to be sorted in order for
    //the binary search to work. If the array is already sorted, then the Binary and Sequential search seem to be done in a similar amount
    //of time. After testing data with 100000 bytes, both searches finished in 89 seconds.

    return 0;
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
