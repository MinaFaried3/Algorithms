#include <set>
#include <map>
#include <list>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <stdio.h>
#include <assert.h>
#include <memory.h>
#include <bitset>
using namespace std;

#define lol long long int
#define endl '\n'
#define sz(v) ((int)((v).size()))
#define loop0(n) for (size_t i = 0; i < n; i++)
#define loop(i, n) for (int i = 0; i < (int)(n); ++i)
#define loopSz(i, v) for (int i = 0; i < sz(v); ++i)
#define BREAK cout << endl \
                   << "--------------------------------------------------------------------" << endl
#define LABEL(i, title) cout << " " << i << " - " << title << " :-" << endl \
                             << endl;
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

///---------------------------------------------------------------------------------------------------------
// ? ITERATIVE WAY
void bubbleSortIterative(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        // Last i elements are already in place
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

// ? SMART WAY
/*
this makes the algorithm not blind
this mean if the array was sorted
it will take only O(n) not o(n^2)
*/
void optimizedBubbleSortIterative(int arr[], int size)
{
    bool isSwapped;
    for (int i = 0; i < size - 1; i++)
    {
        isSwapped = false;
        // Last i elements are already in place
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
        }

        if (isSwapped == false)
            break;
    }
}

///==================================================================

//? RECURSIVE WAY
void bubbleSortRecursive(int arr[], int size)
{
    if (size == 0 || size == 1)
        return;

    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    bubbleSortRecursive(arr, size - 1);
}
// ? SMART WAY
/*
this makes the algorithm not blind
this mean if the array was sorted
it will take only O(n) not o(n^2)
*/
void optimizedBubbleSortRecursive(int arr[], int size)
{
    if (size == 0 || size == 1)
        return;

    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }

    optimizedBubbleSortRecursive(arr, size - 1);
}
int main()
{
    //! notice the array must be ordered
    const int size = 7;
    int arr[size] = {2, 8, 9, 1, 5, 7, 0};

    LABEL(1, "ITERATIVE WAY")
    printArr(arr, size);
    bubbleSortIterative(arr, size);
    printArr(arr, size);

    LABEL(2, "ITERATIVE SMART WAY")
    /*
    this makes the algorithm not blind
    this mean if the array was sorted
    it will take only O(n) not o(n^2)
    */
    int arr2[size] = {0, 2, 8, 9, 1, 5, 7};
    printArr(arr2, size);
    optimizedBubbleSortIterative(arr2, size);
    printArr(arr2, size);

    BREAK; //-----------------------------------
    LABEL(2, "RECURSIVE WAY")
    int arr3[size] = {0, 2, 8, 9, 1, 5, 7};
    printArr(arr3, size);
    bubbleSortRecursive(arr3, size);
    printArr(arr3, size);

    LABEL(2, "ITERATIVE SMART WAY")
    /*
    this makes the algorithm not blind
    this mean if the array was sorted
    it will take only O(n) not o(n^2)
    */
    int arr4[size] = {0, 2, 8, 9, 1, 5, 7};
    printArr(arr4, size);
    optimizedBubbleSortRecursive(arr4, size);
    printArr(arr4, size);
}