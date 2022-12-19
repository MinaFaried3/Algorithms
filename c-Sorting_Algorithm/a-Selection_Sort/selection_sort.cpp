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

int findMinNumber(int arr[], int start, int end)
{
    int minIndex = INT32_MAX;

    for (int i = start; i < end; i++)
    {
        if (arr[minIndex] > arr[i])
            minIndex = i;
    }

    return minIndex;
}

// ? ITERATIVE WAY
void selectionSortIterative(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        // 1 - first find the next min number in array
        int minIndex = findMinNumber(arr, i, size);

        // 2- second swap it with current number
        swap(arr[minIndex], arr[i]);
    }
}

///==================================================================

//? RECURSIVE WAY
int findMinNumberRecursive(int arr[], int current, int size)
{
    if (current == size - 1)
        return current;

    int minIndex = findMinNumberRecursive(arr, current + 1, size);

    if (arr[current] < arr[minIndex])
        return current;
    else
        return minIndex;
}

void selectionSortRecursive(int arr[], int size, int current = 0)
{
    if (current == size)
        return;

    int minIndex = findMinNumberRecursive(arr, current, size);

    swap(arr[current], arr[minIndex]);

    selectionSortRecursive(arr, size, current + 1);
}
int main()
{
    //! notice the array must be ordered
    const int size = 7;
    int arr[size] = {2, 8, 9, 1, 5, 7, 0};

    LABEL(1, "ITERATIVE WAY")
    printArr(arr, size);
    selectionSortIterative(arr, size);
    printArr(arr, size);

    BREAK; //-----------------------------------
    LABEL(2, "RECURSIVE WAY")
    int arr2[size] = {0, 2, 8, 9, 1, 5, 7};
    printArr(arr2, size);
    selectionSortRecursive(arr2, size);
    printArr(arr2, size);
}