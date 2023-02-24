#include <set>
#include <map>
#include <array>
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
#define loop0(n) for (int i = 0; i < n; i++)
#define loop1(n) for (int i = 1; i <= n; i++)
#define loop(i, n) for (int i = 0; i < (int)(n); ++i)
#define loopSz(i, v) for (int i = 0; i < sz(v); ++i)
#define BREAK cout << "--------------------------------------------------------------------" << endl
int numIDX = 0;
#define LABEL(title) cout << endl                                        \
                          << ++numIDX << " - " << title << " :-" << endl \
                          << endl;
#define PI 3.14159265358979323846
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)
#define mino                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

// * 1 - find first element in array
//   0 1 2 3 4 4 4 4 4 5 6 8 8 => find first [4]
int findFirstBinarySearch(int arr[], int size, int num)
{
    int start = 0;
    int end = size - 1;
    int mid;

    while (start < end)
    {
        mid = (start + end) / 2;
        if (num < arr[mid])
            end = mid - 1;
        else if (num > arr[mid])
            start = mid + 1;
        else // num == arr[mid]
            end = mid;
    }

    return start;
}
//-----------------------------------------------------------

// * 2 - find last element in array
//   0 1 2 3 4 4 4 4 4 5 6 8 8 => find last [4]
int findLastBinarySearch(int arr[], int size, int num)
{
    int start = 0;
    int end = size - 1;
    int mid;

    while (start < end)
    {
        mid = start + (end - start + 1) / 2;
        if (num < arr[mid])
            end = mid - 1;
        else if (num > arr[mid])
            start = mid + 1;
        else // num == arr[mid]
            start = mid;
    }

    return start;
}
//-----------------------------------------------------------

int main()
{
    const int size = 15;
    int arr[size] = {0, 1, 2, 2, 3, 3, 4, 4, 4, 4, 4, 5, 6, 8, 8};

    LABEL("find first element in array");

    cout << findFirstBinarySearch(arr, size, 4) << endl;

    BREAK; //------------------------------------------------------

    LABEL("find Last element in array");

    cout << findLastBinarySearch(arr, size, 4) << endl;

    BREAK; //------------------------------------------------------
}