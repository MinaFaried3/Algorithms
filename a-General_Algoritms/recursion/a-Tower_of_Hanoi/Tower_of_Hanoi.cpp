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
                   << "--------------------------------------------------------------------" << endl;
#define LABEL(i, title) cout << " " << i << " - " << title << " :-" << endl \
                             << endl;
#define full(arr, val) memset(arr, val, sizeof(arr) - 1)

void towerOfHanoi1(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi1(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod
         << " to rod " << to_rod << endl;
    towerOfHanoi1(n - 1, aux_rod, to_rod, from_rod);
}

void towerOfHanoi2(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
        return;
    }
    towerOfHanoi2(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod
         << " to rod " << to_rod << endl;
    towerOfHanoi2(n - 1, aux_rod, to_rod, from_rod);
}

void towerOfHanoi3(int n, char A, char B, char C)
{
    if (n == 1)
    {
        cout << "Move disk " << n << " from rod " << A << " to rod " << B << endl;
        return;
    }
    towerOfHanoi3(n - 1, A, C, B);
    cout << "Move disk " << n << " from rod " << A
         << " to rod " << B << endl;
    towerOfHanoi3(n - 1, C, B, A);
}
//-------------------------------------------------------------------------------------
void towerOfHanoi4(int n, char from_rod, char aux_rod, char to_rod)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi4(n - 1, from_rod, to_rod, aux_rod);
    cout << "Move disk " << n << " from rod " << from_rod
         << " to rod " << to_rod << endl;
    towerOfHanoi4(n - 1, aux_rod, to_rod, from_rod);
}

void towerOfHanoi5(int n, char A, char B, char C)
{
    if (n == 1)
    {
        cout << "Move disk " << n << " from rod " << A << " to rod " << C << endl;
        return;
    }
    towerOfHanoi5(n - 1, A, C, B);
    cout << "Move disk " << n << " from rod " << A
         << " to rod " << C << endl;
    towerOfHanoi5(n - 1, B, C, A);
}

int main()
{
    int N = 2;

    // A, B and C are names of rods
    towerOfHanoi1(N, 'A', 'C', 'B');
    BREAK
    towerOfHanoi3(N, 'A', 'C', 'B');
    BREAK BREAK BREAK BREAK BREAK;
    towerOfHanoi4(N, 'A', 'C', 'B');
    BREAK
    towerOfHanoi5(N, 'A', 'C', 'B');
    return 0;
}