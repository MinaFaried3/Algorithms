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
void merge(int arr[], int const left, int const mid,
           int const right)
{
    int const subArrOne = mid - left + 1;
    int const subArrTwo = right - mid;

    // Create temp arrays
    int *leftArr = new int[subArrOne];
    int *rightArr = new int[subArrTwo];

    // Copy data to temp arrays leftArr[] and rightArr[]
    for (int i = 0; i < subArrOne; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < subArrTwo; j++)
        rightArr[j] = arr[mid + 1 + j];

    int indexOfSubArrOne = 0;    // Initial index of first sub-arr
    int indexOfSubArrTwo = 0;    // Initial index of second sub-arr
    int indexOfMergedArr = left; // Initial index of merged arr

    // Merge the temp arrays back into arr[left..right]
    while (indexOfSubArrOne < subArrOne && indexOfSubArrTwo < subArrTwo)
    {
        if (leftArr[indexOfSubArrOne] <= rightArr[indexOfSubArrTwo])
        {
            arr[indexOfMergedArr] = leftArr[indexOfSubArrOne];
            indexOfSubArrOne++;
        }
        else
        {
            arr[indexOfMergedArr] = rightArr[indexOfSubArrTwo];
            indexOfSubArrTwo++;
        }
        indexOfMergedArr++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrOne < subArrOne)
    {
        arr[indexOfMergedArr] = leftArr[indexOfSubArrOne];
        indexOfSubArrOne++;
        indexOfMergedArr++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrTwo < subArrTwo)
    {
        arr[indexOfMergedArr] = rightArr[indexOfSubArrTwo];
        indexOfSubArrTwo++;
        indexOfMergedArr++;
    }
    delete[] leftArr;
    delete[] rightArr;
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    printArr(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1); //last index

    cout << "\nSorted array is \n";
    printArr(arr, arr_size);
    return 0;
}