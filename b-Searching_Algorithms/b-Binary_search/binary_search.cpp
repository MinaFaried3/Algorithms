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

///---------------------------------------------------------------------------------------------------------

// ? ITERATIVE WAY
int BinarySearchIterative(int arr[], int size, int num)
{
    int start = 0;
    int end = size - 1;
    int mid;

    while (start <= end)
    {
        mid = start + (end - start) / 2;

        if (arr[mid] == num)
            return mid;

        if (arr[mid] > num)
            end = mid - 1;

        else if (arr[mid] < num)
            start = mid + 1;
    }

    return -1; //-1 means not found in the array
}

///==================================================================
//? RECURSIVE WAY
int BinarySearchRecursive(int arr[], int num, int start, int end)
{
    if (start > end)
        return -1;

    int mid = (start + end) / 2;

    if (arr[mid] == num)
        return mid;

    if (num < arr[mid])
        return BinarySearchRecursive(arr, num, start, mid - 1);

    if (num > arr[mid])
        return BinarySearchRecursive(arr, num, mid + 1, end);
}
int main()
{
    //! notice the array must be ordered
    const int size = 7;
    int arr[size] = {1, 3, 7, 9, 33, 44, 90};

    LABEL(1, "ITERATIVE WAY")
    cout << "7 found at index : " << BinarySearchIterative(arr, size, 7) << endl;

    BREAK; //-----------------------------------

    LABEL(2, "RECURSIVE WAY")
    cout << "7 found at index : " << BinarySearchRecursive(arr, 7, 0, size - 1) << endl;
}