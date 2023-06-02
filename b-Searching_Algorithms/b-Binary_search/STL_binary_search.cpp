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
#define sizeOf(arr) sizeof(arr) / sizeof(arr[0])
#define mino                              \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);

int main()
{
        LABEL("binary_search");
        int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int size = sizeOf(a);
        sort(a, a + size);

        //* STL
        if (binary_search(a, a + size, 22))
        {
                cout << binary_search(a, a + size, 22) << endl; // found true = 1
                cout << "\nElement found in the array";
        }
        else
        {
                cout << binary_search(a, a + size, 22) << endl; // not found false = 0
                cout << "\nElement not found in the array";
        }
        BREAK; //------------------------------------------------------

        LABEL("lower_bound search from 0 index");
        // initializing vector of integers
        // for single occurrence
        vector<int> arr1 = {10, 15, 20, 25, 30, 35};

        // initializing vector of integers
        // for multiple occurrences
        vector<int> arr2 = {10, 15, 20, 20, 25, 30, 35};

        // initializing vector of integers
        // for no occurrence
        vector<int> arr3 = {10, 15, 25, 30, 35};

        // using lower_bound() to check if 20 exists
        // single occurrence
        // prints 2
        cout << "The position of 20 using lower_bound "
                " (in single occurrence case) : ";
        cout << lower_bound(arr1.begin(), arr1.end(), 20) - arr1.begin();

        cout << endl;

        // using lower_bound() to check if 20 exists
        // multiple occurrence
        // prints 2
        cout << "The position of 20 using lower_bound "
                "(in multiple occurrence case) : ";
        cout << lower_bound(arr2.begin(), arr2.end(), 20) - arr2.begin();

        cout << endl;

        // using lower_bound() to check if 20 exists
        // no occurrence
        // prints 2 ( index of next higher)
        cout << "The position of 333 using lower_bound "
                "(in no occurrence case) : ";

        //! not found but represent the position where must be
        cout << lower_bound(arr3.begin(), arr3.end(), 333) - arr3.begin() << endl;

        cout << "The position of -59 using lower_bound "
                "(in no occurrence case) : ";

        //! not found but represent the position where must be
        cout << lower_bound(arr3.begin(), arr3.end(), -59) - arr3.begin();

        cout << endl;
        BREAK; //------------------------------------------------------

        LABEL("upper_bound start from 1 index");
        // using upper_bound() to check if 10 exists
        // multiple occurrence
        cout << "The position of 10 using upper_bound "
                "(in multiple occurrence case) : ";
        cout << upper_bound(arr2.begin(), arr2.end(), 10) - arr2.begin();

        cout << endl;

        // using upper_bound() to check if 20 exists
        // single occurrence
        // prints 3
        cout << "The position of 20 using upper_bound"
                " (in single occurrence case) : ";
        cout << upper_bound(arr1.begin(), arr1.end(), 20) - arr1.begin();

        cout << endl;

        // using upper_bound() to check if 20 exists
        // multiple occurrence
        // prints 4
        cout << "The position of 20 using upper_bound "
                "(in multiple occurrence case) : ";
        cout << upper_bound(arr2.begin(), arr2.end(), 20) - arr2.begin();

        cout << endl;

        // using upper_bound() to check if 20 exists
        // no occurrence
        // prints 2 ( index of next higher)
        cout << "The position of 20 using upper_bound"
                " (in no occurrence case) : ";
        cout << upper_bound(arr3.begin(), arr3.end(), 20) - arr3.begin();

        cout << endl;

        BREAK; //------------------------------------------------------
}