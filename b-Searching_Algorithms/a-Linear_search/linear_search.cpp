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
int linearSearchIterative(int arr[], int size, int num)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            return i; // the index of founded num
        }
    }

    return -1; //-1 means not found in the array
}

///==================================================================
//? RECURSIVE WAY
// EASY WAY
int linearSearchRecursive1(int arr[], int size, int num, int current = 0)
{
    if (current == size)
        return -1;

    if (arr[current] == num)
        return current;

    return linearSearchRecursive1(arr, size, num, current + 1);
}

// SMART WAY
int linearSearchRecursive2(int arr[], int size, int num)
{
    if (size < 0)
        return -1;

    if (arr[size] == num)
        return size;

    return linearSearchRecursive2(arr, size - 1, num);
}
int main()
{
    int arr[7] = {2, 8, 9, 1, 5, 0, 7};

    LABEL(1, "ITERATIVE WAY")
    cout << "5 found at index : " << linearSearchIterative(arr, 7, 5) << endl;

    BREAK; //-----------------------------------

    LABEL(2, "RECURSIVE EASY WAY")
    cout << "5 found at index : " << linearSearchRecursive1(arr, 7, 5) << endl;

    LABEL(2, "RECURSIVE SMART WAY")
    cout << "5 found at index : " << linearSearchRecursive2(arr, 7, 5) << endl;
}