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

int main()
{
    int x = 5, y = 10;

    /// 1- common way using third variable
    int temp = x;
    x = y;
    y = temp;

    LABEL(1, "common way using third variable");
    cout << "x = " << x << " y = " << y << endl;

    BREAK; //-----------------------------------------------
    x = 5, y = 10;

    /// 2 - without using third variable
    /// 1 - first way
    x = x + y;
    y = x - y;
    x = x - y;

    LABEL(2, "without using third variable");
    LABEL(1, "first way");

    cout << "    x = x + y;" << endl;
    cout << "    y = x - y;" << endl;
    cout << "    x = x - y;" << endl
         << endl;
    cout << "x = " << x << " y = " << y << endl;

    BREAK; //-----------------------------------------------
    x = 5, y = 10;

    /// 2 - second way
    x = x * y;
    y = x / y;
    x = x / y;

    LABEL(2, "second way");
    cout << "    x = x * y;" << endl;
    cout << "    y = x / y;" << endl;
    cout << "    x = x / y;" << endl
         << endl;
    cout << "x = " << x << " y = " << y << endl;

    BREAK; //-----------------------------------------------
    x = 5, y = 10;

    /// 3 - third way
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;

    LABEL(3, "third way");
    cout << "    x = x ^ y;" << endl;
    cout << "    y = x ^ y;" << endl;
    cout << "    x = x ^ y;" << endl
         << endl;
    cout << "x = " << x << " y = " << y << endl;

    BREAK; //-----------------------------------------------
    x = 5, y = 10;

    /// 4 - fourth way
    x = x + y - (y = x);

    LABEL(4, "fourth way");
    cout << "    x = x + y - (y = x);" << endl
         << endl;
    cout << "x = " << x << " y = " << y << endl;

    BREAK; //-----------------------------------------------
    x = 5, y = 10;

    /// 5 - fifth way
    x = x * y / (y = x);

    LABEL(5, "fifth way");
    cout << "    x = x * y / (y = x);" << endl
         << endl;
    cout << "x = " << x << " y = " << y << endl;

    BREAK; //-----------------------------------------------
    x = 5, y = 10;

    /// 6 - sixth way
    x = x ^ y ^ (y = x);

    LABEL(6, "sixth way");
    cout << "    x = x ^ y ^ (y = x);" << endl
         << endl;
    cout << "x = " << x << " y = " << y << endl;

    BREAK; //-----------------------------------------------
    x = 5, y = 10;
}