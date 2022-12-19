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
void insertionSortIterative(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int currentNum = arr[i];

        int x = i - 1;
        while (x >= 0 && arr[x] > currentNum)
        {
            arr[x + 1] = arr[x]; // the after = before
            x--;
        }

        arr[x + 1] = currentNum;
    }
}

///==================================================================

//? RECURSIVE WAY
// this way must take the last index = size - 1
void insertionSortRecursive1(int arr[], int index)
{
    // Base case
    if (index <= 0)
        return;

    // Sort first n-1 elements
    insertionSortRecursive1(arr, index - 1);

    int current = arr[index];
    int x = index - 1;

    while (x >= 0 && arr[x] > current)
    {
        arr[x + 1] = arr[x]; // the after = before
        x--;
    }

    arr[x + 1] = current;
}

// this way must take main size of array
void insertionSortRecursive2(int arr[], int size)
{
    // Base case
    if (size <= 1)
        return;

    // Sort first n-1 elements
    insertionSortRecursive2(arr, size - 1);

    int current = arr[size - 1];
    int x = size - 2;

    while (x >= 0 && arr[x] > current)
    {
        arr[x + 1] = arr[x]; // the after = before
        x--;
    }

    arr[x + 1] = current;
}
int main()
{
    //! notice the array must be ordered
    const int size = 7;
    int arr[size] = {2, 8, 9, 1, 5, 7, 0};

    LABEL(1, "ITERATIVE WAY")
    printArr(arr, size);
    insertionSortIterative(arr, size);
    printArr(arr, size);

    BREAK; //-----------------------------------
    LABEL(2, "RECURSIVE WAY")
    int arr2[size] = {0, 2, 8, 9, 1, 5, 7};
    printArr(arr2, size);
    insertionSortRecursive1(arr2, size - 1);
    printArr(arr2, size);

    LABEL(2, "RECURSIVE WAY")
    int arr3[size] = {0, 2, 8, 9, 1, 5, 7};
    printArr(arr3, size);
    insertionSortRecursive2(arr3, size);
    printArr(arr3, size);
}